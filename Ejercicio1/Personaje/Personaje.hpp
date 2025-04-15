#pragma once
#include "../Arma/Arma.hpp"
#include <vector>
#include <memory>

enum magicLevels {APPRENTICE, SORCERER, MASTER};
enum experienceLevels{RECRUIT, CAPITAIN, LEYEND};

/**
 * @interface IPersonaje
 * @brief Interfaz base para cualquier tipo de personaje
 *
 * Proporciona los métodos fundamentales que cualquier personaje debe implementar.
 */
class IPersonaje{
public:
    virtual bool isMagical() = 0;
        /**
     * @brief Destructor virtual por defecto.
     */
    virtual ~IPersonaje() = default;
    /**
     * @brief Constructor protegido para evitar instanciar la interfaz directamente.
     */
    IPersonaje(){}
    
    /**
     * @brief Muestra la información relevante del personaje.
     */
    virtual void show_info() const = 0;

    virtual void decreaseHP(int damage) = 0;

    virtual bool isAlive() const = 0;

    virtual const std::vector<std::unique_ptr<IArma>>& getWeapons() const = 0;

    virtual int golpeFuerte(int posWeapon) = 0;
    
    virtual int golpeRapido(int posWeapon) = 0;
    
    virtual int defensaGolpe(int posWeapon) = 0;
};