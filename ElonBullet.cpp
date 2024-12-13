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
	dead = false;
}

ElonBullet::~ElonBullet()
{
	usedBullets.clear();
}

// Methods
void ElonBullet::update(std::vector<Prius>& vect, float dt)
{
	if (dead == true)
		return;
	scaleSize -= sf::Vector2f(0.03f, 0.03f);
	elonBullet.setScale(scaleSize);
	size = sf::Vector2f(
		elonBullet.getGlobalBounds().width,
		elonBullet.getGlobalBounds().height
	);
	if (readyToDie() || collidesWithPrius(vect)) {
		dead = true;

	}
}

void ElonBullet::draw(sf::RenderWindow& target)
{
	target.draw(elonBullet);
}

bool ElonBullet::collidesWithPrius(std::vector<Prius>& vect) {
	for (int i = 0; i < vect.size(); i++) {
		sf::FloatRect intersection;
		if (elonBullet.getGlobalBounds().intersects(vect[i].getSprite().getGlobalBounds(), intersection)) {
			vect[i].attacked = true;
			return true;
		}
	}
	return false;
}

bool ElonBullet::readyToDie()
{
	/*std::cout << "ElonBullet::readyToDie() - scale values: x:" << scaleSize.x << ", y: " << scaleSize.y << std::endl;
	std::cout << "ElonBullet::readyToDie() - result: " << (scaleSize.x <= 0.05 || scaleSize.y <= 0.05) << std::endl;*/
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

sf::Sprite ElonBullet::getSprite() {
	return elonBullet;
}