#ifndef _TP2_Ordenacao
#define _TP2_Ordenacao

#include <vector>

class Ordenacao{
	
	public:
		void organizaAgenda(int tempoMes, int numPlanetas, int tamanhoNome);
	
	protected:
		void mergeSort(std::vector<Planeta*> &vetorPlanetas, int esquerda, int direita, int numPlanetas);
		void merge(std::vector<Planeta*> &vetorPlanetas, int esquerda, int meio, int direita, int numPlanetas);
		void radixSort(std::vector<Planeta*> &vetorPlanetas, int numPlanetas);
		void countSort(std::vector<Planeta*> &vetorPlanetas, int numPlanetas, int k);	
		void ordenaMes(std::vector<Planeta*> &vetorPlanetas, int esquerda, int direita, int mes);
};

#endif