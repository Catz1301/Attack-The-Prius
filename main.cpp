#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Prius.h"
#include <vector>
#include <time.h>
#include <sstream>
using namespace sf;

void removePrius(std::vector<Prius> &vect, size_t pos);
void makeNewPrius(std::vector<Prius>& vect, int q = 1);

Texture muskHeadTex, priusTransparentTex; // Elon Musk tex, prius tex
Sprite muskHead; // Elon Musk sprite
int score = 0;
int quanti = 1;


// TODO: Hide cursor, so that Elon Musk appears to be the cursor. He is worthy. :)

RenderWindow window(VideoMode::getDesktopMode(), "Attack the Prius!", Style::None | Style::Fullscreen);

Vector2f size(50, 50);
std::vector<Prius> prii;
//sf::Text priiScore;
//sf::Font fnt;
int main() {
	
	srand(time(0));
	window.setFramerateLimit(30);

	if (!muskHeadTex.loadFromFile("Resources/Images/elon_musk_cropped.png")) {
		throw std::exception("ERROR::MAIN::COULD_NOT_LOAD_TEXTURE");
	}
	if (!priusTransparentTex.loadFromFile("Resources/Images/transparent_prius.png")) {
		throw std::exception("ERROR::MAIN::COULD_NOT_LOAD_TEXTURE");
	}
	/*if (!fnt.loadFromFile("Resources/Fonts/Poppins-ExtraLight.ttf")) {
		throw std::exception("ERROR::MAIN::COULD_NOT_LOAD_FONT");
	}*/

	Image priusImage = priusTransparentTex.copyToImage();

	muskHeadTex.setSmooth(true); // Smoothen Elon Musk's head
	muskHead.setTexture(muskHeadTex);

	// Set muskHead origin for transformations to center
	muskHead.setOrigin(muskHead.getTexture()->getSize().x / 2, muskHead.getTexture()->getSize().y / 2);
	muskHead.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);
	
	window.setMouseCursorVisible(false); // Hide mouse curser
	
	//t.asMilliseconds();
	for (int i = 0; i < 5; i++) {
		float x = rand() % window.getSize().x;
		float y = rand() % window.getSize().y;

		if (x > window.getSize().x - priusTransparentTex.getSize().x)
			x -= priusTransparentTex.getSize().x;

		if (y > window.getSize().y - priusTransparentTex.getSize().y)
			y -= priusTransparentTex.getSize().y;

		prii.push_back(Prius(priusTransparentTex, Vector2f(x, y), size)); // Add new Prius to back of vector<Prius>
	}
	/*prii[0].setScale(1, 1);
	prii[1].setScale(0.5, 0.5);

	prii[0].setColor(Color::Blue);
	prii[1].setColor(Color::Cyan);
	prii[2].setColor(Color::Green);
	prii[3].setColor(Color::Magenta);
	prii[4].setColor(Color::Red);*/
	Clock clck;
	Time dt;

	/*priiScore.setFillColor(Color::White);
	priiScore.setCharacterSize(80);
	priiScore.setColor(sf::Color(0xFFFFFF));
	priiScore.setFont(fnt);
	priiScore.setPosition(50, 50);*/
	while (window.isOpen()) {
		
		
		
		Event e;
		while (window.pollEvent(e)) {

			if (e.type == Event::Closed)
				window.close();

			if (e.type == Event::KeyPressed) {
				if (e.key.code == Keyboard::Escape) {
					prii.clear();
					window.close();
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Up)) {
				muskHead.move(0, -2);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Down)) {
				muskHead.move(0, 2);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Left)) {
				muskHead.move(-2, 0);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right)) {
				muskHead.move(2, 0);
			}
			else if (e.type == Event::KeyPressed) {
				if (e.key.code == Keyboard::S) { // Is 's' is pressed
					prii.clear(); // Remove all Prii from vector<Prius>

					for (int i = 0; i < 5; i++) {
						float x = rand() % window.getSize().x;
						float y = rand() % window.getSize().y;

						if (x > window.getSize().x - priusTransparentTex.getSize().x)
							x -= priusTransparentTex.getSize().x;

						if (y > window.getSize().y - priusTransparentTex.getSize().y)
							y -= priusTransparentTex.getSize().y;

						prii.push_back(Prius(priusTransparentTex, Vector2f(x, y), size));
					}
					/*prii[0].setColor(Color::Blue);
					prii[1].setColor(Color::Cyan);
					prii[2].setColor(Color::Green);
					prii[3].setColor(Color::Magenta);
					prii[4].setColor(Color::Red);*/
				}
			}
			else if (e.type == Event::MouseButtonPressed) {
				if (Mouse::isButtonPressed(Mouse::Button::Left)) {
					
					Vector2f mouse = Vector2f(Mouse::getPosition().x, Mouse::getPosition().y);
					
					int topPrius = -1;
					for (int i = 0; i < prii.size(); i++) {
						if (prii[i].isShot(mouse.x, mouse.y)) {
							topPrius = i;
						}
					}

					if (topPrius != -1) {
						if (topPrius < prii.size() - 1) {
							removePrius(prii, topPrius);
							makeNewPrius(prii, quanti);
							score++;
						}
						else {
							prii.pop_back();
							makeNewPrius(prii, quanti);
							score++;
						}
					}
				}
			}
			// I'm so very sorry :(
			/*if (e.type == Mouse::isButtonPressed(Mouse::Button::Left))*/
				/*muskHead.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);*/
			
		}
		
		
		//priiPos.setFillColor(Color(0xFFF));
		/*priiPos.setFont(Font::loadFromFile())*/
		muskHead.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);
		window.clear(Color(0, 0, 0, 100));
		
		for (int i = 0; i < prii.size(); i++) {
			prii[i].update(dt.asSeconds());
			if (prii[i].isOffScreen()) {
				removePrius(prii, i);
				makeNewPrius(prii);
				score--;
			}
			prii[i].draw(window);
		}
		
		//priiScore.setString("Score: " + );
		prii[2].move(dt.asSeconds());
		window.draw(muskHead);
		window.display();
		if (score % 10 == 0 && score != 0) {
			quanti = score/10;
		}
		dt = clck.restart();
	}
}


////////////////////////////////////////////////////////////////////////
/// Moves all elements of vector vect (starting from pos) to the left.
/// This will result in two copies of the last element for a very short
/// time, but the last element of the vector will be removed in the next
/// instruction of the method.
////////////////////////////////////////////////////////////////////////
void removePrius(std::vector<Prius> &vect, size_t pos) {
	if (pos < vect.size()-1 && pos >= 0) {
		do {
			                           // Simulate a call. remove(prii, 2);
			vect[pos] = vect[pos + 1]; // vect[2] = vect[3] -- true values (not starting on 0): vect[3] = vect[4]
			pos++;                     // pos = 3
									   // vect[3] = vect[4]
			                           // pos = 4
		} while (pos < vect.size() - 1); //terminate -- final result: [0 1 3 4 4]
		vect.pop_back();
	}
	/*else if (pos == vect.size() - 1) {
		vect.pop_back();
	}*/

}

void makeNewPrius(std::vector<Prius> &vect, int q) {
	if (q > 3)
		q = 3;
	for (int i = 0; i < q; i++) {
		float x = 100; //rand() % window.getSize().x + 100;
		float y = rand() % window.getSize().y;
		x += window.getSize().x;
		//if (x > 100 + window.getSize().x - priusTransparentTex.getSize().x)
			//x -= 100;//priusTransparentTex.getSize().x;

		if (y > window.getSize().y - priusTransparentTex.getSize().y)
			y -= priusTransparentTex.getSize().y;

		vect.push_back(Prius(priusTransparentTex, Vector2f(x, y), size));
	}

	/*prii[0].setColor(Color::Blue);
	prii[1].setColor(Color::Cyan);
	prii[2].setColor(Color::Green);
	prii[3].setColor(Color::Magenta);
	prii[4].setColor(Color::Red);*/
}