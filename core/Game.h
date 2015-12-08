#pragma once

//std
#include <cstdint>

//sfml
#include <SFML\Graphics.hpp>

namespace ncmc
{
	class Game
	{
	public:
		Game();
		Game(const Game&) = delete;
		Game& operator=(const Game&) = delete;
		~Game();

		void run();

	protected:
		void printAvailableResolutions() const;

	private:
		static const sf::VideoMode DefaultVM;
		unsigned int width, height, bpp;
		std::string windowTitle;
	};
}