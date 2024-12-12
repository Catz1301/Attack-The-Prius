#include "Scene1.h"
using namespace sf;

// TODO: work in the scoring system (confirm it's there)
// TODO: work on a Holy Object display system using a map. the key will be the count, and its value the variant to use for the holy object.
//		The display system will be map container stored as a member of Scene 1. use same varient textures mapped to the number as defined in Holy Object.
// 

Scene1::Scene1(RenderWindow& win) : window(win) {
	ending_prius = NULL;
	health = NULL;
	numOfChildren = NULL;
	score = NULL;
}

void Scene1::loadScene() {
	if (!muskHeadTex.loadFromFile("Resources/Images/elon_musk_cropped.png")) {
		//throw std::exception("ERROR::MAIN::COULD_NOT_LOAD_TEXTURE");
		std::cout << "ERROR::MAIN::COULD_NOT_LOAD_TEXTURE" << std::endl;
	}
	if (!priusTransparentTex.loadFromFile("Resources/Images/transparent_prius.png")) {
		std::cout << "ERROR::SCENE1::COULD_NOT_LOAD_TEXTURE" << std::endl;
	}
	if (!missPriusTex.loadFromFile("Resources/Images/detgen_prius.png")) {
		std::cout << "ERROR::SCENE1::COULD_NOT_LOAD_TEXTURE" << std::endl;
	}
}

void Scene1::initScene() {
	score = 0;
	numOfChildren = 3;
	ending_prius = -1;
	health = 100;
	size = Vector2f(50, 50);
	windowSize = Vector2f(window.getSize().x, window.getSize().y);
	priusImage = priusTransparentTex.copyToImage();
	muskHeadTex.setSmooth(true);
	muskHead.setTexture(muskHeadTex);
	window.setMouseCursorVisible(false);
	muskHead.setOrigin(muskHead.getTexture()->getSize().x / 2, muskHead.getTexture()->getSize().y / 2);
	priusTransparentTex.setSmooth(true);

	for (int i = 0; i < 5; i++) {
		makeNewPrius(prii);
	}

}

void Scene1::updateScene(Event &e, Time dt)
{
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
	if (e.type == Event::KeyPressed) {
		if (e.key.code == Keyboard::C) { // Is 's' is pressed
			prii.clear(); // Remove all Prii from vector<Prius>

			for (int i = 0; i < 5; i++) {
				makeNewPrius(prii);
			}

		}

	}
	else if (e.type == Event::MouseButtonPressed) {
		if (Mouse::isButtonPressed(Mouse::Button::Left)) { // For good prii

			Vector2f mouse = Vector2f(Mouse::getPosition().x, Mouse::getPosition().y);
			makeNewElonBullet(elonBullets, mouse.x, mouse.y);
			std::cout << "elonBullet_X: " << mouse.x << " | elonBullet_Y " << mouse.y << std::endl;
			int topPrius = -1;
			//					
		}
		else if (Mouse::isButtonPressed(Mouse::Button::Right)) { // for dangerous Prii
			Vector2f mouse = Vector2f(Mouse::getPosition().x, Mouse::getPosition().y);
			makeNewElonBullet(elonBullets, mouse.x, mouse.y);
			std::cout << "elonBullet_X: " << mouse.x << " | elonBullet_Y " << mouse.y << std::endl;
			int topPrius = -1;
		}
	}

	muskHead.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);
	for (int i = 0; i < prii.size(); i++) {
		if (i < prii.size())
			prii[i].update(elonBullets, dt.asSeconds());
		if (i < prii.size()) {
			if (prii[i].attacked) {
				if (prii[i].isDangerous()) {
					//playerDamage?
					health -= 5;
				}
				else {
					score++;
				}
				if (i < prii.size())
					removePrius(prii, i);
				makeNewPrius(prii);
				continue;
			}
		}
		if (i < prii.size()) {
			if (prii[i].isOffScreen(window.getSize().x)) {
				if (i < prii.size())
					removePrius(prii, i);
				makeNewPrius(prii);
				score--;
			}
		}
	}

	for (int i = 0; i < elonBullets.size(); ++i) {
		elonBullets[i].update(dt.asSeconds());
		if (elonBullets[i].dead) {
			removeElonBullet(elonBullets, i);
			//break;
		}
	}
}

void Scene1::drawScene()
{
	for (int i = 0; i < prii.size(); i++) {
		if (i < prii.size()) {
			prii[i].draw(window);
		}
	}
	for (int i = 0; i < elonBullets.size(); i++) {
		elonBullets[i].draw(window);
	}
	window.draw(muskHead);

	window.display();
}

void Scene1::unloadScene() {
	//delete& muskHeadTex;
	//delete& priusTransparentTex;
	//delete& missPriusTex;
	prii.clear();
	elonBullets.clear();
}


////////////////////////////////////////////////////////////////////////
/// Moves all elements of vector vect (starting from pos) to the left.
/// This will result in two copies of the last element for a very short
/// time, but the last element of the vector will be removed in the next
/// instruction of the method.
////////////////////////////////////////////////////////////////////////
void Scene1::removePrius(std::vector<Prius>& vect, size_t pos)
{
	if (pos < vect.size() -1 && pos >= 0) {
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

void Scene1::removeAttackedPrius(std::vector<Prius>& vect) {
	int markedIndex = -1;
	for (int i = 0; i < vect.size(); i++) {
		if (i < vect.size()) {
			if (vect[i].attacked == true) {
				markedIndex = i;
			}
		}
	}

	// n y n n n
	// 0 1
	// vect.begin() = 0
	// vect.begin() + 1 = 1

	/*
	std::vector<int> numbers = {1, 2, 3, 4, 5};

	// Remove the element at index 2 (which is the value 3)
	if (numbers.size() > 2) {
		numbers.erase(numbers.begin() + 2);
	}
	*/
	vect.erase(vect.begin() + markedIndex);
}

void Scene1::makeNewPrius(std::vector<Prius>& vect, int q)
{
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

void Scene1::removeElonBullet(std::vector<ElonBullet>& vect, size_t pos)
{
	vect.erase(vect.begin() + pos);
	//if (pos < vect.size() - 1 && pos >= 0) {
	//	do {
	//		// Simulate a call. remove(prii, 2);
	//		vect[pos] = vect[pos + 1]; // vect[2] = vect[3] -- true values (not starting on 0): vect[3] = vect[4]
	//		pos++;                     // pos = 3
	//								   // vect[3] = vect[4]
	//								   // pos = 4
	//	} while (pos < vect.size() - 1); //terminate -- final result: [0 1 3 4 4]
	//	vect.pop_back();
	//}

	//else if (pos == vect.size() - 1) {
	//	vect.pop_back();
	//}
}

void Scene1::makeNewElonBullet(std::vector<ElonBullet>& vect, float xPos, float yPos)
{
	vect.push_back(ElonBullet(muskHeadTex, xPos, yPos));
}

void Scene1::removeHolyObject(std::vector<HolyObject>& vect, size_t pos)
{
	// TODO: Implement Method
}

void Scene1::makeNewHolyObject(std::vector<HolyObject>& vect, float xPos, float yPos)
{
	// TODO: Implement Method
}
