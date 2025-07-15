
//
// Created by Thu Nhan Truong on 5/25/25.
//

#ifndef FINALPROJECTCS3A_PIECEMANAGER_H
#define FINALPROJECTCS3A_PIECEMANAGER_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "ImageEnum.h"
#include "TextureManager.h"
#include <optional>
#include "PieceUtil.h"

struct Piece {
    PieceType type;
    PieceColor color;
    sf::Vector2i position;  // (row, col)
    bool hasMoved = false;
};

class PieceManager{
private:
    std::vector<Piece> _pieces; // how many
    TextureManager& _textureManager;

public:
    PieceManager(TextureManager& textureManager);

    void loadInitialPosition();
    void draw(sf::RenderWindow& window, std::optional<size_t> excludeIndex) const;

    std::vector<Piece>& getPieces();
    const TextureManager& getTextureManager() const;
    float getTileSize(const sf::RenderWindow& window) const;
};


#endif //FINALPROJECTCS3A_PIECEMANAGER_H
