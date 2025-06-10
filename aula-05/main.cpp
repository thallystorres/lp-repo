#include "funcionario.hpp"
#include <iostream>
using namespace std;

namespace cadastrarFuncionario
{
    empresa::Funcionario cadastrarFuncionario(string nome, int idade, double salario){
        return empresa::Funcionario(nome, idade, salario);
    }
} // namespace cadastrarFuncionario


int main(int argc, char const *argv[])
{
    while (true)
    {
        string nome;
        int idade;
        double salario;
        cout << "Digite seu nome: ";
        cin >> nome;
        cout << "Digite sua idade: ";
        cin >> idade;
        cout << "Digite seu salario: ";
        cin >> salario;
        empresa::Funcionario funcionario = cadastrarFuncionario::cadastrarFuncionario(nome, idade, salario);
        string input;
        cout << "Digite n para sair" << endl;
        cin.ignore();
        getline(cin, input);
        if(input == "n") break;
    }
    
    return 0;
}
