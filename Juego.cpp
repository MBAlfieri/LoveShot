#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <cstdlib>
#include "Juego.h"


Juego::Juego(Vector2f ResolucionPantalla, String TituloDelJuego) { //Constructor.

	JuegoTermina = true; //Es "True" al inicio. Una vez que pasan las pantallas de introducci�n, se vuelve "False".

	VentanaJuego = new RenderWindow(VideoMode(ResolucionPantalla.x, ResolucionPantalla.y), TituloDelJuego); //Crea la Pantalla.

	VentanaJuego->setFramerateLimit(60); //FPS del juego.

	VentanaJuego->setMouseCursorVisible(false); //Oculta el cursor.

	for (int i = 0; i < 6; i++) { //Hace que todas las posibles posiciones en pantalla que pueden tener los NPCS se encuentren vac�os, en un principio.
		PosicionesPersonajes[i] = false;
	}

	EventosJuego = new Event; //Eventos del Juego.

	FondoPantalla(); //Cargo los Sprites y las Texturas del juego.
	Sonidos(); //Cargo los sonidos del juego.

	Cronometro = new Clock; //Inicializo el cron�metro.
	TiempoTranscurrido = new Time; //Inicializo el Tiempo.
	Tiempo = 0; //Idem.

	JugadorNuevo = new JugadorUno; //Crea el Jugador nuevo.

	Fuente = new Font(); //Es la Fuente.
	Fuente->loadFromFile("GILB.ttf"); //Define qu� fuente cargar.
	StringPuntos = new String; //String de los Puntos.
	ColorFont = new Color; //Color de la Fuente.
	ColorFont->Black; //Hace que el color de la Fuente sea de color Negro.
	MisPuntos = new Text(); //Texto que tendr� los Puntos.
	MisPuntos->setFont(*Fuente); //Cargo la Fuente.
	MisPuntos->setPosition(105, 564); //Posici�n del texto.
	MisPuntos->setScale(1, 1); //Tama�o del texto.
	MisPuntos->setOutlineThickness(2); //Tama�o del borde del texto.
	MisPuntos->setOutlineColor(*ColorFont); //Color del Borde del texto.

	LoopFuncionamientoJuego(); //Loop principal del Juego.
}


void Juego::LoopFuncionamientoJuego() { //Es el loop principal del juego.

//------------------------------------------------------------------------------------------Pantallas de introduccion.

Bell.play(); //Reproduce un sonido de campana.

while (JuegoTermina == true) {

	VentanaJuego->clear();

	VentanaJuego->draw(s_Inicio); //Muestra el primer Logo.

	*TiempoTranscurrido = Cronometro->getElapsedTime();

		if (TiempoTranscurrido->asSeconds() > 5 + Tiempo) {

			Tiempo = TiempoTranscurrido->asMilliseconds();

			Bell2.play();//Reproduce un sonido de campana.

		}


		if (TiempoTranscurrido->asSeconds() > 5) {

			Tiempo = TiempoTranscurrido->asMilliseconds();

			VentanaJuego->draw(s_Logo); //Muestra el segundo Logo.


			if (TiempoTranscurrido->asSeconds() > 9) {

				setJuegoTermina(); //Permite que se termine la pantalla de introducci�n y se inicie el juego.
			}
		}

	VentanaJuego->display();

}

//------------------------------------------------------------------------------------------Inicio del Juego.
while (JuegoTermina == false) {

	*StringPuntos = to_string(Puntos); //Convierto los puntos en un String.
	
	MisPuntos->setString(*StringPuntos); //Deposito los puntos en StringPuntos.

	*TiempoTranscurrido = Cronometro->getElapsedTime();

	for (int i = 0; i < 7; i++) { //Revisa si las posiciones de los NPC est�n disponibles para Spawnear. Si no lo estan, se elimina el NPC luego de un cierto tiempo.

		if (PosicionesPersonajes[i] != NULL) { 

			if (Amigo[i]) { //Luego de 4 segundos el NPC Amigo desaparece y se libera la posici�n.

				if (Amigo[i]->getTiempoSpawn() > 4) {

					Amigo[i] = NULL;

					PosicionesPersonajes[i] = false;
				}
			}

			if (Enemigos[i]) {

				if (Enemigos[i]->getTiempoSpawn() > 5) { //Luego de 5 segundos, el NPC Enemigo dispara, desaparece y se libera la posici�n.

					Disparo2.play();

					JugadorNuevo->setRestarVidas();

					PosicionesPersonajes[i] = false;

					Enemigos[i] = NULL;

				}
			}
		}
	}


//------------------------------------------------------------------------------------------Posiciones de Spawn y Probabilidades.

	for (int i = 0; i < 999; i++) { //Este 'for' basicamente decide cuantos enemigos se van a spawnear a lo largo del juego. Si se implementaran niveles, le pondr�a un l�mite m�s bajo.

		if (TiempoTranscurrido->asMilliseconds() > 500 + Tiempo) {

			Tiempo = TiempoTranscurrido->asMilliseconds();

			PosicionRandom = rand() % 8; //Decide una posici�n en pantalla al azar.
			NPCRandom = (rand() % 100); //Elige un numero al azar. De acuerdo a este n�mero va a aparecer cierto NPC.

//------------------------------------------------------------------------------------------Posici�n 0.
			if (PosicionesPersonajes[0] == false && PosicionRandom == 0) { //Si la posici�n 0 est� libre y el n�mero generado al azar es 0, se spawnea un NPC.

				PosicionesPersonajes[0] = true; //La posici�n de spawn se "llena".

				if (NPCRandom < 75) { //Existe un 75% de probabilidad de que se spawnee un Enemigo, en base al n�mero al azar que se ha generado. Sino, se genera un Amigo.

					Enemigos[0] = new Enemigo({ (float)(130.0),288.0 });

				}

				else {

					Amigo[0] = new Amigos({ (float)(133.0),249.0 });

				}

				break;
			}

//------------------------------------------------------------------------------------------Posici�n 1.
			if (PosicionesPersonajes[1] == false && PosicionRandom == 1) { //Si la posici�n 1 est� libre y el n�mero generado al azar es 1, se spawnea un NPC.

				PosicionesPersonajes[1] = true; //La posici�n de spawn se "llena".

				if (NPCRandom < 75) { //Existe un 75% de probabilidad de que se spawnee un Enemigo, en base al n�mero al azar que se ha generado. Sino, se genera un Amigo.

					Enemigos[1] = new Enemigo({ (float)(229.0),94.0 });

				}

				else {

					Amigo[1] = new Amigos({ (float)(232.0),55.0 });

				}

				break;
			}

//------------------------------------------------------------------------------------------Posici�n 2.
				if (PosicionesPersonajes[2] == false && PosicionRandom == 2) {//Si la posici�n 2 est� libre y el n�mero generado al azar es 2, se spawnea un NPC.

					PosicionesPersonajes[2] = true; //La posici�n de spawn se "llena".

					if (NPCRandom < 75) { //Existe un 75% de probabilidad de que se spawnee un Enemigo, en base al n�mero al azar que se ha generado. Sino, se genera un Amigo.

						Enemigos[2] = new Enemigo({ (float)(440.0),96.0 });

					}

					else {

						Amigo[2] = new Amigos({ (float)(435.0),57.0 });

					}

				break;
			}

//------------------------------------------------------------------------------------------Posici�n 3.
				if (PosicionesPersonajes[3] == false && PosicionRandom == 3) { //Si la posici�n 3 est� libre y el n�mero generado al azar es 3, se spawnea un NPC.

					PosicionesPersonajes[3] = true;  //La posici�n de spawn se "llena".

					if (NPCRandom < 75) { //Existe un 75% de probabilidad de que se spawnee un Enemigo, en base al n�mero al azar que se ha generado. Sino, se genera un Amigo.

						Enemigos[3] = new Enemigo({ (float)(330.0),368.0 });

					}

					else {

						Amigo[3] = new Amigos({ (float)(330.0),329.0 });

					}

				break;
			}

//------------------------------------------------------------------------------------------Posici�n 4.
				if (PosicionesPersonajes[4] == false && PosicionRandom == 4) { //Si la posici�n 4 est� libre y el n�mero generado al azar es 4, se spawnea un NPC.

					PosicionesPersonajes[4] = true; //La posici�n de spawn se "llena".

					if (NPCRandom < 75) { //Existe un 75% de probabilidad de que se spawnee un Enemigo, en base al n�mero al azar que se ha generado. Sino, se genera un Amigo.
						 
						Enemigos[4] = new Enemigo({ (float)(35.0),92.0 });

					}

					else {

						Amigo[4] = new Amigos({ (float)(33.0),53.0 });

					}

				break;
			}

//------------------------------------------------------------------------------------------Posici�n 5.
				if (PosicionesPersonajes[5] == false && PosicionRandom == 5) {//Si la posici�n 5 est� libre y el n�mero generado al azar es 5, se spawnea un NPC.

					PosicionesPersonajes[5] = true; //La posici�n de spawn se "llena".

					if (NPCRandom < 75) { //Existe un 75% de probabilidad de que se spawnee un Enemigo, en base al n�mero al azar que se ha generado. Sino, se genera un Amigo.

						Enemigos[5] = new Enemigo({ (float)(530.0),285.0 });

					}

					else {

						Amigo[5] = new Amigos({ (float)(530.0),246.0 });

					}

				break;
			}

//------------------------------------------------------------------------------------------Posici�n 6.
				if (PosicionesPersonajes[6] == false && PosicionRandom == 6) { //Si la posici�n 6 est� libre y el n�mero generado al azar es 6, se spawnea un NPC.

					PosicionesPersonajes[6] = true; //La posici�n de spawn se "llena".

					if (NPCRandom < 75) { //Existe un 75% de probabilidad de que se spawnee un Enemigo, en base al n�mero al azar que se ha generado. Sino, se genera un Amigo.

						Enemigos[6] = new Enemigo({ (float)(617.0),97.0 });

					}

					else {

						Amigo[6] = new Amigos({ (float)(621.0),58.0 });

					}

				break;
			}

		}

	}

//------------------------------------------------------------------------------------------Elementos que se muestran en pantalla.

	VentanaJuego->clear();

	EventosDelJuego(); //Eventos del Juego.

	VentanaJuego->draw(s_fondo); //Dibuja el fondo principal.


	for (int i = 0; i < 7; i++) { //Si la posici�n est� vac�a, dibuja al NPC.

		if (Enemigos[i] != NULL) {

			VentanaJuego->draw(Enemigos[i]->getSprite());

		}

		if (Amigo[i] != NULL) {

			VentanaJuego->draw(Amigo[i]->getSprite());

		}

	}


	VentanaJuego->draw(JugadorNuevo->getSpriteVidas()); //Muestra el Sprite de las Vidas

	VentanaJuego->draw(JugadorNuevo->getSpritePuntos()); //Muestra el Sprite de los Puntos.


		if (JugadorNuevo->getVidas() == 3) { //Si se tienen 3 vidas, se muestra el Sprite correspondiente.

			VentanaJuego->draw(JugadorNuevo->getSpriteCorazon3Vidas());

		}

		if (JugadorNuevo->getVidas() == 2) { //Si se tienen 2 vidas, se muestra el Sprite correspondiente y se mueve Sprite el anterior.

			JugadorNuevo->setSpriteCorazon3Vidas();
			VentanaJuego->draw(JugadorNuevo->getSpriteCorazon3Vidas());
			VentanaJuego->draw(JugadorNuevo->getSpriteCorazon2Vidas());

		}

		if (JugadorNuevo->getVidas() == 1) {//Si se tiene 1 vida, se muestra el Sprite correspondiente y se mueve Sprite el anterior.

			JugadorNuevo->setSpriteCorazon2Vidas();
			VentanaJuego->draw(JugadorNuevo->getSpriteCorazon2Vidas());
			VentanaJuego->draw(JugadorNuevo->getSpriteCorazon());

		}

		if (JugadorNuevo->getVidas() == 0) {//Si no se tienen m�s vidas, se quitan los Sprites y se termina el juego.

			JugadorNuevo->setSpriteCorazon1Vida();
			VentanaJuego->draw(JugadorNuevo->getSpriteCorazon());

			setEnding();
			setGameOver();

		}


	VentanaJuego->draw(*MisPuntos); //Dibuja los Puntos.

	VentanaJuego->draw(s_Mira); //Dibuja la Mira.
	
	VentanaJuego->display();

	}

//------------------------------------------------------------------------------------------Una vez que se termin� el juego, se muestra la pantalla de Game Over.

	while (Ending == true) {

		PuntosFinales = Puntos * 10; //Seg�n mi interpretaci�n del enunciado, he decidio multiplicar los puntos ganados x 10.

		*StringPuntos = to_string(PuntosFinales); // Convierto los Puntos Finales en un String.

		setStringPuntos(); //Cambio la posici�n del Sprite de los Puntos para que aparezcan en el medio de la pantalla.

		MisPuntos->setString(*StringPuntos);  //Deposito el String.

		VentanaJuego->draw(s_GameOver); //Muestra la Pantalla de Game Over.

		VentanaJuego->draw(*MisPuntos); //Muestra los Puntos Finales.

		VentanaJuego->display();

	}

}


void Juego::setStringPuntos() { //Cambia el tama�o y la posici�n de los Puntos.

	MisPuntos->setPosition(380, 285);
	MisPuntos->setScale(1.50, 1.50);

}


void Juego::setJuegoTermina() {//Define si el loop principal se termina.

	JuegoTermina = false;

}

void Juego::setGameOver() { //Define si se va a mostrar la pantalla de Game Over

	JuegoTermina = true;

}

void Juego::setEnding() {//Define si se va a mostrar la pantalla de Game Over.

	Ending = true;

}

void Juego::FondoPantalla() { //Carga los Sprites de las diversas pantallas.

	t_Inicio.loadFromFile("Runa Games.png");
	s_Inicio.setTexture(t_Inicio);

	t_Logo.loadFromFile("Logo2.png");
	s_Logo.setTexture(t_Logo);

	t_fondo.loadFromFile("Fondo.png");
	s_fondo.setTexture(t_fondo);

	t_Mira.loadFromFile("Mira.png");
	s_Mira.setTexture(t_Mira);

	t_GameOver.loadFromFile("GameOver.png");
	s_GameOver.setTexture(t_GameOver);

}

void Juego::Sonidos() { //Carga los sonidos del juego.

	buffer1.loadFromFile("Disparo1.wav");
	Disparo1.setBuffer(buffer1);

	buffer2.loadFromFile("Disparo2.wav");
	Disparo2.setBuffer(buffer2);

	buffer3.loadFromFile("Ow1.wav");
	Grito1.setBuffer(buffer3);

	buffer4.loadFromFile("Ow2.wav");
	Grito2.setBuffer(buffer4);

	buffer5.loadFromFile("Ow3.wav");
	Grito3.setBuffer(buffer5);

	buffer6.loadFromFile("Ow4.wav");
	Grito4.setBuffer(buffer6);

	buffer7.loadFromFile("Ouch2.wav");
	Grito5.setBuffer(buffer7);

	buffer8.loadFromFile("Ouch3.wav");
	Grito6.setBuffer(buffer8);

	buffer9.loadFromFile("Bell.wav");
	Bell.setBuffer(buffer9);

	buffer10.loadFromFile("Bell2.wav");
	Bell2.setBuffer(buffer10);

}

void Juego::EventosDelJuego() { //Eventos del Juego.

	while (VentanaJuego->pollEvent(*EventosJuego)) {

		switch (EventosJuego->type) {
//------------------------------------------------------------------------------------------Permite cerrar la ventana.
			case Event::Closed:

				VentanaJuego->close();

			break;

//------------------------------------------------------------------------------------------Permite mover la Mira.
			case Event::MouseMoved:

				s_Mira.setPosition((Vector2f)Mouse::getPosition(*VentanaJuego));

			break;

//------------------------------------------------------------------------------------------Permite que la Mira interact�e con los NPCS.
			case Event::MouseButtonPressed:

				Disparo1.play(); //Se reproduce un sonido de disparo cada vez que se hace click.

				FloatRect Pos(s_Mira.getPosition(), (Vector2f)s_Mira.getTexture()->getSize()); //Obtiene la posici�n de la Mira.

					for (int i = 0; i < 7; i++) {

						if (Enemigos[i]) { //Se realiza una acci�n si el Amigo est� presente.

							if (Enemigos[i]->getSprite().getGlobalBounds().intersects(Pos)) { //Si el Sprite de la Mira y el Enemigo se tocan al momento de hacer click, este desaparece.

							Puntos++; //Al dispararle a un enemigo, se gana 1 punto.

							NPCRandom = (rand() % 100); //Se genera un n�mero al azar para definir que grito se va a escuchar.

							Enemigos[i] = NULL; //Se elimina al Anemigo.

							PosicionesPersonajes[i] = false; //Se vac�a la posic�n del enemigo derrotado.

								if (NPCRandom < 30) {//Si se obtiene un n�mero menor a 30, se reproduce el Grito 1.

								Grito1.play();

								}

								if (NPCRandom > 30 && NPCRandom < 60) { //Si se obtiene un n�mero mayor a 30 y menor que 60, se reproduce el Grito 2.

								Grito2.play();

								}

								if (NPCRandom > 60 && NPCRandom < 80) {//Si se obtiene un n�mero mayor a 60 y menor que 80, se reproduce el Grito 3.

								Grito3.play();

								}

								if (NPCRandom > 80) { //Si se obtiene un n�mero mayor a 90, se reproduce el Grito 4.

								Grito4.play();

								}
							}
						}	

						if (Amigo[i]) { //Se realiza una acci�n si el Amigo est� presente.

							if (Amigo[i]->getSprite().getGlobalBounds().intersects(Pos)) { //Si el Sprite de la Mira y el Amigo se tocan al momento de hacer click, este desaparece.

								Amigo[i] = NULL; //Se elimina al Amigo.

								Puntos--; //Si se dispara a un Amigo, se pierde un punto.

								JugadorNuevo->setRestarVidas(); //Si se dispara a un Amigo, se pierde una vida.

								PosicionesPersonajes[i] = false; //Se vac�a la posic�n del Amigo abatido.

								NPCRandom = (rand() % 100); //Se genera un n�mero al azar para definir que grito se va a escuchar.

									if (NPCRandom < 50) { //Si se obtiene un n�mero menor a 50, se reproduce el Grito 5.

									Grito5.play();

									}

									if (NPCRandom > 50) {//Si se obtiene un n�mero mayor a 50, se reproduce el Grito 6.

									Grito6.play();

								}
							}
						}
				}
		}
	}
}


