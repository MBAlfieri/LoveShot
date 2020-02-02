#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <cstdlib>
#include "Enemigos.h"

using namespace sf;
using namespace std;

Enemigo::Enemigo(Vector2f PosicionSpawn) {

	int ColorEnemigo; //Me permitir� seleccionar al azar un color de Enemigo. 

	ColorEnemigo = rand() % 4 + 1; //Idem. se seleccionar� un n�mero al azar que definir� de que color ser� el Enemigo.

	std::string path; //Path para la implementaci�n de la Textura al azar.

	path = "Enemigo" + std::to_string(ColorEnemigo) + ".png"; // El n�mero al azar ser� el encargado de definir el color del Enemigo.

	t_enemigo.loadFromFile(path); //Cargo la Textura. 
	s_enemigo.setTexture(t_enemigo); //Cargo la Textura al Sprite.

	s_enemigo.setPosition(PosicionSpawn); //Definir� la posici�n del Enemigo.

	RelojAtaque = new Clock; //Declaro el Clock.
	TiempoAtaque = new Time; //Defino el Time.
	*TiempoAtaque = RelojAtaque->getElapsedTime(); //Har� que TiempoAtaque obtenga el tiempo transcurrido.

}


Sprite Enemigo::getSprite() { //Me devolver� el Sprite.

	return s_enemigo;

}


float Enemigo::getTiempo() { //Me devolver� el Tiempo transcurrido para el Ataque del personaje.

	*TiempoAtaque = RelojAtaque->getElapsedTime();

	return TiempoAtaque->asSeconds();

}