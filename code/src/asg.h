#ifndef _ASG_H_
#define _ASG_H_

#include "pessoa.h" // Inclua o arquivo que contém a definição da classe "Pessoa"
#include "funcionario.h" // Inclua o arquivo que contém a definição da classe abstrata "Funcionario"

// Definição da classe concreta Asg que herda de Pessoa e Funcionario
class Asg : public Pessoa, public Funcionario {
private:
    float adicionalInsalubridade;

public:
    // Construtor vazio
    Asg() {}

    // Construtor parametrizado com todos os atributos
    Asg(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos,
        std::string salario, std::string matricula, Data ingressoEmpresa, float adicionalInsalubridade)
        : Pessoa(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos),
          Funcionario(salario, matricula, ingressoEmpresa) { this->adicionalInsalubridade = adicionalInsalubridade; }

    // Métodos get e set para o atributo adicionalInsalubridade
    float getAdicionalInsalubridade();
    void setAdicionalInsalubridade(float adicionalInsalubridade);

    // Implementação do método calcularSalario da classe abstrata Funcionario
    float calcularSalario(int diasFaltas) override;

    // Implementação do método calcularRecisao da classe abstrata Funcionario
    float calcularRescisao(Data desligamento) override;

    // Imprime os dados de um Asg
    void imprimirDados() const;
};

#endif