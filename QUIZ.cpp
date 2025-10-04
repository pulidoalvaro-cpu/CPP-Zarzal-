/******************************************************************************
 1.1: Escribe un programa en C++ que declare tres variables: una de tipo entero, una de
 tipo flotante y una de tipo carácter. Inicializa las variables con valores adecuados e imprime sus
 valores en consola.
 1.2: Explica la diferencia entre los tipos de datos int, float y char en C++. ¿Cuándo es
 recomendable usar cada uno?
 
 2.1: Escribe un programa en C++ que reciba dos números enteros por teclado y muestre
 la suma, resta, multiplicación, división y módulo de estos dos números
 
*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;


int main(){
    cout<<"1.1 Crea un programa que declare tres variables,una de tipo entero, una de tipo flotante y una de tipo carácter.\n";
    //Declarar variables
    int entero = 27;
    float flotante = 4.9;
    string caracter = "Alvaro";
     
    cout<<"   "<<caracter<<" tiene una edad de "<<entero<<" y sacara una nota de "<<flotante<<" en el parcial.";
    
    cout<<"\n 2.2 Explica la diferencia entre los tipos de datos int, float y char en C++.¿Cuándo esrecomendable usar cada uno?\n";
    
    cout<<" Los tipos de datos int se aconseja trabajar con ellos cuando se requiera trabajar con valores enteros.\n";
    cout<<" Se aconseja trabajar con float cuando se requiera trabajar con valores decimales y se requiera un resultado mas aproximado.\n";
    cout<<" Se utiliza char cuando se requiera trabajar con valores de tipo caracter, tambien sirve para separar los caracteres de una palabra\n";

    cout<<" 2.1: Escribe un programa en C++ que reciba dos números enteros por teclado y muestrela suma,";
    cout<<" resta, multiplicación, división y módulo de estos dos números\n";
    
    int primero;
    int segundo;
    cout<< " Ingrese el primer numero:";
    cin>> primero;
    cout<< " Ingrese el segundo numero:";
    cin>> segundo;
    
    //operaciones
    int suma =  primero + segundo;
    int resta =  primero - segundo;
    int mult =  primero * segundo;
    double divi =  primero / segundo;
    int mod =  primero % segundo;
    
    cout << "\n La suma de los dos numeros es:  " << suma<<"\n";
    cout << "La resta de los dos numeros es:  " << resta<<"\n";
    cout << "La multiplicacion de los dos numeros es:  " << mult<<"\n";
    cout << "La division de los dos numeros es:  " << divi<<"\n";
    cout << "el modulo de los dos numeros es:  " << resta<<"\n";
    
    cout<<" 2.2: ¿Cuál es la diferencia entre los operadores de comparación == y != en C++? Da un ejemplo de su uso\n";
    cout<<"  el == se utiliza para decir que un valor es exactamente igual a otro \n";
    int a;
    float c;
    a = 5;
    c == a;
    cout<<" b es igual a c: "<<c<<"\n "; 
    cout<<" el != se utiliza para decir que un valor no es igual a otro \n";
    
    
    
    
    
   





    





    
    




 
    
    
    return 0;
}


