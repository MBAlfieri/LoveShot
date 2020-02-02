#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> 
#include <cstdlib>
#include "Amigos.h"
#include "Enemigos.h"
#include "Jugador.h"

using namespace std;
using namespace sf;

//Clase "Juego". Es la encargada del funcionamiento de todo el título. Es la más "pesada" de todas.

class Juego {

private: //Características del Enemigo.

	RenderWindow * VentanaJuego; //Ventana del Juego.

	Sprite s_fondo; //Sprite del Fondo del juego.
	Texture t_fondo; //Textura del Fondo del juego.

	Sprite s_GameOver; //Sprite de la pantalla de Game Over.
	Texture t_GameOver; //Textura de la pantalla de Game Over.

	Sprite s_Mira; //Sprite de la Mira.
	Texture t_Mira; //Textura de la Mira.

	Sprite s_Inicio; //Sprite del Logo inicial.
	Texture t_Inicio; //Textura del Logo inicial.

	Sprite s_Logo; //Sprite del Logo de UNL.
	Texture t_Logo; //Textura del Logo de UNL.

	sf::SoundBuffer buffer1; //Buffer del disparo del Jugador.
	sf::Sound Disparo1; //Sonido del disparo del ujgador.

	sf::SoundBuffer buffer2; //Buffer del disparo de los Enemigos.
	sf::Sound Disparo2; //Sonido del disparo de los Enemigos.

	sf::SoundBuffer buffer3;//Buffer del Grito 1.
	sf::Sound Grito1; //Sonido del Grito 1..

	sf::SoundBuffer buffer4;//Buffer del Grito 2.
	sf::Sound Grito2; //Sonido del Grito 2.

	sf::SoundBuffer buffer5;//Buffer del Grito 3.
	sf::Sound Grito3; //Sonido del Grito 3.

	sf::SoundBuffer buffer6;//Buffer del Grito 4.
	sf::Sound Grito4; //Sonido del Grito 4.

	sf::SoundBuffer buffer7;//Buffer del Grito 5.
	sf::Sound Grito5; //Sonido del Grito 5.

	sf::SoundBuffer buffer8;//Buffer del Grito 6.
	sf::Sound Grito6; //Sonido del Grito 6.

	sf::SoundBuffer buffer9;//Buffer de la campana que suena al inicio del Juego.
	sf::Sound Bell; //Sonido de la campana que suena al inicio del Juego.

	sf::SoundBuffer buffer10;//Buffer de la segunda campana que suena al inicio del Juego.
	sf::Sound Bell2; //Sonido de la segunda campana que suena al inicio del Juego.

	Event * EventosJuego; //Eventos que transcurrirán a lo largo del juego.

	Enemigo * Enemigos[7]; //Proviene de la Clase "Enemigos". Es la cantidad de Enemigos que pueden Spawnear.

	Amigos* Amigo[7]; //Proviene de la Clase "Amigos". Es la cantidad de Amigos que pueden Spawnear.

	JugadorUno * JugadorNuevo; //Proviene de la Clase "Jugador".

	Font * Fuente; //Es la Fuente nueva.
	Text * MisPuntos; //Es el texto que muestra los puntos.
	Color * ColorFont; //Color de la Fuente.
	String * StringPuntos; //Es el String que contiene los puntos.

	Clock * Cronometro; //Clock para el funcionamiento de varias operaciones del juego.
	Time * TiempoTranscurrido; //Tiempo para el funcionamiento de varias operaciones del juego.
	float Tiempo; //Idem.

	Clock* Cronometro2; //Clock para el funcionamiento de varias operaciones del juego.
	Time* TiempoTranscurrido2;//Tiempo para el funcionamiento de varias operaciones del juego.

	bool Ending = false; //Define si se inicia la pantalla de Game Over.
	bool PosicionesPersonajes[7]; //Son las posibles posiciones en la pantalla que cada NPC puede tener.
	bool JuegoTermina; //Define si se termina el juego.
	int PosicionRandom; //Permite seleccionar una posicion en pantalla al azar.
	int NPCRandom; //Permite seleccionar un NPC al azar.
	int Puntos; //Puntos.
	int PuntosFinales; //Puntos Finales.

public:

	Juego(Vector2f ResolucionPantalla, String TituloDelJuego); //Es la Pantalla del juego.
	void LoopFuncionamientoJuego(); //Es el loop principal del juego.
	void FondoPantalla(); //Carga los Sprites de las diversas pantallas.
	void Sonidos(); //Carga los sonidos del juego.
	void EventosDelJuego(); //Son los eventos del juego.
	void setJuegoTermina(); //Define si el loop principal se termina.
	void setGameOver(); //Define si se va a mostrar la pantalla de Game Over.
	void setEnding(); //Define si se va a mostrar la pantalla de Game Over.
	void setStringPuntos(); //Cambia el tamaño y la posición de los Puntos.

};

