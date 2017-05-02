#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "Table.h"

//#include "Pawn.h"
#include "Rook.h"
#include "Pieces.h"
#include "Knight.h"
//#include "Bishop.h"
//#include "Queen.h"
#include "King.h"
//#include "PieceTexture.h"
//#include "Init.h"
//#include "Dot.h"
//#include "Texture.h"
#include "PiecesManager.h"

using namespace std;

const int SCREEN_HEIGHT = 670;
const int SCREEN_WIDTH = 640;
const int NUMBER_OF_PIECES = 32;

Pieces* Chess[8][8];

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int main(int args,char* argv[]){

//    Knight* c1=new Knight(5,5,Pieces::BLACK, 0,6, 0, 0);
//    Chess[5][5] = c1;
//    Knight* c2=new Knight(3,2,Pieces::WHITE, 0,6, 0, 0);
//    Chess[3][2] = c2;
//    Rook* r1 = new Rook(1,1,Pieces::WHITE, 0,6, 0, 0);
//    Chess[1][1] = r1;
//    Rook* r2 = new Rook(1,5,Pieces::BLACK, 0,6, 0, 0);
//    Chess[1][5] = r2;
//    King* k1 = new King(5,1,Pieces::BLACK, 0,6, 0, 0);
//    Chess[5][1] = k1;
//    King* k2 = new King(3,1,Pieces::WHITE, 0,6, 0, 0);
//    Chess[3][1] = k2;

    PiecesManager* mag = PiecesManager::getInstance();

    mag -> AddPieces( new Knight(6,3,Pieces::BLACK, 0,6, 0, 0) );

    Pieces* A[8][8];
    mag -> GetPieces(A);
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            if(A[i][j] != NULL)cout<<A[i][j]->getType()<<" "<<A[i][j]->getRow()<<"  "<<A[i][j]->getColumn()<<'\n';

//    Knight* c2=new Knight(7,6,Pieces::BLACK, 0,6, 0, 0);
//    Chess[7][6] = c2;
//    Rook* r1 = new Rook(7,0,Pieces::BLACK, 0,6, 0, 0);
//    Chess[7][0] = r1;
//    Rook* r2 = new Rook(7,7,Pieces::BLACK, 0,6, 0, 0);
//    Chess[7][7] = r2;
//    King* k1 = new King(7,3,Pieces::BLACK, 0,6, 0, 0);
//    Chess[7][3] = k1;
//
//    cout<<boolalpha<<k1 -> point_in_chess(make_pair(7,3), Chess)<<'\n';
//
//    vector <pair<int, int> > aux = k1 -> getPossibleMoves(Chess);
//    for(int i= 0; i <aux.size(); i++)
//        cout<<aux[i].first <<"  "<<aux[i].second<<"  "<<boolalpha<<k1 -> point_in_chess(aux[i], Chess)<<'\n';


    return 0;

}

