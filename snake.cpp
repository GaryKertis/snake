#include "snake.h"
#include "changePoint.h"
#include "food.h"
#include <iostream>


Snake::Snake() {
	int rand_x = rand() % 500;
	int rand_y = rand() % 500;

	for (int i = 0; i < snakeLength; i++) {
		segments.push_back(Segment(rand_x + i * segmentSize, rand_y));
	}
}

float Snake::speed(float newSpeed) {
	f_speed -= newSpeed;
}

float Snake::speed() {
	return f_speed;
}

void Snake::keyboardListener() {
	Direction direction = segments.front().direction;
	if (direction != right && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
	 	newDirection = left;
	if (direction != left && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	 	newDirection = right;
	if (direction != down && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	 	newDirection = up;
	if (direction != up && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	 	newDirection = down;
}

void Snake::grow() {
	Segment lastSeg = segments.back();
	lastSeg.move(-segmentSize);
	segments.push_back(lastSeg);
}

bool Snake::checkForCollision(Food food) {
	sf::FloatRect snakeBox = segments.front().get().getGlobalBounds();
	sf::FloatRect foodBox = food.get().getGlobalBounds();
	return snakeBox.intersects(foodBox);
}

bool Snake::checkForCollision(Walls walls) {
	bool collision = false;
	sf::FloatRect snakeBox = segments.front().get().getGlobalBounds();
	for ( auto & wall : walls.get() ) {
		sf::FloatRect wallBox = wall.getGlobalBounds();
		collision = snakeBox.intersects(wallBox);
		if (collision) break;
	}
	return collision;
}

bool Snake::checkForSelfCollision() {
	bool collision = false;
	int counter = 0;
	for ( auto & segment : segments ) {
		Segment head = segments.front();
		sf::FloatRect headBox = segments.front().get().getGlobalBounds();
		sf::FloatRect segmentBox = segment.get().getGlobalBounds();
		sf::IntRect result;
		collision = counter && segmentBox.intersects(headBox);
		if (collision) break;
		counter++;
	}
	return collision;
}

void Snake::move(float amount) {
	if (newDirection) changeDir(newDirection);
	for ( auto & segment : segments ) {
		segment.move(amount);
	}
}

void Snake::changeDir(Direction direction) {
	Segment firstSeg = segments.front();
	sf::Vector2f point = firstSeg.get().getPosition();

	ChangePoint changePoint = {
		point,
		direction
	};

	for ( auto & segment : segments ) {
		segment.addChangePoint(changePoint);
	}

	newDirection = none;
}