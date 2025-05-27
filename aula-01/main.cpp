#include <iostream>
#include "main.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Calculadora básica:" << endl<< "0- Sair" << endl << "1- Soma" << endl << "2- Subtração" << endl << "3- Divisão" << endl << "4- Multiplicação" << endl << "O que você quer fazer?" << endl;
    int opcao;
    cin >> opcao;
    if (opcao == 0) 
    {
        cout << "Fim de programa" << endl;
        return 0;
    }
    cout << "Certo! Agora insira dois números para fazer a operação:" << endl;
    int x;
    int y;
    int resultado = 0;
    cin >> x >> y; 
    switch (opcao)
    {
    case 1:
        resultado = soma(x,y);
        break;
    case 2:
        resultado = subtracao(x,y);
        break;
    case 3:
        resultado = divisao(x,y);
        break;
    case 4:
        resultado = multiplicacao(x,y);
        break;
    default:
        cout << "Erro! Opção não identificada" << endl;
    }
    cout << resultado << endl;
    return 0;
}
