//
// Created by Thu Nhan Truong on 6/3/25.
//

#ifndef FINALPROJECTCS3A_QUEENLOGIC_H
#define FINALPROJECTCS3A_QUEENLOGIC_H
#include "MoveLogic.h"

class QueenLogic : public MoveLogic {
public:
    std::vector<sf::Vector2i> getValidMoves(const Piece& piece, const std::vector<Piece>& board) const override;
};
#endif //FINALPROJECTCS3A_QUEENLOGIC_H
