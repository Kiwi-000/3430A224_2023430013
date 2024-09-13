#include <iostream>
#include <string>
using namespace std;

// Estructura para representar un contenedor
struct Contenedor {
    int numero;          
    string empresa;      
};

// Estructura para manejar una pila de contenedores
struct PilaContenedores {
    int max;             
    int tope;            
    Contenedor* datos;   
};

// Crear una pila con un tamaño máximo
PilaContenedores crear_pila(int max) {
    PilaContenedores pila;
    pila.max = max;
    pila.tope = -1;
    pila.datos = new Contenedor[max];
    return pila;
}

//Verificar si la pila está vacía
bool pila_vacia(PilaContenedores& pila) {
    return pila.tope == -1;
}

// Verificar si la pila está llena
bool pila_llena(PilaContenedores& pila) {
    return pila.tope == pila.max - 1;
}

// Insertar un contenedor en la pila
void push(PilaContenedores& pila, Contenedor contenedor) {
    if (pila_llena(pila)) {
        cout << "Desbordamiento, Pila de contenedores llena" << endl;
    } else {
        pila.datos[++pila.tope] = contenedor;
        cout << "Contenedor " << contenedor.numero << "/" << contenedor.empresa << " agregado a la pila." << endl;
    }
}

// Remover un contenedor de la pila
Contenedor pop(PilaContenedores& pila) {
}

// Mostrar los contenedores en la pila
void ver_pila(PilaContenedores& pila) {
    if (pila_vacia(pila)) {
        cout << "La pila de contenedores está vacía." << endl;
    } else {
        cout << "Contenido de la pila de contenedores:" << endl;
        for (int i = pila.tope; i >= 0; i--) {
            cout << i + 1 << " |" << pila.datos[i].numero << "/" << pila.datos[i].empresa << "|" << endl;
        }
    }
}

// Liberar la memoria de la pila
void destruir_pila(PilaContenedores& pila) {
    delete[] pila.datos;
}

// Inicializar las pilas del puerto seco
PilaContenedores* crear_puerto() {
}

// Mostrar el estado de todas las pilas
void ver_estado() {
}

// Agregar un contenedor a una pila específica
void agregar_contenedor() {
}

// Retirar un contenedor especificado por número y nombre
void retirar_contenedor(PilaContenedores* pilas, int m, int numero, string empresa) {

    // Buscar el contenedor en las pilas
    // Mover los contenedores superiores 
    // Retirar el contenedor deseado

}

// Función principal para ejecutar el programa
int main() {
    int n, m;
    cout << "Ingrese la capacidad máxima de contenedores por pila (n): ";
    cin >> n;
    cout << "Ingrese el número de pilas disponibles (m): ";
    cin >> m;

    // Creación de las pilas 

    do {
        cout << "\n1. Agregar contenedor" << endl;
        cout << "2. Retirar contenedor" << endl;
        cout << "3. Ver estado de las pilas" << endl;
        cout << "0. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == "1") {
        } else if (opcion == "2") {
        } else if (opcion == "3") {
        } else if (opcion != "0") {
            cout << "Opción no válida." << endl;
        }
    } while (opcion != "0");

    cout << "Saliendo..." << endl;

    // Liberar la memoria de todas las pilas
  
    return 0;
}