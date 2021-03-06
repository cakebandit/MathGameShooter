#pragma once
#include "SFML\Audio.hpp"
#include "SFML\Config.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Main.hpp"
#include "SFML\Network.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"

using namespace sf;

class commands {
public:
	void exit(RenderWindow& window) {
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}
	}
};
