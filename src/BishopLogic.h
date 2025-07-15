//
// Created by Thu Nhan Truong on 6/3/25.
//

#ifndef FINALPROJECTCS3A_BISHOPLOGIC_H
#define FINALPROJECTCS3A_BISHOPLOGIC_H
#include "MoveLogic.h"

class BishopLogic : public MoveLogic {
public:
    std::vector<sf::Vector2i> getValidMoves(const Piece& piece, const std::vector<Piece>& board) const override;
};
#endif //FINALPROJECTCS3A_BISHOPLOGIC_H
