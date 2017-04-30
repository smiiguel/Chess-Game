#include "King.h"
#include <iostream>

King::King () {}

King::King ( std::pair < int, int > table, Color color, std::pair < int, int > texture, int repeat, int moves ) :
    Pieces( table, color, texture, repeat, moves ) { type = Pieces::KING; }

King::King ( int tableRow, int tableColumn, Color color, int textureRow, int textureColumn, int repeat, int moves ) :
    Pieces(tableRow, tableColumn, color, textureRow, textureColumn, repeat, moves) { type = Pieces::KING; }

bool King::valid ( std::pair < int, int > mPair, Pieces* const ChessPiece[8][8]) const {
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

std::vector < std::pair < int, int > > King::getPossibleMoves(Pieces* const ChessPiece[8][8]) const {
    std::vector < std::pair < int, int > > mList;
    std::pair < int, int > aux;
    aux = std::make_pair ( m_pozition.first - 1, m_pozition.second - 1 );
    if( valid ( aux, ChessPiece ) )
       mList.push_back( aux );
    aux = std::make_pair ( m_pozition.first - 1, m_pozition.second );
    if( valid ( aux, ChessPiece ) )
       mList.push_back( aux );
    aux = std::make_pair ( m_pozition.first - 1, m_pozition.second + 1 );
    if( valid ( aux, ChessPiece ) )
       mList.push_back( aux );
    aux = std::make_pair ( m_pozition.first , m_pozition.second + 1 );
    if( valid ( aux, ChessPiece ) )
       mList.push_back( aux );
    aux = std::make_pair ( m_pozition.first , m_pozition.second - 1 );
    if( valid ( aux, ChessPiece ) )
       mList.push_back( aux );
    aux = std::make_pair ( m_pozition.first + 1, m_pozition.second + 1 );
    if( valid ( aux, ChessPiece ) )
       mList.push_back( aux );
    aux = std::make_pair ( m_pozition.first + 1, m_pozition.second );
    if( valid ( aux, ChessPiece ) )
       mList.push_back( aux );
    aux = std::make_pair ( m_pozition.first + 1, m_pozition.second - 1 );
    if( valid ( aux, ChessPiece ) )
       mList.push_back( aux );
    return mList;
}

bool King::with_Rook( std::pair < int, int > mPair, Pieces* const ChessPiece[8][8] ) const {

    for(int i = 1; i < 8; i++)
    {
        if( mPair.first + i < 8 )
            if( ChessPiece[mPair.first + i][mPair.second] != NULL )
                if( ChessPiece[mPair.first + i][mPair.second] -> getType() == Pieces::ROOK &&
                        ChessPiece[mPair.first + i][mPair.second] -> getColor() != getColor() )
                    return true;
    }

    for(int i = 1; i < 8; i++)
    {
        if( mPair.first - i >= 0)
            if( ChessPiece[mPair.first - i][mPair.second] != NULL )
                if( ChessPiece[mPair.first - i][mPair.second] -> getType() == Pieces::ROOK &&
                        ChessPiece[mPair.first - i][mPair.second] -> getColor() != getColor() )
                    return true;
    }

    for(int i = 1; i < 8; i++)
    {
        if( mPair.second + i < 8)
            if( ChessPiece[mPair.first][mPair.second + i] != NULL )
                if( ChessPiece[mPair.first][mPair.second + i] -> getType() == Pieces::ROOK &&
                        ChessPiece[mPair.first][mPair.second + i] -> getColor() != getColor() )
                    return true;
    }

    for(int i = 1; i < 8; i++)
    {
        if( mPair.second - i >= 0)
            if( ChessPiece[mPair.first][mPair.second - i] != NULL )
                if( ChessPiece[mPair.first][mPair.second - i] -> getType() == Pieces::ROOK &&
                        ChessPiece[mPair.first][mPair.second - i] -> getColor() != getColor() )
                    return true;
    }
    return false;
}

bool King::with_Knight( std::pair < int, int > mPair, Pieces* const ChessPiece[8][8] ) const {

    std::pair < int, int > aux;

    aux.first = mPair.first - 2;
    aux.second = mPair.second - 1;
    if( aux.first < 8 &&  aux.first >= 0 && aux.second < 8 &&  aux.second >= 0 )
        if( ChessPiece[aux.first][aux.second] != NULL )
            if( ChessPiece[aux.first][aux.second] -> getType() == Pieces::KNIGHT &&
                    ChessPiece[aux.first][aux.second] -> getColor() != getColor() )
                return true;

    aux.first = mPair.first - 2;
    aux.second = mPair.second + 1;
    if( aux.first < 8 &&  aux.first >= 0 && aux.second < 8 &&  aux.second >= 0 )
        if( ChessPiece[aux.first][aux.second] != NULL )
            if( ChessPiece[aux.first][aux.second] -> getType() == Pieces::KNIGHT &&
                    ChessPiece[aux.first][aux.second] -> getColor() != getColor() )
                return true;

    aux.first = mPair.first - 1;
    aux.second = mPair.second - 2;
    if( aux.first < 8 &&  aux.first >= 0 && aux.second < 8 &&  aux.second >= 0 )
        if( ChessPiece[aux.first][aux.second] != NULL )
            if( ChessPiece[aux.first][aux.second] -> getType() == Pieces::KNIGHT &&
                    ChessPiece[aux.first][aux.second] -> getColor() != getColor() )
                return true;

    aux.first = mPair.first - 1;
    aux.second = mPair.second + 2;
    if( aux.first < 8 &&  aux.first >= 0 && aux.second < 8 &&  aux.second >= 0 )
        if( ChessPiece[aux.first][aux.second] != NULL )
            if( ChessPiece[aux.first][aux.second] -> getType() == Pieces::KNIGHT &&
                    ChessPiece[aux.first][aux.second] -> getColor() != getColor() )
                return true;

    aux.first = mPair.first + 2;
    aux.second = mPair.second - 1;
    if( aux.first < 8 &&  aux.first >= 0 && aux.second < 8 &&  aux.second >= 0 )
        if( ChessPiece[aux.first][aux.second] != NULL )
            if( ChessPiece[aux.first][aux.second] -> getType() == Pieces::KNIGHT &&
                    ChessPiece[aux.first][aux.second] -> getColor() != getColor() )
                return true;

    aux.first = mPair.first + 2;
    aux.second = mPair.second + 1;
    if( aux.first < 8 &&  aux.first >= 0 && aux.second < 8 &&  aux.second >= 0 )
        if( ChessPiece[aux.first][aux.second] != NULL )
            if( ChessPiece[aux.first][aux.second] -> getType() == Pieces::KNIGHT &&
                    ChessPiece[aux.first][aux.second] -> getColor() != getColor() )
                return true;

    aux.first = mPair.first + 1;
    aux.second = mPair.second - 2;
    if( aux.first < 8 &&  aux.first >= 0 && aux.second < 8 &&  aux.second >= 0 )
        if( ChessPiece[aux.first][aux.second] != NULL )
            if( ChessPiece[aux.first][aux.second] -> getType() == Pieces::KNIGHT &&
                    ChessPiece[aux.first][aux.second] -> getColor() != getColor() )
                return true;

    aux.first = mPair.first + 1;
    aux.second = mPair.second + 2;
    if( aux.first < 8 &&  aux.first >= 0 && aux.second < 8 &&  aux.second >= 0 )
        if( ChessPiece[aux.first][aux.second] != NULL )
            if( ChessPiece[aux.first][aux.second] -> getType() == Pieces::KNIGHT &&
                    ChessPiece[aux.first][aux.second] -> getColor() != getColor() )
                return true;

    return false;
}


bool King::with_King( std::pair < int, int > mPair, Pieces* const ChessPiece[8][8] ) const {

    std::pair < int, int > aux;

    aux.first = mPair.first - 1;
    aux.second = mPair.second - 1;
    if( aux.first < 8 &&  aux.first >= 0 && aux.second < 8 &&  aux.second >= 0 )
        if( ChessPiece[aux.first][aux.second] != NULL )
            if( ChessPiece[aux.first][aux.second] -> getType() == Pieces::KING &&
                    ChessPiece[aux.first][aux.second] -> getColor() != getColor() )
                return true;

    aux.first = mPair.first - 1;
    aux.second = mPair.second;
    if( aux.first < 8 &&  aux.first >= 0 && aux.second < 8 &&  aux.second >= 0 )
        if( ChessPiece[aux.first][aux.second] != NULL )
            if( ChessPiece[aux.first][aux.second] -> getType() == Pieces::KING &&
                    ChessPiece[aux.first][aux.second] -> getColor() != getColor() )
                return true;

    aux.first = mPair.first - 1;
    aux.second = mPair.second + 1;
    if( aux.first < 8 &&  aux.first >= 0 && aux.second < 8 &&  aux.second >= 0 )
        if( ChessPiece[aux.first][aux.second] != NULL )
            if( ChessPiece[aux.first][aux.second] -> getType() == Pieces::KING &&
                    ChessPiece[aux.first][aux.second] -> getColor() != getColor() )
                return true;

    aux.first = mPair.first;
    aux.second = mPair.second - 1;
    if( aux.first < 8 &&  aux.first >= 0 && aux.second < 8 &&  aux.second >= 0 )
        if( ChessPiece[aux.first][aux.second] != NULL )
            if( ChessPiece[aux.first][aux.second] -> getType() == Pieces::KING &&
                    ChessPiece[aux.first][aux.second] -> getColor() != getColor() )
                return true;

    aux.first = mPair.first;
    aux.second = mPair.second + 1;
    if( aux.first < 8 &&  aux.first >= 0 && aux.second < 8 &&  aux.second >= 0 )
        if( ChessPiece[aux.first][aux.second] != NULL )
            if( ChessPiece[aux.first][aux.second] -> getType() == Pieces::KING &&
                    ChessPiece[aux.first][aux.second] -> getColor() != getColor() )
                return true;

    aux.first = mPair.first + 1;
    aux.second = mPair.second - 1;
    if( aux.first < 8 &&  aux.first >= 0 && aux.second < 8 &&  aux.second >= 0 )
        if( ChessPiece[aux.first][aux.second] != NULL )
            if( ChessPiece[aux.first][aux.second] -> getType() == Pieces::KING &&
                    ChessPiece[aux.first][aux.second] -> getColor() != getColor() )
                return true;

    aux.first = mPair.first + 1;
    aux.second = mPair.second;
    if( aux.first < 8 &&  aux.first >= 0 && aux.second < 8 &&  aux.second >= 0 )
        if( ChessPiece[aux.first][aux.second] != NULL )
            if( ChessPiece[aux.first][aux.second] -> getType() == Pieces::KING &&
                    ChessPiece[aux.first][aux.second] -> getColor() != getColor() )
                return true;

    aux.first = mPair.first + 1;
    aux.second = mPair.second + 1;
    if( aux.first < 8 &&  aux.first >= 0 && aux.second < 8 &&  aux.second >= 0 )
        if( ChessPiece[aux.first][aux.second] != NULL )
            if( ChessPiece[aux.first][aux.second] -> getType() == Pieces::KING &&
                    ChessPiece[aux.first][aux.second] -> getColor() != getColor() )
                return true;

    return false;
}

bool King::point_in_chess ( std::pair < int, int > mPair, Pieces* const ChessPiece[8][8] ) const {

    if( with_Rook( mPair, ChessPiece ) )
        return true;
    if( with_Knight( mPair, ChessPiece ) )
        return true;
    if( with_King( mPair, ChessPiece ) )
        return true;
    return false;
}

