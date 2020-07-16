#ifndef _gameon_game_hpp
#define _gameon_game_hpp

#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Game {
public:
  void update(sf::Time);
  void handleEvent(sf::Event);
};

#endif /* _gameon_game_hpp */
