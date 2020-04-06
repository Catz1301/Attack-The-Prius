#include "ElonBullet.h"

ElonBullet::ElonBullet(sf::Texture &texture, float x, float y)
{
	elonBullet.setTexture(texture);
	size = texture.getSize();
	scaleSize = elonBullet.getScale();
	elonBullet.setOrigin(size.x/2, size.y/2);
}

ElonBullet::~ElonBullet()
{
	
}

ElonBullet::update(float &dt)
{
	scaleSize -= sf::Vector2f(0.05, 0.05);
	size = sf::Vector2f(elonBullet.getGlobalBounds().width, elonBullet.getGlobalBounds().height);
}

ElonBullet::readyToDie()
{
	return (scaleSize.x < 0.1 && scaleSize.y < 0.1);
}

ElonBullet::getScaleSize()
{
	return scaleSize;
}

ElonBullet::getTargetPoint()
{
	return elonBullet.getPosition();
}

ElonBullet::draw(sf::RenderWindow &target)
{
	target.draw(elonBullet);
}
