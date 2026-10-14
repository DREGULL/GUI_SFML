#pragma once
#include "Engine.h"

namespace Engine {
	//constructors
	GameUI::GameUI( sf::Vector2u windowSize, std::string windowName, unsigned int FPS) {
		
		this->_windowSize = windowSize;
		this->_windowName = windowName;

		this->_FPS_FramePerSecond = FPS;

		SFWindow.create(sf::VideoMode(_windowSize),_windowName);
		
		SFWindow.setFramerateLimit(FPS);
	}
	GameUI::GameUI(sf::RenderWindow window, sf::Vector2u windowSize, std::string windowName) {
		this->_windowSize = windowSize;
		this->_windowName = windowName;

		this->_FPS_FramePerSecond = 60;
	}
	GameUI::GameUI(sf::RenderWindow window, sf::Vector2u windowSize) {
		this->_windowSize = windowSize;
		this->_windowName = "Game Window";

		this->_FPS_FramePerSecond = 60;
	}
	GameUI::GameUI() {
		this->_windowSize = { 1280,720 };
		this->_windowName = "Game Window";

		this->_FPS_FramePerSecond = 60;
	}
	//...

	//setFNs
	void GameUI::setWindowSize(sf::Vector2u windowSize) {
		this->_windowSize = windowSize;
	}

	void GameUI::setWindowName(std::string windowName) {
		this->_windowName = windowName;
	}

	void GameUI::setWindowFPS(unsigned int FPS) {

		this->_FPS_FramePerSecond = FPS;
		//refresh the window
		SFWindow.create(sf::VideoMode(_windowSize), _windowName);
	}
	//...

	//drawing ,displying and clearing fns
	void GameUI::Clear() {
		SFWindow.clear();
	}

	void GameUI::Clear(sf::Color color) {
		SFWindow.clear(color);
	}
}