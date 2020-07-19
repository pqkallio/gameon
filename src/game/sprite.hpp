#ifndef _gameon_game_sprite
#define _gameon_game_sprite

#include <SFML/Graphics.hpp>

class Sprite {
public:
  Sprite(sf::Texture* texture);
  sf::Sprite* getSfSprite();

private:
  sf::Sprite sprite;
};

#endif /* _gameon_game_sprite */
