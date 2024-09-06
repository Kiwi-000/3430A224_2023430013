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
    cout << "---------------------------------------------------" << endl;
    cout << "Nombre: " << p.nombre << endl;
    cout << "Edad: " << p.edad << " años" << endl;
    cout << "Altura: " << p.altura << " m" << endl;
    cout << "Peso: " << p.peso << " kg" << endl;
    cout << "IMC: " << p.imc << endl;
    cout << "A1C: " << p.a1c << endl;
    cout << "Prioridad: " << p.prioridad << endl;
    cout << " " << endl;
}

// Buscar pacientes
void buscarPacientes(const vector<Paciente> &pacientes, float imcMin, float imcMax, float a1cMin, float a1cMax) {
    cout << "---------------------------------------------------" << endl;
    cout << "Pacientes con IMC entre " << imcMin << " y " << imcMax << " y A1C entre " << a1cMin << " y " << a1cMax << ":" << endl;
    for (const auto &p : pacientes) {
        if (p.imc >= imcMin && p.imc <= imcMax && p.a1c >= a1cMin && p.a1c <= a1cMax) {
            mostrarPaciente(p);
        }
    }
}

void mostrarMenu() {
    cout << "---------------------------------------------------" << endl;
    cout << "Menu de Gestion de Pacientes" << endl;
    cout << "1. Mostrar todos los pacientes" << endl;
    cout << "2. Buscar pacientes por IMC y A1C" << endl;
    cout << "3. Mostrar pacientes en cola de prioridad" << endl;
    cout << "4. Atender al siguiente paciente" << endl;
    cout << "5. Salir" << endl;
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
    priority_queue<Paciente, vector<Paciente>, ComparadorPrioridad> copiaCola;  
    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
        case 1:
            cout << "---------------------------------------------------" << endl;
            cout << "Lista de todos los pacientes:" << endl;
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
            cout << "---------------------------------------------------" << endl;
            cout << "Pacientes en cola de prioridad:" << endl;
            copiaCola = cola; 
            while (!copiaCola.empty()) {
                mostrarPaciente(copiaCola.top());
                copiaCola.pop();
            }
            break;
        case 4:
            if (!cola.empty()) {
                cout << "---------------------------------------------------" << endl;
                cout << "Atendiendo al siguiente paciente:" << endl;
                mostrarPaciente(cola.top());
                cola.pop();
            } else {
                cout << "No hay pacientes en la cola." << endl;
            }
            break;
        case 5:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida, intente nuevamente." << endl;
        }
    } while (opcion != 5);

    return 0;
}

