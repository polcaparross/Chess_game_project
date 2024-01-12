
#ifndef Chessboard_hpp
#define Chessboard_hpp

#include <stdio.h>
#include "Piece.hpp"
#include "GameInfo.h"

class Chessboard {

public:
    Chessboard();
    void LoadBoardFromFile(const string& path);
    VecOfPositions GetValidMoves (const ChessPosition& pos) ;
    bool MovePiece (const ChessPosition& posFrom, const ChessPosition& posTo);
    string ToString () const;
    ChessPieceColor GetPieceColorAtPos(const ChessPosition& pos) const;
    ChessPieceType GetPieceTypeAtPos(const ChessPosition& pos) const;
    bool colorDif(ChessPosition p1, ChessPosition p2);
    void moureRei(vector<ChessPosition>& v, ChessPosition pos);
    void moureTorre(vector<ChessPosition>& v, ChessPosition pos);
    void moureReina(vector<ChessPosition>& v, ChessPosition pos);
    void moureAlfil(vector<ChessPosition>& v, ChessPosition pos);
    void mourePeo(vector<ChessPosition>& v, ChessPosition pos);
    void moureCavall(vector<ChessPosition>& v, ChessPosition pos);
    
private:
    Piece m_board[NUM_COLS][NUM_ROWS];
    
};


#endif /* Chessboard_hpp */
