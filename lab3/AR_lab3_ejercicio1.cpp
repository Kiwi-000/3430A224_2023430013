#include <iostream>
#include <string> 
using namespace std;

struct Pila {
    int max;
    int tope;
    int* datos;

    // Constructor para inicializar la pila con un tamaño máximo
    Pila(int max) {
        this->max = max;
        this->tope = -1;
        this->datos = new int[max];
    }

    // Verificar si la pila está vacía
    bool pila_vacia() {
        return tope == -1;
    }

    // Verificar si la pila está llena
    bool pila_llena() {
        return tope == max - 1;
    }

    // Insertar un elemento en la pila
    void push(int dato) {
        if (pila_llena()) {
            cout << "Desbordamiento, Pila llena" << endl;
        } else {
            tope++;
            datos[tope] = dato;
            cout << "Valor " << dato << " agregado a la pila" << endl;
        }
    }

    // Remover un elemento de la pila
    void pop() {
        if (pila_vacia()) {
            cout << "Subdesbordamiento, Pila vacía" << endl;
        } else {
            int eliminado = datos[tope];
            tope--;
            cout << "Elemento eliminado: " << eliminado << endl;
        }
    }

    // Mostrar el contenido de la pila
    void ver_pila() {
        if (pila_vacia()) {
            cout << "La pila está vacía." << endl;
        } else {
            cout << "Contenido de la pila:" << endl;
            for (int i = tope; i >= 0; i--) {
                cout << i + 1 << " |" << datos[i] << "|" << endl;
            }
        }
    }

    // Destructor para liberar memoria
    ~Pila() {
        delete[] datos;
    }
};

int main() {
    string input;
    cout << "Ingrese tamaño máximo de la Pila: ";
    cin >> input;

    // Convertir el string a entero
    int maxSize = stoi(input);

    Pila pila(maxSize);

    string opcion;
    do {
        cout << "\nAgregar/push [1]" << endl;
        cout << "Remover/pop [2]" << endl;
        cout << "Ver pila [3]" << endl;
        cout << "Salir [0]" << endl;
        cout << "----------------" << endl;
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == "1") {
            if (!pila.pila_llena()) {
                cout << "Ingrese valor: ";
                cin >> input;
                int valor = stoi(input);
                pila.push(valor);
            } else {
                cout << "Desbordamiento, Pila llena" << endl;
            }
        } else if (opcion == "2") {
            pila.pop();
        } else if (opcion == "3") {
            pila.ver_pila();
        } else if (opcion != "0") {
            cout << "Opción no válida." << endl;
        }
    } while (opcion != "0");

    cout << "Saliendo del programa..." << endl;
    return 0;
}

