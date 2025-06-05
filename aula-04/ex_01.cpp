#include <iostream>
#include <vector>
using namespace std;

double med(const vector<int>& vetor)
{
    int total = 0;
    for (int numero : vetor)
    {
        total += numero;
    }
    return total/vetor.size();
}

int customMax(const vector<int>& vetor){
    int maxi = 0;
    for(int numero : vetor){
        maxi = max(maxi, numero);
    }
    return maxi;
}

int customMin(const vector<int>& vetor){
    int mini = 0;
    for(int numero : vetor){
        mini = min(mini, numero);
    }
    return mini;
}

int main(int argc, char const *argv[])
{
    vector<int> vetor;
    while (true)
    {
        int numero;
        cout << "Digite um número: ";
        cin >> numero;
        if (numero == -1)
            break;
        else if (numero < 0)
        {
            throw invalid_argument("Digite um número");
        }
        else if (numero > 10000)
        {
            throw overflow_error("Digite um número menor que 10000");
        }
        else
        {
            vetor.push_back(numero);
        }
    }
    cout << "Existem " << vetor.size() << " valores válidos" << endl << "A média dos valores válidos é: " << med(vetor) << endl << "O maior valor é " << customMax(vetor) << endl << "E o menor valor: " << customMin(vetor) << endl;
    return 0;
}
