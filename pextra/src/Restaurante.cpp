#include <iostream>
#include <iomanip>
#include <map>
#include "Restaurante.hpp"

Restaurante::Restaurante() : mesas(3)
{
    adicionarItemCardapio("Pizza Kids", 29.99);
    adicionarItemCardapio("Pizza de Frango", 45.50);
    adicionarItemCardapio("Pizza Suprema", 55.00);
    adicionarItemCardapio("Coca Cola KS", 10.00);
    adicionarItemCardapio("Suco Jarra", 12.00);
}

void Restaurante::adicionarItemCardapio(const string &nome, double valor)
{
    cardapio.emplace_back(nome, valor);
}

void Restaurante::listarMesas() const
{
    cout << "\n--- Status das Mesas ---\n";
    for (size_t i = 0; i < mesas.size(); i++)
    {
        cout << "Mesa " << i + 1 << ": " << (mesas[i].estaAberta() ? "Aberta" : "Fechada") << endl;
        if (mesas[i].estaAberta())
        {
            const auto &pedidos = mesas[i].getPedidos();
            for (const auto &pedido : pedidos)
            {
                cout << " -" << pedido.nome << "(R$ " << fixed << setprecision(2) << pedido.valor << ")" << endl;
            }
            cout << "  Total até o momento: R$ " << fixed << setprecision(2) << mesas[i].getTotal() << endl;
        }
    }
}

void Restaurante::lancarPedido(int idMesa, int idPrato)
{
    if (idMesa < 1 || idMesa > int(mesas.size()) || idPrato < 1 || idPrato > int(cardapio.size()))
    {
        cout << "ID da mesa ou do prato inválido.\n";
        return;
    }
    if (!mesas[idMesa - 1].estaAberta() && mesas[idMesa - 1].getTotal() > 0)
    {
        cout << "Não é possível reabrir uma mesa já fechada.\n";
        return;
    }
    mesas[idMesa - 1].adicionarPedido(cardapio[idPrato - 1]);
    cout << "Pedido '" << cardapio[idPrato - 1].nome << "' adicionado à Mesa " << idMesa << ".\n";
}

void Restaurante::fecharMesa(int idMesa)
{
    if (idMesa < 1 || idMesa > int(mesas.size()))
    {
        cout << "ID da mesa inválido.\n";
    }
    if (!mesas[idMesa - 1].estaAberta())
    {
        cout << "Mesa " << idMesa << " já está fechada.\n";
        return;
    }
    cout << "\n--- Fechamento da Conta - Mesa " << idMesa << " ---\n";
    const auto &pedidos = mesas[idMesa - 1].getPedidos();
    for (const auto &pedido : pedidos)
    {
        cout << " - " << pedido.nome << " (R$ " << fixed << setprecision(2) << pedido.valor << ")" << endl;
         vendasTotais.push_back(pedido);
    }
    cout << "Total da conta: R$ " << fixed << setprecision(2) << mesas[idMesa - 1].getTotal() << endl;
    mesas[idMesa - 1].fecharConta();
    cout << "Conta da Mesa " << idMesa << " fechada.\n";
}

bool Restaurante::todasMesasFechadas() const
{
    for (const auto &mesa : mesas)
    {
        if (mesa.estaAberta())
        {
            return false;
        }
    }
    return true;
}

void Restaurante::gerarRelatorioVendas() const
{
    if (!todasMesasFechadas())
    {
        cout << "Ainda há mesas abertas. Feche todas as mesas para gerar o relatório de vendas\n.";
        return;
    }
    cout << "\n--- Relatório Final de Vendas ---\n";
    map<string, int> contagemItens;
    map<string, double> valorUnitarioItens;
    double totalVendido = 0.0;

    for (const auto& venda : vendasTotais){
        contagemItens[venda.nome]++;
        valorUnitarioItens[venda.nome] = venda.valor;
        totalVendido += venda.valor;
    }
    cout << left << setw(25) << "Item"
         << setw(15) << "Qtd. Vendida"
         << setw(15) << "Preço Unit."
         << "Valor Total" << endl;
    cout << string(70, '-') << endl;

    for (const auto& par : contagemItens) {
        string nomeItem = par.first;
        int quantidade = par.second;
        double precoUnit = valorUnitarioItens[nomeItem];
        double valorTotalItem = quantidade * precoUnit;

        cout << left << setw(25) << nomeItem
        << setw(15) << quantidade
        << "R$ " << fixed << setprecision(2) << setw(12) << precoUnit
        << "R$ " << fixed << setprecision(2) << valorTotalItem << endl;
    }

    cout << string(70, '-') << endl;
    cout << right << setw(55) << "TOTAL GERAL VENDIDO: R$ " << fixed << setprecision(2) << totalVendido << endl;
}

const vector<ItemPedido>& Restaurante::getCardapio() const {
    return cardapio;
}