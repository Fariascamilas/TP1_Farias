#include <iostream>
#include "ArmaDeCombate.hpp"
using namespace std;

ArmaDeCombate::ArmaDeCombate(string _name, int _timesUsed, string _oddity, int _powerLevel, int _material) : name(_name), timesUsed(_timesUsed), oddity(_oddity), powerLevel(_powerLevel), material(_material) {
    if (powerLevel<COMMON || powerLevel>EPIC) {throw invalid_argument("Invalid power level");}
    if (material<WOOD || material>IRON){throw invalid_argument("Invalid provenance");}
}

void ArmaDeCombate::use() {
    timesUsed++;
}

bool ArmaDeCombate::isMagical() const {
    return false;
}

int ArmaDeCombate::getDamage() {
    int damage = ((powerLevel + material)/2) - timesUsed;
    if (damage <= 0){ // Debe haber daño, entonces se resetea timesUsed
        this->timesUsed = 0;
        return ((powerLevel + material)/2);
    }
    return damage;
}

string ArmaDeCombate::getName() const {
    return name;
}

string ArmaDeCombate::getOddity() const {
    return oddity;
}

int ArmaDeCombate::getTimesUsed() const {
    return timesUsed;
}

int ArmaDeCombate::getPoewrLevel() const {
    return powerLevel;
}

int ArmaDeCombate::getMaterial() const {
    return material;
}

//----------------------------------------------------------------------
HachaSimple::HachaSimple(string _name, string _oddity): ArmaDeCombate(_name, 0, _oddity, RARE, IRON) {}

void HachaSimple::show_info() const {
    cout<<"=== [Hacha Simple] ==="<<endl
    << "Nombre: " <<name<<endl
    << "Rareza: " <<oddity<<endl
    << "Nivel de poder: Rare" <<endl
    << "Material: Iron"<<endl;
}

void HachaSimple::wildBreakAtack(){
    timesUsed += 2;
}

//----------------------------------------------------------------------
HachaDoble::HachaDoble(string _name, string _oddity): ArmaDeCombate(_name, 0, _oddity, EPIC, IRON) {}

void HachaDoble::show_info() const {
    cout<<"=== [Hacha Doble] ==="<<endl
    << "Nombre: " <<name<<endl
    << "Rareza: " <<oddity<<endl
    << "Nivel de poder: Epic" <<endl
    << "Material: Iron"<<endl;
}

void HachaDoble::titanCleaveAtack(){
    timesUsed +=2;
}

//----------------------------------------------------------------------
Espada::Espada(string _name, string _oddity): ArmaDeCombate(_name, 0, _oddity, RARE, STEEL) {}

void Espada::show_info() const {
    cout<<"=== [Espada] ==="<<endl
    << "Nombre: " <<name<<endl
    << "Rareza: " <<oddity<<endl
    << "Nivel de poder: Rare" <<endl
    << "Material: Steel"<<endl;
}

void Espada::lightningSlashAtack(){
    timesUsed += 3;
}

//----------------------------------------------------------------------
Lanza::Lanza(string _name, string _oddity): ArmaDeCombate(_name, 0, _oddity, COMMON, STEEL) {}

void Lanza::show_info() const {
    cout<<"=== [Lanza] ==="<<endl
    << "Nombre: " <<name<<endl
    << "Rareza: " <<oddity<<endl
    << "Nivel de poder: Common" <<endl
    << "Material: Steel"<<endl;
}

void Lanza::skyLanceAtack(){
    timesUsed += 3;
}

//----------------------------------------------------------------------
Garrote::Garrote(string _name, string _oddity): ArmaDeCombate(_name, 0, _oddity, COMMON, WOOD) {}

void Garrote::show_info() const {
    cout<<"=== [Garrote] ==="<<endl
    << "Nombre: " <<name<<endl
    << "Rareza: " <<oddity<<endl
    << "Nivel de poder: Common" <<endl
    << "Material: Wood"<<endl;
}

void Garrote::earthshatterAtack(){
    timesUsed += 2;
}