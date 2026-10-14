#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <sstream>

//
// What's up , here in this code i'm just practcing SFML ,or you can say "learning SFML " *_* 
//and this code do not representing to anything, so you can move the ball ,shoot, reaload and 
//you can use the turbo!.... wow a turbo (shut up)
//have not fun :); kidding ,I hope you like the bunch of code
//
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define WINDOW_CENTER_X WINDOW_WIDTH/2
#define WINDOW_CENTER_Y WINDOW_HEIGHT/2

int main()
{
    sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "GUI");
    unsigned int FPS = 60;
    window.setFramerateLimit(FPS);
    unsigned int amoo = 30;

    sf::Font F1("assets/Fonts/Font-1.otf");
    sf::Text amo(F1);

    sf::Clock time;

    sf::CircleShape ball(50.f);
    ball.setFillColor(sf::Color(255,255,255));
    ball.setOrigin({ 50.f,50.f });
    ball.setPosition({ WINDOW_CENTER_X,WINDOW_CENTER_Y });
    sf::Vector2f mousePsition;

    float dt = (float)1 / FPS;
    //velosity
    float velocity = 220.f * dt;

    sf::SoundBuffer buffer("assets/sounds/shoot-1.mp3");
    std::vector<sf::Sound> activeShootSound;

    sf::SoundBuffer buf("assets/sounds/Reload.mp3");
    sf::Sound reload(buf);

    float hoveringValue = 0.f;

    const int MAX_SOUNDS = 28;
    std::vector<std::unique_ptr<sf::Sound>> soundPool;

    for (int i = 0; i < MAX_SOUNDS; ++i) {
        auto sound = std::make_unique<sf::Sound>(buffer);
        soundPool.push_back(std::move(sound));
    }

    while (window.isOpen()) {

        std::stringstream ss;
        ss << amoo;
        std::string amoStr = ss.str();
        amo.setString(amoStr);
        amo.setFillColor(sf::Color(255,10,10));
        amo.setPosition({0.f,680.f});

        mousePsition = static_cast <sf::Vector2f>(sf::Mouse::getPosition(window));

        

        //handling event 
        while (std::optional ev = window.pollEvent()) {

            //closing button 
            if (ev->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        //hovering
        
        if (hoveringValue > 0.f) {
            hoveringValue -= dt;
            hoveringValue = (hoveringValue < 0)? 0.f : hoveringValue;
            uint8_t hv = 255 * (1 - hoveringValue);
            ball.setFillColor(sf::Color(255, hv, hv));
        }


        //moving to the left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            ball.setPosition({ ball.getPosition().x - velocity,ball.getPosition().y });
            //turbo
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl)) ball.setPosition({ ball.getPosition().x - velocity * 2,ball.getPosition().y });
        }
        //moving to the right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            ball.setPosition({ ball.getPosition().x + velocity,ball.getPosition().y });
            //''
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl)) ball.setPosition({ ball.getPosition().x + velocity * 2,ball.getPosition().y });
        }
        //moving down
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            ball.setPosition({ ball.getPosition().x ,ball.getPosition().y + velocity });
            //''
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl)) ball.setPosition({ ball.getPosition().x ,ball.getPosition().y + velocity * 2 });
        }
        //moving up
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            ball.setPosition({ ball.getPosition().x ,ball.getPosition().y - velocity });
            //''
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl)) ball.setPosition({ ball.getPosition().x ,ball.getPosition().y - velocity * 2 });
        }

        //if left mouse button clicked
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            if (amoo <= 0) {
                std::cout << "press 'R' to realod ,can't fire 0 Amoo\n";
            }else if(time.getElapsedTime().asMilliseconds() >= 120 && amoo > 0) {
                
                for (auto& soundPtr : soundPool) {
                    if (soundPtr->getStatus() != sf::Sound::Status::Playing) {
                        soundPtr->play();
                        break;
                    }
                }
                std::cout << "shoot!...." << std::endl;
                hoveringValue = 1;
                amoo--;
                time.restart();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R) && time.getElapsedTime().asMilliseconds() >= 1000) {
            reload.play();
            std::cout << "Realoding...\n";
            amoo = 31;
            time.restart();
        }

        //Right mouse button clicked
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
            std::cout << "Right Button Clicked" << std::endl;
        }

        //display
        window.clear(sf::Color(45, 45, 45));
        window.draw(ball);
        window.draw(amo);
        window.display();
    }

}