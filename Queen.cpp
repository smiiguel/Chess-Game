#include "Queen.h"

Queen::Queen(): Pieces(){
    type = QUEEN;
}


Queen::Queen(std::pair<int, int> position, Color color, std::pair<int, int> texture):
    Pieces(position, color, texture){
    type = QUEEN;
}


Queen::Queen(int tableRow, int tableColumn, Color color, int textureRow, int textureColumn):
    Pieces(tableRow, tableColumn, color, textureRow, textureColumn){
    type = QUEEN;
}


std::pair<int, int> Queen::findThisColorKing(Pieces* const pieces[8][8]) const{
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



std::vector<std::pair<int, int>> Queen::getPossibleMoves(Pieces* const pieces[8][8]) const{
    std::vector<std::pair<int, int>> possibleMoves;

    std::function<bool(std::pair<int, int>)> isOutOfBoard = [](std::pair<int, int> square) -> bool{
        int i = square.first;
        int j = square.second;
        return !(i >= 0 && i <= 7 && j >= 0 && j <= 7);
    };

    King* king = dynamic_cast<King*>(pieces[findThisColorKing(pieces).first][findThisColorKing(pieces).second]);

    bool stop = false;
    std::pair<int, int> currentSquare = this->getPozition();
    while(!stop){
        currentSquare.first++;
        currentSquare.second++;
        if(!isOutOfBoard(currentSquare)){
            Pieces* simulated[8][8];
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    simulated[i][j] = pieces[i][j];
                }
            }
            simulated[currentSquare.first][currentSquare.second] = pieces[getPozition().first][getPozition().second];
            simulated[getPozition().first][getPozition().second] = nullptr;
            if(pieces[currentSquare.first][currentSquare.second] == nullptr){
                if(!king->are_in_chess(simulated)){
                    possibleMoves.push_back(currentSquare);
                }
            }else{
                stop = true;
                if(pieces[currentSquare.first][currentSquare.second]->getColor() != this->getColor()){
                    if(!king->are_in_chess(simulated)){
                        possibleMoves.push_back(currentSquare);
                    }
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
            Pieces* simulated[8][8];
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    simulated[i][j] = pieces[i][j];
                }
            }
            simulated[currentSquare.first][currentSquare.second] = pieces[getPozition().first][getPozition().second];
            simulated[getPozition().first][getPozition().second] = nullptr;
            if(pieces[currentSquare.first][currentSquare.second] == nullptr){
                if(!king->are_in_chess(simulated)){
                    possibleMoves.push_back(currentSquare);
                }
            }else{
                stop = true;
                if(pieces[currentSquare.first][currentSquare.second]->getColor() != this->getColor()){
                    if(!king->are_in_chess(simulated)){
                        possibleMoves.push_back(currentSquare);
                    }
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
            Pieces* simulated[8][8];
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    simulated[i][j] = pieces[i][j];
                }
            }
            simulated[currentSquare.first][currentSquare.second] = pieces[getPozition().first][getPozition().second];
            simulated[getPozition().first][getPozition().second] = nullptr;
            if(pieces[currentSquare.first][currentSquare.second] == nullptr){
                if(!king->are_in_chess(simulated)){
                    possibleMoves.push_back(currentSquare);
                }
            }else{
                stop = true;
                if(pieces[currentSquare.first][currentSquare.second]->getColor() != this->getColor()){
                    if(!king->are_in_chess(simulated)){
                        possibleMoves.push_back(currentSquare);
                    }
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
            Pieces* simulated[8][8];
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    simulated[i][j] = pieces[i][j];
                }
            }
            simulated[currentSquare.first][currentSquare.second] = pieces[getPozition().first][getPozition().second];
            simulated[getPozition().first][getPozition().second] = nullptr;
            if(pieces[currentSquare.first][currentSquare.second] == nullptr){
                if(!king->are_in_chess(simulated)){
                    possibleMoves.push_back(currentSquare);
                }
            }else{
                stop = true;
                if(pieces[currentSquare.first][currentSquare.second]->getColor() != this->getColor()){
                    if(!king->are_in_chess(simulated)){
                        possibleMoves.push_back(currentSquare);
                    }
                }
            }
        }else{
            stop = true;
        }
    }

    stop = false;
    currentSquare = this->getPozition();
    while(!stop){
        currentSquare.first--;
        if(!isOutOfBoard(currentSquare)){
            Pieces* simulated[8][8];
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    simulated[i][j] = pieces[i][j];
                }
            }
            simulated[currentSquare.first][currentSquare.second] = pieces[getPozition().first][getPozition().second];
            simulated[getPozition().first][getPozition().second] = nullptr;
            if(pieces[currentSquare.first][currentSquare.second] == nullptr){
                if(!king->are_in_chess(simulated)){
                    possibleMoves.push_back(currentSquare);
                }
            }else{
                stop = true;
                if(pieces[currentSquare.first][currentSquare.second]->getColor() != this->getColor()){
                    if(!king->are_in_chess(simulated)){
                        possibleMoves.push_back(currentSquare);
                    }
                }
            }
        }else{
            stop = true;
        }
    }

    stop = false;
    currentSquare = this->getPozition();
    while(!stop){
        currentSquare.first++;
        if(!isOutOfBoard(currentSquare)){
            Pieces* simulated[8][8];
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    simulated[i][j] = pieces[i][j];
                }
            }
            simulated[currentSquare.first][currentSquare.second] = pieces[getPozition().first][getPozition().second];
            simulated[getPozition().first][getPozition().second] = nullptr;
            if(pieces[currentSquare.first][currentSquare.second] == nullptr){
                if(!king->are_in_chess(simulated)){
                    possibleMoves.push_back(currentSquare);
                }
            }else{
                stop = true;
                if(pieces[currentSquare.first][currentSquare.second]->getColor() != this->getColor()){
                    if(!king->are_in_chess(simulated)){
                        possibleMoves.push_back(currentSquare);
                    }
                }
            }
        }else{
            stop = true;
        }
    }

    stop = false;
    currentSquare = this->getPozition();
    while(!stop){
        currentSquare.second++;
        if(!isOutOfBoard(currentSquare)){
            Pieces* simulated[8][8];
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    simulated[i][j] = pieces[i][j];
                }
            }
            simulated[currentSquare.first][currentSquare.second] = pieces[getPozition().first][getPozition().second];
            simulated[getPozition().first][getPozition().second] = nullptr;
            if(pieces[currentSquare.first][currentSquare.second] == nullptr){
                if(!king->are_in_chess(simulated)){
                    possibleMoves.push_back(currentSquare);
                }
            }else{
                stop = true;
                if(pieces[currentSquare.first][currentSquare.second]->getColor() != this->getColor()){
                    if(!king->are_in_chess(simulated)){
                        possibleMoves.push_back(currentSquare);
                    }
                }

            }
        }else{
            stop = true;
        }
    }

    stop = false;
    currentSquare = this->getPozition();
    while(!stop){
        currentSquare.second--;
        if(!isOutOfBoard(currentSquare)){
            Pieces* simulated[8][8];
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    simulated[i][j] = pieces[i][j];
                }
            }
            simulated[currentSquare.first][currentSquare.second] = pieces[getPozition().first][getPozition().second];
            simulated[getPozition().first][getPozition().second] = nullptr;
            if(pieces[currentSquare.first][currentSquare.second] == nullptr){
                if(!king->are_in_chess(simulated)){
                    possibleMoves.push_back(currentSquare);
                }
            }else{
                stop = true;
                if(pieces[currentSquare.first][currentSquare.second]->getColor() != this->getColor()){
                    if(!king->are_in_chess(simulated)){
                        possibleMoves.push_back(currentSquare);
                    }
                }
            }
        }else{
            stop = true;
        }
    }

    return possibleMoves;
}


bool Queen::valid(std::pair<int, int> moveCoords, Pieces* const pieces[8][8]) const{
    std::vector<std::pair<int, int>> possibleMoves = getPossibleMoves(pieces);
    return std::find(possibleMoves.begin(), possibleMoves.end(), moveCoords) != possibleMoves.end();
}
