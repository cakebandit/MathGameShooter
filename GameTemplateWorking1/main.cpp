#include "SFMLHeader.h"
#include "mainship.h"
#include "mathShip.h"
#include <iostream>
#include <list>
#include <random>


using namespace sf;

int main() {

	int windowWidth = 480;

	int windowHeight = 600;

	int mathShipOnScreen;
	int respawn;

	//text on screen management
	Font font;
	font.loadFromFile("C:/Windows/Fonts/arial.ttf");

	Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("background.jpg")) {
		std::cout << "didntload";
	}
	Sprite background(backgroundTexture);

	Text enteredText;
	enteredText.setFont(font);
	enteredText.setCharacterSize(20);

	std::string str;

	//random declaration
	std::default_random_engine mathShipRandom;
	std::uniform_int_distribution<int> distribution(0, 450);

	//setting enemy and main ship position
	mainShip mainShip(50, 230);

	std::list<mathShip> listMathShip;
	for (int i = 0; i < 10; i++) {
		mathShip ms(distribution(mathShipRandom));
		listMathShip.push_front(ms);
	}
	
	
	//creating a window instance
	RenderWindow window(VideoMode(windowHeight, windowWidth), "Maths Game");
	

	//while the window is open, do events
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}
			if (event.type == Event::TextEntered) {
				if (event.text.unicode == '\b') { // handle backspace explicitly
					str.erase(str.size() - 1, 1);
				}
				else if (event.text.unicode == '\r') {
					std::cout << "okay";
					mainShip.answer = std::stoi(str);
					str.erase(str.size() - str.size());
					
				}
				else if (str.size() < 5) {
					if (event.text.unicode < 60) {
						str += static_cast<char>(event.text.unicode);
					}
				}
				enteredText.setString(str);
				std::cout << str.size();
			}

		}
		
		

		//setting the frame rate limit
		window.setFramerateLimit(60);

		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
			break;
		}

		//colour of background
		window.clear(Color(26, 128, 182, 255));

		window.draw(background);
		window.draw(mainShip.getPointerShape());
		window.draw(mainShip.getShape());
		for (mathShip& ms : listMathShip) {
			window.draw(ms.getShape());
		}
		
		window.draw(enteredText);
		

		//Keyboard movements
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			mainShip.moveUp();
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			mainShip.moveDown();
		}
		
		enteredText.setPosition(mainShip.position.x, mainShip.position.y - 30);
		for (mathShip& ms : listMathShip) {
			ms.movementMath();
		}
		
		
		window.display();

		mainShip.Update();
		for (mathShip& ms : listMathShip) {
			ms.Update();
		}
		
		
	}

}
