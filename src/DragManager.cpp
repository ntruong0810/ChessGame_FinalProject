//
// Created by Thu Nhan Truong on 5/26/25.
//

//
// Created by Thu Nhan Truong on 5/26/25.
//

#include "DragManager.h"
#include "PawnLogic.h"
#include <iostream>
DragManager::DragManager(PieceManager& pieceManager) : _pieceManager(pieceManager){}

void DragManager::handleEvent(const sf::RenderWindow& window, const std::optional<sf::Event>& event){
    if(!event) return;

    if(event->is<sf::Event::MouseButtonPressed>()){
        handleMousePressed(window);
    }

    if(event->is<sf::Event::MouseButtonReleased>()){
        handleMouseReleased(window);
    }
}

void DragManager::handleMousePressed(const sf::RenderWindow& window){
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    float tileSize = _pieceManager.getTileSize(window);

    size_t index = 0;
    // loop through list of pieces and check if the mpos at that piece
    for (const Piece& piece : _pieceManager.getPieces()){
        sf::FloatRect pieceRect({piece.position.y * tileSize, piece.position.x * tileSize},
                                {tileSize, tileSize});
        // check if the mpos is in that rect piece
        if(pieceRect.contains({static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)})) {
            if (piece.color != _currentTurn)
                return;
            _draggedIndex = index;
            _dragOffset= {mousePos.x - pieceRect.position.x,mousePos.y - pieceRect.position.y};
            break;
        }
        index++;
    }
}

void DragManager::handleMouseReleased(const sf::RenderWindow& window){
    if (!_draggedIndex.has_value())
        return;

    float tileSize = _pieceManager.getTileSize(window);
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    sf::Vector2i newPosition(static_cast<int>(mousePos.y / tileSize),static_cast<int>(mousePos.x / tileSize));

    size_t index = _draggedIndex.value();
    Piece draggedPiece = _pieceManager.getPieces()[index];

    if(!isValidMove(draggedPiece,newPosition)){
        _draggedIndex.reset();
        return;
    }

    // simulate the move
    std::vector<Piece>& pieces = _pieceManager.getPieces();
    std::vector<Piece> backupPieces = pieces;
    resolveMove(index, newPosition, draggedPiece);

    if (GameState::isInCheck(_currentTurn,pieces)){
        pieces = backupPieces;
        _draggedIndex.reset();
        return;
    }

    switchTurn();

    if(GameState::isCheckmate(_currentTurn,pieces)){
        _gameOver = true;
        std::cout << "Checkmate! " << (_currentTurn == PieceColor::White ? "Black" : "White") << " wins!\n";
    }
    _draggedIndex.reset();
}

bool DragManager::isValidMove(const Piece& piece, const sf::Vector2i& destination) const{
    MoveLogic* logic = MoveLogicFactory::create(piece.type);
    std::vector<sf::Vector2i> validMoves = logic->getValidMoves(piece,_pieceManager.getPieces());
    delete logic;

    // loop through all the valid move
    for(const sf::Vector2i& move : validMoves){
        if (move == destination){
            return true;
        }
    }

    return false;
}

void DragManager::resolveMove(size_t index, const sf::Vector2i& newPosition, const Piece& draggedPiece){
    // take the current list of pieces on the board
    std::vector<Piece>& pieces = _pieceManager.getPieces();
    Piece& pieceToMove = pieces[index];

    auto targetIt= pieces.end(); // assume there is no piece at destination

    // loop through all the pieces to check if there is any piece at the destination
    for (auto it= pieces.begin(); it != pieces.end(); it++){
        const Piece& p = *it;
        if(p.position == newPosition){
            targetIt = it;
            break;
        }
    }

// If that piece is an enemy, update the moving piece’s position and remove the enemy piece
    if (targetIt != pieces.end()){
        if (targetIt->color != draggedPiece.color) {
            pieceToMove.position = newPosition;
            pieces.erase(targetIt);
        }

    }
    else // invalid capture (same color), do nothing
        pieceToMove.position = newPosition;
}

void DragManager::switchTurn(){
    if(_currentTurn == PieceColor::White)
        _currentTurn = PieceColor::Black;
    else
        _currentTurn = PieceColor::White;
}

void DragManager::drawDraggingPiece(sf::RenderWindow& window) const{
    if (!_draggedIndex.has_value())
        return;

    float tileSize = _pieceManager.getTileSize(window);

    const std::vector<Piece>& pieces = _pieceManager.getPieces();
    size_t index = _draggedIndex.value();
    const Piece& piece = pieces[index];

    sf::Sprite sprite(_pieceManager.getTextureManager().getSpritesheet());
    sprite.setTextureRect(_pieceManager.getTextureManager().getFigureRect(convertToImageEnum(piece.type, piece.color)));
    float scaleX = tileSize/static_cast<float>(sprite.getTextureRect().size.x);
    float scaleY = tileSize/static_cast<float>(sprite.getTextureRect().size.y);
    sprite.setScale({scaleX, scaleY});

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sprite.setPosition({static_cast<float>(mousePos.x) - _dragOffset.x, static_cast<float>(mousePos.y) - _dragOffset.y});

    window.draw(sprite);
}

std::optional<size_t> DragManager::getDraggedIndex() const {
    return _draggedIndex;
}
