#include <iostream>
#include <string>

using namespace std;

struct Paciente{
    string nombre;
    int edad;
    int peso;
    double altura;

    Paciente* next;
};

//Agregar paciente
void addPaciente(Paciente*& head, const string& nombre, int edad, int peso, double altura){
    Paciente* newPaciente = new Paciente();
    newPaciente -> nombre = nombre;
    newPaciente -> edad = edad;
    newPaciente -> peso = peso;
    newPaciente -> altura = altura;
    newPaciente -> next = head;
    head = newPaciente;

};

//Eliminar paciente
void removePaciente(Paciente*& head, const string& nombre){
    Paciente* nodo = head;
    Paciente* previo = nullptr;

    while(nodo != nullptr && nodo -> nombre != nombre){
        previo = nodo;
        nodo = nodo -> next;
    }

    if (nodo != nullptr){
        if(previo== nullptr){
            head = nodo ->next;
        }
        else{
            previo ->next = nodo ->next;
        }
        delete nodo;
    }

}

//Imprimir pacientes
void printPaciente(const Paciente* head){
    const Paciente* nodo = head;

    while(nodo != nullptr){
        cout <<"Nombre: "<< nodo -> nombre << endl;
        cout << "Edad: " << nodo -> edad << endl;
        cout << "Peso: " << nodo -> peso<< endl;
        cout << "Altura: " << nodo -> altura << endl;
        cout << " " << endl;

        nodo = nodo -> next;
    }
}

int main(){
    Paciente* head = nullptr;

    addPaciente(head,"Camila", 45, 66, 1.70);
    addPaciente(head,"Juan", 5, 15, 0.90);
    addPaciente(head,"Ana", 17, 45, 1.55);

    printPaciente(head);

    removePaciente(head, "Juan");

    printPaciente(head);

    while(head != nullptr){
        Paciente* temp = head;
        head = head -> next;
        delete temp;
    }

    return 0;

}
