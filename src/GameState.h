//
// Created by Thu Nhan Truong on 6/4/25.
//

#ifndef FINALPROJECTCS3A_GAMESTATE_H
#define FINALPROJECTCS3A_GAMESTATE_H
#include "MoveLogic.h"
#include "MoveLogicFactory.h"
#include <vector>
#include "PieceManager.h"

class GameState {
public:
    static bool isInCheck(PieceColor color, const std::vector<Piece>& board);
    static bool isCheckmate(PieceColor color, const std::vector<Piece>& board);
};
#endif //FINALPROJECTCS3A_GAMESTATE_H
