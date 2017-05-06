#include "Bishop.h"


Bishop::Bishop(): Pieces(){

}


Bishop::Bishop(std::pair<int, int> position, Color color, std::pair<int, int> texture, int repeat, int moves):
    Pieces(position, color, texture, repeat, moves){
    type = BISHOP;
}


Bishop::Bishop(int tableRow, int tableColumn, Color color, int textureRow, int textureColumn, int repeat, int moves):
    Pieces(tableRow, tableColumn, color, textureRow, textureColumn, repeat, moves){
    type = BISHOP;
}


std::vector<std::pair<int, int>> Bishop::getPossibleMoves(Pieces* const pieces[8][8]) const{
    std::vector<std::pair<int, int>> possibleMoves;

    std::function<bool(std::pair<int, int>)> isOutOfBoard = [](std::pair<int, int> square) -> bool{
        int i = square.first;
        int j = square.second;
        return !(i >= 0 && i <= 7 && j >= 0 && j <= 7);
    };

    //Verificam in sensul dreapta-sus
    bool stop = false;
    std::pair<int, int> currentSquare = this->getPozition();
    while(!stop){
        currentSquare.first++;
        currentSquare.second++;
        if(!isOutOfBoard(currentSquare)){
            if(pieces[currentSquare.first][currentSquare.second] == nullptr){
                possibleMoves.push_back(currentSquare);
            }else{
                stop = true;
                if(pieces[currentSquare.first][currentSquare.second]->getColor() != this->getColor()){
                    possibleMoves.push_back(currentSquare);
                }
            }
        }else{
            stop = true;
        }
    }


    //Verificam in sensul stanga-sus
    stop = false;
    currentSquare = this->getPozition();
    while(!stop){
        currentSquare.first--;
        currentSquare.second++;
        if(!isOutOfBoard(currentSquare)){
            if(pieces[currentSquare.first][currentSquare.second] == nullptr){
                possibleMoves.push_back(currentSquare);
            }else{
                stop = true;
                if(pieces[currentSquare.first][currentSquare.second]->getColor() != this->getColor()){
                    possibleMoves.push_back(currentSquare);
                }
            }
        }else{
            stop = true;
        }
    }

    //Verificam in sensul stanga-jos
    stop = false;
    currentSquare = this->getPozition();
    while(!stop){
        currentSquare.first--;
        currentSquare.second--;
        if(!isOutOfBoard(currentSquare)){
            if(pieces[currentSquare.first][currentSquare.second] == nullptr){
                possibleMoves.push_back(currentSquare);
            }else{
                stop = true;
                if(pieces[currentSquare.first][currentSquare.second]->getColor() != this->getColor()){
                    possibleMoves.push_back(currentSquare);
                }
            }
        }else{
            stop = true;
        }
    }

    //Verificam in sensul drepata-jos;
    stop = false;
    currentSquare = this->getPozition();
    while(!stop){
        currentSquare.first++;
        currentSquare.second--;
        if(!isOutOfBoard(currentSquare)){
            if(pieces[currentSquare.first][currentSquare.second] == nullptr){
                possibleMoves.push_back(currentSquare);
            }else{
                stop = true;
                if(pieces[currentSquare.first][currentSquare.second]->getColor() != this->getColor()){
                possibleMoves.push_back(currentSquare);
                }
            }
        }else{
            stop = true;
        }
    }

    return possibleMoves;

}



bool Bishop::valid(std::pair<int, int> moveCoords, Pieces* const pieces[8][8]) const{
    std::vector<std::pair<int, int>> possibleMoves = this->getPossibleMoves(pieces);
    return std::find(possibleMoves.begin(), possibleMoves.end(), moveCoords) != possibleMoves.end();
}



Bishop::~Bishop(){}
