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


// Función para importar el contenido de un archivo de texto y almacenar los datos en una lista de cronómetros
void ImportarCronometros(const string& nombreArchivo, list<Cronometro>& tiempos) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para importar cronómetros: " << nombreArchivo << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        istringstream ss(linea);
        string nombreUsuario, fecha;
        int horas, minutos, segundos;
        if (getline(ss, nombreUsuario, ',') &&
            getline(ss, fecha, ',') &&
            ss >> horas && ss.ignore() &&
            ss >> minutos && ss.ignore() &&
            ss >> segundos) {
            
            tiempos.push_back(Cronometro(nombreUsuario, fecha, horas, minutos, segundos));
        }
    }

    archivo.close();
    tiempos.sort(); // Ordenar la lista después de importar
    cout << "Cronómetros importados y ordenados correctamente desde " << nombreArchivo << endl;

    // Imprimir el contenido de la lista de cronómetros
    for (const auto& cronometro : tiempos) {
        cout << cronometro.getNombreUsuario() << ", "
             << cronometro.getFecha() << ", "
             << cronometro.getHoras() << "h "
             << cronometro.getMinutos() << "m "
             << cronometro.getSegundos() << "s" << endl;
    }

    // Preguntar si el usuario desea agregar más cronómetros
    char opcion;
    cout << "¿Desea agregar más cronómetros? (s/n): ";
    cin >> opcion;

    while (opcion == 's' || opcion == 'S') {
        string nombreUsuario, fecha;
        int horas, minutos, segundos;

        cout << "Ingrese el nombre de usuario: ";
        cin >> nombreUsuario;
        cout << "Ingrese la fecha (dd/mm/yyyy): ";
        cin >> fecha;
        cout << "Ingrese horas: ";
        cin >> horas;
        cout << "Ingrese minutos: ";
        cin >> minutos;
        cout << "Ingrese segundos: ";
        cin >> segundos;

        // Agregar el nuevo cronómetro a la lista
        tiempos.push_back(Cronometro(nombreUsuario, fecha, horas, minutos, segundos));
        tiempos.sort(); // Reordenar la lista después de agregar un nuevo cronómetro

        // Mostrar la lista actualizada
        cout << "\nLista de cronómetros actualizada y ordenada:\n";
        for (const auto& cronometro : tiempos) {
            cout << cronometro.getNombreUsuario() << ", "
                 << cronometro.getFecha() << ", "
                 << cronometro.getHoras() << "h "
                 << cronometro.getMinutos() << "m "
                 << cronometro.getSegundos() << "s" << endl;
        }

        cout << "¿Desea agregar otro cronómetro? (s/n): ";
        cin >> opcion;
    }

    // Preguntar si el usuario desea exportar los cronómetros ordenados
    cout << "¿Desea exportar los cronómetros ordenados a un archivo? (s/n): ";
    cin >> opcion;

    if (opcion == 's' || opcion == 'S') {
        // Exportar cronómetros a un archivo
        ExportarCronometros("NUEVOcronometros_ordenados.txt", tiempos);
    }
}

// Función para importar el contenido de un archivo de texto y almacenar los datos en una lista de inventarios
void ImportarInventarios(const string& nombreArchivo, list<Inventario>& inventarios) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para importar inventarios: " << nombreArchivo << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        istringstream ss(linea);
        string nombreObjeto, rareza, tipo;
        int duracion, id;
        if (getline(ss, nombreObjeto, ',') &&
            getline(ss, rareza, ',') &&
            getline(ss, tipo, ',') &&
            ss >> duracion && ss.ignore() &&
            ss >> id) {
            
            inventarios.push_back(Inventario(nombreObjeto, rareza, duracion, tipo, id));
        }
    }

    archivo.close();
    inventarios.sort(); // Ordenar la lista después de importar
    cout << "Inventarios importados y ordenados correctamente desde " << nombreArchivo << endl;

    // Imprimir el contenido de la lista de inventarios
    for (const auto& inventario : inventarios) {
        cout << inventario.getNombredelObjeto() << ", "
             << inventario.getrareza() << ", "
             << inventario.gettipo() << ", "
             << inventario.getduracion() << "d "
             << inventario.getID() << endl;
    }

    // Preguntar si el usuario desea agregar más inventarios
    char opcion;
    cout << "¿Desea agregar más inventarios? (s/n): ";
    cin >> opcion;

    while (opcion == 's' || opcion == 'S') {
        string nombreObjeto, rareza, tipo;
        int duracion, id;

        cout << "Ingrese el nombre del objeto: ";
        cin >> nombreObjeto;
        cout << "Ingrese la rareza: ";
        cin >> rareza;
        cout << "Ingrese el tipo de objeto: ";
        cin >> tipo;
        cout << "Ingrese la duración: ";
        cin >> duracion;
        cout << "Ingrese el ID: ";
        cin >> id;

        // Agregar el nuevo inventario a la lista
        inventarios.push_back(Inventario(nombreObjeto, rareza, duracion, tipo, id));
        inventarios.sort(); // Reordenar la lista después de agregar un nuevo inventario

        // Mostrar la lista actualizada
        cout << "\nLista de inventarios actualizada y ordenada:\n";
        for (const auto& inventario : inventarios) {
            cout << inventario.getNombredelObjeto() << ", "
                 << inventario.getrareza() << ", "
                 << inventario.gettipo() << ", "
                 << inventario.getduracion() << "d "
                 << inventario.getID() << endl;
        }

        cout << "¿Desea agregar otro inventario? (s/n): ";
        cin >> opcion;
    }

    // Preguntar si el usuario desea exportar los inventarios ordenados
    cout << "¿Desea exportar los inventarios ordenados a un archivo? (s/n): ";
    cin >> opcion;

    if (opcion == 's' || opcion == 'S') {
        // Exportar inventarios a un archivo
        ExportarInventarios("NUEVOinventarios_ordenados.txt", inventarios);
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
             << "6. Exportar archivo inventario\n"
             << "7. Importar archivo cronómetro\n"
             << "8. Importar archivo inventario\n"
             << "9. Salir\n"; 

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

        } else if (opcion == 3) {
            string nombre;
            cout << "Introduce el nombre de usuario para buscar: \n";
            cin >> nombre;
            buscarCronometroPorNombre(tiempos, nombre);

        } else if (opcion == 4) {
            string tipo;
            cout << "Introduce el tipo de inventario que deseas buscar: ";
            cin >> tipo;
            buscarInventarioPorTipo(inventarios, tipo);

        } else if (opcion == 5) {
            ExportarCronometros("cronometros_exportados.txt", tiempos);

        } else if (opcion == 6) {
            ExportarInventarios("inventarios_exportados.txt", inventarios);

        } else if (opcion == 7) {
            ImportarCronometros("cronometros_importados.txt", tiempos);

        } else if (opcion == 8) {
            ImportarInventarios("inventarios_importados.txt", inventarios);

        }

    } while (opcion != 9);

    return 0;
}
