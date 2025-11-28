#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include "videojuego.h"
#include "review.h"

//Funciones auxiliares
void  menu(){
    std::cout << "Bienvenido!" << "\n¿Qué deseas hacer?" << std::endl;
    std::cout << "1. Ver Mis Videojuegos" << std::endl;
    std::cout << "2. Agregar Videojuego" << std::endl;
    std::cout << "3. Cambiar Reseña Videojuego" << std::endl;
    std::cout << "4. Cambiar Datos Videojuegos" << std::endl;
    std::cout << "5. Salir" << std::endl;
}
std::string imprimirVideojuegos(Videojuego arg[], int tam){
    std::stringstream aux;
    for (int i = 0; i < tam; i++) {
        aux << arg[i].getTitulo() << "\n";
    }
    return aux.str();
}

int main() {

    Videojuego videojuego;
    Videojuego coleccion[500];
    int totalVideojuegos = 0;

    std::string titulo, productora, genero, rango, comentario, trofeo;
    std::string trofeos[500], itemsObtenidos[500], jefesDerrotados[500];
    int horas, year, nivelPersonaje, partidasJugadas, partidasGanadas, cantidadTrofeos, rating;

    int opcion = 0;

    while (opcion < 5 && opcion > -1) {

        //Imprimir menu
        menu();
        std::cin >> opcion;
        switch(opcion){
            case 1:
            std::cout << "Tus Videojuegos:" << std::endl;
            std::cout << imprimirVideojuegos(coleccion, totalVideojuegos) << std::endl;
            std::cout << "¿Quieres ver los datos de uno?" <<std::endl;
            break;

            case 2:
            int opcionGenero;
            std::cout << "¿Qué género es el videojuego?" << std::endl;
            std::cout << "(1) RPG, (2) Competitivo, (3) Otro" << std::endl;
            std::cin >> opcionGenero;

            std::cout << "Ingrese el título" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, titulo);

            std::cout << "Ingrese la productora" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, productora);

            std::cout << "Ingrese el año en el que salió el juego" << std::endl;
            std::cin >> year;

            std::cout << "Ingrese sus horas jugadas" << std::endl;
            std::cin >> horas;

            std::cout << "¿Cuántos trofeos tienes?" << std::endl;
            std::cin >> cantidadTrofeos;

            //Definir genero
            if (opcionGenero == 1) {
                genero = "RPG";
            }
            else if (opcionGenero == 2) {
                genero = "Competitivo";
            }
            else {
                std::cout << "Escribe el género:" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, genero);
            }

            //Construcción del videojuego sin reseña
            if (opcionGenero == 1) {
                std::cout << "Ingrese el nivel del personaje" << std::endl;
                std::cin >> nivelPersonaje;
                coleccion[totalVideojuegos] = Rpg(titulo, productora, genero, horas, year, nivelPersonaje);
            }
            else if (opcionGenero == 2) {
                std::cout << "Ingrese partidas jugadas" << std::endl;
                std::cin >> partidasJugadas;
                std::cout << "Ingrese partidas ganadas" << std::endl;
                std::cin >> partidasGanadas;
                coleccion[totalVideojuegos] = Ranked(titulo, productora, genero, horas, year, partidasJugadas, partidasGanadas);
            }
            else {
                coleccion[totalVideojuegos] = Estandar(titulo, productora, genero, horas, year);
            }

            //Agregar trofeos
            for (int i = 0; i < cantidadTrofeos; i++) {
                std::cout << "Trofeo #" << i+1 << ": ";
                std::cin.ignore();
                std::getline(std::cin, trofeo);
                coleccion[totalVideojuegos].agregarTrofeo(trofeo);
            }

            //Reseña
            std::cout << "¿Deseas agregar una reseña ahora? (1 = Sí, 2 = No):\n";
            int opResena;
            std::cin >> opResena;

            if (opResena == 1) {
                int rating;
                std::string comentario;

                std::cout << "Ingresa rating (0-10): ";
                std::cin >> rating;

                std::cout << "Ingresa comentario:\n";
                std::cin.ignore();
                std::getline(std::cin, comentario);

                coleccion[totalVideojuegos].setReview(Review(rating, comentario));
                }
            else {
                coleccion[totalVideojuegos].setReview(Review()); // reseña vacía
            }

                totalVideojuegos++;


            break;

            case 3:

            break;

            case 4:

            break;
        }
    }
    return 0;
}
