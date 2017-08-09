#pragma once
#include "SFMLHeader.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace sf;

class mathShip {
private:

	Text question;
	RectangleShape mathShipPlaceholder;
	float movespeed = 5;

public:
	mathShip(int StartY);
	Vector2f position;

	int mathEquation1;
	int mathEquation2;
	int answer;

	bool outOfBounds(Vector2f mathposition);

	FloatRect getPosition();

	RectangleShape getShape();

	Text getText();

	void movementMath();
	
	int mathEquationGuess();

	void Update();
	
};
