#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> a;
    for (size_t i = 0; i < 5; i++)
    {
        cout << "Digite o número da posição " << i << " do array:" << endl;
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    while (true)
    {
        cout << "Que elemento você deseja acessar? (Digite -1 para sair)" << endl;
        int index;
        cin >> index;
        if (index == -1) break;
        try
        {
            cout << "O número é: " << a.at(index) << endl;
        }
        catch (const out_of_range& e)
        {
            cout << "Execção capturada: " << e.what() << endl;
            exit(1);
        }
    }

    return 0;
}
