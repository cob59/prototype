//std
#include <iostream>

//local
#include "Engine.h"

const sf::VideoMode ncmc::PrototypeEngine::DefaultVM(800, 600, 32);

ncmc::PrototypeEngine::PrototypeEngine() : 
		width(DefaultVM.width), 
		height(DefaultVM.height),
		bpp(DefaultVM.bitsPerPixel),
		windowTitle("Prototype")
{
}

ncmc::PrototypeEngine::~PrototypeEngine()
{
}

void ncmc::PrototypeEngine::run()
{
	// Choix du mode vid�o
	sf::VideoMode vm(this->width, this->height, this->bpp);
	if (vm.isValid() == false) vm = DefaultVM;

	// Cr�ation de la fen�tre
	sf::Window window(vm, this->windowTitle);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}

void ncmc::PrototypeEngine::printAvailableResolutions() const
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