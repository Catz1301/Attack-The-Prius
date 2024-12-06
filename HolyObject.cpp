#include "HolyObject.h"

// TODO: IMPLEMENT

HolyObject::HolyObject(float x, float y)
{
	/*texture.setTexture(texture);*/
	variant = std::rand() % 4;
	sf::Texture *tex = new sf::Texture;
	sf::Image errTex = sf::Image();
	errTex.create(367, 367, sf::Color().Magenta);
	//tex.loadFromImage(errTex);

	if (variant == 0) {
		if (!tex->loadFromFile("Resources/Images/bible.png"))
			std::cout << "ERROR::HOLYOBJECT::COULD_NOT_LOAD_TEXTURE" << std::endl;
	}
	else if (variant == 1) {
		if (!tex->loadFromFile("Resources/Images/crown-of-thorns.png"))
			std::cout << "ERROR::HOLYOBJECT::COULD_NOT_LOAD_TEXTURE" << std::endl;
	}
	else if (variant == 2) {
		if (!tex->loadFromFile("Resources/Images/crucifix.png"))
			std::cout << "ERROR::HOLYOBJECT::COULD_NOT_LOAD_TEXTURE" << std::endl;
	}
	else if (variant == 3) {
		if (!tex->loadFromFile("Resources/Images/paschal-candle.png"))
			std::cout << "ERROR::HOLYOBJECT::COULD_NOT_LOAD_TEXTURE" << std::endl;
	}
	//sf::Texture::bind(tex);
	holyObjectSprite.setTexture(*tex);
	size = sf::Vector2f(
		tex->getSize().x,
		tex->getSize().y
	);
	scaleSize = sf::Vector2f(.25f, .25f);
	holyObjectSprite.setScale(scaleSize);
	holyObjectSprite.setOrigin(0, size.y);

	//usedObjects = std::vector<sf::Sprite>();
	holyObjectSprite.setPosition(x, y);
}

void HolyObject::draw(sf::RenderWindow& target) {
	target.draw(holyObjectSprite);
}

HolyObject::~HolyObject()
{
	usedObjects.clear();
}