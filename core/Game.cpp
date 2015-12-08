//std
#include <iostream>

//local
#include "Game.h"

const sf::VideoMode ncmc::Game::DefaultVM(800, 600, 32);

ncmc::Game::Game() : 
		width(DefaultVM.width), 
		height(DefaultVM.height),
		bpp(DefaultVM.bitsPerPixel),
		windowTitle("Prototype")
{
}

ncmc::Game::~Game()
{
}

void ncmc::Game::run()
{
	// Choix du mode vidéo
	sf::VideoMode vm(this->width, this->height, this->bpp);
	if (vm.isValid() == false) vm = DefaultVM;

	// Création de la fenêtre
	sf::Window window(vm, this->windowTitle);

	while (window.isOpen())
	{
		// Fait l'interface entre les infos fournies par SFML et celles requises par notre jeu
		ncmc::EventParser parser;

		// 1) Lecture de tous les events SFML
		sf::Event event;
		while (window.pollEvent(event))
		{
			parser.read(event);
			
			if (event.type == sf::Event::Closed) window.close();
		}

		// 2) 
	}
}

void ncmc::Game::printAvailableResolutions() const
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