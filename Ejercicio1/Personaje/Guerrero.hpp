#pragma once
#include "Personaje.hpp"

/**
 * @brief Clase abstracta para personajes de tipo Guerrero.
 */
class Guerrero : public IPersonaje{
protected:
    std::string name;               /**< Nombre del guerrero */
    std::array<IArma*,2> weapons;   /**< Armas disponibles */
    int experienceLevel;            /**< Nivel de experiencia */
    std::string specialHability;    /**< Habilidad especial */
    
public:
    int HP;                         /**< Puntos de vida */
 
    /**
     * @brief Destructor que libera los punteros en el arreglo de armas.
     */
    virtual ~Guerrero();

    /**
     * @brief Constructor principal para Guerrero.
     * @param _name Nombre del guerrero.
     * @param _weapons Arreglo de armas.
     * @param _experienceLevel Nivel de experiencia.
     * @param _specialHability Habilidad especial.
     * @param _HP Puntos de vida.
     */
    Guerrero(std::string _name, const std::array<IArma*,2>& _weapons, int _experienceLevel, std::string _specialHability, int _HP);

    /**
     * @brief Muestra información específica del guerrero.
     */
    virtual void show_info() const = 0;

    /**
     * @brief Realiza un golpe fuerte contra otro personaje.
     * @param other Referencia al oponente.
     */
    void golpeFuerte(IPersonaje &other) override;
       
    /**
     * @brief Realiza un golpe rápido contra otro personaje.
     * @param other Referencia al oponente.
     */ 
    void golpeRapido(IPersonaje &other) override;
        
    /**
     * @brief Se defiende y da un golpe.
     * @param other Referencia al oponente.
     */
    void defensaGolpe(IPersonaje &other) override;

    /**
     * @brief Obtiene el nombre del guerrero.
     * @return Nombre del guerrero.
     */
    std::string getName() const;

    /**
     * @brief Verifica si se trata de un personaje mágico.
     * @return Siempre falso para Guerrero.
     */
    bool isMagical() override;
        
    /**
     * @brief Devuelve las armas del guerrero.
     * @return Arreglo de punteros a IArma.
     */
    const std::array<IArma*,2>& getWeapons() const; // VER SI TRAE PROBLEMAS, SI HACE UNA COPIA PODRIA TENER MUCHOS PUNTEROS
        
    /**
     * @brief Devuelve el nivel de experiencia.
     * @return Nivel de experiencia.
     */
    int getExperienceLevel() const;
    
    /**
     * @brief Devuelve la habilidad especial.
     * @return Habilidad especial.
     */
    std::string getSpecialHability() const;
    
    /**
     * @brief Devuelve los puntos de vida.
     * @return Puntos de vida.
     */
    int getHP() const;
};

/**
 * @brief Representa a un Guerrero de tipo Bárbaro.
 */
class Barbaro : public Guerrero{
public:
    /**
     * @brief Constructor para Bárbaro.
     * @param _name Nombre del Bárbaro.
     * @param _specialHability Habilidad especial.
     * @param _weapons Arreglo de armas.
     */
    Barbaro(std::string _name, std::string _specialHability, const std::array<IArma*,2>& _weapons);
    
    /**
     * @brief Muestra la información del Bárbaro.
     */
    void show_info() const override;
    
    /**
     * @brief Frase de Victoria.
     * @return Cadena con la frase.
     */
    std::string unstoppableFurySaying();
};

class Paladin : public Guerrero{
public:
    /**
     * @brief Constructor para Paladín.
     * @param _name Nombre del Paladín.
     * @param _specialHability Habilidad especial.
     * @param _weapons Arreglo de armas.
     */
    Paladin(std::string _name, std::string _specialHability, const std::array<IArma*,2>& _weapons);
    
    /**
     * @brief Muestra la información del Paladín.
     */
    void show_info() const override;
    
    /**
     * @brief Frase de Victoria.
     * @return Cadena con la frase.
     */
    std::string lightPrevailsSaying();
};

class Caballero : public Guerrero{
public:
    /**
     * @brief Constructor para Caballero.
     * @param _name Nombre del Caballero.
     * @param _specialHability Habilidad especial.
     * @param _weapons Arreglo de armas.
     */
    Caballero(std::string _name, std::string _specialHability, const std::array<IArma*,2>& _weapons);
    
    /**
     * @brief Muestra la información del Caballero.
     */
    void show_info() const override;
    
    /**
     * @brief Frase de Victoria.
     * @return Cadena con la frase.
     */
    std::string aNobleEndSaying();
};

/**
 * @brief Representa a un Guerrero de tipo Mercenario.
 */
class Mercenario : public Guerrero{
public:
    /**
     * @brief Constructor para Mercenario.
     * @param _name Nombre del Mercenario.
     * @param _specialHability Habilidad especial.
     * @param _weapons Arreglo de armas.
     */
    Mercenario(std::string _name, std::string _specialHability, const std::array<IArma*,2>& _weapons);
    
    /**
     * @brief Muestra la información del Mercenario.
     */
    void show_info() const override;
    
    /**
     * @brief Frase de Victoria.
     * @return Cadena con la frase.
     */
    std::string dealClosedSaying();
};

/**
 * @brief Representa a un Guerrero de tipo Gladiador.
 */
class Gladiador : public Guerrero{
public:
    /**
     * @brief Constructor para Gladiador.
     * @param _name Nombre del Gladiador.
     * @param _specialHability Habilidad especial.
     * @param _weapons Arreglo de armas.
     */
    Gladiador(std::string _name, std::string _specialHability, const std::array<IArma*,2>& _weapons);
    
    /**
     * @brief Muestra la información del Gladiador.
     */
    void show_info() const override;
    
    /**
     * @brief Frase de Victoria.
     * @return Cadena con la frase.
     */
    std::string survivalIsGlorySaying();
};