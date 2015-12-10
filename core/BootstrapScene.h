#pragma once

//local
#include "Scene.h"
#include "BlankScene.h"

//std
#include <memory>

namespace ncmc {

	//
	// TODO
	// Une scène Bootstrap est toujours en 1ère place.
	// Son rôle est de charger de nouvelles scènes en fonction d'une machine à états interne.
	// Cette machine à état est manipulable globalement (Singleton) par la scène courante.
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