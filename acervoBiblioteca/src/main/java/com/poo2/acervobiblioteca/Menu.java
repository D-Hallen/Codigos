package com.poo2.acervobiblioteca;

import com.poo2.acervobiblioteca.itens.*;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Menu {

    public int inicial() {
        Scanner input = new Scanner(System.in);

        while (true) {
            System.out.println("\nOpções Disponíveis:");
            System.out.println("  1- Ver acervo");
            System.out.println("  2- Adicionar item ao acervo");
            System.out.println("  3- Cadastrar pessoa");
            System.out.println("  4- Pegar item emprestado");
            System.out.println("  5- Devolver item emprestado");
            System.out.println("  6- Fazer pesquisa no acervo");
            System.out.println("  7- Deletar item do acervo");
            System.out.println("  0- Sair da biblioteca");
            System.out.print("=> ");

            int m = input.nextInt();
            input.nextLine(); // Consumir a quebra de linha pendente

            if (m >= 0 && m <= 7) {
                return m;
            } else {
                System.out.println("Erro: Valor colocado inválido");
            }
        }
    }

    public void pesquisaGeral(List<Item> acervo, String termoPesquisa) {
        List<Item> resultados = new ArrayList<>();
        for (Item item : acervo) { // procura no nome
            if (item.getNome().contains(termoPesquisa)) {
                resultados.add(item);
                continue;
            }
            for (String tag : item.getTags()) { // procura nas tags
                if (tag.contains(termoPesquisa)) {
                    resultados.add(item);
                    break;
                }
            }
        }
        for (int i = 0; i < resultados.size(); ++i) { // imprime resultados
            System.out.print((i + 1) + ". ");
            resultados.get(i).imprimeFichaTecnica();
            System.out.println();
        }
        if (resultados.isEmpty()) {
            System.out.println("Termo não encontrado no acervo!");
        }
    }

    public Item pesquisaItem(List<Item> acervo, String termoPesquisa) {
        Scanner input = new Scanner(System.in);
        List<Item> resultados = new ArrayList<>();

        // Busca por itens que contenham o termo de pesquisa no nome
        for (Item item : acervo) {
            if (item.getNome().contains(termoPesquisa)) {
                resultados.add(item);
            }
        }

        // Caso nenhum resultado seja encontrado
        if (resultados.isEmpty()) {
            System.out.println("Item desconhecido.");
            return null;
        }
        // Caso haja apenas um resultado, retorna o item
        else if (resultados.size() == 1) {
            return resultados.get(0);
        }
        // Caso haja mais de um resultado, imprime a lista de itens e pede para escolher
        else {
            System.out.println("Encontrados vários itens com o termo de pesquisa:");
            for (int i = 0; i < resultados.size(); i++) {
                System.out.println((i + 1) + ". " + resultados.get(i).getNome());
            }

            System.out.print("Escolha um número para visualizar a ficha técnica do item correspondente: ");
            int escolha = input.nextInt();

            if (escolha > 0 && escolha <= resultados.size()) {
                return resultados.get(escolha - 1);
            } else {
                System.out.println("Escolha inválida.");
                return null;
            }
        }
    }

    public Item pesquisaItem(List<Item> acervo, int idPesquisa) {
        List<Item> resultados = new ArrayList<>();

        // Busca por itens que contenham o ID de pesquisa
        for (Item item : acervo) {
            if (item.getId() == idPesquisa) {
                resultados.add(item);
            }
        }

        Scanner input = new Scanner(System.in);

        // Caso nenhum resultado seja encontrado
        if (resultados.isEmpty()) {
            System.out.println("Item desconhecido.");
            return null;
            // Caso haja apenas um resultado, retorna o item
        } else if (resultados.size() == 1) {
            return resultados.get(0);
            // Caso haja mais de um resultado, imprime a lista e pede para escolher
        } else {
            System.out.println("Encontrados vários itens com o ID de pesquisa:");
            for (int i = 0; i < resultados.size(); ++i) {
                System.out.println((i + 1) + ". " + resultados.get(i).getNome());
            }

            System.out.print("Escolha um número para visualizar a ficha técnica do item correspondente: ");
            int escolha = input.nextInt();

            if (escolha > 0 && escolha <= resultados.size()) {
                return resultados.get(escolha - 1);
            } else {
                System.out.println("Escolha inválida.");
                return null;
            }
        }
    }

    public Pessoa cadastraPessoa() {
        Scanner input = new Scanner(System.in);
        Pessoa p = new Pessoa();

        System.out.println("Insira o nome do usuario:");
        String nome = input.nextLine();

        System.out.println("Insira a data de Nascimento:");
        String dNasc = input.nextLine();

        System.out.println("Insira o CPF:");
        String cpf = input.nextLine();

        p.setNome(nome);
        p.setDataNascimento(dNasc);
        p.setCpf(cpf);

        return p;
    }

    public Pessoa pesquisaPessoa(List<Pessoa> cadastros, String CPF) {
        for (Pessoa pessoa : cadastros) {
            if (pessoa.getCpf().contains(CPF)) {
                return pessoa;
            }
        }
        System.out.println("Cadastro não localizado");
        return null;
    }

    public Item cadastraItem() {
        Scanner input = new Scanner(System.in);

        while (true) {
            System.out.println("Lista de itens disponível:");
            System.out.println("1 - Cartaz");
            System.out.println("2 - Livro");
            System.out.println("3 - Mídia");
            System.out.println("4 - Mapa");
            System.out.println("5 - Periódico");
            System.out.println("6 - Relatório");
            System.out.println("7 - TCC");
            System.out.print("=> ");

            int m = input.nextInt();

            if (m >= 1 && m <= 7) {
                switch (m) {
                    case 1:
                        Cartaz c = new Cartaz();
                        c.cadastra();
                        return c;
                    case 2:
                        Livro l = new Livro();
                        l.cadastra();
                        return l;
                    case 3:
                        /*Midia mi = new Midia();
                        mi.cadastra();
                        return mi;*/
                    case 4:
                        Mapa mp = new Mapa();
                        mp.cadastra();
                        return mp;
                    case 5:
                        /*Periodico p = new Periodico();
                        p.cadastra();
                        return p;*/
                    case 6:
                        /*Relatorio r = new Relatorio();
                        r.cadastra();
                        return r;*/
                    case 7:
                        TCC t = new TCC();
                        t.cadastra();
                        return t;
                }
            } else {
                System.out.println("Valor inválido!");
            }
        }
    }

}
