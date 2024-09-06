#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

struct Paciente {
    string nombre;
    int edad;
    float altura; 
    float peso;   
    float imc;
    float a1c;
    int prioridad;

    // Calcular el IMC 
    void calcularIMC() {
        imc = peso / (altura * altura);
    }

    // Calcular la prioridad del paciente basado en IMC y A1C
    void calcularPrioridad() {
        if (a1c > 6.5) {
            prioridad = 3; 
        } else if (a1c >= 5.7) {
            prioridad = 2; 
        } else {
            prioridad = 1; 
        }
        if (imc > 30) {
            prioridad += 1; 
        }
    }
};

struct ComparadorPrioridad {
    bool operator()(const Paciente &a, const Paciente &b) {
        return a.prioridad < b.prioridad; 
    }
};

vector<Paciente> cargarPacientesDesdeCSV(const string &filename) {
    vector<Paciente> pacientes;
    ifstream archivo(filename);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << filename << endl;
        return pacientes;
    }

    string linea;
    getline(archivo, linea); 
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombre, edad, altura, peso, a1c;
        getline(ss, nombre, ',');
        getline(ss, edad, ',');
        getline(ss, altura, ',');
        getline(ss, peso, ',');
        getline(ss, a1c, ',');

        Paciente p;
        p.nombre = nombre;
        p.edad = stoi(edad);
        p.altura = stof(altura);
        p.peso = stof(peso);
        p.a1c = stof(a1c);
        p.calcularIMC();
        p.calcularPrioridad();
        pacientes.push_back(p);
    }

    archivo.close();
    return pacientes;
}

// Mostrar datos de un paciente
void mostrarPaciente(const Paciente &p) {
    cout << "Nombre: " << p.nombre << ", Edad: " << p.edad
         << ", Altura: " << p.altura << " m, Peso: " << p.peso << " kg, IMC: "
         << p.imc << ", A1C: " << p.a1c << ", Prioridad: " << p.prioridad << endl;
}

// Buscar pacientes 
void buscarPacientes(const vector<Paciente> &pacientes, float imcMin, float imcMax, float a1cMin, float a1cMax) {
    cout << "Pacientes con IMC entre " << imcMin << " y " << imcMax << " y A1C entre " << a1cMin << " y " << a1cMax << ":\n";
    for (const auto &p : pacientes) {
        if (p.imc >= imcMin && p.imc <= imcMax && p.a1c >= a1cMin && p.a1c <= a1cMax) {
            mostrarPaciente(p);
        }
    }
}


void mostrarMenu() {
    cout << "\nMenu de Gestion de Pacientes\n";
    cout << "1. Mostrar todos los pacientes\n";
    cout << "2. Buscar pacientes por IMC y A1C\n";
    cout << "3. Mostrar pacientes en cola de prioridad\n";
    cout << "4. Atender al siguiente paciente\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    string archivoCSV = "patientlist.csv"; 
    vector<Paciente> pacientes = cargarPacientesDesdeCSV(archivoCSV);
    priority_queue<Paciente, vector<Paciente>, ComparadorPrioridad> cola;

    for (const auto &p : pacientes) {
        cola.push(p);
    }

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
        case 1:
            cout << "\nLista de todos los pacientes:\n";
            for (const auto &p : pacientes) {
                mostrarPaciente(p);
            }
            break;
        case 2: {
            float imcMin, imcMax, a1cMin, a1cMax;
            cout << "Ingrese el IMC minimo y maximo: ";
            cin >> imcMin >> imcMax;
            cout << "Ingrese el A1C minimo y maximo: ";
            cin >> a1cMin >> a1cMax;
            buscarPacientes(pacientes, imcMin, imcMax, a1cMin, a1cMax);
            break;
        }
        case 3:
            cout << "\nPacientes en cola de prioridad:\n";
            priority_queue<Paciente, vector<Paciente>, ComparadorPrioridad> copiaCola = cola;
            while (!copiaCola.empty()) {
                mostrarPaciente(copiaCola.top());
                copiaCola.pop();
            }
            break;
        case 4:
            if (!cola.empty()) {
                cout << "\nAtendiendo al siguiente paciente:\n";
                mostrarPaciente(cola.top());
                cola.pop();
            } else {
                cout << "No hay pacientes en la cola.\n";
            }
            break;
        case 5:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción no válida, intente nuevamente.\n";
        }
    } while (opcion != 5);

    return 0;
}
