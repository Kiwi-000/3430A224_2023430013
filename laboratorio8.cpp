#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
#include <chrono>  // Para medir el tiempo
#include <limits>  // Para manejar errores de entrada

using namespace std;

// Función para mover valores del arreglo en el ordenamiento
//Para 
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

//......QUICKSORT.................................

// 
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Ordenamiento
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

//......SELECTIONSORT...............................

// Método de ordenamiento SelectionSort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}


// Ingresar un valor de N 
int ingresarN() {
    int N;
    while (true) {
        cout << "Ingrese el tamano del conjunto a ordenar: ";
        cin >> N;

        //Comprobar que N sea un numero entero positivo
        if (cin.fail() || N <= 0 || cin.peek() != '\n') {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Error: Debe ingresar un numero entero positivo." << endl;
        } 
        else {
            break; 
        }
    }
    return N;
}

// Llenar el arreglo con valores aleatorios entre 1 y 100
void llenarArreglo(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100 + 1;
    }
}

// Mostrar los valores del arreglo
void mostrarArreglo(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Inicializar la semilla para los números aleatorios
    srand(time(0));

    // Ingresar el tamaño del arreglo
    int N = ingresarN();

    // Crear y llenar el arreglo
    int* arrOriginal = new int[N];
    llenarArreglo(arrOriginal, N);

    // Mostrar el arreglo original
    cout << "................................." << endl;
    cout << "Conjunto original:" << endl;
    mostrarArreglo(arrOriginal, N);

    // Crear copias del arreglo para cada método de ordenamiento
    int* arrQuick = new int[N];
    int* arrSelection = new int[N];
    copy(arrOriginal, arrOriginal + N, arrQuick);
    copy(arrOriginal, arrOriginal + N, arrSelection);

//...................................................................................................

    // Medir tiempo de ordenamiento con QuickSort
    auto startQuick = chrono::high_resolution_clock::now();
    quickSort(arrQuick, 0, N - 1);
    auto endQuick = chrono::high_resolution_clock::now();
    auto durationQuick = chrono::duration_cast<chrono::milliseconds>(endQuick - startQuick).count();

    // Medir tiempo de ordenamiento con SelectionSort
    auto startSelection = chrono::high_resolution_clock::now();
    selectionSort(arrSelection, N);
    auto endSelection = chrono::high_resolution_clock::now();
    auto durationSelection = chrono::duration_cast<chrono::milliseconds>(endSelection - startSelection).count();

//...................................................................................................

    // Mostrar arreglos ordenados
    cout << "................................." << endl;

    cout << "\nConjunto ordenado con QuickSort:" << endl;
    mostrarArreglo(arrQuick, N);
    cout << "Tiempo de QuickSort: " << durationQuick << " ms" << endl;

    cout << "\nConjunto ordenado con SelectionSort:" << endl;
    mostrarArreglo(arrSelection, N);
    cout << "Tiempo de SelectionSort: " << durationSelection << " ms" << endl;

    // Liberar memoria
    delete[] arrOriginal;
    delete[] arrQuick;
    delete[] arrSelection;

    return 0;
}

