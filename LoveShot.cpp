/*	Trabajo Pr�ctico N�mero 1
	Alumna: Micaela B. Alfieri
	Materia: Modelos y Algoritmos para Videojuegos I
	Instituci�n: Universidad Nacional del Litoral
	A�o: 2020 */


#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include "Enemigos.h"
#include "Amigos.h"
#include "Juego.h"
#include "Jugador.h"

using namespace std;
using namespace sf;


int main(int argc, char* args[]) {

	srand(time(NULL));

	Juego Jugador1({ 800, 600 }, "LoveShot");

	return 0;

}

