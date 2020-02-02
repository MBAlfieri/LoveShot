#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <cstdlib>
#include "Amigos.h"

using namespace sf;
using namespace std;

Amigos::Amigos(Vector2f Posicion_Spawn) { //Constructor.

	int ColorAmigo; //Me permitirá seleccionar al azar un color de Amigo.

	ColorAmigo = rand() % 4 + 1; //Idem. se seleccionará un número al azar que definirá de que color será el Amigo.

	std::string path; //Path para la implementación de la Textura al azar.

	path = "Amigo" + std::to_string(ColorAmigo) + ".png"; // El número al azar será el encargado de definir el color del Amigo.

	t_amigo.loadFromFile(path); //Cargo la Textura.
	s_amigo.setTexture(t_amigo); //Cargo la Textura al Sprite.

	s_amigo.setPosition(Posicion_Spawn); //Definirá la posición del Amigo.

}

Sprite Amigos::getSprite() { //Me devolverá el Sprite.

	return s_amigo;

}