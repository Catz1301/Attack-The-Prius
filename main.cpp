#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

using namespace sf;

Texture muskHeadTex, priusTransparentTex; // Elon Musk tex, prius tex
Sprite muskHead, prius; // Elon Musk sprite, and Prius sprite
int max = 10; // Maximum number of Random numbers to be generated
int total = 0; // Total number of random numbers generated so far

// TODO: Hide cursor, so that Elon Musk appears to be the cursor. He is worthy. :)

RenderWindow window(VideoMode::getDesktopMode(), "SFML Window", Style::None | Style::Fullscreen);
//Vector2f muskPos(Vector2f(0,0));
bool showPos = true; // boolean to decide on showing Elon Musks' Position
bool showRandNums = false; // boolean to decide on showing random numbers
bool priusHide = false; // boolean to decide on showing the prius

int main() {
	
	if (!muskHeadTex.loadFromFile("Resources/Images/elon_musk_cropped.png")) {
		throw "ERROR::MAIN::COULD_NOT_LOAD_TEXTURE";
	}
	
	if (!priusTransparentTex.loadFromFile("Resources/Images/transparent_prius.png")) {
		throw "ERROR::MAIN::COULD_NOT_LOAD_TEXTURE";
	}
	muskHead.setTexture(muskHeadTex);
	muskHead.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);
	prius.setTexture(priusTransparentTex);

	while (window.isOpen()) {

		Event e;
		while (window.pollEvent(e)) {

			if (e.type == Event::Closed)
				window.close();

			if (e.type == Event::KeyPressed) {
				if (e.key.code == Keyboard::Escape)
					window.close();
			}

			if (Keyboard::isKeyPressed(Keyboard::Up))
				muskHead.move(0, -2);
			else if (Keyboard::isKeyPressed(Keyboard::Down))
				muskHead.move(0, 2);
			else if (Keyboard::isKeyPressed(Keyboard::Left))
				muskHead.move(-2, 0);
			else if (Keyboard::isKeyPressed(Keyboard::Right))
				muskHead.move(2, 0);
			else if (e.type == Event::KeyPressed) {
				if (e.key.code == Keyboard::P) {
					if (showPos == true)
						showPos = false;
					else if (showPos == false)
						showPos = true;
				}
				else if (e.key.code == Keyboard::R) {
					if (showRandNums == true)
						showRandNums = false;
					else if (showRandNums == false)
						showRandNums = true;
				}
				else if (e.key.code == Keyboard::S)
					priusHide = false;
			}
			else if (e.type == Event::MouseButtonPressed) {
				if (Mouse::isButtonPressed(Mouse::Button::Left)) {
					Vector2f priusStart = Vector2f(prius.getPosition().x, prius.getPosition().y);
					Vector2f priusEnd = Vector2f(
						priusStart.x + priusTransparentTex.getSize().x,
						priusStart.y + priusTransparentTex.getSize().y
					);
					Vector2f mouse = Vector2f(
						Mouse::getPosition().x,
						Mouse::getPosition().y
					);
					
					if (mouse.x >= priusStart.x && mouse.x <= priusEnd.x) {
						if (mouse.y >= priusStart.y && mouse.y <= priusEnd.y) {
							priusHide = true;
						}
					}
				}
			}
			// I'm so very sorry :(
			/*if (e.type == Mouse::isButtonPressed(Mouse::Button::Left))*/
				/*muskHead.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);*/
			
		}
		if (showPos)
			std::cout << "X: " << muskHead.getPosition().x << " Y: " << muskHead.getPosition().y << std::endl;
		if (showRandNums) {
			if (total <= max) {
				std::cout << rand();
				total++;
			}
		}
		muskHead.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);
		window.clear();
		if (!priusHide)
			window.draw(prius);
		window.draw(muskHead);
		window.display();
	}
}




/*

	Good Bye! ;)

*/