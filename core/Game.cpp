//std
#include <iostream>

//local
#include "Game.h"
#include "BootstrapScene.h"

using namespace ncmc;

const sf::VideoMode Game::DefaultVM(800, 600, 32);

Game::Game() : 
		width(DefaultVM.width), 
		height(DefaultVM.height),
		bpp(DefaultVM.bitsPerPixel),
		windowTitle("Prototype")
{
	this->pushScene(std::make_shared<BootstrapScene>(this));
}

Game::~Game()
{
}

void Game::run()
{
	// Choix du mode vidéo
	sf::VideoMode vm(this->width, this->height, this->bpp);
	if (vm.isValid() == false) vm = DefaultVM;

	// Création de la fenêtre
	sf::RenderWindow window(vm, this->windowTitle);

	while (window.isOpen())
	{
		//
		//	Scène courante
		//

		std::weak_ptr<Scene> scenePtr = this->getCurrentScene();
		if (scenePtr.expired()) {
			sf::err() << "No current Scene. Exiting." << std::endl;
			window.close();
			continue;
		}

		//
		//	Passage des évènements SFML
		//

		sf::Event event;
		while (window.pollEvent(event))
		{
			//
			//	INPUT
			//

			// Touche pressée
			if (event.type == sf::Event::KeyPressed) {
				if (auto scene = scenePtr.lock())
					scene->onKeyPressed(event.key);
				continue;
			}

			// Touche relâchée
			if (event.type == sf::Event::KeyReleased) {
				if (auto scene = scenePtr.lock())
					scene->onKeyReleased(event.key);
				continue;
			}

			// Bouton de souris pressé
			if (event.type == sf::Event::MouseButtonPressed) {
				if (auto scene = scenePtr.lock())
					scene->onMouseButtonPressed(event.mouseButton);
				continue;
			}

			// Bouton de souris relâché
			if (event.type == sf::Event::MouseButtonReleased) {
				if (auto scene = scenePtr.lock())
					scene->onMouseButtonReleased(event.mouseButton);
				continue;
			}
			
			// Souris déplacée
			if (event.type == sf::Event::MouseMoved) {
				if (auto scene = scenePtr.lock())
					scene->onMouseMoved(event.mouseMove);
				continue;
			}

			// Défilement de souris (MouseWheelMoved deprecated)
			if (event.type == sf::Event::MouseWheelScrolled) {
				if (auto scene = scenePtr.lock())
					scene->onMouseWheelScrolled(event.mouseWheelScroll);
				continue;
			}

			//
			//	WINDOW
			//

			// Fenêtre redimensionnée
			if (event.type == sf::Event::Resized) {
				if (auto scene = scenePtr.lock())
					scene->onWindowResized(window, event.size);
				continue;
			}

			// Fenêtre fermée
			if (event.type == sf::Event::Closed) {
				if (auto scene = scenePtr.lock())
					scene->onWindowClosed(window);
				window.close();
				continue;
			}
		}

		//
		//	Affichage de la scène
		//

		if (auto scene = scenePtr.lock())
		{
			window.clear();
			window.draw(*scene);
			window.display();
		}
	}
}

void Game::pushScene(std::shared_ptr<Scene> newScene)
{
	this->scenes.push(newScene);
}

bool Game::popScene()
{
	this->scenes.pop();
	return !this->scenes.empty();
}

void Game::printAvailableResolutions() const
{
	// Display the list of all the video modes available for fullscreen
	std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
	for (std::size_t i = 0; i < modes.size(); ++i)
	{
		sf::VideoMode mode = modes[i];
		std::cout << "Mode #" << i << ": "
			<< mode.width << "x" << mode.height << " - "
			<< mode.bitsPerPixel << " bpp" << std::endl;
	}
}

std::weak_ptr<Scene> Game::getCurrentScene()
{
	return this->scenes.empty() ? 
		std::weak_ptr<Scene>() :
		this->scenes.top();
}
