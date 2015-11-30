#pragma once

//std
#include <cstdint>

//sfml
#include <SFML\Graphics.hpp>

namespace ncmc
{
	class PrototypeEngine
	{
	public:
		PrototypeEngine();
		PrototypeEngine(const PrototypeEngine&) = delete;
		PrototypeEngine& operator=(const PrototypeEngine&) = delete;
		~PrototypeEngine();

		void run();

	protected:
		void printAvailableResolutions() const;

	private:
		static const sf::VideoMode DefaultVM;
		std::size_t width, height, bpp;
		std::string windowTitle;
	};
}