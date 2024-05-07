#include "Arquivo.h"
#include "Livro.h"
#include "TCC.h"
#include <fstream>


void Arquivo::salvarItens(const string& nomeArquivo, const vector<Item*>& itens) {
	ofstream arq;
	arq.open("ContaPoupanca.txt", ios::trunc);
    if (!arq.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para salvar.\n";
        return;
    }
	
    for (Item* item : itens) {
        
    }
	
    arq.close();
}
/*vector<Item*> Arquivo::carregarItens(const string& nomeArquivo) {
    vector<Item*> itens;
    ifstream arquivo("itens.txt");
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo para carregar.\n";
        return itens;
    }

    stringstream buffer;
    buffer << arquivo.rdbuf();
    string conteudoArquivo = buffer.str(); //recebe todo conteudo do arquivo

    arquivo.close();

    istringstream linhasStream(conteudoArquivo);
    string linha;
    while (getline(linhasStream, linha)) {
         if (linha.find("TipoItem: 1") != string::npos) {
            Livro* livro = new Livro();
            livro->carregar(linhasStream);
            std::getline(linhasStream, linha); // Pula a linha vazia
            livro->carregar(linhasStream); // Função para carregar atributos específicos de Livro
            itens.push_back(livro);
        } else if (linha.find("TipoItem: 2") != string::npos) {
            TCC* tcc = new TCC();
            tcc->carregar(linhasStream);
            std::getline(linhasStream, linha); // Pula a linha vazia
            tcc->carregar(linhasStream); // Função para carregar atributos específicos de TCC
            itens.push_back(tcc);
        } else {
            cerr << "Tipo de item desconhecido.\n";
        }
    }

    return itens;
}*/