#pragma once
#include "Scene.h"
#include <vector>
#include "Prius.h"
#include "ElonBullet.h"
#include "HolyObject.h"
#include "Scene1_GUI.h"
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
    void removeAttackedPrius(std::vector<Prius>& vect);

    sf::Texture muskHeadTex; // Elon Musk Texture
    sf::Texture priusTransparentTex; // Prius Texture
    sf::Texture missPriusTex; // Miss Prius Texture
    sf::Sprite muskHead;
    sf::Image priusImage;
    sf::Vector2f windowSize;
    sf::Vector2f size;
    sf::RenderWindow &window;

    std::vector<Prius> prii;
    std::vector<ElonBullet> elonBullets;
    std::vector<HolyObject> holyObjects;
    Scene1_GUI gui;
    std::map<int, int> holyObjectInventory;

    unsigned int score;
    int totalScore;
    int availableHolyObjects;
    int ending_prius;
    int health;
    bool givenHolyObject = false;
    

};

