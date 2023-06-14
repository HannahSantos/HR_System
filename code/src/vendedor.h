#ifndef _VENDEDOR_H_
#define _VENDEDOR_H_

#include "pessoa.h" // Inclua o arquivo que contém a definição da classe "Pessoa"
#include "funcionario.h" // Inclua o arquivo que contém a definição da classe abstrata "Funcionario"

// Definição da classe concreta Vendedor que herda de Pessoa e Funcionario
class Vendedor : public Pessoa, public Funcionario {
private:
    char tipoVendedor;

public:
    // Construtor vazio
    Vendedor() {}

    // Construtor parametrizado com todos os atributos
    Vendedor(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos,
             std::string salario, std::string matricula, Data ingressoEmpresa, char tipoVendedor)
        : Pessoa(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos),
          Funcionario(salario, matricula, ingressoEmpresa) { this->tipoVendedor = tipoVendedor; }

    // Métodos get e set para o atributo tipoVendedor
    char getTipoVendedor();
    void setTipoVendedor(char tipoVendedor);

    // Implementação do método calcularSalario da classe abstrata Funcionario
    float calcularSalario(int diasFaltas) override;

    // Implementação do método calcularRecisao da classe abstrata Funcionario
    float calcularRescisao(Data desligamento) override;

    // Imprime os dados de um Vendedor
    void imprimirDados() const;
};

#endif
