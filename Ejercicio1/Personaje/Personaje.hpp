#pragma once
#include <array>
#include <string>
#include "../Arma/Arma.hpp"

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
protected:
    /**
     * @brief Constructor protegido para evitar instanciar la interfaz directamente.
     */
    IPersonaje(){}
    
    /**
     * @brief Muestra la información relevante del personaje.
     */
    virtual void show_info() const = 0;

    virtual void golpeFuerte(IPersonaje &other) = 0;
    
    virtual void golpeRapido(IPersonaje &other) = 0;
    
    virtual void defensaGolpe(IPersonaje &other) = 0;
};