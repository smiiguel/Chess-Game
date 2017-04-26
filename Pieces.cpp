#include "Pieces.h"
#include <SDL_image.h>
#include <iostream>
#include "Variables.h"
#include <vector>
#include <utility>

Pieces::Pieces(){}

Pieces::Pieces(int tableColumn,int tableRow,Color color,int textureColumn,int textureHeight,int repeat,int moves){

    m_color = color;
    m_alive = true;
    m_selected = false;
    m_moved = false;
    m_repeat = repeat;
    m_moves = moves;
    m_tableCorner.x = tableColumn;
    m_tableCorner.y = tableRow;
    m_textureCorner.x = textureColumn;
    m_textureCorner.y = textureHeight;
}

Pieces::~Pieces(){}

Pieces::sign(Color color){

    if(color == WHITE)
        return 1;
    return -1;
}
