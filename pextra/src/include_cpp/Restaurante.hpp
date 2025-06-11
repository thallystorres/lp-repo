#pragma once

#include <Mesa.hpp>
#include <ItemPedido.hpp>

class Restaurante
{
private:
    vector<ItemPedido> cardapio;
    vector<Mesa> mesas;
    vector<ItemPedido> vendasTotais;
public:
    Restaurante();
    void adicionarItemCardapio(const string &nome, double valor);
    void listarMesas() const;
    void lancarPedido(int idMesa, int idPrato);
    void fecharMesa(int idMesa);
    void gerarRelatorioVendas() const;
    bool todasMesasFechadas() const;
    const vector<ItemPedido>& getCardapio() const;
};