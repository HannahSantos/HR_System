#include "funcionario.h"

// Métodos get e set para todos os atributos
std::string Funcionario::getSalario() {
    return salario;
}

void Funcionario::setSalario(std::string salario) {
    this->salario = salario;
}

std::string Funcionario::getMatricula() {
    return matricula;
}

void Funcionario::setMatricula(std::string matricula) {
    this->matricula = matricula;
}

Data Funcionario::getIngressoEmpresa() {
    return ingressoEmpresa;
}

void Funcionario::setIngressoEmpresa(Data ingressoEmpresa) {
    this->ingressoEmpresa = ingressoEmpresa;
}
