#include "Chessboard.hpp"
#include <iostream>
#include <fstream>

using namespace std;
Chessboard::Chessboard()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			m_board[i][j].setType(CPT_EMPTY);
			m_board[i][j].setColor(CPC_NONE);
		}
}
void Chessboard::LoadBoardFromFile(const string& path)
{
	Chessboard();
	ifstream fitxer;
    ChessPosition p;
	fitxer.open(path);
	if (fitxer.is_open())
	{
		string l1, l2;
		fitxer >> l1 >> l2;
		while (!fitxer.eof())
		{
			p.convertInvers(l2[1], l2[2]);
			Piece peça(l1[0], l2[0]);
			m_board[p.getPosX()][p.getPosY()].setColor(peça.getColor());
			m_board[p.getPosX()][p.getPosY()].setType(peça.getType());
			fitxer >> l1 >> l2;
		}
		fitxer.close();
        p.convertInvers(l2[1], l2[2]);
        Piece peça(l1[0], l2[0]);
        m_board[p.getPosX()][p.getPosY()].setColor(peça.getColor());
        m_board[p.getPosX()][p.getPosY()].setType(peça.getType());
	}
}
string Chessboard::ToString() const
{
	string t = "";
	for (int i = 7; i != 0; i--)
	{
		int l = i + 1;
		t += l;
		for (int j = 0; j < 8; j++)
		{
			string s;
			s = m_board[i][j].convertPiece();
			t += s;
			
		}
		t += "\n";
	}
	t += " a b c d e f g h ";

	return t;
}
ChessPieceColor Chessboard::GetPieceColorAtPos(const ChessPosition& pos) const
{
    int X, Y;
    X = pos.getPosX();
    Y = pos.getPosY();

    if (m_board[X][Y].getColor() == CPC_Black)
        return CPC_Black;
    else if (m_board[X][Y].getColor() == CPC_White)
        return CPC_White;
    else
        return CPC_NONE;
}
ChessPieceType Chessboard::GetPieceTypeAtPos(const ChessPosition& pos) const
{
    int X, Y;
    X = pos.getPosX();
    Y = pos.getPosY();

    if (m_board[X][Y].getType() == CPT_Bishop)
        return CPT_Bishop;
    else if (m_board[X][Y].getType() == CPT_EMPTY)
        return CPT_EMPTY;
    else if (m_board[X][Y].getType() == CPT_King)
        return CPT_King;
    else if (m_board[X][Y].getType() == CPT_Knight)
        return CPT_Knight;
    else if (m_board[X][Y].getType() == CPT_Pawn)
        return CPT_Pawn;
    else if (m_board[X][Y].getType() == CPT_Queen)
        return CPT_Queen;
    else if (m_board[X][Y].getType() == CPT_Rook)
        return CPT_Rook;
}
VecOfPositions Chessboard::GetValidMoves(const ChessPosition& pos) 
{
    vector <ChessPosition> vector;
    ChessPieceType tipus = m_board[pos.getPosX()][pos.getPosY()].getType();

    if (tipus == CPT_King)
        moureRei(vector, pos);
    else if (tipus == CPT_Queen)
        moureReina(vector, pos);
    else if (tipus == CPT_Rook)
        moureTorre(vector, pos);
    else if (tipus == CPT_Knight)
        moureCavall(vector, pos);
    else if (tipus == CPT_Bishop)
        moureAlfil(vector, pos);
    else if (tipus == CPT_Pawn)
        mourePeo(vector, pos);

    return vector;
}
bool Chessboard::MovePiece(const ChessPosition& posFrom, const ChessPosition& posTo)
{
    vector <ChessPosition> v = GetValidMoves(posFrom);

    bool trobat = false;
    int i = 0;

    while (!trobat && i < v.size()) {
        if (posTo.getPosX() == v[i].getPosX() && posTo.getPosY() == v[i].getPosY()) {
            trobat = true;

            m_board[posTo.getPosX()][posTo.getPosY()].setType(m_board[posFrom.getPosX()][posFrom.getPosY()].getType());
            m_board[posTo.getPosX()][posTo.getPosY()].setColor(m_board[posFrom.getPosX()][posFrom.getPosY()].getColor());

            m_board[posFrom.getPosX()][posFrom.getPosY()].setType(CPT_EMPTY);
            m_board[posFrom.getPosX()][posFrom.getPosY()].setColor(CPC_NONE);
        }
        else
            i++;
    }

    return trobat;
}
bool Chessboard::colorDif(ChessPosition p1, ChessPosition p2) {

    if (m_board[p1.getPosX()][p1.getPosY()].getColor() == m_board[p2.getPosX()][p2.getPosY()].getColor())
        return false;
    else
        return true;
}
void Chessboard::moureRei(vector<ChessPosition>& v, ChessPosition pos) 
{
    int X, Y;
    X = pos.getPosX();
    Y = pos.getPosY();

    int maxA = 7 - Y;
    int maxS = Y;
    int maxD = 7 - X;
    int maxE = X;

    if (maxD >= 1) {
        ChessPosition p1(X + 1, Y);
        if (colorDif(pos, p1) == true) {
            v.push_back(p1);
        }

        if (maxA >= 1) {
            ChessPosition p1(X + 1, Y + 1);

            if (colorDif(pos, p1) == true) {
                v.push_back(p1);
            }

        }
        if (maxS >= 1) {
            ChessPosition p1(X + 1, Y - 1);

            if (colorDif(pos, p1) == true) {
                v.push_back(p1);
            }

        }
    }
    if (maxE >= 1) {
        ChessPosition p1(X - 1, Y);

        if (colorDif(pos, p1) == true) {
            v.push_back(p1);
        }

        if (maxA >= 1) {
            ChessPosition p1(X - 1, Y + 1);

            if (colorDif(pos, p1) == true) {
                v.push_back(p1);
            }
        }
        if (maxS >= 1) {
            ChessPosition p1(X - 1, Y - 1);

            if (colorDif(pos, p1) == true) {
                v.push_back(p1);
            }
        }
    }

    if (maxA >= 1) {
        ChessPosition p1(X, Y + 1);

        if (colorDif(pos, p1) == true) {
            v.push_back(p1);
        };
    }
    if (maxS >= 1) {
        ChessPosition p1(X, Y - 1);

        if (colorDif(pos, p1) == true) {
            v.push_back(p1);
        }
    }
}
void Chessboard::moureTorre(vector<ChessPosition>& v, ChessPosition pos)
{
    int X, Y;
    int i = 1;
    X = pos.getPosX();
    Y = pos.getPosY();

    bool trobat = false;
  
    int maxA = 7 - Y;
    int maxS = Y;
    int maxD = 7 - X;
    int maxE = X;

    while (!trobat && i <= maxA)
    {
        ChessPosition p1(X, Y + i);
        if (colorDif(pos, p1) == true)
            if (m_board[p1.getPosX()][p1.getPosY()].getColor() == CPC_NONE)
            {
                v.push_back(p1);
            }
            else
            {
                v.push_back(p1);
                trobat = true;
            }
        else
            trobat = true;
        i++;
    }
    trobat = false;
    i = 1;
    while (!trobat && i <= maxD)
    {
        ChessPosition p1(X + i, Y);
        if (colorDif(pos, p1) == true)
            if (m_board[p1.getPosX()][p1.getPosY()].getColor() == CPC_NONE)
            {
                v.push_back(p1);
            }
            else
            {
                v.push_back(p1);
                trobat = true;
            }
        else
            trobat = true;
        i++;
    }
    trobat = false;
    i = 1;
    while (!trobat && i <= maxS)
    {
        ChessPosition p1(X, Y - i);
        if (colorDif(pos, p1) == true)
            if (m_board[p1.getPosX()][p1.getPosY()].getColor() == CPC_NONE)
            {
                v.push_back(p1);
            }
            else
            {
                v.push_back(p1);
                trobat = true;
            }
        else
            trobat = true;
        i++;
    }
    trobat = false;
    i = 1;
    while (!trobat && i <= maxE)
    {
        ChessPosition p1(X - i,Y);
        if (colorDif(pos, p1) == true)
            if (m_board[p1.getPosX()][p1.getPosY()].getColor() == CPC_NONE)
            {
                v.push_back(p1);
            }
            else
            {
                v.push_back(p1);
                trobat = true;
            }
        else
            trobat = true;
        i++;
    }

 
}
void Chessboard::moureReina(vector<ChessPosition>& v, ChessPosition pos)
{
    moureTorre(v, pos);
    moureAlfil(v, pos);
}
void Chessboard::mourePeo(vector<ChessPosition>& v, ChessPosition pos)
{
    int X, Y;
    X = pos.getPosX();
    Y = pos.getPosY();

    if (m_board[X][Y].getColor() == CPC_White) {
        int maxV = 7 - Y;
        if (maxV >= 1)
        {
            ChessPosition p(X, Y + 1);
            if (m_board[X][Y + 1].getType() == CPT_EMPTY) {
                v.push_back(p);

                if (Y == 1) {
                    ChessPosition p2(X, Y + 2);
                    if (m_board[X][Y + 2].getType() == CPT_EMPTY) {
                        v.push_back(p2);
                    }
                }
            }
            int maxhr = 7 - X;
            if (maxhr >= 1)
            {
                ChessPosition d(X + 1, Y + 1);
                if (m_board[X + 1][ Y + 1].getColor() != CPC_NONE && m_board[X + 1][Y + 1].getColor() != CPC_White)
                    v.push_back(d);
            }
            int maxhl = X;
            if(maxhl >= 1)
            {
                ChessPosition iz(X - 1, Y + 1);
                if (m_board[X - 1][Y + 1].getColor() != CPC_NONE && m_board[X - 1][Y + 1].getColor() != CPC_White)
                    v.push_back(iz);
            }

        }
    }
   
    if (m_board[X][Y].getColor() == CPC_Black) {
        ChessPosition p(X, Y - 1);
        int  maxV = Y;
        if (maxV >= 1)
        {
            if (m_board[X][Y - 1].getType() == CPT_EMPTY) {
                v.push_back(p);

                if (Y == 6) {
                    ChessPosition p2(X, Y - 2);
                    if (m_board[X][Y - 2].getType() == CPT_EMPTY) {
                        v.push_back(p2);
                    }
                }
            }
            int maxhr = 7 - X;
            if (maxhr >= 1)
            {
                ChessPosition d(X + 1, Y - 1);
                if (m_board[X + 1][Y - 1].getColor() != CPC_NONE && m_board[X + 1][Y - 1].getColor() != CPC_Black)
                    v.push_back(d);
            }
            int maxhl = X;
            if (maxhl >= 1)
            {
                ChessPosition iz(X - 1, Y - 1);
                if (m_board[X - 1][Y - 1].getColor() != CPC_NONE && m_board[X - 1][Y - 1].getColor() != CPC_Black)
                    v.push_back(iz);
            }

        }
    }
}
void Chessboard::moureAlfil(vector<ChessPosition>& v, ChessPosition pos)
{
    int X, Y;
    int i = 1, max;
    X = pos.getPosX();
    Y = pos.getPosY();

    bool trobat = false;

    int maxA = 7 - Y;
    int maxS = Y;
    int maxD = 7 - X;
    int maxE = X;

    //ARRIBA DERECHA

    if (maxA > maxD)
        max = maxD;
    else
        max = maxA;

    while (!trobat && i <= max)
    {
        ChessPosition p1(X + i, Y + i);
        if (colorDif(pos, p1) == true)
            if (m_board[p1.getPosX()][p1.getPosY()].getColor() == CPC_NONE)
            {
                v.push_back(p1);
            }
            else
            {
                v.push_back(p1);
                trobat = true;
            }
        else
            trobat = true;
        i++;
    }


    //ARRIBA IZQUIERDA

    if (maxA > maxE)
        max = maxE;
    else
        max = maxA;
    i = 1;
    trobat = false;
    while (!trobat && i <= max)
    {
        ChessPosition p1(X - i, Y + i);
        if (colorDif(pos, p1) == true)
            if (m_board[p1.getPosX()][p1.getPosY()].getColor() == CPC_NONE)
            {
                v.push_back(p1);
            }
            else
            {
                v.push_back(p1);
                trobat = true;
            }
        else
            trobat = true;
        i++;
    }

    //ABAJO DERECHA

    if (maxS > maxD)
        max = maxD;
    else
        max = maxS;
    i = 1;
    trobat = false;
    while (!trobat && i <= max)
    {
        ChessPosition p1(X + i, Y - i);
        if (colorDif(pos, p1) == true)
            if (m_board[p1.getPosX()][p1.getPosY()].getColor() == CPC_NONE)
            {
                v.push_back(p1);
            }
            else
            {
                v.push_back(p1);
                trobat = true;
            }
        else
            trobat = true;
        i++;
    }

    //ABAJO IZQUIERDA

    if (maxS > maxE)
        max = maxE;
    else
        max = maxS;
    i = 1;
    trobat = false;
    while (!trobat && i <= max)
    {
        ChessPosition p1(X - i, Y - i);
        if (colorDif(pos, p1) == true)
            if (m_board[p1.getPosX()][p1.getPosY()].getColor() == CPC_NONE)
            {
                v.push_back(p1);
            }
            else
            {
                v.push_back(p1);
                trobat = true;
            }
        else
            trobat = true;
        i++;
    }
}
void Chessboard::moureCavall(vector<ChessPosition>& v, ChessPosition pos)
{
    int X, Y;
    X = pos.getPosX();
    Y = pos.getPosY();

    int maxA = 7 - Y;
    int maxS = Y;
    int maxD = 7 - X;
    int maxE = X;

    if (maxD >= 1 && maxA >= 2)
    {
        ChessPosition p1(X + 1, Y + 2);
        if (colorDif(pos, p1) == true)
            v.push_back(p1);
    }
    if (maxD >= 2 && maxA >= 1)
    {
        ChessPosition p1(X + 2, Y + 1);
        if (colorDif(pos, p1) == true)
            v.push_back(p1);
    }
    if (maxE >= 1 && maxA >= 2)
    {
        ChessPosition p1(X - 1, Y + 2);
        if (colorDif(pos, p1) == true) 
            v.push_back(p1);
    }
    if (maxE >= 2 && maxA >= 1)
    {
        ChessPosition p1(X - 2, Y + 1);
        if (colorDif(pos, p1) == true) 
            v.push_back(p1);
    }
    if (maxE >= 2 && maxS >= 1)
    {
        ChessPosition p1(X - 2, Y - 1);
        if (colorDif(pos, p1) == true)
            v.push_back(p1);
    }
    if (maxE >= 1 && maxS >= 2)
    {
        ChessPosition p1(X - 1, Y - 2);
        if (colorDif(pos, p1) == true)
            v.push_back(p1);
    }
    if (maxD >= 2 && maxS >= 1)
    {
        ChessPosition p1(X + 2, Y - 1);
        if (colorDif(pos, p1) == true)
            v.push_back(p1);
    }
    if (maxD >= 1 && maxS >= 2)
    {
        ChessPosition p1(X + 1, Y - 2);
        if (colorDif(pos, p1) == true)
            v.push_back(p1);
    }

}