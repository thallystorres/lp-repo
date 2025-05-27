#pragma once

#include <vector>
#include "aluno.hpp"

struct Turma
{
    std::vector<Aluno> alunos;
    double mediaGeral;

    void adicionarAluno(Aluno aluno);

    double tirarMedia();
};
