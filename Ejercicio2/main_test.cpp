#include <iostream>
#include <vector>
#include <memory>
#include "CharacterGenerator.hpp"
#include "PersonajeFactory.hpp"

using namespace std;

int main() {
    cout << "=== Test de CharacterGenerator y PersonajeFactory ===" << endl;
    
    // 1. Prueba de randomNumber: generar algunos números aleatorios.
    cout << "\n-- Probando randomNumber (valores entre 1 y 100) --" << endl;
    for (int i = 0; i < 5; i++) {
        int n = randomNumber(1, 100);
        cout << "Número aleatorio " << i+1 << ": " << n << endl;
    }
    
    // 2. Crear personajes armados usando PersonajeFactory para todos los tipos disponibles.
    cout << "\n-- Creando personajes armados con PersonajeFactory --" << endl;
    for (int tipo = HECHICERO; tipo <= GLADIADOR; tipo++) {
        auto personaje = PersonajeFactory::createArmedPersonaje(tipo);
        cout << "\nTipo de personaje (" << tipo << "):" << endl;
        personaje->show_info();
    }
    
    // 3. Creación manual de un personaje a partir de un arma específico.
    cout << "\n-- Creación manual de un personaje --" << endl;
    vector<unique_ptr<IArma>> armas;
    // Se crea un arma específico (por ejemplo, ESPADA)
    armas.push_back(PersonajeFactory::createArma(ESPADA));
    // Se crea un personaje de tipo BRUJO (índice 2 en el enum Personajes)
    auto personajeManual = PersonajeFactory::createPersonaje(move(armas), BRUJO);
    personajeManual->show_info();
    
    cout << "\nPrueba completada." << endl;
    return 0;
}