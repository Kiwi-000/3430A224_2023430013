#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define TRUE 1
#define FALSE 0

#define N 5 //Valor fijo para N

//----------------------Declaracion de funciones--------------------------------

void leer_nodos(char vector[N], int n);
void leer_matriz_distancias(char V[N], int M[N][N]);
void inicializar_vector_D(int D[N], int M[N][N], int col);
void inicializar_vector_caracter(char vector[], int col);
void aplicar_dijkstra(char V[N], char S[N], char VS[N], int D[N], int M[N][N]);
void imprimir_matriz(int matriz[N][N]);
void imprimir_vector_caracter(char vector[N], const char *nomVector);
void imprimir_vector_entero(int vector[N]);
void imprimir_grafo(int matriz[N][N], char vector[N]);
void agrega_vertice_a_S(char S[N], char vertice);
void actualizar_VS(char V[N], char S[N], char VS[N]);
int elegir_vertice(char VS[N], int D[N], char V[N]);
void actualizar_pesos(int D[N], char VS[N], int M[N][N], char V[N], char v);
int buscar_indice_caracter(char V[N], char caracter);
int busca_caracter(char c, char vector[N]);
int calcular_minimo(int dw, int dv, int mvw);


//-------------------------Funciones de inicialización---------------------------------------------------------
// Función para leer nodos
void leer_nodos(char vector[N], int n) {
    int inicio = 97;  
    for (int i = 0; i < n; i++) {
        vector[i] = inicio + i;
    }
}

// Función para leer la matriz de distancias
void leer_matriz_distancias(char V[N], int M[N][N]) {
    cout << "Ingrese valores para la matriz de distancias" << endl;
    cout << " - Tenga en cuenta que la Matriz es de 5 x 5" << endl;
    cout << " - Use -1 para distancias infinitas" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                M[i][j] = 0;  
            } else {
                cout << "Distancia del nodo " << V[i] << " al nodo " << V[j] << ": ";
                cin >> M[i][j];
            }
        }
    }
}

// Inicializar el vector D[] desde la primera fila de la matriz de adyacencia
void inicializar_vector_D(int D[N], int M[N][N], int col) {
    for (int i = 0; i < N; i++) {
        D[i] = M[0][i];
    }
}

// Inicializa un vector con espacios
void inicializar_vector_caracter(char vector[], int col) {
    for (int col = 0; col < N; col++) {
        vector[col] = ' ';
    }
}

//---------------------------Funciones del algoritmo Dijkstra-------------------------------------------

// Aplica el algoritmo de Dijkstra
void aplicar_dijkstra(char V[N], char S[N], char VS[N], int D[N], int M[N][N]) {
    int i;
    int v;
    
    // inicializar vector D[] según datos de la matriz M[][]
    inicializar_vector_D(D, M, 0);

    cout << "---------Estados iniciales---------------------------------------" << endl;
    imprimir_matriz(M);
    cout << endl;
    imprimir_vector_caracter(S, "S");
    imprimir_vector_caracter(VS, "VS");
    imprimir_vector_entero(D);
    cout << "------------------------------------------------------------------" << endl << endl;

    // agrega primer vértice
    cout << "> Agrega el primer valor V[0] a S[] y actualiza VS[]" << endl << endl;
    agrega_vertice_a_S(S, V[0]);
    imprimir_vector_caracter(S, "S");
    
    actualizar_VS(V, S, VS);
    imprimir_vector_caracter(VS, "VS");
    imprimir_vector_entero(D);

    for (i = 1; i < N; i++) {
        // elige un vértice en v de VS[] tal que D[v] sea el mínimo
        cout << "\n> Elige vertice menor en VS[] segun valores en D[]" << endl;
        cout << "> Lo agrega a S[] y actualiza VS[]" << endl;
        v = elegir_vertice(VS, D, V);

        agrega_vertice_a_S(S, v);
        imprimir_vector_caracter(S, "S");

        actualizar_VS(V, S, VS);
        imprimir_vector_caracter(VS, "VS");

        actualizar_pesos(D, VS, M, V, v);
        imprimir_vector_entero(D);
    }
}

// Agrega un vértice a S[]
void agrega_vertice_a_S(char S[N], char vertice) {
    for (int i = 0; i < N; i++) {
        if (S[i] == ' ') {
            S[i] = vertice;
            return;
        }
    }
}

// Actualiza VS[] cada vez que se agrega un elemento a S[]
void actualizar_VS(char V[N], char S[N], char VS[N]) {
    int k = 0;
    inicializar_vector_caracter(VS, 0);
    
    for (int j = 0; j < N; j++) {
        if (busca_caracter(V[j], S) != TRUE) {
            VS[k] = V[j];
            k++;
        }
    }
}

// Elige vértice con menor peso en VS[]
int elegir_vertice(char VS[N], int D[N], char V[N]) {
    int menor = 0;
    char vertice = ' ';

    for (int i = 0; VS[i] != ' ' && i < N; i++) {
        int peso = D[buscar_indice_caracter(V, VS[i])];
        if (peso != -1 && peso != 0) {
            if (i == 0 || peso < menor) {
                menor = peso;
                vertice = VS[i];
            }
        }
    }
    
    cout << "\nVértice: " << vertice << endl;
    return vertice;
}

// Actualiza los pesos en D[] para los vértices en VS[]
void actualizar_pesos(int D[N], char VS[N], int M[N][N], char V[N], char v) {
    int indice_v = buscar_indice_caracter(V, v);

    cout << "\n> Actualiza pesos en D[]" << endl;
    
    for (int i = 0; VS[i] != ' '; i++) {
        if (VS[i] != v) {
            int indice_w = buscar_indice_caracter(V, VS[i]);
            D[indice_w] = calcular_minimo(D[indice_w], D[indice_v], M[indice_v][indice_w]);
        }
    }
}

//-------------------------Funciones auxiliares------------------------------------------------------

// Busca el índice del caracter consultado
int buscar_indice_caracter(char V[N], char caracter) {
    for (int i = 0; i < N; i++) {
        if (V[i] == caracter)
            return i;
    }
    return -1;
}

// Verifica si un caracter está en el vector
int busca_caracter(char c, char vector[N]) {
    for (int j = 0; j < N; j++) {
        if (c == vector[j]) {
            return TRUE;
        }
    }
    return FALSE;
}

// Calcula el mínimo entre tres valores
int calcular_minimo(int dw, int dv, int mvw) {
    if (dw == -1) {
        return (dv != -1 && mvw != -1) ? dv + mvw : -1;
    } else {
        if (dv != -1 && mvw != -1) {
            return (dw <= (dv + mvw)) ? dw : dv + mvw;
        } else {
            return dw;
        }
    }
}

//---------------------Funciones de impresión--------------------------------------------------

// Imprime el contenido de un vector de caracteres
void imprimir_vector_caracter(char vector[N], const char *nomVector) {
    for (int i = 0; i < N; i++) {
        cout << nomVector << "[" << i << "]: " << vector[i] << " ";
    }
    cout << endl;
}

// Imprime el contenido de un vector de enteros
void imprimir_vector_entero(int vector[N]) {
    for (int i = 0; i < N; i++) {
        cout << "D[" << i << "]: " << vector[i] << " ";
    }
    cout << endl;
}

// Imprime el contenido de una matriz bidimensional de enteros
void imprimir_matriz(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "matriz[" << i << "," << j << "]: " << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Genera y muestra el grafo a partir de una matriz bidimensional de enteros
void imprimir_grafo(int matriz[N][N], char vector[N]) {
    ofstream fp("grafo.txt");
    fp << "digraph G {" << endl;
    fp << "graph [rankdir=LR]" << endl;
    fp << "node [style=filled fillcolor=yellow];" << endl;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && matriz[i][j] > 0) {
                fp << vector[i] << " -> " << vector[j] << " [label=" << matriz[i][j] << "];" << endl;
            }
        }
    }
    
    fp << "}" << endl;
    fp.close();

    system("dot -Tpng grafo.txt -o grafo.png");
    system("explorer grafo.png ");
}

//---------------------------Función principal---------------------------------------------

int main() {
    char V[N], S[N], VS[N];
    int D[N];
    int M[N][N];

    // V[] Representa los nodos del grafo.
    // S[] Representa los nodos ya visitado.
    // VS[] Representa los nodos aun no visitado.
    // D[] Almacena las distancias minimas desde el nodo de origen.
    // M[][] Representa la matriz de distancias.

    // Inicialización
    inicializar_vector_caracter(V, 0);
    inicializar_vector_caracter(S, 0);
    inicializar_vector_caracter(VS, 0);
    
    leer_nodos(V, N);
    leer_matriz_distancias(V, M);
    imprimir_matriz(M);

    // El origen es el nodo desde el cual se calcularán las distancias mínimas
    char origen;
    cout << "Ingrese el vértice origen 'a' , 'b', 'c', 'd', 'e' : " << endl;
    cin >> origen;

    // Convertir el origen a índice
    int indice_origen = buscar_indice_caracter(V, origen);

    if (indice_origen == -1) {
        cout << "Vertice origen no válido." << endl;
        return 1;
    }

    aplicar_dijkstra(V, S, VS, D, M);

    // Imprime el grafo final y las distancias mínimas
    imprimir_grafo(M, V);
    imprimir_vector_entero(D);

    return 0;
}


