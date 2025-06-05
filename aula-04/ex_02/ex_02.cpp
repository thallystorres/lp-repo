#include <iostream>
#include <vector>
#include "pedido.hpp"
#include "produto.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    Pedido pedido;
    while(true){
        try
        {
            pedido.adicionarProdutos();
        }
        catch(const exception& e)
        {
            cerr << e.what() << endl;
        }
        string fim;
        cout << "Digite FIM para encerrar o programa" << endl;
        getline(cin, fim);
        if(fim == "FIM"){
            break;
        }
    }
    cout << "Fim de programa" << endl;
    return 0;
}
