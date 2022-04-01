#include <iostream>
#include <string>
#include <stdlib.h> 
#include <time.h>
#include <fstream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include "maquina.h"
#include"funcionario.h"
#include "dinheiro.h"

using namespace std;



void compra() {
	char ID;
	float preco;
	string produto;
	float troco;

	float totalIntroduzido;

	int moedas_2;
	int moedas_1;
	int moedas_50;
	int moedas_20;
	int moedas_10;
	int moedas_5;
	int pos;

	MostrarMaquina();
	cout << endl;

	bool OkProduto;
	cout << "*** Bem vindo Cliente ***" << endl;
	do {
		cout << endl;
		cout << "Escolha o slot com o seu produto: ";
		cin >> ID;
		ID = toupper(ID);
		for (int i = 0; i <= TotalSlots; i++) {
			if (VetSlots[i].ID == ID && VetSlots[i].nome != "Vazio") {
				pos = i;
				ID = VetSlots[i].ID;
				preco = VetSlots[i].preco;
				produto = VetSlots[i].nome;
				OkProduto = true;
				break;
			}
			else {
				OkProduto = false;

			}

		}
		if (OkProduto == false)cout << "O Slot que escolheu não está vazio ou não existe. Escolha outro slot." << endl;


	} while (OkProduto == false);
	

	

	cout << endl;
	cout << "Escolheu o produto " << produto << " do slot " << ID << " com o preço de " << preco << simboloEuro() << endl << endl;


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

	totalIntroduzido = (moedas_2 * 2.00) + (moedas_1 * 1.00) + (moedas_50 * 0.50) + (moedas_20 * 0.20) + (moedas_10 * 0.10) + (moedas_5 * 0.05);
	troco = totalIntroduzido - preco;
	
	if (totalIntroduzido < preco) {
		cout << endl;
		cout << "Não introduziu o montante suficiente. O seu dinheiro foi devolvido." << endl <<endl;
		cout << "As suas moedas:" << endl;
		cout << "Moedas de 2: " << moedas_2 << endl;
		cout << "Moedas de 1: " << moedas_1 << endl;
		cout << "Moedas de 50: " << moedas_50 << endl;
		cout << "Moedas de 20: " << moedas_20 << endl;
		cout << "Moedas de 10: " << moedas_10 << endl;
		cout << "Moedas de 5: " << moedas_5 << endl << endl;
		menuMaquina();
	}
	else
	{

	
	int euros = int(troco);
	int cents = round((troco - euros)*100);

	cout << "Valor introduzido: " << totalIntroduzido << endl;
	cout << "Troco total: " << troco << endl << endl;
	

	int n;
	int Troco_2;
	int Troco_1;
	int Troco_50;
	int Troco_20;
	int Troco_10;
	int Troco_5;


		n = euros / 2;    // n calcula quantas moedas de 2 necessárias
		if (VetDinheiro[0].quantidade >= n) {  // se houver essa quantidade de moedas disponível,
			euros = euros % 2;    //  então atualiza a variável euros com o valor restante
			Troco_2 = n;
		}
		else
		{
			euros = euros - (VetDinheiro[0].quantidade * 2); // caso contrário, só poderão ser usadas as moedas dispóniveis e é descontado à varável euros, o valor dessas moedas disponíveis
			Troco_2 = VetDinheiro[0].quantidade;			
		}
		



		n = euros / 1;
		if (VetDinheiro[1].quantidade >= n) {
			euros = euros % 1;
			 Troco_1 = n;
		}
		else
		{
			euros = euros - (VetDinheiro[1].quantidade * 1);
			Troco_1 = VetDinheiro[1].quantidade;
		}




		if (euros > 0) {							// se, sobrar algum valor na variável euros, esse é convertido em centimos 
			cents = (euros * 100) + cents;
		}
		
	
	
		n = cents / 50;
		if (VetDinheiro[2].quantidade >= n) {
			cents = cents % 50;
			Troco_50 = n;
		}
		else
		{
			cents = cents - (VetDinheiro[2].quantidade * 50);
			Troco_50 = VetDinheiro[2].quantidade;
		}
	
	

		n = cents / 20;
		if (VetDinheiro[3].quantidade >= n) {
			cents = cents % 20;
			Troco_20 = n;
		}
		else
		{
			cents = cents - (VetDinheiro[3].quantidade * 20);
			Troco_20 = VetDinheiro[3].quantidade;
		}
		
	

		n = cents / 10;
		if (VetDinheiro[4].quantidade >= n) {
			cents = cents % 10;
			Troco_10 = n;
		}
		else
		{
			cents = cents - (VetDinheiro[4].quantidade * 10);
			Troco_10 = VetDinheiro[4].quantidade;
		}


	
		n = cents / 5;
		if (VetDinheiro[5].quantidade >= n) {
			cents = cents % 5;
			Troco_5 = n;
		}
		else
		{
			cents = cents - (VetDinheiro[5].quantidade * 5);
			Troco_5 = VetDinheiro[5].quantidade;
		}

	

		float verifica = (Troco_2 * 2.00) + (Troco_1 * 1.00) + (Troco_50 * 0.50) + (Troco_20 * 0.20) + (Troco_10 * 0.10) +(Troco_5 * 0.05);
		int verifica2 = round(verifica * 100);
		int troco2 = round(troco * 100);

		if (troco2==verifica2) {  // só avança com a compra, caso o troco gerado seja igual ao troco necessário
			
			// remove da caixa as moedas devolvidas no troco
			VetDinheiro[0].quantidade = VetDinheiro[0].quantidade - Troco_2;
			VetDinheiro[1].quantidade = VetDinheiro[1].quantidade - Troco_1;
			VetDinheiro[2].quantidade = VetDinheiro[2].quantidade - Troco_50;
			VetDinheiro[3].quantidade = VetDinheiro[3].quantidade - Troco_20;
			VetDinheiro[4].quantidade = VetDinheiro[4].quantidade - Troco_10;
			VetDinheiro[5].quantidade = VetDinheiro[5].quantidade - Troco_5;

			// guarda na caixa as moedas introduzidas pelo utilizador
			VetDinheiro[0].quantidade = VetDinheiro[0].quantidade + moedas_2;
			VetDinheiro[1].quantidade = VetDinheiro[1].quantidade + moedas_1;
			VetDinheiro[2].quantidade = VetDinheiro[2].quantidade + moedas_50;
			VetDinheiro[3].quantidade = VetDinheiro[3].quantidade + moedas_20;
			VetDinheiro[4].quantidade = VetDinheiro[4].quantidade + moedas_10;
			VetDinheiro[5].quantidade = VetDinheiro[5].quantidade + moedas_5;

			VetSlots[pos].quantidade = VetSlots[pos].quantidade - 1;

			if (VetSlots[pos].quantidade == 0) {
				VetSlots[pos].nome = "Vazio";
				VetSlots[pos].preco = 0;
			}

			MostrarMaquina();
			mostraCaixa();

			cout << "COMPRA EFETUADA COM SUCESSO" << endl << endl;
			cout << "Introduziu " << totalIntroduzido << simboloEuro() << " e recebeu " << troco << simboloEuro() << " de troco." << endl<< endl;
			cout << "O seu troco:" << endl;
			cout << "Moedas de 2: " << Troco_2 << endl;
			cout << "Moedas de 1: " << Troco_1 << endl;
			cout << "Moedas de 50: " << Troco_50 << endl;
			cout << "Moedas de 20: " << Troco_20 << endl;
			cout << "Moedas de 10: " << Troco_10 << endl;
			cout << "Moedas de 5: " << Troco_5 << endl<<endl;

			cout << "Obrigado pela sua compra!" << endl;
			
			menuMaquina();

		}
		else
		{
			cout << "COMPRA CANCELADA" << endl;
			cout << "A máquina não tem troco suficiente. O seu dinheiro foi devolvido."<< endl << endl;
			cout << "As suas moedas:" << endl;
			cout << "Moedas de 2: " << moedas_2 << endl;
			cout << "Moedas de 1: " << moedas_1 << endl;
			cout << "Moedas de 50: " << moedas_50 << endl;
			cout << "Moedas de 20: " << moedas_20 << endl;
			cout << "Moedas de 10: " << moedas_10 << endl;
			cout << "Moedas de 5: " << moedas_5 << endl << endl;
			
			MostrarMaquina();
			mostraCaixa();
			menuMaquina();
		}
		}
}

