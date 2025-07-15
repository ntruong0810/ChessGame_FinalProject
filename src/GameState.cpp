//
// Created by Thu Nhan Truong on 6/4/25.
//

#include "GameState.h"

// check if the king of player color is in check
bool GameState::isInCheck(PieceColor color, const std::vector<Piece>& board){
    // find the king of player color
    sf::Vector2i kingPos;
    bool foundKing = false;

    // save the king position
    for (const Piece& piece : board){
        if (piece.type == PieceType::King && piece.color == color){
            kingPos = piece.position;
            foundKing = true;
            break;
        }
    }

    // loop through opponent's pieces
    for(const Piece& enemy : board){
        if (enemy.color != color){
            // Create a logic move depend on the piece type of the opponent
            MoveLogic* logic = MoveLogicFactory::create(enemy.type);
            std::vector<sf::Vector2i> enemyMoves = logic->getValidMoves(enemy, board);
            delete logic;

            // Check if the opponent's piece can capture the king
            for(const sf::Vector2i& move : enemyMoves){
                if (move == kingPos) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool GameState::isCheckmate(PieceColor color, const std::vector<Piece>& board){
    // no check -> no checkmate
    if(!isInCheck(color, board))
        return false;

    // loop through all pieces of color player (skip opponent's pieces)
    for (size_t i = 0; i < board.size(); i++){
        const Piece& piece = board[i];
        if(piece.color != color)
            continue;

        // create an object for move logic specific to the type of the piece(Rook, Pawn ...)
        MoveLogic* logic = MoveLogicFactory::create(piece.type);
        auto moves= logic->getValidMoves(piece, board); // store a list of all valid positions
        delete logic;

        for(sf::Vector2i const& move : moves){
            std::vector<Piece> simulated = board;
            simulated[i].position = move;

            // Remove captured piece if any
            simulated.erase(std::remove_if(simulated.begin(), simulated.end(),
            [&](const Piece& p) { return p.position == move && p.color != color; }), simulated.end());

            if (!isInCheck(color,simulated))
                return false;
        }
    }

    return true;
}