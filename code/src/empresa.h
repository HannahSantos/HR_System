#ifndef _EMPRESA_H_
#define _EMPRESA_H_

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "pessoa.h" // Inclua o arquivo que contém a definição da classe "Pessoa"
#include "asg.h" // Inclua o arquivo que contém a definição da classe "Asg"
#include "vendedor.h" // Inclua o arquivo que contém a definição da classe "Vendedor"
#include "gerente.h" // Inclua o arquivo que contém a definição da classe "Gerente"

class Empresa {
private:
    float faturamentoMensal;
    std::string nomeEmpresa;
    std::string cnpj;
    Pessoa dono;
    std::vector<Asg> asgs;
    std::vector<Vendedor> vendedores;
    std::vector<Gerente> gerentes;

public:
    // Construtor vazio
    Empresa() {}

    // Construtor parametrizado com o nomeEmpresa, cnpj e faturamentoMensal
    Empresa(std::string nomeEmpresa, std::string cnpj, float faturamentoMensal);

    // Métodos get e set para os atributos faturamentoMensal, nomeEmpresa e cnpj
    float getFaturamentoMensal();
    void setFaturamentoMensal(float faturamentoMensal);

    std::string getNomeEmpresa();
    void setNomeEmpresa(std::string nomeEmpresa);

    std::string getCnpj();
    void setCnpj(std::string cnpj);

    // Métodos get para os atributos dono, asgs, vendedores e gerentes
    Pessoa getDono();

    std::vector<Asg> getAsgs();

    std::vector<Vendedor> getVendedores();

    std::vector<Gerente> getGerentes();

    // Método para carregar as funções presentes no arquivo funcoes.txt
    void carregaFuncoes();

    // Método para carregar os dados da empresa a partir do arquivo empresa.txt
    void carregarEmpresa();

    // Método para carregar os dados dos ASGs a partir do arquivo asg.txt
    void carregarAsg();

    // Método para carregar os dados dos Vendedores a partir do arquivo vendedor.txt
    void carregarVendedor();

    // Método para carregar os dados dos Gerentes a partir do arquivo gerente.txt
    void carregarGerente();

    // Método para carregar os dados do dono a partir do arquivo dono.txt
    void carregaDono();

    // Método para imprimir todos os atributos dos ASGs
    void imprimeAsgs();

    // Método para imprimir todos os atributos dos Vendedores
    void imprimeVendedores();

    // Método para imprimir todos os atributos dos Gerentes
    void imprimeGerentes();

    // Método para imprimir todos os atributos do dono
    void imprimeDono();

    // Método para buscar um funcionário pelo número de matrícula
    void buscaFuncionario(std::string matricula);

    // Método para calcular o salário de um funcionário pelo número de matrícula
    void calculaSalarioFuncionario(std::string matricula);

    // Método para calcular os salários de todos os funcionários e salvar em um arquivo
    void calculaTodosOsSalarios();

    // Método para calcular a rescisão de um funcionário pelo número de matrícula e data de desligamento
    void calcularRescisao(std::string matricula, Data desligamento);
};


#endif