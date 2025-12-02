#include "ventanainicio.h"	
#include "raylib.h"	

ventanainicio::ventanainicio() {
    ancho = 1090;
    alto = 600;
    musica = { 0 };
    fondoinicio = { 0 };
    botoninicio = { 0 };
    botonsalir = { 0 };
    BotonPlay = { 0 };
    BotonSalir = { 0 };
    mouse = GetMousePosition();
    juegoiniciado = false; 
    musicaInicio = { 0 };
}

ventanainicio::~ventanainicio() {
	UnloadTexture(fondoinicio);
	UnloadTexture(botoninicio);
	UnloadTexture(botonsalir);    
}

float ventanainicio::anchopantalla(){
	return ancho;
}	
float ventanainicio::altopantalla(){
	return alto;
}			

void ventanainicio::cargaventanainicio() {

    InitWindow(ancho, alto, "Juego de plataforma - TP INTEGRADOR");
    InitAudioDevice();
    musicaInicio = LoadMusicStream("assets/IntroPandala.wav");
    PlayMusicStream(musicaInicio);

    // Carga de texturas
    fondoinicio = LoadTexture("assets/Fondo.png");
    SetTextureFilter(fondoinicio, TEXTURE_FILTER_BILINEAR);

    botoninicio = LoadTexture("assets/play.png");
    SetTextureFilter(botoninicio, TEXTURE_FILTER_BILINEAR);

    botonsalir = LoadTexture("assets/exit.png");
    SetTextureFilter(botonsalir, TEXTURE_FILTER_BILINEAR);

    float scale = 0.4f;
    float posicionX = (GetScreenWidth() - botoninicio.width * scale) / 2;
    float posicionY = (GetScreenHeight() - botoninicio.height * scale) / 2;

    BotonPlay = { posicionX, posicionY, botoninicio.width * scale, botoninicio.height * scale };
    BotonSalir = { posicionX, posicionY + 100, botonsalir.width * scale, botonsalir.height * scale };

    SetTargetFPS(60);

    juegoiniciado = false;

    while (!WindowShouldClose()) {
        mouse = GetMousePosition();
        UpdateMusicStream(musicaInicio);
        // Botón Play
        if (CheckCollisionPointRec(mouse, BotonPlay) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            juegoiniciado = true;
            break; 
        }

        // Botón Salir
        if (CheckCollisionPointRec(mouse, BotonSalir) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            juegoiniciado = false;
            break; 
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextureEx(fondoinicio, { 0.0f, 0.0f }, 0.0f, 0.59f, WHITE);
        DrawTextureEx(botoninicio, { BotonPlay.x, BotonPlay.y }, 0.0f, scale, WHITE);
        DrawTextureEx(botonsalir, { BotonSalir.x, BotonSalir.y }, 0.0f, scale, WHITE);

        EndDrawing();
    }
    StopMusicStream(musicaInicio);
    UnloadMusicStream(musicaInicio);

    CloseWindow();
    if (!juegoiniciado) return;
}
