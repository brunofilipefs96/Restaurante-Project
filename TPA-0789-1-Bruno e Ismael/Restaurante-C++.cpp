#include <iostream>
#include <iomanip>
#include <limits>
#include <locale.h>
#include "Cliente.h"
#include "Produto.h"
#include "Restaurante.h"
using namespace std;

Restaurante restaurante;
void menuPrincipal();

void menuPedidosCliente() {
	cout << "---------------------------------------" << endl;
	cout << "|         Pedidos Clientes            |" << endl;
	cout << "---------------------------------------" << endl;
	cout << "| (1) - Criar pedido                  |" << endl;
	cout << "| (2) - Mostrar pedido(s) não pago(s) |" << endl;
	cout << "| (3) - Pagar pedido                  |" << endl;
	cout << "| (0) - Voltar ao menu principal      |" << endl;
	cout << "---------------------------------------" << endl;
	int opcao = restaurante.validaInt(3, "menu");
	switch (opcao)
	{
	case 1:  //selecionar pratos e quantidade
		system("cls");
		restaurante.criarPedido();
		menuPrincipal();
		break;
	case 2:  //imprimir pedido na ecrã
		system("cls");
		restaurante.imprimirPedidos();
		menuPrincipal();
		break;
	case 3:  //imprimir pedido na ecrã
		system("cls");
		restaurante.pagarPedido();
		menuPrincipal();
		break;
	case 0:  //voltar menu principal
		system("cls");
		menuPrincipal();
		break;
	default:
		cout << "Opção inválida!" << endl;
		cout << "Escolha outra opção: ";
		break;
	}

}

void menuGerirStock() {
	cout << "----------------------------------------------" << endl;
	cout << "|                Gerir Stock                 |" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "| (1) - Adicionar novos pratos ao menu       |" << endl;
	cout << "| (2) - Adicionar stock a um prato existente |" << endl;
	cout << "| (3) - Remover um prato do menu             |" << endl;
	cout << "| (0) - Voltar ao menu principal             |" << endl;
	cout << "----------------------------------------------" << endl;
	int opcao = restaurante.validaInt(3, "menu");
	switch (opcao)
	{
	case 1:
		system("cls");
		restaurante.lerProduto(); //Adiciona um novo prato ao menu
		menuPrincipal();
	case 2:
		system("cls");
		restaurante.imprimirStock();  //Mostra o stock atual para cada prato
		restaurante.setStock();  //Adiciona stock a um prato existente
		menuPrincipal();
	case 3:
		system("cls");
		restaurante.imprimirNomes();  //Mostra os nomes dos pratos existentes
		restaurante.removeProduto();  //Remove um prato do menu
		menuPrincipal();
	case 0:  //voltar menu principal
		system("cls");
		menuPrincipal();
		break;
	default:
		cout << "Opção inválida!" << endl;
		cout << "Escolha outra opção: ";
		break;
	}
}

void menuGerarRelatorios() {
	string nome;
	cout << "-----------------------------------------" << endl;
	cout << "|            Gerar Relatórios           |" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "| (1) - Relatório de stock              |" << endl;
	cout << "| (2) - Relatório de vendas por prato   |" << endl;
	cout << "| (3) - Relatório de vendas total       |" << endl;
	cout << "| (4) - Relatório de vendas por Cliente |" << endl;
	cout << "| (0) - Voltar ao menu principal        |" << endl;
	cout << "-----------------------------------------" << endl;
	int opcao = restaurante.validaInt(4, "menu");
	switch (opcao)
	{
	case 1:  //relatório de stock
		system("cls");
		restaurante.imprimirStock();
		menuPrincipal();
	case 2:  //relatório de vendas por prato
		system("cls");
		if (!restaurante.menuVazio()) {
			cout << "---------------------------------------" << endl;
			cout << "|    Relatório de vendas por prato    |" << endl;
			cout << "---------------------------------------" << endl;
			cout << "Insira o nome do prato: ";
			do {
				cin >> nome;


			} while (!restaurante.validaString(nome, "nome"));
			restaurante.relatorioVendasPrato(nome);
		}
		menuPrincipal();


	case 3:  //relatório de vendas total
		system("cls");
		cout << "---------------------------------------" << endl;
		cout << "|      Relatório de vendas total      |" << endl;
		cout << "---------------------------------------" << endl;
		restaurante.relatorioVendasTotal();
		menuPrincipal();

	case 4: //relatório de vendas por cliente
		system("cls");
		if (!restaurante.clientesVazio() && !restaurante.pedidosVazios()) {
			cout << "---------------------------------------" << endl;
			cout << "|   Relatório de vendas por cliente   |" << endl;
			cout << "---------------------------------------" << endl;
			restaurante.imprimirClientes();
			cout << "(0) - Voltar ao menu Principal" << endl << endl;
			cout << "Insira o nome do cliente: ";
			do {
				cin >> nome;
				if (nome == "0") {
					system("cls");
					menuPrincipal();
				}
			} while (!restaurante.validaString(nome, "nome"));
			restaurante.relatorioVendasCliente(nome);
		}
		menuPrincipal();

	case 0:  //voltar menu principal
		system("cls");
		menuPrincipal();
		break;
	default:
		cout << "Opção inválida!" << endl;
		cout << "Escolha outra opção: ";
		break;
	}
}

void menuGerirClientes() {
	cout << "---------------------------------------" << endl;
	cout << "|           Gerir Clientes            |" << endl;
	cout << "---------------------------------------" << endl;
	cout << "| (1) - Registar novo cliente         |" << endl;
	cout << "| (2) - Remover cliente               |" << endl;
	cout << "| (3) - Alterar o nome do cliente     |" << endl;
	cout << "| (0) - Voltar ao menu principa       |" << endl;
	cout << "---------------------------------------" << endl;
	int opcao = restaurante.validaInt(3, "menu");
	switch (opcao)
	{
	case 1:  //registar novo cliente
		system("cls");
		restaurante.lerCliente("0");
		menuPrincipal();
	case 2:  //remover cliente
		system("cls");
		restaurante.removeCliente();
		menuPrincipal();
	case 3:  //alterar o nome do cliente
		system("cls");
		restaurante.alterarNomeCliente();
		menuPrincipal();
	case 0:  //voltar menu principal
		system("cls");
		menuPrincipal();
		break;
	default:
		cout << "Opção inválida!" << endl;
		cout << "Escolha outra opção: ";
		break;
	}
}



void menuPrincipal() {
	cout << "---------------------------------------" << endl;
	cout << "|          Menu Principal             |" << endl;
	cout << "---------------------------------------" << endl;
	cout << "| (1) - Pedidos                       |" << endl;
	cout << "| (2) - Stock                         |" << endl;
	cout << "| (3) - Relatorios                    |" << endl;
	cout << "| (4) - Clientes                      |" << endl;
	cout << "| (0) - Sair                          |" << endl;
	cout << "---------------------------------------" << endl;

	int opcao = restaurante.validaInt(4, "menu");
	switch (opcao)
	{
	case 1:  //registar pedidos de clientes
		system("cls");
		menuPedidosCliente();
		break;
	case 2:  //gerir stock
		system("cls");
		menuGerirStock();
		break;
	case 3:  //gerar relatorios
		system("cls");
		menuGerarRelatorios();
		break;
	case 4:  //gerir clientes
		system("cls");
		menuGerirClientes();
		break;
	case 0:  //sair
		exit(0);
	default:
		cout << "Opção inválida!" << endl;
		cout << "Escolha outra opção: ";
		break;
	}
}



int main()
{

	restaurante.addCliente("Bruno", "919582174", "290129321", "Rua do Bruno", "bruno@email.pt");
	restaurante.addCliente("Ismael", "910284517", "259210392", "Rua do Ismael", "ismael@email.pt");
	restaurante.addCliente("João", "917582196", "221456214", "Rua do João", "joao@email.pt");
	restaurante.addCliente("Maria", "931850293", "200289134", "Rua do Maria", "maria@email.pt");
	restaurante.addCliente("Ana", "931104921", "211246783", "Rua do Ana", "ana@email.pt");
	restaurante.addCliente("Rita", "939982717", "387219402", "Rua do Rita", "rita@email.pt");
	restaurante.addCliente("Pedro", "919988721", "298921045", "Rua do Pedro", "pedro@email.pt");

	restaurante.addProduto("Bacalhau à Brás", 10, "20/11/2023", 19.90, 30);
	restaurante.addProduto("Francesinha c/ ovo", 7, "21/11/2023", 12.90, 3);
	restaurante.addProduto("Rojões c/ arroz e batata", 5, "23/11/2023", 10.25, 15);
	restaurante.addProduto("Vitela assada c/ feijão", 23, "27/11/2023", 19.90, 13);
	restaurante.addProduto("Cachorro especial", 2, "18/11/2023", 8.50, 7);
	restaurante.addProduto("Bitoque c/ ovo", 3, "19/11/2023", 9.90, 10);


	setlocale(LC_ALL, "portuguese");    //Para usar caracteres especiais
	menuPrincipal();



}

