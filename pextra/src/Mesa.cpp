#include "Mesa.hpp"

Mesa::Mesa() : aberta(false) {}

void Mesa::adicionarPedido(const ItemPedido &pedido)
{
    if (!aberta)
    {
        aberta = true;
    }
    this->pedidos.push_back(pedido);
}

double Mesa::getTotal() const
{
    double total = 0.0;
    for (const auto &pedido : pedidos)
    {
        total += pedido.valor;
    }
    return total;
}

void Mesa::fecharConta()
{
    aberta = false;
}

bool Mesa::estaAberta() const
{
    return aberta;
}

const vector<ItemPedido> &Mesa::getPedidos() const
{
    return pedidos;
}