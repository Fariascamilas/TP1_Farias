#pragma once
#include <string>
/**
 * @brief Define posibles procedencias de Items mágicos
 */
enum magicalProvenance {FOREST = 1, MAGIC_LIBRARY, MYSTIC_FALLS, ETERNAL_CAVES};

/**
 * @brief Define posibles materiales de Armas de combate
 */
enum combatMaterials {WOOD = 1, SKYWOOD, STEEL, IRON};

/**
 * @brief Define posibles niveles de poder para todo tipo de armas
 */
enum powerLevels {COMMON = 1, RARE, EPIC};

/**
 * @interface IArma
 * @brief Interfaz base para cualquier tipo de arma
 *
 * Proporciona los métodos fundamentales que cualquier arma debe implementar.
 */
class IArma{
protected:
    /**
     * @brief Usa el arma y cambia su estado interno.
     */
    virtual void use() = 0;
    
    /**
     * @brief Muestra la información relevante del arma.
     */
    virtual void show_info() const = 0;
    
    /**
     * @brief Constructor protegido para evitar instanciar la interfaz directamente.
     */
    IArma(){}
    
public: 
    /**
     * @brief Indica si el arma es mágica.
     * @return true si el arma es mágica, false en caso contrario.
     */
    virtual bool isMagical() const = 0;


    /**
     * @brief Destructor virtual por defecto.
     */
    virtual ~IArma() = default;
};