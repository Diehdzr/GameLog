/*
 * Proyecto GameLog
 * Diego Hernández Rangel
 * A01710524
 * 5/12/2025
 */

/**
 * Descripcion: este es un proyecto demo para la clase de Pensamiento
 * Computacional Orientado a Objetos. El programa guarda los videojuegos que haz
 * jugado junto con una reseña. El videojuego tiene información de su cración
 * y de tus horas de juegos, logros, etc. Asimismo cada videojuego tiene una
 * reseña con un rating de 1 a 10 y un comentario.
 */

// Bibliotecas
#include "review.h"
#include "videojuego.h"
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

// Constante para el limite de strings por lista
const int MAX_JUEGOS = 500;

// Funciones auxiliares

// Procedimiento menu
void menu() {
  // Imprime las opciones que va a tener el sistema
  std::cout << "Bienvenido!"
            << "\n¿Qué deseas hacer?" << std::endl;
  std::cout << "1. Ver Mis Videojuegos" << std::endl;
  std::cout << "2. Agregar Videojuego" << std::endl;
  std::cout << "3. Cambiar Reseña Videojuego" << std::endl;
  std::cout << "4. Cambiar Datos Videojuegos" << std::endl;
  std::cout << "5. Salir" << std::endl;
}

/*
 * Tres funciones que guardan como string una lista de todos los videojuegos
 * guardados de su respectiva clase
 */
std::string imprimirVideojuegosRpg(Rpg arg[], std::string genero, int tam) {
  std::stringstream aux;
  aux << "Tienes " << tam << " juegos del tipo " << genero << ":" << std::endl;
  for (int i = 0; i < tam; i++) {
    aux << "#" << i + 1 << ". " << arg[i].getTitulo() << std::endl;
  }
  return aux.str();
}
std::string imprimirVideojuegosRanked(Ranked arg[], std::string genero,
                                      int tam) {
  std::stringstream aux;
  aux << "Tienes " << tam << " juegos del tipo " << genero << ":" << std::endl;
  for (int i = 0; i < tam; i++) {
    aux << "#" << i + 1 << ". " << arg[i].getTitulo() << std::endl;
  }
  return aux.str();
}
std::string imprimirVideojuegosEstandar(Estandar arg[], std::string genero,
                                        int tam) {
  std::stringstream aux;
  aux << "Tienes " << tam << " juegos del tipo " << genero << ":" << std::endl;
  for (int i = 0; i < tam; i++) {
    aux << "#" << i + 1 << ". " << arg[i].getTitulo() << std::endl;
  }
  return aux.str();
}

/*
 * Tres funciones que guardan como string los atributos de cada videojuego
 * dependiendo de su clase. Usamos referencia para no hacer una copia ya que
 * solo se saca información del objeto
 */
std::string mostrarDetallesRpg(Rpg &rp) {
  std::stringstream aux;
  aux << "Título: " << rp.getTitulo() << std::endl;
  aux << "Productora: " << rp.getProductora() << std::endl;
  aux << "Género: " << rp.getGenero() << std::endl;
  aux << "Año: " << rp.getYear() << std::endl;
  aux << "Horas jugadas: " << rp.getHoras() << std::endl;

  aux << "Nivel del personaje: " << rp.getNivelPersonaje() << std::endl;
  aux << "Items:\n" << rp.mostrarItems();
  aux << "Jefes derrotados:\n" << rp.mostrarJefes();
  aux << "Trofeos:\n" << rp.mostrarTrofeos();

  aux << "Review: " << rp.getReview().getRating()
      << "/10: " << rp.getReview().getComentario() << std::endl
      << std::endl;

  return aux.str();
}
std::string mostrarDetallesRanked(Ranked &r) {
  std::stringstream aux;
  aux << "Título: " << r.getTitulo() << std::endl;
  aux << "Productora: " << r.getProductora() << std::endl;
  aux << "Género: " << r.getGenero() << std::endl;
  aux << "Año: " << r.getYear() << std::endl;
  aux << "Horas jugadas: " << r.getHoras() << std::endl;

  aux << "Partidas jugadas: " << r.getPartidasJugadas() << std::endl;
  aux << "Partidas ganadas: " << r.getPartidasGanadas() << std::endl;
  aux << "Trofeos:\n" << r.mostrarTrofeos();

  aux << "Review: " << r.getReview().getRating()
      << "/10: " << r.getReview().getComentario() << std::endl
      << std::endl;

  return aux.str();
}
std::string mostrarDetallesEstandar(Estandar &e) {
  std::stringstream aux;
  aux << "Título: " << e.getTitulo() << std::endl;
  aux << "Productora: " << e.getProductora() << std::endl;
  aux << "Género: " << e.getGenero() << std::endl;
  aux << "Año: " << e.getYear() << std::endl;
  aux << "Horas jugadas: " << e.getHoras() << std::endl;
  aux << "Trofeos:\n" << e.mostrarTrofeos();
  aux << "Review: " << e.getReview().getRating()
      << "/10: " << e.getReview().getComentario() << std::endl
      << std::endl;

  return aux.str();
}

int main() {

  // Variables y arreglos
  static Rpg rpgs[MAX_JUEGOS];
  static Ranked rankeds[MAX_JUEGOS];
  static Estandar estandars[MAX_JUEGOS];

  // Numero total de videojuegos por clase
  int totalRpgs = 0;
  int totalRankeds = 0;
  int totalEstandars = 0;

  int opcion = 1;

  // Ciclo para que el sistema siga corriendo mientras no elija cualquier otra
  // opción
  while (opcion > 0 && opcion < 5) {
    // Impresion de menu
    menu();
    // Leer indice que selecciona la opcion del menu
    std::cin >> opcion;

    // Switch que genera una accion dependiendo de la eleccion del usuario
    switch (opcion) {

    /*
     * Caso 1. Se imprime todos los juegos que hay divididos por su tipo de
     * clase Luego se da la opcion de ver mas detalles dependiendo del tipo del
     * videojuego
     */
    case 1: {
      std::cout << imprimirVideojuegosRpg(rpgs, "RPG", totalRpgs);
      std::cout << imprimirVideojuegosRanked(rankeds, "Competitivo",
                                             totalRankeds);
      std::cout << imprimirVideojuegosEstandar(estandars, "Otros",
                                               totalEstandars);

      int opcionDetalle;
      std::cout
          << "¿Quieres ver los detalles de algún videojuego? (1 = Si, 2 = No)"
          << std::endl;
      std::cin >> opcionDetalle;

      if (opcionDetalle == 1) {
        // Preguntar la clase del juego
        std::cout << "¿Qué tipo quieres ver?" << std::endl;
        std::cout << "1. RPG" << std::endl;
        std::cout << "2. Competitivo" << std::endl;
        std::cout << "3. Otros" << std::endl;

        int tipo;
        std::cin >> tipo;

        int index;

        // Si el juego es RPG
        if (tipo == 1) {
          // Se verifica que haya algun juego que se pueda mostrar
          if (totalRpgs == 0) {
            std::cout << "No tienes RPGs registrados." << std::endl;
          } else {
            std::cout << imprimirVideojuegosRpg(rpgs, "RPG", totalRpgs);
            std::cout << "Selecciona índice: ";
            std::cin >> index;
            index--;

            if (index < 0 || index >= totalRpgs) {
              std::cout << "Índice inválido." << std::endl;
            } else {
              std::cout << mostrarDetallesRpg(rpgs[index]);
            }
          }
        } else if (tipo == 2) {
          if (totalRankeds == 0) {
            std::cout << "No tienes Competitivos registrados." << std::endl;
          } else {
            std::cout << imprimirVideojuegosRanked(rankeds, "Competitivo",
                                                   totalRankeds);
            std::cout << "Selecciona índice: ";
            std::cin >> index;
            index--;

            if (index < 0 || index >= totalRankeds) {
              std::cout << "Índice inválido." << std::endl;
            } else {
              std::cout << mostrarDetallesRanked(rankeds[index]);
            }
          }
        } else if (tipo == 3) {
          if (totalEstandars == 0) {
            std::cout << "No tienes videojuegos estándar." << std::endl;
          } else {
            std::cout << imprimirVideojuegosEstandar(estandars, "Otros",
                                                     totalEstandars);
            std::cout << "Selecciona índice: ";
            std::cin >> index;
            index--;

            if (index < 0 || index >= totalEstandars) {
              std::cout << "Índice inválido." << std::endl;
            } else {
              std::cout << mostrarDetallesEstandar(estandars[index]);
            }
          }
        } else {
          std::cout << "Tipo inválido." << std::endl;
        }
      }
      break;
    }

      /*
       * Caso 2. Agregar un nuevo juego. Primero se le pide la clase
       * Luego se le pide primero la información que toda clase debe tener
       * Y al final especificaciones por clase
       */
    case 2: {
      std::string titulo, productora, genero, comentario;
      int opcionGenero, horas, year, nivelPersonaje, cantidadTrofeos, rating;

      std::cout << "¿Qué género es el videojuego?" << std::endl;
      std::cout << "(1) RPG, (2) Competitivo, (3) Otro" << std::endl;
      std::cin >> opcionGenero;

      // Verificar que sea una opción válida
      if (opcionGenero < 1 || opcionGenero > 3) {
        std::cout << "Opción inválida." << std::endl;
      } else {

        // Datos para todo tipo de juego
        std::cout << "Ingrese el título:" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, titulo);

        std::cout << "Ingrese la productora:" << std::endl;
        std::getline(std::cin, productora);

        std::cout << "Ingrese el año:" << std::endl;
        std::cin >> year;

        std::cout << "Ingrese horas jugadas:" << std::endl;
        std::cin >> horas;

        std::cout << "¿Cuántos trofeos tienes?" << std::endl;
        std::cin >> cantidadTrofeos;

        std::cout
            << "Antes de ingresar más información. Vamos a escribir tu reseña!"
            << std::endl;
        std::cout << "Ingresa rating (0-10): " << std::endl;
        std::cin >> rating;

        std::cout << "Ingresa comentario:" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, comentario);

        std::cout << "Reseña guardada!" << std::endl;

        // RPG
        if (opcionGenero == 1) {
          genero = "RPG";

          std::cout << "Nivel del personaje:" << std::endl;
          std::cin >> nivelPersonaje;

          rpgs[totalRpgs] = Rpg(rating, comentario, titulo, productora, genero,
                                horas, year, nivelPersonaje);

          int totalItems, totalJefes;
          std::cout << "¿Cuántos items tienes?" << std::endl;
          std::cin >> totalItems;
          std::cin.ignore();

          for (int i = 0; i < totalItems; i++) {
            std::string item;
            std::cout << "Item #" << i + 1 << ": ";
            getline(std::cin, item);
            rpgs[totalRpgs].agregarItems(item);
          }

          std::cout << "¿Cuántos jefes derrotaste?" << std::endl;
          std::cin >> totalJefes;
          std::cin.ignore();

          for (int i = 0; i < totalJefes; i++) {
            std::string jefe;
            std::cout << "Jefe #" << i + 1 << ": ";
            getline(std::cin, jefe);
            rpgs[totalRpgs].agregarJefe(jefe);
          }

          for (int i = 0; i < cantidadTrofeos; i++) {
            std::string trofeo;
            std::cout << "Trofeo #" << i + 1 << ": ";
            std::getline(std::cin, trofeo);
            rpgs[totalRpgs].agregarTrofeo(trofeo);
          }

          totalRpgs++;

        }
        // Ranked
        else if (opcionGenero == 2) {

          genero = "Competitivo";
          int partidasJugadas, partidasGanadas;

          std::cout << "Partidas jugadas:" << std::endl;
          std::cin >> partidasJugadas;

          std::cout << "Partidas ganadas:" << std::endl;
          std::cin >> partidasGanadas;

          rankeds[totalRankeds] =
              Ranked(rating, comentario, titulo, productora, genero, horas,
                     year, partidasJugadas, partidasGanadas);

          std::cin.ignore();
          for (int i = 0; i < cantidadTrofeos; i++) {
            std::string trofeo;
            std::cout << "Trofeo #" << i + 1 << ": ";
            std::getline(std::cin, trofeo);
            rankeds[totalRankeds].agregarTrofeo(trofeo);
          }

          totalRankeds++;

        }
        // Otro
        else {

          std::cout << "Escribe el género:" << std::endl;
          std::getline(std::cin, genero);

          estandars[totalEstandars] = Estandar(rating, comentario, titulo,
                                               productora, genero, horas, year);

          for (int i = 0; i < cantidadTrofeos; i++) {
            std::string trofeo;
            std::cout << "Trofeo #" << i + 1 << ": ";
            std::getline(std::cin, trofeo);
            estandars[totalEstandars].agregarTrofeo(trofeo);
          }

          totalEstandars++;
        }
      }

      break;
    }

      /*
       * Caso 3. Editar la reseña de una videjouego.
       * En cada caso el procedimiento es el mismo, se verificia que haya aunque
       * sea un videojuego de esa clase, se muestran todas las opciones de esa
       * clase, se le pide al usuario que escoja el juego que quiera cambiar,
       * luego se pide la nueva reseña y finalmente se hace
       * el cambio
       */
    case 3: {
      std::cout << "¿De qué tipo es el videojuego que deseas editar la reseña?"
                << std::endl;
      std::cout << "1. RPG" << std::endl;
      std::cout << "2. Competitivo" << std::endl;
      std::cout << "3. Estándar" << std::endl;

      int tipo;
      std::cin >> tipo;

      int index;

      // RPG
      if (tipo == 1) {
        // Verificar si tiene algun juego
        if (totalRpgs == 0) {
          std::cout << "No tienes RPGs." << std::endl;
        } else {

          std::cout << imprimirVideojuegosRpg(rpgs, "RPG", totalRpgs);
          std::cout << "Selecciona índice: ";
          std::cin >> index;
          index--;

          if (index < 0 || index >= totalRpgs) {
            std::cout << "Índice inválido." << std::endl;
          } else {

            int rating;
            std::string comentario;

            std::cout << "Nuevo rating (0–10): ";
            std::cin >> rating;

            while (rating < 0 || rating > 10) {
              std::cout << "Rating inválido. ";
              std::cin >> rating;
            }

            std::cout << "Nuevo comentario: ";
            std::cin.ignore();
            std::getline(std::cin, comentario);

            rpgs[index].getReview().setRating(rating);
            rpgs[index].getReview().setComentario(comentario);

            std::cout << "Reseña actualizada." << std::endl;
          }
        }
      }

      // Ranked
      else if (tipo == 2) {
        if (totalRankeds == 0) {
          std::cout << "No tienes juegos competitivos." << std::endl;
        } else {

          std::cout << imprimirVideojuegosRanked(rankeds, "Competitivo",
                                                 totalRankeds);
          std::cout << "Selecciona índice: ";
          std::cin >> index;
          index--;

          if (index < 0 || index >= totalRankeds) {
            std::cout << "Índice inválido." << std::endl;
          } else {

            int rating;
            std::string comentario;

            std::cout << "Nuevo rating (0–10): ";
            std::cin >> rating;

            while (rating < 0 || rating > 10) {
              std::cout << "Rating inválido. ";
              std::cin >> rating;
            }

            std::cout << "Nuevo comentario: ";
            std::cin.ignore();
            std::getline(std::cin, comentario);

            rankeds[index].getReview().setRating(rating);
            rankeds[index].getReview().setComentario(comentario);

            std::cout << "Reseña actualizada." << std::endl;
          }
        }
      }

      // Otro
      else if (tipo == 3) {
        if (totalEstandars == 0) {
          std::cout << "No tienes videojuegos estándar." << std::endl;
        } else {

          std::cout << imprimirVideojuegosEstandar(estandars, "Otros",
                                                   totalEstandars);
          std::cout << "Selecciona índice: ";
          std::cin >> index;
          index--;

          if (index < 0 || index >= totalEstandars) {
            std::cout << "Índice inválido." << std::endl;
          } else {

            int rating;
            std::string comentario;

            std::cout << "Nuevo rating (0–10): ";
            std::cin >> rating;

            while (rating < 0 || rating > 10) {
              std::cout << "Rating inválido. ";
              std::cin >> rating;
            }

            std::cout << "Nuevo comentario: ";
            std::cin.ignore();
            std::getline(std::cin, comentario);

            estandars[index].getReview().setRating(rating);
            estandars[index].getReview().setComentario(comentario);

            std::cout << "Reseña actualizada." << std::endl;
          }
        }
      }

      else {
        std::cout << "Tipo inválido." << std::endl;
      }

      break;
    }

      /*
       * Caso 4. Si el usuario quiere cambiar datos del juego.
       * Igual se tiene que escoger la clase, luego se imprime la lista
       * completa de los juegos de la clase
       */
    case 4: {

      std::cout << "¿De qué tipo es el videojuego que deseas editar?"
                << std::endl;
      std::cout << "1. RPG" << std::endl;
      std::cout << "2. Competitivo" << std::endl;
      std::cout << "3. Estándar" << std::endl;

      // Se escoge el tipo de videojuego
      int tipo;
      std::cin >> tipo;
      int index;

      /*
       * En cada caso el procedimiento es el mismo, se verificia que haya aunque
       * sea un videojuego de esa clase, se muestran todas las opciones de esa
       * clase, se le pide al usuario que escoja el juego que quiera cambiar,
       * luego se escoge especificamente que quiere cambiar y finalmente se hace
       * el cambio
       */

      // RPG
      if (tipo == 1) {

        if (totalRpgs == 0) {
          std::cout << "No tienes RPGs." << std::endl;
        } else {

          std::cout << imprimirVideojuegosRpg(rpgs, "RPG", totalRpgs);
          std::cout << "Selecciona índice: ";
          std::cin >> index;
          index--;

          if (index < 0 || index >= totalRpgs) {
            std::cout << "Índice inválido." << std::endl;
          } else {

            int opcionCambio;
            std::cout << "¿Qué deseas modificar?" << std::endl;
            std::cout << "1. Título" << std::endl;
            std::cout << "2. Productora" << std::endl;
            std::cout << "3. Horas" << std::endl;
            std::cout << "4. Año" << std::endl;
            std::cout << "5. Nivel del personaje" << std::endl;
            std::cout << "6. Agregar Item" << std::endl;
            std::cout << "7. Agregar Jefe" << std::endl;
            std::cout << "8. Agregar Trofeo" << std::endl;
            std::cin >> opcionCambio;

            std::cin.ignore();

            if (opcionCambio == 1) {
              std::string t;
              std::cout << "Nuevo título: ";
              getline(std::cin, t);
              rpgs[index].setTitulo(t);

            } else if (opcionCambio == 2) {
              std::string p;
              std::cout << "Nueva productora: ";
              getline(std::cin, p);
              rpgs[index].setProductora(p);

            } else if (opcionCambio == 3) {
              int h;
              std::cout << "¿Cuántas horas quieres agregar?: ";
              std::cin >> h;
              rpgs[index].agregarHoras(h);

            } else if (opcionCambio == 4) {
              int y;
              std::cout << "Nuevo año: ";
              std::cin >> y;
              rpgs[index].setYear(y);

            } else if (opcionCambio == 5) {
              int np;
              std::cout << "Nuevo nivel: ";
              std::cin >> np;
              rpgs[index].setNivelPersonaje(np);

            } else if (opcionCambio == 6) {
              std::string item;
              std::cout << "Item a agregar: ";
              getline(std::cin, item);
              rpgs[index].agregarItems(item);

            } else if (opcionCambio == 7) {
              std::string jefe;
              std::cout << "Jefe a agregar: ";
              getline(std::cin, jefe);
              rpgs[index].agregarJefe(jefe);

            } else if (opcionCambio == 8) {
              std::string trofeo;
              std::cout << "Trofeo a agregar: ";
              getline(std::cin, trofeo);
              rpgs[index].agregarTrofeo(trofeo);

            } else {
              std::cout << "Opción inválida." << std::endl;
            }

            std::cout << "Datos actualizados." << std::endl;
          }
        }
      }

      // Ranked
      else if (tipo == 2) {

        if (totalRankeds == 0) {
          std::cout << "No tienes competitivos." << std::endl;
        } else {

          std::cout << imprimirVideojuegosRanked(rankeds, "Competitivo",
                                                 totalRankeds);
          std::cout << "Selecciona índice: ";
          std::cin >> index;
          index--;

          if (index < 0 || index >= totalRankeds) {
            std::cout << "Índice inválido." << std::endl;
          } else {

            int opcionCambio;
            std::cout << "¿Qué deseas modificar?" << std::endl;
            std::cout << "1. Título" << std::endl;
            std::cout << "2. Productora" << std::endl;
            std::cout << "3. Horas" << std::endl;
            std::cout << "4. Año" << std::endl;
            std::cout << "5. Partidas jugadas" << std::endl;
            std::cout << "6. Partidas ganadas" << std::endl;
            std::cout << "7. Agregar Trofeo" << std::endl;
            std::cin >> opcionCambio;

            std::cin.ignore();

            if (opcionCambio == 1) {
              std::string t;
              std::cout << "Nuevo título: ";
              getline(std::cin, t);
              rankeds[index].setTitulo(t);

            } else if (opcionCambio == 2) {
              std::string p;
              std::cout << "Nueva productora: ";
              getline(std::cin, p);
              rankeds[index].setProductora(p);

            } else if (opcionCambio == 3) {
              int h;
              std::cout << "¿Cuántas horas quieres agregar?: ";
              std::cin >> h;
              rankeds[index].agregarHoras(h);

            } else if (opcionCambio == 4) {
              int y;
              std::cout << "Nuevo año: ";
              std::cin >> y;
              rankeds[index].setYear(y);

            } else if (opcionCambio == 5) {
              int pj;
              std::cout << "Nuevo total partidas jugadas: ";
              std::cin >> pj;
              rankeds[index].setPartidasJugadas(pj);

            } else if (opcionCambio == 6) {
              int pg;
              std::cout << "Nuevo total partidas ganadas: ";
              std::cin >> pg;
              rankeds[index].setPartidasGanadas(pg);

            } else if (opcionCambio == 7) {
              std::string trofeo;
              std::cout << "Trofeo a agregar: ";
              getline(std::cin, trofeo);
              rankeds[index].agregarTrofeo(trofeo);

            } else {
              std::cout << "Opción inválida." << std::endl;
            }

            std::cout << "Datos actualizados." << std::endl;
          }
        }
      }

      // Estándar
      else if (tipo == 3) {

        if (totalEstandars == 0) {
          std::cout << "No tienes estándar." << std::endl;
        } else {

          std::cout << imprimirVideojuegosEstandar(estandars, "Otros",
                                                   totalEstandars);
          std::cout << "Selecciona índice: ";
          std::cin >> index;
          index--;

          if (index < 0 || index >= totalEstandars) {
            std::cout << "Índice inválido." << std::endl;
          } else {

            int opcionCambio;
            std::cout << "¿Qué deseas modificar?" << std::endl;
            std::cout << "1. Título" << std::endl;
            std::cout << "2. Productora" << std::endl;
            std::cout << "3. Género" << std::endl;
            std::cout << "4. Horas" << std::endl;
            std::cout << "5. Año" << std::endl;
            std::cout << "6. Agregar Trofeo" << std::endl;
            std::cin >> opcionCambio;

            std::cin.ignore();

            if (opcionCambio == 1) {
              std::string t;
              std::cout << "Nuevo título: ";
              getline(std::cin, t);
              estandars[index].setTitulo(t);

            } else if (opcionCambio == 2) {
              std::string p;
              std::cout << "Nueva productora: ";
              getline(std::cin, p);
              estandars[index].setProductora(p);

            } else if (opcionCambio == 3) {
              std::string g;
              std::cout << "Nuevo género: ";
              getline(std::cin, g);
              estandars[index].setGenero(g);

            } else if (opcionCambio == 4) {
              int h;
              std::cout << "¿Cuántas horas quieres agregar?: ";
              std::cin >> h;
              estandars[index].agregarHoras(h);

            } else if (opcionCambio == 5) {
              int y;
              std::cout << "Nuevo año: ";
              std::cin >> y;
              estandars[index].setYear(y);

            } else if (opcionCambio == 6) {
              std::string trofeo;
              std::cout << "Trofeo a agregar: ";
              getline(std::cin, trofeo);
              estandars[index].agregarTrofeo(trofeo);

            } else {
              std::cout << "Opción inválida." << std::endl;
            }

            std::cout << "Datos actualizados." << std::endl;
          }
        }
      }

      else {
        std::cout << "Tipo inválido." << std::endl;
      }

      break;
    }
    }
  }
  return 0;
}
