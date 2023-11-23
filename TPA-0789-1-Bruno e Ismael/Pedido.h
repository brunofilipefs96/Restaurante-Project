#pragma once
#include <string>;
#include "Cliente.h"
#include "Produto.h"
#include <ctime>
#include <iostream>
using namespace std;

class Pedido
{
private:
    int id;
    int pratoIdQuantidade[50][2];
    int numeroLinha = 0;
    string nifCliente = "999999999";
    double precoUnitario;
    double total;
    double valorPago;
    bool pago = false;
    time_t now = time(0);

public:
    char* dataHora = ctime(&now);
    
    void updateId(int id);

    //Sets
    void setCliente(string nif_cliente);
    void setPrato(int idprato, int qtd);
    void setTotal(double total);
    void setPago(bool pago);

    //Gets
    int getIdPrato(int numeroLinha);
    int getQtdPrato(int numeroLinha);
    int getNumeroLinha();
    string getNifCliente();
    double getTotal();
    bool getPago();
    int getId();

    double calculaTroco(double vPago);

};
	



