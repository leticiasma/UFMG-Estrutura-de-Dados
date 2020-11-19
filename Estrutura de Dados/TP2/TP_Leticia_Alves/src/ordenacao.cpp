#include "includes/planeta.hpp"
#include "includes/ordenacao.hpp"

#include <iostream>

void Ordenacao::organizaAgenda(int tempoMes, int numPlanetas, int tamanhoNome){
	
	std::vector<Planeta*> vetorPlanetas(numPlanetas);
	
	std::string nomePlaneta;
	int tempoVisitacao=0;
	
	for(int i = 0; i < numPlanetas; i++){
		std::cin>>tempoVisitacao>>nomePlaneta;
		vetorPlanetas[i] = new Planeta(nomePlaneta, tempoVisitacao);
	}
	
	mergeSort(vetorPlanetas, 0, numPlanetas-1, numPlanetas);
	
	int mes = 1;
	int tempoMaxMes = 0;
	int esquerda = 0;
	int direita = 0;
	
	for(int i = 0; i < numPlanetas; i++){
		if(tempoMaxMes + vetorPlanetas[i]->tempoVisitacao > tempoMes){
			ordenaMes(vetorPlanetas, esquerda, direita, mes);
			
			esquerda = direita+1;
			mes++;
			tempoMaxMes = 0;
		}
		
		tempoMaxMes = tempoMaxMes + vetorPlanetas[i]->tempoVisitacao;
		direita = i;
		
		if(i == numPlanetas-1){
			ordenaMes(vetorPlanetas, esquerda, direita, mes);
		}
	}
	
	for(int i = 0; i < numPlanetas; i++){
		delete (vetorPlanetas[i]);
	}
};

void Ordenacao::ordenaMes(std::vector<Planeta*> &vetorPlanetas, int esquerda, int direita, int mes){
	std::vector<Planeta*> vetorPlanetasAux((direita+1) - esquerda);
	
	for(int i = esquerda; i <= direita; i++){
		vetorPlanetasAux[i - esquerda] = vetorPlanetas[i];
	}
	
	radixSort(vetorPlanetasAux, ((direita+1) - esquerda));
	
	for(int i = 0; i < ((direita+1) - esquerda); i++){
		std::cout<<mes<<" "<<vetorPlanetasAux[i]->nomePlaneta<<" "<<vetorPlanetasAux[i]->tempoVisitacao<<std::endl;
	}
};

void Ordenacao::mergeSort(std::vector<Planeta*> &vetorPlanetas, int esquerda, int direita, int numPlanetas){
    if(esquerda < direita){
        int meio = (esquerda + direita)/2;
		
        mergeSort(vetorPlanetas, esquerda, meio, numPlanetas) ;
        mergeSort (vetorPlanetas, meio+1, direita, numPlanetas);

        merge(vetorPlanetas, esquerda, meio, direita, numPlanetas);   
   }                    
};

void Ordenacao::merge(std::vector<Planeta*> &vetorPlanetas, int esquerda, int meio, int direita, int numPlanetas){
	int i, j, k;   

	std::vector<Planeta*> vetorPlanetasAux(numPlanetas);

	for (i = esquerda; i <= meio; i++){
		vetorPlanetasAux[i] = vetorPlanetas[i];
	}
	
	for (j = meio+1; j <= direita; j++){
		vetorPlanetasAux[direita-j+meio+1] = vetorPlanetas[j];
	}
	
	i = esquerda; 
	j = direita;
	
	for (k = esquerda; k <= direita; k++){
		if (i <= meio && vetorPlanetasAux[i]->tempoVisitacao <= vetorPlanetasAux[j]->tempoVisitacao){
			vetorPlanetas[k] = vetorPlanetasAux[i++];
		}
		else{
			vetorPlanetas[k] = vetorPlanetasAux[j--]; 
		}
	}
};

void Ordenacao::radixSort(std::vector<Planeta*> &vetorPlanetas, int numPlanetas){
    for (int i = vetorPlanetas[0]->nomePlaneta.size(); i > 0; i--){
        countSort(vetorPlanetas, numPlanetas, i - 1);
    }
};

void Ordenacao::countSort(std::vector<Planeta*> &vetorPlanetas, int numPlanetas, int k){
	std::vector<Planeta*> vetorPlanetasAux(numPlanetas);
	
	int *c = new int[257];

    for (int i = 0; i <257; i++){
        c[i] = 0;
    }
	
    for (int j = 0; j <numPlanetas; j++){   
        c[(int)(unsigned char)vetorPlanetas[j]->nomePlaneta[k] + 1]++;
    }

    for (int f = 1; f <257; f++){
        c[f] += c[f - 1];
    }

    for (int r = numPlanetas - 1; r >= 0; r--){
        vetorPlanetasAux[c[(int)(unsigned char)vetorPlanetas[r]->nomePlaneta[k] + 1] - 1] = vetorPlanetas[r];
        c[(int)(unsigned char)vetorPlanetas[r]->nomePlaneta[k] + 1]--;
    }
	
    for (int l = 0; l < numPlanetas; l++){
        vetorPlanetas[l] = vetorPlanetasAux[l];
    }
	
    delete[] c;
};