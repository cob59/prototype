#pragma once

//local
#include "Scene.h"

namespace ncmc
{
	class BlankScene : public Scene {
	public:
		// Durée de vie
		virtual void onLoad() {}
		virtual void onUnload() {}
		virtual void onUpdate(sf::Time elapsedTime) {}

		// Gestion des events (INPUT)
		virtual void onKeyPressed(sf::Event::KeyEvent) {}
		virtual void onKeyReleased(sf::Event::KeyEvent) {}
		virtual void onMouseButtonPressed(sf::Event::MouseButtonEvent) {}
		virtual void onMouseButtonReleased(sf::Event::MouseButtonEvent) {}
		virtual void onMouseMoved(sf::Event::MouseMoveEvent) {}
		virtual void onMouseWheelScrolled(sf::Event::MouseWheelScrollEvent) {}

		// Gestion des events (WINDOW)
		virtual void onWindowResized(sf::Window& window, sf::Event::SizeEvent) {}
		virtual void onWindowClosed(sf::Window& window) {}

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {}
	};
}
