#include "walls.h"

Walls::Walls() {
	walls.push_back(createVerticalWall(10, 10));
	walls.push_back(createVerticalWall(580, 10));
	walls.push_back(createHorizontalWall(10, 10));
	walls.push_back(createHorizontalWall(10, 580));
}

vector<sf::RectangleShape> Walls::get() {
	return walls;
}

sf::RectangleShape Walls::createVerticalWall(int x, int y) {
	sf::RectangleShape wall(sf::Vector2f(10, 580));
	sf::Vector2f position(x, y);
	wall.setPosition(sf::Vector2f(x, y));
	wall.setFillColor(sf::Color(0, 0, 255));
	return wall;
}

sf::RectangleShape Walls::createHorizontalWall(int x, int y) {
	sf::RectangleShape wall(sf::Vector2f(580, 10));
	sf::Vector2f position(x, y);
	wall.setPosition(sf::Vector2f(x, y));
	wall.setFillColor(sf::Color(0, 0, 255));
	return wall;
}




