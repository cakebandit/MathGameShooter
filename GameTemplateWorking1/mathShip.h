#pragma once
#include "SFMLHeader.h"

using namespace sf;

class mathShip {
private:

	RectangleShape mathShipPlaceholder;
	float movespeed = 5;

public:
	mathShip(int StartY);
	Vector2f position;

	int mathEquation1;
	int mathEquation2;
	int answer;

	FloatRect getPosition();

	RectangleShape getShape();

	void movementMath();
	
	int mathEquationGuess();

	void Update();
	
};
