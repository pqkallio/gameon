#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
  sf::Clock clock;
  sf::Time elapsed;
  sf::Event event = sf::Event();
  sf::Window window(sf::VideoMode(800, 600), "Game on");

  while (window.isOpen()) {
    elapsed = clock.restart();

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
  }

  return 0;
}
