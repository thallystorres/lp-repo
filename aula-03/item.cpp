#include "item.hpp"

Item::Item(string nome, int quantidade, double valorUnitario)
{
    this->nome = nome;
    this->quantidade = quantidade;
    this->valorUnitario = valorUnitario;

    this->valorTotal = this->valorUnitario * this->quantidade;
}