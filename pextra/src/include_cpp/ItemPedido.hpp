#pragma once
#include <string>
using namespace std;

class ItemPedido
{
public:
    string nome;
    double valor;

    ItemPedido(const string &nome, double valor);
};