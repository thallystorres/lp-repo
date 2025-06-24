#include "ContaBancaria.hpp"

ContaBancaria::ContaBancaria(Titular dono, const string &numeroConta, double saldo, bool status) : dono(dono), numeroConta(numeroConta), status(status) {
    if(saldo > 0) {
        this-> saldo = saldo;
    }
}
