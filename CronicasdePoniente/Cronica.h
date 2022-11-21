#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Nodo.h"
#include <iostream>

using namespace std;

class Cronica{
	public:

		sf::Texture txt_img;
		sf::Sprite spr_img;
		sf::Music cancion;
		sf::Event event;

		Nodo* Inicio = new Nodo("Inicio");
		Nodo* Historia = new Nodo("Historia");
		Nodo* Tomar_venganza = new Nodo("Tomar_venganza");
		Nodo* Hacer_caso_a_tu_padre = new Nodo("Hacer_caso_a_tu_padre");
		Nodo* Perdonar_su_deuda = new Nodo("Perdonar_su_deuda");
		Nodo* Marchar_contra_tus_enemigos = new Nodo("Marchar_contra_tus_enemigos");
		Nodo* Marchar_a_casa = new Nodo("Marchar_a_casa");
		Nodo* Pelear = new Nodo("Pelear");
		Nodo* Marchar_a_tarbeck = new Nodo("Marchar_a_tarbeck");
		Nodo* Marchar_a_castamere = new Nodo("Marchar_a_castamere");
		Nodo* Entrar_en_batalla = new Nodo("Entrar_en_batalla");
		Nodo* Quemar = new Nodo("Quemar");
		Nodo* Regresar = new Nodo("Regresar");
		Nodo* Seguir_en_la_guerra = new Nodo("Seguir_en_la_guerra");
		Nodo* No_dejar_testigos = new Nodo("No_dejar_testigos");
		Nodo* Mandar_mensajero = new Nodo("Mandar_mensajero");
		Nodo* Verdad = new Nodo("Verdad");
		Nodo* Mentira = new Nodo("Mentira");
		Nodo* Violencia = new Nodo("Violencia");
		Nodo* Estrategia = new Nodo("Estrategia");
		Nodo* Fin = new Nodo("Fin");

		sf::RenderWindow* ventana2;
		int fps;

	public:

		Cronica(int width, int height, string titulo) {
			Secuencia();
			fps = 60;
			ventana2 = new sf::RenderWindow(sf::VideoMode(width, height), titulo);
			ventana2->setFramerateLimit(fps);

			Inicio_C();
		}

		void Secuencia() {
			Inicio->Setimagen("img1");
			Historia->Setimagen("img2");

			Tomar_venganza->Setimagen("img4");
			Hacer_caso_a_tu_padre->Setimagen("img3");

			Perdonar_su_deuda->Setimagen("img5");
			Marchar_contra_tus_enemigos->Setimagen("img6");

			Marchar_a_casa->Setimagen("img8");
			Pelear->Setimagen("img7");

			Marchar_a_tarbeck->Setimagen("img10");
			Marchar_a_castamere->Setimagen("img9");

			Entrar_en_batalla->Setimagen("img11");
			Quemar->Setimagen("img12");

			Regresar->Setimagen("img13");
			Seguir_en_la_guerra->Setimagen("img14");

			No_dejar_testigos->Setimagen("img15");
			Mandar_mensajero->Setimagen("img16");

			Verdad->Setimagen("img17");
			Mentira->Setimagen("img18");

			Violencia->Setimagen("img19");
			Estrategia->Setimagen("img20");

			Fin->Setimagen("img21");

			Historia->matriz = { Tomar_venganza,Hacer_caso_a_tu_padre };
			Hacer_caso_a_tu_padre->matriz = { Fin,Fin };
			Tomar_venganza->matriz = { Marchar_contra_tus_enemigos, Perdonar_su_deuda };
			Perdonar_su_deuda->matriz = { Fin,Fin };
			Marchar_contra_tus_enemigos->matriz = { Marchar_a_casa, Pelear };
			Pelear->matriz = { Fin,Fin };
			Marchar_a_casa->matriz = { Marchar_a_tarbeck ,Marchar_a_castamere };
			Marchar_a_castamere->matriz = { Fin,Fin };
			Marchar_a_tarbeck->matriz = { Quemar,Entrar_en_batalla };
			Entrar_en_batalla->matriz = { Fin,Fin };
			Quemar->matriz = { Seguir_en_la_guerra, Regresar };
			Regresar->matriz = { Fin,Fin };
			Seguir_en_la_guerra->matriz = { Mandar_mensajero,No_dejar_testigos };
			No_dejar_testigos->matriz = { Fin,Fin };
			Mandar_mensajero->matriz = { Mentira, Verdad };
			Verdad->matriz = { Fin,Fin };
			Mentira->matriz = { Violencia,Estrategia };
			Violencia->matriz = { Fin,Fin };
			Estrategia->matriz = { Fin,Fin };
			Fin->matriz = {};
		}


		void Inicio_C() {
			

			txt_img.loadFromFile("img/img1.png");
			spr_img.setTexture(txt_img);

			while (ventana2->isOpen()) {

				cancion.play();
				while (ventana2->pollEvent(event)) {
					if (event.type == sf::Event::Closed) 
					{
						ventana2->close();
					}
				}
				ventana2->clear();
				ventana2->draw(spr_img);
				ventana2->display();
				sonido();
				cout << "\n\n" << "\t" << "INTRODUCCION" << endl;
				cout << "Apartir de aqui inicia la historia, sea precavido con sus elecciones, pues un error podria costarle su cabeza." << endl;
				cout << "\nGracias por jugar." << endl;
				system("pause");
				system("cls");
				Imagenes();
			}
		}

		void Imagenes() {

			sf::Texture txt_21;
			sf::Sprite spr_21;
			sf::Music cancion;

			unsigned int op;
			string election;
			

			txt_21.loadFromFile("img/img21.png");
			spr_21.setTexture(txt_21);

			Nodo* nI = new Nodo("aux");
			Nodo* nA = new Nodo("aux");
			nA = Historia;
			nI = Historia;

			while (!nA->matriz.empty()) {

				cancion.openFromFile(nA->GetCancion());
				cancion.setLoop(true);
				cancion.play();

				ventana2->clear();
				ventana2->draw(nA->Getimagen());
				ventana2->display();

				system("cls");
				cout << "Que decision tomara el Joven leon?" << endl;

				for (auto x : nA->matriz) {
					if (x->GetNombre() == "Fin") {
						system("cls");
						cout << "\nEs el fin para los Lannister?" << endl;
						cout << "*) Fin" << endl;
					}
					else {
						cout << "\n*)" << x->GetNombre() << endl;
					}
				}

				cout << endl;
				cout << "Opcion:";
				cin >> election;

				for_each(nA->matriz.begin(), nA->matriz.end(), [&nA, election](Nodo* siguiente) {
					if (siguiente->GetNombre() == election) nA = siguiente;
					});

				ventana2->clear(); 
			}

			system("cls");
			cout << "Regresar a la cronica" << endl;
			cout << "1) Si" << endl;
			cout << "2) No" << endl;
			cout << "OPcion: ";
			cin >> op;
			cancion.stop();

			if (op == 1) {
				nA = nI;
			}
			else {
				ventana2->clear();
				ventana2->draw(spr_21);
				ventana2->display();

				cancion.openFromFile("canciones/fi.ogg");
				cancion.setLoop(true);
				cancion.play();

				system("cls");
				cout << "Gracias, vuelve pronto a los 7 reinos" << endl;
				system("pause");

				cancion.stop();
				ventana2->close();
			}
		}

		
		void sonido() {
			cancion.openFromFile("cancion.ogg");
			cancion.setLoop(true);
			cancion.play();
		}
};