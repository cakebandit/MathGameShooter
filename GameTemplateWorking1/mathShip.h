#pragma once
#include "SFMLHeader.h"

using namespace sf;

class mathShip {
private:
	Vector2f position;

	RectangleShape mathShipPlaceholder;
	float movespeed = 3;

public:
	mathShip();
	int mathEquation1;
	int mathEquation2;
	int answer;

	FloatRect getPosition();

	RectangleShape getShape();
	
	int mathEquationGuess();

	int spawnMath();
	
};
