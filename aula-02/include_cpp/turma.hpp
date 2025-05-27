#pragma once

#include <vector>
#include "aluno.hpp"

struct Turma
{
    std::vector<Aluno> alunos;
    double mediaGeral = 0.0;

    void adicionarAluno(Aluno aluno);

    double tirarMedia();
};
