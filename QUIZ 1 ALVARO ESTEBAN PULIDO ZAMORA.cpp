/******************************************************************************

QUIZ 1
ALVARO ESTEBAN PULIDO ZAMORA
                              

*******************************************************************************/
#include <iostream>
using namespace std;

int main() {
   
    cout<<"--Variables y tipos de datos--\n\n";
    cout<<"  Pregunta 1.1\n";
    
    int numero_entero= 7;
    float numero_flotante= 10.5;
    char caracter= 'A';

    cout<<"  Valor tipo entero: "<<numero_entero<<"\n";
    cout<<"  Valor tipo flotante: "<<numero_flotante<<"\n";
    cout<<"  Valor tipo caracter: "<<caracter<<"\n\n";

    cout<<"  Pregunta 1.2\n";
    
    cout<<"  int: Almacena numeros enteros, normalmente se utilizan para obtener datos simples como la edad;\n";
    cout<<"  tambien para hacer contadores y bucles\n\n";
    cout<<"  float: Almacena numeros con decimales, se utiliza para hacer calculos con una aproximacion mas\n";
    cout<<"  detallada como lo es el precio de un producto\n\n";
    cout<<"  char: Almacena un solo caracter, ya sea un numero, letra o simbolo, entre sus usos esta\n";
    cout<<"  como separador para organizar la informacion a la hora de mostrarla al usuario\n\n";
    
    cout<<"--Operadores--\n\n";
    cout<<"  Pregunta 2.1\n";

    int num1, num2;
    cout<<"  Ingresa el primer numero entero: ";
    cin>> num1;
    cout<<"  Ingresa el segundo numero entero: ";
    cin>> num2;

    cout<<"  Resultados de las Operaciones:\n";
    cout<<"  Suma: "<< num1 + num2 <<"\n";
    cout<<"  Resta: "<< num1 - num2 << "\n";
    cout<<"  Multiplicacion: "<< num1 * num2<< "\n";
    cout<<"  Division: "<< (float)num1 / num2<<"\n"; 
    
    if (num2 != 0) {
        cout<<"  Modulo: "<< num1 % num2<<"\n\n";;
    } else {
        cout<<"  No esta definida la division por cero"<<"\n\n";;
    }

    cout<<"  Pregunta 2.2\n";
    
    cout<<"  Tanto == y != son operadores de comparacion que devuelven un valor verdadero o falso (booleano)\n";
    cout<<"  Ejemplo: \n\n";
    cout<<"  X = 5\n";
    cout<<"  Y = 10\n\n";
    cout<<"  Usando ==\n";
    cout<<"  if (x == y){   Esto es false (falso) y no se ejecuta\n\n";
    cout<<"  Usando !=\n";
    cout<<"  if (x != y){\n"; 
    cout<<"  cout <<\" Esto es verdadero (true) y se ejecuta\";\n\n";
    
    cout<<"  Pregunta 2.3\n";
    
    cout<<"  Los operadores logicos se utilizan para establecer multiples condiciones o para negar condiciones.\n";
    cout<<"  Ejemplo: \n\n"; 
    cout<<"  int edad = 25; \n";  
    cout<<"  bool estudiante = true; \n\n"; 
    cout<<"  if ((edad >= 18) && (estudiante == true)){\n";
    cout<<"  cout <<\" Es verdadero, cumple las dos condiciones\";\n\n";
    cout<<"  if ((edad <= 9) || (estudiante == true)){\n";
    cout<<"  cout <<\" Es verdadero, cumple almenos una de las condiciones\";\n\n";
    cout<<"  if (!estudiante)  // Es falso, se niega el booleano\n\n";
    

    cout<<"  Pregunta 3.1\n";
    
    int edad;
    cout<<"  Ingresa tu edad: ";
    cin>> edad;

    if (edad >= 18){
        cout<<"  Eres mayor de edad.\n";
    }else{
        cout<<"  Eres menor de edad.\n";
    }

    cout<<"\n  Pregunta 3.2\n";
    cout<<"  La estructura else if se compone de 3 partes (condiciones):\n\n";
    cout<<"  if: el programa verifica si la condicion del if es verdadera para ejecutar\n";
    cout<<"  dicho bloque de codigo, sino lo es pasa a la condicion del else if\n\n";
    cout<<"  else if: el programa verifica si la condicion del else if es verdadera para \n";
    cout<<"  ejecutar dicho bloque de codigo, si es falsa repite el proceso si hay otros else if\n\n";
    cout<<"  else: si todas las condiciones anteriores son falsas, entonces se ejecuta \n";
    cout<<"  el bloque de codigo del else\n\n";
    cout<<"  Ejemplo:\n";
    cout<<"  int nota = 3;\n";
    cout<<"  string calificacion;\n\n";
    cout<<"  if (nota >= 4.5){  // Es falso, no se cumple la condicion\n";
    cout<<"     calificacion = \"Excelente\";\n\n";
    cout<<"  }else if(nota >= 4) { // todavia no se cumple la condicion\n";
    cout<<"     calificacion = \"Sobresaliente\";\n\n";
    cout<<"  }else if (nota >= 3) { // Se cumple la condicion\n";
    cout<<"     calificacion = \"Aceptable\";\n\n";
    cout<<"  }else {\n";
    cout<<"     calificacion = \"Reprobado\";\n\n";
    cout<<"  }\n";
    cout<<"  cout <<\" Resultado de 3: Calificacion Aceptable\";\n\n";


    cout<<"\n  Pregunta 4.1\n";
    cout<<"  Numeros del 1 al 10: ";
    for (int i = 1; i <= 10; ++i){
        cout<<i <<(i == 10 ? "" : ", ");
    }
    
    cout<<"\n\n  Pregunta 4.2\n";
    cout<<"  Numeros del 10 al 1: ";
    int j = 10;
    while (j >= 1) {
        cout << j << (j == 1 ? "" : ", ");
        j--;
    }

    cout<<"\n\n  Pregunta 4.3\n";
    cout<<"  Numeros pares entre 1 y 20: ";
    int k = 2;
    do{
        cout << k << (k >= 20 ? "" : ", ");
        k += 2; 
    }while (k <= 20);
    

    cout<<"\n\n  Pregunta 5.1\n";
    
    const int tamaño_array = 5;
    int array_unidimensional[tamaño_array];
    cout<<"  Por favor, ingresa " << tamaño_array << " numeros enteros:\n";

    //Llenar el array
    for (int i = 0; i < tamaño_array; ++i) {
        cout<<"  Elemento [" << i << "]: ";
        cin>> array_unidimensional[i];
    }

    //Imprimir el array
    cout<<"\n  Los elementos ingresados son: [";
    for (int i = 0; i < tamaño_array; ++i) {
        cout << array_unidimensional[i] << (i == tamaño_array - 1 ? "" : ", ");
    }
    cout << "]\n";

    cout<<"\n  Pregunta 5.2\n";
    cout<<"  Un array bidimensional es un array de arrays, organizando los datos en filas y columnas FxC:\n";
    cout<<"  Para crear uno, Se especifica el numero de filas y columnas, ejemplo:\n\n";
    cout<<"  int matriz2x3[2][3]= {\n";
    cout<<"  {1, 2, 3}, // Fila 0\n";
    cout<<"  {4, 5, 6}  // Fila 1\n\n";
    cout<<"  Para acceder a sus elementos, debes tener en cuenta la ubicacion de dicho valor en las filas y columnas\n";
    cout<<"  int valor = matriz_2x3[0][1]; // el elemento es 2, guardas dicho elemento en una variable\n";
    cout<<"  cout <<\" El elemento [0][1]de la matriz es:\" << valor; //  imprime 2\n\n";
    

       
    cout<<"\n  Pregunta 5.3\n";

    int matriz[3][3]={
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int suma_total= 0;

    //Imprimir la matriz
    cout<<"  Matriz 3x3:\n";
    for (int fila = 0; fila < 3; ++fila) {
        for (int col = 0; col < 3; ++col) {
            cout<< matriz[fila][col]<< " ";
            suma_total+= matriz[fila][col];
        }
        cout<<"\n  ";
    }
    cout<<"\n  La suma de todos los elementos es: "<< suma_total<< "\n";

    

    return 0;
}