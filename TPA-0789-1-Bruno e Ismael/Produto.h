#pragma once
#include <iostream>
#include <string>;
using namespace std;

class Produto
{
private:
	int id; 
	string nome;
	int quantidade;
	string validade;
	double precoCusto;
	int totalVendas;

public:

	Produto();
	Produto(string nome, int quantidade, string validade, double preco_custo, int totalVendas);

	void setId(int id_prato);
	void setNome(string nome);
	void setQuantidade(int quantidade);
	void setValidade(int validade);
	void setPreco(int preco_custo);

	void updateId(int id);
	int getId();
	string getNome();
	int getQuantidade();
	string getValidade();
	int getTotalVendas();
	double getPreco();

	double totalLucro();

	string toString();

};


