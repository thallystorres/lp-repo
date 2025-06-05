#pragma once
#include <string>
using namespace std;

struct Produto{
    string nome;
    double preco;
    int qtd;
    Produto(string nome, double preco, int qtd);
};