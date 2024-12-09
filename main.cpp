#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Prius.h"
#include <vector>
#include <time.h>
#include <sstream>
#include "ElonBullet.h"
#include "HolyObject.h"
#include "Player.h"

// Every 5 points (in score), give a new holy object. Holy objects will be used to attack the bad prii. 
//   Don't waste holy objects.
// For every bad prius that gets through, the demonic goat queen will get stronger.
// For every bad prius attacked without holy objects, health will diminish. play evil goat scream
// Maybe holy water can help restore health

// ------ LONG TERM TODO -------
// TODO: Make a scene manager class
// TODO: Move object makers and removers to an object management file.
// TODO: Find demonic goat queen

// TODO: Add a demonic goat queen strength bar in the bottom left corner.
// TODO: Add a health bar at the bottom left corner, under strength bar.
// TODO: Make game over effective.

// ------ TOP PIORITY --------
// TODO: Properly calculate score, and award holy objects
// TODO: Add a holy object count that displays a holy object for every holy object currently held. display under health
// bar


using namespace sf;

int main();

void removePrius(std::vector<Prius>& vect, size_t pos);
void makeNewPrius(std::vector<Prius>& vect, int q = 1);
void removeElonBullet(std::vector<ElonBullet>& vect, size_t pos);
void makeNewElonBullet(std::vector<ElonBullet>& vect, float xPos, float yPos);

Texture muskHeadTex; // Elon Musk Texture
Texture priusTransparentTex; // Prius Texture
Texture missPriusTex; // Miss Prius Texture

Sprite muskHead; // Elon Musk sprite

int score = 0;
int numOfChildren = 3;
int ending_prius = -1;
int health = 100;
bool GAME_OVER = false;
sf::Vector2f windowSize;

RenderWindow window(VideoMode::getDesktopMode(), "Attack the Prius!", Style::None | Style::Fullscreen, sf::ContextSettings(0, 0, 3, 1, 1, 0, false));
// TODO: Hide cursor, so that Elon Musk appears to be the cursor. He is worthy. :)
sf::Color meowColor = sf::Color(0, 0, 0);

Vector2f size = Vector2f(50, 50);
std::vector<Prius> prii;
std::vector<ElonBullet> elonBullets;

bool inflictDamage() {
	health -= 5;
	return (health <= 0);
}

//sf::Text priiScore;
//sf::Font fnt;
int main() {
	/*ContextSettings settings;
	settings.antialiasingLevel = 3;*/

	srand(time(0));
	window.setFramerateLimit(60);
	windowSize = Vector2f(window.getSize().x, window.getSize().y);

	if (!muskHeadTex.loadFromFile("Resources/Images/elon_musk_cropped.png")) {
		//throw std::exception("ERROR::MAIN::COULD_NOT_LOAD_TEXTURE");
		std::cout << "ERROR::MAIN::COULD_NOT_LOAD_TEXTURE" << std::endl;
	}
	if (!priusTransparentTex.loadFromFile("Resources/Images/transparent_prius.png")) {
		//throw std::exception("ERROR::MAIN::COULD_NOT_LOAD_TEXTURE");
		std::cout << "ERROR::MAIN::COULD_NOT_LOAD_TEXTURE" << std::endl;
	}
	if (!missPriusTex.loadFromFile("Resources/Images/detgen_prius.png")) {
		//throw std::exception("ERROR::MAIN::COULD_NOT_LOAD_TEXTURE");
		std::cout << "ERROR::MAIN::COULD_NOT_LOAD_TEXTURE" << std::endl;
	}
	/*if (!fnt.loadFromFile("Resources/Fonts/Poppins-ExtraLight.ttf")) {
		throw std::exception("ERROR::MAIN::COULD_NOT_LOAD_FONT");
	}*/

	Image priusImage = priusTransparentTex.copyToImage();
	window.setIcon(priusImage.getSize().x, priusImage.getSize().y, priusImage.getPixelsPtr());
	muskHeadTex.setSmooth(true); // Smoothen Elon Musk's head
	muskHead.setTexture(muskHeadTex);

	// Set muskHead origin for transformations to center
	muskHead.setOrigin(muskHead.getTexture()->getSize().x / 2, muskHead.getTexture()->getSize().y / 2);
	muskHead.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);

	window.setMouseCursorVisible(false); // Hide mouse curser
	priusTransparentTex.setSmooth(true);

	//Player player = Player(&window);
	
	//t.asMilliseconds();
	for (int i = 0; i < 5; i++) {
		makeNewPrius(prii);
		//player.makeNewPrius();
	}
	HolyObject test = HolyObject(window.getSize().x / 2, window.getSize().y / 2);

	//mve.openFromFile("Resources/Videos/Test.mp4");
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
				if (e.key.code == Keyboard::C) { // Is 's' is pressed
					prii.clear(); // Remove all Prii from vector<Prius>

					for (int i = 0; i < 5; i++) {
						makeNewPrius(prii);
					}

				}
				/*else if (e.key.code == Keyboard::P) {
					if (mve.getStatus() != sfe::Playing)
						mve.play();
				}*/
			}
			else if (e.type == Event::MouseButtonPressed) {
				if (Mouse::isButtonPressed(Mouse::Button::Left)) { // For good prii

					Vector2f mouse = Vector2f(Mouse::getPosition().x, Mouse::getPosition().y);
					makeNewElonBullet(elonBullets, mouse.x, mouse.y);
					std::cout << "elonBullet_X: " << mouse.x << " | elonBullet_Y " << mouse.y << std::endl;
					int topPrius = -1;
//					for (int i = 0; i < prii.size(); i++) {
//						if (prii[i].isShot(mouse.x, mouse.y)) {
//							topPrius = i;
//						}
//					}
//
//					if (topPrius != -1) {
//						if (!prii[topPrius].isDangerous()) {
//							int giveChildren = std::rand();
//							if (topPrius < prii.size() - 1) {
//								removePrius(prii, topPrius);
//								makeNewPrius(prii);
////								if (giveChildren % 32 == 0)
//	//								numOfChildren++;
//							}
//							else {
//								prii.pop_back();
//								makeNewPrius(prii);
//								//score++;
//								//if (giveChildren % 32 == 0)
//									//numOfChildren++;
//							}
//						}
//						else {
//							prii[topPrius].setOrigin(
//								prii[topPrius].getPosition().x - prii[topPrius].getSize().x / 2,
//								prii[topPrius].getPosition().y - prii[topPrius].getSize().y / 2);
//
//							prii[topPrius].setScale(2, 2);
//							if (prii[topPrius].getFacingLeft())
//								prii[topPrius].setPosition(0, 0);
//							else
//								prii[topPrius].setPosition(window.getSize().x, 0);
//							GAME_OVER = true;
//							for (int i = 0; i < prii.size(); i++) {
//								prii[i].stop();
//							}
//							ending_prius = topPrius;
//							//numOfChildren--;
//						}
					//}
				}
				else if (Mouse::isButtonPressed(Mouse::Button::Right)) { // for dangerous Prii
					Vector2f mouse = Vector2f(Mouse::getPosition().x, Mouse::getPosition().y);
					makeNewElonBullet(elonBullets, mouse.x, mouse.y);
					std::cout << "elonBullet_X: " << mouse.x << " | elonBullet_Y " << mouse.y << std::endl;
					int topPrius = -1;
					//for (int i = 0; i < prii.size(); i++) {
					//	if (prii[i].isShot(mouse.x, mouse.y)) {
					//		topPrius = i;
					//	}
					//}

					//if (topPrius != -1) {
					//	if (!prii[topPrius].isDangerous()) {
					//		if (topPrius < prii.size() - 1) {
					//			removePrius(prii, topPrius);
					//			makeNewPrius(prii);
					//			//score++;
					//			//numOfChildren--;
					//		}
					//		else {
					//			prii.pop_back();
					//			makeNewPrius(prii);
					//			//score++;
					//			//numOfChildren--;
					//		}
					//	}
					//	else {
					//		prii[topPrius].setOrigin(
					//			prii[topPrius].getPosition().x - prii[topPrius].getSize().x / 2,
					//			prii[topPrius].getPosition().y - prii[topPrius].getSize().y / 2);

					//		prii[topPrius].setScale(2, 2);
					//		if (prii[topPrius].getFacingLeft())
					//			prii[topPrius].setPosition(0, 0);
					//		else
					//			prii[topPrius].setPosition(window.getSize().x, 0);
					//		//GAME_OVER = true;
					//		// for (int i = 0; i < prii.size(); i++) {
					//		// 	prii[i].stop();
					//		// }
					//		ending_prius = topPrius;
					//		numOfChildren--;
					//	}
					//}
				}
			}
			// I'm so very sorry :(
			/*if (e.type == Mouse::isButtonPressed(Mouse::Button::Left))*/
				/*muskHead.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);*/

		}
		if (GAME_OVER) {
			meowColor = sf::Color(255, 0, 0);
		}
		if (numOfChildren <= 0)
			GAME_OVER = true;
		//priiPos.setFillColor(Color(0xFFF));
		/*priiPos.setFont(Font::loadFromFile())*/
		//if (GAME_OVER == false) {
		muskHead.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);
		window.clear(Color(meowColor));

		for (int i = 0; i < prii.size(); i++) {
			prii[i].update(elonBullets, dt.asSeconds());
			if (prii[i].attacked) {
				if (prii[i].isDangerous()) {
					if (inflictDamage())
						GAME_OVER = true;
				} else {
					score++;
				}
				removePrius(prii, i);
				makeNewPrius(prii);
				continue;
			} 
			if (prii[i].isOffScreen(window.getSize().x)) {
				removePrius(prii, i);
				makeNewPrius(prii);
				score--;
			}
			prii[i].draw(window);
		}

		for (int i = 0; i < elonBullets.size(); ++i) {
			elonBullets[i].update(dt.asSeconds());
			if (elonBullets[i].dead) {
				removeElonBullet(elonBullets, i);
				//break;
			}
			if (elonBullets.size() != 0)
				elonBullets[i].draw(window);
		}

		//priiScore.setString("Score: " + );
		//prii[2].move(dt.asSeconds());
		test.draw(window);
		window.draw(muskHead);
		//mve.update();
		//window.draw(mve);

	//}
	//else {
		//window.clear(Color(255, 0, 0, 127));
		//prii[ending_prius].draw(window);
	//}
		window.display();

		dt = clck.restart();
	}

	return 0;
}


////////////////////////////////////////////////////////////////////////
/// Moves all elements of vector vect (starting from pos) to the left.
/// This will result in two copies of the last element for a very short
/// time, but the last element of the vector will be removed in the next
/// instruction of the method.
////////////////////////////////////////////////////////////////////////
void removePrius(std::vector<Prius>& vect, size_t pos) {
	if (pos < vect.size() - 1 && pos >= 0) {
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

void makeNewPrius(std::vector<Prius>& vect, int q) {
	if (q > 2)
		q = 2;
	for (int i = 0; i < 1; i++) {
		int direction = std::rand();
		int bad_prius = std::rand();
		float x;
		float y = rand() % window.getSize().y;
		if (direction % 2 == 0)
			x = 10 + window.getSize().x;
		else
			x = -50;

		//float x = 100; //rand() % window.getSize().x + 100;
		//float y = rand() % window.getSize().y;
		//else {
			//float x = -50;
			//x += window.getSize().x;
			//float y = rand() % window.getSize().y;
		//}
		//if (x > 100 + window.getSize().x - priusTransparentTex.getSize().x)
			//x -= 100;//priusTransparentTex.getSize().x;

		if (y > window.getSize().y - priusTransparentTex.getSize().y)
			y -= priusTransparentTex.getSize().y;
		int speed = 3 + (std::rand() % 5);

		speed *= 100;

		if (bad_prius % 5 == 0) {
			if (direction % 2 == 0)
				vect.push_back(Prius(missPriusTex, Vector2f(x, y), size, windowSize, true, true, speed));
			else if (direction % 2 == 1)
				vect.push_back(Prius(missPriusTex, Vector2f(x, y), size, windowSize, true, false, 50));
		}
		else {
			if (direction % 2 == 0)
				vect.push_back(Prius(priusTransparentTex, Vector2f(x, y), size, windowSize, false, true, speed));
			else if (direction % 2 == 1)
				vect.push_back(Prius(priusTransparentTex, Vector2f(x, y), size, windowSize, false, false, 50));
		}
	}

	/*prii[0].setColor(Color::Blue);
	prii[1].setColor(Color::Cyan);
	prii[2].setColor(Color::Green);
	prii[3].setColor(Color::Magenta);
	prii[4].setColor(Color::Red);*/
}

void removeElonBullet(std::vector<ElonBullet>& vect, size_t pos) {
	if (pos < vect.size() - 1 && pos >= 0) {
		do {
			// Simulate a call. remove(prii, 2);
			vect[pos] = vect[pos + 1]; // vect[2] = vect[3] -- true values (not starting on 0): vect[3] = vect[4]
			pos++;                     // pos = 3
									   // vect[3] = vect[4]
									   // pos = 4
		} while (pos < vect.size() - 1); //terminate -- final result: [0 1 3 4 4]
		vect.pop_back();
	}
	
	else if (pos == vect.size() - 1) {
		vect.pop_back();
	}
}
void makeNewElonBullet(std::vector<ElonBullet>& vect, float xPos, float yPos) {
	vect.push_back(ElonBullet(muskHeadTex, xPos, yPos));
}