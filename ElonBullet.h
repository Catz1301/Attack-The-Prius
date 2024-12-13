#ifndef ELONBULLET_H
#define ELONBULLET_H

#include <SFML/Graphics.hpp>
#include "Prius.h"

class ElonBullet {
public:
	ElonBullet(sf::Texture& texture, float x, float y);
	virtual ~ElonBullet();
	void update(std::vector<Prius>& vect, float dt);
	void draw(sf::RenderWindow& target);
	bool collidesWithPrius(std::vector<Prius>& vect);
	bool readyToDie();
	sf::Vector2f getScaleSize();
	sf::Vector2f getTargetPoint();
	std::vector<sf::Sprite> usedBullets;
	bool dead;
	sf::Vector2f size;
	sf::Sprite getSprite();

private:
	sf::Sprite elonBullet;
	sf::Vector2f scaleSize;
};
#endif