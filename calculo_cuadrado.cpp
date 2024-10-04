#include <iostream>

int cuadrado(int x){
    return x * x;
}

void print_cuadrado(int x){
    std::cout << x << " al cuadrado es " << cuadrado(x) ;
}

int main(){
    print_cuadrado(2);

}