#pragma once
#include "pedido.hpp"
using namespace std;

struct Impressora
{
    void imprimePedido(Pedido pedido);
    void imprimeItem(Item item);
};
