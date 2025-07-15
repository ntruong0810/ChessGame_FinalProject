//
// Created by Thu Nhan Truong on 6/3/25.
//

#ifndef FINALPROJECTCS3A_KINGLOGIC_H
#define FINALPROJECTCS3A_KINGLOGIC_H

#endif //FINALPROJECTCS3A_KINGLOGIC_H
#include "MoveLogic.h"

class KingLogic : public MoveLogic {
public:
    std::vector<sf::Vector2i> getValidMoves(const Piece& piece, const std::vector<Piece>& board) const override;
};