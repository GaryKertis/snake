#ifndef SNAKE_H
#define SNAKE_H
#include "segment.h"
#include "direction.h"
#include "food.h"
#include "walls.h"
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
	bool checkForCollision(Food);
	bool checkForCollision(Walls);
	bool checkForSelfCollision();

	void draw(sf::RenderWindow);
	//draw the snake

	vector<Segment> segments;
	void keyboardListener();

	float speed();
	float speed(float);
	int score();

private:
	int snakeLength = 5;
	int segmentSize = 11;
	float f_speed = 7;
	Direction newDirection = none;
};

#endif