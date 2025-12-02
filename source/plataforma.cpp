#include "plataforma.h"
#include "raylib.h"

plataforma::plataforma() {
    Plataforma = { 0 };                
    posicion = { 0.0f, 0.0f };           
    escala = 0.4f;                        
    areaPlataforma = { 0, 0, 0, 0 };     
}

plataforma::~plataforma() {
    UnloadTexture(Plataforma);           
}


void plataforma::cargarPlataforma() {
    Plataforma = LoadTexture("assets/Plataforma.png");
    SetTextureFilter(Plataforma, TEXTURE_FILTER_BILINEAR);
    actualizarArea();                   
}


void plataforma::actualizarArea() {
    areaPlataforma = {posicion.x,posicion.y,Plataforma.width * escala,Plataforma.height * escala };
}


void plataforma::Dibujarplataforma() {
    actualizarArea();                    
    DrawTextureEx(Plataforma, posicion, 0.0f, escala, WHITE);
    DrawRectangleRec(areaPlataforma, Fade(RAYWHITE, 0.0f)); 
}