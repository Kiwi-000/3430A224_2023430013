#include <iostream>
#include <ctime>   // Para time()
#include <chrono>  // Para medir el tiempo

using namespace std;


//Quick Sort---------------------------------------------------------------------
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}


//Selection Sort-------------------------------------------------------------------------
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

/* int main() {
    const int SIZE = 10000; // Tamano del arreglo
    int arr[SIZE];

    // Inicializa la semilla para numeros aleatorios
    srand(static_cast<unsigned int>(time(0)));

    // ------------------------------------------

    // Llamar a la funcion para llenar el arreglo
    llenarArreglo(arr, SIZE);

    std::cout << "\nArreglo de numeros enteros:\n";
    // Llamar a la funcion para mostrar el arreglo
    mostrarArreglo(arr, SIZE);
    
    // Inicio ejecucion
    auto start = std::chrono::high_resolution_clock::now(); // Iniciar el cronometro
    // Llamar a la funcion Burbuja Menor
    burbuja_menor(arr, SIZE);
    // Final ejecucion
    auto end = std::chrono::high_resolution_clock::now(); // Detener el cronometro
    // Calcular la duracion
    std::chrono::duration<double> duration = (end - start);

    std::cout << "\nArreglo de numeros ordenados:\n";
    // Llamar a la funcion para mostrar el arreglo
    mostrarArreglo(arr, SIZE);

    // Mostrar el tiempo de ejecución
    std::cout << "\nTiempo de ejecucion: " << duration.count() << " segundos" << std::endl;

    return 0;
}  */