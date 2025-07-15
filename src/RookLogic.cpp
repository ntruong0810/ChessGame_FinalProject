//
// Created by Thu Nhan Truong on 6/3/25.
//

#include "RookLogic.h"

std::vector<sf::Vector2i> RookLogic::getValidMoves(const Piece& piece, const std::vector<Piece>& board) const {
    std::vector<sf::Vector2i> moves;
    static const sf::Vector2i directions[] = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}  // Down, Up, Right, Left
    };

    for (const auto& dir : directions) {
        sf::Vector2i current = piece.position + dir;
        while (current.x >= 0 && current.x < 8 && current.y >= 0 && current.y < 8) {
            bool blocked = false;
            for (const auto& other : board) {
                if (other.position == current) {
                    if (other.color != piece.color) {
                        moves.push_back(current); // Can capture enemy
                    }
                    blocked = true;
                    break; // Stop in this direction
                }
            }
            if (blocked) break;
            moves.push_back(current); // Free tile
            current += dir; // Go further in same direction
        }
    }

    return moves;
}