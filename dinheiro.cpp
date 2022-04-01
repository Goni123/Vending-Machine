#include <iostream>
#include <string>
#include <stdlib.h> 
#include <time.h>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "maquina.h"
#include "funcionario.h"
#include "dinheiro.h"

caixa VetDinheiro[6];
float TotalCaixa = 0;



void iniciaCaixa() {

	caixa* novaMoeda = new caixa;

	novaMoeda->ID = 5;
	novaMoeda->nome = "5 cêntimos";
	novaMoeda->valor = 0.05;
	novaMoeda->quantidade = aleatorio(10, 20);
	VetDinheiro[5] = *novaMoeda;
	

	
	novaMoeda->ID = 10;
	novaMoeda->nome = "10 cêntimos";
	novaMoeda->valor = 0.10;
	novaMoeda->quantidade = aleatorio(10, 20);
	VetDinheiro[4] = *novaMoeda;
	

	
	novaMoeda->ID = 20;
	novaMoeda->nome = "20 cêntimos";
	novaMoeda->valor = 0.20;
	novaMoeda->quantidade = aleatorio(10, 20);
	VetDinheiro[3] = *novaMoeda;
	

	
	novaMoeda->ID = 50;
	novaMoeda->nome = "5 cêntimos";
	novaMoeda->valor = 0.50;
	novaMoeda->quantidade = aleatorio(10, 20);
	VetDinheiro[2] = *novaMoeda;


	
	novaMoeda->ID = 1;
	novaMoeda->nome = "1 euro";
	novaMoeda->valor = 1.00;
	novaMoeda->quantidade = aleatorio(10, 20);
	VetDinheiro[1] = *novaMoeda;
	

	
	novaMoeda->ID = 2;
	novaMoeda->nome = "2 euros";
	novaMoeda->valor = 2.00;
	novaMoeda->quantidade = aleatorio(10, 20);
	VetDinheiro[0] = *novaMoeda;
	
}

void avisoMoedas() {
	cout << endl;
	for (int i = 0; i <= 5; i++) {
		if (VetDinheiro[i].quantidade == 3) {
			cout << "*** ATENÇAO! Existem apenas 3 moedas de " << VetDinheiro[i].valor << simboloEuro() << " ***" << endl;
		}
		if (VetDinheiro[i].quantidade == 2) {
			cout << "*** ATENÇAO! Existem apenas 2 moedas de " << VetDinheiro[i].valor << simboloEuro() << " ***" << endl;
		}
		if (VetDinheiro[i].quantidade == 1) {
			cout << "*** ATENÇAO! Existe apenas 1 moeda de " << VetDinheiro[i].valor << simboloEuro() << " ***" << endl;
		}
		if (VetDinheiro[i].quantidade == 0) {
			cout << "*** ATENÇAO! Não existem moedas de " << VetDinheiro[i].valor << simboloEuro() << " ***" << endl;

		}

	}
	cout << endl;
}

void mostraCaixa() {
	TotalCaixa = (VetDinheiro[0].quantidade * VetDinheiro[0].valor) + (VetDinheiro[1].quantidade * VetDinheiro[1].valor) + (VetDinheiro[2].quantidade * VetDinheiro[2].valor) +
		(VetDinheiro[3].quantidade * VetDinheiro[3].valor) + (VetDinheiro[4].quantidade * VetDinheiro[4].valor) + (VetDinheiro[5].quantidade * VetDinheiro[5].valor);


	cout << "Total em caixa: " << setprecision(2) << fixed << TotalCaixa << simboloEuro() << endl;
	cout << "Moedas de 2 euros: " << VetDinheiro[0].quantidade << endl;
	cout << "Moedas de 1 euro: " << VetDinheiro[1].quantidade << endl;
	cout << "Moedas de 50 cêntimos: " << VetDinheiro[2].quantidade << endl;
	cout << "Moedas de 20 cêntimos: " << VetDinheiro[3].quantidade << endl;
	cout << "Moedas de 10 cêntimos: " << VetDinheiro[4].quantidade << endl;
	cout << "Moedas de 5 cêntimos: " << VetDinheiro[5].quantidade << endl;
	cout << endl;

	avisoMoedas();
	
}
