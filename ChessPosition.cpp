#include "ChessPosition.hpp"
#include "GameInfo.h"

/* Coordinate system:
    Y (rows)
  . ^
  . |  ***Black***
  4 |
  3 |
  2 |
  1 |  ***White***
 (0,0)----------> X (cols)
      a b c ...
*/

void ChessPosition::convertInvers(char x, char y)
{
    switch (x)
    {
    case 'a': m_posX = 0;
        break;
    case 'b': m_posX = 1;
        break;
    case 'c': m_posX = 2;
        break;
    case 'd': m_posX = 3;
        break;
    case 'e': m_posX = 4;
        break;
    case 'f': m_posX = 5;
        break;
    case 'g': m_posX = 6;
        break;
    case 'h': m_posX = 7;
        break;
    }

    switch (y)
    {
    case '1': m_posY = 0;
        break;
    case '2': m_posY = 1;
        break;
    case '3': m_posY = 2;
        break;
    case '4': m_posY = 3;
        break;
    case '5': m_posY = 4;
        break;
    case '6': m_posY = 5;
        break;
    case '7': m_posY = 6;
        break;
    case '8': m_posY = 7;
        break;

    }
}