//
// Created by Thu Nhan Truong on 6/3/25.
//

#ifndef FINALPROJECTCS3A_MOVELOGICFACTORY_H
#define FINALPROJECTCS3A_MOVELOGICFACTORY_H
#include "MoveLogic.h"
#include "PawnLogic.h"
#include "RookLogic.h"
#include "KnightLogic.h"
#include "BishopLogic.h"
#include "QueenLogic.h"
#include "KingLogic.h"

class MoveLogicFactory {
public:
    static MoveLogic* create(PieceType type);
};

#endif //FINALPROJECTCS3A_MOVELOGICFACTORY_H
