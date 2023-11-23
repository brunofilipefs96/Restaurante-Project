#include "Produto.h"

Produto::Produto()
{
    id += 1;    
    nome = "n/a";
    quantidade = 0;
    validade = "n/a";
    precoCusto = 0.0;
    totalVendas = 0;

}

Produto::Produto(string nome, int quantidade, string validade, double precoCusto, int totalVendas)
{
    this->id += 1;  
    this->nome = nome;
    this->quantidade = quantidade;
    this->validade = validade;
    this->precoCusto = precoCusto;
    this->totalVendas = totalVendas;
}


void Produto::setId(int id)
{
    this->id = id;
}

void Produto::setNome(string nome)
{
    this->nome = nome;
}

void Produto::setQuantidade(int quantidade)
{
    this->quantidade = quantidade;
}

void Produto::setValidade(int validade)
{
    this->validade = validade;
}

void Produto::setPreco(int precoCusto)
{
    this->precoCusto = precoCusto;
}


void Produto::updateId(int id)
{
    this->id = id;
}

int Produto::getId()
{
    return id;
}

string Produto::getNome()
{
    return nome;
}

int Produto::getQuantidade()
{
    return quantidade;
}

string Produto::getValidade()
{
    return validade;
}

int Produto::getTotalVendas() {
    return totalVendas;
}

double Produto::getPreco()
{
    return precoCusto;
}

double Produto::totalLucro()
{
    double totalLucro;
    
    totalLucro = (precoCusto * totalVendas) * 1.3;

    return totalLucro;
}


string Produto::toString()
{
    return "ID: " + to_string(id) + ", Nome: " + nome + ", Quantidade: " + to_string(quantidade) + ", Validade: " + validade + ", Preço Custo: " + to_string(precoCusto) + ", Total Vendas: " + to_string(totalVendas);
}
