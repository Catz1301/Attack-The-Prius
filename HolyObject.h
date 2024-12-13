#ifndef HOLYOBJECT_HPP
#define HOLYOBJECT_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Prius.h"

class HolyObject
{
public:
	HolyObject(float x, float y);
	~HolyObject();
	int variant;
	void update(std::vector<Prius>& vect, float dt);
	void draw(sf::RenderWindow& target);
	bool readyToDie();
	bool collidesWithPrius(std::vector<Prius>& vect);
	sf::Vector2f getScaleSize();
	sf::Vector2f getTargetPoint();
	std::vector<sf::Sprite> usedObjects;
	bool dead = false;
private:
	sf::Sprite holyObjectSprite;
	sf::Vector2f scaleSize;
	sf::Vector2f size;
};

#endif