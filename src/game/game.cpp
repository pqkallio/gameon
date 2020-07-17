#include "game.hpp"
#include <iostream>

Game::Game()
{
  this->map = TileMap();

  if (!this->map.load("assets/images/tileset.png", sf::Vector2u(32, 32), LEVEL, 16, 8)) {
    this->errored = true;
    return;
  }
}

TileMap Game::getDrawable()
{
   return this->map;
}

bool Game::getErrored()
{
  return this->errored;
}

void Game::update(sf::Time elapsed)
{
  if (elapsed.asMicroseconds() > 0) {
    return;
  }
}

void Game::handleEvent(sf::Event event)
{
  if (event.type == sf::Event::EventType::KeyReleased) {
    return;
  }
}
