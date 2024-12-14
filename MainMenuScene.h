#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class MainMenuScene :
    public Scene
{
    MainMenuScene();
    void initScene();
    void loadScene();
    void updateScene(sf::Event& e_, sf::Time dt);
    void drawScene();
    void unloadScene();
private:
    
};

