#include <iostream>
#include <locale>
#include "Livro.h"
#include "TCC.h"
#include "Pessoa.h"
#include "Periodico.h"
#include "Relatorio.h"
#include "Midia.h"
#include "Mapa.h"
#include "Cartaz.h"
#include "Arquivo.h"
#include "Menu.h"

int main(int argc, char** argv) {
	setlocale(LC_ALL, "portuguese");
	system("chcp 1252 > nul");
	Menu menu;
	int m;
	
	vector<Item*> acervo= menu.carregaAcervo();
	cout<<"Bem vindo ao acervo da biblioteca!"<<endl;
	
	vector<Pessoa*> cadastro = menu.carregaCadastros();
	inicio:
	
	m =menu.inicial();
	string termoPesquisa;
	int itemPesquisa;
	Item *item;
	Pessoa *pessoa;
	
	switch (m){
		case 1:
			for (const auto& item : acervo){
				item->imprimeFichaTecnica();
			}
			
			break;
		case 2:
			acervo.push_back(menu.cadastraItem());
			cout <<"Item cadastrado!"<<endl;
			break;
		case 3:
			cadastro.push_back(menu.cadastraPessoa());
			cout <<"Usuario cadastrado!"<<endl;
			
			break;
		case 4:
				cout << "Digite o nome do arquivo: ";
				cin.ignore();
			    getline (cin, termoPesquisa);
				item=menu.pesquisaItem(acervo, termoPesquisa);
			if (item != NULL){
				item->imprimeFichaTecnica();
				cin.ignore();
				cout <<endl << "Digite CPF da pessoa que esta a pegar o item: ";
		    	getline (cin, termoPesquisa);
		    	pessoa = menu.pesquisaPessoa(cadastro, termoPesquisa);
		    	if (pessoa != NULL){
		    		cout << "Cadastro localizado: "<< pessoa->getNome() <<endl;
		    		item->setEmprestado(true);
		    		pessoa->pegaItem(item->getId());
		    		cout << "O Emprestimo de '" << item->getNome() <<"' foi realizado para " <<pessoa->getNome()<<" e deve ser devolvido daqui 2 semanas"<<endl;
				}
			}
			
			break;
		case 5:
			cout << "Insira o id do item a ser devolvido: ";
			cin >> itemPesquisa;
			item = menu.pesquisaItem(acervo, itemPesquisa);
			if (item != NULL){
				item->imprimeFichaTecnica();
				cout <<endl << "Digite CPF da pessoa que esta com o item: ";
		    	cin >> termoPesquisa;
		    	pessoa = menu.pesquisaPessoa(cadastro, termoPesquisa);
		    	if (pessoa!=NULL){
					cout << "Cadastro localizado: "<< pessoa->getNome() <<endl;
					if (pessoa->estaCom(item->getId())){
						pessoa->removeItem(item->getId());
						item->setEmprestado(false);
						cout <<"Devolucao realizada com sucesso" <<endl;
					}else {
						cout <<"Essa pessoa nao esta com o item indicado." <<endl;
					}
				}
			}
			
			
			break;
		case 6:
		    cout << "Digite o termo da pesquisa: ";
		    cin.ignore();
			getline (cin, termoPesquisa);
			menu.pesquisaGeral(acervo, termoPesquisa);
			break;		    
		case 7:
		    cout << "Digite o nome do arquivo: ";
		    cin.ignore();
			getline (cin, termoPesquisa);
			item=menu.pesquisaItem(acervo, termoPesquisa);
			if (item != NULL){
				item->imprimeFichaTecnica();
				cout <<endl << "Aperte 1 para Apagar Unidade, 2 para Apagar Item ou 0 para cancelar ";
		    	cin >> itemPesquisa;
		    	if (itemPesquisa==1){
		    		item->setQtd(item->getQtd()-1);
		    		cout <<"Unidade de item deletado do acervo!"<<endl;
				}else if (itemPesquisa == 0){
					break;	
				}else if(itemPesquisa == 2){
					delete(item);
					cout <<"Item removido do acervo!"<<endl;
				}else{
					cout<<"Valor invalido."<<endl;
		    		break;
				}
			}
			break;
		case 0:
			cout <<"Obrigado por acessar a biblioteca online!"<<endl;
			return 1;
			break;
		
	}
	system ("pause");
	system ("cls");
	goto inicio;
}

