#include <iostream>
#include <string>
#include <stdlib.h> 
#include <time.h>
#include <fstream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include"maquina.h"
#include"funcionario.h"
#include"dinheiro.h"

using namespace std;





int main() {

	srand((unsigned int)time(NULL));
	

	IniciaMaquina();
	iniciaCaixa();
	MostrarMaquina();
	menuMaquina();
	
	

	

	return 0;

}


	





