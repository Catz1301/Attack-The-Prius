#include "Prius.h"
// Constructors / Destructors
Prius::Prius(sf::Texture &texture, float x, float y, float sizeX, float sizeY, bool isBad, bool isFacingLeft)
{
	/*priusBasic.setSize(sf::Vector2f(sizeX, sizeY));
	priusBasic.setPosition(x-sizeX/2, y-sizeY/2);
	priusBasic.setFillColor(sf::Color(0, 0, 255));
	priusBasic.setOrigin(sizeX / 2, sizeY / 2);*/
	priusSprite.setTexture(texture);
	priusSprite.setScale(0.5, 0.5);
	priusSprite.setPosition(x - sizeX / 2, y - sizeY / 2);
	has_Ms_D = isBad;
	facingLeft = isFacingLeft;
}

Prius::Prius(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size, bool isBad, bool isFacingLeft)
{
	/*priusBasic.setSize(size);
	priusBasic.setPosition(position.x - size.x/2, position.y-size.y/2);
	priusBasic.setFillColor(sf::Color(sf::Color::Cyan));*/
	priusSprite.setTexture(texture);
	priusSprite.setScale(0.5, 0.5);
	priusSprite.setPosition(position.x - size.x / 2, position.y - size.y / 2);
	has_Ms_D = isBad;
	facingLeft = isFacingLeft;
}

Prius::~Prius()
{

}

void Prius::setScale(const sf::Vector2f factors)
{
	priusSprite.setScale(factors);
}

void Prius::setScale(float factorX, float factorY)
{
	priusSprite.setScale(factorX, factorY);
}

sf::Sprite Prius::getSprite()
{
	return priusSprite;
}

void Prius::draw(sf::RenderWindow &target)
{
	target.draw(priusSprite);
}


bool Prius::isShot(float mouseX, float mouseY)
{

	if (mouseX >= priusSprite.getGlobalBounds().left &&
		mouseX <= priusSprite.getGlobalBounds().left + priusSprite.getGlobalBounds().width &&
		mouseY >= priusSprite.getGlobalBounds().top &&
		mouseY <= priusSprite.getGlobalBounds().top + priusSprite.getGlobalBounds().height)
		return true;
	else
		return false;
}


// Sets the color of the prius
void Prius::setColor(const sf::Color color)
{
	// TODO: Add your implementation code here.
	priusSprite.setColor(color);
}


// Update Prius
void Prius::update(float dt)
{
	// TODO: Add your implementation code here.
	this->move(dt);
}


// Moves the Prius to the direction it's facing
void Prius::move(float dt)
{
	// TODO: Add your implementation code here.
	if (facingLeft)
		priusSprite.move((-1*speed)*dt, 0);
	else
		priusSprite.move((1*speed)*dt, 0);

}


bool Prius::isOffScreen(sf::RenderWindow &target)
{
	// TODO: Add your implementation code here.
	if (facingLeft == true)
		return (priusSprite.getPosition().x + priusSprite.getGlobalBounds().width < -10);
	else if (facingLeft == false)
		return (priusSprite.getPosition().x > target.getSize().x + 10)
	else
		return false;
}

void Prius::setSpeed(int newSpeed)
{
	speed = newSpeed;
}
