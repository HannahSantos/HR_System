#include "asg.h"

// Métodos get e set para o atributo adicionalInsalubridade
float Asg::getAdicionalInsalubridade() {
    return adicionalInsalubridade;
}

void Asg::setAdicionalInsalubridade(float adicionalInsalubridade) {
    this->adicionalInsalubridade = adicionalInsalubridade;
}

// Implementação do método calcularSalario da classe abstrata Funcionario
float Asg::calcularSalario(int diasFaltas) override {
    // Cálculo do salário do ASG com base nas regras fornecidas
    float salarioBase = std::stof(getSalario());
    float salarioDescontado = salarioBase - (salarioBase / 30) * diasFaltas;
    float salarioComInsalubridade = salarioDescontado + (salarioDescontado * (adicionalInsalubridade / 100));
    float salarioFinal = salarioComInsalubridade + (getQtdFilhos() * 100);

    return salarioFinal;
}

// Implementação do método calcularRecisao da classe abstrata Funcionario
float Asg::calcularRescisao(Data desligamento) override {
    // Cálculo da rescisão do ASG com base nas regras fornecidas
    int anosTrabalhados = desligamento.ano - getIngressoEmpresa().ano;
    float mesesTrabalhados = desligamento.mes - getIngressoEmpresa().mes;
    float diasTrabalhados = desligamento.dia - getIngressoEmpresa().dia;

    float tempoTrabalhado = anosTrabalhados + (mesesTrabalhados / 12) + (diasTrabalhados / 365);

    float salarioBaseAnual = std::stof(getSalario()) * 12;
    float rescisao = tempoTrabalhado * salarioBaseAnual;

    return rescisao;
}


void Asg::imprimirDados() const {
    std::cout << "Dados do ASG" << std::endl;
    std::cout << "Nome: " << getNome() << std::endl;
    std::cout << "CPF: " << getCpf() << std::endl;
    std::cout << "Data de Nascimento: " << getDataNascimento().dia << "/" << getDataNascimento().mes << "/" << getDataNascimento().ano << std::endl;
    std::cout << "Endereço: " << getEnderecoPessoal().rua << ", " << getEnderecoPessoal().numero << ", " << getEnderecoPessoal().bairro << ", " << getEnderecoPessoal().cidade << ", " << getEnderecoPessoal().cep << std::endl;
    std::cout << "Estado Civil: " << getEstadoCivil() << std::endl;
    std::cout << "Quantidade de Filhos: " << getQtdFilhos() << std::endl;
    std::cout << "Matrícula: " << getMatricula() << std::endl;
    std::cout << "Salário: " << getSalario() << std::endl;
    std::cout << "Data de Ingresso na Empresa: " << getIngressoEmpresa().dia << "/" << getIngressoEmpresa().mes << "/" << getIngressoEmpresa().ano << std::endl;
    std::cout << "Adicional de Insalubridade: " << getAdicionalInsalubridade() << std::endl;
    std::cout << std::endl;
}
