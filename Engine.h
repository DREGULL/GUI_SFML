#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

namespace Engine {

	class GameUI {
	private:
		
		sf::Vector2u _windowSize;
		std::string _windowName;

		unsigned int _FPS_FramePerSecond;


	public:
		sf::RenderWindow SFWindow;

		GameUI(sf::Vector2u windowSize, std::string windowName, unsigned int FPS);
		GameUI(sf::RenderWindow window,sf::Vector2u windowSize, std::string windowName);
		GameUI(sf::RenderWindow window,sf::Vector2u windowSize);
		GameUI();


		void setWindowSize(sf::Vector2u windowSize);
		void setWindowName(std::string windowName);
		void setWindowFPS(unsigned int FPS);

		void Clear();
		void Clear(sf::Color color);

	};

}