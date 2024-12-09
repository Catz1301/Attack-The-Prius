#include <vector>
#include "ElonBullet.h"
#include "Prius.h"
#include "HolyObject.h"
#include <SFML/Graphics.hpp>

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
public:
	Player(sf::RenderWindow *window);
	~Player();
	bool inflictDamage(int amount = 5);
	void heal(int amount = 20);
	void setScore(int newScore);
	int getScore();
	void shootBullet(float xPos, float yPos);
	void shootHolyObject(float xPos, float yPos);
	int getHolyObjectCount();
	std::vector<ElonBullet> elonBullets;
	std::vector<Prius> prii;
	std::vector<HolyObject> holyObjects;
	void makeNewPrius(std::vector<Prius>& vect, int q);
	void makeNewPrius(int q = 1);
	void removePrius(std::vector<Prius>& vect, size_t pos);
	void makeNewElonBullet(std::vector<ElonBullet>& vect, float xPos, float yPos);
	void removeElonBullet(std::vector<ElonBullet>& vect, size_t pos);
	void makeNewHolyObject(std::vector<HolyObject>& vect, float xPos, float yPos);
	void removeHolyObject(std::vector<HolyObject>& vect, size_t pos);
	void update();
	void draw();

private:
	int health;
	int score;
	sf::RenderWindow *windowCtx;

};

#endif