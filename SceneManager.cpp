#include "SceneManager.h"

SceneManager::SceneManager() {

}

void SceneManager::addScene(std::shared_ptr<Scene> scene) {
	scenes.push_back(scene);
}


void SceneManager::load(int index) {
	if (index >= 0 && index < scenes.size()) {
		if (currentScene) {
			currentScene->unloadScene();
		}
		currentScene = scenes[index];
		currentScene->loadScene();
		currentScene->initScene();
	}
}

void SceneManager::update(sf::Event& e, sf::Time dt) {
	if (currentScene) {
		currentScene->updateScene(e, dt);
	}
}

void SceneManager::render() {
	if (currentScene) {
		currentScene->drawScene();
	}
}

void SceneManager::unload() {
	if (currentScene) {
		currentScene->unloadScene();
	}
}