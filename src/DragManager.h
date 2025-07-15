//
// Created by Thu Nhan Truong on 5/26/25.
//

#ifndef FINALPROJECTCS3A_DRAGMANAGER_H
#define FINALPROJECTCS3A_DRAGMANAGER_H

#include <optional>
#include <SFML/Graphics.hpp>
#include "PieceManager.h"
#include "TextureManager.h"
#include "MoveLogicFactory.h"
#include "GameState.h"
class DragManager {
private:
    std::optional<size_t> _draggedIndex;
    sf::Vector2f _dragOffset; // store the offset when clicking the mouse and the top left pos of that piece
    PieceManager& _pieceManager;
    void handleMousePressed(const sf::RenderWindow& window);
    void handleMouseReleased(const sf::RenderWindow& window);
    PieceColor _currentTurn = PieceColor::Black;
    bool _gameOver = false;
public:
    DragManager(PieceManager& pieceManager);
    void switchTurn();
    void handleEvent(const sf::RenderWindow& window, const std::optional<sf::Event>& event);
    void drawDraggingPiece(sf::RenderWindow& window) const;
    std::optional<size_t> getDraggedIndex() const;
    void resolveMove(size_t index, const sf::Vector2i& newPosition, const Piece& draggedPiece);
    bool isValidMove(const Piece& piece, const sf::Vector2i& destination) const;

};



#endif //FINALPROJECTCS3A_DRAGMANAGER_H
