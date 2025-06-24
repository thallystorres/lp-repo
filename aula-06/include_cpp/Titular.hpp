#pragma once
#include <string>
using namespace std;

class Titular
{
private:
    string nome;
    string CPF;

public:
    Titular(const string &nome, const string &CPF);
};
