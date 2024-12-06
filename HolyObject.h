#ifndef HOLYOBJECT_HPP
#define HOLYOBJECT_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class HolyObject
{
public:
	HolyObject(float x, float y);
	~HolyObject();
	int variant;
	void update(float dt);
	void draw(sf::RenderWindow& target);
	bool readyToDie();
	sf::Vector2f getScaleSize();
	sf::Vector2f getTargetPoint();
	std::vector<sf::Sprite> usedObjects;
	bool dead;
private:
	sf::Sprite holyObjectSprite;
	sf::Vector2f scaleSize;
	sf::Vector2f size;
};

#endif