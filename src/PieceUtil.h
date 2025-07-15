//
// Created by Thu Nhan Truong on 6/3/25.
//

#ifndef FINALPROJECTCS3A_PIECEUTIL_H
#define FINALPROJECTCS3A_PIECEUTIL_H


#include "ImageEnum.h"

//PieceType + PieceColor -> ImageEnum on sprite sheet
inline ImageEnum convertToImageEnum(PieceType type, PieceColor color) {
    int row;
    if (color == PieceColor::White)
        row = 0; // white pieces are in row 0 of the spritesheet
    else
        row = 1; // black pieces are in row 1
    int index = static_cast<int>(type) + row * 6; // 6 pieces per row
    return static_cast<ImageEnum>(index);
}


#endif //FINALPROJECTCS3A_PIECEUTIL_H
