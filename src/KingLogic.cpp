//
// Created by Thu Nhan Truong on 6/3/25.
//

#include "KingLogic.h"
std::vector<sf::Vector2i> KingLogic::getValidMoves(const Piece& piece, const std::vector<Piece>& board) const{
    std::vector<sf::Vector2i> moves;
    sf::Vector2i directions[]={
            {1, 0},{-1, 0},{0, 1},{0, -1},
            {1, 1},{-1, -1},{1, -1},{-1, 1} // 8 surrounding directions
    };

    for(const auto& dir : directions){
        sf::Vector2i target = piece.position + dir;
        if (target.x >= 0 && target.x < 8 && target.y >= 0 && target.y < 8){
            bool occupiedByOwn = false;
            for (const Piece& other : board){
                if (other.position == target && other.color == piece.color){
                    occupiedByOwn = true;
                    break;
                }
            }
            if(!occupiedByOwn){
                moves.push_back(target);
            }
        }
    }

    return moves;
}