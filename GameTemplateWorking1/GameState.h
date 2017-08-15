#pragma once
#include "SFMLHeader.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace sf;

class gameState {

public:
	
	static int intro(RenderWindow& window);
	static void game(RenderWindow& window);
	static void deathscreen(RenderWindow& window);

};