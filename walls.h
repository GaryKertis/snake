#ifndef WALLS_H
#define WALLS_H
#include <SFML/Graphics.hpp>
using std::vector;

class Walls {
public:
	Walls();
	vector<sf::RectangleShape> get();
private:
	vector<sf::RectangleShape> walls;
	sf::RectangleShape createHorizontalWall(int, int);
	sf::RectangleShape createVerticalWall(int, int);
};

#endif