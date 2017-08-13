#include "SFMLHeader.h"
#include "mainship.h"
#include "mathShip.h"
#include "GameState.h"
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <random>

using namespace sf;

enum state {inIntro, inGame, indeathScreen} switchstate;

int main() {
	int windowWidth = 480;
	int windowHeight = 600;

	RenderWindow window(VideoMode(windowHeight, windowWidth), "Maths Game");
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}
		}

		window.setFramerateLimit(60);
		
		if (switchstate == inGame) {
			gameState::game(window);
		}

		if (switchstate == inIntro) {
			gameState::intro(window);
		}
		
	}

}

int gameState::intro(RenderWindow& window) {
	Font font;
	font.loadFromFile("C:/Windows/Fonts/arial.ttf");

	Text title;
	Text enter;

	title.setFont(font);
	title.setCharacterSize(20);

	enter.setFont(font);
	enter.setCharacterSize(20);

	Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("background.jpg")) {
		std::cout << "didntload";
	}
	Sprite background(backgroundTexture);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}
		}
		title.setString("Endless Space Shooter");
		enter.setString("Press Enter to Continue!");
		title.setPosition(100, 100);
		enter.setPosition(200, 200);


		if (event.type == Event::TextEntered) {

			if (event.text.unicode == '\r') {
				return switchstate = inGame;
				break;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
			break;
		}

		window.clear(Color(26, 128, 182, 255));

		window.draw(background);
		window.draw(title);
		window.draw(enter);

		window.display();

		return switchstate = inIntro;
		break;
	}
}


void gameState::game(RenderWindow& window) {
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

	//List of Ships that have been executed
	std::list<mathShip> listMathShip;
	
	//creating a window instance
	
	//while the window is open, do events
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}
			if (event.type == Event::TextEntered) {
				if (event.text.unicode == '\b') {
					str.erase(str.size() - 1, 1);
				}

				else if (event.text.unicode == '\r') {
					std::cout << "okay";
					if (str.size() > 0) {
						mainShip.answer = std::stoi(str);
						str.erase(str.size() - str.size());
					}
					for (mathShip& ms : listMathShip) {
						while (ms.position.y - 10 < mainShip.position.y < ms.position.y + 10) {
							if (mainShip.answer == ms.answer) {

							}
							
						}
					}
					
					

					
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

		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
			break;
		}
		
		time1 += clock.getElapsedTime();

		//spawning the ships
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
		
		//setting the frame rate limit
		

		//colour of background
		window.clear(Color(26, 128, 182, 255));

		//Rendering each object
		window.draw(background);
		window.draw(mainShip.getPointerShape());
		window.draw(mainShip.getSprite());
		for (mathShip& ms : listMathShip) {
			if (ms.isAlive == true) {
				ms.mathShipSprite.setTexture(ms.mathShipTexture);
				window.draw(ms.getSprite());
				ms.question.setFont(font);
				window.draw(ms.getText());
			}
			}
		
		window.draw(enteredText);
		
		//Keyboard movements
		mainShip.moveUp();
		mainShip.moveDown();

		//Setting Text position
		enteredText.setPosition(mainShip.position.x - 5, mainShip.position.y - 50);

		//Movement of each ship
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



