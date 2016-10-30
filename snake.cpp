#include "snake.h"
#include "changePoint.h"

#include <iostream>

Snake::Snake() {
	int snakeSize = 3;
}

void Snake::keyboardListener() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	 	changeDir(left);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	 	changeDir(right);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	 	changeDir(up);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	 	changeDir(down);
}

void Snake::move(float amount) {
	keyboardListener();
	for ( auto & segment : segments ) {
		segment.move(amount);
	}
}

void Snake::changeDir(Direction dir) {
	direction = dir;
	Segment firstSeg = segments.front();
	sf::Vector2f point = firstSeg.get().getPosition();

	ChangePoint changePoint = {
		point,
		direction
	};

	for ( auto & segment : segments ) {
		segment.addChangePoint(changePoint);
	}
}