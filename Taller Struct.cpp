/******************************************************************************

                             Taller Struct

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <numeric>

//=== Ejercicio 1 y 2: Producto con constructores, valores por defecto, validación y operadores===

struct Producto{
    std::string nombre;
    double precio = 0.0;
    int stock = 0;

    //Constructor valores por defecto
    Producto(const std::string& nombre, double precio = 0.0, int stock = 0)
        : nombre(nombre), precio(precio), stock(stock) {}

    bool disponible() const{
        return stock > 0;
    }
   
   //Validacion
    bool esValido() const{
        return precio >= 0 && !nombre.empty();
    }

    void imprimir() const{
        std::cout << "Producto: " << nombre << ", Precio: " << precio << ", Stock: " << stock << "\n";
    }

    //Sobrecarga del operador 
    bool operator==(const Producto& otro) const{
        std::string nombre1 = nombre, nombre2 = otro.nombre;
        std::transform(nombre1.begin(), nombre1.end(), nombre1.begin(), ::tolower);
        std::transform(nombre2.begin(), nombre2.end(), nombre2.begin(), ::tolower);
        return nombre1 == nombre2;
    }

    //Sobrecarga del operador <
    bool operator<(const Producto& otro) const{
        if (precio == otro.precio) {
            return nombre < otro.nombre;
        }
        return precio < otro.precio;
    }
};

//===Ejercicio 3 y 5: Operadores == y < para ordenar y buscar===
//===Inventario mas complejo===

struct Inventario{
    std::vector<Producto> productos;

    void agregarProducto(const Producto& p) {
        productos.push_back(p);
    }

    void eliminarProducto(const std::string& nombre) {
        auto it = std::remove_if(productos.begin(), productos.end(),
                                 [&nombre](const Producto& p) { return p.nombre == nombre; });
        if (it != productos.end()) {
            productos.erase(it, productos.end());
            std::cout<< "Producto '"<< nombre<< "' eliminado del inventario.\n";
        } else {
            std::cout<< "Producto '"<< nombre<< "' no encontrado.\n";
        }
    }

    void actualizarProducto(const std::string& nombre, double nuevoPrecio, int nuevoStock) {
        auto it = std::find_if(productos.begin(), productos.end(),
                               [&nombre](const Producto& p) { return p.nombre == nombre; });
        if (it != productos.end()) {
            it->precio = nuevoPrecio;
            it->stock = nuevoStock;
            std::cout<< "Producto '"<< nombre<< "' actualizado.\n";
        } else {
            std::cout<< "Producto '"<< nombre<< "' no encontrado.\n";
        }
    }

    void imprimirInventario() const{
        std::cout<< "Inventario de productos:\n";
        if (productos.empty()) {
            std::cout<< "No hay productos en el inventario.\n";
            return;
        }
        for (const auto& p : productos) {
            p.imprimir();
        }
    }

    void imprimirProductosDisponibles() const {
        std::cout << "Productos disponibles en inventario:\n";
        bool encontrados = false;
        for (const auto& p : productos){
            if (p.disponible()) {
                p.imprimir();
                encontrados = true;
            }
        }
        if (!encontrados) {
            std::cout << "No hay productos disponibles.\n";
        }
    }
};

//===Ejercicio 4: Estructura polinomio===
struct Polinomio {
    std::vector<int> coeficientes; // coeficientes del polinomio

    Polinomio(std::initializer_list<int> coef) : coeficientes(coef) {}

    void imprimir() const {
        for (int i = coeficientes.size() - 1; i >= 0; --i) {
            if (coeficientes[i] != 0) {
                if (i < coeficientes.size() - 1) std::cout << " + ";
                std::cout << coeficientes[i];
                if (i > 0) std::cout << "x^" << i;
            }
        }
        std::cout<<"\n";
    }
};

// === Ejercicio 6: Estructura fraccion ===
struct Fraccion{
    int numerador, denominador;
    Fraccion(int num, int den) : numerador(num), denominador(den == 0 ? 1 : den) {}

    void simplificar(){
        int gcd = std::gcd(numerador, denominador); // Requiere C++17 o posterior
        numerador /= gcd;
        denominador /= gcd;
    }

    void imprimir() const {
        std::cout << "Fracción: " << numerador << "/" << denominador << "\n";
    }
};

//===Ejercicio 7: Gestion de contactos===
struct Contacto{
    std::string nombre;
    std::string telefono;
    std::string correo;

    Contacto(const std::string& nom, const std::string& tel, const std::string& mail)
        : nombre(nom), telefono(tel), correo(mail) {}

    void imprimir() const{
        std::cout<< "Nombre: " << nombre << ", Teléfono: " << telefono << ", Correo: " << correo << "\n";
    }
};

int main(){
    //===Ejercicio 1 y 2===
    std::cout<<"=== Ejercicio 1 y 2: Producto con constructores,valores por defecto y validación===\n";
    Producto p1("Tomate");                //solo nombre
    Producto p2("Atun", 8000.0);          //nombre y precio
    Producto p3("Arroz", 2500.0, 20);      //nombre, precio y inventario

    p1.imprimir();
    p2.imprimir();
    p3.imprimir();

    // Validación
    std::vector<Producto> productos = {p1, p2, p3};
    productos.erase(std::remove_if(productos.begin(), productos.end(),
                                    [](const Producto& p) { return !p.esValido() || !p.disponible(); }),
                     productos.end());

    std::cout<<"\nProductos válidos y disponibles:\n";
    for (const auto& p : productos) {
        p.imprimir();
    }

    //===Ejercicio 3 operadores de ordenar y buscar===
    std::cout << "\n=== Ejercicio 3: Operadores de Ordenar y Buscar===\n";
    
    //Agregar un producto
    productos.push_back(Producto("Jamon", 9000.0, 10));
    std::sort(productos.begin(), productos.end());

    std::cout<<"\nProductos ordenados:\n";
    for (const auto& p : productos) {
        p.imprimir();
    }

    auto it = std::find(productos.begin(), productos.end(), Producto("Jamon"));
    if (it != productos.end()) {
        std::cout << "\nProducto encontrado: ";
        it->imprimir();
    }else{
        std::cout << "\nProducto no encontrado.\n";
    }

    //===Ejercicio 4 Estructura Polinomio===
    std::cout<<"\n=== Ejercicio 4: Estructura Polinomio ===\n";
    Polinomio p1_poly{1, -3, 2}; // x^2 - 3x + 2
    p1_poly.imprimir();

    // === Ejercicio 5: Sistema de Inventario Más Complejo ===
    std::cout<<"\n===Ejercicio 5: Sistema de Inventario Más Complejo===\n";
    Inventario inv;
    inv.agregarProducto(Producto("Salsa", 3000.0, 10));
    inv.agregarProducto(Producto("Carne", 30000.0, 15));
    inv.agregarProducto(Producto("Mandarina", 1000.0, 0));

    inv.imprimirInventario();

    inv.eliminarProducto("Mandarina");
    inv.imprimirInventario();

    inv.actualizarProducto("Doritos", 3000.0, 5);
    inv.imprimirInventario();

    inv.imprimirProductosDisponibles();

    //===Ejercicio 6 ==
    std::cout<<"\n===Ejercicio 6: Fracción ===\n";
    Fraccion f1(8, 12);
    f1.simplificar();
    f1.imprimir();

    //===Ejercicio 7===
    std::cout << "\n=== Ejercicio 7: Gestion de contactos ===\n";
    Contacto c1("Alvaro Esteban", "123456789", "estebanzamora@gmail.com");
    Contacto c2("Maria Elena", "978654321", "mariaelena@gmail.com");

    c1.imprimir();
    c2.imprimir();

    return 0;
}
