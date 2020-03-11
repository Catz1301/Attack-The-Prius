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
	scaleSize -= sf::Vector2f(0.05, 0.05);
	size = sf::Vector2f(elonBullet.getGlobalBounds().width, elonBullet.getGlobalBounds().height);
	if (scaleSize.x < 0.1 && scaleSize.y < 0.1) {
		// TODO: Remove elonBullet and prius it shot.
	}
}

ElonBullet::draw(sf::RenderWindow &target)
{
	target.draw(elonBullet);
}
