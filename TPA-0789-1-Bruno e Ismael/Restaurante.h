#pragma once
#include "Produto.h"
#include "Cliente.h"
#include "Pedido.h"
#include<iostream>
#include <string>;
#include <ctime>
#include <locale.h>
#include <algorithm>
#include <iomanip>
using namespace std;


class Restaurante
{
private:	
	int totalPratos = 0; 
	int contPratos = 0; // Contador de pratos(id)
	int totalClientes = 0; 
	int contClientes = 0; // Contador de clientes(id)
	int totalPedidos = 0;
	Produto pratos[20];
	Cliente clientes[999];
	Pedido pedidos[100];
	bool existemProdutosVendidos();   //Verifica se existem produtos vendidos

public:
	

	//Adicionar e Remover Pratos
	void addProduto(string nome, int quantidade, string validade, double preco_custo, int totalVendas);
	void lerProduto();  //Adicionar prato
	void removeProduto();  //Remover prato
	string getNomePrato(int id);  //Procura prato
	double getPrecoPrato(int id);  //Procura prato

	//Sets e Gets
	void setStock();  //Adicionar stock
	int getTotalPratos();  //Total de Pratos 
	int procuraCliente(string nif);  //Id do Cliente

	//Validações
	double validaPreco();  //Valida Double
	int validaInt(int opcoes, string tipoValidacao);  //Valida Inteiro
	bool menuVazio();  //Verifica se o menu está vazio
	bool clientesVazio(); //Verifica se existem clientes
	bool pedidosVazios(); //Verifica se existem pedidos
	bool validaNifTelefone(string numero, string tipoValidacao);  //Valida NIF
	bool validaString(string texto, string campo);  //Valida String
	

	//Relatórios
	void relatorioVendasPrato(string nomePrato);  //Mostrar total de vendas de um Prato
	void relatorioVendasTotal();  //Mostrar relatório de vendas
	void relatorioVendasCliente(string nomeCliente);  //Mostrar relatório de vendas por cliente

	//Pedidos
	void criarPedido();        //Criar um novo pedido
	bool selecionarPratos();   //Selecionar pratos para o pedido
	void imprimirTotal();      //imprimir total do pedido
	void pagarPedido();        //pagar pedido
	void imprimirPedidos();	   //imprimir pedidos
	void imprimirRecibo(Pedido pedido, double troco);     //imprimir recibo
	bool pedidosNaoPagos();    //Verificar se existem pedidos não pagos
	

	//Imprimir Menu
	void imprimirStock(); //Mostrar stock
	void imprimirNomes(); //Mostrar nomes dos Pratos

	//Clientes
	void addCliente(string nome, string telefone, string nif, string endereco, string email);  //Adicionar cliente
	void lerCliente(string contribuinte);  //Adicionar cliente
	int  lerNif();  // Procura Cliente por NIF e retorna a posicao no array
	void removeCliente();  //Remover cliente
	void alterarNomeCliente();  //alterar nome do cliente
	void imprimirClientes();  //Mostrar clientes
	bool novoCliente(string nif);  //Pesquisa NIF para criar ficha cliente (caso não exista) após o pedido

};

