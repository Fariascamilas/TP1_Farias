#include <cstdlib>
#include <ctime>
#include "CharacterGenerator.hpp"
using namespace std;

int randomNumber(int min, int max){
    static bool semillaPlantada = false; // Static para que conserve su valor.
    if(!semillaPlantada){ 
        srand(static_cast<unsigned int>(time(nullptr)));
        semillaPlantada = true; // Una ves que es true, al ser static no cambia con otro llamado a randomNumber.
    } 
    int random = min + (rand() % (max - min + 1));
    return random;
}

int cantPersonajes(){
    return randomNumber(3,7);
}

int cantArmas(){
    return randomNumber(0,2);
}