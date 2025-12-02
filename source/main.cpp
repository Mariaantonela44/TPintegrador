#include "ventanainicio.h"  
#include "game.h"
#include "raylib.h" 


int main() {
  
    ventanainicio ventana;
    ventana.cargaventanainicio();

    if (ventana.juegoiniciado) {
        game juego;
        juego.ventanajuego(); 
    }
  
    return 0;}
