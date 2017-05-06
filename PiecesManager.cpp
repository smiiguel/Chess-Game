#include "PiecesManager.h"

PiecesManager* PiecesManager::instance = 0;

PiecesManager* PiecesManager::getInstance( )
{
    if ( instance == 0 )
        instance = new PiecesManager( );

    return instance;
}

PiecesManager::~PiecesManager(){
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            if( Chess[i][j] != NULL )
                delete Chess[i][j];
    delete instance;
}

PiecesManager::PiecesManager( ) {
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            Chess[i][j] = NULL;
}

void PiecesManager::GetPieces( Pieces* Matrix[][8] ) const{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            Matrix[i][j] = Chess[i][j];
}

bool PiecesManager::AddPieces( Pieces* piece ) {
    if(piece == NULL)
        return 0;
    Chess[piece->getRow()][piece->getColumn()] = piece;
    return 1;
}

bool PiecesManager::DeletePieces( std::pair < int, int > MyPair) {
    if(Chess[MyPair.first][MyPair.second] == NULL)
        return 0;
    Chess[MyPair.first][MyPair.second] -> setAlive(false);
    return 1;
}

bool PiecesManager::RevivePieces( std::pair < int, int > MyPair ) {
    if(Chess[MyPair.first][MyPair.second] == NULL)
        return 0;
    Chess[MyPair.first][MyPair.second] -> setAlive(true);
    return 1;
}

bool PiecesManager::MovePieces( std::pair < int, int > Initial, std::pair < int, int > Final) {

}
