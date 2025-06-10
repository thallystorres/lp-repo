#include "funcionario.hpp"
#include <string>
#include <iostream>
using namespace std;

empresa::Funcionario::Funcionario(string nome, int idade, double salario){
    if (idade <= 18){
        throw invalid_argument("O funcionário deve ser maior de idade.");
    }
    this->nome = nome;
    this->idade = idade;
    this->salario = salario;
}