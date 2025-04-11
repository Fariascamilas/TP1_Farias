#pragma once
#include <string>
#include "Arma.hpp"

/**
 * @class ArmaDeCombate
 * Clase abstracta para armas de combate que implementa la interfaz IArma.
 */
class ArmaDeCombate : public IArma{
protected:
    std::string name;       /**< Nombre del arma */
    int timesUsed;          /**< Veces usada (el daño se reduce con el aumento de timesUsed)*/
    std::string oddity;     /**< Rareza */
    int powerLevel;         /**< Nivel de poder */
    int material;           /**< Tipo de material */
public:
    /**
     * @brief Constructor de ArmaDeCombate
     * @param _name Nombre del arma
     * @param _timesUsed Veces que se usó inicialmente
     * @param _oddity Rareza
     * @param _powerLevel Nivel de poder
     * @param _material Material que la compone
     */
    ArmaDeCombate(std::string _name, int _timesUsed, std::string _oddity, int _powerLevel, int _material);
    
    /**
     * @brief Destructor virtual por defecto
     */
    virtual ~ArmaDeCombate() = default;

    /**
     * @brief Incrementa en 1 las veces usadas
     */
    virtual void use() override;
    
    /**
     * @brief Muestra información detallada del arma
     */
    virtual void show_info() const = 0;
    
    /**
     * @brief Indica si el arma es mágica
     * @return siempre false
     */
    virtual bool isMagical() const override;

    /**
     * @brief Calcula el daño en base al nivel de poder,
     *        material y veces usadas. Reinicia timesUsed si el daño resulta <= 0.
     * @return Cantidad de daño producido
     */
    virtual int getDamage();
    
    /**
     * @brief Devuelve el nombre
     * @return name
     */
    virtual std::string getName() const;
    
    /**
     * @brief Devuelve la rareza
     * @return oddity
     */
    virtual std::string getOddity() const;
    
    /**
     * @brief Devuelve cuántas veces se ha usado
     * @return timesUsed
     */
    virtual int getTimesUsed() const;
    
    /**
     * @brief Devuelve el nivel de poder
     * @return powerLevel
     */
    virtual int getPoewrLevel() const;
    
    /**
     * @brief Devuelve el material del arma
     * @return material
     */
    virtual int getMaterial() const;
};

/**
 * @class HachaSimple
 * Arma de combate tipo hacha simple.
 */
class HachaSimple : public ArmaDeCombate{
public:
    /**
     * @brief Construye un hacha simple
     * @param _name Nombre del arma
     * @param _oddity Rareza
     */
    HachaSimple(std::string _name, std::string _oddity);
    
    /**
     * @brief Muestra información específica del HachaSimple
     */
    void show_info() const override;
    
    /**
     * @brief Ataque Especial del Hacha Simple. Aplicarlo cuesta dos usos convencionales
     */
    void wildBreakAtack();
};


/**
 * @class HachaDoble
 * Arma de combate tipo hacha doble.
 */
class HachaDoble : public ArmaDeCombate{
public:
    /**
     * @brief Construye un hacha doble
     * @param _name Nombre del arma
     * @param _oddity Rareza
     */
    HachaDoble(std::string _name, std::string _oddity);

    /**
     * @brief Muestra información específica del HachaDoble
     */
    void show_info() const override;

    /**
     * @brief Ataque Especial del Hacha Doble. Aplicarlo cuesta dos usos convencionales
     */
    void titanCleaveAtack();
};

class Espada : public ArmaDeCombate{
public:
    /**
     * @brief Construye una espada
     * @param _name Nombre del arma
     * @param _oddity Rareza
     */
    Espada(std::string _name, std::string _oddity);

    /**
     * @brief Muestra información específica de la Espada
     */
    void show_info() const override;

    /**
     * @brief Ataque Especial de la Espada. Aplicarlo cuesta tres usos convencionales
     */
    void lightningSlashAtack();
};

class Lanza : public ArmaDeCombate{
public:
    /**
     * @brief Construye una Lanza
     * @param _name Nombre del arma
     * @param _oddity Rareza
     */
    Lanza(std::string _name, std::string _oddity);

    /**
     * @brief Muestra información específica de la Lanza
     */
    void show_info() const override;

    /**
     * @brief Ataque Especial de la Lanza. Aplicarlo cuesta tres usos convencionales
     */
    void skyLanceAtack();
};

class Garrote : public ArmaDeCombate{
public:
    /**
     * @brief Construye un Garrote
     * @param _name Nombre del arma
     * @param _oddity Rareza
     */
    Garrote(std::string _name, std::string _oddity);

    /**
     * @brief Muestra información específica del Garrote
     */
    void show_info() const override;

    /**
     * @brief Ataque Especial del Garrote. Aplicarlo cuesta dos usos convencionales
     */
    void earthshatterAtack();
};