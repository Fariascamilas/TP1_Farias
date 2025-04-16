#pragma once
#include <memory>
#include <vector>
#include <string>
#include "../Ejercicio1/Arma/ArmaDeCombate.hpp"
#include "../Ejercicio1/Arma/ItemMagico.hpp"
#include "../Ejercicio1/Personaje/Guerrero.hpp"
#include "../Ejercicio1/Personaje/Mago.hpp"

/**
 * @class PersonajeFactory
 * @brief Fábrica para crear personajes y armas.
 */
class PersonajeFactory{
public:
    /**
     * @brief Crea un personaje con las armas proporcionadas según el tipo indicado.
     * @param weapons Vector de punteros únicos a armas.
     * @param type Tipo de personaje (según el enum Personajes).
     * @return Puntero único a un objeto IPersonaje.
     */
    static std::unique_ptr<IPersonaje> createPersonaje(std::vector<std::unique_ptr<IArma>> weapons, int type);

    /**
     * @brief Crea un arma basada en el tipo indicado.
     * @param type Tipo de arma (según el enum Armas).
     * @return Puntero único a un objeto IArma.
     */
    static std::unique_ptr<IArma> createArma(int type);

    /**
     * @brief Crea un personaje con armas aleatorias según el tipo de personaje.
     * @param typeCharacter Tipo de personaje (según el enum Personajes).
     * @return Puntero único a un objeto IPersonaje armado con dos armas.
     */
    static std::unique_ptr<IPersonaje> createArmedPersonaje(int typeCharacter);
};