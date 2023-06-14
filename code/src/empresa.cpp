#include "empresa.h"

// Construtor parametrizado com o nomeEmpresa, cnpj e faturamentoMensal
Empresa::Empresa(std::string nomeEmpresa, std::string cnpj, float faturamentoMensal) {
    this->nomeEmpresa = nomeEmpresa;
    this->cnpj = cnpj;
    this->faturamentoMensal = faturamentoMensal;
}

// Métodos get e set para os atributos faturamentoMensal, nomeEmpresa e cnpj
float Empresa::getFaturamentoMensal() {
    return faturamentoMensal;
}

void Empresa::setFaturamentoMensal(float faturamentoMensal) {
    this->faturamentoMensal = faturamentoMensal;
}

std::string Empresa::getNomeEmpresa() {
    return nomeEmpresa;
}

void Empresa::setNomeEmpresa(std::string nomeEmpresa) {
    this->nomeEmpresa = nomeEmpresa;
}

std::string Empresa::getCnpj() {
    return cnpj;
}

void Empresa::setCnpj(std::string cnpj) {
    this->cnpj = cnpj;
}

// Métodos get para os atributos dono, asgs, vendedores e gerentes
Pessoa Empresa::getDono() {
    return dono;
}

std::vector<Asg> Empresa::getAsgs() {
    return asgs;
}

std::vector<Vendedor> Empresa::getVendedores() {
    return vendedores;
}

std::vector<Gerente> Empresa::getGerentes() {
    return gerentes;
}

// Método para carregar as funções presentes no arquivo funcoes.txt
void Empresa::carregaFuncoes() {
    std::ifstream file("funcoes.txt");
    std::string line;

    while (std::getline(file, line)) {
        // Verificar se a linha não está vazia
        if (!line.empty()) {
            // Chamar a função correspondente à linha
            chamarFuncao(line);
        }
    }

    file.close();
}

void Empresa::chamarFuncao(const std::string& linha) {
    std::istringstream iss(linha);
    std::string funcao;

    // Extrair o nome da função da linha
    if (iss >> funcao) {
        // Verificar qual função deve ser chamada
        if (funcao == "carregarEmpresa") {
            carregarEmpresa();
        } 
        else if (funcao == "carregarAsg") {
            carregarAsg();
        } 
        else if (funcao == "carregarVendedor") {
            carregarVendedor();
        } 
        else if (funcao == "carregarGerente") {
            carregarGerente();
        } 
        else if (funcao == "carregaDono") {
            carregaDono();
        } 
        else if (funcao == "imprimeAsgs") {
            imprimeAsgs();
        } 
        else if (funcao == "imprimeVendedores") {
            imprimeVendedores();
        } 
        else if (funcao == "imprimeGerentes") {
            imprimeGerentes();
        } 
        else if (funcao == "imprimeDono") {
            imprimeDono();
        } 
        else if (funcao == "buscaFuncionario") {
            istd::string matricula;
            if (iss >> matricula) {
                buscaFuncionario(matricula);
            }
        } 
        else if (funcao == "calculaSalarioFuncionario") {
            std::string matricula;
            if (iss >> matricula) {
                calculaSalarioFuncionario(matricula);
            }
        } 
        else if (funcao == "calculaTodosOsSalarios") {
            calculaTodosOsSalarios();
        } 
        else if (funcao == "calcularRescisao") {
            std::string matricula;
            Data desligamento;
            if (iss >> matricula >> desligamento.ano >> desligamento.mes >> desligamento.dia) {
                calcularRescisao(matricula, desligamento);
            }
        } 
        else {
            // Função não reconhecida
            std::cout << "Função não reconhecida: " << funcao << std::endl;
        }
    }
}


// Método para carregar os dados da empresa a partir do arquivo empresa.txt
void Empresa::carregarEmpresa() {
    std::ifstream file("empresa.txt");
    std::string nome;
    float faturamento;
    std::string cnpj;

    if (file >> nome >> cnpj >> faturamento) {
        setNomeEmpresa(nome);
        setCnpj(cnpj);
        setFaturamentoMensal(faturamento);
    } 
    else {
        std::cout << "Erro ao ler o arquivo empresa.txt." << std::endl;
    }

    file.close();
}

// Método para carregar os dados dos ASGs a partir do arquivo asg.txt
void Empresa::carregarAsg() {
    std::ifstream file("asg.txt");
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo asg.txt." << std::endl;
        return;
    }

    int qtdAsgs;
    if (!(file >> qtdAsgs)) {
        std::cout << "Erro ao ler a quantidade de ASGs." << std::endl;
        file.close();
        return;
    }

    for (int i = 0; i < qtdAsgs; i++) {
        std::string nome;
        std::string cpf;
        int ano, mes, dia;
        std::string cidade;
        std::string bairro;
        std::string rua;
        std::string cep;
        int numero;
        std::string estadoCivil;
        int qtdFilhos;
        float salario;
        std::string matricula;
        int anoIngresso, mesIngresso, diaIngresso;

        if (!(file >> nome >> cpf >> ano >> mes >> dia >> cidade >> bairro >> rua >> cep >> numero >> estadoCivil >> qtdFilhos >> salario >> matricula >> anoIngresso >> mesIngresso >> diaIngresso)) {
            std::cout << "Erro ao ler os dados do ASG." << std::endl;
            break;
        }

        Data dataNascimento(ano, mes, dia);
        Endereco enderecoPessoal(cidade, bairro, rua, cep, numero);
        Data ingressoEmpresa(anoIngresso, mesIngresso, diaIngresso);

        Asg asg(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos, salario, matricula, ingressoEmpresa);
        asgs.push_back(asg);
    }

    file.close();
}

// Método para carregar os dados dos Vendedores a partir do arquivo vendedor.txt
void Empresa::carregarVendedor() {
    std::ifstream file("vendedor.txt");
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo vendedor.txt." << std::endl;
        return;
    }

    int qtdVendedores;
    if (!(file >> qtdVendedores)) {
        std::cout << "Erro ao ler a quantidade de vendedores." << std::endl;
        file.close();
        return;
    }

    for (int i = 0; i < qtdVendedores; i++) {
        std::string nome;
        std::string cpf;
        int ano, mes, dia;
        std::string cidade;
        std::string bairro;
        std::string rua;
        std::string cep;
        int numero;
        std::string estadoCivil;
        int qtdFilhos;
        float salario;
        std::string matricula;
        int anoIngresso, mesIngresso, diaIngresso;
        char tipoVendedor;

        if (!(file >> nome >> cpf >> ano >> mes >> dia >> cidade >> bairro >> rua >> cep >> numero >> estadoCivil >> qtdFilhos >> salario >> matricula >> anoIngresso >> mesIngresso >> diaIngresso >> tipoVendedor)) {
            std::cout << "Erro ao ler os dados do vendedor." << std::endl;
            break;
        }

        Data dataNascimento(ano, mes, dia);
        Endereco enderecoPessoal(cidade, bairro, rua, cep, numero);
        Data ingressoEmpresa(anoIngresso, mesIngresso, diaIngresso);

        Vendedor vendedor(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos, salario, matricula, ingressoEmpresa, tipoVendedor);
        vendedores.push_back(vendedor);
    }

    file.close();
}


// Método para carregar os dados dos Gerentes a partir do arquivo gerente.txt
void Empresa::carregarGerente() {
    std::ifstream file("gerente.txt");
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo gerente.txt." << std::endl;
        return;
    }

    int qtdGerentes;
    if (!(file >> qtdGerentes)) {
        std::cout << "Erro ao ler a quantidade de gerentes." << std::endl;
        file.close();
        return;
    }

    for (int i = 0; i < qtdGerentes; i++) {
        std::string nome;
        std::string cpf;
        int ano, mes, dia;
        std::string cidade;
        std::string bairro;
        std::string rua;
        std::string cep;
        int numero;
        std::string estadoCivil;
        int qtdFilhos;
        float salario;
        std::string matricula;
        int anoIngresso, mesIngresso, diaIngresso;
        float participacaoLucros;

        if (!(file >> nome >> cpf >> ano >> mes >> dia >> cidade >> bairro >> rua >> cep >> numero >> estadoCivil >> qtdFilhos >> salario >> matricula >> anoIngresso >> mesIngresso >> diaIngresso >> participacaoLucros)) {
            std::cout << "Erro ao ler os dados do gerente." << std::endl;
            break;
        }

        Data dataNascimento(ano, mes, dia);
        Endereco enderecoPessoal(cidade, bairro, rua, cep, numero);
        Data ingressoEmpresa(anoIngresso, mesIngresso, diaIngresso);

        Gerente gerente(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos, salario, matricula, ingressoEmpresa, participacaoLucros);
        gerentes.push_back(gerente);
    }

    file.close();
}


// Método para carregar os dados do dono a partir do arquivo dono.txt
void Empresa::carregaDono() {
    std::ifstream file("dono.txt");
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo dono.txt." << std::endl;
        return;
    }

    std::string nome;
    std::string cpf;
    int ano, mes, dia;
    std::string cidade;
    std::string bairro;
    std::string rua;
    std::string cep;
    int numero;
    std::string estadoCivil;
    int qtdFilhos;

    if (!(file >> nome >> cpf >> ano >> mes >> dia >> cidade >> bairro >> rua >> cep >> numero >> estadoCivil >> qtdFilhos)) {
        std::cout << "Erro ao ler os dados do dono." << std::endl;
        file.close();
        return;
    }

    Data dataNascimento(ano, mes, dia);
    Endereco enderecoPessoal(cidade, bairro, rua, cep, numero);

    dono = Pessoa(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos);

    file.close();
}


// Método para imprimir todos os atributos dos ASGs
void Empresa::imprimeAsgs() {
    std::cout << "----- ASGs -----" << std::endl;
    for (const auto& asg : asgs) {
        asg.imprimirDados();
    }
}


// Método para imprimir todos os atributos dos Vendedores
void Empresa::imprimeVendedores() {
    std::cout << "----- Vendedores -----" << std::endl;
    for (const auto& vendedor : vendedores) {
        vendedor.imprimirDados();
    }
}


// Método para imprimir todos os atributos dos Gerentes
void Empresa::imprimeGerentes() {
    std::cout << "----- Gerentes -----" << std::endl;
    for (const auto& gerente : gerentes) {
        gerente.imprimirDados();
    }
}


// Método para imprimir todos os atributos do dono
void Empresa::imprimeDono() {
    std::cout << "----- Dono -----" << std::endl 
              << "Nome: " << dono.getNome() << std::endl
              << "CPF: " << dono.getCPF() << std::endl
              << "Data de Nascimento: " << dono.getDataNascimento().dia << "/"
              << dono.getDataNascimento().mes << "/" << dono.getDataNascimento().ano << std::endl
              << "Endereço: " << std::endl
              << "   Cidade: " << dono.getEnderecoPessoal().cidade << std::endl
              << "   Bairro: " << dono.getEnderecoPessoal().bairro << std::endl
              << "   Rua: " << dono.getEnderecoPessoal().rua << std::endl
              << "   CEP: " << dono.getEnderecoPessoal().cep << std::endl
              << "   Número: " << dono.getEnderecoPessoal().numero << std::endl
              << "Estado Civil: " << dono.getEstadoCivil() << std::endl
              << "Quantidade de Filhos: " << dono.getQtdFilhos() << std::endl
              << std::endl;
}


// Método para buscar um funcionário pelo número de matrícula
void Empresa::buscaFuncionario(std::string matricula) {
    bool encontrado = false;

    // Busca nos ASGs
    for (const auto& asg : asgs) {
        if (asg.getMatricula() == matricula) {
            encontrado = true;
            std::cout << "----- ASG Encontrado -----" << std::endl;
            asg.imprimirDados();
            break;
        }
    }

    // Busca nos Vendedores
    if (!encontrado) {
        for (const auto& vendedor : vendedores) {
            if (vendedor.getMatricula() == matricula) {
                encontrado = true;
                std::cout << "----- Vendedor Encontrado -----" << std::endl;
                vendedor.imprimirDados();
                break;
            }
        }
    }

    // Busca nos Gerentes
    if (!encontrado) {
        for (const auto& gerente : gerentes) {
            if (gerente.getMatricula() == matricula) {
                encontrado = true;
                std::cout << "----- Gerente Encontrado -----" << std::endl;
                gerente.imprimirDados();
                break;
            }
        }
    }

    // Funcionário não encontrado
    if (!encontrado) {
        std::cout << "Funcionário não encontrado no sistema" << std::endl;
    }
}


// Método para calcular o salário de um funcionário pelo número de matrícula
float Empresa::calculaSalarioFuncionario(std::string matricula) {
    // Busca nos ASGs
    for (const auto& asg : asgs) {
        if (asg.getMatricula() == matricula) {
            return asg.calcularSalario(diasFaltas);
        }
    }

    // Busca nos Vendedores
    for (const auto& vendedor : vendedores) {
        if (vendedor.getMatricula() == matricula) {
            return vendedor.calcularSalario(diasFaltas);
        }
    }

    // Busca nos Gerentes
    for (const auto& gerente : gerentes) {
        if (gerente.getMatricula() == matricula) {
            return gerente.calcularSalario(diasFaltas);
        }
    }

    // Funcionário não encontrado
    std::cout << "Funcionário não encontrado no sistema" << std::endl;
    return 0.0f;
}


// Método para calcular os salários de todos os funcionários e salvar em um arquivo
void Empresa::calculaTodoOsSalarios() {
    // Abrir arquivo para escrita
    std::ofstream arquivo("salarios.txt");

    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir o arquivo salarios.txt" << std::endl;
        return;
    }

    // Variáveis para total de salários
    float totalSalariosASGs = 0.0f;
    float totalSalariosVendedores = 0.0f;
    float totalSalariosGerentes = 0.0f;
    float totalSalariosEmpresa = 0.0f;

    // Calcular salários de ASGs
    arquivo << "ASGs:" << std::endl;
    for (const auto& asg : asgs) {
        float salario = asg.calcularSalario(diasFaltas);
        arquivo << "Nome: " << asg.getNome() << ", Cargo: ASG, Salário: R$" << salario << std::endl;
        totalSalariosASGs += salario;
        totalSalariosEmpresa += salario;
    }
    arquivo << "Total de salários de ASGs: R$" << totalSalariosASGs << std::endl;

    // Calcular salários de Vendedores
    arquivo << "Vendedores:" << std::endl;
    for (const auto& vendedor : vendedores) {
        float salario = vendedor.calcularSalario(diasFaltas);
        arquivo << "Nome: " << vendedor.getNome() << ", Cargo: Vendedor, Salário: R$" << salario << std::endl;
        totalSalariosVendedores += salario;
        totalSalariosEmpresa += salario;
    }
    arquivo << "Total de salários de Vendedores: R$" << totalSalariosVendedores << std::endl;

    // Calcular salários de Gerentes
    arquivo << "Gerentes:" << std::endl;
    for (const auto& gerente : gerentes) {
        float salario = gerente.calcularSalario(diasFaltas);
        arquivo << "Nome: " << gerente.getNome() << ", Cargo: Gerente, Salário: R$" << salario << std::endl;
        totalSalariosGerentes += salario;
        totalSalariosEmpresa += salario;
    }
    arquivo << "Total de salários de Gerentes: R$" << totalSalariosGerentes << std::endl;

    arquivo << "Total de salários da empresa: R$" << totalSalariosEmpresa << std::endl;

    // Fechar arquivo
    arquivo.close();

    // Exibir resultados no console
    std::cout << "Salários calculados e salvos no arquivo salarios.txt" << std::endl
              << "Total de salários de ASGs: R$" << totalSalariosASGs << std::endl
              << "Total de salários de Vendedores: R$" << totalSalariosVendedores << std::endl
              << "Total de salários de Gerentes: R$" << totalSalariosGerentes << std::endl
              << "Total de salários da empresa: R$" << totalSalariosEmpresa << std::endl;
}


// Método para calcular a rescisão de um funcionário pelo número de matrícula e data de desligamento
void Empresa::calcularRescisao(std::string matricula, Data desligamento) {
    bool encontrado = false;

    // Procurar o funcionário pelo número de matrícula
    for (Asg& asg : asgs) {
        if (asg.getMatricula() == matricula) {
            encontrado = true;
            float valorRescisao = asg.calcularRescisao(desligamento);
            std::cout << "Valor da rescisão do ASG: R$" << valorRescisao << std::endl;
            break;
        }
    }

    if (!encontrado) {
        for (Vendedor& vendedor : vendedores) {
            if (vendedor.getMatricula() == matricula) {
                encontrado = true;
                float valorRescisao = vendedor.calcularRescisao(desligamento);
                std::cout << "Valor da rescisão do Vendedor: R$" << valorRescisao << std::endl;
                break;
            }
        }
    }

    if (!encontrado) {
        for (Gerente& gerente : gerentes) {
            if (gerente.getMatricula() == matricula) {
                encontrado = true;
                float valorRescisao = gerente.calcularRescisao(desligamento);
                std::cout << "Valor da rescisão do Gerente: R$" << valorRescisao << std::endl;
                break;
            }
        }
    }

    // Caso o funcionário não seja encontrado
    if (!encontrado) {
        std::cout << "Funcionário não encontrado no sistema." << std::endl;
    }
}
