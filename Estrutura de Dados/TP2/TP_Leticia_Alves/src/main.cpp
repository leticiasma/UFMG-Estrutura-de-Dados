#include "includes/planeta.hpp"
#include "includes/ordenacao.hpp"

int main(){
	int t;
	int p;
	int c;
	
	Ordenacao agendaViagens;
  
	while(scanf("%d %d %d", &t, &p, &c) != EOF){
		agendaViagens.organizaAgenda(t,p,c);
	}
  
	return 0;
};