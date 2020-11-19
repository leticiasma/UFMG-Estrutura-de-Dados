#ifndef _TP2_Planeta
#define _TP2_Planeta

#include <string>

class Planeta{
	
	protected:
		std::string nomePlaneta;
		int tempoVisitacao;
		
		Planeta(std::string nomePlaneta, int tempoVisitacao);
		
	friend class Ordenacao;
};

#endif