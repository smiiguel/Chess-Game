#include "PieceTexture.h"
#include "Variables.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

void PieceTexture::Render(int x,int y,SDL_Rect* rect){
    //std :: cout << x << " " << y << std :: endl;
    SDL_Rect auxRect;
    auxRect.x = x;
    auxRect.y = y;
    auxRect.w = rect -> w;
    auxRect.h = rect -> h;

    //std :: cout << auxRect.w << " " << auxRect.h << std :: endl;

    SDL_RenderCopy(renderer,m_texture,rect,&auxRect);
}

bool PieceTexture::LoadMedia(const char* src){

    int flag = IMG_INIT_JPG;
    if(!(IMG_Init(flag) & flag)){
        std :: cout << "IMG nu a fost initializat:" << SDL_GetError();
        return false;
    }
    else{

        SDL_Surface* surface = IMG_Load(src);

        if(surface == NULL){
            std :: cout << "Suprafata nu a fost incarcata:" << SDL_GetError();
            return false;
        }
        else{
            m_texture = SDL_CreateTextureFromSurface(renderer,surface);

            if(m_texture == NULL){
                std :: cout << "Textura neinitializata:" << SDL_GetError();
                return false;
            }
            else{

                m_pieceWidth = surface -> w / 6;
                m_pieceHeight = surface -> h / 2;

                SDL_FreeSurface(surface);
            }
        }
    }

    return true;
}
