#include <iostream>
#include "SFML\Graphics.hpp"

using namespace std;

sf::RenderWindow ventana(sf::VideoMode(412,600),"Tetris");

sf::Texture background;
sf::Sprite bg(background);

int cargarFondo() {
	if (!background.loadFromFile("Asset//bg.png")) {
		cout << "Error al cargar la imagen" << endl;
		return 42;
	}
	return 0;
}
int iniciarVentana() {
	sf::Event event;
	while (ventana.isOpen()) {
		while (ventana.pollEvent(event)) {
			while (event.type == sf::Event::EventType::Closed) {
				ventana.close();
			}
			while (event.type == sf::Event::EventType::KeyPressed) {
				switch (event.key.code) {
				case sf::Keyboard::Up: bg.move(0.0, -1.0);
					break;
				case sf::Keyboard::Down: bg.move(0.0, 1.0);
					break;
				case sf::Keyboard::Right: bg.move(1.0, 0.0);
					break;
				case sf::Keyboard::Left: bg.move(-1.0, 0.0);
					break;
				default:break;
				}
			}

			ventana.clear();
			ventana.draw(bg);
			ventana.display();

		}//fin de ejecucion del ciclo de la ventana
		return 0;
	}
}

int main(int argc, char** argv) {
	cargarFondo();
	iniciarVentana();

	return 0;
}
