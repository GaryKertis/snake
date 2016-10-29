#ifndef SEGMENT_H
#define SEGMENT_H
#include <SFML/Graphics.hpp>
#include "direction.h"

class Segment {
public:
	Segment(int, int);
	sf::RectangleShape get();
	void move(float);
	void changeDir(Direction);
	Direction direction = right;
private:
	sf::RectangleShape rectangle;
};

#endif