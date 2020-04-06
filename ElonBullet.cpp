#include "ElonBullet.h"

ElonBullet::ElonBullet(sf::Texture &texture, float x, float y)
{
	elonBullet.setTexture(texture);
	size = sf::Vector2f(
		texture.getSize().x,
		texture.getSize().y
	);
	scaleSize = elonBullet.getScale();
	elonBullet.setOrigin(size.x/2, size.y/2);
}

ElonBullet::~ElonBullet()
{
	
}

// Methods
void ElonBullet::update(float &dt)
{
	scaleSize -= sf::Vector2f(0.05, 0.05);
	size = sf::Vector2f(
		elonBullet.getGlobalBounds().width,
		elonBullet.getGlobalBounds().height
	);
}

void ElonBullet::draw(sf::RenderWindow& target)
{
	target.draw(elonBullet);
}

bool ElonBullet::readyToDie()
{
	return (scaleSize.x < 0.1 && scaleSize.y < 0.1);
}

sf::Vector2f ElonBullet::getScaleSize()
{
	return scaleSize;
}

sf::Vector2f ElonBullet::getTargetPoint()
{
	return elonBullet.getPosition();
}