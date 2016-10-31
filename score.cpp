#include "score.h"

Score::Score() {
	font.loadFromFile("Coiny-Regular.ttf");
	text.setFont(font);
	text.setString("Score: 0");
	text.setColor(sf::Color(255,255,255));
	text.setPosition(sf::Vector2f(10, 590));
	text.setCharacterSize(10);
}

sf::Text Score::get() {
	return text;
}

void Score::point() {
	score++;
	text.setPosition(sf::Vector2f(10, 590));
	text.setString("Score: " + to_string(score));
}

void Score::reset() {
	score = 0;
	text.setPosition(sf::Vector2f(10, 590));
	text.setString("Score: " + to_string(score));
}
