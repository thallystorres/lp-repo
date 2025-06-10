#pragma once
#include <string>
using namespace std;

namespace empresa
{
    struct Funcionario{
    string nome;
    int idade;
    double salario;
    Funcionario(string nome, int idade, double salario);
    };
} // namespace empresa
