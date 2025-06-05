#pragma once
#include <vector>
#include "produto.hpp"

struct Pedido
{
    vector<Produto> produtos;
    Pedido() = default;
    void adicionarProdutos();
};
