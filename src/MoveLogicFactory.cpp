//
// Created by Thu Nhan Truong on 6/3/25.
//

#include "MoveLogicFactory.h"

MoveLogic* MoveLogicFactory::create(PieceType type){
    switch (type){
        case PieceType::Pawn: return new PawnLogic();
        case PieceType::Rook: return new RookLogic();
        case PieceType::Knight: return new KnightLogic();
        case PieceType::Bishop: return new BishopLogic();
        case PieceType::Queen: return new QueenLogic();
        case PieceType::King: return new KingLogic();
        default: return nullptr;
    }
}