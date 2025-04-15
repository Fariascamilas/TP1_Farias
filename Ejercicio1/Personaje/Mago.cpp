#include "Mago.hpp"
#include "Guerrero.hpp"
#include "../Arma/ItemMagico.hpp"
#include "../Arma/ArmaDeCombate.hpp"
#include <iostream>
using namespace std;

Mago::Mago(string _name, vector<unique_ptr<IArma>> _weapons, int _magicLevel, string _specialHability, int _HP) : name(_name), weapons(move(_weapons)), magicLevel(_magicLevel), specialHability(_specialHability), HP(_HP){
    if (_HP < 0) {throw invalid_argument("HP inválido");}
    if (_magicLevel < APPRENTICE || _magicLevel > MASTER) {throw invalid_argument("Nivel de Magia inválido");}
}

void Mago::decreaseHP(int damage){
    HP -= damage;
}

bool Mago::isAlive() const {
    if(HP>0){return true;}
    return false;
}

int Mago::golpeFuerte(int posWeapon) {
    if(posWeapon < 0){
        throw invalid_argument("Posición inválida");
    }
    if(weapons[posWeapon]){
        weapons[posWeapon]->use();
        return weapons[posWeapon]->getDamage()+10;
    }
    return 10;  // si no hay arma en esa posicion el golpe le cuesta 10 puntos de vida al oponente
}

int Mago::golpeRapido(int posWeapon) {
    if(posWeapon < 0){
        throw invalid_argument("Posición inválida");
    }
    if(weapons[posWeapon]){
        weapons[posWeapon]->use();
        return weapons[posWeapon]->getDamage()+10;
    }
    return 10;
    
    /*if(auto enemy = dynamic_cast<Guerrero*>(other.get())){ 
        if(auto w = dynamic_cast<ItemMagico*>(other.get())){
            enemy->HP -= (10 + w->getDamage());
            delete enemy;
            delete w;
            return;
        }
        auto w = dynamic_cast<ArmaDeCombate*>(other.get());
        enemy->HP -= (10 + w->getDamage()); 
        delete enemy;
        delete w;
        return;// No debo hacer delete porque es un puntero temporal, no quiero borrar el dato
    }
    auto enemy = dynamic_cast<Mago*>(other.get());
    if(auto w = dynamic_cast<ItemMagico*>(other.get())){
        enemy->HP -= (10 + w->getDamage());
        delete enemy;
        delete w;
        return;
    }
    auto w = dynamic_cast<ArmaDeCombate*>(other.get());
    enemy->HP -= (10 + w->getDamage()); 
    enemy->HP -= 10;
    delete enemy;
    delete w;
    return;*/
}

int Mago::defensaGolpe(int posWeapon) {
    if(posWeapon < 0){
        throw invalid_argument("Posición inválida");
    }
    if(weapons[posWeapon]){
        weapons[posWeapon]->use();
        return weapons[posWeapon]->getDamage()+10;
    }
    return 10;
}

string Mago::getName() const{
    return name;
}

bool Mago::isMagical() {
    return false;
}

const vector<unique_ptr<IArma>>& Mago::getWeapons() const{
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
Hechicero::Hechicero(string _name, string _specialHability, vector<unique_ptr<IArma>> _weapons) : Mago(_name, move(_weapons), APPRENTICE, _specialHability, 100){}

void Hechicero::show_info() const{
    cout<<"=== [Hechicero \U0001F9D9] ==="<<endl
    << "Nombre: " <<name<<endl
    << "Habilidad Especial: " <<specialHability<<endl
    << "\u2728 Nivel de Magia: Apprentice" <<endl
    << "\u2764 HP: " <<HP<<endl;
}

string Hechicero::arcaneSupremacySaying(){
    return "El poder arcano nunca falla.";
}

//----------------------------------------------------------------------
Conjurador::Conjurador(string _name, string _specialHability, vector<unique_ptr<IArma>> _weapons) : Mago(_name,  move(_weapons), SORCERER, _specialHability, 100){}

void Conjurador::show_info() const{
    cout<<"=== [Conjurador \U0001F9D9] ==="<<endl
    << "Nombre: " <<name<<endl
    << "Habilidad Especial: " <<specialHability<<endl
    << "\u2728 Nivel de Magia: Sorcerer" <<endl
    << "\u2764 HP: " <<HP<<endl;
}

string Conjurador::superiorMagicSaying(){
    return "El poder arcano nunca falla.";
}

//----------------------------------------------------------------------
Brujo::Brujo(string _name, string _specialHability, vector<unique_ptr<IArma>> _weapons) : Mago(_name,  move(_weapons), SORCERER, _specialHability, 100){}

void Brujo::show_info() const{
    cout<<"=== [Brujo \U0001F9D9] ==="<<endl
    << "Nombre: " <<name<<endl
    << "Habilidad Especial: " <<specialHability<<endl
    << "\u2728 Nivel de Magia: Sorcerer" <<endl
    << "\u2764 HP: " <<HP<<endl;
}

string Brujo::tooLateSaying(){
    return "Demasiado tarde para rogar.";
}

//----------------------------------------------------------------------
Nigromante::Nigromante(string _name, string _specialHability, vector<unique_ptr<IArma>> _weapons) : Mago(_name,  move(_weapons), MASTER, _specialHability, 100){}

void Nigromante::show_info() const{
    cout<<"=== [Nigromante \U0001F9D9] ==="<<endl
    << "Nombre: " <<name<<endl
    << "Habilidad Especial: " <<specialHability<<endl
    << "\u2728 Nivel de Magia: Master" <<endl
    << "\u2764 HP: " <<HP<<endl;
}

string Nigromante::silentPrizeSaying(){
    return "Silencio eterno, mi recompensa favorita.";
}