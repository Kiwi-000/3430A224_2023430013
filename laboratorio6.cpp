// M = matriz de adyacencia ; N = parametro n° de nodos
// V = los nodos ; S = nodos ya procesados
// VS = conjuntos de nodos aun no procesados ; D = distancias mínimas 

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

//leer nodos
void leer_nodos (char vector[N], int N) {
  int inicio = 34;
  for (i=0; i<N; i++) {
    vector[i] = inicio+i;
  }
}

// copia contenido inicial a D[] desde la matriz M[][].
void inicializar_vector_D (int D[N], int M[N][N]) {
  int col;
  
  for (col=0; col<N; col++) {
    D[col] = M[0][col];
  }
}

// inicializa un vector. recibe el vector como un puntero.
void inicializar_vector_caracter (string *vector, int n) {
    int col;
  
    // recorre el vector.
    for (col=0; col<n; col++) {
        vector[col] = ' ';
    }
}

// imprime un vector. recibe el vector como un puntero.
void imprimir_vector_caracter(string *vector, int n) {
    cout << endl;
    for (int i=0; i<n; i++) {
        cout << "vector[" << i << "]: " << vector[i] << " ";
    }
    cout << endl;
}

// inicializa matriz nxn. recibe puntero a la matriz.
void inicializar_matriz_enteros (int **matriz, int n) {
    for (int fila=0; fila<n; fila++) {
        for (int col=0; col<n; col++) {
            matriz[fila][col] = -1;
        }
    }
}

// imprime matriz.
void imprimir_matriz(int **matriz, int n) {
    cout << endl;
    for (int fila=0; fila<n; fila++) {
        for (int col=0; col<n; col++) {
            cout << matriz[fila][col] << " ";
        }
        cout << endl;
    }
}

// Aplica el algoritmo de Dijkstra
void aplicar_dijkstra (char V[N], char S[N], char VS[N], int D[N], int M[N][N]) {
    int v;

    inicializar_vector_D(D, M);

    cout << "---------Estados iniciales---------------------------------------\n";
    imprimir_matriz(M);
    imprimir_vector_caracter(S, "S");
    imprimir_vector_caracter(VS, "VS");
    imprimir_vector_entero(D);
    cout << "------------------------------------------------------------------\n\n";

    // Agrega el primer vértice
    cout << "> agrega primer valor V[0] a S[] y actualiza VS[]\n\n";
    agrega_vertice_a_S(S, V[0]);
    imprimir_vector_caracter(S, "S");
    actualizar_VS(V, S, VS);
    imprimir_vector_caracter(VS, "VS");
    imprimir_vector_entero(D);

    for (int i = 1; i < N; i++) {
        // Elige el vértice de VS[] con el menor peso en D[]
        cout << "\n> elige vertice menor en VS[] segun valores en D[]\n";
        v = elegir_vertice(VS, D, V);

        // Agrega el vértice a S y actualiza VS
        agrega_vertice_a_S(S, v);
        imprimir_vector_caracter(S, "S");
        actualizar_VS(V, S, VS);
        imprimir_vector_caracter(VS, "VS");
        actualizar_pesos(D, VS, M, V, v);
        imprimir_vector_entero(D);
    }
}



int main(int argc, char **argv) {
    int D[N]
    char V[N], S[N], VS[N];
    //definir N 
    int N
    
    // valida cantidad de parámetros mínimos.
    if (argc<2) {
        cout << "Uso: \n./matriz n" << endl;
        return -1;
    }

    // convierte string a entero.
    int  N = atoi(argv[1]);

    //definir matriz
    M[][] = N[]
    if (N < 2) {
        cout << "El número de nodos es invalido" << endl;
        return -1;
    }


}

