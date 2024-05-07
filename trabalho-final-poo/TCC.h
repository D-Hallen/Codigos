#ifndef TCC_H
#define TCC_H
#include "Item.h"

enum TipoConclusao {
			Monografia  = 0 , Dissertacao = 1, Tese =2
		};
class TCC : public Item
{
	public:
		TCC();
		~TCC();
		string getAutor ();
		string getUniversidade ();
		string getCurso ();
		int getAno ();
		string getLocal ();
		TipoConclusao getTipo ();
		
		void setAutor (string autor);
		void setUniversidade (string universidade);
		void setCurso (string curso);
		void setAno (int ano);
		void setLocal (string local);
		void setTipo (TipoConclusao tipo);
		
		void imprimeFichaTecnica() override;
		TCC* cadastra ();
	/*	TipoItem obterTipo() const override{
        return TipoItem::TCC;
    	}
		
		string salvar() const override;
    	void carregar(istringstream& dados) override;*/
		
	protected:
		
	private: 
	string autor;
	string universidade;
	string curso;
	int ano;
	string local;
	TipoConclusao tipo;
};

#endif
#ifndef TCC_H
#define TCC_H

class TCC
{
	public:
	protected:
};

#endif