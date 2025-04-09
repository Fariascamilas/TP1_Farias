#include "Empleado.hpp"
#include <iostream>
using namespace std;

int Empleado::getAntiguedad() const{
    return antiguedad;
}
bool Empleado::updateSalario(float newSalario){
    if (newSalario < 0){return false;}
    salario = newSalario;
    return true;
}
float Empleado::getSalario() const{
    return salario;
}

bool Manager::updateBono(float newBono){
    if (newBono < 0){return false;}
    bono = newBono;
    return true;
}
float Manager::getBono(){
    return bono;
}
bool Manager::setLevel(std::string newLevel){
    level = newLevel;
    return true;
}