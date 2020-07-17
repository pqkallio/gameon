#ifndef _gameon_game_hpp
#define _gameon_game_hpp

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "tilemap.hpp"

const int LEVEL[] = {
  0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
  0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
  0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
  0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
  2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
  0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
};

class Game {
public:
  Game();
  void update(sf::Time);
  void handleEvent(sf::Event);
  TileMap getDrawable();
  bool getErrored();

private:
  TileMap map;
  bool errored;
};

#endif /* _gameon_game_hpp */
