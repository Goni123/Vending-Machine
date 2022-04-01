#include <iostream>
#include <string>
#include <stdlib.h> 
#include <time.h>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "maquina.h"
#include "funcionario.h"
#include "dinheiro.h"
#include "cliente.h"

using namespace std;

char simboloEuro() {
	SetConsoleOutputCP(1252);
	char simbolo = '\u20AC';

	return simbolo;
}

void menuMaquina() {
	bool sair=false;
	char opcao;
	cout << endl;
	do {
		cout << "*** Bem vindo - MÁQUINA DE VENDING EDA: ***" << endl << endl;

		cout << "Escolha o tipo de utilizador:" << endl << endl;

		cout << "1. (C)liente " << endl;
		cout << "2. (F)uncionário" << endl;
		cout << "0. Sair" << endl;


		cin >> opcao;
		cout << endl;
		switch (opcao) {
		case '1':
		case 'c':
		case 'C':
			cout << "--> Escolheu entrar como Cliente" << endl << endl;
			compra();
			break;

		case '2':
		case 'f':
		case 'F':
			cout << "--> Escolheu entrar como Funcionário" << endl << endl;
			menuFuncionario();
			break;

		case '0':
			sair = true;
			break;

		default:
			cout << endl;
			cout << "Introduza a sua opção:" << endl;
			menuMaquina();
		}
	} while (false);
}


int aleatorio(int inicio, int fim) {

	int* valor = new int;
	*valor = rand() % (fim - inicio + 1) + inicio;
		return *valor;
}

string Produtos() {
	ifstream myFile("produtos.txt");
	string line;
	string* Produto = new string[24];
	int i = 0;
	if (myFile.is_open()) { //verificar se o ficheiro existe

		while (getline(myFile, line)) {
			Produto[i] = line;
			i++;

		}
	}
	myFile.close();
	
	return Produto[aleatorio(0,23)]; // (0,23) porque o vetor terá posiçoes do 0 ao 23 (total de 24 produtos)
}

float Preços() {
	ifstream myFile("precos.txt");
	string line;
	float* ArrayPreço = new float[9];
	int i = 0;
	if (myFile.is_open()) { //verificar se o ficheiro existe

		while (getline(myFile, line)) {

			ArrayPreço[i] = stof(line);
			i++;

		}
	}
	myFile.close();
	
	return ArrayPreço[aleatorio(0, 9)]; // (0,9) porque o vetor terá posiçoes do 0 ao 9 (total de 10 preços)

}

char letras[] = { ' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
slot VetSlots[26]; // 26 = Numero de letras do abecedario, é o máximo possível de slots que poderão ser criados 
int TotalSlots = aleatorio(9, 12);

void IniciaMaquina() {
	string ProdutoAleatorio = Produtos();
	for (int i = 1; i <= TotalSlots; i++) {
		slot* novoSlot = new slot;
		int CAPACIDADE = aleatorio(5, 10);

		bool OK;
		do {
			ProdutoAleatorio = Produtos();
			for (int e = 1; e <= i; e++) {
				if (VetSlots[e].nome == ProdutoAleatorio) {
					OK = false;
					break;
				}
				else {
					OK = true;
				}
			}
		} while (OK == false);

		novoSlot->ID = letras[i];
		novoSlot->nome = ProdutoAleatorio;
		novoSlot->preco = Preços();
		novoSlot->capacidade = CAPACIDADE;
		novoSlot->quantidade = CAPACIDADE;
		VetSlots[i] = *novoSlot;
	}
}

void MostrarMaquina(){
	cout << endl;
	cout << "--------------------------------------------" << endl;
	for (int i = 1; i <= TotalSlots; i++){
		cout << "Slot: " << VetSlots[i].ID << endl;
		cout << "Produto: " << VetSlots[i].nome << endl;
		cout << "Preço: " << setprecision(2) << fixed << VetSlots[i].preco << simboloEuro() << endl;
		cout << "Quantidade: " << VetSlots[i].quantidade << "         " << " |   Capacidade: " << VetSlots[i].capacidade << endl;
		cout << "--------------------------------------------" << endl ;
	}
	cout <<  endl;
	avisoMoedas();
}

