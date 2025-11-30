/*********************************************
   TAlLER PROGRAMACION DE OBJETOS
   ALVARO ESTEBAN PULIDO ZAMORA
**********************************************/

#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip> 

//--------------NIVEL 1---------------------------
//Constante para la validación del año (Primer vehículo a motor)
const int año_Minimo = 1886;

class Vehiculo {
private:
    std::string marca;
    std::string modelo;
    int año;
    double velocidadMaxima;

public:
    // Constructor
    Vehiculo(const std::string& marca, const std::string& modelo, int año, double velocidadMaxima) {
        setMarca(marca);
        setModelo(modelo);
        setAño(año);
        setVelocidadMaxima(velocidadMaxima);
    }

    // Getters
    std::string getMarca() const{ return marca; }
    std::string getModelo() const{ return modelo; }
    int getAño() const{ return año; }
    double getVelocidadMaxima() const{ return velocidadMaxima; }

    // Setters con validaciones 
    void setMarca(const std::string& nuevaMarca){
        if (nuevaMarca.empty()){
            throw std::invalid_argument("  La marca no puede estar vacia.");
        }
        marca= nuevaMarca;
    }

    void setModelo(const std::string& nuevoModelo){
        if (nuevoModelo.empty()){
            throw std::invalid_argument("  El modelo no puede estar vacio.");
        }
        modelo= nuevoModelo;
    }

    void setAño(int nuevoAño){
        // El año debe ser mayor a 1886
        if (nuevoAño < año_Minimo){
            throw std::invalid_argument("  El año (" + std::to_string(nuevoAño) + ") debe ser posterior al primer vehiculo motorizado (" + std::to_string(año_Minimo) + ").");
        }
        año= nuevoAño;
    }

    void setVelocidadMaxima(double nuevaVelocidad){
        // La velocidad máxima debe ser positiva
        if (nuevaVelocidad <= 0){
            throw std::invalid_argument("  La velocidad maxima debe ser positiva.");
        }
        velocidadMaxima= nuevaVelocidad;
    }

    // Métodos de comportamiento 
    // Método mostrarInfo() (virtual para posible sobrescritura futura)
    virtual void mostrarInfo() const{
        std::cout<<"\n--- Informacion del Vehiculo ---"<< std::endl;
        std::cout<<"  Marca: "<< marca << std::endl;
        std::cout<<"  Modelo: "<< modelo << std::endl;
        std::cout<<"  Año: "<< año << std::endl;
        std::cout<<"  Velocidad Maxima: "<< std::fixed<< std::setprecision(2)<< velocidadMaxima<< " km/h"<< std::endl;
    }

    // Método acelerar 
    void acelerar(double incremento){
        if (incremento > 0){
            velocidadMaxima += incremento;
            std::cout<<"\n  El vehiculo acelero, la nueva velocidad maxima es: "<< std::fixed<< std::setprecision(2)<< velocidadMaxima<< " km/h."<< std::endl;
        } else {
            std::cout<<"\n  El incremento de velocidad debe ser positivo."<< std::endl;
        }
    }

    // Destructor virtual
    virtual ~Vehiculo() = default;
};


//  Clase que representa un Producto en una tienda.
 
class Producto{
private:
    std::string codigo;
    std::string nombre;
    double precio;
    int cantidad;

public:
    // Constructor
    Producto(const std::string& codigo, const std::string& nombre, double precio, int cantidad){
        setCodigo(codigo);
        setNombre(nombre);
        setPrecio(precio);
        setCantidad(cantidad);
    }

    //  Getters 
    std::string getCodigo() const { return codigo; }
    std::string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }

    //   Setters con validaciones 
    void setCodigo(const std::string& nuevoCodigo) {
        if (nuevoCodigo.empty()){
            throw std::invalid_argument("  El codigo no puede estar vacio.");
        }
        codigo = nuevoCodigo;
    }

    void setNombre(const std::string& nuevoNombre){
        if (nuevoNombre.empty()) {
            throw std::invalid_argument("  El nombre no puede estar vacio.");
        }
        nombre = nuevoNombre;
    }

    void setPrecio(double nuevoPrecio){
        // el precio no puede ser negativo
        if (nuevoPrecio < 0) {
            throw std::invalid_argument("  El precio no puede ser negativo.");
        }
        precio = nuevoPrecio;
    }

    void setCantidad(int nuevaCantidad) {
        // La cantidad no puede ser negativa
        if (nuevaCantidad < 0) {
            throw std::invalid_argument("  La cantidad no puede ser negativa.");
        }
        cantidad = nuevaCantidad;
    }


    // Método calcularValorTotal()
    double calcularValorTotal() const {
        return precio * cantidad;
    }

    // Método aplicarDescuento(double porcentaje)
    void aplicarDescuento(double porcentaje){
        if (porcentaje < 0 || porcentaje > 100){
            throw std::invalid_argument("  El porcentaje de descuento debe estar entre 0 y 100.");
        }
        double factor = 1.0 - (porcentaje / 100.0);
        precio *= factor;
        std::cout<<"\n  Se aplico un descuento del "<< std::fixed<< std::setprecision(2)<< porcentaje<< "%."<< std::endl;
    }

    // Método mostrarInfo()
    void mostrarInfo() const{
        std::cout<<"\n--- Informacion del Producto ---"<< std::endl;
        std::cout<<"  Codigo: "<< codigo<< std::endl;
        std::cout<<"  Nombre: "<< nombre<< std::endl;
        std::cout<<"  Precio Unitario: $"<< std::fixed<< std::setprecision(2)<< precio<< std::endl;
        std::cout<<"  Cantidad en Stock: "<< cantidad<< std::endl;
    }

    ~Producto() = default;
};

//-------------NIVEL 2-------------------------------------
//Clase Auto que hereda de Vehiculo 
 
class Auto : public Vehiculo{
private:
    int numeroPuertas;
    std::string tipoCombustible;

public:
    // Constructor que llama al constructor de la base
    Auto(const std::string& marca, const std::string& modelo, int año, double velocidadMaxima,
         int numeroPuertas, const std::string& tipoCombustible)
        : Vehiculo(marca, modelo, año, velocidadMaxima){
        setNumeroPuertas(numeroPuertas);
        setTipoCombustible(tipoCombustible);
    }

    // Getters 
    int getNumeroPuertas() const { return numeroPuertas; }
    std::string getTipoCombustible() const { return tipoCombustible; }

    // Setters con validaciones 
    void setNumeroPuertas(int num) {
        if (num <= 0) {
            throw std::invalid_argument("  El numero de puertas debe ser positivo.");
        }
        numeroPuertas = num;
    }

    void setTipoCombustible(const std::string& tipo) {
        if (tipo.empty()) {
            throw std::invalid_argument("  El tipo de combustible no puede estar vacio.");
        }
        tipoCombustible = tipo;
    }

    //  mostrarInfo() sobrescrito
    void mostrarInfo() const override {
        // Reutilizamos la lógica de la clase base
        Vehiculo::mostrarInfo();
        std::cout<<"  Tipo de Vehiculo: Auto"<< std::endl;
        std::cout<<"  Numero de Puertas: "<< numeroPuertas<< std::endl;
        std::cout<<"  Tipo de Combustible: "<< tipoCombustible<< std::endl;
        std::cout<<"---------------------------------"<< std::endl;
    }

    ~Auto() override = default;
};

// Clase Motocicleta que hereda de Vehiculo.
 
class Motocicleta : public Vehiculo{
private:
    bool tieneAlaron;
    int cilindrada;

public:
    // Constructor
    Motocicleta(const std::string& marca, const std::string& modelo, int año, double velocidadMaxima,
                bool tieneAlaron, int cilindrada)
        : Vehiculo(marca, modelo, año, velocidadMaxima) {
        setTieneAlaron(tieneAlaron);
        setCilindrada(cilindrada);
    }

    // Getters 
    bool getTieneAlaron() const{ return tieneAlaron; }
    int getCilindrada() const{ return cilindrada; }

    // Setters con validaciones 
    void setTieneAlaron(bool alaron){
        tieneAlaron = alaron;
    }

    void setCilindrada(int cc){
        if (cc <= 0){
            throw std::invalid_argument("  La cilindrada debe ser positiva.");
        }
        cilindrada = cc;
    }

    // mostrarInfo() sobrescrito 
    void mostrarInfo() const override{
        // Reutilizamos la lógica de la clase base
        Vehiculo::mostrarInfo();
        std::cout<<"  Tipo de Vehiculo: Motocicleta"<< std::endl;
        std::cout<<"  Tiene Alaron: "<< (tieneAlaron ? "Si" : "No")<< std::endl;
        std::cout<<"  Cilindrada: "<< cilindrada << " cc"<< std::endl;
        std::cout<<"---------------------------------"<< std::endl;
    }

    ~Motocicleta() override = default;
};

//  Clase base Empleado.

class Empleado{
protected: // protected para acceso directo en clases derivadas
    std::string nombreCompleto;
    std::string numeroEmpleado;
    double salarioBase;

public:
    // Constructor
    Empleado(const std::string& nombre, const std::string& num, double salario){
        setNombreCompleto(nombre);
        setNumeroEmpleado(num);
        setSalarioBase(salario);
    }

    // Getters
    std::string getNombreCompleto() const{ return nombreCompleto; }
    std::string getNumeroEmpleado() const{ return numeroEmpleado; }
    double getSalarioBase() const{ return salarioBase; }

    // Setters con validaciones
    void setNombreCompleto(const std::string& nombre){
        if (nombre.empty()) throw std::invalid_argument("  Nombre no valido.");
        nombreCompleto = nombre;
    }
    void setNumeroEmpleado(const std::string& num){
        if (num.empty()) throw std::invalid_argument("  Numero de empleado no valido.");
        numeroEmpleado = num;
    }
    void setSalarioBase(double salario){
        if (salario < 0) throw std::invalid_argument("  Salario base no puede ser negativo.");
        salarioBase = salario;
    }

    // Métodos virtuales 
    virtual double calcularSalarioTotal() const = 0;
    virtual void mostrarInfo() const{
        std::cout<<"\n--- Empleado ---"<< std::endl;
        std::cout<<"  Nombre: "<< nombreCompleto<< std::endl;
        std::cout<<"  Nro Empleado: "<< numeroEmpleado<< std::endl;
    }

    // Destructor virtual
    virtual ~Empleado() = default;
};

//   Clase EmpleadoTiempoCompleto que hereda de Empleado.

class EmpleadoTiempoCompleto : public Empleado{
private:
    std::string beneficios;
    double bono;

public:
    // Constructor
    EmpleadoTiempoCompleto(const std::string& nombre, const std::string& num, double salario,
                           const std::string& beneficios, double bono)
        : Empleado(nombre, num, salario){
        setBeneficios(beneficios);
        setBono(bono);
    }

    // Getters y Setters con validación
    std::string getBeneficios() const{ return beneficios; }
    double getBono() const { return bono; }

    void setBeneficios(const std::string& b){
        if (b.empty()) throw std::invalid_argument("  Beneficios no validos.");
        beneficios = b;
    }
    void setBono(double b){
        if (b < 0) throw std::invalid_argument("  El bono no puede ser negativo.");
        bono = b;
    }

    // calcularSalarioTotal() sobrescrito
    double calcularSalarioTotal() const override {
        return salarioBase + bono;
    }

    // mostrarInfo() sobrescrito
    void mostrarInfo() const override{
        Empleado::mostrarInfo();
        std::cout << "  Tipo: Tiempo Completo" << std::endl;
        std::cout << "  Salario Base: $" << std::fixed << std::setprecision(2) << salarioBase << std::endl;
        std::cout << "  Bono: $" << std::fixed << std::setprecision(2) << bono << std::endl;
        std::cout << "  Beneficios: " << beneficios << std::endl;
        std::cout << "---------------------------------" << std::endl;
    }

    ~EmpleadoTiempoCompleto() override = default;
};

//   Clase EmpleadoPorHoras que hereda de Empleado.

class EmpleadoPorHoras : public Empleado {
private:
    int horasTrabajadas;
    double tarifaPorHora;

public:
    // Constructor (Salario base se ignora/pone en 0, pero se mantiene en la base)
    EmpleadoPorHoras(const std::string& nombre, const std::string& num, double salarioBase,
                     int horas, double tarifa)
        : Empleado(nombre, num, salarioBase){ // Se pasa salarioBase (aunque sea 0)
        setHorasTrabajadas(horas);
        setTarifaPorHora(tarifa);
    }

    // Getters y Setters con validación
    int getHorasTrabajadas() const{ return horasTrabajadas; }
    double getTarifaPorHora() const{ return tarifaPorHora; }

    void setHorasTrabajadas(int h){
        if (h < 0) throw std::invalid_argument("  Las horas trabajadas no pueden ser negativas.");
        horasTrabajadas = h;
    }
    void setTarifaPorHora(double t){
        if (t < 0) throw std::invalid_argument("  La tarifa por hora no puede ser negativa.");
        tarifaPorHora = t;
    }

    // calcularSalarioTotal() sobrescrito
    double calcularSalarioTotal() const override {
        return horasTrabajadas * tarifaPorHora;
    }

    // mostrarInfo() sobrescrito
    void mostrarInfo() const override {
        Empleado::mostrarInfo();
        std::cout<<"  Tipo: Por Horas"<< std::endl;
        std::cout<<"  Tarifa por Hora: $"<< std::fixed<< std::setprecision(2)<< tarifaPorHora<< std::endl;
        std::cout<<"  Horas Trabajadas: "<< horasTrabajadas<< std::endl;
        std::cout<<"---------------------------------"<< std::endl;
    }

    ~EmpleadoPorHoras() override = default;
};


//------------NIVEL 3-----------------------
//      Clase base Animal.

class Animal{
protected:
    std::string nombre;
    int edad;
    double peso;

public:
    // Constructor
    Animal(const std::string& nombre, int edad, double peso){
        setNombre(nombre);
        setEdad(edad);
        setPeso(peso);
    }

    // Getters y Setters con validaciones
    std::string getNombre() const{ return nombre; }
    int getEdad() const{ return edad; }
    double getPeso() const{ return peso; }

    void setNombre(const std::string& n){
        if (n.empty()) throw std::invalid_argument("   El nombre no puede estar vacio.");
        nombre= n;
    }
    void setEdad(int e){
        if (e < 0) throw std::invalid_argument("   La edad no puede ser negativa.");
        edad= e;
    }
    void setPeso(double p){
        if (p <= 0) throw std::invalid_argument("   El peso debe ser positivo.");
        peso= p;
    }

    //  Métodos virtuales 
    virtual void hacerSonido() const= 0;
    virtual void mostrarInfo() const{
        std::cout<<" \n--- Animal (" << nombre << ") ---" << std::endl;
        std::cout<<"  Edad: "<< edad<< " años" << std::endl;
        std::cout<<"  Peso: "<< std::fixed<< std::setprecision(1)<< peso<< " kg" << std::endl;
    }

    virtual ~Animal() = default;
};

// Clase intermedia Mamifero (hereda de Animal).

class Mamifero : public Animal{
protected:
    bool tieneColaMamifero;

public:
    Mamifero(const std::string& nombre, int edad, double peso, bool tieneCola)
        : Animal(nombre, edad, peso), tieneColaMamifero(tieneCola) {}

    bool getTieneColaMamifero() const{ return tieneColaMamifero; }
    void setTieneColaMamifero(bool tieneCola){ tieneColaMamifero = tieneCola; }

    void mostrarInfo() const override{
        Animal::mostrarInfo();
        std::cout<<"  Clase: Mamifero"<< std::endl;
        std::cout<<"  Tiene Cola: "<< (tieneColaMamifero ? "Si" : "No")<< std::endl;
    }

    // Se implementa "hacerSonido aquí" en las clases finales.
    // virtual void hacerSonido() const override = 0; 
    virtual ~Mamifero() = default;
};

//  Clase intermedia Ave (hereda de Animal).

class Ave : public Animal{
protected:
    double envergaduraAlas;

public:
    Ave(const std::string& nombre, int edad, double peso, double envergadura)
        : Animal(nombre, edad, peso){
        setEnvergaduraAlas(envergadura);
    }

    double getEnvergaduraAlas() const{ return envergaduraAlas; }
    void setEnvergaduraAlas(double e){
        if (e <= 0) throw std::invalid_argument("   Envergadura debe ser positiva.");
        envergaduraAlas = e;
    }

    void mostrarInfo() const override{
        Animal::mostrarInfo();
        std::cout<< "  Clase: Ave" << std::endl;
        std::cout<< "  Envergadura Alas: "<< std::fixed<< std::setprecision(2)<< envergaduraAlas<< " metros"<< std::endl;
    }

    virtual ~Ave() = default;
};

//-------  CLASES FINALES   --------------------------------------------

class Perro final : public Mamifero{
public:
    Perro(const std::string& nombre, int edad, double peso, bool tieneCola)
        : Mamifero(nombre, edad, peso, tieneCola) {}

    void hacerSonido() const override{
        std::cout<<"  Sonido: ¡Ladrando!  "<< std::endl;
    }
    void mostrarInfo() const override{
        Mamifero::mostrarInfo();
        std::cout<<"  Especie: Perro"<< std::endl;
        std::cout<<"-------------------------------"<< std::endl;
    }
};

class Gato final : public Mamifero{
public:
    Gato(const std::string& nombre, int edad, double peso, bool tieneCola)
        : Mamifero(nombre, edad, peso, tieneCola) {}

    void hacerSonido() const override {
        std::cout<<"  Sonido: ¡Maullando!" << std::endl;
    }
    void mostrarInfo() const override {
        Mamifero::mostrarInfo();
        std::cout << "  Especie: Gato" << std::endl;
        std::cout << "-------------------------------" << std::endl;
    }
};

class Loro final : public Ave{
public:
    Loro(const std::string& nombre, int edad, double peso, double envergadura)
        : Ave(nombre, edad, peso, envergadura) {}

    void hacerSonido() const override {
        std::cout<<"  Sonido: ¡Canta e imita sonidos!" << std::endl;
    }
    void mostrarInfo() const override {
        Ave::mostrarInfo();
        std::cout<<"  Especie: Loro" << std::endl;
        std::cout<<"-------------------------------" << std::endl;
    }
};

class Aguila final : public Ave{
public:
    Aguila(const std::string& nombre, int edad, double peso, double envergadura)
        : Ave(nombre, edad, peso, envergadura) {}

    void hacerSonido() const override {
        std::cout<<"  Sonido: ¡Grito fuerte!" << std::endl;
    }
    void mostrarInfo() const override {
        Ave::mostrarInfo();
        std::cout<<"  Especie: Aguila" << std::endl;
        std::cout<<"-------------------------------" << std::endl;
    }
};


//    Clase base Cuenta-----bancaria

class Cuenta{
protected:
    std::string numeroCuenta;
    std::string propietario;
    double saldo;

public:
    // Constructor
    Cuenta(const std::string& num, const std::string& prop, double sal){
        setNumeroCuenta(num);
        setPropietario(prop);
        setSaldo(sal);
    }

    // Getters
    std::string getNumeroCuenta() const{ return numeroCuenta; }
    std::string getPropietario() const{ return propietario; }
    double getSaldo() const { return saldo; }

    // Setters con validaciones
    void setNumeroCuenta(const std::string& num){
        if (num.empty()) throw std::invalid_argument("  Numero de cuenta no puede estar vacio.");
        numeroCuenta = num;
    }
    void setPropietario(const std::string& prop){
        if (prop.empty()) throw std::invalid_argument("  Propietario no puede estar vacio.");
        propietario = prop;
    }
    void setSaldo(double sal) {
        if (sal < 0) throw std::invalid_argument("  El saldo inicial no puede ser negativo.");
        saldo = sal;
    }

    //  Métodos virtuales 
    virtual void depositar(double monto){
        if (monto <= 0){
            throw std::invalid_argument("  El monto a depositar debe ser positivo.");
        }
        saldo += monto;
        std::cout<<"  Deposito de $"<< std::fixed<< std::setprecision(2)<< monto<<" realizado."<< std::endl;
    }

    virtual void retirar(double monto){
        if (monto <= 0){
            throw std::invalid_argument("  El monto a retirar debe ser positivo.");
        }
        if (monto > saldo){
            throw std::runtime_error("  Saldo insuficiente para retirar $" + std::to_string(monto));
        }
        saldo -= monto;
        std::cout<<"  Retiro de $" <<std::fixed<< std::setprecision(2)<< monto<< " realizado."<< std::endl;
    }

    virtual void mostrarInfo() const {
        std::cout << "\n---Informacion de la Cuenta---" << std::endl;
        std::cout << "  Numero: " << numeroCuenta << std::endl;
        std::cout << "  Propietario: " << propietario << std::endl;
        std::cout << "  Saldo Actual: $" << std::fixed << std::setprecision(2) << saldo << std::endl;
    }

    virtual ~Cuenta() = default;
};

//   Clase CuentaAhorro que hereda de Cuenta.
 
class CuentaAhorro : public Cuenta{
private:
    double tasaInteres;

public:
    CuentaAhorro(const std::string& num, const std::string& prop, double sal, double tasa)
        : Cuenta(num, prop, sal) {
        setTasaInteres(tasa);
    }

    double getTasaInteres() const{ return tasaInteres; }
    void setTasaInteres(double t){
        if (t < 0) throw std::invalid_argument("  La tasa de interes no puede ser negativa.");
        tasaInteres = t;
    }

    // Método generarInteres()
    void generarInteres() {
        double interesGenerado = saldo * tasaInteres;
        saldo += interesGenerado;
        std::cout<< "  Interes generado (" << tasaInteres * 100 << "%): $"<< std::fixed<< std::setprecision(2)<< interesGenerado<< std::endl;
    }

    // Sobrescribir depositar()
    void depositar(double monto) override {
        std::cout<< "  Cuenta Ahorro: ";
        Cuenta::depositar(monto);
    }

    // Sobrescribir retirar()
    void retirar(double monto) override {
        std::cout << "  Cuenta Ahorro: ";
        Cuenta::retirar(monto);
    }

    void mostrarInfo() const override {
        Cuenta::mostrarInfo();
        std::cout<< "  Tipo: Cuenta de Ahorro"<< std::endl;
        std::cout<< "  Tasa de Interes: "<< std::fixed<< std::setprecision(2)<< tasaInteres * 100 << "%"<< std::endl;
        std::cout<< "---------------------------------"<< std::endl;
    }

    ~CuentaAhorro() override = default;
};

//  Clase CuentaCorriente que hereda de Cuenta.

class CuentaCorriente : public Cuenta{
private:
    double limiteDescubierto;

public:
    CuentaCorriente(const std::string& num, const std::string& prop, double sal, double limite)
        : Cuenta(num, prop, sal){
        setLimiteDescubierto(limite);
    }

    double getLimiteDescubierto() const { return limiteDescubierto; }
    void setLimiteDescubierto(double l) {
        if (l < 0) throw std::invalid_argument("  El limite descubierto no puede ser negativo.");
        limiteDescubierto = l;
    }

    // Método solicitar Descubierto (deuda)
    bool solicitarDescubierto(double monto) {
        // Se permite el retiro si el saldo actual - el monto no excede el límite descubierto
        if (saldo - monto >= -limiteDescubierto) {
            saldo -= monto;
            std::cout<<"  Retiro con descubierto de $"<< std::fixed<< std::setprecision(2)<< monto<<" realizado."<< std::endl;
            return true;
        } else {
            std::cout<<"  ERROR: El retiro de $"<< std::fixed<< std::setprecision(2)<< monto<<" excede el limite de descubierto de $"<< limiteDescubierto << std::endl;
            return false;
        }
    }

    // Sobrescribir depositar
    void depositar(double monto) override{
        std::cout<< "  Cuenta Corriente: ";
        Cuenta::depositar(monto);
    }

    // Sobrescribir retirar, Añadiendo descubierto (saldo negativo)
    void retirar(double monto) override{
        if (monto <= 0){
            throw std::invalid_argument("  El monto a retirar debe ser positivo.");
        }
        if (monto <= saldo){
            Cuenta::retirar(monto); // Llama al método base si hay saldo suficiente
        } else {
            std::cout<<"  Cuenta Corriente (Sin saldo suficiente, intentando descubierto): ";
            solicitarDescubierto(monto);
        }
    }

    void mostrarInfo() const override{
        Cuenta::mostrarInfo();
        std::cout<<"  Tipo: Cuenta Corriente"<< std::endl;
        std::cout<<"  Limite Descubierto: $"<< std::fixed<< std::setprecision(2)<< limiteDescubierto<< std::endl;
        std::cout<<"---------------------------------"<< std::endl;
    }

    ~CuentaCorriente() override = default;
};


//------------NIVEL 4-----------------------------------

#include <vector>
#include <numeric> 

//   Clase que representa un Curso, usada dentro de Estudiante.
 
class Curso {
private:
    std::string codigo;
    std::string nombre;
    int creditos;
    std::string profesor;
    double calificacion; // 0.0 por defecto

public:
    Curso(const std::string& cod, const std::string& nom, int cred, const std::string& prof)
        : codigo(cod), nombre(nom), creditos(cred), profesor(prof), calificacion(0.0) {
        if (cred <= 0) throw std::invalid_argument("  Creditos deben ser positivos.");
    }

    // Getters
    std::string getCodigo() const{ return codigo; }
    std::string getNombre() const{ return nombre; }
    int getCreditos() const{ return creditos; }
    std::string getProfesor() const{ return profesor; }
    double getCalificacion() const{ return calificacion; }

    // Setter de Calificacion con validacion
    void setCalificacion(double cal){
        if (cal < 0 || cal > 5.0) throw std::invalid_argument("  Calificacion fuera del rango [0.0, 5.0].");
        calificacion = cal;
    }

    void mostrarInfo() const{
        std::cout<< "    - "<< codigo<< ": "<< nombre<< " ("<< creditos<< " creditos). Prof: "<< profesor;
        if (calificacion > 0) {
             std::cout<< " | Calificacion: "<< std::fixed<< std::setprecision(1)<< calificacion<< std::endl;
        } else {
            std::cout<< std::endl;
        }
    }
};

//           Clase Base: Persona 

class Persona{
protected:
    std::string nombre;
    int edad;
    std::string cedula;

public:
    Persona(const std::string& n, int e, const std::string& c){
        setNombre(n);
        setEdad(e);
        setCedula(c);
    }

    // Getters y Setters
    std::string getNombre() const{ return nombre; }
    int getEdad() const{ return edad; }
    std::string getCedula() const{ return cedula; }

    void setNombre(const std::string& n){
        if (n.empty()) throw std::invalid_argument("  Nombre no valido.");
        nombre = n;
    }
    void setEdad(int e){
        if (e < 0) throw std::invalid_argument("  Edad no valida.");
        edad = e;
    }
    void setCedula(const std::string& c){
        if (c.empty()) throw std::invalid_argument("  Cedula no valida.");
        cedula = c;
    }

    //  mostrarInfo() virtual
    virtual void mostrarInfo() const{
        std::cout<< "\n ---Persona---"<< std::endl;
        std::cout<< "  Nombre: "<< nombre<< std::endl;
        std::cout<< "  Edad: "<< edad<< " años" << std::endl;
        std::cout<< "  Cedula: "<< cedula<< std::endl;
    }

    virtual ~Persona() = default;
};

//     Clases Derivadas de Persona 

class Estudiante : public Persona{
private:
    std::string carrera;
    double promedio;
    int semestre;
    std::vector<Curso> cursosMatriculados; // Composición

public:
    Estudiante(const std::string& n, int e, const std::string& c, const std::string& car, double prom, int sem)
        : Persona(n, e, c){
        setCarrera(car);
        setPromedio(prom);
        setSemestre(sem);
    }

    // Getters y Setters (con validación para promedio y semestre)
    std::string getCarrera() const{ return carrera; }
    double getPromedio() const{ return promedio; }
    int getSemestre() const{ return semestre; }

    void setCarrera(const std::string& car){
        if (car.empty()) throw std::invalid_argument("  Carrera no valida.");
        carrera = car;
    }
    void setPromedio(double prom) {
        if (prom < 0.0 || prom > 5.0) throw std::invalid_argument("  Promedio debe estar en [0.0, 5.0].");
        promedio = prom;
    }
    void setSemestre(int sem) {
        if (sem <= 0) throw std::invalid_argument("  Semestre debe ser positivo.");
        semestre = sem;
    }

    // Método para matricular cursos
    void matricularCurso(const Curso& curso) {
        cursosMatriculados.push_back(curso);
        std::cout<<"  "<<nombre<< "  matriculo el curso "<< curso.getNombre()<< "."<< std::endl;
    }

    // Método para ver calificaciones 
    void verCalificaciones() const{
        std::cout<<"\n--- Calificaciones de "<< nombre<< " ---"<< std::endl;
        for (const auto& curso : cursosMatriculados){
            curso.mostrarInfo();
        }
    }

    // Estudiante::calcularPromedioActual()
    double calcularPromedioActual() const{
        if (cursosMatriculados.empty()) return 0.0;
        
        double sumaCalificaciones = 0.0;
        int totalCreditos = 0;
        
        for (const auto& curso : cursosMatriculados){
            // Nota: es ponderado por créditos
            if (curso.getCalificacion() > 0) { // Solo si tiene nota
                sumaCalificaciones += curso.getCalificacion() * curso.getCreditos();
                totalCreditos += curso.getCreditos();
            }
        }
        
        if (totalCreditos == 0) return 0.0;
        
        return sumaCalificaciones / totalCreditos;
    }

    void mostrarInfo() const override{
        Persona::mostrarInfo();
        std::cout<<"  Rol: Estudiante"<< std::endl;
        std::cout<<"  Carrera: "<< carrera<< std::endl;
        std::cout<<"  Semestre: "<< semestre<< std::endl;
        std::cout<<"  Promedio General: "<< std::fixed<< std::setprecision(2)<< promedio<< std::endl;
        std::cout<<"---------------------------------"<< std::endl;
    }
};

class Profesor : public Persona{
private:
    std::string especialidad;
    int añosExperiencia;
    int numeroEstudiantes;

public:
    Profesor(const std::string& n, int e, const std::string& c, const std::string& esp, int años, int numEst)
        : Persona(n, e, c){
        setEspecialidad(esp);
        setAñosExperiencia(años);
        setNumeroEstudiantes(numEst);
    }

    // Getters y Setters
    std::string getEspecialidad() const{ return especialidad; }
    int getAñosExperiencia() const{ return añosExperiencia; }
    int getNumeroEstudiantes() const{ return numeroEstudiantes; }

    void setEspecialidad(const std::string& esp){
        if (esp.empty()) throw std::invalid_argument("  Especialidad no valida.");
        especialidad= esp;
    }
    void setAñosExperiencia(int años){
        if (años < 0) throw std::invalid_argument("  Años de experiencia no validos.");
        añosExperiencia= años;
    }
    void setNumeroEstudiantes(int numEst){
        if (numEst < 0) throw std::invalid_argument("  Numero de estudiantes no valido.");
        numeroEstudiantes= numEst;
    }

    // Profesor::estaDisponible(int horaDelDía)
    bool estaDisponible(int horaDelDia) const{
        // el profesor solo trabaja de 8 a 17 horas, con 1 hora libre al mediodía (12 AM - 1 PM)
        return (horaDelDia >= 8 && horaDelDia < 12) || (horaDelDia >= 13 && horaDelDia < 17);
    }

    void mostrarInfo() const override {
        Persona::mostrarInfo();
        std::cout<<"  Rol: Profesor"<< std::endl;
        std::cout<<"  Especialidad: "<< especialidad<< std::endl;
        std::cout<<"  Años Experiencia: "<< añosExperiencia<< std::endl;
        std::cout<<"  Estudiantes Asignados: "<< numeroEstudiantes<< std::endl;
        std::cout<<"---------------------------------"<< std::endl;
    }
};

class Personal : public Persona{
private:
    std::string puesto;
    std::string departamento;
    double salario;

public:
    Personal(const std::string& n, int e, const std::string& c, const std::string& pto, const std::string& dep, double sal)
        : Persona(n, e, c) {
        setPuesto(pto);
        setDepartamento(dep);
        setSalario(sal);
    }

    // Getters y Setters
    std::string getPuesto() const{ return puesto; }
    std::string getDepartamento() const{ return departamento; }
    double getSalario() const{ return salario; }

    void setPuesto(const std::string& pto){
        if (pto.empty()) throw std::invalid_argument("  Puesto no valido.");
        puesto= pto;
    }
    void setDepartamento(const std::string& dep){
        if (dep.empty()) throw std::invalid_argument("  Departamento no valido.");
        departamento= dep;
    }
    void setSalario(double sal){
        if (sal < 0) throw std::invalid_argument("  Salario no puede ser negativo.");
        salario= sal; // Salario base mensual
    }

    // Personal::calcularSalarioMensual()
    double calcularSalarioMensual() const {
        return salario; 
    }

    void mostrarInfo() const override {
        Persona::mostrarInfo();
        std::cout<<"  Rol: Personal Administrativo"<< std::endl;
        std::cout<<"  Departamento: "<< departamento<< std::endl;
        std::cout<<"  Cargo: "<< puesto<< std::endl;
        std::cout<<"  Salario Mensual: $"<< std::fixed<< std::setprecision(2)<< calcularSalarioMensual()<< std::endl;
        std::cout<<"---------------------------------"<< std::endl;
    }
};

//--------SALIDA DE LA FUNCION PRINCIPAL (MAIN)--------
//-----------------------------------------------------

void ejecutarPruebas(){
    
    std::cout<<"\n=============  EJERCICIOS   ============"<< std::endl;
    
    try{
        // Nivel 1.1: Clase Vehículo 
        std::cout<<"\n---Nivel 1.1: Clase Vehiculo---"<< std::endl;
        Vehiculo auto1("Ferrari", "PuraSangre", 2024, 280.0);
        auto1.mostrarInfo();
        auto1.acelerar(20.5); //Aumenta la velocidad máxima
        auto1.mostrarInfo();
        // Prueba de validación
        // auto1.setAño(1800); //Esto lanzaría una excepción

        // Nivel 1.2: Clase Producto
        std::cout<<"\n---Nivel 1.2: Clase Producto---"<< std::endl;
        Producto laptop("001", "Laptop ASUS", 1500000, 5);
        laptop.mostrarInfo();
        std::cout<<"  Valor total en inventario: $"<< std::fixed<< std::setprecision(2)<< laptop.calcularValorTotal()<< std::endl;
        laptop.aplicarDescuento(10.0); // 10% de descuento
        laptop.mostrarInfo();

        // Nivel 2.1: Herencia de Vehículos
        std::cout<<"\n---Nivel 2.1: Herencia de Vehiculos---"<< std::endl;
        Auto miAuto("Chevrolet", "GT", 2025, 180.0, 4, "Gasolina");
        Motocicleta miMoto("Suzuki", "Prado", 2024, 200.0, true, 750);

        // Se llama el mostrarInfo()
        miAuto.mostrarInfo();
        miMoto.mostrarInfo();

        // Nivel 2.2: Sistema de Empleados 
        std::cout<< "\n--- Nivel 2.2: Sistema de Empleados ---"<< std::endl;
        EmpleadoTiempoCompleto emp1("Juan Lopez", "001", 40000.0, "Bono", 5000000.0);
        // El salario base se pone en 0 para el por horas, ya que no se usa, pero se pasa al constructor base.
        EmpleadoPorHoras emp2("Maria Garcia", "002", 0.0, 48, 36000.0); 

        emp1.mostrarInfo();
        std::cout<<"  Salario Total: $"<< std::fixed<< std::setprecision(2)<< emp1.calcularSalarioTotal()<< std::endl;

        emp2.mostrarInfo();
        std::cout<<"  Salario Total: $"<< std::fixed<< std::setprecision(2)<< emp2.calcularSalarioTotal()<< std::endl;

        //---Nivel 3.1: Jerarquía de Animales ---
        std::cout<<"\n--- Nivel 3.1: Jerarquia de Animales ---"<< std::endl;
        Perro perro("Roky", 5, 25.0, true);
        Gato gato("Corina", 3, 4.5, false);
        Loro loro("Lorenzo", 2, 0.5, 0.3);
        Aguila aguila("Salvaje", 3, 5, 1.28);

        perro.mostrarInfo();
        perro.hacerSonido();

        gato.mostrarInfo();
        gato.hacerSonido();

        loro.mostrarInfo();
        loro.hacerSonido();
        
        aguila.mostrarInfo();
        aguila.hacerSonido();

        //---Nivel 3.2: Sistema Bancario---
        std::cout<< "\n--- Nivel 3.2: Sistema Bancario ---"<< std::endl;
        CuentaAhorro ahorros("123456", "Alvaro", 6000000.0, 0.02);
        
        ahorros.depositar(1000000.0);
        ahorros.generarInteres();
        ahorros.mostrarInfo();
        
        CuentaCorriente corriente("789012", "Maria", 1000000.0, 1000000.0);

        corriente.retirar(1000000.0); // Retiro normal con el saldo positivo
        corriente.retirar(500000.0); // Uso de descubierto (lo que falta del retiro y le queda debiendo al banco)( 1000000 - 1500000 = -500000. Limite es -1000000)
        corriente.mostrarInfo();

        // Nivel 4.1: Sistema de Universidades
        std::cout<< "\n--- Nivel 4.1: Sistema de Universidades---"<< std::endl;

        Estudiante est1("Alvaro Pulido", 20, "123456", "Ing. Sistemas", 4.2, 5);
        Profesor prof1("Sebastian Gomez", 55, "987456", "Inteligencia Artificial", 15, 60);
        Personal pers1("Luisa Marin", 35, "789654", "Secretaria", "Admisiones", 3600000.0);

        est1.mostrarInfo();
        prof1.mostrarInfo();
        
        std::cout<<"  Profesor disponible a las 10 AM: "<< (prof1.estaDisponible(10) ? "Si" : "No")<< std::endl; // Disponible
        std::cout<<"  Profesor disponible a las 12 PM: "<< (prof1.estaDisponible(12) ? "Si" : "No")<< std::endl; // No disponible

        pers1.mostrarInfo();
        std::cout<<"  Salario Mensual de Personal: $"<< std::fixed<< std::setprecision(2)<< pers1.calcularSalarioMensual()<<std::endl;
        std::cout<<"------------------------------------------------------------"<<"\n\n";
        // Composición y Promedio
        Curso c1("A1234", "Programacion C++", 3, prof1.getNombre());
        Curso c2("B5678", "Calculo II", 4, "Lic. Carlos");
        
        est1.matricularCurso(c1);
        est1.matricularCurso(c2);
        
        // Asignar calificaciones para el cálculo
        c1.setCalificacion(4.5);
        c2.setCalificacion(3.8);
        
        // Hacemos un acceso directo para la prueba:
        est1.verCalificaciones(); 
        
        std::cout<<"\n  (Asumiendo notas actualizadas) Promedio Actual: "<< std::fixed<< std::setprecision(2)<< est1.getPromedio()<< std::endl; // Usamos el promedio inicial

    }catch (const std::invalid_argument& e){
        std::cerr<<" \n--- Error de Validacion (std::invalid_argument) ---"<< std::endl;
        std::cerr<<"  Error: "<< e.what()<< std::endl;
        std::cerr<<" -----------------------------------------------------"<< std::endl;
    }catch (const std::runtime_error& e){
        std::cerr<<" \n--- Error de Ejecucion (std::runtime_error) ---"<< std::endl;
        std::cerr<<"  Error: " << e.what() << std::endl;
        std::cerr<<" -----------------------------------------------"<< std::endl;
    }catch (const std::exception& e){
        std::cerr<<" \n--- Error Desconocido ---"<< std::endl;
        std::cerr<<"  Error: "<< e.what()<< std::endl;
        std::cerr<<" -------------------------"<< std::endl;
    }
}

int main(){
    ejecutarPruebas();
    return 0;
}
