#pragma once
#include <string>
#include "Arma.hpp"

/**
 * @class ItemMagico
 * Clase abstracta para Items Mágicos que implementa la interfaz IArma.
 */
class ItemMagico : public IArma{
protected:
    std::string name;       /**< Nombre del arma */
    int timesUsed;          /**< Veces usada (el daño se reduce con el aumento de timesUsed)*/
    std::string oddity;     /**< Rareza */
    int powerLevel;         /**< Nivel de poder */
    int provenance;         /**< Lugar mágico del que proviene */

    /**
     * @brief Constructor de ItemMagico
     * @param _name Nombre del arma
     * @param _timesUsed Veces que se usó inicialmente
     * @param _oddity Rareza
     * @param _powerLevel Nivel de poder
     * @param _provenance Lugar mágico del que proviene
     */
    ItemMagico(std::string _name, int _timesUsed, std::string _oddity, int _powerLevel, int _provenance);

    /**
     * @brief Destructor virtual por defecto
     */
    virtual ~ItemMagico() = default;

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
     * @return siempre true
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
    std::string getName() const;
        
    /**
     * @brief Devuelve la rareza
     * @return oddity
     */
    std::string getOddity() const;
        
    /**
     * @brief Devuelve cuántas veces se ha usado
     * @return timesUsed
     */
    int getTimesUsed() const;
        
    /**
     * @brief Devuelve el nivel de poder
     * @return powerLevel
     */
    int getPoewrLevel() const;
        
    /**
     * @brief Devuelve el lugar de procedencia del arma
     * @return provenance
     */
    int getProvenance() const;
};

/**
 * @class Baston
 * Item Mágico tipo Bastón.
 */
class Baston : public ItemMagico{
public:
    /**
     * @brief Construye un Bastón
     * @param _name Nombre del arma
     * @param _oddity Rareza
     */
    Baston(std::string _name, std::string _oddity);
    
    /**
     * @brief Muestra información específica del Bastón
     */
    void show_info() const override;
    
    /**
     * @brief Ataque Especial del Bastón. Aplicarlo cuesta dos usos convencionales
     */
    void arcaneBurstAtack();
};

/**
 * @class LibroDeHechizos
 * Item Mágico tipo Libro de Hechizos.
 */
class LibroDeHechizos : public ItemMagico{
public:
    /**
     * @brief Construye un Libro de hechizos
     * @param _name Nombre del arma
     * @param _oddity Rareza
     */
    LibroDeHechizos(std::string _name, std::string _oddity);

    /**
     * @brief Muestra información específica del Libro de Hechizos
     */
    void show_info() const override;
    
    /**
     * @brief Ataque Especial del Libro de Hechizos. Aplicarlo cuesta tres usos convencionales
     */
    void forbiddenWordAtack();
};

/**
 * @class Posion
 * Item Mágico tipo Posión.
 */
class Posion : public ItemMagico{
public:
    /**
     * @brief Construye una Posión
     * @param _name Nombre del arma
     * @param _oddity Rareza
     */
    Posion(std::string _name, std::string _oddity);

    /**
     * @brief Muestra información específica de la Posión
    */
    void show_info() const override;
    
    /**
     * @brief Ataque Especial de la Posión. Aplicarlo cuesta dos usos convencionales
     */
    void alchemicalExplosionAtack();
    
    /**
     * @brief Ataque Especial de la Posión. Aplicarlo cuesta tres usos convencionales
     */
    void mirrorBrewAtack();
};

/**
 * @class Amuleto
 * Item Mágico tipo Amuleto.
 */
class Amuleto : public ItemMagico{
public:
    /**
     * @brief Construye un Amuleto
     * @param _name Nombre del arma
     * @param _oddity Rareza
     */
    Amuleto(std::string _name, std::string _oddity);

    /**
     * @brief Muestra información específica del Amuleto
     */
    void show_info() const override;
    
    /**
     * @brief Ataque Especial del Amuleto. Aplicarlo cuesta dos usos convencionales
     */
    void soulLinkAtack();
};