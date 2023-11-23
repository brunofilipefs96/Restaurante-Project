#pragma once
#include <string>;
#include <iostream>
#include <iomanip>
using namespace std;

class Cliente
{
private:
    int idCliente;   //id automático
    string nome;
    string endereco;
    string email;
    string telefone;
    string nif;
    int totalCompras = 0;
    

public:
    Cliente();
    Cliente(string nome, string telefone, string nif, string endereco, string email);

    void setNome(string nome);
    void setTotalCompras(int totalCompras);

    void updateId(int id);
    int getId();
    string getNome();
    string getTelefone();
    string getNif();
    string getEndereco();
    string getEmail();
    string toString();
    int getTotalCompras();

    void dadosDefault();
    void imprimirCliente();
};