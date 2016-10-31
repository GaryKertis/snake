#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics.hpp>
#include <string>
using std::string;
using std::to_string;

class Score {
public:
	Score();
	sf::Text get();
	void point();
	void reset();
private:
	sf::Font font;
	sf::Text text;
	int score = 0;
};

#endif