#include "Scene1_GUI.h"
#include <iostream>

Scene1_GUI::Scene1_GUI() {
	// reserved
}

Scene1_GUI::~Scene1_GUI() {

}

void Scene1_GUI::load() {
	if (!displayFont.loadFromFile("Resources/Fonts/Poppins-ExtraLight.ttf")) {
		std::cout << "ERROR::SCENE1::SCENE1_GUI::load() - COULD_NOT_LOAD_TEXTURE" << std::endl;
	}
}

void Scene1_GUI::init(Vector2f windowSize_) {
	windowSize = windowSize_;
	scoreText.setFont(displayFont);
	healthText.setFont(displayFont);
	availableHolyObjectsText.setFont(displayFont);
	scoreText.setFont(displayFont);
	
}

void Scene1_GUI::update(int score, int health, int availableHolyObjects) {
	scoreText.setString(std::string("Score: ").append(std::to_string(score)));
	healthText.setString(std::string("Health: ") + std::to_string(health).append(std::string("/100")));
	availableHolyObjectsText.setString(std::string("Available Holy Objects: ").append(std::to_string(availableHolyObjects)));
	scoreText.setPosition(8,
		(windowSize.y - (
			(availableHolyObjectsText.getLocalBounds().height
				+ lineHeight
				) + (
					healthText.getLocalBounds().height
					+ lineHeight
					) + (
						scoreText.getLocalBounds().height
						+ lineHeight
						)
			)
			)
	);
	healthText.setPosition(8,
		(windowSize.y - (
			(availableHolyObjectsText.getLocalBounds().height
				+ lineHeight
				) + (
					healthText.getLocalBounds().height
					+ lineHeight
					)
			)
			)
		);
	availableHolyObjectsText.setPosition(8,
		(windowSize.y - (
			availableHolyObjectsText.getLocalBounds().height
			+ lineHeight
			)
		)
	);
}

void Scene1_GUI::draw(RenderWindow& window) {
	window.draw(scoreText);
	window.draw(healthText);
	window.draw(availableHolyObjectsText);
}