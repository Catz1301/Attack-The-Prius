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
	// TODO: Shrink scaleSize
}

ElonBullet::draw(sf::RenderWindow &target)
{
	target.draw(elonBullet);
}
