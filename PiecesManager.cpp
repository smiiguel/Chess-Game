#include "PiecesManager.h"

PiecesManager* PiecesManager::instance = 0;


PiecesManager* PiecesManager::getInstance()
{
    if ( instance == 0 )
        instance = new PiecesManager( );

    return instance;
}

PiecesManager::~PiecesManager(){
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            if( ChessPieces[i][j] != NULL )
                delete ChessPieces[i][j];
    delete instance;
}

PiecesManager::PiecesManager( ) {
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            ChessPieces[i][j] = NULL;

    selected = false;
    turn = 0;
    isChess = false;
    isCheckMate = false;
}

void PiecesManager::GetPieces( Pieces* Matrix[][8] ) const{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            Matrix[i][j] = ChessPieces[i][j];
}

bool PiecesManager::AddPieces( Pieces* piece ) {
    if(piece == NULL)
        return 0;
    ChessPieces[piece->getRow()][piece->getColumn()] = piece;
    return 1;
}

bool PiecesManager::DeletePieces( std::pair < int, int > MyPair) {
    if(ChessPieces[MyPair.first][MyPair.second] == NULL)
        return 0;
    ChessPieces[MyPair.first][MyPair.second] -> setAlive(false);
    return 1;
}

bool PiecesManager::RevivePieces( std::pair < int, int > MyPair ) {
    if(ChessPieces[MyPair.first][MyPair.second] == NULL)
        return 0;
    ChessPieces[MyPair.first][MyPair.second] -> setAlive(true);
    return 1;
}

bool PiecesManager::MovePieces( std::pair < int, int > Initial, std::pair < int, int > Final) {
    if(ChessPieces[Initial.first][Initial.second] == NULL)
        return 0;
    std::vector < std::pair < int, int > > moves = ChessPieces[Initial.first][Initial.second] -> getPossibleMoves( ChessPieces );
    for ( std::vector < std::pair < int, int > >::iterator it = moves.begin(); it != moves.end(); ++it )
        if( *it == Final )
            return true;
    return false;
}

bool PiecesManager::InitPieces(int width,int height){

    const int number_of_pawns = 8;

    for(int i = 0;i < number_of_pawns; ++i){
        ChessPieces[1][i] = new Pawn(1,i,Pieces::WHITE,5 * width,(int)Pieces::WHITE * height);
        ChessPieces[6][i] = new Pawn(6,i,Pieces::BLACK,5 * width,(int)Pieces::BLACK * height);
    }

    //WHITE ROOKS
    ChessPieces[0][0] = new Rook(0,0,Pieces::WHITE,0,(int)Pieces::WHITE * height);
    ChessPieces[0][7] = new Rook(0,7,Pieces::WHITE,0,(int)Pieces::WHITE * height);

    //BLACK ROOKS
    ChessPieces[7][0] = new Rook(7,0,Pieces::BLACK,0,(int)Pieces::BLACK * height);
    ChessPieces[7][7] = new Rook(7,7,Pieces::BLACK,0,(int)Pieces::BLACK * height);

    //WHITE BISHOPS
    ChessPieces[0][2] = new Bishop(0,2,Pieces::WHITE,2 * width,(int)Pieces::WHITE * height);
    ChessPieces[0][5] = new Bishop(0,5,Pieces::WHITE,2 * width,(int)Pieces::WHITE * height);

    //BLACK BISHOPS
    ChessPieces[7][2] = new Bishop(7,2,Pieces::BLACK,2 * width,(int)Pieces::BLACK * height);
    ChessPieces[7][5] = new Bishop(7,5,Pieces::BLACK,2 * width,(int)Pieces::BLACK * height);

    //WHITE KNIGHT
    ChessPieces[0][1] = new Knight(0,1,Pieces::WHITE,width,(int)Pieces::WHITE * height);
    ChessPieces[0][6] = new Knight(0,6,Pieces::WHITE,width,(int)Pieces::WHITE * height);

    //BLACK KNIGHT
    ChessPieces[7][1] = new Knight(7,1,Pieces::BLACK,width,(int)Pieces::BLACK * height);
    ChessPieces[7][6] = new Knight(7,6,Pieces::BLACK,width,(int)Pieces::BLACK * height);

    //WHITE QUEEN
    ChessPieces[0][4] = new Queen(0,4,Pieces::WHITE,3 * width,(int)Pieces::WHITE * height);

    //BLACK QUEEN
    ChessPieces[7][4] = new Queen(7,4,Pieces::BLACK,3 * width,(int)Pieces::BLACK * height);

    //WHITE KING
    ChessPieces[0][3] = new King(0,3,Pieces::WHITE,4 * width,(int)Pieces::WHITE * height);

    //BLACK KING
    ChessPieces[7][3] = new King(7,3,Pieces::BLACK,4 * width,(int)Pieces::BLACK * height);

    return true;
}

Pieces* PiecesManager::SwapPieces(std::pair<int,int> p1,std::pair<int,int> p2){

    Pieces* aux;

    aux = ChessPieces[p1.first][p1.second];
    ChessPieces[p1.first][p1.second] = ChessPieces[p2.first][p2.second];
    ChessPieces[p2.first][p2.second] = NULL;

    return aux;
}

void PiecesManager::RestoreTable(std::pair<int,int> p1,std::pair<int,int> p2,Pieces* p){

    ChessPieces[p1.first][p1.second] = ChessPieces[p2.first][p2.second];
    ChessPieces[p2.first][p2.second] = p;
}

std::pair<int,int> PiecesManager::getKing(Pieces::Color color){

    int i, j;
    std::pair<int,int> aux;

    for(i = 0;i < 8; ++i)
        for(j = 0;j < 8; ++j)
            if(ChessPieces[i][j] != NULL && ChessPieces[i][j] -> getColor() == color && ChessPieces[i][j] -> getType() == Pieces::KING){
                aux = std::make_pair(i,j);
                return aux;
            }

    return aux;
}

std::pair<int,int> PiecesManager::getEnemyKing(Pieces::Color color){

    int i, j;
    std::pair<int,int> aux;

    for(i = 0;i < 8; ++i)
        for(j = 0;j < 8; ++j)
            if(ChessPieces[i][j] != NULL && ChessPieces[i][j] -> getColor() != color && ChessPieces[i][j] -> getType() == Pieces::KING){
                aux = std::make_pair(i,j);
                return aux;
            }

    return aux;
}

std::vector<std::pair<int,int >> PiecesManager::HandleEvent(SDL_Point selected_piece,int width,int height){

    bool is_king = false;
    std::pair<int,int> king_position;
    int i, j;

    if(!selected){
        if(ChessPieces[selected_piece.y][selected_piece.x] != NULL){
           if(ChessPieces[selected_piece.y][selected_piece.x] -> getColor() ==(Pieces::Color)(turn % 2)){
                actual_piece = selected_piece;
                selected = true;
                ChessPieces[selected_piece.y][selected_piece.x] -> setSelected(true);
                piece_moves = ChessPieces[selected_piece.y][selected_piece.x] -> getPossibleMoves(ChessPieces);
                piece_moves.push_back(std::make_pair(selected_piece.y,selected_piece.x));

                king_position = getKing(ChessPieces[selected_piece.y][selected_piece.x] -> getColor());
                int len = piece_moves.size();
                --len;
                std::pair<int,int> aux = {selected_piece.y,selected_piece.x};

                if(selected_piece.y != king_position.first || selected_piece.x != king_position.second)
                    for(int i = 0;i < len; ++i){
                        Pieces* p = SwapPieces(piece_moves[i],aux);

                        bool answ = ChessPieces[king_position.first][king_position.second] -> are_in_chess(ChessPieces);
                        RestoreTable(aux,piece_moves[i],p);;

                        if(answ)
                            piece_moves[i] = std::make_pair(-1,-1);
                    }

                last_piece = selected_piece;
           }
        }
    }
    else{

        bool valid_move = false;
        int len = piece_moves.size();

        for(int i = 0;i < len; ++i){
            if(piece_moves[i].first == selected_piece.y && piece_moves[i].second == selected_piece.x){
                valid_move = true;
                break;
            }
        }

        if(valid_move){
            if(last_piece.x != selected_piece.x || last_piece.y != selected_piece.y){
                king_position = getEnemyKing(ChessPieces[last_piece.y][last_piece.x] -> getColor());
                ChessPieces[last_piece.y][last_piece.x] -> setMoved(true);
                ChessPieces[last_piece.y][last_piece.x] -> setSelected(false);
                ChessPieces[last_piece.y][last_piece.x] -> setTableCornerX(selected_piece.x );
                ChessPieces[last_piece.y][last_piece.x] -> setTableCornerY(selected_piece.y );
                ChessPieces[last_piece.y][last_piece.x] -> setPozition({selected_piece.y,selected_piece.x});

                if( ChessPieces[last_piece.y][last_piece.x] -> getType() == Pieces::KING)
                    is_king = true;

                if(is_king && (last_piece.x - selected_piece.x == 2) ) { // MAKE CASTLING LEFT AND MOVE THE ROOK
                    ChessPieces[last_piece.y][last_piece.x] -> setMoved(true);
                   // ChessPieces[last_piece.y][last_piece.x] -> setSelected(false);
                    ChessPieces[last_piece.y][0] -> setTableCornerX( 2 );
                    ChessPieces[last_piece.y][0] -> setTableCornerY(selected_piece.y );
                    ChessPieces[last_piece.y][0] -> setPozition(std::make_pair(last_piece.y, 2));
                    ChessPieces[last_piece.y][2] = ChessPieces[last_piece.y][0];
                    ChessPieces[last_piece.y][0] = NULL;
                }

                if(is_king && (selected_piece.x - last_piece.x == 2) ) { // MAKE CASTLING RIGHT AND MOVE THE ROOK
                    ChessPieces[last_piece.y][last_piece.x] -> setMoved(true);
                   // ChessPieces[last_piece.y][last_piece.x] -> setSelected(false);
                    ChessPieces[last_piece.y][7] -> setTableCornerX( 4 );
                    ChessPieces[last_piece.y][7] -> setTableCornerY(selected_piece.y );
                    ChessPieces[last_piece.y][7] -> setPozition(std::make_pair(last_piece.y, 4));
                    ChessPieces[last_piece.y][4] = ChessPieces[last_piece.y][7];
                    ChessPieces[last_piece.y][7] = NULL;
                }

                if(ChessPieces[selected_piece.y][selected_piece.x] != NULL)
                    ChessPieces[selected_piece.y][selected_piece.x] -> setAlive(false);

                ChessPieces[selected_piece.y][selected_piece.x] = ChessPieces[last_piece.y][last_piece.x];
                ChessPieces[last_piece.y][last_piece.x] = NULL;

                isChess = ChessPieces[king_position.first][king_position.second] -> are_in_chess(ChessPieces);

                if(isChess){
                    isCheckMate = true;
                    for(i = 0;i < 8; ++i)
                        for(j = 0;j < 8; ++j)
                            if(ChessPieces[i][j] != NULL){
                                if(ChessPieces[i][j] -> getColor() == ChessPieces[king_position.first][king_position.second] -> getColor()){
                                    std::vector<std::pair<int,int >> aux = ChessPieces[i][j] -> getPossibleMoves(ChessPieces);
                                    int len = aux.size();
                                    std::pair<int,int> aux_pair = {i,j};

                                    if(i != king_position.first || j != king_position.second)
                                        for(int k = 0;k < len; ++k){
                                            Pieces* p = SwapPieces(aux[k],aux_pair);

                                            bool answ = ChessPieces[king_position.first][king_position.second] -> are_in_chess(ChessPieces);
                                            RestoreTable(aux_pair,aux[k],p);

                                            if(answ)
                                                aux[k] = std::make_pair(-1,-1);
                                        }
                                    for(int k = len - 1;k >= 0; --k)
                                        if(aux[k].first < 0)
                                            aux.pop_back();

                                    if(aux.size()){
                                        isCheckMate = false;
                                        i = 9;
                                        j = 9;
                                    }
                                }

                            }
                }

                turn = (turn + 1) % 70;
            }
            else
                ChessPieces[selected_piece.y][selected_piece.x] -> setSelected(false);
            selected = false;

                piece_moves.erase(piece_moves.begin(),piece_moves.end());
                last_piece = {-1,-1};
        }
    }

    last_piece = actual_piece;

    return piece_moves;
}
