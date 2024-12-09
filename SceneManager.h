#pragma once
#include <memory>
#include "Scene.h"
#include <SFML/Graphics.hpp>
class SceneManager
{
public:
	SceneManager();
	void addScene(std::shared_ptr<Scene> scene);
	void load(int index);
	void update(sf::Event& e, sf::Time dt);
	void render();
	void unload();

private:
	std::vector<std::shared_ptr<Scene>> scenes;
	std::shared_ptr<Scene> currentScene;
};

void addScene(std::shared_ptr<Scene> scene);
