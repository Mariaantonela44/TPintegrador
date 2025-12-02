#include"player.h" 
#include "plataforma.h" 
#include <raylib.h> 

player::player() {
    sonidosalto = { 0 };
    Player = { 0 };
    saltoInicioY = 0;
    posicion = { 100.0f, 300.0f };
    escala = 0.4f;
    velocidad = 200.0f;
    salto = 40.0f;
    saltando = false;
    inicio = 0;
    areajugador = { 0 };
    ancho = 0;
    altura = 0;
    areaPlataforma1 = { 0 };
    velocidadY = 0;
    plataforma = false;
    gravedad = 500.0f;
    color = WHITE;
    cambiocolor = false;
    sonidosalto = { 0 };
}
player::~player() {
    UnloadTexture(Player);
    UnloadSound(sonidosalto);
}
//carga del jugador

void player::cargarPlayer() {
    Player = LoadTexture("assets/gatito.png");
    SetTextureFilter(Player, TEXTURE_FILTER_BILINEAR);
    sonidosalto = LoadSound("assets/salto.wav");
    ancho = Player.width * escala;
    altura = Player.height * escala;
    areajugador = { posicion.x, posicion.y, ancho, altura };

}

void player::movimiento() {

    float deltatime = GetFrameTime();

    // MOVIMIENTO IZQUIERDA Y DERECHA 
    if (IsKeyDown(KEY_RIGHT)) {
        posicion.x = posicion.x + velocidad * deltatime;
    }
    if (IsKeyDown(KEY_LEFT)) {
        posicion.x = posicion.x - velocidad * deltatime;
    }
    if (IsKeyPressed(KEY_UP)) {
        cambiocolor=!cambiocolor;
    }

    if (cambiocolor) {
        color = YELLOW;
    }
    else {
        color = WHITE;
    }

    // SALTO 
    if (!saltando && IsKeyPressed(KEY_SPACE) && plataforma) {
        saltando = true;
        plataforma = false;
        PlaySound(sonidosalto);


    }
    //gravedad 
    velocidadY = velocidadY + gravedad * deltatime;
    posicion.y = posicion.y + velocidadY * deltatime;

    float velocidadSubida = 350.0f;
    float velocidadCaida = 200.0f;
    /*
        if (saltando) {
            posicion.y = posicion.y-velocidadSubida * deltatime;

            // Si llegaste a la altura máxima
            if (posicion.y <= inicio - salto) {
                saltando = false;  // comienza a caer
            }
        }
        else { // cayendo
            if (posicion.y < inicio) {
                posicion.y = posicion.y+velocidadCaida * deltatime;
                if (posicion.y > inicio) {
                    posicion.y = inicio;
                }
            }
        }*/

    float  saltoInicioY = 0;
    //saltar solo con espacio y en la plataforma    
    if (IsKeyPressed(KEY_SPACE) && plataforma) {
        saltando = true;
        plataforma = false;
        saltoInicioY = posicion.y;
    }

    //salto subida
    if (saltando) {
        posicion.y -= velocidadSubida * deltatime;

        // Limitar altura del salto
        if (saltoInicioY - posicion.y >= salto) {
            saltando = false; // llegó a la altura máxima
        }
    }

    // Caída
    if (!saltando) {
        if (posicion.y < inicio) {
            posicion.y = posicion.y + velocidadCaida * deltatime;
            if (posicion.y > inicio) posicion.y = inicio;
        }
    }

    if (IsKeyPressed(KEY_SPACE) && plataforma) {
        velocidadY = velocidadY - velocidad;
        plataforma = false;
    }

    //LÍMITES 
    float anchoPantalla = 1080;
    float alturaPantalla = 600;

    if (posicion.x < 0) {
        posicion.x = 0;
    }
    if (posicion.y < 0) {
        posicion.y = 0;
    }
    if ((posicion.x + Player.width * escala) > anchoPantalla) {
        posicion.x = anchoPantalla - Player.width * escala;
    }
    /*if ((posicion.y + Player.height * escala) > alturaPantalla) {
        posicion.y = alturaPantalla - Player.height * escala;
        velocidadY = 0;
        plataforma = true;
    } */


    // Actualizacion area del jugador   
    areajugador = { posicion.x, posicion.y, ancho, altura };
}
void player::Dibujarjugador() {
    DrawTextureEx(Player, posicion, 0.0f, escala, color);
};
//COLISIONES

//CON PLATAFORMAS   
void player::colisionarConPlataforma(Rectangle plataformaRect) {

    if (posicion.x + ancho > plataformaRect.x &&
        posicion.x < plataformaRect.x + plataformaRect.width) {

        float topePlataforma = plataformaRect.y - altura;


        if (posicion.y + altura >= plataformaRect.y - 5 &&
            posicion.y + altura <= plataformaRect.y + 10) {

            posicion.y = topePlataforma;
            velocidadY = 0;
            plataforma = true;
            saltando = false;
        }
    }

    // Actualizar  area del jugador
    areajugador = { posicion.x, posicion.y, ancho, altura };
}
void player::reiniciarPosicion() {
    posicion = { 100.0f, 300.0f };
}
