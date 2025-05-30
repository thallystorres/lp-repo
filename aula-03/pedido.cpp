#include "pedido.hpp"

Pedido::Pedido(vector<Item> itens){
    this->itens = itens;
    this->valorTotalDaCompra = 0;
    for(Item item: itens){
        this->valorTotalDaCompra += item.valorTotal;
    }
}