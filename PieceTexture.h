#ifndef PIECETEXTURE_H_INCLUDED
#define PIECETEXTURE_H_INCLUDED
#include <SDL.h>

class PieceTexture{

    private:
        int m_pieceHeight;
        int m_pieceWidth;
        SDL_Texture* m_texture;

    public:
        void Render(int,int,SDL_Rect*);
        bool LoadMedia(const char*);
        inline int getPieceWidth(){
            return m_pieceWidth;
        }

        inline int getPieceHeight(){
            return m_pieceHeight;
        }

        inline void setAlpha(int a){
            SDL_SetTextureAlphaMod(m_texture,a);
        }
};


#endif // PIECETEXTURE_H_INCLUDED
