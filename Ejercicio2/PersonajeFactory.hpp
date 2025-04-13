#pragma once
#include <memory>
#include "../Ejercicio1/Arma/ArmaDeCombate.hpp"
#include "../Ejercicio1/Arma/ItemMagico.hpp"
#include "../Ejercicio1/Personaje/Guerrero.hpp"
#include "../Ejercicio1/Personaje/Mago.hpp"

class PersonajeFactory{
public:
    static std::unique_ptr<Guerrero> createGuerrero(const std::array<IArma*,2>& weapons, int type);
    static std::unique_ptr<Mago> createMago(const std::array<IArma*,2>& weapons, int type);
    static std::unique_ptr<ArmaDeCombate> createArmadeCombate(int type);
    static std::unique_ptr<ItemMagico> createItemMagico(int type);

    static std::unique_ptr<Guerrero> createArmedGuerrero(int typeCharacter);
    static std::unique_ptr<Mago> createArmedMago(int typeCharacter);
};