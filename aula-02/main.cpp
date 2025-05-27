#include <iostream>
#include <vector>
#include <string>
#include "include_cpp/aluno.hpp"
#include "include_cpp/turma.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    Turma turma;
    while (true)
    {
        cout << "O que você deseja fazer?" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Adicionar alunos" << endl;
        cout << "2 - Exibir aluno(s)" << endl;
        cout << "3 - Buscar aluno" << endl;
        int opcao;
        cin >> opcao;
        size_t qtd;
        string nome;
        double nota1;
        double nota2;

        switch (opcao)
        {
            case 0:
                cout << "Fim do programa" << endl;
                exit(0);
                break;
            case 1:
                cout << "Quantos alunos você deseja adicionar: ";
                cin >> qtd;
                for (size_t i = 0; i < qtd; i++)
                {
                    cout << "Nome do aluno: ";
                    cin >> nome;
                    cout << "Nota 1: ";
                    cin >> nota1;
                    cout << "Nota 2: ";
                    cin >> nota2;
                    Aluno aluno(nome, nota1, nota2);
                    turma.adicionarAluno(aluno);
                    cout << "A média do aluno é" << aluno.media;
                }
                break;
            case 2:
                cout << "Alunos da turma: " << endl;
                for (size_t i = 0; i < turma.alunos.size(); i++)
                {
                    cout << i + 1 << "- " << turma.alunos[i].nome << " | " << turma.alunos[i].nota1 << " | " << turma.alunos[i].nota2 << " | " << turma.alunos[i].media << endl;
                }
                cout << "Média final da turma: " << turma.mediaGeral << endl;
                break;
            case 3:
                cout << "Qual aluno você deseja buscar?" << endl;
                cin >> nome;
                for (Aluno aluno : turma.alunos)
                {
                    if (aluno.nome == nome)
                    {
                    cout << aluno.nome << " | " << aluno.nota1 << " | " << aluno.nota2 << " | " << aluno.media << endl;
                    }
                    else {
                        cout << "Aluno não encontrado" << endl;
                    }
                }
                break;
            default:
                break;
        }
    }
    return 0;
}
