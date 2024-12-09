#include "Player.h"

Player::Player(sf::RenderWindow *windowCtx_) {
	health = 100;
	score = 0;
	windowCtx = windowCtx_;
}

Player::~Player() {
	// clear the vectors
}

bool Player::inflictDamage(int amount) {
	health -= amount;
	return (health <= 0);
}

void Player::heal(int amount) {
	if (health + amount >= 100) {
		health = 100; // to cap health at 100
	}
	else {
		health += amount;
	}
}

void Player::setScore(int newScore) {
	score = newScore;
	if (score % 5 == 0) {
		// add to holyObjectVectorStat
	}
}

int Player::getScore() {
	return score;
}

void Player::shootBullet(float xPos, float yPos) {
	makeNewElonBullet(elonBullets, xPos, yPos);
}

void Player::shootHolyObject(float xPos, float yPos) {
	makeNewHolyObject(holyObjects, xPos, yPos);
	// holyObjectStatVector.popBack();
}

int Player::getHolyObjectCount() {
	return holyObjects.size();
}

//void Player::makeNewPrius(std::vector<Prius>& vect, int q) {
//	if (q > 2)
//		q = 2;
//	for (int i = 0; i < 1; i++) {
//		int direction = std::rand();
//		int bad_prius = std::rand();
//		float x;
//		float y = rand() % windowCtx.getSize().y;
//		if (direction % 2 == 0)
//			x = 10 + window.getSize().x;
//		else
//			x = -50;
//
//		//float x = 100; //rand() % window.getSize().x + 100;
//		//float y = rand() % window.getSize().y;
//		//else {
//			//float x = -50;
//			//x += window.getSize().x;
//			//float y = rand() % window.getSize().y;
//		//}
//		//if (x > 100 + window.getSize().x - priusTransparentTex.getSize().x)
//			//x -= 100;//priusTransparentTex.getSize().x;
//
//		if (y > window.getSize().y - priusTransparentTex.getSize().y)
//			y -= priusTransparentTex.getSize().y;
//		int speed = 3 + (std::rand() % 5);
//
//		speed *= 100;
//
//		if (bad_prius % 5 == 0) {
//			if (direction % 2 == 0)
//				vect.push_back(Prius(missPriusTex, Vector2f(x, y), size, windowSize, true, true, speed));
//			else if (direction % 2 == 1)
//				vect.push_back(Prius(missPriusTex, Vector2f(x, y), size, windowSize, true, false, 50));
//		}
//		else {
//			if (direction % 2 == 0)
//				vect.push_back(Prius(priusTransparentTex, sf::Vector2f(x, y), size, windowSize, false, true, speed));
//			else if (direction % 2 == 1)
//				vect.push_back(Prius(priusTransparentTex, sf::Vector2f(x, y), size, windowSize, false, false, 50));
//		}
//	}
//
//	/*prii[0].setColor(Color::Blue);
//	prii[1].setColor(Color::Cyan);
//	prii[2].setColor(Color::Green);
//	prii[3].setColor(Color::Magenta);
//	prii[4].setColor(Color::Red);*/
//}

void Player::makeNewPrius(int q) {

}

void Player::removePrius(std::vector<Prius>& vect, size_t pos) {

}

void Player::makeNewElonBullet(std::vector<ElonBullet>& vect, float xPos, float yPos) {

}

void Player::removeElonBullet(std::vector<ElonBullet>& vect, size_t pos) {

}

void Player::makeNewHolyObject(std::vector<HolyObject>& vect, float xPos, float yPos) {

}

void Player::removeHolyObject(std::vector<HolyObject>& vect, size_t pos) {

}

void Player::update() {

}

void Player::draw() {

}