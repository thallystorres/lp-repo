#include <iostream>
#include "turma.hpp"
using namespace std;

void Turma::adicionarAluno(Aluno aluno)
{
    if (this->alunos.size() == 10)
    {
        cout << "Capacidade máxima de alunos atingida" << endl;
        return;
    }
    this->alunos.push_back(aluno);
    this->mediaGeral = this->tirarMedia();
}

double Turma::tirarMedia()
{
    if (alunos.empty()) return 0.0;

    double soma = 0.0;
    for (Aluno aluno : this->alunos)
    {
        soma += aluno.media;
    }
    double mediaGeral = soma / this->alunos.size();
    return mediaGeral;
}