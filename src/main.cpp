#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include "game/game.hpp"
#include "game/tilemap.hpp"

int main()
{
  sf::Clock clock;
  sf::Time elapsed = sf::microseconds(0);
  sf::Time renderElapsed = sf::microseconds(0);
  sf::Time renderThreshold = sf::microseconds(100);
  sf::Time waitThreshold = sf::microseconds(50);

  sf::Event event = sf::Event();
  sf::RenderWindow window(sf::VideoMode(800, 600), "Game on");

  Game game;

  if (game.getErrored()) {
    return -1;
  }

  while (window.isOpen()) {
    elapsed = clock.restart();
    renderElapsed += elapsed;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else {
        game.handleEvent(event);
      }
    }

    if (renderElapsed >= renderThreshold) {
      game.update(renderElapsed);
      renderElapsed %= renderThreshold;

      window.clear();
      window.draw(*game.getTileMap());

      for (Sprite* sprite : game.getSprites()) {
        window.draw(*sprite->getSfSprite());
      }

      window.display();
    }

    elapsed %= waitThreshold;

    std::this_thread::sleep_for(std::chrono::microseconds((waitThreshold - elapsed).asMicroseconds()));
  }

  return 0;
}
