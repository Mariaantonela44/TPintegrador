#ifndef PLAYER_H
#define PLAYER_H	
#include "raylib.h"	

class player {
private:
	float velocidad;
	float salto;
	float gravedad;	
	float escala;
	Sound sonidosalto;	
	Texture2D Player;
	Color color = WHITE;
	bool cambiocolor;

public:
	bool saltando;
	float  saltoInicioY;
	Vector2 posicion;
	float velocidadY;      
	bool plataforma;
	float inicio;
	int i = 0;	
	void colisionarConPlataforma(Rectangle plataforma);
	Rectangle areajugador;
	Rectangle areaPlataforma1;	
	float ancho;
	float altura;
	player();
	~player();
	void reiniciarPosicion();
	void cargarPlayer();
	void movimiento();
	void Dibujarjugador();
};

#endif