#include "SFMLHeader.h"
#include "mathShip.h"
#include "mainship.h"
#include <cstdlib>

mathShip::mathShip(){
	position.y = rand() % 400;
	position.x = 600;

	mathShipPlaceholder.setSize(Vector2f(60, 25));
	
	int mathEquation1 = (rand() % 10);
	int mathEquation2 = (rand() % 9);

	int answer = mathEquation1 * mathEquation2;

	mathShipPlaceholder.setPosition(position);
}

FloatRect mathShip::getPosition()
{
	return mathShipPlaceholder.getGlobalBounds();
}

RectangleShape mathShip::getShape() {
	return mathShipPlaceholder;
}