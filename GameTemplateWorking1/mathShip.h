#pragma once
#include "SFMLHeader.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace sf;

class mathShip {
private:
	float movespeed = 5;

public:
	Texture mathShipTexture;
	Sprite mathShipSprite;

	mathShip(int StartY);
	Vector2f position;

	int mathEquation1;
	int mathEquation2;
	int answer;

	Text question;

	bool outOfBounds(Vector2f mathposition);
	bool isAlive;

	Sprite getSprite();

	Text getText();

	void movementMath();

	void Update();
	
};
