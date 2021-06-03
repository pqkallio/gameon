#include "entity.hpp"

Entity::Entity(
  std::string* spriteFilename,
  size_t frames,
  size_t height,
  size_t width,
  float x,
  float y
) : frames(frames), height(height), width(width), errored(false), position(sf::Vector2f(x, y))
{
  this->texture = sf::Texture();

  if (!this->texture.loadFromFile(*spriteFilename)) {
    this->errored = true;
    return;
  }

  sf::IntRect spriteRect(0, 0, width, height);

  this->spriteRect = sf::IntRect(spriteRect);

  this->sprite = sf::Sprite(this->texture, this->spriteRect);
  this->sprite.setPosition(x, y);
}

sf::Vector2f Entity::getPosition() {
  return this->position;
}

sf::Sprite* Entity::getSprite() {
  return &this->sprite;
}
