#ifndef  VENTANAINICIO_H	
#define VENTANAINICIO_H	
#include "raylib.h"	



class ventanainicio {
private:
	int ancho;
	int alto;
	Texture2D fondoinicio;
	Texture2D botoninicio;
	Texture2D botonsalir;	
	Vector2 mouse;
	Sound musica;
	Rectangle BotonPlay;
	Rectangle BotonSalir;
	Music musicaInicio;
	
public:
	bool juegoiniciado;
	~ventanainicio();
	ventanainicio();
	void cargaventanainicio();
	float anchopantalla();
	float altopantalla();
	
};

#endif 




