#ifndef SNAKE_H
#define SNAKE_H
#include "segment.h"
#include "direction.h"
#include <SFML/Graphics.hpp>
#include <vector>
using std::vector;

class Snake {
public:
	Snake();

	//add a segment to the snake
	void grow();

	//have the snake change direction
	void changeDir(Direction);

	//have the snake move forward in whatever direction it's currently facing
	void move(float);

	//check if the snake has collided with itself
	void checkForCollisions();

	void draw(sf::RenderWindow);
	//draw the snake

	vector<Segment> segments = {Segment(10, 50), Segment(21, 50), Segment(32, 50), Segment(43, 50), Segment(54, 50), Segment(65, 50)};
private:
	Direction direction = left;
	sf::Vector2f changePoint;
};

#endif