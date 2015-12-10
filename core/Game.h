#pragma once

//std
#include <cstdint>
#include <memory>
#include <stack>

//sfml
#include <SFML\Graphics.hpp>

//local
#include "Scene.h"

namespace ncmc
{
	class Game : public SceneStack
	{
	public:
		Game();
		Game(const Game&) = delete;
		Game& operator=(const Game&) = delete;
		~Game();

		void run();

		virtual void pushScene(std::shared_ptr<Scene>);
		virtual bool popScene();

	protected:
		void printAvailableResolutions() const;
		std::weak_ptr<Scene> getCurrentScene();

	private:
		static const sf::VideoMode DefaultVM;
		unsigned int width, height, bpp;
		std::string windowTitle;

		std::stack<std::shared_ptr<Scene>> scenes;
		sf::Clock clock;
	};
}