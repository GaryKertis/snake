#include <SFML/Graphics.hpp>
#include <iostream>
#include "snake.h"

int main()
{
	srand(time(0));
	int snakeSpeed = 1;
	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	window.setVerticalSyncEnabled(true); // call it once, after creating the window
	//window.setFramerateLimit(60); // call it once, after creating the window

	Snake snake;
	Food food;
	snake.changeDir(down);
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

		snake.move(snakeSpeed);
		bool ateFood = snake.checkForCollision(food);

		if (ateFood) {
			snake.grow();
			food.move();
			snakeSpeed += 0.1;
		}

		int counter = 0;
		for ( auto & segment : snake.segments ) {

			if (counter > 2) {
			    bool crash = snake.checkForCollision(segment);
			    if (crash) {
			    	std::cout << "Game Over" << std::endl;
			    }
		    }

			window.draw(segment.get());
			counter++;
		}

		window.draw(food.get());

		// end the current frame
		window.display();
	}

	return 0;
}
