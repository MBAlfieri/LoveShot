#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <cstdlib>
#include "NPC.h"

using namespace sf;
using namespace std;

//Clase "Amigos". Hija de "NPC".
//Este ser� el NPC que no deberemos da�ar.

class Amigos : public NPC {

private:  //Caracter�sticas del Amigo

	Sprite s_amigo; //Sprite del Amigo.
	Texture t_amigo; //Textura del Amigo.


public: //Acciones del Amigo.

	Amigos(Vector2f Posicion_Spawn); //Constructor.
	Sprite getSprite(); //Me devolver� el Sprite.

};