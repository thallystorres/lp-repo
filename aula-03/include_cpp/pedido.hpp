#pragma once
#include <vector>
#include "item.hpp"
using namespace std;

struct Pedido{
    vector<Item> itens;
    double valorTotalDaCompra;

    Pedido(vector<Item> itens);
};