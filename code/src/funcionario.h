#ifndef _FUNCIONARIO_H_
#define _FUNCIONARIO_H_

#include "util.h" // Incluir o arquivo "util.h" para ter acesso à definição da estrutura "Data"

// Definição da classe abstrata Funcionario
class Funcionario {
private:
    std::string salario;
    std::string matricula;
    Data ingressoEmpresa;

public:
    // Métodos get e set para todos os atributos
    std::string getSalario();
    void setSalario(std::string salario);

    std::string getMatricula();
    void setMatricula(std::string matricula);

    Data getIngressoEmpresa();
    void setIngressoEmpresa(Data ingressoEmpresa);

    // Método virtual para calcular o salário
    virtual float calcularSalario(int diasFaltas) = 0;

    // Método virtual para calcular a rescisão
    virtual float calcularRescisao(Data desligamento) = 0;
};

#endif
