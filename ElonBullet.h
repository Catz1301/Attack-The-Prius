#ifndef ELONBULLET
#define ELONBULLET

#include <SFML/Graphics.hpp>

class ElonBullet {
	public:
		ElonBullet(sf::Texture &texture, float x, float y);
		virtual ~ElonBullet();
		void update(float &dt);
		void draw(sf::RenderWindow &target);
	private:
		sf::Sprite elonBullet;
		sf::Vector2f scaleSize;

#endif //!AMMO_H
