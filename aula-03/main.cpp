#include <iostream>
#include <string>
#include <vector>
#include "item.hpp"
#include "pedido.hpp"
#include "impressora.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    Impressora impressora;
    Item item1("Pão", 10, 15);
    Item item2("Ovos", 2, 15);
    vector<Item> itens = {item1, item2};
    Pedido pedido1(itens);
    // impressora.imprimeItem(item1);
    // impressora.imprimeItem(item2);
    impressora.imprimePedido(pedido1);
    return 0;
}

