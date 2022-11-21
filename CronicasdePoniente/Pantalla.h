#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Cronica.h"


using namespace std;

class Pantalla {

private:
	sf::Font* fuente1;

	sf::RenderWindow* ventana;

	sf::Texture txt_fondo;
	sf::Sprite spr_fondo;

	sf::RectangleShape* rectangulo;
	sf::RectangleShape* rectangulo_s;

	sf::Text* txt_menu;
	sf::Text* txt_b;
	sf::Text* txt_t;
	sf::Text* txt_s;

	sf::Music musica;

	bool gameover = false;

	int opz, scl, fps, contador = 0;
	string dato;

public:

	Pantalla(sf::Vector2f dimenciones, string titulo) {
		gameover = false;

		fps = 60;

		ventana = new sf::RenderWindow(sf::VideoMode(dimenciones.x, dimenciones.y), titulo);

		ventana->setFramerateLimit(fps);

		crear_figuras();
		textos();
		cargar_graficos();
		sonido();
		gameloop();
	}

	void gameloop() {
		while (!gameover) {
			ventana->clear();

			ventana->draw(spr_fondo);
			ventana->draw(*rectangulo);
			ventana->draw(*txt_menu);
			ventana->draw(*txt_b);
			ventana->draw(*txt_t);
			ventana->draw(*txt_s);

			botones();

			ventana->display();
		}
	}

	void crear_figuras() {
		rectangulo = new sf::RectangleShape(sf::Vector2f(700.f, 80.f));
		rectangulo->setFillColor(sf::Color::White);
		rectangulo->setPosition(150, 450);
	}

	void textos() {
		fuente1 = new sf::Font();
		fuente1->loadFromFile("got.ttf");

		txt_menu = new sf::Text();
		txt_menu->setFont(*fuente1);
		txt_menu->setString("INICIAR");
		txt_menu->setPosition(450, 480);
		txt_menu->setCharacterSize(24);
		txt_menu->setFillColor(sf::Color::Black);
		txt_menu->setStyle(sf::Text::Bold);

		txt_b = new sf::Text();
		txt_b->setFont(*fuente1);
		txt_b->setString("Bienvenido a");
		txt_b->setPosition(400, 150);
		txt_b->setCharacterSize(20);
		txt_b->setFillColor(sf::Color(192, 192, 192));

		txt_t = new sf::Text();
		txt_t->setFont(*fuente1);
		txt_t->setString("Cronicas de Poniente");
		txt_t->setPosition(70, 200);
		txt_t->setCharacterSize(60);
		txt_t->setFillColor(sf::Color(192, 192, 192));

		txt_s = new sf::Text();
		txt_s->setFont(*fuente1);
		txt_s->setString("un juego de Game of Thrones");
		txt_s->setPosition(250, 270);
		txt_s->setCharacterSize(25);
		txt_s->setFillColor(sf::Color(192,192,192));
	}



	void cargar_graficos() {
		string rutas;

		txt_fondo.loadFromFile("got.png");
		spr_fondo.setTexture(txt_fondo);;
		spr_fondo.setScale((float)ventana->getSize().x / txt_fondo.getSize().x, (float)ventana->getSize().y / txt_fondo.getSize().y);
	}

	void sonido() {
		musica.openFromFile("got.ogg");
		musica.setLoop(true);
		musica.play();
	}

	void botones() {
		sf::Event Event;
		while (ventana->pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
				ventana->close();
				break;
			case sf::Event::MouseMoved:
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(*ventana);
				sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
				if (rectangulo->getGlobalBounds().contains(mousePosF))
				{
					rectangulo->setFillColor(sf::Color(29,29,29));
				}
				else
				{
					rectangulo->setFillColor(sf::Color(127,127,127));
				}
			}
			break;
			case sf::Event::MouseButtonPressed:
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(*ventana);
				sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
				if (rectangulo->getGlobalBounds().contains(mousePosF))
				{
					ventana->close();
					musica.stop();
					Cronica* vent1;
					vent1 = new Cronica(960, 540, "Cronicas de poniente");
				}
			}
			break;
			}
		}
	}
};
