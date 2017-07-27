#include "SFMLHeader.h"
#include "mainship.h"
#include <iostream>
#include <string>


using namespace sf;

mainShip::mainShip(float startX, float startY) {
	position.x = startX;
	position.y = startY;

	shipPlaceholder.setSize(Vector2f(60, 25));
	shipPointer.setSize(Vector2f(500, 2));

	shipPlaceholder.setPosition(position);
	shipPointer.setPosition(position.x - 50, position.y - 10);
}


FloatRect mainShip::getPosition()
{
	return shipPlaceholder.getGlobalBounds();
}

FloatRect mainShip::getPointerPosition() 
{
	return shipPointer.getGlobalBounds();
}

//gets ship shape for displaying
RectangleShape mainShip::getShape()
{
	return shipPlaceholder;
}

//gets pointershape for displaying
RectangleShape mainShip::getPointerShape() 
{
	return shipPointer;
}


void mainShip::moveUp() {
	if (position.y >= 5) {
		position.y = position.y - movespeed;
	}
	
}

void mainShip::moveDown() {
	if (position.y <= 451) {
		position.y = position.y + movespeed;
	}
	
	
}

//Updates the position of the ship's texture
void mainShip::Update() {
	shipPlaceholder.setPosition(position);
	shipPointer.setPosition(position.x, position.y + 10);

	//std::cout << position.y;
}

void mainShip::fire(int mathShipPosY, int mainShipPosY) {
	if (mathShipPosY == mainShipPosY) {

	}
}