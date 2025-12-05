/*
 * Proyecto GameLog
 * Diego Hernández Rangel
 * A01710524
 * 5/12/2025
 */

/*
 * Clase Review que contiene los metodos para agregar un rating
 * y comentario, junto con metodos para modificarlos.
 */

#ifndef REVIEW_H
#define REVIEW_H
#include <string>

//Declaración de la clase Review
class Review {
    private:
    //Atributos
    int rating;
    std::string comentario;

    public:
    //Constructor vacío
    Review() : rating(0), comentario(""){};

    //Constructor con parametros
    Review(int ra, std::string cm) : rating(ra), comentario(cm){};

    //Declarar getters
    int getRating();
    std::string getComentario();

    //Declarar setters
    void setRating(int r);
    void setComentario(std::string c);
};

// Getters

/**
 * getter rating
 *
 * @param
 * @return int: rating
 */
int Review::getRating() {
    return rating;
}

/**
 * getter comentario
 *
 * @param
 * @return string: comentario
 */
std::string Review::getComentario() {
    return comentario;
}

// Setters

/**
 * setter de rating
 *
 * param int r: nuevo rating
 * a rating
 */
void Review::setRating(int r) {
    rating = r;
}

/**
 * setter de comentario
 *
 * @param: string c: nuevo comentario
 * a comentario
 */
void Review::setComentario(std::string c) {
    comentario = c;
}

#endif
