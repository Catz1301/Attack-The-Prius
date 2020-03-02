#include "Prius.h"
// Constructors / Destructors
Prius::Prius(sf::Texture &texture, float x, float y, float sizeX, float sizeY, bool isBad, bool isFacingLeft, int speeed)
{
	
	priusSprite.setTexture(texture);
	
	if (isFacingLeft == true) {
		priusSprite.setScale(0.5, 0.5);
	}
	else {
		priusSprite.setScale(-0.5, 0.5);
	}
	priusSprite.setPosition(x - sizeX / 2, y - sizeY / 2);
	has_Ms_D = isBad;
	//speed = speeed;
	speed = 1;
	facingLeft = isFacingLeft;
	stopped = false;
}

Prius::Prius(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size, bool isBad, bool isFacingLeft, int speeed)
{
	priusSprite.setTexture(texture);

	if (isFacingLeft == true) {
		priusSprite.setScale(0.5, 0.5);
	}
	else {
		priusSprite.setScale(-0.5, 0.5); // Note: X will end up on the top-right hand corner of the Prius.
	}
	priusSprite.setPosition(position.x - size.x / 2, position.y - size.y / 2);
	has_Ms_D = isBad;
	//speed = speeed;
	speed = 1;
	facingLeft = isFacingLeft;
	stopped = false;
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

bool Prius::isDangerous()
{
	return has_Ms_D;
}

void Prius::stop()
{
	stopped = true;
}

sf::Sprite Prius::getSprite()
{
	return priusSprite;
}

void Prius::draw(sf::RenderWindow &target)
{
	target.draw(priusSprite);
}

void Prius::setPosition(float xPos, float yPos)
{
	priusSprite.setPosition(xPos, yPos);
}

bool Prius::isShot(float mouseX, float mouseY)
{
	if (stopped == true)
		return false;

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
	if (!stopped) {
		this->move(dt);
		this->setSpeed(speed + 0.05);
	}
}


// Moves the Prius to the direction it's facing
void Prius::move(float dt)
{
	// TODO: Add your implementation code here.
	if (facingLeft == true)
		priusSprite.move(-1*speed, 0);
	else
		priusSprite.move(1*speed, 0); // Would be the same as speed*dt, but this way makes it look uniform
}


bool Prius::isOffScreen(int windowWidth)
{
	// TODO: Add your implementation code here.
	if (facingLeft == true)
		return (priusSprite.getPosition().x + priusSprite.getGlobalBounds().width < -10);
	else if (facingLeft == false)
		return (priusSprite.getPosition().x > windowWidth + priusSprite.getGlobalBounds().width + 20);
	else
		return false;
}


void Prius::setSpeed(float newSpeed)
{
	// TODO: Add your implementation code here.
	speed = newSpeed;
}

void Prius::setOrigin(float x, float y)
{
	priusSprite.setOrigin(x, y);
}

sf::Vector2f Prius::getSize()
{
	return sf::Vector2f(priusSprite.getGlobalBounds().width, priusSprite.getGlobalBounds().height);
}

sf::Vector2f Prius::getPosition()
{
	return sf::Vector2f(priusSprite.getPosition());
}

bool Prius::getFacingLeft()
{
	return facingLeft;
}
