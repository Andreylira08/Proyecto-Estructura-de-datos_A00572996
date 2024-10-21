#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include "Cronometro.h"
#include "inventario.h"
#include "MergeSort.h"

using namespace std;




// Exportar cronómetros a un archivo de texto
void ExportarCronometros(const string& nombreArchivo, const list<Cronometro>& tiempos) {
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para exportar cronómetros: " << nombreArchivo << endl;
        return;
    }

    for (const auto& cronometro : tiempos) {
        archivo << cronometro.getNombreUsuario() << ","
                << cronometro.getFecha() << ","
                << cronometro.getHoras() << ","
                << cronometro.getMinutos() << ","
                << cronometro.getSegundos() << endl;
    }

    archivo.close();
    cout << "Cronómetros exportados correctamente a " << nombreArchivo << endl;
}
// Exportar inventarios a un archivo de texto
void ExportarInventarios(const string& nombreArchivo, const list<Inventario>& inventarios) {
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para exportar inventarios: " << nombreArchivo << endl;
        return;
    }

    for (const auto& inventario : inventarios) {
        archivo << inventario.getNombredelObjeto() << ","
                << inventario.getrareza() << ","
                << inventario.getduracion() << ","
                << inventario.gettipo() << ","
                << inventario.getID() << endl;
    }

    archivo.close();
    cout << "Inventarios exportados correctamente a " << nombreArchivo << endl;
}

// Buscar por nombre de usuario 
void buscarCronometroPorNombre(const list<Cronometro>& tiempos, const string& nombre) {
    bool encontrado = false;

    for (const auto& tiempo : tiempos) {
        if (tiempo.getNombreUsuario() == nombre) {
            cout << "Cronómetro encontrado: " << tiempo << endl;
            encontrado = true;
            break;  
        }
    }

    if (!encontrado) {
        cout << "No se encontró un cronómetro para el usuario: " << nombre << endl;
    }
}

// Buscar por tipo en el inventario

void buscarInventarioPorTipo(const list<Inventario>& inventarios, const string& tipo) {
    bool encontrado = false;

    for (const auto& inventario : inventarios) {
        if (inventario.gettipo() == tipo) {
            cout << inventario << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron inventarios del tipo: " << tipo << endl;
    }
}

int main() {

    std::list<Cronometro> tiempos = {

        Cronometro("Alice", "10/10/2024", 4, 30, 30),
        Cronometro("Bob", "11/10/2024", 2, 15, 0),
        Cronometro("Charlie", "12/10/2024", 1, 15, 50),
        Cronometro("Dave", "10/10/2024", 1, 30, 0),
        Cronometro("Eve", "11/10/2024", 2, 10, 15),
        Cronometro("Carlos", "12/10/2024", 4, 15, 50),
        Cronometro("Enrique", "12/09/2024", 5, 30, 53),
        Cronometro("Lalo", "12/09/2024", 5, 15, 33),
        Cronometro("Santiago", "12/10/2024", 1, 52, 12),
        Cronometro("Pedro", "12/12/2024", 1, 12, 19),
        Cronometro("Pookie", "12/09/2024", 2, 23, 10),
        Cronometro("Juan", "12/01/2024", 3, 12, 03),
        Cronometro("Emilio", "12/04/2024", 1, 42, 21),
        Cronometro("Carlos", "12/10/2024", 1, 13, 02),
        Cronometro("Mateo", "12/10/2024", 5, 33, 11),
        Cronometro("Charlie", "12/10/2024", 1, 13, 65),
    };

    Sort<Cronometro> sort;
    std::list<Cronometro> tiemposOrdenados(tiempos.begin(), tiempos.end());
    tiemposOrdenados.sort();

    std::list<Inventario> inventarios = {
        Inventario("Espada", "Legendario", 30, "Arma", 1),
        Inventario("Escudo", "Epico", 30, "Defensa", 2),
        Inventario("Palo", "Normal", 10, "Arma", 7),
        Inventario("Armadura", "Legendario", 30, "Defensa", 6),
        Inventario("Manzana", "Raro", 1, "Comida", 4),
        Inventario("Linterna", "comun", 30, "Utilidad", 3),
        Inventario("Espejo", "comun", 20, "Utilidad", 4),
        Inventario("papel", "raro", 5, "Utilidad", 11),
        Inventario("llave", "raro", 1, "Utilidad", 12),
    };

    Sort<Inventario> sorts;
    std::list<Inventario> inventariosOrdenados(inventarios.begin(), inventarios.end());
    inventariosOrdenados.sort();

   int opcion = 0;

    do {
        cout << "Bienvenido a la base de datos del videojuego - La casita del terror -\n";
        cout << "¿Qué quieres hacer?\n"
             << "1. Ver tiempos record\n"
             << "2. Ver inventario del juego ordenado por ID\n"
             << "3. Buscar cronómetro por nombre\n"
             << "4. Buscar inventario por tipo\n"
             << "5. Exportar archivo cronómetro\n"
             << "6. Importar archivo inventario\n"
             << "7. Salir\n"; 

        cin >> opcion;

        if (opcion == 1) {
            cout << "Tiempos ordenados:\n";
            tiempos.sort();
            for (const auto& tiempo : tiempos) {
                cout << tiempo << endl;
            }

        } else if (opcion == 2) {
            cout << "Inventario ordenado por ID:\n";
            inventarios.sort();
            for (const auto& inventario : inventarios) {
                cout << inventario << endl;
            }
            
        } 
        
        else if (opcion == 3) {
            string nombre;
            cout << "Introduce el nombre de usuario para buscar: \n";
            cout <<"===========================================\n"; 

            cin >> nombre;

            cout <<"===========================================\n"; 
            buscarCronometroPorNombre(tiempos, nombre);
            cout <<"===========================================\n"; 
        } 
        
        else if (opcion == 4) {
            string tipo;
            cout <<"===========================================\n"; 
            cout << "Introduce el tipo de inventario que deseas buscar: ";
            cout <<"===========================================\n"; 
            cin >> tipo;
            buscarInventarioPorTipo(inventarios, tipo);
            cout <<"===========================================\n"; 
        }
         else if (opcion == 5) {

            ExportarCronometros("cronometros_exportados.txt", tiempos);

        } else if (opcion == 6) {

            ExportarInventarios("inventarios_exportados.txt", inventarios);

        }
    } while (opcion != 7);

    return 0;
}