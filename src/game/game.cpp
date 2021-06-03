#include "game.hpp"
#include <iostream>

Game::Game()
{
  this->map = TileMap();

  sf::Texture texture;
  std::string spriteSheet = "assets/images/sprite.png";

  this->entities = {
    new Entity(&spriteSheet, 4, 16, 16),
    new Entity(&spriteSheet, 4, 16, 16, 23.5, 67.5),
  };

  if (!this->map.load("assets/images/tileset.png", sf::Vector2u(32, 32), LEVEL, 16, 8)) {
    this->errored = true;
    return;
  }
}

void Game::tearDown()
{
  for (Entity* s : this->entities) {
    delete s;
  }
}

std::vector<Entity*> Game::getEntities()
{
  return this->entities;
}

TileMap* Game::getTileMap()
{
   return &this->map;
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
