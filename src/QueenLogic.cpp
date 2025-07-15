//
// Created by Thu Nhan Truong on 6/3/25.
//

#include "QueenLogic.h"
std::vector<sf::Vector2i> QueenLogic::getValidMoves(const Piece& piece, const std::vector<Piece>& board) const {
    std::vector<sf::Vector2i> moves;
    sf::Vector2i directions[] = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}, // rook-like
            {1, 1}, {-1, -1}, {1, -1}, {-1, 1} // bishop-like
    };

    for (const auto& dir : directions) {
        sf::Vector2i pos = piece.position + dir;
        while (pos.x >= 0 && pos.x < 8 && pos.y >= 0 && pos.y < 8) {
            bool blocked = false;
            for (const auto& other : board) {
                if (other.position == pos) {
                    if (other.color != piece.color) {
                        moves.push_back(pos);
                    }
                    blocked = true;
                    break;
                }
            }
            if (blocked) break;
            moves.push_back(pos);
            pos += dir;
        }
    }

    return moves;
}