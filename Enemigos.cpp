#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <cstdlib>
#include "Enemigos.h"

using namespace sf;
using namespace std;

Enemigo::Enemigo(Vector2f PosicionSpawn) {

	int ColorEnemigo; //Me permitirá seleccionar al azar un color de Enemigo. 

	ColorEnemigo = rand() % 4 + 1; //Idem. se seleccionará un número al azar que definirá de que color será el Enemigo.

	std::string path; //Path para la implementación de la Textura al azar.

	path = "Enemigo" + std::to_string(ColorEnemigo) + ".png"; // El número al azar será el encargado de definir el color del Enemigo.

	t_enemigo.loadFromFile(path); //Cargo la Textura. 
	s_enemigo.setTexture(t_enemigo); //Cargo la Textura al Sprite.

	s_enemigo.setPosition(PosicionSpawn); //Definirá la posición del Enemigo.

	RelojAtaque = new Clock; //Declaro el Clock.
	TiempoAtaque = new Time; //Defino el Time.
	*TiempoAtaque = RelojAtaque->getElapsedTime(); //Hará que TiempoAtaque obtenga el tiempo transcurrido.

}


Sprite Enemigo::getSprite() { //Me devolverá el Sprite.

	return s_enemigo;

}


float Enemigo::getTiempo() { //Me devolverá el Tiempo transcurrido para el Ataque del personaje.

	*TiempoAtaque = RelojAtaque->getElapsedTime();

	return TiempoAtaque->asSeconds();

}