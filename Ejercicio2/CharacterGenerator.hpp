#pragma once

//enum Magos {HECHICERO, CONJURADOR, BRUJO, NIGROMANTE}; // 4
//enum Guerreros {BARBARO, PALADIN, CABALLERO, MERCENARIO, GLADIADOR}; // 5
//enum ItemsMagicos {BASTON, LIBRO_DE_HECHIZOS, POSION, AMULETO}; // 4
//enum ArmasDeCombate {HACHA_SIMPLE, HACHA_DOBLE, ESPADA, LANZA, GARROTE}; // 5

/**
 * @enum Personajes
 * @brief Enumerador de tipos de personajes disponibles.
 */
enum Personajes {HECHICERO, CONJURADOR, BRUJO, NIGROMANTE, BARBARO, PALADIN, CABALLERO, MERCENARIO, GLADIADOR};

/**
 * @enum Armas
 * @brief Enumerador de tipos de armas disponibles.
 */
enum Armas {BASTON, LIBRO_DE_HECHIZOS, POSION, AMULETO, HACHA_SIMPLE, HACHA_DOBLE, ESPADA, LANZA, GARROTE};

/**
 * @brief Genera un número aleatorio en el rango [min, max].
 * @param min Límite inferior del rango.
 * @param max Límite superior del rango.
 * @return Número aleatorio entre min y max, inclusive.
 */
int randomNumber(int min, int max);

/**
 * @brief Genera una cantidad aleatoria de personajes.
 * @return Número aleatorio dentro del rango definido para la cantidad de personajes.
 */
int cantPersonajes();

/**
 * @brief Genera una cantidad aleatoria de armas.
 * @return Número aleatorio dentro del rango definido para la cantidad de armas.
 */
int cantArmas();