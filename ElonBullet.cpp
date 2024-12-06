#include "ElonBullet.h"
#include <iostream>

ElonBullet::ElonBullet(sf::Texture &texture, float x, float y)
{
	elonBullet.setTexture(texture);
	size = sf::Vector2f(
		texture.getSize().x,
		texture.getSize().y
	);
	scaleSize = sf::Vector2f(1.2f, 1.2f);
	elonBullet.setOrigin(size.x/2, size.y/2);
	usedBullets = std::vector<sf::Sprite>();
	elonBullet.setPosition(x, y);
}

ElonBullet::~ElonBullet()
{
	usedBullets.clear();
}

// Methods
void ElonBullet::update(float dt)
{
	if (dead == true)
		return;
	scaleSize -= sf::Vector2f(0.03f, 0.03f);
	elonBullet.setScale(scaleSize);
	size = sf::Vector2f(
		elonBullet.getGlobalBounds().width,
		elonBullet.getGlobalBounds().height
	);
	if (readyToDie()) {
		dead = true;

	}
}

void ElonBullet::draw(sf::RenderWindow& target)
{
	target.draw(elonBullet);
}

bool ElonBullet::readyToDie()
{
	std::cout << "ElonBullet::readyToDie() - scale values: x:" << scaleSize.x << ", y: " << scaleSize.y << std::endl;
	std::cout << "ElonBullet::readyToDie() - result: " << (scaleSize.x <= 1.0 || scaleSize.y <= 1.0) << std::endl;
	return (scaleSize.x <= 0.05 || scaleSize.y <= 0.05);
}

sf::Vector2f ElonBullet::getScaleSize()
{
	return scaleSize;
}

sf::Vector2f ElonBullet::getTargetPoint()
{
	return elonBullet.getPosition();
}