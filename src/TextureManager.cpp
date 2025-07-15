//
// Created by Thu Nhan Truong on 5/25/25.
//

#include "TextureManager.h"
#include <SFML/Graphics/Rect.hpp>

const int row = 2, col = 6;

// cut the initial sheet to smaller sprites (firuges)

sf::Vector2i TextureManager::getFigureDimension(int columns, int rows) const {
    int spriteWidth = _spritesheet.getSize().x / columns;
    int spriteHeight = _spritesheet.getSize().y / rows;
    return {spriteWidth, spriteHeight}; // width and length of each figure
}

bool TextureManager::loadSpritesheet(const std::string& path, int columns, int rows){
    if (!_spritesheet.loadFromFile(path))
        return false;

    sf::Vector2i dimension = getFigureDimension(columns, rows);

    // 1 row in the sprite sheet: white figure
    ImageEnum whitePieces[]= {
            ImageEnum::WhiteKing,ImageEnum::WhiteQueen,ImageEnum::WhiteBishop,
            ImageEnum::WhiteKnight,ImageEnum::WhiteRook,ImageEnum::WhitePawn
    };

    // 2nd row in the sprite sheet: black
    ImageEnum blackPieces[]={
            ImageEnum::BlackKing,ImageEnum::BlackQueen,ImageEnum::BlackBishop,
            ImageEnum::BlackKnight,ImageEnum::BlackRook,ImageEnum::BlackPawn
    };

    // loop through the 1st row (white) and assign the intRect position for each figure
    for(int i = 0; i < columns; i++){
        sf::IntRect rect;
        rect.position.x = i * dimension.x;
        rect.position.y = 0;
        rect.size = dimension;
        _figureRects[whitePieces[i]] = rect; // each piece on sheet has it intRect
    }

    // assign the intRect for 2nd row (black)
    for(int i = 0; i < columns; i++){
        sf::IntRect rect;
        rect.position.x = i * dimension.x;
        rect.position.y = dimension.y; // 2nd row
        rect.size = dimension;
        _figureRects[blackPieces[i]] = rect;
    }
    return true;
}


// getters
const sf::Texture& TextureManager::getSpritesheet() const{
    return _spritesheet;
}

const sf::IntRect& TextureManager::getFigureRect(ImageEnum figure) const{
    return _figureRects.at(figure);
}
