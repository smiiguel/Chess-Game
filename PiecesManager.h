#ifndef PIECESMANAGER_H_INCLUDED
#define PIECESMANAGER_H_INCLUDED
#include "Pieces.h"

class PiecesManager{ //Singleton class

private:
    static PiecesManager* instance;
    PiecesManager( );
    Pieces* Chess[8][8];

public:
    static PiecesManager* getInstance( );
    virtual ~PiecesManager();
    void GetPieces( Pieces* Matrix[][8] ) const;
    bool AddPieces( Pieces* piece );
    bool DeletePieces( std::pair < int, int > );
    bool RevivePieces( std::pair < int, int > );
    bool MovePieces( std::pair < int, int >, std::pair < int, int > );
};

#endif // PIECESMANAGER_H_INCLUDED
