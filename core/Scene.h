#pragma once

//sfml
#include <SFML/Graphics.hpp>

namespace ncmc
{
	class Scene : public sf::Drawable, public sf::Transformable {
	public:
		void update()
		{
			this->onUpdate(this->clock.restart());
		}

	protected:
		virtual void onLoad() = 0;
		virtual void onUnload() = 0;
		virtual void onUpdate(sf::Time elapsedTime) = 0;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	private:
		sf::Clock clock;
	};
}
