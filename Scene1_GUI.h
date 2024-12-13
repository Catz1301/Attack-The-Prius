#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Scene1_GUI {
public:
	Scene1_GUI();
	~Scene1_GUI();
	void load();
	void init(Vector2f windowSize_);
	void update(int score, int health, int availableHolyObjects);
	void draw(RenderWindow& window);

private:
	Vector2f windowSize;
	Font displayFont;
	Text scoreText;
	Text healthText;
	Text availableHolyObjectsText;
	int lineHeight = 5;
};