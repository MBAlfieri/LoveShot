#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <cstdlib>

using namespace sf;
using namespace std;

//Clase Jugador. Basicamente contiene las Vidas del Jugador.

class JugadorUno {

private:

	int Vidas; //Número de las vidas.

	Sprite s_Corazon1; //Sprite de 1 Corazón.
	Texture t_Corazon1; //Textura de 1 Corazón

	Sprite s_Corazon2; //Sprite de 2 Corazones.
	Texture t_Corazon2; // Textura de los 2 Corazones

	Sprite s_Corazon3; //Sprite de los 3 Corazones.
	Texture t_Corazon3;// Textura de los 3 Corazones

	Sprite s_Vidas; //Sprite del Texto "Vidas"
	Texture t_Vidas; //Textura del Texto "Vidas"

	Sprite s_Puntos; //Sprite del Texto "Puntos".
	Texture t_Puntos; //Sprite del Texto "Puntos."

public:

	JugadorUno(); //Constructor.

	Sprite getSpriteVidas(); //Me devuelve el Sprite del Texto "Vidas".
	Sprite getSpritePuntos(); //Me devuelve el Sprite del Texto "Puntos".
	Sprite getSpriteCorazon3Vidas(); //Me devuelve el Sprite de los 3 Corazones.
	Sprite getSpriteCorazon2Vidas(); //Me devuelve el Sprite de los 2 Corazones.
	Sprite getSpriteCorazon(); //Me devuelve el Sprite del Corazón.

	void setRestarVidas(); //Resta las Vidas del jugador.
	void setSpriteCorazon3Vidas(); //Define la posicion de los 3 Corazones.
	void setSpriteCorazon2Vidas(); //Define la posicion de los 2 Corazones.
	void setSpriteCorazon1Vida(); //Define la posicion del Corazón

	int getVidas(); //Me devuelve las Vidas del Jugador.

};
