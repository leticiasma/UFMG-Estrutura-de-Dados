#ifndef _TP1_celula
#define _TP1_celula

class Celula{
	
	protected:
		int volume;
		int numOperacoes;
		Celula *proximo;
		
		Celula();	             
		Celula(int volume);
		Celula(int volume, int numOperacoes);
		
	friend class Lista;
};

#endif