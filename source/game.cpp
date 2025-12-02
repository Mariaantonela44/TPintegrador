#include "game.h"
#include "raylib.h"
#include "player.h"
#include "plataforma.h"
#include "enemigo.h"

game::game() {
	ancho = 1090;
	alto = 600;
	Fondojuego = { 0 };
	gameover = { 0 };
	ganaste = { 0 };
	vidajugador = 3;
	estado = false;
	meta = false;
	escalagame = 0.5f;
	metaplataforma = {0};
	pausa = false;
	Golpefuerte = { 0 };
	musicaJuego = { 0 };
}


game::~game() {
	UnloadTexture(Fondojuego);
	UnloadTexture(gameover);
	UnloadTexture(ganaste);
	UnloadSound(Golpefuerte);	
	UnloadMusicStream(musicaJuego);

}

void game::reiniciarJuego() {
	vidajugador = 3;
	jugador.reiniciarPosicion();
	estado = false;
	meta = false;	

}

void game::ventanajuego() {
	SetWindowPosition(200, 100);
	InitWindow(ancho, alto, "Comienzo de juego");
	//InitAudioDevice();

	Fondojuego = LoadTexture("assets/Fondojuego.png");
	SetTextureFilter(Fondojuego, TEXTURE_FILTER_BILINEAR);
	gameover = LoadTexture("assets/gameover.png");
	SetTextureFilter(gameover, TEXTURE_FILTER_BILINEAR);
	ganaste = LoadTexture("assets/ganaste.png");
	SetTextureFilter(ganaste, TEXTURE_FILTER_BILINEAR);
	Golpefuerte = LoadSound("assets/GolpeFuerte.wav");
	musicaJuego = LoadMusicStream("assets/pandala.wav");
	PlayMusicStream(musicaJuego);


		

	//jugador

	jugador.cargarPlayer();


	//plaformas
	plataforma plataforma1;
	plataforma1.posicion = { 51.0f, 390.0f };
	plataforma1.cargarPlataforma();

	/*plataforma plataforma2;
	plataforma2.posicion = { 261.0f, 458.0f };
	plataforma2.cargarPlataforma();*/


	plataforma plataforma3;
	plataforma3.posicion = { 404.0f, 346.0f };
	plataforma3.cargarPlataforma();


	/*plataforma plataforma4;
	plataforma4.posicion = { 620.0f, 451.0f };
	plataforma4.cargarPlataforma();*/


	plataforma plataforma5;
	plataforma5.posicion = { 664.0f, 234.0f };
	plataforma5.cargarPlataforma();


	plataforma plataforma6;
	plataforma6.posicion = { 809.0f, 541.0f };
	plataforma6.cargarPlataforma();

	plataforma plataforma7;
	plataforma7.posicion = { 956.0f, 423.0f };
	plataforma7.cargarPlataforma();


	metaplataforma.x = plataforma6.posicion.x;            
	metaplataforma.y = plataforma6.posicion.y-5;           
	metaplataforma.width = plataforma6.areaPlataforma.width;  
	metaplataforma.height = plataforma6.areaPlataforma.height;


	//enemigos
	enemigo enemigo1(400, 285);
	enemigo enemigo2(700, 175);
	enemigo enemigo3(840, 368);

	enemigo1.cargarEnemigo();
	enemigo2.cargarEnemigo();
	enemigo3.cargarEnemigo();



	SetTargetFPS(60);


	while (!WindowShouldClose()) {

		UpdateMusicStream(musicaJuego);
		

		// COLISIONES


		//colisiones plataformas 
		jugador.colisionarConPlataforma(plataforma1.areaPlataforma);
		//jugador.colisionarConPlataforma(plataforma2.areaPlataforma);
		jugador.colisionarConPlataforma(plataforma3.areaPlataforma);
		//jugador.colisionarConPlataforma(plataforma4.areaPlataforma);
		jugador.colisionarConPlataforma(plataforma5.areaPlataforma);
		jugador.colisionarConPlataforma(plataforma6.areaPlataforma);
		jugador.colisionarConPlataforma(plataforma7.areaPlataforma);

	


		bool estaSobreAlgo = false;


		if (CheckCollisionRecs(jugador.areajugador, plataforma1.areaPlataforma)) {
			estaSobreAlgo = true;
		}
		//if (CheckCollisionRecs(jugador.areajugador, plataforma2.areaPlataforma)) {
		//	estaSobreAlgo = true; }
		
		if (CheckCollisionRecs(jugador.areajugador, plataforma3.areaPlataforma)) {
			estaSobreAlgo = true;
		}
		//if (CheckCollisionRecs(jugador.areajugador, plataforma4.areaPlataforma)) { 
		//	estaSobreAlgo = true; }
		
		if (CheckCollisionRecs(jugador.areajugador, plataforma5.areaPlataforma)) {
			estaSobreAlgo = true;
		}
		
		if (CheckCollisionRecs(jugador.areajugador, plataforma6.areaPlataforma)) {
			estaSobreAlgo = true;
		

		}
		if (CheckCollisionRecs(jugador.areajugador, plataforma7.areaPlataforma)) {
			estaSobreAlgo = true;
		}

		if (CheckCollisionRecs(jugador.areajugador, metaplataforma)) {
			meta = true;           
		}

		//if (meta) estaSobreAlgo = true;

		if (!estaSobreAlgo) {
			jugador.inicio = 300.0f;
		}


		//enemigos	
		enemigo1.movilidadenemigo();
		enemigo2.movilidadenemigo();
		enemigo3.movilidadenemigo();

		if (CheckCollisionRecs(jugador.areajugador, enemigo1.areaEnemigo)) {
			vidajugador = vidajugador - 1;
			PlaySound(Golpefuerte);
			jugador.reiniciarPosicion();
		}
		if (CheckCollisionRecs(jugador.areajugador, enemigo2.areaEnemigo)) {
			vidajugador = vidajugador - 1;
			PlaySound(Golpefuerte);
			jugador.reiniciarPosicion();
		}
		if (CheckCollisionRecs(jugador.areajugador, enemigo3.areaEnemigo)) {
			vidajugador = vidajugador - 1;
			PlaySound(Golpefuerte);
			jugador.reiniciarPosicion();
		}

		float alturaPantalla = 600;
		if (jugador.posicion.y + jugador.areajugador.height >= alturaPantalla) {
			vidajugador = vidajugador - 1;
			PlaySound(Golpefuerte);
			jugador.reiniciarPosicion();
		}

		BeginDrawing();

		ClearBackground(RAYWHITE);

		// Fondo
		DrawTextureEx(Fondojuego, { 0,0 }, 0.0f, 0.59f, WHITE);


		//plataformas
		plataforma1.Dibujarplataforma();
		//plataforma2.Dibujarplataforma();
		plataforma3.Dibujarplataforma();
		//plataforma4.Dibujarplataforma();
		plataforma5.Dibujarplataforma();
		plataforma6.Dibujarplataforma();
		plataforma7.Dibujarplataforma();

		//enemigos
		enemigo1.DibujarEnemigo();
		enemigo2.DibujarEnemigo();
		enemigo3.DibujarEnemigo();

		// Player
		jugador.Dibujarjugador();

		DrawText(TextFormat("Para ganar hay que llegar a la plataforma purpura"), 10, 10, 20, BLACK);
		DrawText(TextFormat("Para cambiar de color del jugador apreta la flecha hacia arriba"), 10, 30, 20, BLACK);
		DrawText(TextFormat("VIDAS DEL JUGADOR: %i", vidajugador), 10, 80, 20, BLACK);
		DrawText(TextFormat("COORDENADAS %.1f    %.1f", jugador.posicion.x, jugador.posicion.y),10, 60, 20, BLACK);
		DrawRectangle(metaplataforma.x,metaplataforma.y,metaplataforma.width,metaplataforma.height,Fade(PURPLE, 0.4f));

		if (vidajugador == 0) {
			estado = true;
		}

		//remarcar meta 
		// 
	
		// Game Over	
		if (estado&&!meta) {
			float x = (GetScreenWidth() - gameover.width * escalagame) / 2;
			float y = (GetScreenHeight() - gameover.height * escalagame) / 2;

			DrawTextureEx(gameover, { x, y }, 0.0f, escalagame, WHITE);
			DrawText("Presiona ENTER para reiniciar", 300, 500, 30, WHITE);

			if (IsKeyPressed(KEY_ENTER)) {
				reiniciarJuego();
			}
		}
	 //ganaste
		if (meta) {
			float x = (GetScreenWidth() - ganaste.width * escalagame) / 2;
			float y = (GetScreenHeight() - ganaste.height * escalagame) / 2;

			DrawTextureEx(ganaste, { x, y }, 0.0f, 0.5f, WHITE);
			DrawText("Presiona ENTER para reiniciar", 300, 500, 30, WHITE);

			if (IsKeyPressed(KEY_ENTER)) {
				reiniciarJuego();
			}
		}

		if (vidajugador <= 0 || meta) {
			pausa = true;
		}
		else {
			pausa = false;
		}

		if (!pausa) {
			jugador.movimiento();
		}

		EndDrawing();
	}
}


void game::inicializarJuego() {};