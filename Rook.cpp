#include "Rook.h"

Rook::Rook () {}

/*Rook::Rook ( std::pair < int, int > table, Color color, std::pair < int, int > texture) :
    Pieces( table, color, texture) { type = Pieces::ROOK; }
*/
Rook::Rook ( int tableRow, int tableColumn, Color color, int textureRow, int textureColumn) :
    Pieces(tableRow, tableColumn, color, textureRow, textureColumn) { type = Pieces::ROOK; }

bool Rook::valid ( std::pair < int, int > mPair, Pieces* const ChessPiece[8][8]) const {
    if( mPair.first >= 8 || mPair.first < 0 )
        return false;
    if( mPair.second >= 8 || mPair.second < 0 )
        return false;
    if( ChessPiece[mPair.first][mPair.second] == NULL )
        return true;
    else
        if( ChessPiece[mPair.first][mPair.second] -> getColor() == getColor() )
            return false;
        else
            return true;
}

std::vector < std::pair < int, int > > Rook::getPossibleMoves(Pieces* const ChessPiece[8][8]) const {
    std::vector < std::pair < int, int > > mList;
    std::pair < int, int > aux;

    for(int i = 1; i < 8; i++)
    {
        aux = std::make_pair ( m_pozition.first + i, m_pozition.second );
        if( valid ( aux, ChessPiece ) )
           mList.push_back( aux );
        else
            break;
        if( ChessPiece[m_pozition.first + i][m_pozition.second] != NULL)
            if( ChessPiece[m_pozition.first + i][m_pozition.second] -> getColor() != getColor() )
                break;
    }

    for(int i = 1; i < 8; i++)
    {
        aux = std::make_pair ( m_pozition.first - i, m_pozition.second );
        if( valid ( aux, ChessPiece ) )
           mList.push_back( aux );
        else
            break;
        if( ChessPiece[m_pozition.first - i][m_pozition.second] != NULL)
            if( ChessPiece[m_pozition.first - i][m_pozition.second] -> getColor() != getColor() )
                break;
    }

    for(int i = 1; i < 8; i++)
    {
        aux = std::make_pair ( m_pozition.first, m_pozition.second + i );
        if( valid ( aux, ChessPiece ) )
           mList.push_back( aux );
        else
            break;
        if( ChessPiece[m_pozition.first][m_pozition.second + i] != NULL)
            if( ChessPiece[m_pozition.first][m_pozition.second + i] -> getColor() != getColor() )
                break;
    }

    for(int i = 1; i < 8; i++)
    {
        aux = std::make_pair ( m_pozition.first, m_pozition.second - i );
        if( valid ( aux, ChessPiece ) )
           mList.push_back( aux );
        else
            break;
        if( ChessPiece[m_pozition.first][m_pozition.second - i] != NULL)
            if( ChessPiece[m_pozition.first][m_pozition.second - i] -> getColor() != getColor() )
                break;
    }
    return mList;
}
