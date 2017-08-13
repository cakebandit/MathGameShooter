#include "SFMLHeader.h"
#include "mainship.h"
#include "mathShip.h"
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <random>

using namespace sf;

int main() {
	
	int windowWidth = 480;

	int windowHeight = 600;

	Clock clock;
	Time time1;
	


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
	std::uniform_int_distribution<int> distribution(0, 400);
	std::uniform_int_distribution<int> randomnumber(463, 500);

	//setting enemy and main ship position
	mainShip mainShip(50, 230);

	std::list<mathShip> listMathShip;
	
	
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
		
		
		time1 += clock.getElapsedTime();

		if (randomnumber(mathShipRandom) < time1.asSeconds()) {
			std::cout << "meme";
			clock.restart();
			time1 = time1 - time1;

			for (int i = 0; i < 1; i++) {
				mathShip ms(distribution(mathShipRandom));
				listMathShip.push_front(ms);
				i = 0;
			}
		}

		//for (mathShip& ms : listMathShip) {
			//if (mainShip.position.y == ms.position.y) {
				
			//}
		//}
		
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
		window.draw(mainShip.getSprite());
		for (mathShip& ms : listMathShip) {
			ms.mathShipSprite.setTexture(ms.mathShipTexture);
			window.draw(ms.getSprite());

			ms.question.setFont(font);
			window.draw(ms.getText());
		}
		
		window.draw(enteredText);
		

		//Keyboard movements
		
		mainShip.moveUp();
		mainShip.moveDown();

		enteredText.setPosition(mainShip.position.x - 5, mainShip.position.y - 50);
		for (mathShip& ms : listMathShip) {
			ms.movementMath();
		}
		
		window.display();

		mainShip.Update();
		for (mathShip& ms : listMathShip) {
			ms.Update();
			ms.outOfBounds(ms.position);
		}
		
	
	}

}

