#ifndef ENEMIGO_h
#define ENEMIGO_H
#include "raylib.h"	


class enemigo{	
	public:
	float direccion;
	float velocidad;	
	float izquierda;
	float derecha;
	float ancho;	
	float altura;
	Texture2D Enemigo;
	float escala;
	Vector2 posicion;
	Rectangle areaEnemigo;	
	enemigo(float x, float y);
	~enemigo();
	void cargarEnemigo();
	void movilidadenemigo();
	void DibujarEnemigo();
};;
#endif

