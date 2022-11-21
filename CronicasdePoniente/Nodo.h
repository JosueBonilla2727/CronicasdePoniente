#pragma once
#include <string>
#include <list>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace std;

class Nodo {
	private:

		string nombre;
		sf::Texture txt_img;
		sf::Sprite spr_img;
		string img;
		string cancion;

	public:
		list<Nodo*> matriz;

		Nodo(string n) {
			this->nombre = n;
		}

		void Setimagen(string img) {
			txt_img.loadFromFile("img/" + img + ".PNG");
			spr_img.setTexture(txt_img);
		}

		sf::Sprite Getimagen() {
			return spr_img;
		}

		string GetNombre() {
			return nombre;
		}

		string GetCancion() {
			return cancion;
		}

		void SetCancion(string cancion) {
			this->cancion =  cancion + ".ogg";
		}
};
