#pragma once
#include "Titular.hpp"

class ContaBancaria
{
public:
    Titular dono;
    string numeroConta;
    double saldo;
    bool status;
    ContaBancaria(Titular dono, const string &numeroConta, double saldo, bool status);
};