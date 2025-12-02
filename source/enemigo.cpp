#include "enemigo.h"
#include "raylib.h"	

enemigo::enemigo(float x, float y){
	areaEnemigo = { 0 };	
	Enemigo = { 0 };	
	escala=0.2f;
	posicion = { x,y };
	velocidad=2;
	direccion = -1;
	izquierda = x - 150;
	derecha = x + 150;
	ancho = 0;
	altura = 0;	
}		

enemigo::~enemigo(){
	
}	

void enemigo::cargarEnemigo(){
	Enemigo= LoadTexture("assets/perrito.png");
	SetTextureFilter(Enemigo, TEXTURE_FILTER_BILINEAR);	
	ancho = Enemigo.width * escala;
	altura = Enemigo.height * escala;
	areaEnemigo = { posicion.x, posicion.y, ancho, altura };


	//limites de movimiento del enemigo	
	if (izquierda < 0) izquierda = 0;

	if (derecha > 1090 - ancho)
		derecha = 1090 - ancho;
}	

void enemigo::movilidadenemigo(){

	posicion.x= posicion.x+velocidad*direccion;

	if (posicion.x <= izquierda) {
		direccion = 1;   
	}
	if (posicion.x >= derecha) {
		direccion = -1;  
	}
	areaEnemigo.x=posicion.x;

	areaEnemigo = { posicion.x, posicion.y, ancho, altura };
}	
void enemigo::DibujarEnemigo(){
	DrawTextureEx(Enemigo,posicion,0.0f,escala,WHITE);
	areaEnemigo = { posicion.x, posicion.y, ancho, altura };
}	