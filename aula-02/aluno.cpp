#include "aluno.hpp"

Aluno::Aluno(std::string nome, double nota1, double nota2)
    : nome(nome), nota1(nota1), nota2(nota2)
{
    media = (nota1 + nota2) / 2.0;
}