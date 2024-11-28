#include "ElonBullet.h"

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
	scaleSize -= sf::Vector2f(0.05f, 0.05f);
	elonBullet.setScale(scaleSize);
	size = sf::Vector2f(
		elonBullet.getGlobalBounds().width,
		elonBullet.getGlobalBounds().height
	);
	if (this->readyToDie()) {
		dead = true;
	}
}

void ElonBullet::draw(sf::RenderWindow& target)
{
	target.draw(elonBullet);
}

bool ElonBullet::readyToDie()
{
	return (scaleSize.x <= 1.0f || scaleSize.y <= 1.0f);
}

sf::Vector2f ElonBullet::getScaleSize()
{
	return scaleSize;
}

sf::Vector2f ElonBullet::getTargetPoint()
{
	return elonBullet.getPosition();
}