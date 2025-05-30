#pragma once

#include <string>
using namespace std;

struct Item
{
    string nome;
    double quantidade;
    double valorUnitario;
    double valorTotal;

    // Constructor
    Item(string nome, int quantidade, double valorUnitario);
};