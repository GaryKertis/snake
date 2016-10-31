#include <SFML/Graphics.hpp>
#include <iostream>
#include "snake.h"
#include "score.h"

Snake snake;
Walls walls;
Food food;
Score score;
float counter = 0;

void levelUp() {
	snake.speed(0.1);
	snake.grow();
	score.point();
	food.move();
}

void gameOver() {
	snake = Snake();
	score.reset();
	food.move();
}

int main()
{
	snake.changeDir(down);
	srand(time(0));
	// create the window
	sf::RenderWindow window(sf::VideoMode(600, 600), "My window");
	//window.setVerticalSyncEnabled(true); // call it once, after creating the window
	window.setFramerateLimit(60); // call it once, after creating the window

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

        window.clear(sf::Color::Black);

        bool ateFood = snake.checkForCollision(food);
		bool crashSelf = snake.checkForSelfCollision();
		bool crashWall = snake.checkForCollision(walls);

		if (ateFood) levelUp();
		if (crashSelf || crashWall) gameOver();

		snake.keyboardListener();

        if (counter <= 0) {
			snake.move(11);
        	counter = snake.speed();
        } else {
        	counter--;
        }

		for ( auto & segment : snake.segments ) {
			window.draw(segment.get());
		}

		for ( auto & wall : walls.get() ) {
			window.draw(wall);
		}

		window.draw(food.get());
		window.draw(score.get());

		// end the current frame
		window.display();
	}

	return 0;
}
