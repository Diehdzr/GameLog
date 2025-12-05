/*
 * Proyecto GameLog
 * Diego Hernández Rangel
 * A01710524
 * 5/12/2025
 */

/*
 * Clase Videojuego junto con sus herencias.
 * La clase padre contiene como composición a la clase reseña
 * junto con informacion como horas de juego, trofeos, etc.
 * Tiene los metodos para recibir la información de tanto
 * la clase videojuego como reseña.
 */

#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H
#include "review.h"
#include <iostream>
#include <sstream>
#include <string>

const int MAX_LISTA = 200;

// Clase padre
class Videojuego {
private:
  // Atributos
  Review review;
  std::string titulo;
  std::string productora;
  std::string genero;
  std::string trofeos[MAX_LISTA];
  int horas;
  int year;

  // Contador para saber el # actual de trofeos
  int trofeosObtenidos = 0;

public:
  // Constructor Estandar
  /**
   * constructor vacío
   *
   * @param
   * @return Videojuego
   */
  Videojuego()
      : review(), titulo(""), productora(""), genero(""), horas(0), year(0) {
    for (int i = 0; i < MAX_LISTA; i++) {
      trofeos[i] = "";
    }
  };

  // Constructor con parámetros
  /**
   * constructor con parámetros
   *
   * @param int ra: rating
   * @param string cm: comentario
   * @param string t: titulo
   * @param string pr: productora
   * @param string g: genero
   * @param int h: horas
   * @param int y: año
   * @return Videojuego
   */
  Videojuego(int ra, std::string cm, std::string t, std::string pr,
             std::string g, int h, int y)
      : review(ra, cm), titulo(t), productora(pr), genero(g), horas(h),
        year(y) {
    for (int i = 0; i < MAX_LISTA; i++) {
      trofeos[i] = "";
    }
  };

  // Declarar Getters
  Review getReview();
  std::string getTitulo();
  std::string getProductora();
  std::string getGenero();
  int getTrofeosObtenidos();
  int getHoras();
  int getYear();

  // Declarar Setters
  void setReview(Review r);
  void setTitulo(std::string t);
  void setProductora(std::string pr);
  void setGenero(std::string g);
  void setHoras(int h);
  void setYear(int y);

  // Funciones extras
  std::string mostrarTrofeos();
  void agregarTrofeo(std::string t);
  void agregarHoras(int h);
};

// Getters

/**
 * getter review
 *
 * @param
 * @return Review: review
 */
Review Videojuego::getReview() { return review; }

/**
 * getter titulo
 *
 * @param
 * @return string: titulo
 */
std::string Videojuego::getTitulo() { return titulo; }

/**
 * getter productora
 *
 * @param
 * @return string: productora
 */
std::string Videojuego::getProductora() { return productora; }

/**
 * getter genero
 *
 * @param
 * @return string: genero
 */
std::string Videojuego::getGenero() { return genero; }

/**
 * getter trofeosObtenidos
 *
 * @param
 * @return int: trofeos obtenidos
 */
int Videojuego::getTrofeosObtenidos() { return trofeosObtenidos; }

/**
 * getter horas
 *
 * @param
 * @return int: horas
 */
int Videojuego::getHoras() { return horas; }

/**
 * getter year
 *
 * @param
 * @return int: año
 */
int Videojuego::getYear() { return year; }

// Setters

/**
 * setter review
 *
 * @param Review r: nuevo review
 * @return void
 */
void Videojuego::setReview(Review r) { review = r; }

/**
 * setter titulo
 *
 * @param string t: nuevo titulo
 * @return void
 */
void Videojuego::setTitulo(std::string t) { titulo = t; }

/**
 * setter productora
 *
 * @param string pr: nueva productora
 * @return void
 */
void Videojuego::setProductora(std::string pr) { productora = pr; }

/**
 * setter genero
 *
 * @param string g: nuevo genero
 * @return void
 */
void Videojuego::setGenero(std::string g) { genero = g; }

/**
 * setter horas
 *
 * @param int h: nuevas horas
 * @return void
 */
void Videojuego::setHoras(int h) { horas = h; }

/**
 * setter year
 *
 * @param int y: nuevo año
 * @return void
 */
void Videojuego::setYear(int y) { year = y; }

// Funciones extras

/**
 * agrega un trofeo
 *
 * @param string t: trofeo nuevo
 * @return void
 */
void Videojuego::agregarTrofeo(std::string t) {
  trofeos[trofeosObtenidos] = t;
  trofeosObtenidos++;
}

/**
 * muestra trofeos
 *
 * @param
 * @return string: lista de trofeos obtenidos
 */
std::string Videojuego::mostrarTrofeos() {
  std::stringstream aux;
  for (int i = 0; i < trofeosObtenidos; i++) {
    aux << "#" << i + 1 << trofeos[i] << "\n";
  }
  return aux.str();
}

/**
 * agrega horas al total
 *
 * @param int h: horas a agregar
 * @return void
 */
void Videojuego::agregarHoras(int h) {
  if (h >= 0) {
    horas = horas + h;
  }
}

// Herencias:
//  Rpg
class Rpg : public Videojuego {
private:
  // Atributos
  std::string itemsObtenidos[MAX_LISTA];
  std::string jefesDerrotados[MAX_LISTA];
  int nivelPersonaje;
  // Contadores
  int contadorItems = 0;
  int contadorJefes = 0;

public:
  // Constructores

  /**
   * constructor vacío
   *
   * @param
   * @return Rpg
   */
  Rpg() : Videojuego(), nivelPersonaje(0) {
    for (int i = 0; i < MAX_LISTA; i++) {
      itemsObtenidos[i] = "";
    }
    for (int i = 0; i < MAX_LISTA; i++) {
      jefesDerrotados[i] = "";
    }
  };

  /**
   * constructor con parámetros
   *
   * @param int ra: rating
   * @param string cm: comentario
   * @param string t: titulo
   * @param string pr: productora
   * @param string g: genero
   * @param int h: horas
   * @param int y: año
   * @param int np: nivelPersonaje
   * @return Rpg
   */
  Rpg(int ra, std::string cm, std::string t, std::string pr, std::string g,
      int h, int y, int np)
      : Videojuego(ra, cm, t, pr, g, h, y), nivelPersonaje(np) {
    for (int i = 0; i < MAX_LISTA; i++) {
      itemsObtenidos[i] = "";
    }
    for (int i = 0; i < MAX_LISTA; i++) {
      jefesDerrotados[i] = "";
    }
  };

  // Declarar Getters
  int getNivelPersonaje();

  // Declarar Setters
  void setNivelPersonaje(int np);

  // Funciones extras
  std::string mostrarItems();
  std::string mostrarJefes();
  void agregarItems(std::string i);
  void agregarJefe(std::string j);
};

// Getters

/**
 * getter nivelPersonaje
 *
 * @param
 * @return int: nivel del personaje
 */
int Rpg::getNivelPersonaje() { return nivelPersonaje; }

// Setters

/**
 * setter nivelPersonaje
 *
 * @param int np: nuevo nivel
 * @return void
 */
void Rpg::setNivelPersonaje(int np) { nivelPersonaje = np; }

// Funciones

/**
 * muestra items obtenidos
 *
 * @param
 * @return string: lista de items
 */
std::string Rpg::mostrarItems() {
  std::stringstream aux;
  for (int i = 0; i < contadorItems; i++) {
    aux << "#" << i + 1 << "Item: " << itemsObtenidos[i] << "\n";
  }
  return aux.str();
}

/**
 * muestra jefes derrotados
 *
 * @param
 * @return string: lista de jefes derrotados
 */
std::string Rpg::mostrarJefes() {
  std::stringstream aux;
  for (int i = 0; i < contadorJefes; i++) {
    aux << "#" << i + 1 << "Jefe: " << jefesDerrotados[i] << "\n";
  }
  return aux.str();
}

/**
 * agrega un item obtenido
 *
 * @param string i: item nuevo
 * @return void
 */
void Rpg::agregarItems(std::string i) {
  itemsObtenidos[contadorItems] = i;
  contadorItems++;
}

/**
 * agrega un jefe derrotado
 *
 * @param string j: jefe nuevo
 * @return void
 */
void Rpg::agregarJefe(std::string j) {
  jefesDerrotados[contadorJefes] = j;
  contadorJefes++;
}

// Ranked
class Ranked : public Videojuego {
private:
  // Atributos
  std::string rango;
  int partidasJugadas;
  int partidasGanadas;

public:
  // constructor vacío
  Ranked() : Videojuego(), partidasJugadas(0), partidasGanadas(0){};

  /**
   * constructor con parámetros
   *
   * @param int ra: rating
   * @param string cm: comentario
   * @param string t: titulo
   * @param string pr: productora
   * @param string g: genero
   * @param int h: horas
   * @param int y: año
   * @param int pj: partidas jugadas
   * @param int pg: partidas ganadas
   * @return Ranked
   */
  Ranked(int ra, std::string cm, std::string t, std::string pr, std::string g,
         int h, int y, int pj, int pg)
      : Videojuego(ra, cm, t, pr, g, h, y), partidasJugadas(pj),
        partidasGanadas(pg){};

  // Declarar Getters
  std::string getRango();
  int getPartidasJugadas();
  int getPartidasGanadas();

  // Declarar Setters
  void setRango(std::string r);
  void setPartidasJugadas(int pj);
  void setPartidasGanadas(int pg);
};

// Getters

/**
 * getter rango
 *
 * @param
 * @return string: rango actual
 */
std::string Ranked::getRango() { return rango; }

/**
 * getter partidasJugadas
 *
 * @param
 * @return int: partidas jugadas
 */
int Ranked::getPartidasJugadas() { return partidasJugadas; }

/**
 * getter partidasGanadas
 *
 * @param
 * @return int: partidas ganadas
 */
int Ranked::getPartidasGanadas() { return partidasGanadas; }

// Setters

/**
 * setter rango
 *
 * @param string r: nuevo rango
 * @return void
 */
void Ranked::setRango(std::string r) { rango = r; }

/**
 * setter partidasJugadas
 *
 * @param int pj: nuevas partidas jugadas
 * @return void
 */
void Ranked::setPartidasJugadas(int pj) { partidasJugadas = pj; }

/**
 * setter partidasGanadas
 *
 * @param int pg: nuevas partidas ganadas
 * @return void
 */
void Ranked::setPartidasGanadas(int pg) { partidasGanadas = pg; }

// Estandar
class Estandar : public Videojuego {
public:
  // constructor vacío
  Estandar() : Videojuego() {}

  /**
   * constructor con parámetros
   *
   * @param int ra: rating
   * @param string cm: comentario
   * @param string t: titulo
   * @param string pr: productora
   * @param string g: genero
   * @param int h: horas
   * @param int y: año
   * @return Estandar
   */
  Estandar(int ra, std::string cm, std::string t, std::string pr, std::string g,
           int h, int y)
      : Videojuego(ra, cm, t, pr, g, h, y) {}
};

#endif
