#include <iostream>
#include <vector>
#include <string>

class Cronometro {
private:

    std::string nombreUsuario;
    std::string fecha;  // formato "DD/MM/AAAA"
    int horas;
    int minutos;
    int segundos;

public:

    Cronometro() : horas(0), minutos(0), segundos(0) {}


    Cronometro(const std::string& nombre, const std::string& fecha, int h, int m, int s)
        : nombreUsuario(nombre), fecha(fecha), horas(h), minutos(m), segundos(s) {}


    std::string getNombreUsuario() const { return nombreUsuario; }
    std::string getFecha() const { return fecha; }
    int getHoras() const { return horas; }
    int getMinutos() const { return minutos; }
    int getSegundos() const { return segundos; }


    bool operator<(const Cronometro& other) const {
        if (horas != other.horas) return horas < other.horas;
        if (minutos != other.minutos) return minutos < other.minutos;
        return segundos < other.segundos;
    }


    friend std::ostream& operator<<(std::ostream& os, const Cronometro& c) {
        os << "Usuario: " << c.nombreUsuario << ", Fecha: " << c.fecha 
           << ", Tiempo: " << c.horas << "h " << c.minutos << "m " << c.segundos << "s";
        return os;
    }
};
