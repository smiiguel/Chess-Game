#ifndef PIECES_H
#define PIECES_H

#include <vector>
#include "Table.h"
#include <SDL.h>

class Pieces{

    public:
        enum Color{
            WHITE,
            BLACK
        };

    protected:
        int m_pieceHeight;
        int m_pieceWidth;
        bool m_alive;
        bool m_selected;
        bool m_moved;
        int m_repeat;
        int m_moves;
        int sign(Color);
        SDL_Point* m_directions;
        SDL_Point m_tableCorner; // coordonatele de pe tabla unde va fi afiasata piesa(coltul patratelului)
        SDL_Point m_textureCorner; //coordonatele din poza cu piese de unde va fi afisata piesa(tot colt)
        Color m_color;
        SDL_Texture* m_texture; //textura

    public:
        Pieces();
        Pieces(int column, int row, Color color,int,int,int,int);
        virtual ~Pieces();
        //SDL_Point getEvent(SDL_Event*);

        inline int getPieceWidth(){
            return m_pieceWidth;
        }

        inline int getPieceHeight(){
            return m_pieceHeight;
        }

        inline int getTableCornerX(){
            return m_tableCorner.x;
        }

        inline int getTableCornerY(){
            return m_tableCorner.y;
        }

        inline int getTextureCornerX(){
            return m_textureCorner.x;
        }

        inline int getTextureCornerY(){
            return m_textureCorner.y;
        }

        inline void setSelected(bool x){
            m_selected = x;
        }

        inline void setAlive(bool x){
            m_alive = x;
        }

        inline bool isSelected(){
            return m_selected;
        }

        inline bool isAlive(){
            return m_alive;
        }

        inline void setAlpha(int a){
            SDL_SetTextureAlphaMod(m_texture,a);
        }

        inline void setTableCornerX(int x){
            m_tableCorner.x = x;
        }

        inline void setTableCornerY(int y){
            m_tableCorner.y = y;
        }

        inline Color getColor(){
            return m_color;
        }

        inline void setMoved(bool x){
            m_moved = x;
        }

       // int getColumn();
        //void setColumn(int column);
        //int getRow();
        //void setRow(int row);
        //Color getColor();
        //void setColor(Color color); //Metoda setColor s-ar putea sa nu fie utila vreodata, nu vad vreo situatie in care sa vrem sa
                                    //schimbam culoarea unei piese. Ramane de vazut daca e sau nu nevoie

        /*Returneaza un vector cu toate coordonatele (coloana, rand) pe care piesa se poate muta.
        Trebuie sa primeasca sub o forma configuratia tablei.
        Ramane de vazut daca forma va fi asta sau alta (de ex: sa primeasca un obiect din clasa Tabla
        */

        virtual std::vector<std::pair<int, int>> getPossibleMoves(int v[8][8],int,int,std::vector<Pieces*>){}

        /*Returneza daca mutarea piesei la coloana x si randul y este o mutare valida.
        Aceeasi problema ca mai sus
        Dupa ce getPossibleMoves e implementata, validateMove s-ar putea eventual implementa pur si simplu in vectorul dat de getPossibleMoves
        */

        //virtual bool isValidMove(int x, int y, const std::vector<Piece*>& board) = 0;
};


#endif // PIECES_H
