#pragma once

enum Magos {HECHICERO, CONJURADOR, BRUJO, NIGROMANTE}; // 4
enum Guerreros {BARBARO, PALADIN, CABALLERO, MERCENARIO, GLADIADOR}; // 5
enum ItemsMagicos {BASTON, LIBRO_DE_HECHIZOS, POSION, AMULETO}; // 4
enum ArmasDeCombate {HACHA_SIMPLE, HACHA_DOBLE, ESPADA, LANZA, GARROTE}; // 5

int randomNumber(int min, int max);
int cantPersonajes();
int cantArmas();