#include "SFMLHeader.h"
#include "mainship.h"
#include <iostream>


using namespace sf;

int main() {

	int windowWidth = 480;

	int windowHeight = 600;

	mainShip mainShip(50, 230);

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
		}
		//setting the frame rate limit
		window.setFramerateLimit(60);

		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
			break;
		}

		//colour of background
		window.clear(Color(26, 128, 182, 255));

		window.draw(mainShip.getPointerShape());
		window.draw(mainShip.getShape());

		//Keyboard movements
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			mainShip.moveUp();
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			mainShip.moveDown();
		}

		if (event.type == sf::Event::EventType::KeyPressed) {
			int currentPressedKey = event.key.code;
			if (currentPressedKey == ) {
				std::cout << currentPressedKey;
			}
		}

		window.display();

		mainShip.Update();
	}

}