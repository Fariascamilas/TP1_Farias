#include "PersonajeFactory.hpp"
#include "CharacterGenerator.hpp"
#include <iostream>
using namespace std;

unique_ptr<Guerrero> PersonajeFactory::createGuerrero(const array<IArma*,2>& weapons, int type){
    switch(type){
        case BARBARO:
            return make_unique<Barbaro>("Barbaro","",weapons); // Lo ideal sería que lleven diversos nombres, pero es innecesario en este caso
        case PALADIN:
            return make_unique<Paladin>("Paladin","",weapons);
        case CABALLERO:
            return make_unique<Caballero>("Caballero","",weapons);
        case MERCENARIO:
            return make_unique<Mercenario>("Mercenario","",weapons);
        case GLADIADOR:
            return make_unique<Gladiador>("Gladiador","",weapons);
        default:
            throw invalid_argument("Invalid character option");
    }
}

unique_ptr<Mago> PersonajeFactory::createMago(const array<IArma*,2>& weapons, int type){
    switch(type){
        case HECHICERO:
            return make_unique<Hechicero>("Hechicero","",weapons); 
        case CONJURADOR:
            return make_unique<Conjurador>("Conjurador","",weapons);
        case BRUJO:
            return make_unique<Brujo>("Brujo","",weapons);
        case NIGROMANTE:
            return make_unique<Nigromante>("Nigromante","",weapons);
        default:
            throw invalid_argument("Invalid character option");
    }
}

unique_ptr<ArmaDeCombate> PersonajeFactory::createArmadeCombate(int type){
    switch(type){
        case HACHA_SIMPLE:
            return make_unique<HachaSimple>("HachaSimple",""); 
        case HACHA_DOBLE:
            return make_unique<HachaDoble>("HachaDoble","");
        case ESPADA:
            return make_unique<Espada>("Espada","");
        case LANZA:
            return make_unique<Lanza>("Lanza","");
        case GARROTE:
            return make_unique<Garrote>("Garrote","");
        default:
            throw invalid_argument("Invalid character option");
    }
}

unique_ptr<ItemMagico> PersonajeFactory::createItemMagico(int type){
    switch(type){
        case BASTON:
            return make_unique<Baston>("Baston",""); 
        case LIBRO_DE_HECHIZOS:
            return make_unique<LibroDeHechizos>("LibroDeHechizos","");
        case POSION:
            return make_unique<Posion>("Posion","");
        case AMULETO:
            return make_unique<Amuleto>("Amuleto","");
        default:
            throw invalid_argument("Invalid character option");
    }
}

unique_ptr<Guerrero> PersonajeFactory::createArmedGuerrero(int typeCharacter){
    int numWeapons = cantArmas();
    array<IArma*,2> weapons = {nullptr, nullptr};
    for(int i = 0; i<numWeapons; i++){
        unique_ptr<ArmaDeCombate> weapon = createArmadeCombate(randomNumber(0,4));
        weapons[i] = weapon.release();
    }
    return createGuerrero(weapons, typeCharacter);
}

unique_ptr<Mago> PersonajeFactory::createArmedMago(int typeCharacter){
    int numWeapons = cantArmas();
    array<IArma*,2> weapons = {nullptr, nullptr};
    for(int i = 0; i<numWeapons; i++){
        unique_ptr<ItemMagico> weapon = createItemMagico(randomNumber(0,3));
        weapons[i] = weapon.release();
    }
    return createMago(weapons, typeCharacter);
}