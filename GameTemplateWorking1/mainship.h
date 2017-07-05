#pragma once
#include "SFMLHeader.h"

using namespace sf;

class mainShip {
private:

	float movespeed = 10;
	
	RectangleShape shipPlaceholder;
	RectangleShape shipPointer;

public:

	mainShip(float startX, float startY);
	
	Vector2f position;

	FloatRect getPosition();
	FloatRect getPointerPosition();

	RectangleShape getShape();
	RectangleShape getPointerShape();

	int answer;

	void moveUp();
	void moveDown();

	void Update();
};
