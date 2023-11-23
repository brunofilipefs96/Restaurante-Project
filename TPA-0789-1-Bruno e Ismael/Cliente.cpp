#include "Cliente.h"

Cliente::Cliente()
{
    nome = "n/a";
    nif = "999999999";
    endereco = "n/a";
    email = "n/a";
    idCliente += 1;

}

Cliente::Cliente(string nome, string telefone, string nif, string endereco, string email)
{
    this->idCliente += 1;
    this->nome = nome;
    this->telefone = telefone;
    this->nif = nif;
    this->endereco = endereco;
    this->email = email;
}

void Cliente::setNome(string nome)
{
    this->nome = nome;
}

void Cliente::setTotalCompras(int totalCompras)
{
	this->totalCompras += totalCompras;
}

void Cliente::updateId(int id)
{
    this->idCliente = id;
}


int Cliente::getId()
{
    return idCliente;
}

string Cliente::getNome()
{
    cout << nome;
    return nome;
}

string Cliente::getTelefone()
{
    return telefone;
}

string Cliente::getNif()
{
    return nif;
}

string Cliente::getEndereco()
{
    return endereco;
}

string Cliente::getEmail()
{
    return email;
}

string Cliente::toString()
{
    return "| NIF: " + nif + ", Nome: " + nome + ", telefone: " + telefone +  ", Endereco: " + endereco + ", Email: " + email;
}

int Cliente::getTotalCompras()
{
    return totalCompras;
}

void Cliente::dadosDefault()
{
        this->nome = "n/a";
        this->nif = "999999999";
        this->endereco = "n/a";
        this->email = "n/a";
    
}

void Cliente::imprimirCliente()
{
    cout << "| NIF: " << setw(10) << left << nif << "| Nome: " << setw(12) << nome << "| Telefone: " << setw(10) << telefone << "| Email: " << setw(19) << email <<  " |" << endl;
}



