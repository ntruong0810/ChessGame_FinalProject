//
// Created by Thu Nhan Truong on 6/3/25.
//

#ifndef FINALPROJECTCS3A_MOVELOGIC_H
#define FINALPROJECTCS3A_MOVELOGIC_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "PieceManager.h"

class MoveLogic { // child class need to override
public:
    virtual ~MoveLogic() = default;
    virtual std::vector<sf::Vector2i> getValidMoves(const Piece& piece, const std::vector<Piece>& board) const = 0;
};


#endif //FINALPROJECTCS3A_MOVELOGIC_H
