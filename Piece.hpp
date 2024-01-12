
#ifndef Piece_hpp
#define Piece_hpp

#include <stdio.h>
#include <vector>
#include "GameInfo.h"
using namespace std;

typedef enum {
    CPT_King,
    CPT_Queen,
    CPT_Rook,
    CPT_Bishop,
    CPT_Knight,
    CPT_Pawn,
    CPT_EMPTY
} ChessPieceType;

typedef enum {
    CPC_Black,
    CPC_White,
    CPC_NONE
} ChessPieceColor;

class Piece {

public:
    Piece() { m_type = CPT_EMPTY; m_color = CPC_NONE;}
    Piece(ChessPieceColor color, ChessPieceType type) { m_type = type; m_color = color; }
    Piece(char color, char type);
    ChessPieceColor getColor() const { return m_color; }
    void setColor(const ChessPieceColor& color) { m_color = color; }
    ChessPieceType getType() const { return m_type; }
    void setType(const ChessPieceType& type) { m_type = type; }
    string convertPiece() const;
private:
    ChessPieceType  m_type;
    ChessPieceColor m_color;
};


#endif /* Piece_hpp */
