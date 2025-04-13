#include "Mago.hpp"
#include "Guerrero.hpp"
#include <iostream>
using namespace std;

Mago::Mago(string _name, const array<IArma*,2>& _weapons, int _magicLevel, string _specialHability, int _HP) : name(_name), weapons(_weapons), magicLevel(_magicLevel), specialHability(_specialHability), HP(_HP){
    if (_HP < 0) {throw invalid_argument("HP inválido");}
    if (_magicLevel < APPRENTICE || _magicLevel > MASTER) {throw invalid_argument("Nivel de Magia inválido");}
}

Mago::~Mago(){
    for (auto weapon : weapons) {
        if(weapon){delete weapon;}
    }
}

void Mago::golpeFuerte(IPersonaje &other) {
    if(other.isMagical()){
        Mago* otherM = dynamic_cast<Mago*>(&other);
        otherM->HP -= 10;
        return;
    }
    Guerrero* otherG = dynamic_cast<Guerrero*>(&other);
    otherG->HP -= 10;
}

void Mago::golpeRapido(IPersonaje &other) {
    if(other.isMagical()){
        Mago* otherM = dynamic_cast<Mago*>(&other);
        otherM->HP -= 10;
        return;
    }
    Guerrero* otherG = dynamic_cast<Guerrero*>(&other);
    otherG->HP -= 10;
}

void Mago::defensaGolpe(IPersonaje &other) {
    if(other.isMagical()){
        Mago* otherM = dynamic_cast<Mago*>(&other);
        otherM->HP -= 10;
        return;
    }
    Guerrero* otherG = dynamic_cast<Guerrero*>(&other);
    otherG->HP -= 10;
}

string Mago::getName() const{
    return name;
}

bool Mago::isMagical() {
    return false;
}

const array<IArma*,2>& Mago::getWeapons() const{
    return weapons;
}

int Mago::getMagicLevel() const{
    return magicLevel;
}

string Mago::getSpecialHability() const{
    return specialHability;
}

int Mago::getHP() const{
    return HP;
}

//----------------------------------------------------------------------
Hechicero::Hechicero(string _name, string _specialHability, const array<IArma*,2>& _weapons) : Mago(_name, _weapons, APPRENTICE, _specialHability, 100){}

void Hechicero::show_info() const{
    cout<<"=== [Hechicero \U0001F9D9] ==="<<endl
    << "\u2728 Nivel de Magia: Apprentice" <<endl
    << "\u2764 HP: " <<HP<<endl;
    /*<< "Nombre: " <<name<<endl
    << "Habilidad Especial: " <<specialHability<<endl*/
}

string Hechicero::arcaneSupremacySaying(){
    return "El poder arcano nunca falla.";
}

//----------------------------------------------------------------------
Conjurador::Conjurador(string _name, string _specialHability, const array<IArma*,2>& _weapons) : Mago(_name, _weapons, SORCERER, _specialHability, 100){}

void Conjurador::show_info() const{
    cout<<"=== [Conjurador \U0001F9D9] ==="<<endl
    << "\u2728 Nivel de Magia: Sorcerer" <<endl
    << "\u2764 HP: " <<HP<<endl;
}

string Conjurador::superiorMagicSaying(){
    return "El poder arcano nunca falla.";
}

//----------------------------------------------------------------------
Brujo::Brujo(string _name, string _specialHability, const array<IArma*,2>& _weapons) : Mago(_name, _weapons, SORCERER, _specialHability, 100){}

void Brujo::show_info() const{
    cout<<"=== [Brujo \U0001F9D9] ==="<<endl
    << "\u2728 Nivel de Magia: Sorcerer" <<endl
    << "\u2764 HP: " <<HP<<endl;
}

string Brujo::tooLateSaying(){
    return "Demasiado tarde para rogar.";
}

//----------------------------------------------------------------------
Nigromante::Nigromante(string _name, string _specialHability, const array<IArma*,2>& _weapons) : Mago(_name, _weapons, MASTER, _specialHability, 100){}

void Nigromante::show_info() const{
    cout<<"=== [Nigromante \U0001F9D9] ==="<<endl
    << "\u2728 Nivel de Magia: Master" <<endl
    << "\u2764 HP: " <<HP<<endl;
}

string Nigromante::silentPrizeSaying(){
    return "Silencio eterno, mi recompensa favorita.";
}