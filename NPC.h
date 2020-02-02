#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <cstdlib>
 
using namespace sf;
using namespace std;

//Clase "NPC". Madre de las Clases "Amigos" y "Enemigos".
//Esta Clase basicamente crear� un "cron�metro" para cada personaje a medida que aparezcan en la pantalla.

class NPC {

protected: //Caracter�sticas del NPC.

	Clock * Spawn; //Me medir� el tiempo transcurrido.
	Time * TiempoSpawn; //Me representar� el tiempo transcurrido.

public://Acciones del NPC.

	NPC(); //Constructor
	float getTiempoSpawn(); //Me devolver� el Tiempo transcurrido para el Spawn del personaje.

};