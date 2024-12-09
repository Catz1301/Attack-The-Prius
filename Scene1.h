#pragma once
#include "Scene.h"
#include <vector>
#include "Prius.h"
#include "ElonBullet.h"
#include "HolyObject.h"
class Scene1 :
    public Scene
{
public:
    Scene1(sf::RenderWindow& win);
    void initScene();
    void loadScene();
    void updateScene(sf::Event &e, sf::Time dt);
    void drawScene();
    void unloadScene();

private:
    void removePrius(std::vector<Prius>& vect, size_t pos);
    void makeNewPrius(std::vector<Prius>& vect, int q = 1);
    void removeElonBullet(std::vector<ElonBullet>& vect, size_t pos);
    void makeNewElonBullet(std::vector<ElonBullet>& vect, float xPos, float yPos);
    void removeHolyObject(std::vector<HolyObject>& vect, size_t pos);
    void makeNewHolyObject(std::vector<HolyObject>& vect, float xPos, float yPos);

    sf::Texture muskHeadTex; // Elon Musk Texture
    sf::Texture priusTransparentTex; // Prius Texture
    sf::Texture missPriusTex; // Miss Prius Texture
    sf::Sprite muskHead;
    sf::Image priusImage;
    sf::Vector2f windowSize;
    sf::Vector2f size;
    sf::RenderWindow &window;
    sf::Event e;
    std::vector<Prius> prii;
    std::vector<ElonBullet> elonBullets;
    std::vector<HolyObject> holyObjects;


    int score;
    int numOfChildren;
    int ending_prius;
    int health;

};

