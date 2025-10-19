/******************************************************************************

Parcial C++

Nombre: ALVARO ESTEBAN PULIDO ZAMORA		 Grupo: 	 Fecha: 	/	/	 Duración: 3 horas	Total: 100 pts equivalente a 5
Temas: Nivel 1 — Variables/Tipos/IO, Operadores, Condicionales, Bucles; Nivel 2 — Funciones
Instrucciones

•	Usa C++17 o superior.
•	Lee cuidadosamente cada pregunta. Marca una sola opción en la Sección A.
•	En la Sección B, escribe exactamente lo que se imprime (respeta espacios y saltos de línea).
•	En la Sección C, implementa solo las funciones solicitadas. No uses librerías fuera de <iostream> y <string>.


*******************************************************************************/

//Sección C — Implementación de funciones

//C1) Firma: int max3(int a, int b, int c);
int max3(int a, int b, int c){
    int maximo;
    if (a>b){
        if (a>c)
            maximo= a;
        else
            maximo= c;
    }else{
        if (b>c)
            maximo= b;
        else
            maximo= c;
    }
    return maximo;
}

//C2) Firma: int sumaRango(int a, int b); no se necita controlar a "a"
int rango(int a, int b){
    int suma=0;
    for (int i=a; i<=b; i++) {
        suma+= i;  
    }
    return suma;
}

//C3) Firma: bool contieneDigito(int n, int d);
bool contienedigito(int n, int d){
    if (n == 0 && d == 0) return true;
    while (n>0){
        int ultimonumero= n % 10;
        if (ultimonumero== d){
            return true;
        }
        n = n / 10;
    }
    return false;
}

#include <iostream>
#include <string>

//C4) Firma: void tablaMultiplicar(int n);
void tablaMultiplicar(int n){
    for (int i=1; i<=10; i++) {
        std::cout<<" "<<n<<" x "<<i<<" = "<<(n*i)<<"\n";
    }
}

int main(){
    
    std::cout<<"Sección A — Opción múltiple (10 × 3 pts = 30 pts)"<<"\n\n";
    std::cout<<" 1) Cuál declara y define una variable entera con valor 10 "<<"\n\n";
    std::cout<<"( )"<<" A) int x; x == 10;"<<"\n";
    std::cout<<"(X)"<<" B) int x = 10"<<"\n";
    std::cout<<"( )"<<" C) int x( ); x = '10';"<<"\n";
    std::cout<<"( )"<<" D) int x {""\"10\"};"<<"\n\n";

    std::cout<<" 2) ¿Qué imprime? std::cout << 7/2 <<"<<" \" \" << 7/2.0;"<<"\n\n";
    std::cout<<"( )"<<" A) 3 3"<<"\n";
    std::cout<<"(X)"<<" B) 3 3.5"<<"\n";
    std::cout<<"( )"<<" C) 3.5 3.5"<<"\n";
    std::cout<<"( )"<<" D) 3 3.0"<<"\n\n";
    
    std::cout<<" 3) Con bool a=true, b=false; ¿Qué imprime? std::cout << (a&&b) << \" \" << (a||b) << \" \" << (!b);"<<"\n\n";
    std::cout<<"( )"<<" A) true true false"<<"\n";
    std::cout<<"(X)"<<" B) 0 1 1"<<"\n";
    std::cout<<"( )"<<" C) 1 1 0 "<<"\n";
    std::cout<<"( )"<<" D) false true true"<<"\n\n";

    std::cout<<" 4) Dado int x=3; if (x=0) { ... } else { ... } ¿qué ocurre?;"<<"\n\n";
    std::cout<<"( )"<<" A) Error de compilación por asignación en if."<<"\n";
    std::cout<<"( )"<<" B) Entra al if siempre"<<"\n";
    std::cout<<"(X)"<<" C) Entra al else porque el valor es 0 tras la asignación"<<"\n"; //el resultado es CERO, debido a que no se esta haciendo una comparacion, sino una asignacion.
    std::cout<<"( )"<<" D) Comportamiento indefinido."<<"\n\n";  
    
    std::cout<<" 5) do-while respecto a while:"<<"\n\n";
    std::cout<<"( )"<<" A) Nunca ejecuta si la condición es falsa"<<"\n";
    std::cout<<"(X)"<<" B) Ejecuta al menos una vez"<<"\n";//el do-while ejecuta almenos una vez sin importar si la condicion es falsa.
    std::cout<<"( )"<<" C) Ejecuta exactamente una vez"<<"\n";
    std::cout<<"( )"<<" D) Es más rápido por definición."<<"\n\n";
    
    std::cout<<" 6) ¿Cuál lee dos enteros separados por espacio?"<<"\n\n";
    std::cout<<"( )"<<" A) cin << a << b;"<<"\n";
    std::cout<<"( )"<<" B) cin >> a, b;"<<"\n";
    std::cout<<"(X)"<<" C) cin >> a >> b;"<<"\n";    
    std::cout<<"( )"<<" D) cin (a, b);"<<"\n\n";
    
    std::cout<<" 7) ¿Qué imprime?int a=5, b=2;std::cout << a + b*3 << /n; "<<"\n\n";
    std::cout<<"(X)"<<" A) 11"<<"\n"; // primero son las operaciones de orden superior, luego suma y resta.
    std::cout<<"( )"<<" B) 21"<<"\n";
    std::cout<<"( )"<<" C) 10"<<"\n";    
    std::cout<<"( )"<<" D) 7"<<"\n\n";
    
    std::cout<<" 8) ¿Cuál firma pasa un entero por referencia?"<<"\n\n";
    std::cout<<"( )"<<" A) void f(int n&);"<<"\n";
    std::cout<<"(X)"<<" B) void f(int& n);"<<"\n";// Es una funcion, para llamar a una funcion propia.
    std::cout<<"( )"<<" C) void f(ref int n);"<<"\n";    
    std::cout<<"( )"<<" D) int& f(int n);"<<"\n\n";
    
    std::cout<<" 9) ¿Qué hace continue en un for?"<<"\n\n";
    std::cout<<"( )"<<" A) Termina por completo el bucle."<<"\n";
    std::cout<<"(X)"<<" B) Salta a la siguiente iteración"<<"\n";
    std::cout<<"( )"<<" C) Reinicia el contador a 0"<<"\n";    
    std::cout<<"( )"<<" D) Salta dos iteraciones.;"<<"\n\n";

    std::cout<<" 10) ¿Cuál condición es verdadera?"<<"\n\n";
    std::cout<<"(X)"<<" A) (3 == 3) && !(2 > 5)"<<"\n";
    std::cout<<"( )"<<" B) (3 = 3) || (2 < 1);"<<"\n";
    std::cout<<"( )"<<" C) !(3 == 3) || (2 > 5);"<<"\n";    
    std::cout<<"( )"<<" D) (3 != 3) && (2 <= 5);"<<"\n\n";
    
    std::cout<<" Sección B — Predice la salidad"<<"\n\n";
    
    std::cout<<" 1)"<<"\n";
    std::cout<<" int a=5, b=2;"<<"\n";
    std::cout<<" std::cout << a + b*3 << std::endl;"<<"\n";
    std::cout<<" Respuesta:"<<"11"<<"\n";
    
    std::cout<<"\n 2)"<<"\n";
    std::cout<<" while (n<3) {"<<"\n";
    std::cout <<"   std::cout << n <<"<<"\" \";"<<"\n";
    std::cout <<"   n++;"<<"\n";
    std::cout <<" } "<<"\n";
    std::cout<<" Respuesta:"<<"0 1 2"<<"\n";
    
    std::cout<<"\n 3)"<<"\n";
    std::cout<<" int x=10;"<<"\n";
    std::cout<<" if (x%2==0) std::cout <<""\"par\";"<<"\n";
    std::cout<<" else std::cout <<""\"impar\";"<<"\n";
    std::cout<<" Respuesta:"<<"par"<<"\n";
    
    std::cout<<"\n 4)"<<"\n";
    std::cout<<" int i=3;"<<"\n";
    std::cout<<" do {"<<"\n";
    std::cout<<" std::cout << i--;"<<"\n";
    std::cout<<" } while (i>0); "<<"\n";
    std::cout<<" Respuesta:"<<"321"<<"\n";

    std::cout<<"\n 5)"<<"\n";
    std::cout<<" int a=1;"<<"\n";
    std::cout<<" int b = (a++ > 1) ? 100 : 200;"<<"\n";
    std::cout<<" std::cout << a <<"<<" \" \" << b;"<<"\n";
    std::cout<<" Respuesta:"<<"2 200"<<"\n";


    std::cout<<"\n Sección C — Implementación de funciones (4 × 10 pts = 40 pts)"<<"\n\n";
    std::cout<<" C1) Firma: int max3(int a, int b, int c);"<<"\n";
    std::cout<<" Devuelve el mayor de tres enteros usando if/else<<"<<"\n";
    std::cout<<" max3(5, 10, 15)= "<< max3(5, 10, 15)<<"\n\n";
    
    std::cout<<" C2) Firma: int sumaRango(int a, int b);"<<"\n";
    std::cout<<" Devuelve la suma de todos los enteros en [a, b] (se asume a <= b) usando un bucle."<<"\n";
    std::cout <<" sumarango(1, 10) = "<<rango(1, 10)<<"\n\n"; 
    
    std::cout<<" C3) Firma: bool contieneDigito(int n, int d);"<<"\n";
    std::cout<<" Devuelve true si n (no negativo) contiene el dígito d (0–9). Usa operadores aritméticos."<<"\n";
    std::cout<<" ¿n tiene el digito de d?(3, 3): "<<(contienedigito(7, 7) ? "true" : "false")<<"\n";
    std::cout<<" ¿n tiene el digito de d?(100, 8): "<<(contienedigito(100, 8) ? "true" : "false")<<"\n\n";
   
    std::cout<<" C4) Firma: void tablaMultiplicar(int n);"<<"\n";
    std::cout<<" Imprime la tabla de n del 1 al 10 con el formato exacto: n x i = resultado (un renglón por i).."<<"\n\n";
    tablaMultiplicar(7);

     
    return 0;

}






