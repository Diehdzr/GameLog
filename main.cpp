#include <iostream>
#include <string>

#include "videojuego.h"
#include "review.h"
#include "usuario.h"

int main() {

    // Crear un videojuego
    videojuego game("Hollow Knight", "Metroidvania", "Multi-Plataforma", "Team Cherry", 2017);

    std::cout << "VIDEOJUEGO:" << std::endl;
    std::cout << "Titulo: " << game.getTitulo() << std::endl;
    std::cout << "Genero: " << game.getGenero() << std::endl;
    std::cout << "Plataforma: " << game.getPlataforma() << std::endl;
    std::cout << "Productora: " << game.getProductora() << std::endl;
    std::cout << "Año: " << game.getYear() << std::endl;
    std::cout << std::endl;


    // Crear un usuario
    usuario user("Diego", 18);

    std::cout << "USUARIO:" << std::endl;
    std::cout << "Nombre: " << user.getNombre() << std::endl;
    std::cout << "Edad: " << user.getEdad() << std::endl;
    std::cout << std::endl;


    // Crear una review
    review rev("Hollow Knight", 9.5, 100.0, 42, "El mejor juego indie que he jugado en mi vida fr.", "Completado");

    std::cout << "RESEÑA:" << std::endl;
    std::cout << "Juego: " << rev.getTituloJuego() << std::endl;
    std::cout << "Rating: " << rev.getRating() << std::endl;
    std::cout << "Trofeos: " << rev.getPorcentajeTrofeos() << "%" << std::endl;
    std::cout << "Horas jugadas: " << rev.getHorasJugadas() << std::endl;
    std::cout << "Comentario: " << rev.getComentario() << std::endl;
    std::cout << "Estado: " << rev.getEstado() << std::endl;

    return 0;
}
