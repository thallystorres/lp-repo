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
        cout << "3 - Buscar aluno" << endl
             << endl;
        int opcao;
        cin >> opcao;
        size_t qtd;
        string nome;
        double nota1;
        double nota2;

        switch (opcao)
        {
        case 0:
            cout << "Fim do programa" << endl
                 << endl;
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
                cout << "A média do aluno é " << aluno.media << endl
                     << endl;
            }
            break;
        case 2:
            cout << "Alunos da turma: " << endl
                 << endl;
            for (size_t i = 0; i < turma.alunos.size(); i++)
            {
                cout << i + 1 << "- " << turma.alunos[i].nome << " | " << turma.alunos[i].nota1 << " | " << turma.alunos[i].nota2 << " | " << turma.alunos[i].media << endl
                     << endl;
            }
            cout << "Média final da turma: " << turma.mediaGeral << endl
                 << endl;
            break;
        case 3:
        {
            cout << "Qual aluno você deseja buscar?" << endl;
            cin.ignore();
            getline(cin, nome);

            bool encontrado = false;

            for (Aluno aluno : turma.alunos)
            {
                if (aluno.nome == nome)
                {
                    cout << "Nome: " << aluno.nome 
                        << " | Nota 1: " << aluno.nota1 
                        << " | Nota 2: " << aluno.nota2 
                        << " | Media: " << aluno.media << endl << endl;
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado)
            {
                cout << "Aluno não encontrado" << endl << endl;
            }
            break;
        }
        default:
            break;
        }
    }
    return 0;
}