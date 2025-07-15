//
// Created by Thu Nhan Truong on 5/25/25.
//

#ifndef FINALPROJECTCS3A_TEXTUREMANAGER_H
#define FINALPROJECTCS3A_TEXTUREMANAGER_H
#include <SFML/Graphics.hpp>
#include <map>
#include "ImageEnum.h"

class TextureManager {
private:
    sf::Texture _spritesheet;
    // each figure has its own position (intRect) on the spritesheet -> use map<key,value>
    std::map<ImageEnum, sf::IntRect> _figureRects;

public:
    sf::Vector2i getFigureDimension(int columns, int rows) const;
    bool loadSpritesheet(const std::string& path, int columns, int rows);
    const sf::Texture& getSpritesheet() const;
    const sf::IntRect& getFigureRect(ImageEnum figure) const;

};


#endif //FINALPROJECTCS3A_TEXTUREMANAGER_H
