#ifndef PLAFORMA_H	
#define PLATFORMA_H	
#include "raylib.h"

class plataforma {	
	public:
	Texture2D Plataforma;
	float escala;
	Vector2 posicion;
	Rectangle areaPlataforma;
	plataforma();
	~plataforma();
	void cargarPlataforma();
	void Dibujarplataforma();
	void actualizarArea();
};	
#endif 