#include <iostream>
#include "includes/celula.hpp"

Celula::Celula(){
	this->volume = 0;
	this->numOperacoes = 0;
	this->proximo = nullptr;
};

Celula::Celula(int volume){
	this->volume = volume;
	this->numOperacoes = 0;
	this->proximo = nullptr;
};

Celula::Celula(int volume, int numOperacoes){
	this->volume = volume;
	this->numOperacoes = numOperacoes;
	this->proximo = nullptr;
};