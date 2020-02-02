#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include "Jugador.h"


JugadorUno::JugadorUno() { //Constructor

	Vidas = 3; //El Jugador tendrá 3 vidas.

	t_Vidas.loadFromFile("Vidas.png"); //Cargo la Textura.
	s_Vidas.setTexture(t_Vidas); //Cargo la Textura al Sprite.
	s_Vidas.setPosition(3, 518); //Defino la Posición del Sprite.

	t_Corazon1.loadFromFile("corazon1.png");//Cargo la Textura.
	t_Corazon2.loadFromFile("corazon2.png");//Idem.
	t_Corazon3.loadFromFile("corazon3.png");//Idem.

	s_Corazon1.setTexture(t_Corazon1);//Cargo la Textura al Sprite.
	s_Corazon2.setTexture(t_Corazon2);//Idem.
	s_Corazon3.setTexture(t_Corazon3);//Idem.

	s_Corazon1.setPosition(76, 522);//Defino la Posición del Sprite.
	s_Corazon2.setPosition(73, 522);//Idem.
	s_Corazon3.setPosition(73, 522);//Idem.

	t_Puntos.loadFromFile("Puntos.png");//Cargo la Textura.
	s_Puntos.setTexture(t_Puntos);//Cargo la Textura al Sprite.
	s_Puntos.setPosition(10, 560);//Defino la Posición del Sprite.

}

void JugadorUno::setRestarVidas() { //Resta las Vidas del jugador.

	Vidas--;

}


int JugadorUno::getVidas() { //Me devuelve las Vidas del Jugador.

	return Vidas;

}

Sprite JugadorUno::getSpriteVidas() { //Me devuelve el Sprite del Texto "Vidas".

	return s_Vidas;

}

Sprite JugadorUno::getSpritePuntos() { //Me devuelve el Sprite del Texto "Puntos".

	return s_Puntos;

}

Sprite JugadorUno::getSpriteCorazon3Vidas() { //Me devuelve el Sprite de los 3 Corazones.

	return s_Corazon3;

}

Sprite JugadorUno::getSpriteCorazon2Vidas() { //Me devuelve el Sprite de los 2 Corazones.

	return s_Corazon2;

}

Sprite JugadorUno::getSpriteCorazon() { //Me devuelve el Sprite del Corazón.

	return s_Corazon1;

}

void JugadorUno::setSpriteCorazon3Vidas() { //Define la posicion de los 3 Corazones.

	s_Corazon3.setPosition(1000, 1000);

}

void JugadorUno::setSpriteCorazon2Vidas() { //Define la posicion de los 2 Corazones.

	s_Corazon2.setPosition(1000, 1000);

}

void JugadorUno::setSpriteCorazon1Vida() {//Define la posicion del Corazón.

	s_Corazon1.setPosition(1000, 1000);

}