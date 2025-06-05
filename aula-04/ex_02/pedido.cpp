#include <iostream>
#include "pedido.hpp"
#include "produto.hpp"
using namespace std;

void Pedido::adicionarProdutos(){
    string nome;
    double preco;
    int qtd;
    cout << "Nome: " << endl;
    getline(cin, nome);
    if(nome.empty()){
    throw invalid_argument("O nome não pode ser vazio.");
    }
    cout << "Preço: " << endl;
    cin >> preco;
    if(preco < 0){
        throw invalid_argument("Não existe valor negativo");
    }
    cin.ignore();
    cout << "Qtd: " << endl;
    cin >> qtd;
    if(qtd < 0){
        throw out_of_range("Não existe quantidade negativa");
    }
    cin.ignore();
}
