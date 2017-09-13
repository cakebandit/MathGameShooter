#pragma once
#include "SFMLHeader.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace sf;

class gameState {

public:
	
	static int intro(RenderWindow& window);
	static int game(RenderWindow& window);
	static int deathscreen(RenderWindow& window);

};