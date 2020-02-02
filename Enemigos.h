#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <cstdlib>
#include "NPC.h"

using namespace sf;
using namespace std;

//Clase "Enemigos". Hija de "NPC".
//Este será el NPC que debemos derrotar.

class Enemigo : public NPC{
	
private: //Características del Enemigo.

	Sprite s_enemigo; //Sprite del Enemigo.
	Texture t_enemigo; //Textura del Enemigo.
	Clock * RelojAtaque; //Reloj que permitirá definir cuanto tiempo va a pasar antes de que el Enemigo ataque.
	Time * TiempoAtaque; //Idem

public: //Acciones del Amigo.

	Enemigo(Vector2f PosicionSpawn); //Constructor.
	Sprite getSprite(); //Me devolverá el Sprite.
	float getTiempo(); //Me devolverá el Tiempo.

};
