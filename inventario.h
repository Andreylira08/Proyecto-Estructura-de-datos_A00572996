#include <iostream>
#include <vector>
#include <string>

class Inventario {
private:

    std::string Nombredelobjeto;
    std::string rareza;  // formato "DD/MM/AAAA"
    int duracion;
    std::string tipo;
    int ID;

public:

    Inventario() : ID(0) {}


    Inventario(const std::string& nombre, const std::string& rareza, int d,const std::string& tipo, int id)
        : Nombredelobjeto(nombre), rareza(rareza), duracion(d), tipo(tipo), ID(id) {}


    std::string getNombredelObjeto() const { return Nombredelobjeto; }
    std::string getrareza() const { return rareza; }
    int getduracion() const { return duracion; }
    std::string gettipo() const { return tipo; }
    int getID() const { return ID; }


    bool operator<(const Inventario& other) const {
        if (ID != other.ID) return ID< other.ID;
        return false; 
    }


    friend std::ostream& operator<<(std::ostream& os, const Inventario& c) {
        os << "Nombre del objeto: " << c.Nombredelobjeto << ", Rareza: " << c.rareza
           << ", Duracion: " << c.duracion << " Tipo:  " << c.tipo << " ID:  " << c.ID ;
        return os;
    }
};
