#include "snake.h"
#include "changePoint.h"
#include "food.h"

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

void Snake::grow() {
	Segment lastSeg = segments.back();
	lastSeg.move(-11);
	segments.push_back(lastSeg);
}

bool Snake::checkForCollision(Food food) {
	sf::FloatRect snakeBox = segments.front().get().getGlobalBounds();
	sf::FloatRect foodBox = food.get().getGlobalBounds();
	return snakeBox.intersects(foodBox);
}

bool Snake::checkForCollision(Segment segment) {
	sf::FloatRect snakeBox = segments.front().get().getGlobalBounds();
	sf::FloatRect segmentBox = segment.get().getGlobalBounds();
	return snakeBox.intersects(segmentBox);
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