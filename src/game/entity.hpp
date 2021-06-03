#ifndef _gameon_game_entity
#define _gameon_game_entity

#include <SFML/Graphics.hpp>
#include <string>

class Entity {
public:
  Entity(
    std::string* spriteFilename,
    size_t frames,
    size_t height,
    size_t width,
    float x = 0.0f,
    float y = 0.0f
  );
  sf::Sprite* getSprite();
  bool getErrored();
  sf::Vector2f getPosition();

private:
  sf::Sprite sprite;
  sf::Texture texture;
  sf::IntRect spriteRect;
  const size_t frames;
  const size_t height;
  const size_t width;
  bool errored;
  sf::Vector2f position;
};

#endif /* _gameon_game_entity */
