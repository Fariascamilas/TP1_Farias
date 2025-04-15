#include "Guerrero.hpp"
#include "Mago.hpp"
#include "../Arma/ItemMagico.hpp"
#include "../Arma/ArmaDeCombate.hpp"
#include <iostream>
using namespace std;

Guerrero::Guerrero(string _name, vector<unique_ptr<IArma>> _weapons, int _experienceLevel, string _specialHability, int _HP) : name(_name), weapons(move(_weapons)), experienceLevel(_experienceLevel), specialHability(_specialHability), HP(_HP) {
    if (_HP < 0) {throw invalid_argument("HP inválido");}
    if (_experienceLevel < RECRUIT || _experienceLevel > LEYEND) {throw invalid_argument("Nivel de experiencia inválido");}
}

void Guerrero::decreaseHP(int damage){
    HP -= damage;
}

bool Guerrero::isAlive() const {
    if(HP>0){return true;}
    return false;
}

int Guerrero::golpeFuerte(int posWeapon) {
    if(posWeapon < 0){
        throw invalid_argument("Posición inválida");
    }
    if(weapons[posWeapon]){
        weapons[posWeapon]->use();
        return weapons[posWeapon]->getDamage()+10;
    }
    return 10;
}

int Guerrero::golpeRapido(int posWeapon) {
    if(posWeapon < 0){
        throw invalid_argument("Posición inválida");
    }
    if(weapons[posWeapon]){
        weapons[posWeapon]->use();
        return weapons[posWeapon]->getDamage()+10;
    }
    return 10;
}

int Guerrero::defensaGolpe(int posWeapon) {
    if(posWeapon < 0){
        throw invalid_argument("Posición inválida");
    }
    if(weapons[posWeapon]){
        weapons[posWeapon]->use();
        return weapons[posWeapon]->getDamage()+10;
    }
    return 10;
}

string Guerrero::getName() const{
    return name;
}

bool Guerrero::isMagical() {
    return false;
}

const vector<unique_ptr<IArma>>& Guerrero::getWeapons() const{
    return weapons;
}

int Guerrero::getExperienceLevel() const{
    return experienceLevel;
}

string Guerrero::getSpecialHability() const{
    return specialHability;
}

int Guerrero::getHP() const{
    return HP;
}

//----------------------------------------------------------------------
Barbaro::Barbaro(string _name, string _specialHability, vector<unique_ptr<IArma>> _weapons) : Guerrero(_name,  move(_weapons), CAPITAIN, _specialHability, 100){}

void Barbaro::show_info() const{
    cout<<"=== [Barbaro \U0001F9DD\u200D] ==="<<endl
    << "Nombre: " <<name<<endl
    << "Habilidad Especial: " <<specialHability<<endl
    << "\u2694 Nivel de experiencia: Capitain" <<endl
    << "\u2764 HP: " <<HP<<endl;
}

string Barbaro::unstoppableFurySaying(){
    return "Mi furia no conoce límites.";
}

//----------------------------------------------------------------------
Paladin::Paladin(string _name, string _specialHability, vector<unique_ptr<IArma>> _weapons) : Guerrero(_name,  move(_weapons), RECRUIT, _specialHability, 100){}

void Paladin::show_info() const{
    cout<<"=== [Paladin \U0001F9DD\u200D] ==="<<endl
    << "Nombre: " <<name<<endl
    << "Habilidad Especial: " <<specialHability<<endl
    << "\u2694 Nivel de experiencia: Recruit" <<endl
    << "\u2764 HP: " <<HP<<endl;
}

string Paladin::lightPrevailsSaying(){
    return "La luz ha triunfado una vez más.";
}

//----------------------------------------------------------------------
Caballero::Caballero(string _name, string _specialHability, vector<unique_ptr<IArma>> _weapons) : Guerrero(_name,  move(_weapons), CAPITAIN, _specialHability, 100){}

void Caballero::show_info() const{
    cout<<"=== [Caballero \U0001F9DD\u200D] ==="<<endl
    << "Nombre: " <<name<<endl
    << "Habilidad Especial: " <<specialHability<<endl
    << "\u2694 Nivel de experiencia: Capitain" <<endl
    << "\u2764 HP: " <<HP<<endl;
}

string Caballero::aNobleEndSaying(){
    return "Una batalla justa, una victoria digna.";
}

//----------------------------------------------------------------------
Mercenario::Mercenario(string _name, string _specialHability, vector<unique_ptr<IArma>> _weapons) : Guerrero(_name,  move(_weapons), LEYEND, _specialHability, 100){}

void Mercenario::show_info() const{
    cout<<"=== [Mercenario \U0001F9DD\u200D] ==="<<endl
    << "Nombre: " <<name<<endl
    << "Habilidad Especial: " <<specialHability<<endl
    << "\u2694 Nivel de experiencia: Leyend" <<endl
    << "\u2764 HP: " <<HP<<endl;
}

string Mercenario::dealClosedSaying(){
    return "Negocio cerrado.";
}

//----------------------------------------------------------------------
Gladiador::Gladiador(string _name, string _specialHability, vector<unique_ptr<IArma>> _weapons) : Guerrero(_name,  move(_weapons), LEYEND, _specialHability, 100) {}

void Gladiador::show_info() const{
    cout<<"=== [Gladiador \U0001F9DD\u200D] ==="<<endl
    << "Nombre: " <<name<<endl
    << "Habilidad Especial: " <<specialHability<<endl
    << "\u2694 Nivel de experiencia: Leyend" <<endl
    << "\u2764 HP: " <<HP<<endl;
}

string Gladiador::survivalIsGlorySaying(){
    return "¡Gloria eterna para el que sobrevive!";
}