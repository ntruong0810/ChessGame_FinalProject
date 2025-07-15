//
// Created by Thu Nhan Truong on 5/25/25.
//

#include "PieceManager.h"
PieceManager::PieceManager(TextureManager& textureManager) : _textureManager(textureManager) {}

void PieceManager::loadInitialPosition(){
    _pieces.push_back({PieceType::Rook,PieceColor::White,{0, 0}});
    _pieces.push_back({PieceType::Knight,PieceColor::White,{0, 1}});
    _pieces.push_back({PieceType::Bishop,PieceColor::White,{0, 2}});
    _pieces.push_back({PieceType::Queen,PieceColor::White,{0, 3}});
    _pieces.push_back({PieceType::King,PieceColor::White,{0, 4}});
    _pieces.push_back({PieceType::Bishop,PieceColor::White,{0, 5}});
    _pieces.push_back({PieceType::Knight,PieceColor::White,{0, 6}});
    _pieces.push_back({PieceType::Rook,PieceColor::White,{0, 7}});

    for(int col = 0; col < 8; col++){
        _pieces.push_back({PieceType::Pawn,PieceColor::White,{1, col}});
    }

    _pieces.push_back({PieceType::Rook,PieceColor::Black, {7, 0}});
    _pieces.push_back({PieceType::Knight,PieceColor::Black,{7, 1}});
    _pieces.push_back({PieceType::Bishop,PieceColor::Black,{7, 2}});
    _pieces.push_back({PieceType::Queen,PieceColor::Black,{7, 3}});
    _pieces.push_back({PieceType::King,PieceColor::Black,{7, 4}});
    _pieces.push_back({PieceType::Bishop,PieceColor::Black,{7, 5}});
    _pieces.push_back({PieceType::Knight,PieceColor::Black,{7, 6}});
    _pieces.push_back({PieceType::Rook,PieceColor::Black,{7, 7}});

    for(int col = 0; col < 8; col++){
        _pieces.push_back({PieceType::Pawn,PieceColor::Black,{6, col}});
    }
}

// only draw the dragged piece
void PieceManager::draw(sf::RenderWindow& window, std::optional<size_t> excludeIndex) const{
    // check if the dragging piece, then skip the loop
    for(size_t index = 0; index < _pieces.size(); index++){
        if(excludeIndex.has_value() && index == excludeIndex.value()){
            continue;
        }

        const Piece& piece = _pieces[index];
        sf::Sprite sprite(_textureManager.getSpritesheet());
        sprite.setTextureRect(_textureManager.getFigureRect(convertToImageEnum(piece.type, piece.color)));
        float scaleX = 100.f / static_cast<float>(sprite.getTextureRect().size.x);
        float scaleY = 100.f / static_cast<float>(sprite.getTextureRect().size.y);
        sprite.setScale({scaleX, scaleY});
        // set the top left position
        float tileSize = getTileSize(window);
        sprite.setPosition({piece.position.y * tileSize,piece.position.x * tileSize});
        window.draw(sprite);
    }
}

float PieceManager::getTileSize(const sf::RenderWindow& window) const {
    return static_cast<float>(window.getSize().x) / 8.f; // row = col = 8
}

std::vector<Piece>& PieceManager::getPieces(){ return _pieces; }
const TextureManager& PieceManager::getTextureManager() const { return _textureManager; }