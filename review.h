#include <string>

class review {
private:
    std::string tituloJuego;
    float rating;                  // 1 - 10
    float porcentajeTrofeos;
    int horasJugadas;
    std::string comentario;
    std::string estado;          // Jugando, Completado, Pendiente, Abandonado

public:
    review() : tituloJuego(""), rating(0.0), porcentajeTrofeos(0.0), horasJugadas(0),
            comentario(""), estado("") {};

    review(std::string tj, float r, float pt, int h, std::string com, std::string est) :
        tituloJuego(tj), rating(r), porcentajeTrofeos(pt), horasJugadas(h),
        comentario(com), estado(est) {};

    std::string getTituloJuego();
    float getRating();
    float getPorcentajeTrofeos();
    int getHorasJugadas();
    std::string getComentario();
    std::string getEstado();

    void setTituloJuego(std::string tj);
    void setRating(float r);
    void setPorcentajeTrofeos(float pt);
    void setHorasJugadas(int h);
    void setComentario(std::string com);
    void setEstado(std::string est);
};

std::string review::getTituloJuego() {
    return tituloJuego;
}

float review::getRating() {
    return rating;
}

float review::getPorcentajeTrofeos() {
    return porcentajeTrofeos;
}

int review::getHorasJugadas() {
    return horasJugadas;
}

std::string review::getComentario() {
    return comentario;
}

std::string review::getEstado() {
    return estado;
}

void review::setTituloJuego(std::string tj) {
    tituloJuego = tj;
}

void review::setRating(float r) {
    rating = r;
}

void review::setPorcentajeTrofeos(float pt) {
    porcentajeTrofeos = pt;
}

void review::setHorasJugadas(int h) {
    horasJugadas = h;
}

void review::setComentario(std::string com) {
    comentario = com;
}

void review::setEstado(std::string est) {
    estado = est;
}
