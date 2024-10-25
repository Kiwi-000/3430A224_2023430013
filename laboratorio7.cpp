#include <iostream>
#include <fstream>
#include <climits>  

using namespace std;

const int INF = INT_MAX;

class Grafo {
    int N;         // Número de nodos
    int **matriz;  // Matriz 

public:

    //Constructor
    Grafo(int n) : N(n) {
        matriz = new int*[N];
        for (int i = 0; i < N; i++) {
            matriz[i] = new int[N];
            for (int j = 0; j < N; j++) {
                matriz[i][j] = (i == j) ? 0 : INF;  
            }
        }
    }

    // Liberar la memoria
    ~Grafo() {
        for (int i = 0; i < N; i++) {
            delete[] matriz[i];  
        }
        delete[] matriz;  
    }

    // Función para leer la matriz de distancias
    void leer_matriz_distancias() {
        cout << "Ingrese valores para la matriz de distancias (use -1 para infinitos):" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    cout << "Distancia del nodo " << char('A' + i) << " al nodo " << char('A' + j) << ": ";
                    int dist;
                    cin >> dist;
                    matriz[i][j] = (dist == -1) ? INF : dist;
                }
            }
        }
        cout << ".................................." << endl;
    }

    //Imprime Matriz
    void imprimir_matriz() {
        cout << "Matriz de distancias:" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (matriz[i][j] == INF)
                    cout << "-1\t"; 
                else
                    cout << matriz[i][j] << "\t";  
            }
            cout << endl;
        }
        cout << ".................................." << endl;
    }

    // Implementacion del algoritmo de Prim 
    void prim(int padre[]) {
        int clave[N];   
        bool enMST[N];  

        // Inicializar todas las claves 
        for (int i = 0; i < N; i++) {
            clave[i] = INF;
            enMST[i] = false;
        }

        clave[0] = 0;    
        padre[0] = -1;   

        // PRIM
        for (int count = 0; count < N - 1; count++) {
            int u = encontrar_min_clave(clave, enMST); 
            enMST[u] = true;  

            // Actualizar las claves y padres 
            for (int v = 0; v < N; v++) {
                if (matriz[u][v] && !enMST[v] && matriz[u][v] < clave[v]) {
                    padre[v] = u;
                    clave[v] = matriz[u][v];
                }
            }
        }
    }

    // Función para encontrar el vértice con la clave mínima que no esté en el MST
    int encontrar_min_clave(int clave[], bool enMST[]) {
        int min = INF, min_index;
        for (int v = 0; v < N; v++) {
            if (!enMST[v] && clave[v] < min) {
                min = clave[v];
                min_index = v;
            }
        }
        return min_index;
    }

    // Función para imprimir el conjunto de aristas en el árbol de expansión mínima
    void imprimir_conjunto_L(int padre[]) {
        cout << "Aristas del arbol de expansion minima:" << endl;
        for (int i = 1; i < N; i++) {
            cout << char('A' + padre[i]) << " - " << char('A' + i) << " Peso: " << matriz[i][padre[i]] << endl;
        }
    }

    // Función para imprimir el grafo original
    void imprimir_grafo_original() {
        ofstream fp("grafo_original.dot");
        fp << "digraph G {" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (matriz[i][j] != INF && i != j) {
                    fp << char('A' + i) << " -> " << char('A' + j) << " [label=" << matriz[i][j] << "];" << endl;
                }
            }
        }
        fp << "}" << endl;
        fp.close();
        system("dot -Tpng grafo_original.dot -o grafo_original.png");
    }

    // Función para imprimir el grafo de costo mínimo 
    void imprimir_grafo_CM(int padre[]) {
        ofstream fp("grafo_CM.dot");
        fp << "digraph G {" << endl;
        for (int i = 1; i < N; i++) {
            fp << char('A' + padre[i]) << " -> " << char('A' + i) << " [label=" << matriz[i][padre[i]] << "];" << endl;
        }
        fp << "}" << endl;
        fp.close();
        system("dot -Tpng grafo_CM.dot -o grafo_CM.png");
    }
};


// Principal

int main() {
    int N;
    cout << "Ingrese el numero de nodos: ";
    cin >> N;

    // Crear el objeto Grafo
    Grafo g(N);

    g.leer_matriz_distancias();

    g.imprimir_matriz();

    int padre[N];
    g.prim(padre);

    g.imprimir_grafo_original();

    g.imprimir_grafo_CM(padre);

    g.imprimir_conjunto_L(padre);

    return 0;
}
