#ifndef _TP1_lista
#define _TP1_lista

#include "celula.hpp"

class Lista{
	
	public:
		Lista();
		~Lista();
			
		void insereElemento(int volume);
		void retiraElemento(int volume);
		int minimoOperacoes(int volumeDesejado);
		
	protected:
		Celula *primeiro, *ultimo;

		void insereElemento(int numOperacoes, int volume);
		bool estaVazia();
};

#endif