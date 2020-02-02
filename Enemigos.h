#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <cstdlib>
#include "NPC.h"

using namespace sf;
using namespace std;

//Clase "Enemigos". Hija de "NPC".
//Este ser� el NPC que debemos derrotar.

class Enemigo : public NPC{
	
private: //Caracter�sticas del Enemigo.

	Sprite s_enemigo; //Sprite del Enemigo.
	Texture t_enemigo; //Textura del Enemigo.
	Clock * RelojAtaque; //Reloj que permitir� definir cuanto tiempo va a pasar antes de que el Enemigo ataque.
	Time * TiempoAtaque; //Idem

public: //Acciones del Amigo.

	Enemigo(Vector2f PosicionSpawn); //Constructor.
	Sprite getSprite(); //Me devolver� el Sprite.
	float getTiempo(); //Me devolver� el Tiempo.

};
