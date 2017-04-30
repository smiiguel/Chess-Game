#include "Knight.h"

Knight::Knight () {}

Knight::Knight ( std::pair < int, int > table, Color color, std::pair < int, int > texture, int repeat, int moves ) :
    Pieces( table, color, texture, repeat, moves ) { type = Pieces::KNIGHT; }

Knight::Knight ( int tableRow, int tableColumn, Color color, int textureRow, int textureColumn, int repeat, int moves ) :
    Pieces(tableRow, tableColumn, color, textureRow, textureColumn, repeat, moves) { type = Pieces::KNIGHT; }

bool Knight::valid ( std::pair < int, int > mPair, Pieces* const ChessPiece[8][8]) const {
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

std::vector < std::pair < int, int > > Knight::getPossibleMoves(Pieces* const ChessPiece[8][8]) const {
    std::vector < std::pair < int, int > > mList;
    std::pair < int, int > aux;
    aux = std::make_pair ( m_pozition.first - 2, m_pozition.second - 1 );
    if( valid ( aux, ChessPiece ) )
       mList.push_back( aux );
    aux = std::make_pair ( m_pozition.first - 2, m_pozition.second + 1 );
    if( valid ( aux, ChessPiece ) )
       mList.push_back( aux );
    aux = std::make_pair ( m_pozition.first - 1, m_pozition.second - 2 );
    if( valid ( aux, ChessPiece ) )
       mList.push_back( aux );
    aux = std::make_pair ( m_pozition.first - 1, m_pozition.second + 2 );
    if( valid ( aux, ChessPiece ) )
       mList.push_back( aux );
    aux = std::make_pair ( m_pozition.first + 2, m_pozition.second - 1 );
    if( valid ( aux, ChessPiece ) )
       mList.push_back( aux );
    aux = std::make_pair ( m_pozition.first + 2, m_pozition.second + 1 );
    if( valid ( aux, ChessPiece ) )
       mList.push_back( aux );
    aux = std::make_pair ( m_pozition.first + 1, m_pozition.second - 2 );
    if( valid ( aux, ChessPiece ) )
       mList.push_back( aux );
    aux = std::make_pair ( m_pozition.first + 1, m_pozition.second + 2 );
    if( valid ( aux, ChessPiece ) )
       mList.push_back( aux );
    return mList;
}
