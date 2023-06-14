#ifndef _UTIL_H_
#define _UTIL_H_

#include <string>
#include <iostream>

// Definição da estrutura Data
typedef struct{
    int ano;
    int mes;
    int dia;
}Data;

// Definição da estrutura Endereco
typedef struct{
    std::string cidade;
    std::string bairro;
    std::string rua;
    std::string cep;
    int numero;
}Endereco;

#endif