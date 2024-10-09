#include <iostream>
#include <fstream>

using namespace std;

struct Nodo {
    int dato;
    int FE;  
    Nodo* derecho;
    Nodo* izquierdo;
    Nodo* padre;
};

//Puntero
typedef Nodo* Arbol;

//Crear nodo
Nodo* crearNodo(int dato) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    nuevo->padre = NULL;
    nuevo->FE = 0;
    return nuevo;
}



// RII
void RotaIzquierdaIzquierda(Arbol& nodo) {
    Arbol hijoIzq = nodo->izquierdo;
    nodo->izquierdo = hijoIzq->derecho;
    if (hijoIzq->derecho != NULL) {
        hijoIzq->derecho->padre = nodo;
    }
    hijoIzq->derecho = nodo;
    hijoIzq->padre = nodo->padre;
    nodo->padre = hijoIzq;
    nodo = hijoIzq;
    nodo->derecho->FE = 0;
    nodo->FE = 0;
}

// RDD
void RotaDerechaDerecha(Arbol& nodo) {
    Arbol hijoDer = nodo->derecho;
    nodo->derecho = hijoDer->izquierdo;
    if (hijoDer->izquierdo != NULL) {
        hijoDer->izquierdo->padre = nodo;
    }
    hijoDer->izquierdo = nodo;
    hijoDer->padre = nodo->padre;
    nodo->padre = hijoDer;
    nodo = hijoDer;
    nodo->izquierdo->FE = 0;
    nodo->FE = 0;
}

// RID
void RotaIzquierdaDerecha(Arbol& nodo) {
    RotaDerechaDerecha(nodo->izquierdo);
    RotaIzquierdaIzquierda(nodo);
}

// RDI
void RotaDerechaIzquierda(Arbol& nodo) {
    RotaIzquierdaIzquierda(nodo->derecho);
    RotaDerechaDerecha(nodo);
}

// Insertar nodo
void inserta_balanceado(Arbol& raiz, bool& crece, int dato) {
    if (raiz == NULL) {
        raiz = crearNodo(dato);
        crece = true;
        return;
    }

    if (dato < raiz->dato) {
        inserta_balanceado(raiz->izquierdo, crece, dato);
        if (crece) {
            raiz->FE--;
            if (raiz->FE == -2) {
                if (raiz->izquierdo->FE == -1) {
                    RotaIzquierdaIzquierda(raiz);
                } else {
                    RotaIzquierdaDerecha(raiz);
                }
                crece = false;
            } else if (raiz->FE == 0) {
                crece = false;
            }
        }
    } else if (dato > raiz->dato) {
        inserta_balanceado(raiz->derecho, crece, dato);
        if (crece) {
            raiz->FE++;
            if (raiz->FE == 2) {
                if (raiz->derecho->FE == 1) {
                    RotaDerechaDerecha(raiz);
                } else {
                    RotaDerechaIzquierda(raiz);
                }
                crece = false;
            } else if (raiz->FE == 0) {
                crece = false;
            }
        }
    } else {
        crece = false;  
    }
}

//Imprimir en preorden
void printPreorder(Nodo* root) {
    if (root == NULL){
        return;
    }
    cout << root->dato << " ";
    printPreorder(root->izquierdo);
    printPreorder(root->derecho);
}

//Buscar elemento
bool search(Nodo* root, int data){
    if(root == NULL){
        return false;
    }
    else if (root->dato == data){
        return true;
    }
    else if (data < root->dato){
        return search(root->izquierdo, data);
    }
    else{
        return search(root->derecho, data);
    }
}

//Eliminar nodo 
void eliminar_balanceado(Nodo*& raiz, int dato, bool& decrece) {
    if (raiz == NULL) {
        decrece = false;
        return;
    }

    if (dato < raiz->dato) {
        eliminar_balanceado(raiz->izquierdo, dato, decrece);
        if (decrece) {
            raiz->FE++;
            if (raiz->FE == 2) {
                if (raiz->derecho->FE >= 0) {
                    RotaDerechaDerecha(raiz);
                    if (raiz->FE == -1) decrece = false;
                } else {
                    RotaDerechaIzquierda(raiz);
                }
            } else if (raiz->FE == 1) {
                decrece = false;
            }
        }
    } else if (dato > raiz->dato) {
        eliminar_balanceado(raiz->derecho, dato, decrece);
        if (decrece) {
            raiz->FE--;
            if (raiz->FE == -2) {
                if (raiz->izquierdo->FE <= 0) {
                    RotaIzquierdaIzquierda(raiz);
                    if (raiz->FE == 1) decrece = false;
                } else {
                    RotaIzquierdaDerecha(raiz);
                }
            } else if (raiz->FE == -1) {
                decrece = false;
            }
        }
    } else {  
        Nodo* eliminado = raiz;

        if (raiz->izquierdo == NULL) {
            raiz = raiz->derecho;
            decrece = true;
        } else if (raiz->derecho == NULL) {
            raiz = raiz->izquierdo;
            decrece = true;
        } else {
            Nodo* reemplazo = raiz->izquierdo;
            while (reemplazo->derecho != NULL) {
                reemplazo = reemplazo->derecho;
            }
            raiz->dato = reemplazo->dato;
            eliminar_balanceado(raiz->izquierdo, reemplazo->dato, decrece);
            if (decrece) {
                raiz->FE++;
                if (raiz->FE == 2) {
                    if (raiz->derecho->FE >= 0) {
                        RotaDerechaDerecha(raiz);
                        if (raiz->FE == -1) decrece = false;
                    } else {
                        RotaDerechaIzquierda(raiz);
                    }
                } else if (raiz->FE == 1) {
                    decrece = false;
                }
            }
        }
        delete eliminado;
    }
}

//Modificar nodo
void modify(Nodo*& raiz, int oldData, int newData) {
    bool decrece = false;
    if (search(raiz, oldData)) {
        eliminar_balanceado(raiz, oldData, decrece);
        bool crece = false;
        inserta_balanceado(raiz, crece, newData);
        cout << "Nodo modificado correctamente." << endl;
    } else {
        cout << "Elemento no encontrado." << endl;
    }
}

// Libera memoria
void Podar(Nodo*& nodo) {
    if (nodo) {
        Podar(nodo->izquierdo);
        Podar(nodo->derecho);
        delete nodo;
        nodo = NULL;
    }
}

// Genera archivo DOT 
void generarDot(Nodo* raiz, ofstream& archivo) {
    if (raiz == NULL) return;

    archivo << "    " << raiz->dato << " [label=\"" << raiz->dato << " (FE=" << raiz->FE << ")\"];" << endl;

    if (raiz->izquierdo != NULL) {
        archivo << "    " << raiz->dato << " -> " << raiz->izquierdo->dato << ";" << endl;
        generarDot(raiz->izquierdo, archivo);
    }

    if (raiz->derecho != NULL) {
        archivo << "    " << raiz->dato << " -> " << raiz->derecho->dato << ";" << endl;
        generarDot(raiz->derecho, archivo);
    }
}

// Crear archivo DOT 
void crearDot(Nodo* raiz) {
    ofstream archivo("arbol.dot");
    archivo << "digraph G {" << endl;
    generarDot(raiz, archivo);
    archivo << "}" << endl;
    archivo.close();
    cout << "Archivo DOT generado correctamente." << endl;
}

// Menú 
void MenuPrincipal() {
    cout << "-------------------------" <<endl;
    cout << "1. Insertar elemento" << endl;
    cout << "2. Buscar elemento" << endl;
    cout << "3. Eliminar elemento" << endl;
    cout << "4. Modificar elemento" << endl;
    cout << "5. Imprimir Preorden" << endl;
    cout << "6. Generar Grafo" << endl;
    cout << "0. Salir" << endl;
    cout << "-------------------------" <<endl;
}

// Main
int main() {
    Arbol raiz = NULL;
    bool crece = false, decrece = false;
    int opcion, dato, oldData, newData;

    do {
        MenuPrincipal();  
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese valor: ";
            cin >> dato;
            inserta_balanceado(raiz, crece, dato);
            cout << "Elemento insertado."<< endl;
            break;
        case 2:
            cout << "Ingrese valor a buscar: ";
            cin >> dato;
            if (search(raiz, dato)) {
                cout << "Elemento encontrado."<< endl;
            } else {
                cout << "Elemento no encontrado."<< endl;
            }
            break;
        case 3:
            cout << "Ingrese valor a eliminar: ";
            cin >> dato;
            eliminar_balanceado(raiz, dato, decrece);
            cout << "Elemento eliminado."<< endl;
            break;
        case 4:
            cout << "Ingrese valor a modificar: ";
            cin >> oldData;
            cout << "Ingrese nuevo valor: ";
            cin >> newData;
            modify(raiz, oldData, newData);
            break;
        case 5:
            cout << "Preorden: ";
            printPreorder(raiz);
            cout << endl;
            break;
        case 6:
            crearDot(raiz);
            system("dot -Tpng arbol.dot -o arbol.png");
            system("explorer arbol.png");
            break;
        case 0:
            cout << "Saliendo del programa."<< endl;
            cout << ". . ." <<endl;
            break;
        default:
            cout << "Opción inválida."<< endl;
        }
    } while (opcion != 0);

    Podar(raiz);  
    return 0;
}
