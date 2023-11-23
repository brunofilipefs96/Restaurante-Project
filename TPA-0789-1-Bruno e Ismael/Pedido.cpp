#include "Pedido.h"


void Pedido::setCliente(string nifCliente)
{
    this->nifCliente = nifCliente;
}


int Pedido::getIdPrato(int numeroLinha)
{
    return pratoIdQuantidade[numeroLinha][0];
}

int Pedido::getQtdPrato(int numeroLinha)
{
    return pratoIdQuantidade[numeroLinha][1];
}

void Pedido::updateId(int id) {
    this -> id = id;
}

void Pedido::setPrato(int idprato, int qtd)
{
    pratoIdQuantidade[numeroLinha][0] = idprato;
    pratoIdQuantidade[numeroLinha][1] = qtd;
    numeroLinha++;
}

int Pedido::getNumeroLinha()
{
    return numeroLinha;
}

string Pedido::getNifCliente()
{
    return nifCliente;
}

double Pedido::getTotal()
{
    return total;
}

bool Pedido::getPago()
{
    return pago;
}

int Pedido::getId()
{
    return id;
}

void Pedido::setTotal(double total)
{
    	this->total += total;
}

void Pedido::setPago(bool pago)
{
    this->pago = pago;
}


double Pedido::calculaTroco(double vPago) {
    return vPago - total;
}

