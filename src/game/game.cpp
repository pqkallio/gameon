#include "game.hpp"
#include <iostream>

void Game::update(sf::Time elapsed)
{
  std::cout << "time: " << elapsed.asMicroseconds() << std::endl;
}

void Game::handleEvent(sf::Event event)
{
  std::cout << "event: " << event.type << std::endl;
}
