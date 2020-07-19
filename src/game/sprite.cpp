#include "sprite.hpp"

Sprite::Sprite(sf::Texture* texture) {
  this->sprite = sf::Sprite();
  this->sprite.setTexture(*texture);
}

sf::Sprite* Sprite::getSfSprite() {
  return &this->sprite;
}
