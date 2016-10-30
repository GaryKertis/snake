#ifndef SEGMENT_H
#define SEGMENT_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "direction.h"
#include "changePoint.h"
using std::vector;

class Segment {
public:
	Segment(int, int);
	sf::RectangleShape get();
	void move(float);
	void changeDir(Direction);
	void addChangePoint(ChangePoint);
	Direction direction = left;
private:
	sf::RectangleShape rectangle;
	vector<ChangePoint> changeQueue;
	void changeQueueListener();
};

#endif