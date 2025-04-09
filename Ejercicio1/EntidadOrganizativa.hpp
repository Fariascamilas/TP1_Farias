#pragma once
#include <string>
#include <vector>
using namespace std;

// Ver:
// A donde agregar constructores y destructores
// Cuales metodos son virtuales puros y cuales no y por que
// Donde poner private protected y public

class EntidadOrganizativa{
public:
    EntidadOrganizativa(string _nombre,vector<EntidadOrganizativa*> subidentidades);
    virtual ~EntidadOrganizativa() = default;
    
    string nombre;  

    virtual void agregarSubentidad(EntidadOrganizativa* subentidades);
    virtual int contarSubentidades() const;

private:
    vector<EntidadOrganizativa*> subidentidades; 
}; 

class CentralRegional : public EntidadOrganizativa{
public:
    string direccion;

    // Necesito crear la clase departamento oara seguir
};

class Empresa : public EntidadOrganizativa{

};

/*
- Nota:
En una clase abstracta suele haber un constructor (generalmente protected) y un destructor virtual (a veces puro para forzar la abstracción del todo). Los subclases heredan el constructor base, pero típicamente necesitan sus propios constructores si requieren inicialización adicional. Los métodos que quieras forzar a implementar se declaran como virtuales puros. Los que tengan comportamiento por defecto y puedan sobreescribirse se declaran como virtuales simples. Atributos y métodos deben ser privados si solo la clase los usa internamente, protegidos si necesitan ser accesibles desde derivadas y públicos si son parte de la interfaz externa.
*/