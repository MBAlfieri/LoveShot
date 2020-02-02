#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <cstdlib>
#include "NPC.h"

using namespace sf;
using namespace std;

//Clase "Amigos". Hija de "NPC".
//Este será el NPC que no deberemos dañar.

class Amigos : public NPC {

private:  //Características del Amigo

	Sprite s_amigo; //Sprite del Amigo.
	Texture t_amigo; //Textura del Amigo.


public: //Acciones del Amigo.

	Amigos(Vector2f Posicion_Spawn); //Constructor.
	Sprite getSprite(); //Me devolverá el Sprite.

};