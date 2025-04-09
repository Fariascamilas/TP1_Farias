#include "Departamento.hpp"
using namespace std;

int Departamento::contarEmpleados() const{
    return cantEmpleadosDepts; // QUE ES DEPTS
}

vector<shared_ptr<Empleado>> Departamento::getEmployees() const{
    return empleados;
}

bool Departamento::contratarEmpleado(std::shared_ptr<Empleado> empleado){
    empleados.push_back(empleado);
    return true;
}

bool Departamento::despedirEmpleado(std::shared_ptr<Empleado> empleado){
    for (int i = 0; i<(empleados.size()); i++){
        if (empleados[i]->nombre == empleado->nombre){
            //todo
        }
    }
}