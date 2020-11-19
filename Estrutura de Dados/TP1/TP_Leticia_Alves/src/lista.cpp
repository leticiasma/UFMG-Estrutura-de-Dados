#include <iostream>
#include "includes/lista.hpp"

Lista::Lista(){
	this->primeiro = new Celula();  
	this->ultimo = this->primeiro; 
};

Lista::~Lista(){
	Celula *celulaAux = this->primeiro;
	while (celulaAux != nullptr){
		this->primeiro = celulaAux->proximo;
		delete celulaAux;
		celulaAux = this->primeiro;
	}
};

bool Lista::estaVazia(){
	return (this->primeiro == this->ultimo);
};

void Lista::insereElemento(int volume) {
	Celula *novaCelula = new Celula(volume);
	this->ultimo->proximo = novaCelula;
	this->ultimo = novaCelula;
};

void Lista::insereElemento(int numOperacoes, int volume) {
	Celula *novaCelula = new Celula(volume, numOperacoes);
	this->ultimo->proximo = novaCelula;
	this->ultimo = novaCelula;
};
	
void Lista::retiraElemento(int volume){	

		if (this->estaVazia()){
			std::cout<<"Erro: Lista vazia."<<std::endl;        			
			return;
		}
		
		//Testa se a célula imediatamente depois da cabeça contém o volume procurado
		if (this->primeiro->proximo->volume == volume){
			Celula *celulaTemp = this->primeiro->proximo;
			this->primeiro->proximo = celulaTemp->proximo;
			if (celulaTemp->proximo == nullptr){
                ultimo = primeiro;
			}
			delete celulaTemp;
			
			return;
		}
		
		//Ponteiro que representa o elemento anterior ao que se deseja retirar
		Celula *celulaAtual = this->primeiro->proximo;
		
		//Procura pelo elemento a ser retirado no restante da lista
		while (celulaAtual->proximo != nullptr && celulaAtual->proximo->volume != volume){
			celulaAtual = celulaAtual->proximo;
		}
		
		if(celulaAtual->proximo == nullptr){
			std::cout<<"Erro: Valor nao encontrado."<<std::endl;			
			return;
		}
		
		Celula *celulaTemp = celulaAtual->proximo;
		celulaAtual->proximo = celulaTemp->proximo;
		
		delete celulaTemp; 
		
		//Atualiza o ultimo elemento da lista se o retirado era o ultimo
		if (celulaAtual->proximo == nullptr){
			this->ultimo = celulaAtual;
		}
		
		return;
};

int Lista::minimoOperacoes(int volumeDesejado){
	
	if (this->estaVazia() || volumeDesejado < 0){ 
		std::cout<<"Erro: Lista vazia ou volume desejado inválido."<<std::endl;	
		return -1;
	}
	
	//Caso base do problema de medição
	if (volumeDesejado == 0){ 	
		return 0;
	}
	
	Lista *listaOperacoes = new Lista();
	
	//Itera sobre a lista de recipientesDisponiveis
	Celula *recipienteAtual = this->primeiro->proximo;
	
	//Itera sobre a listaOperacoes
	Celula *operacaoAtual = listaOperacoes->primeiro;
	
	//Guardam os volumes parciais obtidos durante as combinações
	int volumeTempSoma = 0;
	int volumeTempSubtr = 0;

	while(operacaoAtual != nullptr){
		while (recipienteAtual != nullptr){
			
			volumeTempSoma = operacaoAtual->volume + recipienteAtual->volume;
			volumeTempSubtr = operacaoAtual->volume - recipienteAtual->volume;
			
			if (volumeTempSoma == volumeDesejado){
				
				int numOperacoes = operacaoAtual->numOperacoes+1;
				delete listaOperacoes;

				return numOperacoes;
			}
			
			if(volumeTempSoma >= 0){
				listaOperacoes->insereElemento(operacaoAtual->numOperacoes+1, volumeTempSoma);
			}
			
			if (volumeTempSubtr == volumeDesejado){
				
				int numOperacoes = operacaoAtual->numOperacoes+1;
				delete listaOperacoes;

				return numOperacoes;
			}
			
			if(volumeTempSubtr >= 0){
				listaOperacoes->insereElemento(operacaoAtual->numOperacoes+1, volumeTempSubtr);
			}
						
			recipienteAtual = recipienteAtual->proximo;
		}
		
		recipienteAtual = this->primeiro->proximo;
		operacaoAtual = operacaoAtual->proximo;
	};
	
	return -1;
};