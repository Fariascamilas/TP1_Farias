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
protected:
    /**
     * @brief Constructor protegido para evitar instanciar la interfaz directamente.
     */
    IPersonaje(){}
    
public:
        /**
     * @brief Destructor virtual por defecto.
     */

    virtual ~IPersonaje() = default;
    
    /**
     * @brief Muestra la información relevante del personaje.
     */
    virtual void show_info() const = 0;

    /**
     * @brief Decrementa el HP segun el daño causado por su oponente.
     * @param damage Puntos a restar de HP (daño causado).
     */
    virtual void decreaseHP(int damage) = 0;

    /**
     * @brief Verifica si un personaje esta vivo (HP>0).
     * @return Devuelve true si lo está, false caso contrario.
     */
    virtual bool isAlive() const = 0;

    virtual const std::vector<std::unique_ptr<IArma>>& getWeapons() const = 0;

    /**
     * @brief Realiza un golpe fuerte contra otro personaje.
     * @param posWeapon Posicion del arma a utilizar en el vector de armas.
     * @return Devuelve el daño total que realiza el arma con un golpe fuerte.
     */
    virtual int golpeFuerte(int posWeapon) = 0;
         
    /**
     * @brief Realiza un golpe rápido contra otro personaje.
     * @param posWeapon Posicion del arma a utilizar en el vector de armas.
     * @return Devuelve el daño total que realiza el arma con un golpe rápido.
     */ 
    virtual int golpeRapido(int posWeapon) = 0;
              
    /**
     * @brief Se defiende y da un golpe.
     * @param posWeapon Posicion del arma a utilizar en el vector de armas.
     * @return Devuelve el daño total que realiza el arma con defensa y golpe.
     */
    virtual int defensaGolpe(int posWeapon) = 0;

    /**
     * @brief Verifica si se trata de un personaje mágico.
     * @return Siempre verdadero para Mago.
     */
    virtual bool isMagical() = 0;
};