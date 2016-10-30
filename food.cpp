#include "food.h"

Food::Food() {
	circle = sf::CircleShape(5);
	circle.setFillColor(sf::Color(255, 0, 0));
	move();
}

void Food::move() {
	int rand_x = rand() % 790;
	int rand_y = rand() % 590;
	circle.setPosition(sf::Vector2f(rand_x, rand_y));
}

sf::CircleShape Food::get() {
	return circle;
}


