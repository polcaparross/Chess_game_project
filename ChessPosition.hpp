
#ifndef ChessPosition_hpp
#define ChessPosition_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class ChessPosition {

public:
  
    ChessPosition() { m_posX = 0; m_posY = 0; }
    ChessPosition(int x, int y) { m_posX = x; m_posY = y; }
    ChessPosition(string& pos)
    {
        convertInvers(pos[0], pos[1]);
    }
    void SetPosX(int x) { m_posX = x; }
    void SetPosY(int y) { m_posY = y; }
    int getPosX() const { return m_posX; }
    int getPosY() const{ return m_posY; }
    void convertInvers(char x, char y);
    string convertPosition()
    {
        string s;
        switch (m_posX)
        {
        case 0: s += "a";
            break;
        case 1: s += "b";
            break;
        case 2: s += "c";
            break;
        case 3: s += "d";
            break;
        case 4: s += "e";
            break;
        case 5: s += "f";
            break;
        case 6: s += "g";
            break;
        case 7: s += "h";
            break;
        }

        switch (m_posY)
        {
        case 0: s += "1";
            break;
        case 1: s += "2";
            break;
        case 2: s += "3";
            break;
        case 3: s += "4";
            break;
        case 4: s += "5";
            break;
        case 5: s += "6";
            break;
        case 6: s += "7";
            break;
        case 7: s += "8";
            break;

        }
        return s;
    }
    bool operator==(const ChessPosition& pos1) const
    {
        if (m_posX == pos1.m_posX)
            if (m_posY == pos1.m_posY)
                return true;
        return false;
    }
    friend ostream& operator<<(ostream& output, ChessPosition& pos)
    {
        string posicio;
        posicio = pos.convertPosition();
        output << posicio;
        return output;
    }
  
private:
    int m_posX; //Columna
    int m_posY; //Fila
    
    
};


#endif /* ChessPosition_hpp */
