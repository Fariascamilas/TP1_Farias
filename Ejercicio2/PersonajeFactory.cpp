#include "PersonajeFactory.hpp"
#include "CharacterGenerator.hpp"
#include "../Ejercicio1/Arma/ArmaDeCombate.hpp"
#include "../Ejercicio1/Arma/ItemMagico.hpp"
#include "../Ejercicio1/Personaje/Guerrero.hpp"
#include "../Ejercicio1/Personaje/Mago.hpp"
#include <iostream>
#include <vector>
using namespace std;

std::vector<std::string> names = {"Aelric", "Thalor", "Kaelwyn", "Dareth", "Varek", "Elandor", "Maelis", "Draven", "Nyros", "Zarion", "Vaelric", "Korwyn", "Sylthar", "Orimar", "Rhaziel", "Tarnak", "Zephir", "Malrik", "Fenros", "Caldrin", "Arenvar", "Myrden", "Kaedor", "Velmorr", "Thandor", "Eryndor", "Galrik", "Sorveth", "Zarnak", "Lareth", "Branor", "Vaedin", "Nerys", "Khorlan", "Syvar", "Drelkar", "Faelric", "Xandor", "Tyveris", "Orren"};

std::vector<std::string> habilities = {"Despertar", "Esencia", "Resonancia", "Sombra", "Impulso", "Eco", "Luz", "Vínculo", "Voluntad", "Furia", "Silencio", "Ascenso", "Colapso", "Guardia", "Llamado", "Aliento", "Destino", "Amanecer", "Caída"};

std::vector<std::string> namesWeapons = {"Umbra", "Ignaris", "Velanth", "Thoros", "Zephyrion", "Lunaris", "Duskbane", "Solmara", "Ebonflare", "Mystral", "Nerion", "Vaelshade", "Pyrralis", "Oreth", "Drakmor", "Nytheris", "Glimveil", "Xarn", "Volraith", "Aetherin"};

std::vector<std::string> oddities = {"Común", "Poco Común", "Rara", "Épica", "Legendaria", "Mítica", "Ancestral", "Arcana", "Maldita", "Divina", "Única", "Desconocida", "Inestable", "Forjada", "Perdida", "Primordial", "Infame", "Corrupta", "Celestial", "Eterna"};


unique_ptr<IPersonaje> PersonajeFactory::createPersonaje(vector<unique_ptr<IArma>> weapons, int type){
    switch(type){
        case HECHICERO:
            return make_unique<Hechicero>(names[randomNumber(0,names.size()-1)], habilities[randomNumber(0, habilities.size()-1)],move(weapons)); 
        case CONJURADOR:
            return make_unique<Conjurador>(names[randomNumber(0,names.size()-1)], habilities[randomNumber(0, habilities.size()-1)],move(weapons));
        case BRUJO:
            return make_unique<Brujo>(names[randomNumber(0,names.size()-1)], habilities[randomNumber(0, habilities.size()-1)],move(weapons));
        case NIGROMANTE:
            return make_unique<Nigromante>(names[randomNumber(0,names.size()-1)], habilities[randomNumber(0, habilities.size()-1)],move(weapons));
        case BARBARO:
            return make_unique<Barbaro>(names[randomNumber(0,names.size()-1)], habilities[randomNumber(0, habilities.size()-1)],move(weapons)); 
        case PALADIN:
            return make_unique<Paladin>(names[randomNumber(0,names.size()-1)], habilities[randomNumber(0, habilities.size()-1)],move(weapons));
        case CABALLERO:
            return make_unique<Caballero>(names[randomNumber(0,names.size()-1)], habilities[randomNumber(0, habilities.size()-1)],move(weapons));
        case MERCENARIO:
            return make_unique<Mercenario>(names[randomNumber(0,names.size()-1)], habilities[randomNumber(0, habilities.size()-1)],move(weapons));
        case GLADIADOR:
            return make_unique<Gladiador>(names[randomNumber(0,names.size()-1)], habilities[randomNumber(0, habilities.size()-1)],move(weapons));
        default:
            return nullptr;
    }
}

unique_ptr<IArma> PersonajeFactory::createArma(int type){
    switch(type){
        case BASTON:
            return make_unique<Baston>(namesWeapons[randomNumber(0,namesWeapons.size()-1)], oddities[randomNumber(0, oddities.size()-1)]); 
        case LIBRO_DE_HECHIZOS:
            return make_unique<LibroDeHechizos>(namesWeapons[randomNumber(0,namesWeapons.size()-1)], oddities[randomNumber(0, oddities.size()-1)]);
        case POSION:
            return make_unique<Posion>(namesWeapons[randomNumber(0,namesWeapons.size()-1)], oddities[randomNumber(0, oddities.size()-1)]);
        case AMULETO:
            return make_unique<Amuleto>(namesWeapons[randomNumber(0,namesWeapons.size()-1)], oddities[randomNumber(0, oddities.size()-1)]);
        case HACHA_SIMPLE:
            return make_unique<HachaSimple>(namesWeapons[randomNumber(0,namesWeapons.size()-1)], oddities[randomNumber(0, oddities.size()-1)]); 
        case HACHA_DOBLE:
            return make_unique<HachaDoble>(namesWeapons[randomNumber(0,namesWeapons.size()-1)], oddities[randomNumber(0, oddities.size()-1)]);
        case ESPADA:
            return make_unique<Espada>(namesWeapons[randomNumber(0,namesWeapons.size()-1)], oddities[randomNumber(0, oddities.size()-1)]);
        case LANZA:
            return make_unique<Lanza>(namesWeapons[randomNumber(0,namesWeapons.size()-1)], oddities[randomNumber(0, oddities.size()-1)]);
        case GARROTE:
            return make_unique<Garrote>(namesWeapons[randomNumber(0,namesWeapons.size()-1)], oddities[randomNumber(0, oddities.size()-1)]);
        default:
            return nullptr;
    }
}

unique_ptr<IPersonaje> PersonajeFactory::createArmedPersonaje(int typeCharacter){
    std::vector<unique_ptr<IArma>> weapons;
    weapons.push_back(PersonajeFactory::createArma(randomNumber(0,8)));
    weapons.push_back(PersonajeFactory::createArma(randomNumber(0,8)));
    auto newpersonaje=createPersonaje(move(weapons), typeCharacter);
    return newpersonaje;
}