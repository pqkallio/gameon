#include "game.hpp"
#include <iostream>

Game::Game()
{
  this->map = TileMap();

  sf::Texture texture;
  std::string spriteSheet = "assets/images/sprite.png";

  this->sprites = {
    new Sprite(&spriteSheet, 4, 16, 16),
    new Sprite(&spriteSheet, 4, 16, 16, 23.5, 67.5),
  };

  if (!this->map.load("assets/images/tileset.png", sf::Vector2u(32, 32), LEVEL, 16, 8)) {
    this->errored = true;
    return;
  }
}

void Game::tearDown()
{
  for (Sprite* s : this->sprites) {
    delete s;
  }
}

std::vector<Sprite*> Game::getSprites()
{
  return this->sprites;
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
