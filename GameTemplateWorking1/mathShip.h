#pragma once
#include "SFMLHeader.h"
#include <iostream>
#include <string>
#include <time.h>
#include <list>
#include <random>
#include <sstream>

using namespace sf;



class mathShip {

public:

	Texture mathShipTexture;
	Sprite mathShipSprite;

	mathShip(int StartY);
	Vector2f position;

	int mathEquation1 = (rand() % 10);
	int mathEquation2 = (rand() % 10);

	int answer = mathEquation1 + mathEquation2;

	float movespeed = 0.5;

	std::string s;

	Text question;

	int answerquestion(int mainShipAnswer, int score);

	int outOfBounds(int position);
	bool isAlive;

	Sprite getSprite();

	Text getText();

	void movementMath(std::list<mathShip> list);

	void Update();
	
};
