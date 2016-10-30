#ifndef FOOD_H
#define FOOD_H
#include <SFML/Graphics.hpp>

class Food {
public:
	Food();
	sf::CircleShape get();
	void move();
private:
	sf::CircleShape circle;
};

#endif