#include <SFML/Graphics.hpp>
#include "snake.h"

int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	window.setVerticalSyncEnabled(true); // call it once, after creating the window
	//window.setFramerateLimit(60); // call it once, after creating the window

	Snake snake;
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

		snake.move(1);
        window.clear(sf::Color::Black);
		for ( auto & segment : snake.segments ) {
			window.draw(segment.get());
		}

		// end the current frame
		window.display();
	}

	return 0;
}
