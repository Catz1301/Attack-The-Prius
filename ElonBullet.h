#ifndef ELONBULLET_H
#define ELONBULLET_H

#include <SFML/Graphics.hpp>

class ElonBullet {
	public:
		ElonBullet(sf::Texture &texture, float x, float y);
		virtual ~ElonBullet();
		void update(float &dt);
		void draw(sf::RenderWindow &target);
		bool readyToDie();
		sf::Vector2f getScaleSize();
		sf::Vector2f getTargetPoint();
	
	private:
		sf::Sprite elonBullet;
		sf::Vector2f scaleSize;
		sf::Vector2f size;

#endif //!ELONBULLET_H
