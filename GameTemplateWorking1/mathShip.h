#pragma once
#include "SFMLHeader.h"
#include <iostream>
#include <string>
#include <time.h>
#include <random>
#include <sstream>

using namespace sf;



class mathShip {
private:
	float movespeed = 0.5;

public:

	Texture mathShipTexture;
	Sprite mathShipSprite;

	mathShip(int StartY);
	Vector2f position;

	int mathEquation1 = (rand() % 10);
	int mathEquation2 = (rand() % 10);

	int answer = mathEquation1 + mathEquation2;
	

	std::string s;

	Text question;

	int answerquestion(int mainShipAnswer);

	bool outOfBounds(Vector2f mathposition);
	bool isAlive;

	Sprite getSprite();

	Text getText();

	void movementMath();

	void Update();
	
};
