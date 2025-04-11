#include <iostream>
#include "ItemMagico.hpp"
using namespace std;

ItemMagico::ItemMagico(string _name, int _timesUsed, string _oddity, int _powerLevel, int _provenance) : name(_name), timesUsed(_timesUsed), oddity(_oddity), powerLevel(_powerLevel), provenance(_provenance) {
    if (powerLevel<COMMON || powerLevel>EPIC) {throw invalid_argument("Invalid power level");}
    if (provenance<FOREST || provenance>ETERNAL_CAVES){throw invalid_argument("Invalid provenance");}
}

void ItemMagico::use(){
    timesUsed ++;
}

bool ItemMagico::isMagical() const {
    return true;
}

int ItemMagico::getDamage() {
    int damage = ((powerLevel + provenance)/2) - timesUsed;
    if (damage <= 0){ // Debe haber daño, entonces se resetea timesUsed
        this->timesUsed = 0;
        return ((powerLevel + provenance)/2);
    }
    return damage;
}

string ItemMagico::getName() const {
    return name;
}

string ItemMagico::getOddity() const {
    return oddity;
}

int ItemMagico::getTimesUsed() const {
    return timesUsed;
}

int ItemMagico::getPoewrLevel() const {
    return powerLevel;
}

int ItemMagico::getProvenance() const {
    return provenance;
}

//----------------------------------------------------------------------
Baston::Baston(string _name, string _oddity) : ItemMagico(_name, 0, _oddity, COMMON, FOREST) {}

void Baston::arcaneBurstAtack(){
    timesUsed += 2; // Conlleva a mayor desgaste que un uso común
}

void Baston::show_info() const{
    cout<<"=== [Bastón] ==="<<endl
    << "Nombre: " <<name<<endl
    << "Rareza: " <<oddity<<endl
    << "Nivel de poder: Common" <<endl
    << "Procedencia: Forest"<<endl;
}

//----------------------------------------------------------------------
LibroDeHechizos::LibroDeHechizos(string _name, string _oddity) : ItemMagico(_name, 0, _oddity, RARE, MAGIC_LIBRARY) {}

void LibroDeHechizos::forbiddenWordAtack(){
    timesUsed += 3;
}

void LibroDeHechizos::show_info() const{
    cout<<"=== [Libro de Hechizos] ==="<<endl
    << "Nombre: " <<name<<endl
    << "Rareza: " <<oddity<<endl
    << "Nivel de poder: Rare" <<endl
    << "Procedencia: Magic Library"<<endl;
}

//----------------------------------------------------------------------
Posion::Posion(string _name, string _oddity) : ItemMagico(_name, 0, _oddity, RARE, MYSTIC_FALLS) {}

void Posion::alchemicalExplosionAtack(){
    timesUsed += 2;
}

void Posion::mirrorBrewAtack(){
    timesUsed += 3;
}

void Posion::show_info() const{
    cout<<"=== [Posión] ==="<<endl
    << "Nombre: " <<name<<endl
    << "Rareza: " <<oddity<<endl
    << "Nivel de poder: Rare" <<endl
    << "Procedencia: Mystic Falls"<<endl;
}

//----------------------------------------------------------------------
Amuleto::Amuleto(string _name, string _oddity) : ItemMagico(_name, 0, _oddity, EPIC, ETERNAL_CAVES) {}

void Amuleto::soulLinkAtack(){
    timesUsed += 2;
}

void Amuleto::show_info() const {
    cout<<"=== [Amuleto] ==="<<endl
    << "Nombre: " <<name<<endl
    << "Rareza: " <<oddity<<endl
    << "Nivel de poder: Epic" <<endl
    << "Procedencia: Eternal Caves"<<endl;
}