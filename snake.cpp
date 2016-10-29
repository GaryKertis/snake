#include "snake.h"
#include <iostream>

Snake::Snake() {
	int snakeSize = 3;
}

void Snake::move(float amount) {
	for ( auto & segment : segments ) {

		sf::Vector2f position = segment.get().getPosition();
		switch(segment.direction) {
	    case up : if (position.y <= changePoint.y)
				    segment.changeDir(direction);
		    break;
	    case down : if (position.y >= changePoint.y)
				    segment.changeDir(direction);
		    break;
	    case left : if (position.x <= changePoint.x)
				    segment.changeDir(direction);
		    break;
	    case right : if (position.x >= changePoint.x)
				    segment.changeDir(direction);
		    break;
	}

		segment.move(amount);
	}
}

void Snake::changeDir(Direction dir) {
	direction = dir;
	Segment lastseg = segments.back();
	changePoint = lastseg.get().getPosition();
	changePoint.x += 10;
	changePoint.y += 10;
	//segments.back().changeDir(direction);
}