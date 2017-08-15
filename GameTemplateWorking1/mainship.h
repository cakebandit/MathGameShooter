#pragma once
#include "SFMLHeader.h"

using namespace sf;

class mainShip {
private:

	float movespeed = 3;
	Texture mainShipTexture;
	Sprite mainShipSprite;
	
	RectangleShape shipPlaceholder;
	RectangleShape shipPointer;

public:

	mainShip(float startX, float startY);
	
	Vector2f position;

	FloatRect getPosition();
	FloatRect getPointerPosition();

	Sprite getSprite();
	RectangleShape getPointerShape();

	int answer;

	void moveUp();
	void moveDown();

	void fire(int mathShipPosY, int mainShipPosY, int answer, bool inbounds);
	void Update();
};
