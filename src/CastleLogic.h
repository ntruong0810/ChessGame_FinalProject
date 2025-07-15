//
// Created by Thu Nhan Truong on 6/4/25.
//

#ifndef FINALPROJECTCS3A_CASTLELOGIC_H
#define FINALPROJECTCS3A_CASTLELOGIC_H
#include "MoveLogic.h"
#include "PieceUtil.h"

class CastleLogic : public MoveLogic {
public:
//    std::vector<sf::Vector2i> getValidMoves(const Piece& piece, const std::vector<Piece>& board) override;

private:
    bool isPathClear(const sf::Vector2i& start, const sf::Vector2i& end, const std::vector<Piece>& board) const;
    bool hasRookMoved(PieceColor color, bool isKingSide, const std::vector<Piece>& board) const;
    bool hasKingMoved(PieceColor color, const std::vector<Piece>& board) const;
};
#endif //FINALPROJECTCS3A_CASTLELOGIC_H
