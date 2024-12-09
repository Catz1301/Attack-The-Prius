#pragma once
#include <SFML/Graphics.hpp>
class Scene
{
public:
	virtual ~Scene() {};
	virtual void initScene() = 0;
	virtual void loadScene() = 0;
	virtual void updateScene(sf::Event& e_, sf::Time dt) = 0;
	virtual void drawScene() = 0;
	virtual void unloadScene() = 0;
};

