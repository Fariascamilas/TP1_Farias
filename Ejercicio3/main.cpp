#include <iostream>
#include "../Ejercicio2/CharacterGenerator.hpp"
#include "../Ejercicio2/PersonajeFactory.hpp"
#include <vector>
#include <memory>
#include <cstdlib>

using namespace std;

enum Atacks {GOLPE_FUERTE = 1, GOLPE_RAPIDO, DEFENSA_GOLPE};

int main(){
    cout<< " Bienvenido a: \U0001F3F0 \U0001F9D9 'THE LOST KINGDOM' \U0001F9DD\u200D \U0001F3F9 \n"
        << "\n    1. INICIAR JUEGO\n    2. SALIR\n\n"
        <<"Ingrese una opción: ";

    int choice;
    cin>>choice;
    while(choice<1 || choice>2){
        cout<<"Por favor ingrese una opción válida...\n"
            <<"Ingrese una opción: ";
        cin>>choice;
    }
    if (choice == 2){
        cout<< "\n¡HASTA LUEGO! \u2728 \n";
        return 0;
    }

    cout<<"\nSi eres nuevo puedes acceder a la descripción del juego, ¿deseas hacerlo?\n\n"
        <<"    1. VER DESCRIPCION\n    2. INICIAR PARTIDA\n\n"
        <<"Ingrese una opción: ";
    cin>>choice;
    while(choice<1 || choice>2){
        cout<<"Por favor ingrese una opción válida...\n"
            <<"Ingrese una opción: ";
        cin>>choice;
    }
    if(choice == 1){
        cout<<"\n==================== TUTORIAL DE BATALLA ====================\n\n"
        "¡Bienvenido al campo de batalla, valiente combatiente!\n"
        "Aquí aprenderás todo lo que necesitás saber para comenzar a jugar\n"
        "y sobrevivir en este duelo mágico y brutal.\n"
        "Dos personajes entran... uno solo saldrá victorioso.\n\n"
        "1) ELIGE TU PERSONAJE Y TU ARMA ⚔️\n"
        "Antes de comenzar la pelea, debés elegir un personaje y un arma que lo acompañará.\n"
        "El personaje rival y su arma serán elegidos automáticamente por el sistema.\n\n"
        "2) SISTEMA DE COMBATE: TIPO PIEDRA, PAPEL O TIJERA\n"
        "Cada ronda de batalla se resuelve con uno de tres movimientos posibles:\n"
        "  - 💥  Golpe Fuerte\n"
        "  - ⚡  Golpe Rápido\n"
        "  - 🛡️  Defensa y Golpe\n\n"
        "Escribí tu elección por teclado.\n"
        "El personaje enemigo elegirá su acción al azar.\n\n"
        "3) REGLAS DEL ENFRENTAMIENTO:\n"
        "  > Golpe Fuerte vence a Golpe Rápido     → 10 pts de daño\n"
        "  > Golpe Rápido vence a Defensa y Golpe  → 10 pts de daño\n"
        "  > Defensa y Golpe bloquea Golpe Fuerte  → 10 pts al atacante\n"
        "  > Si ambos eligen lo mismo, no hay daño. Se pasa a la próxima ronda.\n\n"
        "4) CONDICIÓN DE VICTORIA\n"
        "Cada personaje comienza con 100 HP (puntos de vida).\n"
        "Pierde el primero que llegue a 0 HP.\n\n"
        "¡Y eso es todo! Elegí tu arma, preparate para la batalla... ¡y que gane el mejor! 🏆\n";
        cout<<"\n==========================================================\n\n";
        cout<<"¿COMENZAMOS?\n\n    1. SI\n    2. SALIR\n\n";
        cout<<"Ingrese una opción: ";

        cin>>choice;
        while(choice<1 || choice>2){
            cout<<"Por favor ingrese una opción válida...\n"
                <<"Ingrese una opción: ";
            cin>>choice;
        }
        if (choice == 2){
            cout<< "\n¡HASTA LUEGO! \u2728 \n";
            return 0;
        }
    }
  

    // Se crea un personaje aleatorio para jugar
    auto other = PersonajeFactory::createArmedPersonaje(randomNumber(0,8));
    int charChoice;
    int weapChoice;
    cout<<"\n\n========== ELEGE UN PERSONAJE ==========\n";
    cout<<"¿En quién te convertirás?\n\n"
        << "    1. HECHICERO\n    2. CONJURADOR\n    3. BRUJO\n    4. NIGROMANTE\n    5. BARBARO\n    6. PALADIN\n    7. CABALLERO\n    8. MERCENARIO\n    9. GLADIADOR\n\n";
    cout<<"Ingrese una opción: ";
    cin>>charChoice;
    
    while(charChoice<1 || charChoice>9){
            cout<<"Personaje no encontrado. Por favor intentelo de nuevo...\n"
                <<"Ingrese una opción: ";
            cin>>charChoice;
    }
    
    cout<<"\n========== AHORA ELIGE UN ARMA ==========\n";
    cout<<"Tu decides con que arma enfrentarás a tu oponente...\n\n"
        << "    1. BASTON\n    2. LIBRO DE HECHIZOS\n    3. POSION\n    4. AMULETO\n    5. HACHA SIMPLE\n    6. HACHA DOBLE\n    7. ESPADA\n    8. LANZA\n    9. GARROTE\n\n";
    cout<<"Ingrese una opción: ";
    cin>>weapChoice;
    
    while(weapChoice<1 || weapChoice>9){
            cout<<"Arma no encontrada. Por favor intentelo de nuevo...\n"
                <<"Ingrese una opción: ";
            cin>>weapChoice;
    }

    vector<unique_ptr<IArma>> weapons;
    weapons.push_back(PersonajeFactory::createArma(weapChoice));
    auto character = PersonajeFactory::createPersonaje(move(weapons), charChoice-1);

    cout<<"✨ El destino ha sido sellado... Conozcamos a los héroes que se batirán en duelo:\n\n"
        <<"TU PERSONAJE:\n"
        <<"-----------------------------------\n";
    character->show_info();
    cout<<"-----------------------------------\n"
        <<"\nTU OPONENTE:\n"
        <<"-----------------------------------\n";
    other->show_info();
    cout<<"-----------------------------------\n\n";

    cout<<"¿DESEAS COMENZAR LA BATALLA?\n\n    1. SI\n    2. SALIR\n\n";
    cout<<"Ingrese una opción: ";
    cin>>choice;
    while(choice<1 || choice>2){
        cout<<"Por favor ingrese una opción válida...\n"
            <<"Ingrese una opción: ";
        cin>>choice;
    }
    if (choice == 2){
        cout<< "\n¡HASTA LUEGO! \u2728 \n";
        return 0;
    }

    int i = 0;
    while(character->isAlive()>0 && other->isAlive()>0){
        i++;
        cout<< "==================================================\n";
        cout<< "⚔️  RONDA "<<i<<"\n\n";
        
        cout<< "Tu acción: (1) Golpe Fuerte, (2) Golpe Rápido, (3) Defensa y Golpe → ";
        cin>>choice;
        while(choice<1 || choice>3){
            cout<<"Por favor ingrese una opción válida...\n"
                <<"Ingrese una opción: ";
            cin>>choice;
        }

        int otherAtack = randomNumber(1,3);

        switch(choice){
            case GOLPE_FUERTE:
                if (otherAtack == GOLPE_FUERTE){ 
                    cout << "Jugada espejo. Ninguno toma ventaja esta vez.\n";
                    break;
                }
                else if(otherAtack == GOLPE_RAPIDO){
                    other->decreaseHP(character->golpeFuerte(0));
                    cout << "✅ ¡Tu ataque fue efectivo! Dañaste a tu oponente con precisión y fuerza.\n";
                    break;
                }
                else{
                    character->decreaseHP(other->defensaGolpe(0));
                    cout << "💢 ¡Has sido golpeado! El enemigo leyó tu jugada y te superó esta vez.\n";
                }
                break;
            case GOLPE_RAPIDO:
                if (otherAtack == GOLPE_RAPIDO){ 
                    cout << "Jugada espejo. Ninguno toma ventaja esta vez.\n";  
                    break;
                }
                else if(otherAtack == DEFENSA_GOLPE){
                    other->decreaseHP(character->golpeRapido(0));
                    cout << "✅ ¡Tu ataque fue efectivo! Dañaste a tu oponente con precisión y fuerza.\n";
                    break;
                }
                else{
                    character->decreaseHP(other->golpeFuerte(0));
                    cout << "💢 ¡Has sido golpeado! El enemigo leyó tu jugada y te superó esta vez.\n";
                }
                break;
            case DEFENSA_GOLPE:
                if (otherAtack == DEFENSA_GOLPE){ 
                    cout << "Jugada espejo. Ninguno toma ventaja esta vez.\n";
                    break;
                }
                else if(otherAtack == GOLPE_FUERTE){
                    other->decreaseHP(character->defensaGolpe(0));
                    cout << "✅ ¡Tu ataque fue efectivo! Dañaste a tu oponente con precisión y fuerza.\n";
                    break;
                }
                else{
                    character->decreaseHP(other->golpeRapido(0));
                    cout << "💢 ¡Has sido golpeado! El enemigo leyó tu jugada y te superó esta vez.\n";
                }
                break;
        }

        cout<<"==================================================\n"
            << "Tú:\n"
            <<"--------------------------------------------------\n";
        character->show_info();
        cout<< "-------------------------------------------------\n\n";        

        cout<<"==================================================\n";
        cout<< "Tu oponente:\n"
            <<"--------------------------------------------------\n";
        other->show_info();
        cout<< "-------------------------------------------------\n\n";        
    }
    if (character->isAlive()){
        cout<<"==================================================\n"
            <<"                🏆 ¡VICTORIA! 🏆                 \n"
            <<"==================================================\n";
        return 0;
    }
    cout<<"==================================================\n"
        <<"                  ☠ DERROTA ☠                   \n"
        <<"==================================================\n";
}