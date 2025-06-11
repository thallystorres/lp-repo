#pragma once
#include <vector>
#include "ItemPedido.hpp"

class Mesa
{
private:
    bool aberta;
    vector<ItemPedido> pedidos;

public:
    Mesa();
    void adicionarPedido(const ItemPedido &pedido);
    double getTotal() const;
    void fecharConta();
    bool estaAberta() const;
    const vector<ItemPedido> &getPedidos() const;
};