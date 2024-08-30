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


void addPaciente(Paciente*& head, const string& nombre, int edad, int peso, double altura){
    Paciente* newPaciente = new Paciente();
    newPaciente -> nombre = nombre;
    newPaciente -> edad = edad;
    newPaciente -> peso = peso;
    newPaciente -> altura = altura;
    newPaciente -> next = head;
    head = newPaciente;

};


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


void promedio_edad(const Paciente* head){
    int sum_edades = 0;
    int num_pacientes = 0;
    const Paciente* nodo = head;

    while(nodo != nullptr){
        sum_edades += nodo -> edad;
        num_pacientes++;
        nodo = nodo -> next;
    }
    double prom_edad = sum_edades / num_pacientes;

    cout << "El promedio de edad de los pacientes es de: " << prom_edad << " años." << endl;

}

void promedio_peso(const Paciente* head){
    int sum_pesos = 0;
    int num_pacientes= 0;
    const Paciente* nodo = head;

    while(nodo != nullptr){
        sum_pesos += nodo -> peso;
        num_pacientes++;
        nodo = nodo -> next;
    }
    double prom_peso = sum_pesos / num_pacientes;
    cout << "El promedio de peso en los pacientes es de: " << prom_peso << "Kg" << endl;
    
    cout << " " << endl;

}

void calculo_imc(const Paciente* head){
        const Paciente* nodo = head;

    while(nodo != nullptr){
        int peso = nodo -> peso;
        double altura = nodo -> altura;
        double imc = peso / (altura * altura);

        
        cout << "El IMC de " << nodo -> nombre << " es " << imc << endl;

        nodo = nodo -> next;
    }
}


int main(){
    Paciente* head = nullptr;

    addPaciente(head,"Camila", 45, 66, 1.73);
    addPaciente(head,"Juan", 5, 15, 0.90);
    addPaciente(head,"Ana", 17, 45, 1.55);

    printPaciente(head);

    promedio_edad(head);

    promedio_peso(head);

    calculo_imc(head);

    removePaciente(head, "Juan");


    //-------------Luego de eliminar un paciente---------------

    cout << " " << endl;

    printPaciente(head);

    promedio_edad(head);

    promedio_peso(head);
    
    calculo_imc(head);

    while(head != nullptr){
        Paciente* temp = head;
        head = head -> next;
        delete temp;
    }

    return 0;

}