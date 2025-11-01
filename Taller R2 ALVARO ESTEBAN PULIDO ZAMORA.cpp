#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

// 1. Min, max, promedio de arreglo
void leer_arreglo(int *a, size_t n){
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
}
void min_max_prom(const int *a, size_t n, int *minv, int *maxv, double *prom) {
    if (n == 0) {
        *minv = 0;
        *maxv = 0;
        *prom = 0.0;
        return;
    }
    *minv = a[0];
    *maxv = a[0];
    *prom = 0.0;
    const int *puntero = a;
    for (size_t i = 0; i < n; i++) {
        if (*puntero < *minv) *minv = *puntero;
        if (*puntero > *maxv) *maxv = *puntero;
        *prom += *puntero;
        puntero++;
    }
    *prom /= n;
}
void menu_min_max_prom() {
    size_t n;
    cout << "Ingrese cantidad de elementos: ";
    cin >> n;
    if (n == 0) { cout << "Nada que procesar\n"; return; }
    int* arreglo = new int[n];
    leer_arreglo(arreglo, n);
    int minv, maxv; double prom;
    min_max_prom(arreglo, n, &minv, &maxv, &prom);
    cout << "min=" << minv << " max=" << maxv << " prom=" << fixed << setprecision(2) << prom << endl;
    delete[] arreglo;
}

// 2. Rotar arreglo a la derecha
void reverse(int *a, size_t i, size_t j) {
    int *izq = a + i, *der = a + j;
    while (izq < der) { int t=*izq; *izq=*der; *der=t; izq++; der--; }
}
void rotar_derecha(int *a, size_t n, size_t k) {
    if (n == 0) return;
    k = k % n;
    if (k == 0) return;
    reverse(a, 0, n-1);
    reverse(a, 0, k-1);
    reverse(a, k, n-1);
}
void imprimir_arreglo(const int *a, size_t n) {
    cout << "[";
    for (size_t i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}
void menu_rotar_derecha() {
    size_t n, k;
    cout << "Ingrese cantidad de elementos: ";
    cin >> n;
    if (n == 0) { cout << "Nada que procesar\n"; return; }
    int* arreglo = new int[n];
    cout << "Ingrese los " << n << " elementos:\n";
    for (size_t i=0; i<n; i++) cin >> arreglo[i];
    cout << "Ingrese k (cuantas posiciones a la derecha): ";
    cin >> k;
    cout << "Antes: "; imprimir_arreglo(arreglo, n);
    rotar_derecha(arreglo, n, k);
    cout << "Después: "; imprimir_arreglo(arreglo, n);
    delete[] arreglo;
}

// 3. Normalizar espacios en una cadena
size_t normalizar_espacios(const char *src, char *dst, size_t outcap) {
    if (outcap == 0) return 0;
    const char *p = src;
    char *q = dst;
    char *end = dst + outcap - 1;
    bool prev_space = true;
    while (*p && q < end) {
        if (*p == ' ' || *p == '\t') {
            if (!prev_space) { *q++ = ' '; prev_space = true; }
        } else {
            *q++ = *p; prev_space = false;
        }
        p++;
    }
    if (q > dst && *(q-1) == ' ') q--;
    *q = '\0';
    return q - dst;
}
void menu_normalizar_espacios() {
    string s;
    cout << "Ingrese una cadena con espacios y/o tabs: ";
    cin.ignore();
    getline(cin, s);
    char salida[1001];
    size_t len = normalizar_espacios(s.c_str(), salida, sizeof(salida));
    cout << "Cadena normalizada: \"" << salida << "\" (longitud=" << len << ")\n";
}

// 4. Suma filas y columnas de matriz
int* mat_crear(size_t m, size_t n) { return new int[m * n]; }
void mat_destruir(int* A) { delete[] A; }
void mat_sumas(int* A, size_t m, size_t n, int* sumF, int* sumC) {
    for (size_t i = 0; i < m; i++) sumF[i] = 0;
    for (size_t j = 0; j < n; j++) sumC[j] = 0;
    for (size_t i = 0; i < m; i++) for (size_t j = 0; j < n; j++) {
        int elemento = A[i * n + j];
        sumF[i] += elemento; sumC[j] += elemento;
    }
}
void menu_mat_sumas() {
    size_t m, n;
    cout << "Ingrese filas y columnas de la matriz: ";
    cin >> m >> n;
    if (m == 0 || n == 0) { cout << "Nada que procesar\n"; return; }
    int* A = mat_crear(m, n);
    cout << "Ingrese los elementos fila por fila:\n";
    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < n; j++)
            cin >> A[i * n + j];
    int* sumFila = new int[m]; int* sumCol = new int[n];
    mat_sumas(A, m, n, sumFila, sumCol);
    cout << "Sumas de filas: "; imprimir_arreglo(sumFila, m);
    cout << "Sumas de columnas: "; imprimir_arreglo(sumCol, n);
    mat_destruir(A); delete[] sumFila; delete[] sumCol;
}

// 5. Gestión de estudiantes
typedef struct {
    char nombre[40];
    int edad;
    double promedio;
} Estudiante;
int cmp_prom_desc(const void *a, const void *b) {
    const Estudiante *A = (const Estudiante *)a, *B = (const Estudiante *)b;
    if (A->promedio > B->promedio) return -1;
    if (A->promedio < B->promedio) return 1;
    return 0;
}
int buscar_nombre(Estudiante *v, size_t n, const char *clave) {
    for (size_t i = 0; i < n; i++)
        if (strcmp(v[i].nombre, clave) == 0) return i;
    return -1;
}
void menu_estudiantes() {
    int n;
    cout << "Cantidad de estudiantes: "; cin >> n; cin.ignore();
    if (n <= 0) { cout << "Nada que procesar\n"; return; }
    Estudiante *E = new Estudiante[n];
    for (int i=0; i<n; i++) {
        cout << "Nombre: "; cin.getline(E[i].nombre, 40);
        cout << "Edad: "; cin >> E[i].edad;
        cout << "Promedio: "; cin >> E[i].promedio;
        cin.ignore();
    }
    qsort(E, n, sizeof(Estudiante), cmp_prom_desc);
    cout << "\n-- TOP 3 --\n";
    for (int i=0; i<n && i<3; i++)
        cout << i+1 << ". " << E[i].nombre << " - Edad: " << E[i].edad << " - Prom: " << fixed << setprecision(2) << E[i].promedio << endl;
    char clave[40];
    cout << "Buscar por nombre: "; cin.getline(clave, 40);
    int idx = buscar_nombre(E, n, clave);
    if (idx != -1)
        cout << "Encontrado: " << E[idx].nombre << ", Edad: " << E[idx].edad << ", Promedio: " << fixed << setprecision(2) << E[idx].promedio << " (posicion " << idx+1 << ")\n";
    else
        cout << "No encontrado.\n";
    cout << "-- Lista completa ordenada --\n";
    for (int i=0; i<n; i++)
        cout << i+1 << ". " << E[i].nombre << " - Edad: " << E[i].edad << " - Prom: " << fixed << setprecision(2) << E[i].promedio << endl;
    delete[] E;
}

// 6. Lista enlazada simple
typedef struct Nodo {
    int x;
    struct Nodo *sig;
} Nodo;
void push_front(Nodo **cabeza, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo) { cerr << "Error memoria\n"; exit(1); }
    nuevo->x = valor; nuevo->sig = *cabeza; *cabeza = nuevo;
}
void push_back(Nodo **cabeza, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo) { cerr << "Error memoria\n"; exit(1); }
    nuevo->x = valor; nuevo->sig = nullptr;
    if (!*cabeza) { *cabeza = nuevo; return; }
    Nodo *a = *cabeza;
    while (a->sig) a = a->sig;
    a->sig = nuevo;
}
void pop_front(Nodo **cabeza) {
    if (!*cabeza) return;
    Nodo *tmp = *cabeza;
    *cabeza = (*cabeza)->sig;
    free(tmp);
}
size_t size(Nodo *cabeza) {
    size_t c=0; for (Nodo*a=cabeza;a;a=a->sig) c++; return c;
}
void clear(Nodo **cabeza) {
    Nodo *a = *cabeza, *sig;
    while (a) { sig = a->sig; free(a); a = sig; }
    *cabeza = nullptr;
}
void imprimir_lista(Nodo *cabeza) {
    if (!cabeza) { cout << "Lista vacía\n"; return; }
    Nodo *a = cabeza;
    while (a) { cout << a->x; if (a->sig) cout << " "; a = a->sig; }
    cout << endl;
}
void menu_lista_enlazada() {
    Nodo *cabeza = nullptr;
    char comando[10]; int valor;
    cout << "Comandos: pf <val>, pb <val>, pop, size, clear, fin\n";
    while (true) {
        cout << "> "; cin >> comando;
        if (strcmp(comando, "pf") == 0) { cin >> valor; push_front(&cabeza, valor); }
        else if (strcmp(comando, "pb") == 0) { cin >> valor; push_back(&cabeza, valor); }
        else if (strcmp(comando, "pop") == 0) { pop_front(&cabeza); }
        else if (strcmp(comando, "size") == 0) { cout << "Tamaño: " << size(cabeza) << endl; }
        else if (strcmp(comando, "clear") == 0) { clear(&cabeza); }
        else if (strcmp(comando, "fin") == 0) break;
        else cout << "Comando no reconocido.\n";
    }
    cout << "Lista final: "; imprimir_lista(cabeza); clear(&cabeza);
}

// 7. Aplicar función a cada elemento de arreglo
int doble(int x) { return x*2; }
int cuadrado(int x) { return x*x; }
void aplicar(int *a, size_t n, int (*op)(int)) { for (size_t i=0;i<n;i++) a[i]=op(a[i]); }
void menu_aplicar_funcion() {
    size_t n;
    cout << "Tamaño del arreglo: "; cin >> n;
    if (n <= 0) { cout << "Nada que procesar\n"; return; }
    int* arreglo = new int[n];
    cout << "Ingrese " << n << " elementos:\n";
    for (size_t i=0; i<n; i++) {
        cout << "Elemento " << i+1 << ": ";
        cin >> arreglo[i];
    }
    int op;
    do {
        cout << "\n1. Doble\n2. Cuadrado\n3. Nuevo arreglo\n4. Salir\nOpción: ";
        cin >> op;
        if (op == 1) { aplicar(arreglo, n, doble); cout << "Aplicado doble\n"; }
        else if (op == 2) { aplicar(arreglo, n, cuadrado); cout << "Aplicado cuadrado\n"; }
        else if (op == 3) {
            delete[] arreglo;
            cout << "Nuevo tamaño: "; cin >> n;
            arreglo = new int[n];
            cout << "Ingrese " << n << " elementos:\n";
            for (size_t i=0; i<n; i++) {
                cout << "Elemento " << i+1 << ": ";
                cin >> arreglo[i];
            }
        }
        if (op == 1 || op == 2 || op == 3) {
            cout << "Arreglo: "; imprimir_arreglo(arreglo, n);
        }
    } while (op != 4);
    delete[] arreglo;
}

// 8. Ventas desde CSV
typedef struct {
    char prod[32];
    int unidades;
    double precio;
} Venta;
Venta* leer_csv(const char* filename, size_t* n) {
    ifstream archivo(filename);
    if (!archivo.is_open()) { *n=0; return nullptr; }
    string linea; size_t contador=0;
    while (getline(archivo, linea))
        if (!linea.empty() && isalpha(linea[0])) contador++;
    if (contador == 0) { *n=0; archivo.close(); return nullptr; }
    Venta* ventas = new Venta[contador];
    archivo.clear(); archivo.seekg(0);
    size_t idx = 0;
    while (getline(archivo, linea) && idx < contador) {
        if (linea.empty() || !isalpha(linea[0])) continue;
        size_t pos1 = linea.find(',');
        size_t pos2 = linea.find(',', pos1 + 1);
        if (pos1 == string::npos || pos2 == string::npos) continue;
        string producto = linea.substr(0, pos1);
        if (producto.length() >= 32) producto = producto.substr(0, 31);
        strcpy(ventas[idx].prod, producto.c_str());
        string str_unidades = linea.substr(pos1 + 1, pos2 - pos1 - 1);
        ventas[idx].unidades = atoi(str_unidades.c_str());
        string str_precio = linea.substr(pos2 + 1);
        ventas[idx].precio = atof(str_precio.c_str());
        idx++;
    }
    archivo.close();
    *n = idx;
    return ventas;
}
double calcular_total_vendido(Venta* ventas, size_t n) {
    double total = 0.0;
    for (size_t i = 0; i < n; i++)
        total += ventas[i].unidades * ventas[i].precio;
    return total;
}
const char* encontrar_producto_mas_vendido(Venta* ventas, size_t n) {
    if (n == 0) return "No hay productos";
    int max_unidades = ventas[0].unidades;
    size_t idx_max = 0;
    for (size_t i = 1; i < n; i++)
        if (ventas[i].unidades > max_unidades) {
            max_unidades = ventas[i].unidades; idx_max = i;
        }
    return ventas[idx_max].prod;
}
double calcular_ticket_promedio(Venta* ventas, size_t n) {
    if (n == 0) return 0.0;
    double total_vendido = calcular_total_vendido(ventas, n);
    return total_vendido / n;
}
void imprimir_ventas(Venta* ventas, size_t n) {
    cout << left << setw(20) << "Producto"
         << setw(10) << "Unidades"
         << setw(10) << "Precio"
         << setw(15) << "Subtotal" << endl;
    cout << string(55, '-') << endl;
    for (size_t i = 0; i < n; i++) {
        double subtotal = ventas[i].unidades * ventas[i].precio;
        cout << left << setw(20) << ventas[i].prod
             << setw(10) << ventas[i].unidades
             << "$" << setw(9) << fixed << setprecision(2) << ventas[i].precio
             << "$" << setw(14) << subtotal << endl;
    }
}
void liberar_memoria(Venta* ventas) { delete[] ventas; }
void menu_ventas_csv() {
    string filename;
    cout << "Nombre del archivo CSV: ";
    cin >> filename;
    size_t n;
    Venta* ventas = leer_csv(filename.c_str(), &n);
    if (!ventas) { cout << "No se pudo leer archivo o está vacío.\n"; return; }
    imprimir_ventas(ventas, n);
    cout << "\nTotal vendido: $" << fixed << setprecision(2) << calcular_total_vendido(ventas, n) << endl;
    cout << "Producto más vendido: " << encontrar_producto_mas_vendido(ventas, n) << endl;
    cout << "Ticket promedio: $" << calcular_ticket_promedio(ventas, n) << endl;
    liberar_memoria(ventas);
}

// Menú principal
int main() {
    int op;
    do {
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1. Min, max y promedio de arreglo\n";
        cout << "2. Rotar arreglo a la derecha\n";
        cout << "3. Normalizar espacios en cadena\n";
        cout << "4. Sumas de filas y columnas de matriz\n";
        cout << "5. Gestion de estudiantes\n";
        cout << "6. Lista enlazada simple\n";
        cout << "7. Aplicar funcion a arreglo\n";
        cout << "8. Ventas desde CSV\n";
        cout << "9. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> op;
        switch (op) {
            case 1: menu_min_max_prom(); break;
            case 2: menu_rotar_derecha(); break;
            case 3: menu_normalizar_espacios(); break;
            case 4: menu_mat_sumas(); break;
            case 5: menu_estudiantes(); break;
            case 6: menu_lista_enlazada(); break;
            case 7: menu_aplicar_funcion(); break;
            case 8: menu_ventas_csv(); break;
            case 9: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n";
        }
    } while (op != 9);
    return 0;
}