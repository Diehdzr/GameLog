#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H
#include <string>
#include <sstream>
#include <iostream>
#include "review.h"

//Clase padre
class Videojuego{
  private:
    //Atributos
    Review review;
    std::string titulo;
    std::string productora;
    std::string genero;
    std::string trofeos[500];
    int horas;
    int year;

    //Contador para saber el # actual de trofeos
    int trofeosObtenidos = 0;
  public:
  //Constructor Estandar
  Videojuego(): review(), titulo(""), productora(""), genero(""), horas(0), year(0){
      for (int i = 0; i < 500; i++) {
          trofeos[i] = "";
      }
  };
  //Constructor
  Videojuego(std::string t, std::string pr, std::string g, int h, int y):
    review(), titulo(t), productora(pr), genero(g), horas(h), year(y){
        for (int i = 0; i < 500; i++) {
            trofeos[i] = "";
        }
    };

  //Declarar Getters
  Review getReview();
  std::string getTitulo();
  std::string getProductora();
  std::string getGenero();
  int getTrofeosObtenidos();
  int getHoras();
  int getYear();

  //Declarar Setters
  void setReview(Review r);
  void setTitulo(std::string t);
  void setProductora(std::string pr);
  void setGenero(std::string g);
  void setHoras(int h);
  void setYear(int y);

  //Funciones extras
  std::string mostrarTrofeos();
  void agregarTrofeo(std::string t);
  void agregarHoras(int h);
};

//Getters
Review Videojuego::getReview() {
        return review;
    }
std::string Videojuego::getTitulo() {
    return titulo;
}
std::string Videojuego::getProductora() {
    return productora;
}
std::string Videojuego::getGenero() {
    return genero;
}
int Videojuego::getTrofeosObtenidos() {
    return trofeosObtenidos;
}
int Videojuego::getHoras() {
    return horas;
}
int Videojuego::getYear() {
    return year;
}

//Setters
void Videojuego::setReview(Review r) {
        review = r;
    }
void Videojuego::setTitulo(std::string t) {
    titulo = t;
}
void Videojuego::setProductora(std::string pr) {
    productora = pr;
}
void Videojuego::setGenero(std::string g) {
    genero = g;
}
void Videojuego::setHoras(int h) {
    horas = h;
}
void Videojuego::setYear(int y) {
    year = y;
}

//Funciones extras
void Videojuego::agregarTrofeo(std::string t){
    trofeos[trofeosObtenidos] = t;
    trofeosObtenidos ++;
}
std::string Videojuego::mostrarTrofeos(){
    std::stringstream aux;
    for (int i = 0; i < trofeosObtenidos; i++) {
        aux << trofeos[i] << "\n";
    }
    return aux.str();
}
void Videojuego::agregarHoras(int h){
    if (h >= 0) {
        horas = horas + h;
    }
}


//Herencias:
// Rpg
class Rpg : public Videojuego{
  private:
  //Atributos
  std::string itemsObtenidos[500];
  std::string jefesDerrotados[500];
  int nivelPersonaje;
  //Contadores
  int contadorItems = 0;
  int contadorJefes = 0;

  public:
  //Constructores
  Rpg() : Videojuego(), nivelPersonaje(0){
      for (int i = 0; i < 500; i++) {
          itemsObtenidos[i] = "";
      }
      for (int i = 0; i < 500; i++) {
          jefesDerrotados[i] = "";
      }
  };
  Rpg(std::string t, std::string pr, std::string g, int h, int y, int np):
  Videojuego(t, pr, g, h, y), nivelPersonaje(np){
      for (int i = 0; i < 500; i++) {
          itemsObtenidos[i] = "";
      }
      for (int i = 0; i < 500; i++) {
          jefesDerrotados[i] = "";
      }
  };

  //Declarar Getters
  int getNivelPersonaje();

  //Declarar Setters
  void setNivelPersonaje(int np);

  //Funciones extras
  void agregarItems(std::string i);
  void agregarJefe(std::string j);
  void aumentarNivel(int n);
};

//Getters
int Rpg::getNivelPersonaje(){
    return nivelPersonaje;
}

//Setters
void Rpg::setNivelPersonaje(int np){
    nivelPersonaje = np;
}

//Funciones
void Rpg::agregarItems(std::string i){
    itemsObtenidos[contadorItems] = i;
    contadorItems ++;
}
void Rpg::agregarJefe(std::string j){
    jefesDerrotados[contadorJefes] = j;
    contadorJefes ++;
}
void Rpg::aumentarNivel(int n){
    nivelPersonaje = nivelPersonaje + n;
}

//Ranked
class Ranked : public Videojuego {
  private:
  //Atributos
  std::string rango;
  int partidasJugadas;
  int partidasGanadas;

  public:
  //Constructores
  Ranked() : Videojuego(), partidasJugadas(0), partidasGanadas(0){};
  Ranked(std::string t, std::string pr, std::string g, int h, int y, int pj, int pg):
  Videojuego(t, pr, g, h, y), partidasJugadas(pj), partidasGanadas(pg){};

  //Declarar Getters
  std::string getRango();
  int getPartidasJugadas();
  int getPartidasGanadas();

  //Declarar Setters
  void setRango(std::string r);
  void setPartidasJugadas(int pj);
  void setPartidasGanadas(int pg);
};

//Getters
std::string Ranked::getRango(){
    return rango;
}
int Ranked::getPartidasJugadas(){
    return partidasJugadas;
}
int Ranked::getPartidasGanadas(){
    return partidasGanadas;
}

//Setters
void Ranked::setRango(std::string r){
    rango = r;
}
void Ranked::setPartidasJugadas(int pj){
    partidasJugadas = pj;
}
void Ranked::setPartidasGanadas(int pg){
    partidasGanadas = pg;
}

//Estandar
class Estandar : public Videojuego {
public:
    // Constructor vacio
    Estandar() : Videojuego() {}

    // Constructor
    Estandar(std::string t, std::string pr, std::string g, int h, int y)
        : Videojuego(t, pr, g, h, y) {}
};

#endif
