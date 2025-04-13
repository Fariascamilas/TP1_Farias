#include "Guerrero.hpp"
#include "Mago.hpp"
#include <iostream>
using namespace std;

Guerrero::Guerrero(string _name, const std::array<IArma*,2>& _weapons, int _experienceLevel, string _specialHability, int _HP) : name(_name), weapons(_weapons), experienceLevel(_experienceLevel), specialHability(_specialHability), HP(_HP) {
    if (_HP < 0) {throw invalid_argument("HP inválido");}
    if (_experienceLevel < RECRUIT || _experienceLevel > LEYEND) {throw invalid_argument("Nivel de experiencia inválido");}
}

Guerrero::~Guerrero(){
    for (auto weapon : weapons) {
        if(weapon){delete weapon;}
    }
}

void Guerrero::golpeFuerte(IPersonaje &other) {
    if(other.isMagical()){
        Mago* otherM = dynamic_cast<Mago*>(&other);
        otherM->HP -= 10;
        return;
    }
    Guerrero* otherG = dynamic_cast<Guerrero*>(&other);
    otherG->HP -= 10;
}

void Guerrero::golpeRapido(IPersonaje &other) {
    if(other.isMagical()){
        Mago* otherM = dynamic_cast<Mago*>(&other);
        otherM->HP -= 10;
        return;
    }
    Guerrero* otherG = dynamic_cast<Guerrero*>(&other);
    otherG->HP -= 10;
}

void Guerrero::defensaGolpe(IPersonaje &other) {
    if(other.isMagical()){
        Mago* otherM = dynamic_cast<Mago*>(&other);
        otherM->HP -= 10;
        return;
    }
    Guerrero* otherG = dynamic_cast<Guerrero*>(&other);
    otherG->HP -= 10;
}

string Guerrero::getName() const{
    return name;
}

bool Guerrero::isMagical() {
    return false;
}

const std::array<IArma*,2>& Guerrero::getWeapons() const{
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
Barbaro::Barbaro(string _name, string _specialHability, const std::array<IArma*,2>& _weapons) : Guerrero(_name, _weapons, CAPITAIN, _specialHability, 100){}

void Barbaro::show_info() const{
    cout<<"=== [Barbaro \U0001F9DD\u200D] ==="<<endl
    << "\u2694 Nivel de experiencia: Capitain" <<endl
    << "\u2764 HP: " <<HP<<endl;
}

string Barbaro::unstoppableFurySaying(){
    return "Mi furia no conoce límites.";
}

//----------------------------------------------------------------------
Paladin::Paladin(string _name, string _specialHability, const std::array<IArma*,2>& _weapons) : Guerrero(_name, _weapons, RECRUIT, _specialHability, 100){}

void Paladin::show_info() const{
    cout<<"=== [Paladin \U0001F9DD\u200D] ==="<<endl
    << "\u2694 Nivel de experiencia: Recruit" <<endl
    << "\u2764 HP: " <<HP<<endl;
}

string Paladin::lightPrevailsSaying(){
    return "La luz ha triunfado una vez más.";
}

//----------------------------------------------------------------------
Caballero::Caballero(string _name, string _specialHability, const std::array<IArma*,2>& _weapons) : Guerrero(_name, _weapons, CAPITAIN, _specialHability, 100){}

void Caballero::show_info() const{
    cout<<"=== [Caballero \U0001F9DD\u200D] ==="<<endl
    << "\u2694 Nivel de experiencia: Capitain" <<endl
    << "\u2764 HP: " <<HP<<endl;
}

string Caballero::aNobleEndSaying(){
    return "Una batalla justa, una victoria digna.";
}

//----------------------------------------------------------------------
Mercenario::Mercenario(string _name, string _specialHability, const std::array<IArma*,2>& _weapons) : Guerrero(_name, _weapons, LEYEND, _specialHability, 100){}

void Mercenario::show_info() const{
    cout<<"=== [Mercenario \U0001F9DD\u200D] ==="<<endl
    << "\u2694 Nivel de experiencia: Leyend" <<endl
    << "\u2764 HP: " <<HP<<endl;
}

string Mercenario::dealClosedSaying(){
    return "Negocio cerrado.";
}

//----------------------------------------------------------------------
Gladiador::Gladiador(string _name, string _specialHability, const std::array<IArma*,2>& _weapons) : Guerrero(_name, _weapons, LEYEND, _specialHability, 100) {}

void Gladiador::show_info() const{
    cout<<"=== [Gladiador \U0001F9DD\u200D] ==="<<endl
    << "\u2694 Nivel de experiencia: Leyend" <<endl
    << "\u2764 HP: " <<HP<<endl;
}

string Gladiador::survivalIsGlorySaying(){
    return "¡Gloria eterna para el que sobrevive!";
}