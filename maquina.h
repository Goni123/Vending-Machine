#pragma once
#include<string>
#include<iostream>

using namespace std;

void menuMaquina();

void IniciaMaquina();

string Produtos();

float Pre�os();

int aleatorio(int inicio, int fim);

void MostrarMaquina();

char simboloEuro();

struct slot {
	char ID;  // ID ser� a letra
	string nome;  // Produto
	float preco;
	int capacidade;
	int quantidade;
};


extern int TotalSlots;
extern slot VetSlots[26];



