#include <iostream>
#include <limits>
#include "Restaurante.hpp"

void mostrarMenuUsuario() {
    std::cout << "\n===== Sistema de Gestão do Restaurante =====\n";
    std::cout << "1. Listar Mesas e Pedidos\n";
    std::cout << "2. Lançar Pedido\n";
    std::cout << "3. Fechar Conta da Mesa\n";
    std::cout << "4. Gerar Relatório de Vendas (apenas com todas as mesas fechadas)\n";
    std::cout << "0. Sair\n";
    std::cout << "Escolha uma opção: ";
}

void mostrarCardapio(const Restaurante& restaurante) {
    std::cout << "\n--- Cardápio ---\n";
    const auto& cardapio = restaurante.getCardapio();
    for (size_t i = 0; i < cardapio.size(); ++i) {
        std::cout << i + 1 << ". " << cardapio[i].nome << " - R$ " << cardapio[i].valor << std::endl;
    }
}

int main() {
    Restaurante meuRestaurante;
    int opcao;

    do {
        mostrarMenuUsuario();
        std::cin >> opcao;

        if (std::cin.fail()) {
            std::cout << "Entrada inválida. Por favor, insira um número.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (opcao) {
            case 1:
                meuRestaurante.listarMesas();
                break;
            case 2: {
                int idMesa, idPrato;
                meuRestaurante.listarMesas();
                std::cout << "Digite o número da mesa: ";
                std::cin >> idMesa;
                mostrarCardapio(meuRestaurante);
                std::cout << "Digite o ID do prato: ";
                std::cin >> idPrato;
                meuRestaurante.lancarPedido(idMesa, idPrato);
                break;
            }
            case 3: {
                int idMesa;
                meuRestaurante.listarMesas();
                std::cout << "Digite o número da mesa para fechar a conta: ";
                std::cin >> idMesa;
                meuRestaurante.fecharMesa(idMesa);
                break;
            }
            case 4:
                meuRestaurante.gerarRelatorioVendas();
                break;
            case 0:
                std::cout << "Saindo do sistema...\n";
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    } while (opcao != 0);

    return 0;
}