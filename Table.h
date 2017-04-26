#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED
#include <SDL.h>
#include "Variables.h"

class Table{

    private:
        int m_width, m_height; // latimea si inaltimea tablei de sah (670x640,am adaugat 30 de cm jos pt o banda neagra unde afisam chestii)
        int m_colNumber, m_rowNumber; //numarul de coloare si de linii al tablei
        int m_cellWidth, m_cellHeight; //latimea si inaltimea unui patratel
        SDL_Texture* m_tableTexture; //textura

    public:
        Table();
        Table(int); //constructor
        ~Table();
        void Render(int,int,SDL_Rect*); //randeaza tabla de sah in fereastra
        bool LoadMedia(const char*); //incarca poza(tabla de sah)
        bool Init(); //initializari
        void Close(); //un fel de destructor pt librarii

        inline int getTableWidth(){
            return m_width;
        }

        inline int getTableHeight(){
            return m_height;
        }

        inline int getCellWidth(){
            return m_cellWidth;
        }

        inline int getCellHeight(){
            return m_cellHeight;
        }
};

#endif // TABLE_H_INCLUDED
