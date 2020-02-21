#pragma once

#include <SFML/Graphics.hpp>

class Prius
{
public:
	Prius(sf::Texture &texture, float x, float y, float sizeX, float sizeY, bool isBad = false, bool isFacingLeft = true, int speed = 100);
	Prius(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size, bool isBad = false, bool isFacingLeft = true, int speed = 100);
	virtual ~Prius();
	bool isShot(float mouseX, float mouseY);
	void draw(sf::RenderWindow &target);
	sf::Sprite getSprite();
	void setScale(const sf::Vector2f factors);
	void setScale(float factorX, float factorY);

protected:

private:
	sf::RectangleShape priusBasic;
	sf::Sprite priusSprite;
	bool has_Ms_D;
	bool facingLeft;
	int speed; // Speed multiplier

public:
	// Sets the color of the prius
	void setColor(const sf::Color color);
	// Update Prius
	void update(float dt);
	// Moves the Prius to the direction it's facing
	void move(float dt);
	bool isOffScreen(sf::RenderWindow &target);
	void setSpeed(int newSpeed);
};

