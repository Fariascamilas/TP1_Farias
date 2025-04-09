#include "Empleado.hpp"
#include <string>
#include <vector>
#include <memory>
class Departamento{
public:
    Departamento(std::string _nombre, std::string _ubicacion, std::vector<std::shared_ptr<Empleado>> _empleados, int _cantEmpleadosDepts) : nombre(_nombre), ubicacion(_ubicacion), empleados(_empleados), cantEmpleadosDepts(_cantEmpleadosDepts) {}
    ~Departamento(){}
    
    std::string nombre;
    std::string ubicacion;

    int contarEmpleados() const;
    std::vector<std::shared_ptr<Empleado>> getEmployees() const;
    bool contratarEmpleado(std::shared_ptr<Empleado> empleado);
    bool despedirEmpleado(std::shared_ptr<Empleado> empleado);

private:
    std::vector<std::shared_ptr<Empleado>> empleados;
    int cantEmpleadosDepts;
};