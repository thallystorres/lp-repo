#pragma once

#include <string>

struct Aluno
{
    std::string nome;
    double nota1;
    double nota2;
    double media;

    // Constructor

    Aluno(std::string nome, double nota1, double nota2);
};