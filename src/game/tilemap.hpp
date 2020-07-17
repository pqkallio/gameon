#ifndef _gameon_tilemap_hpp
#define _gameon_tilemap_hpp

#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
  bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();

    states.texture = &_tileset;

    target.draw(_vertices, states);
  }

  sf::VertexArray _vertices;
  sf::Texture _tileset;
};

#endif /* _gameon_tilemap_hpp */
