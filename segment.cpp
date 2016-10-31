#include "segment.h"
#include <iostream>

Segment::Segment(int x, int y) {
	rectangle = sf::RectangleShape(sf::Vector2f(10, 10));
	rectangle.setPosition(sf::Vector2f(x, y));
	rectangle.setFillColor(sf::Color(100, 250, 50));
}

void Segment::changeDir(Direction dir) {
	direction = dir;
}

void Segment::addChangePoint(ChangePoint changePoint) {
	changeQueue.push_back(changePoint);
}

void Segment::changeQueueListener() {

		if (changeQueue.size()) {
			sf::Vector2f position = rectangle.getPosition();
			ChangePoint changePoint = changeQueue.front();
			switch(direction) {
			    case up : if (position.y <= changePoint.point.y) {
						    	changeDir(changePoint.direction);
						    	rectangle.setPosition(changePoint.point);
						    	changeQueue.erase(changeQueue.begin());
							}
				    break;
			    case down : if (position.y >= changePoint.point.y) {
						    	changeDir(changePoint.direction);
						   		rectangle.setPosition(changePoint.point);
						    	changeQueue.erase(changeQueue.begin());
							}
				    break;
			    case left : if (position.x <= changePoint.point.x) {
						    	changeDir(changePoint.direction);
						    	rectangle.setPosition(changePoint.point);
						    	changeQueue.erase(changeQueue.begin());
							}
				    break;
			    case right : if (position.x >= changePoint.point.x) {
						    	changeDir(changePoint.direction);
						    	rectangle.setPosition(changePoint.point);
						    	changeQueue.erase(changeQueue.begin());
							}
				    break;
			}
		}

}

void Segment::move(float amount) {
	changeQueueListener();
	sf::Vector2f position = rectangle.getPosition(); // = (10, 20)
	switch(direction) {
	    case up : rectangle.setPosition(position.x,  position.y - amount);
		    break;
	    case down : rectangle.setPosition(position.x, position.y + amount);
		    break;
	    case left : rectangle.setPosition(position.x - amount, position.y);
		    break;
	    case right : rectangle.setPosition(position.x + amount, position.y);
		    break;
	}
}

sf::RectangleShape Segment::get() {
	return rectangle;
}


