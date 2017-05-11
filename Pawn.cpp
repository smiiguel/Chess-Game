#include "Pawn.h"

///Mai trebuie facut ceva cu ajunsul pe ultima linie si promovarea la alta piesa

Pawn::Pawn(): Pieces(){

}


Pawn::Pawn(std::pair<int, int> position, Color color, std::pair<int, int> texture):
    Pieces(position, color, texture){

}


Pawn::Pawn(int tableRow, int tableColumn, Color color, int textureRow, int textureColumn):
    Pieces(tableRow, tableColumn, color, textureRow, textureColumn){

}


Pawn::~Pawn(){

}

std::pair<int, int> Pawn::findThisColorKing(Pieces* const pieces[8][8]) const{
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            if(pieces[i][j] != nullptr){
                if(pieces[i][j]->getType() == Pieces::KING && pieces[i][j]->getColor() == this->getColor()){
                    return {i, j};
                }
            }
        }
    }
    return {-1, -1}; //eroare dubioasa si grava
}


std::vector<std::pair<int, int>> Pawn::getPossibleMoves(Pieces* const pieces[8][8]) const{
    std::vector<std::pair<int, int>> possibleMoves;

    //Daca pionul este alb atunci a merge in fata inseamna a scadea linia, iar pentru negru a creste linia.
    //Asta in ipoteza in care incepem cu coordonata (0, 0) in coltul stanga-sus, iar piesele albe sunt asezate in partea de jos.
    //Daca nu e asa, trebuie modificat
    int stepForward;
    if(getColor() == WHITE){
        stepForward = -1;
    }else{
        stepForward = +1;
    }

    King* king = dynamic_cast<King*>(pieces[findThisColorKing(pieces).first][findThisColorKing(pieces).second]);

    std::pair<int, int> pos = getPozition();
    //In functie de culoare una din aceste conditii este redundanta, dar este mai simplu sa le punem pe amandoua.
    if(pos.first >= 0 && pos.first <= 6){
        if(pieces[pos.first + stepForward][pos.second] == nullptr){
            Pieces* simulated[8][8];
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    simulated[i][j] = pieces[i][j];
                }
            }
            simulated[pos.first + stepForward][pos.second] = pieces[getPozition().first][getPozition().second];
            simulated[getPozition().first][getPozition().second] = nullptr;
            if(!king->are_in_chess(simulated)){
                possibleMoves.push_back(std::make_pair(pos.first + stepForward, pos.second));
            }
            //Presupunand ca m_moved este true daca piesa a mai fost mutata, si true daca nu.
            //Daca nu e asa trebuie facut un alt membru in Pawn pentru asta
            if(getMoved() == false){
                //Nu mai are rost sa verificam daca nu iesim de pe table pentru ca pionii nemutati statu pe penultima linie in sensul lor de mers
                if(pieces[pos.first + 2 * stepForward][pos.second] == nullptr){
                    simulated[pos.first + 2 * stepForward][pos.second] = simulated[pos.first + stepForward][pos.second];
                    simulated[pos.first + stepForward][pos.second] = nullptr;
                    if(!king->are_in_chess(simulated)){
                        possibleMoves.push_back(std::make_pair(pos.first + 2 * stepForward, pos.second));
                    }
                }
            }
        }
        if(pos.second >= 1){
            if(pieces[pos.first + stepForward][pos.second - 1] != nullptr){
                Pieces* simulated[8][8];
                for(int i = 0; i < 8; i++){
                    for(int j = 0; j < 8; j++){
                        simulated[i][j] = pieces[i][j];
                    }
                }
                simulated[pos.first + stepForward][pos.second - 1] = pieces[getPozition().first][getPozition().second];
                simulated[getPozition().first][getPozition().second] = nullptr;
                if(pieces[pos.first + stepForward][pos.second - 1]->getColor() != this->getColor()){
                    if(!king->are_in_chess(simulated)){
                        possibleMoves.push_back(std::make_pair(pos.first + stepForward, pos.second - 1));
                    }
                }
            }
        }
        if(pos.second <= 6){
            if(pieces[pos.first + stepForward][pos.second + 1] != nullptr){
                Pieces* simulated[8][8];
                for(int i = 0; i < 8; i++){
                    for(int j = 0; j < 8; j++){
                        simulated[i][j] = pieces[i][j];
                    }
                }
                simulated[pos.first + stepForward][pos.second + 1] = pieces[getPozition().first][getPozition().second];
                simulated[getPozition().first][getPozition().second] = nullptr;
                if(pieces[pos.first + stepForward][pos.second + 1]->getColor() != this->getColor()){
                    if(!king->are_in_chess(simulated)){
                        possibleMoves.push_back(std::make_pair(pos.first + stepForward, pos.second + 1));
                    }
                }
            }
        }
    }

    return possibleMoves;
}


bool Pawn::valid(std::pair<int, int> moveCoords, Pieces* const pieces[8][8]) const{
    std::vector<std::pair<int, int>> possibleMoves = getPossibleMoves(pieces);
    return std::find(possibleMoves.begin(), possibleMoves.end(), moveCoords) != possibleMoves.end();
}
