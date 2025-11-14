#include <string>

class videojuego{
  private:
    std::string titulo;
    std::string genero;
    std::string plataforma; //Consola, steam, etc
    std::string productora;
    int year;
  public:
  videojuego(): titulo(""), genero(""), plataforma(""), productora(""), year(0){};
  videojuego(std::string t, std::string g, std::string pl, std::string pr, int y):
    titulo(t), genero(g), plataforma(pl), productora(pr), year(y){};
  std::string getTitulo();
  std::string getGenero();
  std::string getPlataforma();
  std::string getProductora();
  int getYear();

  void setTitulo(std::string t);
  void setGenero(std::string g);
  void setPlataforma(std::string pl);
  void setProductora(std::string pr);
  void setYear(int y);
};

std::string videojuego::getTitulo() {
    return titulo;
}

std::string videojuego::getGenero() {
    return genero;
}

std::string videojuego::getPlataforma() {
    return plataforma;
}

std::string videojuego::getProductora() {
    return productora;
}

int videojuego::getYear() {
    return year;
}

void videojuego::setTitulo(std::string t) {
    titulo = t;
}

void videojuego::setGenero(std::string g) {
    genero = g;
}

void videojuego::setPlataforma(std::string pl) {
    plataforma = pl;
}

void videojuego::setProductora(std::string pr) {
    productora = pr;
}

void videojuego::setYear(int y) {
    year = y;
}
