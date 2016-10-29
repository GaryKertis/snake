#include "snake.h"
#include <iostream>

Snake::Snake() {
	int snakeSize = 3;
}

void Snake::move(float amount) {
	for ( auto & segment : segments ) {
		segment.move(amount);
	}

}

