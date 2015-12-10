#pragma once

//local
#include "Scene.h"
#include "BlankScene.h"

//std
#include <memory>

namespace ncmc {

	//
	// TODO
	// Une sc�ne Bootstrap est toujours en 1�re place.
	// Son r�le est de charger de nouvelles sc�nes en fonction d'une machine � �tats interne.
	// Cette machine � �tat est manipulable globalement (Singleton) par la sc�ne courante.
	//

	class BootstrapScene : public BlankScene {
	public:
		BootstrapScene() = delete;
		BootstrapScene(const BootstrapScene&) = delete;
		BootstrapScene& operator=(const BootstrapScene&) = delete;
		BootstrapScene(SceneStack* stack);
		~BootstrapScene() = default;

	private:
		SceneStack* const sceneStack;
	};

}