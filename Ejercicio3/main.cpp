#include <iostream>
#include "../Ejercicio2/CharacterGenerator.hpp"
#include "../Ejercicio2/PersonajeFactory.hpp"
#include <vector>
#include <memory>
using namespace std;

enum Atacks {GOLPE_FUERTE, GOLPE_RAPIDO, DEFENSA_GOLPE};

int main(){
    cout<< " Bienvenido a: \U0001F3F0 \U0001F9D9 'THE LOST KINGDOM' \U0001F9DD\u200D \U0001F3F9 \n"
        << "\n    1. INICIAR JUEGO\n    2. SALIR\n\n"
        <<"Ingrese una opción: ";
    
    int choice;
    cin>>choice;
    if (choice == 2){
        cout<< "\nHASTA LUEGO! \u2728 \n";
        return 0;
    }

    // Se crea un personaje aleatorio para jugar
    // TODO

    cout<<"\n======== VAMOS A ELEGIR UN PERSONAJE ========\n";
    cout<<"En quién te convertirás? Un Mago o un Guerrero?\n\n"
        << "    1. MAGO\n    2. GUERRERO\n\n";

    cin>>choice;

    while(choice<1 || choice>2){
        cout<<"Personaje no encontrado. Por favor intentelo de nuevo...\n"
            <<"Ingrese una opción: ";
        cin>>choice;
    }

    if (choice == 1){
        cout<<"\nAhora selecciona un Mago:\n"
            << "\n    1. HECHICERO\n    2. CONJURADOR\n    3. BRUJO\n    4. NIGROMANTE\n\n"
            <<"Ingrese una opción: ";
        cin>>choice;
        while(choice>4 || choice<1){
            cout<<"Personaje no encontrado. Por favor intentelo de nuevo...\n"
                <<"Ingrese una opción: ";
            cin>>choice;
        }
        const array<IArma*,2> weapons = {nullptr,nullptr};
        if(choice-1 == HECHICERO){
            unique_ptr<Mago> character = PersonajeFactory::createMago(weapons, HECHICERO);
        }
        else if(choice-1 == CONJURADOR){
            unique_ptr<Mago> character = PersonajeFactory::createMago(weapons, CONJURADOR);
        }
        else if(choice-1 == BRUJO){
            unique_ptr<Mago> character = PersonajeFactory::createMago(weapons, BRUJO);
        }
        else if(choice-1 == NIGROMANTE){
            unique_ptr<Mago> character = PersonajeFactory::createMago(weapons, NIGROMANTE);
        }
        
    }else if(choice == 2){
        cout<<"\nAhora selecciona un Guerrero:\n"
        << "\n    1. BARBARO\n    2. PALADIN\n    3. CABALLERO\n    4. MERCENARIO\n    5. GLADIADOR\n\n"
        <<"Ingrese una opción: ";
        cin>>choice;
        while(choice>5 || choice<1){
            cout<<"Personaje no encontrado. Por favor intentelo de nuevo...\n"
            <<"Ingrese una opción: ";
            cin>>choice;
        }
        const array<IArma*,2> weapons = {nullptr,nullptr};
        if(choice-1 == BARBARO){
            unique_ptr<Guerrero> character = PersonajeFactory::createGuerrero(weapons, BARBARO);
        }
        else if(choice-1 == PALADIN){
            unique_ptr<Guerrero> character = PersonajeFactory::createGuerrero(weapons, PALADIN);
        }
        else if(choice-1 == CABALLERO){
            unique_ptr<Guerrero> character = PersonajeFactory::createGuerrero(weapons, CABALLERO);
        }
        else if(choice-1 == MERCENARIO){
            unique_ptr<Guerrero> character = PersonajeFactory::createGuerrero(weapons, MERCENARIO);
        }
        else if(choice-1 == GLADIADOR){
            unique_ptr<Guerrero> character = PersonajeFactory::createGuerrero(weapons, GLADIADOR);
        }
    }    
}