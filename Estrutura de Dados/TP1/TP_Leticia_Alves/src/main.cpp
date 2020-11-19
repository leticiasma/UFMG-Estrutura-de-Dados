#include <iostream>
#include "includes/lista.hpp"

int main() {
	
	Lista *recipientesDisponiveis = new Lista();
	int q;
	char e;
	
	while(scanf("%d %c", &q, &e) != EOF) {
		if (e == 'p'){
		std::cout<<recipientesDisponiveis->minimoOperacoes(q)<<std::endl;
		}
		if (e == 'i'){	  
			recipientesDisponiveis->insereElemento(q);
		}
		if (e == 'r'){	  
			recipientesDisponiveis->retiraElemento(q);
		}
	}

		delete recipientesDisponiveis;
		
	return 0;
}
