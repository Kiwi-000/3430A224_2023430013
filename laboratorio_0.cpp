#include <iostream>
#include <string>

//funcion para ver si el número es par o impar
bool par_impar(int numero){
    return numero % 2 == 0;
}


int main() {

    //Evaluar número par o impar 
    int numero;

    std::cout << "Ingrese un número: " ;
    std::cin >> numero;

    if (par_impar(numero)){
        std::cout << "El número ingresado es par."<< std::endl;
    }
    else{
        std::cout << "El número ingresado es impar."<< std::endl;
    }

    // para que no de problemas con el getline
    std::cin.ignore();

    // Texto
    std::string texto;

    std::cout << "Ingrese un texto: ";
    std::getline(std::cin, texto);
    std::cout << texto;
    
}