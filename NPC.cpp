#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <cstdlib>
#include "NPC.h"

using namespace sf;
using namespace std;

NPC::NPC() { //Constructor

	Spawn = new Clock; //Declaro el Clock.
	TiempoSpawn = new Time; //Declaro el Time.
	*TiempoSpawn = Spawn->getElapsedTime(); //Hará que TiempoSpawn obtenga el tiempo transcurrido.

}


float NPC::getTiempoSpawn() { //Me devolverá el Tiempo transcurrido para el Spawn del personaje.

	*TiempoSpawn = Spawn->getElapsedTime();
	return TiempoSpawn->asSeconds(); 

}