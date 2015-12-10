#pragma once

//std
#include <memory>

//sfml
#include <SFML/Graphics.hpp>

namespace ncmc
{
	class Scene : public sf::Drawable, public sf::Transformable {
	public:
		// Durée de vie
		virtual void onLoad() = 0;
		virtual void onUnload() = 0;
		virtual void onUpdate(sf::Time elapsedTime) = 0;

		// Gestion des events (INPUT)
		virtual void onKeyPressed(sf::Event::KeyEvent) = 0;
		virtual void onKeyReleased(sf::Event::KeyEvent) = 0;
		virtual void onMouseButtonPressed(sf::Event::MouseButtonEvent) = 0;
		virtual void onMouseButtonReleased(sf::Event::MouseButtonEvent) = 0;
		virtual void onMouseMoved(sf::Event::MouseMoveEvent) = 0;
		virtual void onMouseWheelScrolled(sf::Event::MouseWheelScrollEvent) = 0;

		// Gestion des events (WINDOW)
		virtual void onWindowResized(sf::Window& window, sf::Event::SizeEvent) = 0;
		virtual void onWindowClosed(sf::Window& window) = 0;

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	};


	class SceneStack {
	public:
		virtual void pushScene(std::shared_ptr<Scene>) = 0;
		virtual bool popScene() = 0;
	};
}
