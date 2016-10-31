#include <SFML/Graphics.hpp>
#include <iostream>
#include "snake.h"

Snake snake;
Food food;
float snakeSpeed = 7;
float snakeCounter = 0; 

int main()
{
	snake.changeDir(down);
	srand(time(0));
	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
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

		if (ateFood) {
			snakeSpeed -= 0.1;
			snake.grow();
			food.move();
		}

		int counter = 0;
		for ( auto & segment : snake.segments ) {
			if (counter > 2) {
			    bool crash = snake.checkForCollision(segment);
			    if (crash) {
			    	std::cout << "Game Over" << std::endl;
			    }
		    }
			counter++;
		}

		snake.keyboardListener();

        if (snakeCounter <= 0) {
			snake.move(11);
        	snakeCounter = snakeSpeed;
        } else {
        	snakeCounter--;
        }

		for ( auto & segment : snake.segments ) {
			window.draw(segment.get());
		}

		window.draw(food.get());

		// end the current frame
		window.display();
	}

	return 0;
}
