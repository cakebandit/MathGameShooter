#include "SFMLHeader.h"
#include "mainship.h"
#include <iostream>
#include <string>


using namespace sf;

mainShip::mainShip(float startX, float startY) {
	position.x = startX;
	position.y = startY;

	shipPointer.setSize(Vector2f(800, 1));

	if (!mainShipTexture.loadFromFile("spaceship2.png")) {
		std::cout << "didntload";
	}
	mainShipSprite.setTexture(mainShipTexture);
	mainShipSprite.setRotation(90);
	mainShipSprite.setScale(0.3, 0.3);
	

	mainShipSprite.setPosition(position);
	shipPointer.setPosition(position.x - 50, position.y - 10);
}


FloatRect mainShip::getPosition()
{
	return mainShipSprite.getGlobalBounds();
}

FloatRect mainShip::getPointerPosition() 
{
	return shipPointer.getGlobalBounds();
}

//gets ship shape for displaying
Sprite mainShip::getShape()
{
	return mainShipSprite;
}

//gets pointershape for displaying
RectangleShape mainShip::getPointerShape() 
{
	return shipPointer;
}


void mainShip::moveUp() {
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		if (position.y >= 5) {
			position.y = position.y - movespeed;
		}
	}
	
	
}

void mainShip::moveDown() {
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		if (position.y <= 451) {
			position.y = position.y + movespeed;
		}
	}
	
}

//Updates the position of the ship's texture
void mainShip::Update() {
	mainShipSprite.setPosition(position.x + 50, position.y - 10);
	shipPointer.setPosition(position.x, position.y + 10);

	//std::cout << position.y;
}

void mainShip::fire(int mathShipPosY, int mainShipPosY, int answer, bool inbounds) {
	//if (mathShipPosY == mainShipPosY && ) {
		//
	//}
}