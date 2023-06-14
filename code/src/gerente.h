#ifndef _GERENTE_H_
#define _GERENTE_H_

#include "pessoa.h" // Inclua o arquivo que contém a definição da classe "Pessoa"
#include "funcionario.h" // Inclua o arquivo que contém a definição da classe abstrata "Funcionario"

// Definição da classe concreta Gerente que herda de Pessoa e Funcionario
class Gerente : public Pessoa, public Funcionario {
private:
    float participacaoLucros;

public:
    // Construtor vazio
    Gerente() {}

    // Construtor parametrizado com todos os atributos
    Gerente(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos,
            std::string salario, std::string matricula, Data ingressoEmpresa, float participacaoLucros)
        : Pessoa(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos),
          Funcionario(salario, matricula, ingressoEmpresa) { this->participacaoLucros = participacaoLucros; }

    // Métodos get e set para o atributo participacaoLucros
    float getParticipacaoLucros();
    void setParticipacaoLucros(float participacaoLucros);

    // Implementação do método calcularSalario da classe abstrata Funcionario
    float calcularSalario(int diasFaltas) override;

    // Implementação do método calcularRecisao da classe abstrata Funcionario
    float calcularRescisao(Data desligamento) override;

    // Imprime os dados de um Gerente
    void imprimirDados() const;
};
#endif