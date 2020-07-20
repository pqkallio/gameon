#include "sprite.hpp"

Sprite::Sprite(
  std::string* filename,
  size_t frames,
  size_t height,
  size_t width,
  float x,
  float y
) : frames(frames), height(height), width(width), errored(false)
{
  this->texture = sf::Texture();

  if (!this->texture.loadFromFile(*filename)) {
    this->errored = true;
    return;
  }

  sf::IntRect spriteRect(0, 0, width, height);

  this->spriteRect = sf::IntRect(spriteRect);

  this->sprite = sf::Sprite(this->texture, this->spriteRect);
  this->sprite.setPosition(x, y);
}

sf::Sprite* Sprite::getSfSprite() {
  return &this->sprite;
}
