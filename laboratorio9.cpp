#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype> 

using namespace std;

const int TABLE_SIZE = 20;
const string EMPTY = "VACIO";

struct Node {
    int key;
    string value;
    Node* next;
};

//----------------------Funciones Hash------------------------

// Función hash básica
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Segunda función hash para doble direccionamiento
int hashFunctionPrime(int key) {
    return 7 - (key % 7); // Un numero primo menor que TABLE_SIZE
}

//----------------------Funciones de impresión----------------

// Imprimir el contenido del arreglo (para cualquier metodo)
void printTable(const string table[TABLE_SIZE]) {
    cout << "Tabla Hash: Estado Actual" << endl;
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << ": " << table[i] << endl;
    }
    cout << "-------------------------" << endl << endl;
}

// Imprimir la lista enlazada para encadenamiento
void printChainedTable(Node* table[TABLE_SIZE]) {
    cout << "Tabla Hash (Encadenamiento): Estado Actual" << endl;
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << ": ";
        Node* current = table[i];
        while (current != nullptr) {
            cout << "[" << current->key << ", " << current->value << "] -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
    cout << "------------------------------" << endl;
}

//----------------------Funciones de resolucion de colisiones--------------------

// Resolucion de colisiones con Prueba Lineal
void pruebaLineal(string table[TABLE_SIZE], int key, const string& value) {
    cout << "Insercion: Prueba Lineal" << endl;
    int index = hashFunction(key);
    int startIndex = index;
    int steps = 0;

    while (table[index] != EMPTY) {
        index = (index + 1) % TABLE_SIZE; // Prueba lineal
        steps++;
        if (index == startIndex) {
            cout << "Tabla llena, no se puede insertar." << endl;
            cout << "-----------------------------------" << endl;
            return;
        }
    }
    table[index] = value;
    cout << "Insertado en indice: " << index << " (desplazamientos: " << steps << ")" << endl;
    cout << "------------------------------" << endl;
}

// Resolucion de colisiones con Prueba Cuadratica
void pruebaCuadratica(string table[TABLE_SIZE], int key, const string& value) {
    cout << "Insercion: Prueba Cuadratica" << endl;
    int index = hashFunction(key);
    int i = 0, steps = 0;

    while (table[index] != EMPTY) {
        i++;
        index = (hashFunction(key) + i * i) % TABLE_SIZE;
        steps++;
        if (i >= TABLE_SIZE) {
            cout << "Tabla llena, no se puede insertar." << endl;
            cout << "-----------------------------" << endl;
            return;
        }
    }
    table[index] = value;
    cout << "Insertado en indice: " << index << " (desplazamientos: " << steps << ")" << endl;
    cout << "-----------------------------" << endl;
}

// Resolucion de colisiones con Doble Direccion Hash
void dobleDireccion(string table[TABLE_SIZE], int key, const string& value) {
    cout << "Insercion: Doble Direccion Hash" << endl;
    int index = hashFunction(key);
    int originalIndex = index;
    int steps = 0;

    while (table[index] != EMPTY) {
        int h2 = hashFunctionPrime(key); // Segunda funcion hash
        index = (index + h2) % TABLE_SIZE;
        steps++;
        if (index == originalIndex) {
            cout << "Tabla llena, no se puede insertar." << endl;
            cout << "-----------------------------" << endl;
            return;
        }
    }
    table[index] = value;
    cout << "Insertado en indice: " << index << " (desplazamientos: " << steps << ")" << endl;
    cout << "-----------------------------" << endl;
}

// Resolucion de colisiones con Encadenamiento
void encadenamiento(Node* table[TABLE_SIZE], int key, const string& value) {
    cout << "Insercion: Encadenamiento" << endl;
    int index = hashFunction(key);

    Node* newNode = new Node{key, value, nullptr};
    if (table[index] == nullptr) {
        table[index] = newNode;
        cout << "Insertado en indice: " << index << endl;
    } else {
        Node* current = table[index];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        cout << "Insertado en lista enlazada en indice: " << index << endl;
    }
    cout << "-----------------------------" << endl;
}

//----------------------Funciones de busqueda-------------------------------------

// Busqueda de un elemento
void buscar(string table[TABLE_SIZE], int key, const string& value) {
    cout << "Busqueda: Tabla Hash" << endl;
    int index = hashFunction(key);
    int steps = 0;

    while (table[index] != EMPTY) {
        if (table[index] == value) {
            cout << "Encontrado en indice: " << index << " (desplazamientos: " << steps << ")" << endl;
            cout << "-----------------------------" << endl;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        steps++;
        if (steps > TABLE_SIZE) {
            break;
        }
    }
    cout << "Elemento no encontrado." << endl;
    cout << "-----------------------------" << endl;
}

// Busqueda en tabla encadenada
void buscarEncadenado(Node* table[TABLE_SIZE], int key) {
    cout << "Busqueda: Tabla Encadenada" << endl;
    int index = hashFunction(key);
    Node* current = table[index];

    while (current != nullptr) {
        if (current->key == key) {
            cout << "Encontrado en indice: " << index << " con valor: " << current->value << endl;
            cout << "-----------------------------" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Elemento no encontrado." << endl;
    cout << "-----------------------------" << endl;
}

//---------------------------Funcion principal-----------------------------------

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Use: ./laboratorio9 {L|C|D|E}" << endl;
        return 1;
    }

    // Convertir el argumento a mayusculas
    string method = argv[1];
    for (char& c : method) {
        c = toupper(c); // Convierte a mayuscula
    }

    if (method != "L" && method != "C" && method != "D" && method != "E") {
        cout << "Metodo no valido." << endl;
        return 1;
    }

    string table[TABLE_SIZE];
    Node* chainedTable[TABLE_SIZE] = {nullptr};

    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = EMPTY;
    }

    int key;
    string value;

    // Bucle principal de insercion y busqueda
    while (true) {
        cout << "Ingrese clave y valor (o -1 para terminar): ";
        cin >> key;
        if (key == -1) break;
        cin >> value;

        if (method == "L") {
            pruebaLineal(table, key, value);
        } else if (method == "C") {
            pruebaCuadratica(table, key, value);
        } else if (method == "D") {
            dobleDireccion(table, key, value);
        } else if (method == "E") {
            encadenamiento(chainedTable, key, value);
        }

        if (method == "E") {
            printChainedTable(chainedTable);
        } else {
            printTable(table);
        }
    }

    // Busqueda final
    cout << "Ingrese clave a buscar: ";
    cin >> key;

    if (method == "E") {
        buscarEncadenado(chainedTable, key);
    } else {
        buscar(table, key, value);
    }

    return 0;
}
