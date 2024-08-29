#include <iostream>
#include <string>

using namespace std;

struct Paciente{
    string nombre;
    int edad;
    int peso;
    double altura;
};

int main(){


    Paciente persona1 = {"Camila", 45, 66, 1.70 };
    Paciente persona2 = {"Juan", 5, 15, 0.90 };
    Paciente persona3 = {"Ana", 17, 45, 1.55 };

    cout <<"Nombre: "<< persona1.nombre << endl;
    cout << "Edad: " << persona1.edad << endl;
    cout << "Peso: " << persona1.peso << endl;
    cout << "Altura: " << persona1.altura << endl;
    cout << " " << endl;

    cout <<"Nombre: "<< persona2.nombre << endl;
    cout << "Edad: " << persona2.edad << endl;
    cout << "Peso: " << persona2.peso << endl;
    cout << "Altura: " << persona2.altura << endl;
    cout << " " << endl;

    cout <<"Nombre: "<< persona3.nombre << endl;
    cout << "Edad: " << persona3.edad << endl;
    cout << "Peso: " << persona3.peso << endl;
    cout << "Altura: " << persona3.altura << endl;
    cout << " " << endl;

    return 0;

}

