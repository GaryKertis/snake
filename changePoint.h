#ifndef CHANGEPOINT_H
#define CHANGEPOINT_H
#include <SFML/Graphics.hpp>
#include "direction.h"

struct ChangePoint {
	sf::Vector2f point;
	Direction direction;
};

#endif