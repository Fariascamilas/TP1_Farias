#pragma once
#include <string>

class Empleado{
    friend Manager;
public:
    Empleado(std::string _nombre, std::string _puesto, int _antiguedad, float _salario) : nombre(_nombre), puesto(_puesto), antiguedad(_antiguedad), salario(_salario) {}
    virtual ~Empleado() = default; 
    
    std::string nombre;
    std::string puesto;

    /**
     * @brief Devuelve la antigüedad del empleado.
     * @return Antigüedad en años.
     */
    int getAntiguedad() const;

    /**
     * @brief Actualiza el salario del empleado.
     * @param newSalario Nuevo salario.
     * @return true si se pudo actualizar, false en caso de error (salario negativo).
     */
    bool updateSalario(float newSalario);

    /**
     * @brief Devuelve el salario actual.
     * @return Salario en formato float.
     */    
    float getSalario() const;

private:
    int antiguedad;
    float salario;
};

class Manager : public Empleado{
    friend LiderEquipo;
    friend GerenteBajo;
    friend GerenteMedio;
    friend GerenteAlto;

public:
    Manager(std::string _nombre, std::string _puesto, int _antiguedad, float _salario, float _bono, std::string _level) : Empleado(_nombre, _puesto, _antiguedad, _salario), bono(_bono), level(_level) {}
    
    float bono;
    /** 
     * @brief Actualiza el bono del Manager.
     * @param newBono Nuevo bono.
     * @return true si se pudo actualizar, false en caso de error (bono negativo).
    */
    bool updateBono(float newBono);

    /**
     * @brief Devuelve el bono actual.
     * @return Bono en formato float.
     */
    float getBono();

    /** 
     * @brief Actualiza el level del Manager.
     * @param newLevel Nuevo level.
     * @return true si se pudo actualizar, false en caso de error.
    */
    bool setLevel(std::string newLevel); // CUANDO ES FALSE??

private:
    std::string level;
};

class LiderEquipo : public Manager{};

class GerenteBajo : public Manager{};

class GerenteMedio : public Manager{};

class GerenteAlto : public Manager{};