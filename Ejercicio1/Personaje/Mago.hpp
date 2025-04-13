#pragma once
#include "Personaje.hpp"

/**
 * @brief Clase abstracta para personajes de tipo Mago.
 */
class Mago : public IPersonaje{
protected:
    std::string name;               /**< Nombre del Mago */
    std::array<IArma*,2> weapons;   /**< Armas disponibles */
    int magicLevel;                 /**< Nivel de magia */
    std::string specialHability;    /**< Habilidad especial */
    
public:
    int HP;                         /**< Puntos de vida */
    
    /**
     * @brief Destructor que libera los punteros en el arreglo de armas.
     */
    virtual ~Mago();

    /**
     * @param _name Nombre del mago.
     * @param _weapons Arreglo de armas.
     * @param _magicLevel Nivel de magia.
     * @param _specialHability Habilidad especial.
     * @param _HP Puntos de vida.
     */
    Mago(std::string _name, const std::array<IArma*,2>& _weapons, int _magicLevel, std::string _specialHability, int _HP);

    /**
     * @brief Muestra información detallada del mago.
     * 
     * Este método debe mostrar atributos como el nombre, nivel de magia,
     * habilidad especial, puntos de vida y cualquier otra información relevante
     * sobre el personaje.
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
     * @brief Obtiene el nombre del mago.
     * @return Nombre del guerrero.
     */
    std::string getName() const;

    /**
     * @brief Verifica si se trata de un personaje mágico.
     * @return Siempre verdadero para Mago.
     */
    bool isMagical() override;
       
    /**
     * @brief Devuelve las armas del guerrero.
     * @return Referencia constante al arreglo de punteros a IArma.
     */
    const std::array<IArma*,2>& getWeapons() const;
        
    /**
     * @brief Devuelve el nivel de magia.
     * @return Nivel de magia.
     */
    int getMagicLevel() const;
    
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
 * @brief Representa a un Guerrero de tipo Hechicero.
 */
class Hechicero : public Mago{
public: 
    /**
     * @brief Constructor para Hechicero.
     * @param _name Nombre del Hechicero.
     * @param _specialHability Habilidad especial.
     * @param _weapons Arreglo de armas.
     */
    Hechicero(std::string _name, std::string specialHability, const std::array<IArma*,2>& weapons);
     
    /**
     * @brief Muestra la información del Hchicero.
     */
    void show_info() const override;
    
    /**
     * @brief Frase de Victoria.
     * @return Cadena con la frase.
     */
    std::string arcaneSupremacySaying();
};

class Conjurador : public Mago{
public:
    /**
     * @brief Constructor para Conjurador.
     * @param _name Nombre del Conjurador.
     * @param _specialHability Habilidad especial.
     * @param _weapons Arreglo de armas.
     */
    Conjurador(std::string _name, std::string specialHability, const std::array<IArma*,2>& weapons);
     
    /**
     * @brief Muestra la información del Conjurador.
     */
    void show_info() const override;
    
    /**
     * @brief Frase de Victoria.
     * @return Cadena con la frase.
     */
    std::string superiorMagicSaying();
};

class Brujo : public Mago{
public:
    /**
     * @brief Constructor para Brujo.
     * @param _name Nombre del Brujo.
     * @param _specialHability Habilidad especial.
     * @param _weapons Arreglo de armas.
     */
    Brujo(std::string _name, std::string specialHability, const std::array<IArma*,2>& weapons);
     
    /**
     * @brief Muestra la información del Brujo.
     */
    void show_info() const override;
    
    /**
     * @brief Frase de Victoria.
     * @return Cadena con la frase.
     */
    std::string tooLateSaying();
};

class Nigromante : public Mago{
public:
    /**
     * @brief Constructor para Nigromante.
     * @param _name Nombre del Nigromante.
     * @param _specialHability Habilidad especial.
     * @param _weapons Arreglo de armas.
     */
    Nigromante(std::string _name, std::string specialHability, const std::array<IArma*,2>& weapons);
     
    /**
     * @brief Muestra la información del Nigromante.
     */
    void show_info() const override;
    
    /**
     * @brief Frase de Victoria.
     * @return Cadena con la frase.
     */ 
    std::string silentPrizeSaying();
};