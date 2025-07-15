//
// Created by Thu Nhan Truong on 6/3/25.
//

#include "KnightLogic.h"

std::vector<sf::Vector2i> KnightLogic::getValidMoves(const Piece& piece, const std::vector<Piece>& board) const {
    std::vector<sf::Vector2i> moves;
    sf::Vector2i offsets[] ={
            {2, 1},{1, 2},{-1, 2},{-2, 1},
            {-2, -1},{-1, -2},{1, -2},{2, -1}
    };

    for(const auto& offset: offsets){
        sf::Vector2i target = piece.position + offset;
        if (target.x >= 0 && target.x < 8 && target.y >= 0 && target.y < 8){
            bool occupiedByOwn = false;
            for(const Piece& other : board){
                // check if destination is occupied by own
                if(other.position == target && other.color == piece.color){
                    occupiedByOwn = true;
                    break;
                }
            }
            if (!occupiedByOwn) {
                moves.push_back(target);
            }
        }
    }

    return moves;
}