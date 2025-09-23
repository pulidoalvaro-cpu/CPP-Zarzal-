/*******************************************************************************
== Taller 2 ===
    "1. Crea un programa que encuentre la mediana de un array
    "2. Implementa la búsqueda binaria en un array ordenado
    "3. Desarrolla un programa que calcule la transpuesta de una matriz
    "4. Crea un sistema de inventario simple con arrays
    "5. Implementa el algoritmo de ordenamiento por selección
    "6. Desarrolla un programa que encuentre elementos duplicados
    "7. Crea un juego de tres en raya usando arrays bidimensionales

*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(){
    
    cout<<"1. Crea un programa que encuentre la mediana de un array\n\n";
    
    //Definir array 
    int array[] = {10,8,6,4,2,1,3,5,7,9};
    int n = sizeof(array) / sizeof(array[0]); //tamaño del array
    
    int array1[10] = {10,8,6,4,2,1,3,5,7,9}; // copia del array
    
    //Ordenar el array
    sort(array, array + n);
    
    //Calcular la mediana
    double mediana;
    if (n % 2 == 1) {
        mediana = array[n / 2];
    } else {
        mediana = (array[n / 2 - 1] + array[n / 2]) / 2.0;
    }

    //Resultados
    cout <<"Array original: ";
    for (int i = 0; i < n; i++) {
        cout << array1[i] << " ";
    }
    cout <<"\nArray ordenado: ";
    for (int i = 0; i < n; i++) {
        cout <<array[i]<< " ";
    }
    cout <<"\n La mediana es: "<< mediana<< "\n";
    
    cout<<"\n2. Implementa la búsqueda binaria en un array ordenado\n\n";
    
    //Definir array ordenado 
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int m = sizeof(array) / sizeof(array[0]); // tamaño del array
    
    //Valor a buscar
    int buscar = 8;
    
    //Inicializar variables para la búsqueda
    int inicio = 0;
    int fin = m - 1;
    int encontrado = -1; // -1 significa no encontrado
    
    //Busqueda binaria
    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;
        
        if(numeros[medio] == buscar) {
            encontrado = medio;
            break;
        }
        
        if(numeros[medio] < buscar) {
            inicio = medio + 1;
        }else{
            fin = medio - 1;
        }
    }
    // Mostrar resultado
    cout <<"Array: ";
    for (int i = 0; i < m; i++) {
        cout <<numeros[i]<<" ";
    }
    cout << "\nBuscando: " << buscar <<"\n";
    
    if (encontrado != -1){
        cout <<"¡Encontrado! Posicion: "<<encontrado<<"\n";
    } else {
        cout <<"No encontrado"<<"\n";
    }
    
    cout<<"\n3. Desarrolla un programa que calcule la transpuesta de una matriz\n\n";
    //Matriz 3x3 con valores del 1 al 9
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    //Declarar la matriz transpuesta 3x3
    int transpuesta[3][3];
    //Calcular la transpuesta
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }
    //Mostrar matriz original
    cout << "MATRIZ 3x3:" << "\n";
    cout << "===================" <<"\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
    //Mostrar matriz transpuesta
    cout << "\nMATRIZ TRANSPUESTA 3x3:" <<"\n";
    cout << "======================" <<"\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << transpuesta[i][j] << " ";
        }
        cout <<"\n";
    }
    
    cout<<"\n4. Crear un sistema de inventario simple con arrays\n\n";
    
    //Declarar variables
    string productos[10];
    int stock[10] = {0};
    int contador = 0;
    int opcion;
    
    //Menu de opciones
    cout << "INVENTARIO SIMPLE" << "\n";
    while (true) {
        cout << "\n1. Agregar" << "\n";
        cout << "2. Ver todo" << "\n";
        cout << "3. Salir" << "\n";
        cout << "Elige: ";
        cin >> opcion;
        
        if (opcion == 1) {
            // Agregar producto
            if (contador < 10) {
                cout << "Nombre del producto: ";
                cin >> productos[contador];
                cout << "Cantidad: ";
                cin >> stock[contador];
                contador++;
            }else{
                cout << "No hay espacio!" << "\n";
            }
            
        } else if(opcion == 2) {
            // Ver inventario
            cout << "\nProductos en stock:" << "\n";
            for (int i = 0; i < contador; i++) {
                cout << productos[i] << " - " << stock[i] << " unidades" << "\n";
            }
            
        } else if (opcion == 3) {
            break;
        }
    }
    
    cout<<"\n5. Implementa el algoritmo de ordenamiento por selección\n\n";
    
    // Crear una copia para ordenar
    int numerosOrdenados[10];
    for (int i = 0; i < 10; i++) {
        numerosOrdenados[i] = array[i];
    }

    // Ordenamiento burbuja (ascendente)
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (numerosOrdenados[j] > numerosOrdenados[j + 1]) {
                // Intercambiar elementos
                int temp = numerosOrdenados[j];
                numerosOrdenados[j] = numerosOrdenados[j + 1];
                numerosOrdenados[j + 1] = temp;
            }
        }
    }
    //Resultados
    cout <<" Array original: ";
    for (int i = 0; i < n; i++) {
        cout << array1[i] << " ";
    }
    cout << "   Array ordenado (ascendente): ";
    for (int i = 0; i < 10; i++) {
        cout << numerosOrdenados[i] << " ";
    }
    cout << "\n\n";
   
    cout<<"\n6. Desarrolla un programa que encuentre elementos duplicados\n\n";
    
    //crear array
    int arrai[] = {4, 2, 7, 4, 9, 2, 1, 7};
    int ñ = sizeof(arrai) / sizeof(arrai[0]);

    cout << "Elementos del arreglo:\n";
    for (int i = 0; i < ñ; i++) {
        cout << arrai[i] << " ";
    }
    cout << "\n\nElementos duplicados encontrados:\n";

    bool Duplicados = false;

    // Buscar duplicados
    for(int i = 0; i < ñ; i++){
        bool elementoscontados = false;

        // Verificar si ya fue contado
        for (int k = 0; k < i; k++) {
            if (arrai[i] == arrai[k]) {
                elementoscontados = true;
                break;
            }
        }

        if (elementoscontados)
            continue;

        int conteo = 0;

        for (int j = 0; j < ñ; j++) {
            if (arrai[i] == arrai[j]) {
                conteo++;
            }
        }

        if (conteo > 1) {
            cout << arrai[i] << " (aparece " << conteo << " veces)\n";
            Duplicados = true;
        }
    }

    if (!Duplicados) {
        cout << "No se encontraron elementos duplicados.\n";
    }
    
    cout<<"\n7. Crea un juego de tres en raya usando arrays bidimensionales\n\n";
    //Crear array del tablero
    char tablero[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    char jugador = 'X';
    int turno = 0;

    while (turno < 9) {
        //Mostrar tablero
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            cout << " " << tablero[i][0] << " | " << tablero[i][1] << " | " << tablero[i][2] << "\n";
            if (i < 2) cout << "---+---+---\n";
        }

        //Entrada del jugador
        int opcion;
        cout << "\nTurno del jugador " << jugador << ". Elige una casilla (1-9): ";
        cin >> opcion;

        //Validar y aplicar movimiento
        bool valido = false;
        for (int i = 0; i < 3 && !valido; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i][j] == opcion + '0') {
                    tablero[i][j] = jugador;
                    valido = true;
                    break;
                }
            }
        }

        if (!valido) {
            cout << "Movimiento inválido. Intenta de nuevo.\n";
            continue;
        }

        //Verificar ganador
        bool gana = false;
        for (int i = 0; i < 3; i++) {
            if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador)
                gana = true;
            if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)
                gana = true;
        }
        if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador)
            gana = true;
        if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)
            gana = true;

        if (gana) {
            //Mostrar tablero y mensaje ganador
            cout << "\n";
            for (int i = 0; i < 3; i++) {
                cout << " " << tablero[i][0] << " | " << tablero[i][1] << " | " << tablero[i][2] << "\n";
                if (i < 2) cout << "---+---+---\n";
            }
            cout << "\n¡El jugador " << jugador << " ha ganado!\n";
            return 0;
        }

        //Cambiar jugador
        jugador = (jugador == 'X') ? 'O' : 'X';
        turno++;
    }

    //Empate
    cout << "\n¡Empate! No hay ganador.\n";
    
    
    return 0;
}