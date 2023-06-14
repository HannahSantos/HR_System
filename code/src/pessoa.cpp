#include "pessoa.h"

// Construtor parametrizado com todos os atributos
Pessoa::Pessoa(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos) {
    this->nome = nome;
    this->cpf = cpf;
    this->dataNascimento = dataNascimento;
    this->enderecoPessoal = enderecoPessoal;
    this->estadoCivil = estadoCivil;
    this->qtdFilhos = qtdFilhos;
}

// Métodos get e set para todos os atributos
std::string Pessoa::getNome() {
    return nome;
}

void Pessoa::setNome(std::string nome) {
    this->nome = nome;
}

std::string Pessoa::getCPF() {
    return cpf;
}

void Pessoa::setCPF(std::string cpf) {
    this->cpf = cpf;
}

Data Pessoa::getDataNascimento() {
    return dataNascimento;
}

void Pessoa::setDataNascimento(Data dataNascimento) {
    this->dataNascimento = dataNascimento;
}

Endereco Pessoa::getEnderecoPessoal() {
    return enderecoPessoal;
}

void Pessoa::setEnderecoPessoal(Endereco enderecoPessoal) {
    this->enderecoPessoal = enderecoPessoal;
}

std::string Pessoa::getEstadoCivil() {
    return estadoCivil;
}

void Pessoa::setEstadoCivil(std::string estadoCivil) {
    this->estadoCivil = estadoCivil;
}

int Pessoa::getQtdFilhos() {
    return qtdFilhos;
}

void Pessoa::setQtdFilhos(int qtdFilhos) {
    this->qtdFilhos = qtdFilhos;
}