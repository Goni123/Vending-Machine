#pragma once
#include<string>
#include<iostream>

struct caixa {
	int ID;
	string nome;
	float valor;
	int quantidade;
};

void iniciaCaixa();
void mostraCaixa();
void avisoMoedas();

extern caixa VetDinheiro[6];