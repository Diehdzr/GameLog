#ifndef REVIEW_H
#define REVIEW_H
#include <string>

class Review {
    private:
    //Atributos
    int rating;
    std::string comentario;

    public:
    //Constructores
    Review() : rating(0), comentario("") {};
    Review(int ra, std::string cm) : rating(ra), comentario(cm) {};

    //Declarar getters
    int getRating();
    std::string getComentario();

    //Declarar setters
    void setRating(int r);
    void setComentario(std::string c);

    //Metodos de actualizacion
    void cambiarRating(int r);
    void cambiarComentario(std::string c);
};

// Getters
   int Review::getRating() {
       return rating;
   }
   std::string Review::getComentario() {
       return comentario;
   }

   // Setters
   void Review::setRating(int r) {
       if (r >= 0 && r <= 10) { // por ejemplo, escala 0-10
           rating = r;
       }
   }
   void Review::setComentario(std::string c) {
       comentario = c;
   }

   // Métodos de actualización
   void Review::cambiarRating(int r) {
       setRating(r);
   }
   void Review::cambiarComentario(std::string c) {
       comentario = c;
   }

#endif
