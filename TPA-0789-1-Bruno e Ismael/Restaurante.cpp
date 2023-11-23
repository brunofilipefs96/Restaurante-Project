#include "Restaurante.h"


bool Restaurante::existemProdutosVendidos()
{
	for (int i = 0; i < totalPratos; i++)
	{
		if (pratos[i].getTotalVendas() > 0) {
			return true;
		}
	}
	return false;
}

bool Restaurante::validaNifTelefone(string numero, string tipoValidacao) //Valida NIF e Telefone
{
	if (numero == "0") { //Se o utilizador quiser voltar atrás
		return false;
	}else if (numero.length() != 9) { //Testa se o numero tem 9 digitos
		cout << "O " << tipoValidacao << " está inválido, digite novamente: ";
		return false;
	}
	else {
		for (int i = 0; i < 9; i++) {  //Testa se só existem numeros na string
			if (!isdigit(numero[i])) {
				cout << "O " << tipoValidacao << " está inválido, digite novamente: ";
				return false;
			}
		}
		if (!clientesVazio()) {
			for (int i = 0; i < totalClientes; i++)
			{
				if (tipoValidacao == "nif") {
					if (numero == "999999999") {
						cout << "O " << tipoValidacao << " está inválido, digite novamente: ";
						return false;
					}
					else if (numero == clientes[i].getNif()) {
						cout << "Esse " << tipoValidacao << " já existe, digite novamente: ";
						return false;
					}
				}
				else if (tipoValidacao == "telefone") {
					if (numero == clientes[i].getTelefone()) {
						cout << "O " << tipoValidacao << " está inválido, digite novamente: ";
						return false;
					}
				}				
			}
			return true;
		}
	}
	return true;
}

bool Restaurante::validaString(string texto, string campo)  //Valida String
{
	if (texto.length() < 3) {
		cout << "O " << campo << " está inválido, digite novamente: ";
		return false;
	}
	return true;
}

void Restaurante::addProduto(string nome, int quantidade, string validade, double preco_custo, int totalVendas)
{
	if (totalPratos < 20) {
		pratos[totalPratos] = Produto(nome, quantidade, validade, preco_custo, totalVendas);
		pratos[totalPratos].updateId(contPratos);
		contPratos++;
		totalPratos++;
	}
	else {
		cout << endl << "Menu cheio!" << endl;
	}
}

void Restaurante::lerProduto()
{	
	cout << "----------------------------------------" << endl;
	cout << "|             Inserir Prato            |" << endl;
	cout << "----------------------------------------" << endl;
	Produto produto;
	string nome, validade;
	double preco_custo;
	int quantidade, totalVendas;
	if (totalPratos < 20) {

		cout << "Nome: ";
		do { 
			cin >> nome;

		} while (!validaString(nome, "nome"));

		
		quantidade = validaInt(0,"quantidade");


		cout << "Validade (dia/mês/ano): ";
		do {
			cin >> validade;

		} while (!validaString(validade, "validade"));
		
		preco_custo = validaPreco();
				
		totalVendas = validaInt(0, "totalVendas");
		
		
		
		pratos[totalPratos] = Produto(nome, quantidade, validade, preco_custo, totalVendas);
		pratos[totalPratos].updateId(contPratos);
		contPratos++;
		totalPratos++;
		cout << endl << "Prato inserido com sucesso!" << endl;
	}
	else {
		cout << endl <<  "Menu cheio!" << endl;
	}
}

void Restaurante::removeProduto()
{
	if (!menuVazio()) {
		cout << "(0) - Voltar ao menu Principal" << endl << endl;
		int opcao = validaInt(totalPratos, "pratos");
		if (opcao == 0) {
			system("cls");
			return;
		}
		for (int i = opcao - 1; i < totalPratos - 1; i++)
		{
			pratos[i] = pratos[i + 1];
		}
		totalPratos--;
		system("cls");
		cout << "Prato removido com sucesso!" << endl << endl;
	}

}

string Restaurante::getNomePrato(int id)
{
	for (int i = 0; i < totalPratos; i++)
	{
		if (id == pratos[i].getId()) {
			return pratos[i].getNome();
		}
	}
	return "-1";
}

double Restaurante::getPrecoPrato(int id)
{
	for (int i = 0; i < totalPratos; i++)
	{
		if (id == pratos[i].getId()) {
			return pratos[i].getPreco();
		}
	}
	return -1;
}

void Restaurante::setStock()
{
	if (!menuVazio()) {
		cout << "(0) - Voltar ao menu Principal" << endl << endl;
		int quantidadeInserir = 0, opcao = validaInt(totalPratos, "pratos");
		if (opcao == 0) {
			system("cls");
			return;
		}

		quantidadeInserir = validaInt(0,"quantidade");

		quantidadeInserir += pratos[opcao - 1].getQuantidade();  //Acrescenta a quantidade à já existente
		pratos[opcao - 1].setQuantidade(quantidadeInserir);
		system("cls");
		cout << endl << "Stock atualizado com sucesso!" << endl << endl;
	}
}

int Restaurante::getTotalPratos()
{
	return totalPratos;
}

int Restaurante::procuraCliente(string nif)   //Procura o index do Cliente por NIF
{
	for (int i = 0; i < totalClientes; i++)
	{
		if (clientes[i].getNif() == nif) {
			return i;
		}
	}
	return -1;
}

double Restaurante::validaPreco()
{
	double value;
	while (true) {
		cout << "Preço custo: ";
		if (cin >> value && value >= 0) {
			break;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Preço inválido!" << endl;
		}
	}
	return value;
}

int Restaurante::validaInt(int opcoes, string tipoValidacao)
{
	int value;
	while (true) {
		if (tipoValidacao == "quantidade") {
			cout << "Quantidade: ";
		}else if (tipoValidacao == "totalVendas") {
			cout << "Total vendas: ";
		}
		else if (tipoValidacao == "menu") {
			cout << "Escolha uma opção: ";
		}
		else if (tipoValidacao == "pratos") {
			cout << "Escolha o prato: ";
		}
		if (tipoValidacao == "menu" || tipoValidacao == "pratos") {

			if (cin >> value && value >= 0 && value <= opcoes) {
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (tipoValidacao == "menu") {
					cout << "Opção inválida!" << endl;
				}
				else if (tipoValidacao == "pratos") {
					cout << "Prato inválido!" << endl;
				}
			}
		}
		else
		{
			if (cin >> value && value >= 0) {
				break;
			}
			else {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (tipoValidacao == "quantidade") {
					cout << "Quantidade inválida!" << endl;
				}
				else if (tipoValidacao == "totalVendas") {
					cout << "Total vendas inválido!" << endl;
				}
			}
		}
	}
	return value;
}

	


		

bool Restaurante::menuVazio()         //Verifica se o menu está vazio
{
	if (totalPratos <= 0)
	{
		cout << endl << "Não existem pratos no menu!" << endl;
		return true;
	}
	else {
		return false;
	}

}

bool Restaurante::clientesVazio()
{
	if (totalClientes <= 0)
	{
		cout << endl << "Não existem clientes!" << endl;
		return true;
	}
	else {
		return false;
	}
}

void Restaurante::imprimirStock()
{
	if (!menuVazio()) {
		cout << "-----------------------------------------------------------------------------" << endl;
		cout << "|                          Pratos Disponíveis                               |" << endl;
		cout << "-----------------------------------------------------------------------------" << endl;
		for (int i = 0; i < totalPratos; i++) {
			cout << "| (" << i + 1 << ") - Nome: " << setw(30) << left << pratos[i].getNome() << "| Preço: " << fixed << setprecision(2) << setw(6) << pratos[i].getPreco() << "| Quantidade: " << setw(2) << pratos[i].getQuantidade() << " |" << endl;
		}
		cout << "-----------------------------------------------------------------------------" << endl;
		cout << endl;
	}
}

void Restaurante::imprimirNomes()
{
	if (!menuVazio()) {
		cout << "----------------------------------------------" << endl;
		cout << "|             Pratos Disponíveis             |" << endl;
		cout << "----------------------------------------------" << endl;
		for (int i = 0; i < totalPratos; i++)
		{
			cout << "| (" << i + 1 << ") - " << "Nome: " << setw(30) << left << pratos[i].getNome() << " |" << endl;
		}
		cout << "----------------------------------------------" << endl;
	}
}

void Restaurante::addCliente(string nome, string telefone, string nif, string endereco, string email)
{
	if (totalClientes < 999) {
		for (int i = 0; i < totalClientes; i++)    //Testa se já existe algum cliente com esse nif
		{
			if (nif == clientes[i].getNif() || !validaNifTelefone(nif,"nif")) {
				return;
			}
		}
		clientes[totalClientes] = Cliente(nome, telefone, nif, endereco, email);
		clientes[totalClientes].updateId(contClientes);
		contClientes++;
		totalClientes++;
	}
}

void Restaurante::lerCliente(string contribuinte)
{
	cout << "----------------------------------------" << endl;
	cout << "|             Inserir Cliente           |" << endl;
	cout << "----------------------------------------" << endl;
	Cliente cliente;
	string nome, endereco, email, telefone, nif;
	if (totalClientes < 999) { 
		
		if (contribuinte == "0") {
			cout << "NIF: ";
			do
			{
				cin >> nif;
			} while (!validaNifTelefone(nif, "nif"));
		}
		
		cout << "Nome: ";
		do {
			cin >> nome;
		} while (!validaString(nome, "nome"));
		
		cout << "Telefone: ";
		do
		{
			cin >> telefone;
		} while (!validaNifTelefone(telefone, "telefone"));

		
		cout << "Endereço: ";
		do {
			cin >> endereco;
			getline(cin, endereco);

		} while (!validaString(endereco, "endereço"));
		
		cout << "Email: ";
		do {
			cin >> email;

		} while (!validaString(email, "email"));

		if (contribuinte == "0") {
			clientes[totalClientes] = Cliente(nome, telefone, nif, endereco, email);
		}
		else {
			clientes[totalClientes] = Cliente(nome, telefone, contribuinte, endereco, email);
		}
		clientes[totalClientes].updateId(contClientes);
		contClientes++;
		totalClientes++;

		cout << endl << "Cliente inserido com sucesso!" << endl;
	}
	else {
		cout << endl << "Lista cheia!" << endl;
	}	
}

int Restaurante::lerNif()
{
	string nif = "999999999";
	int index;
	cout << "Insira o NIF do Cliente: ";
	do
	{
		cin >> nif;
		index = procuraCliente(nif);
	} while (index == -1 && !validaNifTelefone(nif, "NIF"));   
	return index;
}

void Restaurante::removeCliente()
{
	if (!clientesVazio()) {
		imprimirClientes();
		string nif;
		cout << "(0) - Voltar ao menu Principal" << endl << endl;
		cout << "Insira o NIF do Cliente: ";
		do
		{
			cin >> nif;
		} while (!validaNifTelefone(nif, "NIF") && nif != "0");
		if (nif == "0") {
			system("cls");
			return;
		}

		int index = procuraCliente(nif);

		if (index != -1) {  //Se o cliente existir, remover
			
			clientes[index].dadosDefault(); 
			for (int i = index; i < totalClientes - 1; i++) {
				clientes[i] = clientes[i + 1];
			}
			totalClientes--;
			system("cls");
			cout << endl << "Cliente removido com sucesso!" << endl << endl;

		}
		else {
			system("cls");
			cout << endl << "Cliente não encontrado!" << endl << endl;
		}
	}
}


void Restaurante::alterarNomeCliente()
{	
		if (!clientesVazio()) {
			imprimirClientes();
			string nif, nome;
			cout << "(0) - Voltar ao menu Principal" << endl << endl;
			cout << "Insira o NIF do Cliente: ";
			do
			{
				cin >> nif;
			} while (!validaNifTelefone(nif, "NIF") && nif != "0");
			if (nif == "0") {
				system("cls");
				return;
			}


			int index = procuraCliente(nif);
			
			if (index != -1) {
				cout << "Nome atual: " << clientes[index].getNome() << endl;
				cout << "Insira o novo nome: ";
				do {
					cin >> nome;
				} while (!validaString(nome, "nome"));
				clientes[index].setNome(nome);
				system("cls");
				cout  << endl << "Nome alterado com sucesso!" << endl << endl;

			}
			else {
				system("cls");
				cout << endl << "Cliente não encontrado!" << endl << endl;
			}
		}
	
	
	
}

void Restaurante::imprimirClientes()
{
	
	if (!clientesVazio()) {
		cout << "-----------------------------------------------------------------------------------------" << endl;
		cout << "|                                  Lista de clientes                                    |" << endl;
		cout << "-----------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < totalClientes; i++)
		{
			clientes[i].imprimirCliente();
		}
	}	
	cout << "-----------------------------------------------------------------------------------------" << endl;
}

bool Restaurante::novoCliente(string nif)
{
	for (int i = 0; i < totalClientes; i++)
	{
		if (clientes[i].getNif() == nif) {
			return false;
		}
	}
	return true;
}





void Restaurante::relatorioVendasPrato(string nomePrato)
{
	if (!menuVazio())
	{
		for (int i = 0; i < totalPratos; i++)
		{
			string nomePratoLowerCase = nomePrato;
			transform(nomePratoLowerCase.begin(), nomePratoLowerCase.end(), nomePratoLowerCase.begin(), ::tolower); // Transforma a string para minusculas

			string nomePratoNoCase = pratos[i].getNome();
			transform(nomePratoNoCase.begin(), nomePratoNoCase.end(), nomePratoNoCase.begin(), ::tolower); // Transforma a string para minusculas

			size_t isFound = nomePratoNoCase.find(nomePratoLowerCase); // Procura a string inserida pelo utilizador no nome do prato
			if (isFound != string::npos)  //Se o nome do prato não for encontrado, retorna npos
			{
				cout << endl << "Prato: " << pratos[i].getNome() << endl;
				cout << endl << "Total de vendas: " << pratos[i].getTotalVendas() << endl;
				return;
			}
		}
		cout << endl << "Prato inválido!" << endl;
	}
}


void Restaurante::relatorioVendasTotal()
{
	Produto pratoMaisVendido, pratoMenosVendido, pratoMaiorLucro;
	Cliente clienteFavorito;  //Cliente com maior quantidade de produtos

	if (!menuVazio())
	{
		if (existemProdutosVendidos()) {
			pratoMaisVendido = pratos[0];
			pratoMenosVendido = pratos[0];
			pratoMaiorLucro = pratos[0];

			for (int i = 1; i < totalPratos; i++)
			{
				if (pratoMaisVendido.getTotalVendas() < pratos[i].getTotalVendas())
				{
					pratoMaisVendido = pratos[i];
				}
				if (pratoMenosVendido.getTotalVendas() > pratos[i].getTotalVendas())
				{
					pratoMenosVendido = pratos[i];
				}
				if (pratoMaiorLucro.totalLucro() < pratos[i].totalLucro())
				{
					pratoMaiorLucro = pratos[i];
				}

			}
			cout << endl << "Prato mais vendido: " << pratoMaisVendido.getNome() << " | Quantidade: " << pratoMaisVendido.getTotalVendas() << endl;
			cout << endl << "Prato menos vendido: " << pratoMenosVendido.getNome() << " | Quantidade: " << pratoMenosVendido.getTotalVendas() << endl;
			cout << endl << "Prato com maior lucro: " << pratoMaiorLucro.getNome() << " | Total Receitas: " << fixed << setprecision(2) << pratoMaiorLucro.totalLucro()<< " eur" << endl << endl;

		}
		if (!pedidosVazios())    //Ver se os pedidos estao vazios e depois percorrer os pedidos e ver o prato mais vendido relacionado com o cliente
		{
			clienteFavorito = clientes[0];				//Cliente fav = Possui a maior quantidade de pedidos
			for (int i = 0; i < totalClientes; i++)
			{
				if (clientes[i].getTotalCompras() > clienteFavorito.getTotalCompras())
				{
					clienteFavorito = clientes[i];
				}
			}
			cout << endl << "Cliente que mais comprou: " << clienteFavorito.getNome() << " | Total: " << clienteFavorito.getTotalCompras() <<" pratos." << endl << endl;
		}
	}
}

void Restaurante::relatorioVendasCliente(string nomeCliente)
{
	if (!clientesVazio() && !pedidosVazios())
	{
		for (int i = 0; i < totalClientes; i++)
		{
			string nomeClienteLowerCase = nomeCliente;
			transform(nomeClienteLowerCase.begin(), nomeClienteLowerCase.end(), nomeClienteLowerCase.begin(), ::tolower); // Transforma a string para minusculas

			string nomeClienteNoCase = clientes[i].getNome();
			transform(nomeClienteNoCase.begin(), nomeClienteNoCase.end(), nomeClienteNoCase.begin(), ::tolower); // Transforma a string para minusculas

			size_t isFound = nomeClienteNoCase.find(nomeClienteLowerCase); // Procura a string inserida pelo utilizador no nome do prato
			if (isFound != string::npos)  //Se o nome do prato não for encontrado, retorna npos
			{
				cout << endl << "Cliente: " << clientes[i].getNome() << endl;
				cout << endl << "Total de vendas: " << clientes[i].getTotalCompras() << endl;
				return;
			}
		}
		cout << endl << "Cliente inválido!" << endl;
	}	
}
		
		


void Restaurante::criarPedido()    
{
		if (selecionarPratos()) {    //Se o pedido foi criado com sucesso, pedir dados do cliente
			char opcaoString;
			int index;
			string nif;
			cout << endl << "Deseja contribuinte no pedido? (Y/N): ";
			do {
				cin >> opcaoString;
				opcaoString = tolower(opcaoString);
				if (opcaoString == 'y' && !clientesVazio())
				{
					cout << "Insira o NIF do Cliente: ";
					do
					{
						cin >> nif;
					} while (!validaNifTelefone(nif, "NIF") && nif != "0");
					
					if (novoCliente(nif)) {   //Se o cliente não existir, criar novo cliente
						cout << endl << "Cliente não registado no sistema!" << endl;
						
						lerCliente(nif);
					}
					index = procuraCliente(nif);

					clientes[index].setTotalCompras(pedidos[totalPedidos].getNumeroLinha());  //Adiciona 1 ao total de compras do cliente
					pedidos[totalPedidos].setCliente(clientes[index].getNif());
				}
			} while (opcaoString != 'y' && opcaoString != 'n');
			system("cls");
			cout << endl << "Pedido criado com sucesso!" << endl;
			cout << endl << "Valor total: " << fixed << setprecision(2) << pedidos[totalPedidos].getTotal() << " eur" << endl;
			pedidos[totalPedidos].updateId(totalPedidos);
			totalPedidos++;
			
		}
		else {
			system("cls");
			cout << endl << "Pedido inválido!" << endl << endl;
		}	
}

bool Restaurante::selecionarPratos()    //(0) Cancelar Pedido, apenas se ainda não tiver adicionado pratos (senão é obrigado a finalizar)
{
	char opcaoString;
	if (!menuVazio())
	{
		int quantidadeInserir = 0, opcao, cont = 0;
		do {
			if (cont > 0) {
				cout << "-----------------------------------------------------" << endl;
				cout << "|                        Pedido                     |" << endl;
				cout << "-----------------------------------------------------" << endl;
				for (int i = 0; i < cont; i++) {
					cout << "| (" << i + 1 << ") - " << "Nome: " << setw(15) << left << getNomePrato(pedidos[totalPedidos].getIdPrato(i)) << " | Quantidade: " << setw(4) << pedidos[totalPedidos].getQtdPrato(i) << " |" << endl;
				}
				cout << "-----------------------------------------------------" << endl;
			}
			imprimirStock();
			if (cont <= 0) {
				cout << endl << "(0) - Voltar ao menu anterior" << endl << endl;
			}
			cout << "Escolha o prato: ";
			cin >> opcao;
			if (cont <= 0 && opcao == 0) {   //Não inseriu pratos e voltou atrás no menu
				return false;
			}
			else if (cont > 0 && opcao == 0) {   //Inseriu pratos e quer voltar atrás no menu
				system("cls");
				cout << endl << "Tem pratos inseridos, impossivel voltar ao menu anterior." << endl;
				cout << endl << "Finalize o seu pedido primeiro!" << endl;
			}
			else if (opcao <= totalPratos && opcao >= 0) {
				cout << "Quantidade a inserir: ";
				cin >> quantidadeInserir;
				if (quantidadeInserir <= 0) {
					system("cls");
					cout << endl << "Quantidade inválida!" << endl << endl;
				}
				else {
					if (quantidadeInserir > pratos[opcao - 1].getQuantidade()) {
						system("cls");
						cout << endl << "Quantidade insuficiente!" << endl << endl;
					}
					else {
						pratos[opcao - 1].setQuantidade(pratos[opcao - 1].getQuantidade() - quantidadeInserir);  //Retira a quantidade inserida ao stock
						pedidos[totalPedidos].setPrato(pratos[opcao - 1].getId(), quantidadeInserir);  //Adiciona o prato ao pedido
						pedidos[totalPedidos].setTotal(pratos[opcao - 1].getPreco() * quantidadeInserir);  //Adiciona o preco dos pratos ao total do pedido
						cont++;
						cout << endl << "Deseja finalizar o pedido? (Y/N): ";
						do {
							cin >> opcaoString;
							opcaoString = tolower(opcaoString);
							if (opcaoString == 'y') {
								return true;
								pedidos[totalPedidos].setTotal(pratos[opcao - 1].getPreco() * 1.30); //Adiciona os 30% ao Preço de Custo
								pedidos[totalPedidos].setPago(true);
							}

						} while (opcaoString != 'y' && opcaoString != 'n');
						system("cls");
					}
				}
			}
			else {
				cout << endl << "Opção inválida!" << endl;
			}
		} while (true);

	}
	return false;
}

void Restaurante::imprimirTotal()
{
	if (!pedidosVazios()&& !clientesVazio()) 
	{
		imprimirClientes();
		int index = lerNif();
		double total = 0;
		for (int i = totalPedidos; i >= 0; i--)
		{ 
			if (clientes[index].getNif()== pedidos[i].getNifCliente())
			{
				cout <<endl <<  "Valor total: " << fixed << setprecision(2) << pedidos[i].getTotal() << " eur" << endl;
				return;
			}
		}
		cout << endl << "Cliente não encontrado!" << endl;
	}
		
}

void Restaurante::pagarPedido()
{
	if (pedidosNaoPagos()) 
	{
		int opcao;
		double vPago, troco;
		imprimirPedidos();
		cout << "(0) - Voltar ao menu anterior" << endl << endl;
		do
		{
			cout << "Escolha o pedido: ";
			cin >> opcao;
			if (opcao < 0 || opcao > totalPedidos) {
				cout << "Opção inválida! Insira novamente: " << endl;
			}
		} while (opcao > totalPedidos || opcao < 0 || pedidos[opcao-1].getPago());

		if (opcao == 0) {
			system("cls");
			return;
		}

		srand((unsigned)time(NULL));
		int random = 1 + (rand() % 100);

		if (random == 7) {
			cout << endl << "Venceu o prémio! Este pedido fica por nossa conta! " << endl;
			pedidos[opcao - 1].setPago(true);
			pedidos[opcao - 1].setTotal(0);
			imprimirRecibo(pedidos[opcao - 1], 0);
			return;
		}

		cout << endl << "Custo total: " << fixed << setprecision(2) << pedidos[opcao-1].getTotal() << " eur" << endl;

		for (int i = 0; i < totalPedidos; i++)
		{
			do
			{
				cout << "Pagamento: ";
				cin >> vPago;
				if (vPago < pedidos[i].getTotal()) {
					cout << "Valor insuficiente! Insira novamente: " << endl;
				}

			} while (vPago < pedidos[opcao-1].getTotal());

			pedidos[opcao - 1].setPago(true);
			pedidos[opcao-1].setTotal(0);
			troco = pedidos[opcao - 1].calculaTroco(vPago);
			
			cout << endl << "Pedido pago com sucesso!" << endl;
			imprimirRecibo(pedidos[opcao - 1], troco);

			return;
		}
		cout << endl << "Cliente não encontrado!" << endl;
	}
}

void Restaurante::imprimirPedidos()
{
	if (pedidosNaoPagos()) {
		cout << "-------------------------------------------" << endl;
		cout << "|           Pedidos por liquidar          |" << endl;
		cout << "-------------------------------------------" << endl;
		for (int i = 0; i < totalPedidos; i++) {
			if (!pedidos[i].getPago()) {
				cout << "| (" << i +1 << ") - NIF: " << setw(10) << left << pedidos[i].getNifCliente() << "| Total: " << fixed << setprecision(2) << pedidos[i].getTotal() << " eur |" << endl;
			}
		}
		cout << "-------------------------------------------" << endl;
		cout << endl;
	}
}

void Restaurante::imprimirRecibo(Pedido pedido, double troco)
{
	system("cls");
	cout << "-------------------------------------------------------------" << endl;
	cout << "|                             Recibo                        |" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "| Nº Recibo: " << setw(3) << left << pedido.getId() << "| Data: " << pedido.dataHora  << endl;
	cout << "| ID Cliente: " << setw(30) << left << pedido.getNifCliente() << endl;
	for (int i = 0; i < pedido.getNumeroLinha(); i++)
	{
		cout << "| " << i << " | " << getNomePrato(pedido.getIdPrato(i)) << " | Qtd: " << pedido.getQtdPrato(i) << " | Preço Unitário: " << fixed << setprecision(6) << getPrecoPrato(pedido.getIdPrato(i)) <<  endl;
	}
	cout << "| Total: " << setw(15) << left << pedido.getTotal() << endl;
	cout << "| Valor Pago: " << setw(15) << pedido.getTotal() + troco << endl;
	cout << "| Troco: " << setw(15) << left << troco << endl;
	cout << "-------------------------------------------------------------" << endl;
}

bool Restaurante::pedidosNaoPagos()   //Verifica se existem pedidos que não estão pagos
{
	if (!pedidosVazios()) {
		for (int i = 0; i < totalPedidos; i++)
		{
			if (!pedidos[i].getPago()) {
				return true;
			}
		}
		cout << endl << "Não existem pedidos por liquidar!" << endl;
		return false;
	}
	return false;
}



bool Restaurante::pedidosVazios()
{
	if (totalPedidos <= 0)
	{
		cout << "O Restaurante não possui nenhum pedido!" << endl << endl;
		return true;
	}
	else {
		return false;
	}
}
			

				