//
//  Piece.cpp
//  LearnChess
//
//  Created by Enric Vergara on 21/2/22.
//

#include "Piece.hpp"
#include <string>
#include <iostream>
using namespace std;

Piece::Piece(char color, char type) 
{
	if (color == '0')
		m_color = CPC_White;
	else if (color == '1')
		m_color = CPC_Black;
	else
		m_color = CPC_NONE;

	switch (type)
	{
	case 'R': m_type = CPT_King;
		break;
	case 'D': m_type = CPT_Queen;
		break;
	case 'A': m_type = CPT_Bishop;
		break;
	case 'T': m_type = CPT_Rook;
		break;
	case 'C': m_type = CPT_Knight;
		break;
	case 'P': m_type = CPT_Pawn;
		break;
	default: m_type = CPT_EMPTY;
		break;
	}

}
string Piece::convertPiece() const
{
	string llista = "";

	if (m_color == CPC_Black)
		llista += 'b';
	else if (m_color == CPC_White)
		llista += 'w';
	else
		llista += '_';

	if (m_type == CPT_King)
		llista += 'R';
	else if (m_type == CPT_Queen)
		llista += 'D';
	else if (m_type == CPT_Rook)
		llista += 'T';
	else if (m_type == CPT_Bishop)
		llista += 'A';
	else if (m_type == CPT_Knight)
		llista += 'C';
	else if (m_type == CPT_Pawn)
		llista += 'P';
	else
		llista += '_';
	
	return llista;
}

