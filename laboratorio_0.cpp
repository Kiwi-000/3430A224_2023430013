#include <iostream>
#include <string>

//funcion para ver si el número es par o impar
bool par_impar(int numero){
    return numero % 2 == 0;
}

//funcion para determinar la longitud
int calcular_longitud(std::string texto){
    int longitud = 0;

    for(char c : texto){
        longitud ++;
    }

    return longitud;
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
    std::cout <<"____________________________________________________________________" << std::endl;

    std::string texto_ejemplo = "Hola Mundo!";
    std::cout << texto_ejemplo << std::endl;

    int longitud_ejemplo = calcular_longitud(texto_ejemplo);
    std::cout << "La longitud de el texto anterior es de: " << longitud_ejemplo << std::endl;

    std::cout <<"____________________________________________________________________" << std::endl;

    std::string texto;

    std::cout << "Ingrese un texto: " << std::endl;
    std::getline(std::cin, texto);
    //std::cout << texto;
    
    int longitud = calcular_longitud(texto);
    std::cout << "La longitud de ese texto es de: " << longitud;


    return 0; 
}