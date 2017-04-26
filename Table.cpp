#include "Table.h"
#include "Variables.h"
#include <SDL_image.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

Table::Table(){}

Table::Table(int x){

    m_width = 0;
    m_height = 0;
    m_cellWidth = 0;
    m_cellHeight = 0;
    m_colNumber = x;
    m_rowNumber = x;
}

Table::~Table(){
    SDL_DestroyTexture(m_tableTexture);
}

void Table::Render(int x,int y,SDL_Rect* rect){

    SDL_Rect auxRect;
    auxRect.x = x;
    auxRect.y = y;
    auxRect.w = rect -> w;
    auxRect.h = rect -> h;

    SDL_RenderCopy(renderer,m_tableTexture,rect,&auxRect);
}

bool Table::LoadMedia(const char* src){

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
            m_tableTexture = SDL_CreateTextureFromSurface(renderer,surface);

            if(m_tableTexture == NULL){
                std :: cout << "Textura neinitializata:" << SDL_GetError();
                return false;
            }
            else{

                m_width = surface -> w;
                m_height = surface -> h;
                m_cellWidth = m_width / m_colNumber;
                m_cellHeight = (m_height - 30) / m_rowNumber;

                SDL_FreeSurface(surface);
            }
        }
    }

    return true;
}

bool Table::Init(){

    if((SDL_Init(SDL_INIT_VIDEO) || SDL_Init(SDL_INIT_EVENTS) || SDL_Init(SDL_INIT_AUDIO))){
        std :: cout << "SDL Video sau SDL Audio sau SDL Event neinitializat:" << SDL_GetError();
        return false;
    }
    else
        window = SDL_CreateWindow("Chess Game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                                  SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

    if(window == NULL){
        std :: cout << "Fereastra nu a fost initializata:" << SDL_GetError();
        return false;
    }

    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1")){
        std :: cout << "Linear texture neinitializat:" << SDL_GetError();
        return false;
    }
    else
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(renderer == NULL){
        std :: cout << "Rendererul nu a fost initializat:" << SDL_GetError();
        return false;
    }
    else
        SDL_SetRenderDrawColor(renderer,0,0,0xFF,0xFF);

    int flag = IMG_INIT_JPG;

    if(!(IMG_Init(flag) & flag)){
        std :: cout << "IMG nu a fost initializat:" << SDL_GetError();
        return false;
    }

    if(TTF_Init()){
        std :: cout << "TTF nu a fost initializat:" << SDL_GetError();
        return 0;
    }

    return true;
}

void Table::Close(){

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;

    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}
