#include <iostream>
#include <string>
#include <stdlib.h> 
#include <time.h>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include "maquina.h"
#include"funcionario.h"
#include "dinheiro.h"

using namespace std;


void limparSlot() {
	char ID;
	bool Ok = false;
	cout << "Escreva a letra do Slot que deseja limpar:";
	cin >> ID;
	ID = toupper(ID);

	for (int i = 1; i <= TotalSlots; i++) {
		if (VetSlots[i].ID == ID) {
			VetSlots[i].nome = "Vazio";
			VetSlots[i].preco = 0;
			VetSlots[i].quantidade = 0;
			cout << "Slot "<< ID <<" limpo com sucesso." << endl;
			Ok = true;
			break;
		}
		
		}	

	if (Ok == false)
	cout << "O slot que escolheu não existe.";

	cout << endl;
	
	MostrarMaquina();
	menuFuncionario();

}

void limparMaquina() {

	char opcao;
	cout << endl;

	cout << "Esta opção irá esvaziar todos os slots. Tem a certeza que quer continuar?" << endl;
	cout << "1. (S)im" << endl;
	cout << "2. (N)ão" << endl;

	cin >> opcao;
	cout << endl;
	switch (opcao) {
	case '1':
	case 's':
	case 'S':

		for (int i = 1; i <= TotalSlots; i++) {
			VetSlots[i].nome = "Vazio";
			VetSlots[i].preco = 0;
			VetSlots[i].quantidade = 0;
		}
		cout << "Máquina Limpa com suceso" << endl;
		cout << endl;

		MostrarMaquina();
		menuFuncionario();
		break;

	case '2':
	case 'n':
	case 'N':

		menuFuncionario();
		break;
		


	default:
		cout << endl;
		menuFuncionario();
	}
}
	


void alterarCapacidade(char ID, int i) {
	int capacidade;
	int quantidade;
	cout << "A sua capacidade atual é de : " << VetSlots[i].capacidade << endl;
	cout << "Escreva a capacidade que pretende para o seu Slot:" << endl;
	cin >> capacidade;
	cout << "Escreva quantos produtos pretende adicionar ao Slot." << endl;
	cin >> quantidade;

	

	
	if (capacidade >= VetSlots[i].quantidade+ quantidade) {    // caso o utilizador introduza um valor superior à capacidade que acabou de alterar
		VetSlots[i].quantidade = VetSlots[i].quantidade + quantidade;
		VetSlots[i].capacidade = capacidade;
}
	else
		do{
	{
		cout << "Existem " << VetSlots[i].quantidade << " produtos no slot " << VetSlots[i].ID << "  e a sua capacidade é: " << VetSlots[i].capacidade << endl;
		cout << "A capacidade do slot é insuficiente. Introduza novamente quantos produtos pretende adicionar ao Slot: " << endl;
		cin >> quantidade;
	}
	} while (VetSlots[i].quantidade + quantidade >= capacidade);

	
	MostrarMaquina();
	cout << endl;
	cout << "SUCESSO: Alterou a capcidade do Slot " << VetSlots[i].ID  << " para " << VetSlots[i].capacidade << " e a sua quantidade para " << VetSlots[i].quantidade <<  endl;
}

void adicionarResto( int numero, int e) {
	char SlotsVazios[26];
	int TotalVazios = 0;
	char ID;
	
	int resto =abs( (VetSlots[e].capacidade - VetSlots[e].quantidade) - numero);
	
	
		for (int i = 0; i <= TotalSlots; i++) {  // Adiciona ao SlotsVazios as letras dos Slots que podem ser usados
			if (VetSlots[i].nome == "Vazio" and VetSlots[i].capacidade >= resto) {
				SlotsVazios[TotalVazios] = VetSlots[i].ID;
				TotalVazios++;
			}
				 
		}
		

	if (TotalVazios > 0){
		cout << "Os slots seguintes estão vazios e têm capacidade para armazenar o resto dos seus produtos: ";
		for (int i = 0; i <= TotalVazios-1; i++)
			cout << SlotsVazios[i] << "  " ;
		
		bool Ok;
		do {
			cout << endl;
			cout << "Escolha o slot onde pretende adicionar o resto: ";
			cin >> ID;
			ID = toupper(ID);
			cout << endl;

			

			
			for (int i = 0; i <= TotalVazios - 1; i++) {
				if (SlotsVazios[i] == ID) {
					Ok = true;
					break;
				}
				else
				{
					
					Ok = false;
				}
			}

			if (Ok == true) {
				for (int i = 0; i <= TotalSlots; i++) {
					if (VetSlots[i].ID == ID) {
						VetSlots[i].quantidade = resto;
						VetSlots[i].nome = VetSlots[e].nome;
						VetSlots[i].preco = VetSlots[e].preco;
						VetSlots[e].quantidade = VetSlots[e].capacidade; // Como a quantidade pretendida é superior à capacidade, a capacidade do slot escolhido inicialmente é igualada ao máximo da capacidade
						MostrarMaquina();
						cout << "  Adicionou " << VetSlots[e].nome << " no Slot " << VetSlots[e].ID << " e adicionou a restante quantidade ao Slot " << VetSlots[i].ID << endl << endl;
						menuFuncionario();
					}
				}
			}
			else
			{
				cout << "Escolheu o Slot errado." << endl;

			}


		} while (Ok == false);

	
	}
	else
	{
		cout << "Não existem slots vazios com a capacidade para armazenar o resto dos produtos" << endl;
		
		MostrarMaquina();
		menuFuncionario();
	}

	
}




void adicionarProdutoExistente() { // Repor Stock
	char ID;
	int numero;
	string produto;
	bool Ok = false;
	

	
	
	cout << "Escreva a letra do Slot, onde pretende adicionar o produto:" << endl;
	cin >> ID;
	ID = toupper(ID);

	do{
	for (int i = 1; i <= TotalSlots; i++) {
		if (VetSlots[i].ID == ID) {
			produto = VetSlots[i].nome;
			Ok = true;
			if (VetSlots[i].nome == "Vazio"){
				cout << "O slot escolhido não tem nenhum produto. Escolha outro slot: ";
				cin >> ID;
				ID = toupper(ID);
		}
	}
	}
	} while (produto == "Vazio");
	
	
	cout << "Escreva a quantidade que deseja adicionar:" << endl;
	cin >> numero;
	

	for (int i = 1; i <= TotalSlots; i++) {
		if (VetSlots[i].ID == ID) {
		
			if (VetSlots[i].quantidade + numero <= VetSlots[i].capacidade) {
				VetSlots[i].quantidade = VetSlots[i].quantidade + numero;
				MostrarMaquina();
				cout << "SUCESSO: Adicionou " << numero << " " << VetSlots[i].nome << " ao Slot " << VetSlots[i].ID << endl;
				
			}
			else {
				cout << "CAPACIDADE INSUFICIENTE Escolha uma das opções seguintes: " << endl;
				cout << endl;
				char opcao;
				cout << "1. Alterar Capacidade do Slot " << VetSlots[i].ID << endl;
				cout << "2. Adicionar o resto dos produtos a um Slot vazio. " << endl;
				cout << "3. Apenas adicionar ao slot a quantidade permitida." << endl;
				cin >> opcao;
				cout << endl;
				switch (opcao) {
				case '1':
					cout << "Escolheu a opção alterar a capacidade do Slot " << VetSlots[i].ID << endl;

					alterarCapacidade(VetSlots[i].ID, i);
					break;
				case '2':
					cout << "Escolheu a opção adicionar o resto dos produtos a um Slot vazio." << endl<<endl;
					
					adicionarResto( numero, i);
					
					break;
				case '3':
					cout << "Escolheu a opção adicionar ao slot a quantidade permitida." << endl << endl;
					
					cout << "Foi adicionado " << (VetSlots[i].capacidade - VetSlots[i].quantidade) << " " << VetSlots[i].nome << " ao slot " << VetSlots[i].ID << endl << endl;
					VetSlots[i].quantidade = VetSlots[i].capacidade;
					break;
				}
			}
		}
	
	}
	
	if (Ok == false) cout << "Escolheu um slot que não existe. Tente novamente." << endl;
}




void adicionarNovoProduto() {
	char SlotsVazios[26] = { '\0' }; //para eliminar junk carateres (<< le o array até encontrar o primeiro NULL)
	int TotalVazios = 0;
	char ID;
	int num;
	string nome;
	float preço;

	for (int i = 0; i <= TotalSlots; i++) {  // Adiciona ao SlotsVazios as letras dos Slots que podem ser usados
		if (VetSlots[i].nome == "Vazio") {
			SlotsVazios[TotalVazios] = VetSlots[i].ID;
			TotalVazios++;
		}
	}

	if (TotalVazios > 0) {  // Mostra os slots vazios
		cout << "Os slots seguintes estão vazios: ";
		for (int i = 0; i <= TotalVazios; i++) {
			cout << SlotsVazios[i] << "  ";
		}

		 
		int e;
		bool OkProduto;
		do {
		cout << endl;
		cout << "Escolha o slot onde pretende adicionar o seu produto: ";
		cin >> ID;
		ID = toupper(ID);
		for (int i = 0; i <= TotalSlots; i++) {
			if (VetSlots[i].ID == ID) {
				e = i;
				break;
			}

		}

			if (VetSlots[e].nome != "Vazio") {
				cout << "O Slot que escolheu não está vazio ou não existe. Escolha outro slot." << endl;
				OkProduto = false;
			}
			else
			{
				OkProduto = true;
				
			}
			
		} while (OkProduto == false);
	

		cout << "Escreva o nome do produto que pretende adicionar: " << endl;
		cin >> nome;


		bool OkPreço;
		do{
		cout << "Escreva o preço do produto que pretende adicionar: " << endl;
		cin >> preço;
		
		int intpreço = preço * 100;
		
		if (intpreço % 5 != 0) {
			OkPreço = false;
			cout << "O preço que introduziu é inválido. Introduza um preço multiplo de 5." << endl;
		}
		else OkPreço =  true;
		} while (OkPreço == false);


		cout << endl;
		cout << "Escreva a quantidade que pretende adicionar: " << endl;
		cin >> num;

		
			for (int i = 0; i <= TotalSlots; i++) {
				if (VetSlots[i].ID == ID) {
					if (VetSlots[i].quantidade + num <= VetSlots[i].capacidade) {
						VetSlots[i].quantidade = num;
						VetSlots[i].nome = nome;
						VetSlots[i].preco = preço;
						MostrarMaquina();
						cout << " Adicionou " << VetSlots[i].nome << " no Slot " << VetSlots[i].ID << endl;
						menuFuncionario();
					}
					else {
						cout << "CAPACIDADE INSUFICIENTE Escolha uma das opções seguintes: " << endl;
						cout << endl;
						char opcao;
						cout << "1. Alterar Capacidade do Slot " << VetSlots[i].ID << endl;
						cout << "2. Adicionar o resto dos produtos a um Slot vazio. " << endl;
						cout << "3. Apenas adicionar ao slot a quantidade permitida." << endl;
						cin >> opcao;
						cout << endl;
						switch (opcao) {
						case '1':
							cout << "Escolheu a opção alterar a capacidade do Slot " << VetSlots[i].ID << endl;
							VetSlots[i].nome = nome;
							VetSlots[i].preco = preço;
							alterarCapacidade(VetSlots[i].ID, i);
							cout << "Adicionou o novo produto " << nome << " ao slot " << VetSlots[i].ID << endl;
							break;
						case '2':
							cout << "Escolheu a opção adicionar o resto dos produtos a um Slot vazio." << endl;
							adicionarResto(num, i);
							
							VetSlots[i].nome = nome;
							VetSlots[i].preco = preço;
							
						
							break;
						case '3':
							
							VetSlots[i].nome = nome;
							VetSlots[i].preco = preço;
							VetSlots[i].quantidade = VetSlots[i].capacidade;
							MostrarMaquina();
							cout << "Escolheu a opção adicionar ao slot a quantidade permitida." << endl;
							cout << "Adicionou o novo produto " << nome << " ao slot " << VetSlots[i].ID << " e a quantidade " << VetSlots[i].quantidade<<endl;
							break;
						}

					}
				}
			}
		
	}
	else
	{
		cout << "Não existem slots vazios para armazenar o produto." << endl;
		menuFuncionario();
	}
}





void adicionarSlots() {
	int num;
	int capacidade;
	cout << "Escreva quantas Slots deseja adicionar." << endl;
	cin >> num;
	char letras[] = { ' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	int contador = 1;

	slot* novoSlot = new slot;
	if (TotalSlots + num <= 26) {
		for (int i = TotalSlots + 1; i <= TotalSlots + num; i++) {
			cout << "Escreva a capacidade que pretende para o seu Slot " << contador << ":" << endl;
			cin >> capacidade;

			novoSlot->ID = letras[i];
			novoSlot->nome = "Vazio";
			novoSlot->preco = 0;
			novoSlot->capacidade = capacidade;
			novoSlot->quantidade = 0;
			VetSlots[i] = *novoSlot;
			contador++;
		}
		TotalSlots = TotalSlots + num;
		MostrarMaquina();
		
		cout << "Adicionou " << num << " novo(s) " << "slot(s) à máquina." << endl;
		
		menuFuncionario();
	}
	else {
		cout << "Capacidade máxima da máquina excedida!" << endl;
		menuFuncionario();
		cout << endl;
	}
}

void adicionarProduto() {
	char opcao;
	cout << "1. Adicionar um produto existente à máquina. (Repor Stock)" << endl;
	cout << "2. Adicionar um produto novo." << endl;
	cin >> opcao;
	switch (opcao) {
	case '1':
		cout << endl;
		cout << "Escolheu a opção adiconar um produto existente." << endl;
		adicionarProdutoExistente();
		break;
	case '2':
		cout << endl;
		cout << "Escolheu a opção adicionar um produto novo" << endl;
		adicionarNovoProduto();
		break;
	}
	menuFuncionario();
}

void alterarPreço() {
		string produto;

		int e;
		cin.ignore();

		bool OkProduto;
		do {

			cout << "Introduza o nome do produto que deseja alterar o preço:" << endl; 

			getline(cin, produto);
			for (int i = 1; i <= TotalSlots; i++)
			{
				if (VetSlots[i].nome == produto) {
					OkProduto = true;
					e = i;
					break;
				}
				else
				{
					OkProduto = false;
				}
			}
			if (OkProduto == false) {
				cout << endl;
				cout << "O produto não existe." << endl;

			}
		} while (OkProduto == false);



		float novo_preço;
		bool OkPreco;
		do {

			cout << "Introduza o novo preço:" << endl;
			cin >> novo_preço;
			int cent = novo_preço * 100;  //passar float para int
			if (cent % 5 == 0) {
				OkPreco = true;
				break;
			}

			else {
				OkPreco = false;
			}
			if (OkPreco == false) {
				cout << endl;
				cout << "Preço inválido! Introduza um novo valor multiplo de 5." << endl;
			}
		} while (OkPreco == false);

		for (int i = 1; i <= TotalSlots; i++)
		{
			if (VetSlots[i].nome == produto) {
				VetSlots[i].preco = novo_preço;
			}
		}

		MostrarMaquina();
		cout << "Alterou o preço do produto " << VetSlots[e].nome << " para " << VetSlots[e].preco << endl;
		menuFuncionario();
}



void carregarMoedas() {
	cout << "Estado atual da Caixa" << endl << endl;
	mostraCaixa();
	cout << endl;
	int moedas_2;
	int moedas_1;
	int moedas_50;
	int moedas_20;
	int moedas_10;
	int moedas_5;

	cout << "Introduza a quantidade de moedas de 2 euros:";
	cin >> moedas_2;
	cout << "Introduza a quantidade de moedas de 1 euro:";
	cin >> moedas_1;
	cout << "Introduza a quantidade de moedas de 50 cêntimos:";
	cin >> moedas_50;
	cout << "Introduza a quantidade de moedas de 20 cêntimos:";
	cin >> moedas_20;
	cout << "Introduza a quantidade de moedas de 10 cêntimos:";
	cin >> moedas_10;
	cout << "Introduza a quantidade de moedas de 5 cêntimos:";
	cin >> moedas_5;
	cout << endl;

	VetDinheiro[5].quantidade = VetDinheiro[5].quantidade + moedas_5;
	VetDinheiro[4].quantidade = VetDinheiro[4].quantidade + moedas_10;
	VetDinheiro[3].quantidade = VetDinheiro[3].quantidade + moedas_20;
	VetDinheiro[2].quantidade = VetDinheiro[2].quantidade + moedas_50;
	VetDinheiro[1].quantidade = VetDinheiro[1].quantidade + moedas_1;
	VetDinheiro[0].quantidade = VetDinheiro[0].quantidade + moedas_2;

	cout << "Adicionou à caixa " << moedas_2 << " moedas de 2 euros, " << moedas_1 << " moedas de 1 euro, " << moedas_50 << " moedas de 50 cêntimos, " << moedas_20 <<
		" moedas de 20 cêntimos, " << moedas_10 << " moedas de 10 cêntimos e " << moedas_5 << " moedas de 5 cêntimos." << endl <<endl;
	mostraCaixa();
	menuFuncionario();
}

void ordemPreco() {
	float precos[26];
	string nomes[26];
	for (int i = 1; i <= TotalSlots; i++) {
		precos[i] = VetSlots[i].preco;
		nomes[i] = VetSlots[i].nome;
	}


	bool swapped = true;
	for (int i = 0; i < TotalSlots && swapped; i++) {
		swapped = false;
		for (int j = TotalSlots; j > i; j--) {
			if (precos[j] < precos[j - 1]) {
				swap(precos[j], precos[j - 1]);
				swap(nomes[j], nomes[j - 1]);
				swapped = true;
			}
		}
	}



	cout << "LISTA DOS PRODUTOS ORDENADOS PELO PREÇO:" << endl << endl;
	cout << "----------------------------------------------" << endl;

	for (int i = 1; i <= TotalSlots; i++) {
		cout << "Produto: " << nomes[i] << endl;
		cout << "Preço: " << setprecision(2) << fixed << precos[i] << simboloEuro() << endl;
		cout << "----------------------------------------------" << endl;

	}

}



void ordemQuantidade() {
	int quantidades[26];
	string nomes[26];
	for (int i = 1; i <= TotalSlots; i++) {
		quantidades[i] = VetSlots[i].quantidade;
		nomes[i] = VetSlots[i].nome;
	}



	bool swapped = true;
	for (int i = 0; i < TotalSlots && swapped; i++) {
		swapped = false;
		for (int j = TotalSlots; j > i; j--) {
			if (quantidades[j] < quantidades[j - 1]) {
				swap(quantidades[j], quantidades[j - 1]);
				swap(nomes[j], nomes[j - 1]);
				swapped = true;
			}
		}
	}

	cout << "LISTA DOS PRODUTOS ORDENADOS PELA QUANTIDADE DISPONÍVEL:" << endl << endl;
	cout << "----------------------------------------------" << endl;

	for (int i = 1; i <= TotalSlots; i++) {
		cout << "Produto: " << nomes[i] << endl;
		cout << "Quantidade: " << quantidades[i] << endl;
		cout << "----------------------------------------------" << endl;

	}

}

void ordemAlfabetica() {
	string nomes[26];
	int quantidades[26];
	for (int i = 1; i <= TotalSlots; i++) {
		nomes[i] = VetSlots[i].nome;
		quantidades[i] = VetSlots[i].quantidade;
	}


	bool swapped = true;
	for (int i = 1; i < TotalSlots && swapped; i++) {
		swapped = false;
		for (int j = TotalSlots; j > i; j--) {
			if (nomes[j] < nomes[j - 1]) {
				swap(nomes[j], nomes[j - 1]);
				swap(quantidades[j], quantidades[j - 1]);
				swapped = true;
			}
		}
	}

	cout << "LISTA DOS PRODUTOS ORDENADOS POR ORDEM ALFABÉTICA:" << endl << endl;
	cout << "----------------------------------------------" << endl;

	for (int i = 1; i <= TotalSlots; i++) {
		cout << "Produto: " << nomes[i] << endl;
		cout << "Quantidade: " << quantidades[i] << endl;
		cout << "----------------------------------------------" << endl;

	}

}

void menuImprimeProdutos() {
	char opcao;
	cout << "1. Por ordem alfabética" << endl;
	cout << "2. Por Preço" << endl;
	cout << "3. Por quantidade disponível" << endl;
	cout << "Escolha a sua opção:" << endl;
	cin >> opcao;
	switch (opcao) {
	case '1':
		cout << endl;
		ordemAlfabetica();
		cout << endl;
		break;
	case '2':
		cout << endl;
		ordemPreco();
		break;
	case '3':

		cout << endl;
		ordemQuantidade();
		break;
	}
	menuFuncionario();
}

void removerFundos() {
	cout << "Estado atual da Caixa:" << endl << endl;
	mostraCaixa();
	cout << endl;
	cout << "Escreva a quantidade de moedas de cada tipo que deseja remover da caixa" << endl;
	int moedas_2;
	int moedas_1;
	int moedas_50;
	int moedas_20;
	int moedas_10;
	int moedas_5;


	bool Ok2;
	do{
	cout << endl;
	cout << "Introduza a quantidade de moedas de 2 euros que deseja remover:";
	cin >> moedas_2;
	if ( moedas_2 > VetDinheiro[0].quantidade){
		cout << "Não pode remover moedas para além da quantidade existente." << endl;
		Ok2 = false;
	}
	else
	{
	Ok2 = true;
	}
	}
	while (Ok2==false);


	bool Ok1;
	do {
		cout << endl;
		cout << "Introduza a quantidade de moedas de 1 euro que deseja remover:";
		cin >> moedas_1;
		if (moedas_1 > VetDinheiro[1].quantidade) {
			cout << "Não pode remover moedas para além da quantidade existente." << endl;
			Ok1 = false;
		}
		else
		{
			Ok1 = true;
		}
	} while (Ok1 == false);


	bool Ok50;
	do {
		cout << endl;
		cout << "Introduza a quantidade de moedas de 50 cêntimos que deseja remover:";
		cin >> moedas_50;
		if (moedas_50 > VetDinheiro[2].quantidade) {
			cout << "Não pode remover moedas para além da quantidade existente." << endl;
			Ok50 = false;
		}
		else
		{
			Ok50 = true;
		}
	} while (Ok50 == false);


	bool Ok20;
	do {
		cout << endl;
		cout << "Introduza a quantidade de moedas de 20 cêntimos que deseja remover:";
		cin >> moedas_20;
		if (moedas_20 > VetDinheiro[3].quantidade) {
			cout << "Não pode remover moedas para além da quantidade existente." << endl;
			Ok20 = false;
		}
		else
		{
			Ok20 = true;
		}
	} while (Ok20 == false);


	bool Ok10;
	do {
		cout << endl;
		cout << "Introduza a quantidade de moedas de 10 cêntimos que deseja remover:";
		cin >> moedas_10;
		if (moedas_10 > VetDinheiro[4].quantidade) {
			cout << "Não pode remover moedas para além da quantidade existente." << endl;
			Ok10 = false;
		}
		else
		{
			Ok10 = true;
		}
	} while (Ok10 == false);


	bool Ok5;
	do {
		cout << endl;
		cout << "Introduza a quantidade de moedas de 5 cêntimos que deseja remover:";
		cin >> moedas_5;
		if (moedas_5 > VetDinheiro[5].quantidade) {
			cout << "Não pode remover moedas para além da quantidade existente." << endl;
			Ok5 = false;
		}
		else
		{
			Ok5 = true;
		}
	} while (Ok5 == false);


	cout << endl;

	VetDinheiro[5].quantidade = VetDinheiro[5].quantidade - moedas_5;
	VetDinheiro[4].quantidade = VetDinheiro[4].quantidade - moedas_10;
	VetDinheiro[3].quantidade = VetDinheiro[3].quantidade - moedas_20;
	VetDinheiro[2].quantidade = VetDinheiro[2].quantidade - moedas_50;
	VetDinheiro[1].quantidade = VetDinheiro[1].quantidade - moedas_1;
	VetDinheiro[0].quantidade = VetDinheiro[0].quantidade - moedas_2;

	cout << "Removeu da caixa " << moedas_2 << " moedas de 2 euros, " << moedas_1 << " moedas de 1 euro, " << moedas_50 << " moedas de 50 cêntimos, " << moedas_20 <<
		" moedas de 20 cêntimos, " << moedas_10 << " moedas de 10 cêntimos e " << moedas_5 << " moedas de 5 cêntimos." << endl << endl;
	mostraCaixa();
	menuFuncionario();
}


void saveCaixa() {
	fstream fs;
	fs.open("saveCaixa.txt", ifstream::out);

	for (int i = 0; i <= 5; i++) {

		fs << VetDinheiro[i].ID;
		fs << '|';
		fs << VetDinheiro[i].nome;
		fs << '|';
		fs << VetDinheiro[i].valor;
		fs << '|';
		fs << VetDinheiro[i].quantidade;
		fs << endl;
	}
	fs.close();

}

void carregarCaixa() {


	ifstream myFile("saveCaixa.txt");
	string line = "";
	int i = 0;
	if (myFile.is_open()) { //verificar se o ficheiro existe

		while (getline(myFile, line)) {
			caixa* novaMoeda = new caixa;

			int pos = line.find('|');
			string StringID = line.substr(0, pos);
			const char* CharID = StringID.c_str();
			int IntID = atoi(CharID);
			line.erase(0, (pos + 1));

			pos = line.find('|');
			string StringNome = line.substr(0, pos);
			line.erase(0, (pos + 1));


			pos = line.find('|');
			string StringValor = line.substr(0, pos);
			const char* CharValor = StringValor.c_str();
			float FloatValor = atof(CharValor);          // atof transforma char* em float
			line.erase(0, (pos + 1));


			pos = line.find('|');
			string StringQuantidade = line.substr(0, pos);
			const char* CharQuantidade = StringQuantidade.c_str();
			int IntQuantidade = atoi(CharQuantidade);
			line.erase(0, (pos + 1));



			novaMoeda->ID = IntID;
			novaMoeda->nome = StringNome;
			novaMoeda->valor = FloatValor;
			novaMoeda->quantidade = IntQuantidade;
			VetDinheiro[i] = *novaMoeda;

			i++;


		}
	}
	myFile.close();



}

void saveMaquina() {
	fstream fs;
	fs.open("saveMaquina.txt", ifstream::out);

	for (int i = 1; i <= TotalSlots; i++) {

		fs << VetSlots[i].ID;
		fs << '|';
		fs << VetSlots[i].nome;
		fs << '|';
		fs << VetSlots[i].preco;
		fs << '|';
		fs << VetSlots[i].quantidade;
		fs << '|';
		fs << VetSlots[i].capacidade;
		fs << endl;
	}
	fs.close();

}



void carregarMaquina() {


	ifstream myFile("saveMaquina.txt");
	string line = "";
	int i = 1;
	if (myFile.is_open()) { //verificar se o ficheiro existe



		while (getline(myFile, line)) {
			slot* novoSlot = new slot;

			int pos = line.find('|');
			string StringID = line.substr(0, pos);  // substr(0,pos) copia os caracteres apartir da posição 0 até a posição pos
			const char* ConstCharID = StringID.c_str();   // c_str() transforma a string em char*
			char CharID = ConstCharID[0];
			line.erase(0, (pos + 1));  // erase(0,(pos+1)) apaga os caracatares apartir da posição 0 até a posição pos+1


			pos = line.find('|');
			string StringNome = line.substr(0, pos);
			line.erase(0, (pos + 1));

			pos = line.find('|');
			string StringPreco = line.substr(0, pos);
			const char* CharPreco = StringPreco.c_str();
			float FloatPreco = atof(CharPreco);          // atof transforma char* em float
			line.erase(0, (pos + 1));

			pos = line.find('|');
			string StringQuantidade = line.substr(0, pos);
			const char* CharQuantidade = StringQuantidade.c_str();
			int IntQuantidade = atoi(CharQuantidade);
			line.erase(0, (pos + 1));

			pos = line.find('|');
			string StringCapacidade = line.substr(0, pos);
			const char* CharCapacidae = StringCapacidade.c_str();
			int IntCapacidade = atoi(CharCapacidae);              // atoi transforma char* em int
			line.erase(0, (pos + 1));


			novoSlot->ID = CharID;
			novoSlot->nome = StringNome;
			novoSlot->preco = FloatPreco;
			novoSlot->quantidade = IntQuantidade;
			novoSlot->capacidade = IntCapacidade;
			VetSlots[i] = *novoSlot;

			i++;


		}
	}
	myFile.close();

	TotalSlots = i - 1;

}

void menuFuncionario() {

	int opcao;
	cout << endl;
	cout << "*** Bem vindo funcionário ***" << endl << endl;
	
		

		cout << "1. Limpar slots" << endl;
		cout << "2. Limpar máquina" << endl;
		cout << "3. Adicionar produto" << endl;
		cout << "4. Alterar preço" << endl;
		cout << "5. Adicionar slots" << endl;
		cout << "6. Carregar moedas" << endl;
		cout << "7. Imprimir produtos" << endl;
		cout << "8. Gravar máquina" << endl;
		cout << "9. Carregar máquina" << endl;
		cout << "10. Remover trocos" << endl;
		cout << "0. Voltar" << endl;
		
		cin >> opcao;
		cout << endl;
		switch (opcao) {
		case 1: 
			cout << "Escolheu a opcão Limpar slots" << endl << endl;
			limparSlot();
			break;

		case 2:
			cout << "Escolheu a opcão Limpar máquina" << endl << endl;
			limparMaquina();
			break;

		case 3:
			cout << "Escolheu a opcão Adicionar produto" << endl << endl;
			adicionarProduto();
			break;

		case 4:
			cout << "Escolheu a opcão Alterar preço" << endl << endl;
			alterarPreço();
			break;

		case 5:
			cout << "Escolheu a opcão Adicionar slots" << endl << endl;
			adicionarSlots();
			break;

		case 6:
			cout << "Escolheu a opcão adicionar moedas à Caixa." << endl << endl;
			carregarMoedas();
			break;

		case 7:
			cout << "Escolheu a opcão Imprimir produtos" << endl << endl;
			menuImprimeProdutos();
			break;

		case 8:
			cout << "Escolheu a opcão Gravar máquina" << endl << endl;
			saveMaquina();
			saveCaixa();
			cout << "Gravou o estado atual da máquina e caixa de moedas." << endl;
			menuFuncionario();
			break;

		case 9:
			cout << "Escolheu a opcão Carregar máquina" << endl << endl;
			carregarMaquina();
			carregarCaixa();
			MostrarMaquina();
			menuMaquina();
		
		
			break;

		case 10:
			cout << "Escolheu a opcão Remover trocos" << endl << endl;
			removerFundos();
			break;

		case 0:
			menuMaquina();

		
		default:
			cout << endl;
			cout << "Introduza a sua opção:" << endl;
		}
	} 
