#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <cstdlib>
#include "Amigos.h"

using namespace sf;
using namespace std;

Amigos::Amigos(Vector2f Posicion_Spawn) { //Constructor.

	int ColorAmigo; //Me permitir� seleccionar al azar un color de Amigo.

	ColorAmigo = rand() % 4 + 1; //Idem. se seleccionar� un n�mero al azar que definir� de que color ser� el Amigo.

	std::string path; //Path para la implementaci�n de la Textura al azar.

	path = "Amigo" + std::to_string(ColorAmigo) + ".png"; // El n�mero al azar ser� el encargado de definir el color del Amigo.

	t_amigo.loadFromFile(path); //Cargo la Textura.
	s_amigo.setTexture(t_amigo); //Cargo la Textura al Sprite.

	s_amigo.setPosition(Posicion_Spawn); //Definir� la posici�n del Amigo.

}

Sprite Amigos::getSprite() { //Me devolver� el Sprite.

	return s_amigo;

}