#ifndef GAME_H
#define GAME_H
#include "raylib.h"
#include "player.h"
class game {
private:
	Texture2D ganaste;
	Texture2D gameover;
	Texture2D Fondojuego;
	Rectangle metaplataforma;
	int alto;
	int ancho;
	int vidajugador;
	bool estado;
	bool meta;	
	float escalagame;
	bool pausa;	
	Sound Golpefuerte;
	Music musicaJuego;

public:
	player jugador;
	game();
	~game();
	void reiniciarJuego();
	void ventanajuego();
	void inicializarJuego();

};
#endif 

