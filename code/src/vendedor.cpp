#include "vendedor.h" 
 
// Métodos get e set para o atributo tipoVendedor
char Vendedor::getTipoVendedor() {
    return tipoVendedor;
}

void Vendedor::setTipoVendedor(char tipoVendedor) {
    this->tipoVendedor = tipoVendedor;
}

// Implementação do método calcularSalario da classe abstrata Funcionario
float Vendedor::calcularSalario(int diasFaltas) override {
    // Cálculo do salário do Vendedor com base nas regras fornecidas
    float salarioBase = std::stof(getSalario());
    float salarioDescontado = salarioBase - (salarioBase / 30) * diasFaltas;
    float gratificacao = 0.0;

    if (tipoVendedor == 'A') {
        gratificacao = salarioBase * 0.25;
    } 
    else if (tipoVendedor == 'B') {
        gratificacao = salarioBase * 0.1;
    } 
    else if (tipoVendedor == 'C') {
        gratificacao = salarioBase * 0.05;
    }

    float salarioFinal = salarioDescontado + gratificacao + (getQtdFilhos() * 100);

    return salarioFinal;
}

// Implementação do método calcularRecisao da classe abstrata Funcionario
float Vendedor::calcularRescisao(Data desligamento) override {
    // Cálculo da rescisão do Vendedor com base nas regras fornecidas
    int anosTrabalhados = desligamento.ano - getIngressoEmpresa().ano;
    float mesesTrabalhados = desligamento.mes - getIngressoEmpresa().mes;
    float diasTrabalhados = desligamento.dia - getIngressoEmpresa().dia;

    float tempoTrabalhado = anosTrabalhados + (mesesTrabalhados / 12) + (diasTrabalhados / 365);

    float salarioBaseAnual = std::stof(getSalario()) * 12;
    float rescisao = tempoTrabalhado * salarioBaseAnual;

    return rescisao;
}


void Vendedor::imprimirDados() const {
    std::cout << "Dados do Vendedor" << std::endl;
    std::cout << "Nome: " << getNome() << std::endl;
    std::cout << "CPF: " << getCpf() << std::endl;
    std::cout << "Data de Nascimento: " << getDataNascimento().dia << "/" << getDataNascimento().mes << "/" << getDataNascimento().ano << std::endl;
    std::cout << "Endereço: " << getEnderecoPessoal().rua << ", " << getEnderecoPessoal().numero << ", " << getEnderecoPessoal().bairro << ", " << getEnderecoPessoal().cidade << ", " << getEnderecoPessoal().cep << std::endl;
    std::cout << "Estado Civil: " << getEstadoCivil() << std::endl;
    std::cout << "Quantidade de Filhos: " << getQtdFilhos() << std::endl;
    std::cout << "Matrícula: " << getMatricula() << std::endl;
    std::cout << "Salário: " << getSalario() << std::endl;
    std::cout << "Data de Ingresso na Empresa: " << getIngressoEmpresa().dia << "/" << getIngressoEmpresa().mes << "/" << getIngressoEmpresa().ano << std::endl;
    std::cout << "Tipo de Vendedor: " << getTipoVendedor() << std::endl;
    std::cout << std::endl;
}