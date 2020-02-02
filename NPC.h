#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <cstdlib>
 
using namespace sf;
using namespace std;

//Clase "NPC". Madre de las Clases "Amigos" y "Enemigos".
//Esta Clase basicamente creará un "cronómetro" para cada personaje a medida que aparezcan en la pantalla.

class NPC {

protected: //Características del NPC.

	Clock * Spawn; //Me medirá el tiempo transcurrido.
	Time * TiempoSpawn; //Me representará el tiempo transcurrido.

public://Acciones del NPC.

	NPC(); //Constructor
	float getTiempoSpawn(); //Me devolverá el Tiempo transcurrido para el Spawn del personaje.

};