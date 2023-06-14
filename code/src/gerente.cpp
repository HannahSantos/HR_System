#include "gerente.h"

// Métodos get e set para o atributo participacaoLucros
float Gerente::getParticipacaoLucros() {
    return participacaoLucros;
}

void Gerente::setParticipacaoLucros(float participacaoLucros) {
    this->participacaoLucros = participacaoLucros;
}

// Implementação do método calcularSalario da classe abstrata Funcionario
float Gerente::calcularSalario(int diasFaltas) override {
    // Cálculo do salário do Gerente com base nas regras fornecidas
    float salarioBase = std::stof(getSalario());
    float salarioDescontado = salarioBase - (salarioBase / 30) * diasFaltas;
    float salarioComLucros = salarioDescontado + getParticipacaoLucros();
    float salarioFinal = salarioComLucros + (getQtdFilhos() * 100);

    return salarioFinal;
}

// Implementação do método calcularRecisao da classe abstrata Funcionario
float Gerente::calcularRescisao(Data desligamento) override {
    // Cálculo da rescisão do Gerente com base nas regras fornecidas
    float anosTrabalhados = desligamento.ano - getIngressoEmpresa().ano;
    float mesesTrabalhados = desligamento.mes - getIngressoEmpresa().mes;
    float diasTrabalhados = desligamento.dia - getIngressoEmpresa().dia;

    float tempoTrabalhado = anosTrabalhados + (mesesTrabalhados / 12) + (diasTrabalhados / 365);

    float salarioBaseAnual = std::stof(getSalario()) * 12;
    float rescisao = tempoTrabalhado * salarioBaseAnual;

    return rescisao;
}


void Gerente::imprimirDados() const {
    std::cout << "Dados do Gerente" << std::endl;
    std::cout << "Nome: " << getNome() << std::endl;
    std::cout << "CPF: " << getCpf() << std::endl;
    std::cout << "Data de Nascimento: " << getDataNascimento().dia << "/" << getDataNascimento().mes << "/" << getDataNascimento().ano << std::endl;
    std::cout << "Endereço: " << getEnderecoPessoal().rua << ", " << getEnderecoPessoal().numero << ", " << getEnderecoPessoal().bairro << ", " << getEnderecoPessoal().cidade << ", " << getEnderecoPessoal().cep << std::endl;
    std::cout << "Estado Civil: " << getEstadoCivil() << std::endl;
    std::cout << "Quantidade de Filhos: " << getQtdFilhos() << std::endl;
    std::cout << "Matrícula: " << getMatricula() << std::endl;
    std::cout << "Salário: " << getSalario() << std::endl;
    std::cout << "Data de Ingresso na Empresa: " << getIngressoEmpresa().dia << "/" << getIngressoEmpresa().mes << "/" << getIngressoEmpresa().ano << std::endl;
    std::cout << "Participação nos Lucros: " << getParticipacaoLucros() << std::endl;
    std::cout << std::endl;
}
