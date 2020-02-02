#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "MiJuego.h"



MiJuego::MiJuego(Vector2f ResolucionPantalla, String LoveShot) {

	JuegoContinua = false;

	FuncionamientoJuego();

	Texturas();

}





void MiJuego::Texturas() {


    t_background.loadFromFile("C:\\Users\\Mikan\\Desktop\\LoveShot\\Assets\\Fondo.png");
	s_background.setTexture(t_background);
	s_background.setPosition(0, 0);

	t_enemigo1.loadFromFile("C:\\Users\Mikan\Desktop\LoveShot\Assets\Enemigo1.png");
	s_enemigo1.setTexture(t_enemigo1);

	t_enemigo2.loadFromFile("C:\\Users\Mikan\Desktop\LoveShot\Assets\Enemigo2.png");
	s_enemigo2.setTexture(t_enemigo2);

	t_enemigo3.loadFromFile("C:\\Users\Mikan\Desktop\LoveShot\Assets\Enemigo3.png");
	s_enemigo3.setTexture(t_enemigo3);

	t_enemigo4.loadFromFile("C:\\Users\Mikan\Desktop\LoveShot\Assets\Enemigo4.png");
	s_enemigo4.setTexture(t_enemigo4);

	t_Mira.loadFromFile("C:\\Users\Mikan\Desktop\LoveShot\Assets\Mira.png");
	s_Mira.setTexture(t_Mira);


}