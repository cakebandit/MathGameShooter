#include "SFMLHeader.h"
#include "mainship.h"
#include "mathShip.h"
#include "GameState.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <list>
#include <random>

using namespace sf;


int highscoregame = 0;
int currentscore = 0;
commands command;

enum state { inIntro, inGame, indeathScreen } switchstate;

int main() {
	commands command;

	int windowWidth = 480;
	int windowHeight = 600;

	std::ofstream savefile;
	savefile.open("Saves.txt");

	//Creating Window Instance 
	RenderWindow window(VideoMode(windowHeight, windowWidth), "Matematica infinita");

	//Loop
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}
		}

		window.setFramerateLimit(60);
		
		//Handling the states in the main Loop
		if (switchstate == inIntro) {
			gameState::intro(window);
		}
		if (switchstate == inGame) {
			gameState::game(window);
		}
		if (switchstate == indeathScreen) {
			gameState::deathscreen(window);
		}

		
	}

}

int gameState::intro(RenderWindow& window) {
	//Loading Font
	Font font;
	font.loadFromFile("C:/Windows/Fonts/arial.ttf");

	//Creating Title
	Text title;
	Text enter;

	//Setting title
	title.setFont(font);
	title.setCharacterSize(50);

	enter.setFont(font);
	enter.setCharacterSize(20);


	//Loading Textures
	Texture titletexture;
	if (!titletexture.loadFromFile("Title screen.png")) {
		std::cout << "didntload";
	}
	Sprite titlesprite(titletexture);

	Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("background.jpg")) {
		std::cout << "didntload";
	}
	Sprite background(backgroundTexture);

	Texture controlsTexture;
	if (!controlsTexture.loadFromFile("controls.png")) {
		std::cout << "didntload";
	}
	Sprite controls(controlsTexture);


	//Event Loop
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}
		}
		//Displaying title within the instance of the window
		titlesprite.setScale(1.2, 1.2);
		title.setString("Matematica Infinita");
		titlesprite.setPosition(5, 0);
		controls.setPosition(55, 200);

		//Handling Typing and Key Presses using Eventa
		if (event.type == Event::TextEntered) {

			if (event.text.unicode == '\r') {
				return switchstate = inGame;
				break;
			}
		}

		command.exit(window);

		//Drawing objects
		window.clear(Color(26, 128, 182, 255));

		window.draw(background);
		window.draw(titlesprite);
		window.draw(controls);

		window.display();

		//returning the state it is in
		return switchstate = inIntro;
		break;
	}
}

int gameState::game(RenderWindow& window) {
	//Starting Clock
	Clock clock;
	Time time1;

	int score = 0;
	
	//Loading font
	Font font;
	font.loadFromFile("C:/Windows/Fonts/arial.ttf");

	//Loading background textures
	Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("background.jpg")) {
		std::cout << "didntload";
	}
	Sprite background(backgroundTexture);

	//Initializing Score Text
	Text scorebox;
	scorebox.setCharacterSize(20);
	scorebox.setFont(font);
	scorebox.setPosition(30, 20);
	
	//Initializaing Entered Text
	Text enteredText;
	enteredText.setFont(font);
	enteredText.setCharacterSize(20);

	std::string str;


	//setting enemy and main ship position
	mainShip mainShip(50, 230);

	//List of Ships that have been executed
	std::list<mathShip> listMathShip;
	
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
					if (str.size() > 0) {
						str.erase(str.size() - 1, 1);
					}
				}
					

				if (event.text.unicode == '\r') {
					if (str.size() > 0) {
						mainShip.answer = std::stoi(str);
						str.erase(str.size() - str.size());
					}
					for (mathShip& ms : listMathShip) {
						if (ms.isAlive == true) {
							if (mainShip.position.y > ms.position.y - 20 && mainShip.position.y < ms.position.y + 20) {
								ms.answerquestion(mainShip.answer, score);
								if (ms.answer == mainShip.answer) {
									score += 1;
									ms.isAlive = false;
								}
							}
						}

					}
				}
					
				else if(str.size() < 5) {
					if (event.text.unicode < 58 && 47 < event.text.unicode) {
						str += static_cast<char>(event.text.unicode);
					}
				}
				enteredText.setString(str);
			}

		}

		command.exit(window);

		time1 += clock.getElapsedTime();

		//spawning the ships
		if ((rand() % 47 + 200) < time1.asSeconds()) {
			clock.restart();
			time1 = time1 - time1;

			for (int i = 0; i < 1; i++) {
				mathShip ms(rand() % 400 + 20);
				listMathShip.push_front(ms);
				i = 0;
			}
		}

		//colour of background
		window.clear(Color(26, 128, 182, 255));

		//Rendering each object
		window.draw(background);
		window.draw(mainShip.getPointerShape());
		window.draw(mainShip.getSprite());
		window.draw(scorebox);
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
			if (ms.isAlive) {
				ms.movementMath(listMathShip);
				ms.outOfBounds(ms.position.x);
				if (ms.outOfBounds(ms.position.x) == true) {
					return switchstate = indeathScreen, currentscore = score;
					break;
				}
					
			}
			
		}
		window.display();

		scorebox.setString("Score: " + std::to_string(score));
		mainShip.Update();
		for (mathShip& ms : listMathShip) {
			if (ms.isAlive == true) {
				ms.Update();
			}
			
		}
		
	}
	return switchstate = inGame;
}

int gameState::deathscreen(RenderWindow& window) {
	Font font;
	font.loadFromFile("C:/Windows/Fonts/arial.ttf");

	Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("background.jpg")) {
		std::cout << "didntload";
	}
	Sprite background(backgroundTexture);

	Texture yourdead;
	if (!yourdead.loadFromFile("youredead.png")) {
		std::cout << "didntload";
	}
	Sprite yourdeadsprite(yourdead);

	Text highscore;

	if (currentscore > highscoregame) {
		highscoregame = currentscore;
	}
	yourdeadsprite.setScale(1.4, 1.45);
	yourdeadsprite.setPosition(-53, 90);

	highscore.setCharacterSize(20);
	highscore.setFont(font);
	highscore.setPosition(20, 440);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::R)) {
			return switchstate = inGame;
		}


		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			return switchstate = inIntro;
		}


		command.exit(window);
			

		highscore.setString("High Score: " + std::to_string(highscoregame));
		window.draw(background);
		window.draw(yourdeadsprite);
		window.draw(highscore);

		window.display();
	}
}



