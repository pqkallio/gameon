#ifndef _gameon_game_sprite
#define _gameon_game_sprite

#include <SFML/Graphics.hpp>
#include <string>

class Sprite {
public:
  Sprite(
    std::string* filename,
    size_t frames,
    size_t height,
    size_t width,
    float x = 0.0f,
    float y = 0.0f
  );
  sf::Sprite* getSfSprite();
  bool getErrored();

private:
  sf::Sprite sprite;
  sf::Texture texture;
  sf::IntRect spriteRect;
  const size_t frames;
  const size_t height;
  const size_t width;
  bool errored;
};

#endif /* _gameon_game_sprite */
