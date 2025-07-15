//
// Created by Thu Nhan Truong on 6/3/25.
//

#include "PawnLogic.h"
std::vector<sf::Vector2i> PawnLogic::getValidMoves(const Piece& piece, const std::vector<Piece>& board) const{
    std::vector<sf::Vector2i> moves;

    int direction;
    if (piece.color == PieceColor::White)
        // White pawns move downward (increasing row number)
        direction = 1;
    else
        // Black pawns move upward (decreasing row number)
        direction = -1;
    sf::Vector2i forward = piece.position + sf::Vector2i(direction, 0);

    // 1 square forward
    bool blocked = false;
    for (const Piece& other : board) {
        if (other.position == forward) {
            blocked = true;
            break;
        }
    }
    if (!blocked) moves.push_back(forward);

    // 2 squares forward from initial position
    int startRow;
    if (piece.color == PieceColor::White)
        startRow = 1;  // White pawns start on row 1 (second row from top)
    else
        startRow = 6;  // Black pawns start on row 6 (second row from bottom)

    // If pawn is on its starting row
    if (piece.position.x == startRow){
        sf::Vector2i doubleForward = piece.position + sf::Vector2i(2 * direction,0);
        blocked = false;
        for (const auto& other: board){
            if (other.position == doubleForward || other.position == forward) {
                blocked = true;
                break;
            }
        }
        if (!blocked) moves.push_back(doubleForward);
    }

    // Capture diagonally
    for(int dx = -1; dx <= 1; dx += 2){
        sf::Vector2i diag = piece.position + sf::Vector2i(direction, dx);
        for (const Piece& other : board){
            // Capture if there's an enemy piece diagonally
            if (other.position == diag && other.color != piece.color) {
                moves.push_back(diag);
                break;
            }
        }
    }
    return moves;
}
