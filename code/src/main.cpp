#include "empresa.h"

int main() {
    try {
        Empresa* atacadoDosCalcado = new Empresa("Atacado dos Calçados", "40.101.588/0001-98", 156289.56);
        atacadoDosCalcado->carregaFuncoes();
    } catch (std::exception& e) {
        std::cout << "O arquivo não pôde ser carregado: " << e.what() << std::endl;
    }

    return 0;
}
