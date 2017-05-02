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
    Chess[piece->m_pozition.first][piece->m_pozition.second] = piece;
    return 1;
}

