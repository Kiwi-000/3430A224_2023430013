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
    
    Paciente persona[3];

    persona[0].nombre = "Camila";
    persona[0].edad = 45;
    persona[0].peso = 66;
    persona[0].altura = 1.70;

    persona[1].nombre = "Juan";
    persona[1].edad = 5;
    persona[1].peso = 15;
    persona[1].altura = 0.90;

    persona[2].nombre = "Ana";
    persona[2].edad = 17;
    persona[2].peso = 45;
    persona[2].altura = 1.55;
            
            
    for ( int i= 0; i < 3; ++i){
        cout <<"Nombre: "<< persona[i].nombre << endl;
        cout << "Edad: " << persona[i].edad << endl;
        cout << "Peso: " << persona[i].peso << endl;
        cout << "Altura: " << persona[i].altura << endl;
        cout << " " << endl;

    };

    return 0;

}

