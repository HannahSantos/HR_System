#ifndef _PESSOA_H_
#define _PESSOA_H_

#include "util.h"

// Definição da classe Pessoa
class Pessoa {
private:
    std::string nome;
    std::string cpf;
    Data dataNascimento;
    Endereco enderecoPessoal;
    std::string estadoCivil;
    int qtdFilhos;

public:
    // Construtor vazio
    Pessoa() {}

    // Construtor parametrizado com todos os atributos
    Pessoa(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos);

    // Métodos get e set para todos os atributos
    std::string getNome();
    void setNome(std::string nome);

    std::string getCPF();
    void setCPF(std::string cpf);

    Data getDataNascimento();
    void setDataNascimento(Data dataNascimento);

    Endereco getEnderecoPessoal();
    void setEnderecoPessoal(Endereco enderecoPessoal);

    std::string getEstadoCivil();
    void setEstadoCivil(std::string estadoCivil);

    int getQtdFilhos();
    void setQtdFilhos(int qtdFilhos);
};

#endif