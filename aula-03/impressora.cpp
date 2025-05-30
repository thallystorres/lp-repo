#include <iostream>
#include <string>
#include "impressora.hpp"

using namespace std;

void Impressora::imprimeItem(Item item){
    cout << "Item |" << " Preço |" << " Qtd |" << " Total" << endl;
    cout << item.nome << " | " << item.valorUnitario << " | " << item.quantidade << " | " << item.valorTotal << endl;
}

void Impressora::imprimePedido(Pedido pedido){
    cout << "Item |" << " Preço |" << " Qtd |" << " Total" << endl;
    for(Item item: pedido.itens)
    {
        cout << item.nome << " | " << item.valorUnitario << " | " << item.quantidade << " | " << item.valorTotal << endl;
    }
}