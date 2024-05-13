/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.poo2.acervobiblioteca;

import com.poo2.acervobiblioteca.enums.TipoTCC;
import com.poo2.acervobiblioteca.itens.*;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author danie
 */
public class Main {

    public static void main(String[] args) {
        Menu menu = new Menu();
        System.out.println("Bem-Vindo(a) ao acervo da Biblioteca!");
        int m= -1;
        String termoPesquisa;
        Item item;
        int itemPesquisa;
        Pessoa pessoa;
        ArrayList<Item> acervo= new ArrayList<>();
        ArrayList<Pessoa> cadastro = new ArrayList<>();
        Scanner input = new Scanner(System.in);



        while (m != 0){
            m = menu.inicial();
            switch (m) {
                case 1:
                    for (Item i : acervo) {
                        i.imprimeFichaTecnica();
                    }
                    break;
                case 2:
                    acervo.add(menu.cadastraItem());
                    System.out.println("Item cadastrado!");
                    break;
                case 3:
                    cadastro.add(menu.cadastraPessoa());
                    System.out.println("Usuário cadastrado!");
                    break;
                case 4:
                    System.out.print("Digite o nome do item: ");
                    input.nextLine(); // Limpar o buffer
                    termoPesquisa = input.nextLine();
                    item = menu.pesquisaItem(acervo, termoPesquisa);
                    if (item != null) {
                        item.imprimeFichaTecnica();
                        System.out.print("\nDigite o CPF da pessoa que está pegando o item: ");
                        termoPesquisa = input.nextLine();
                        pessoa = menu.pesquisaPessoa(cadastro, termoPesquisa);
                        if (pessoa != null) {
                            System.out.println("Cadastro localizado: " + pessoa.getNome());
                            item.setEmprestado(true);
                            pessoa.pegaItem(item.getId());
                            System.out.println("O empréstimo de '" + item.getNome() + "' foi realizado para " + pessoa.getNome() + " e deve ser devolvido daqui 2 semanas");
                        }
                    }
                    break;
                case 5:
                    System.out.print("Insira o ID do item a ser devolvido: ");
                    itemPesquisa = input.nextInt();
                    item = menu.pesquisaItem(acervo, itemPesquisa);
                    if (item != null) {
                        item.imprimeFichaTecnica();
                        System.out.print("\nDigite o CPF da pessoa que está com o item: ");
                        input.nextLine(); // Limpar o buffer
                        termoPesquisa = input.nextLine();
                        pessoa = menu.pesquisaPessoa(cadastro, termoPesquisa);
                        if (pessoa != null) {
                            System.out.println("Cadastro localizado: " + pessoa.getNome());
                            if (pessoa.estaCom(item.getId())) {
                                pessoa.removeItem(item.getId());
                                item.setEmprestado(false);
                                System.out.println("Devolução realizada com sucesso");
                            } else {
                                System.out.println("Essa pessoa não está com o item indicado.");
                            }
                        }
                    }
                    break;
                case 6:
                    System.out.print("Digite o termo da pesquisa: ");
                    input.nextLine(); // Limpar o buffer
                    termoPesquisa = input.nextLine();
                    menu.pesquisaGeral(acervo, termoPesquisa);
                    break;
                case 7:
                    System.out.print("Digite o nome do item: ");
                    input.nextLine(); // Limpar o buffer
                    termoPesquisa = input.nextLine();
                    item = menu.pesquisaItem(acervo, termoPesquisa);
                    if (item != null) {
                        item.imprimeFichaTecnica();
                        System.out.print("\nAperte 1 para apagar unidade, 2 para apagar item ou 0 para cancelar: ");
                        itemPesquisa = input.nextInt();
                        if (itemPesquisa == 1) {
                            item.setQtd(item.getQtd() - 1);
                            System.out.println("Unidade de item deletada do acervo!");
                        } else if (itemPesquisa == 2) {
                            acervo.remove(item);
                            System.out.println("Item removido do acervo!");
                        } else if (itemPesquisa != 0) {
                            System.out.println("Valor inválido.");
                        }
                    }
                    break;
                case 0:
                    m = 0;
                    System.out.println("Obrigado por acessar a biblioteca online!");
                    return;
            }
        }
        //////////////////////////////////////////////////////////////////////

        /*TCC tcc =new TCC();
        tcc.setAno(2015);
        tcc.setAutor("Daniel");
        tcc.setCurso("Eng Comp");
        tcc.setTipo(TipoTCC.MONOGRAFIA);
        tcc.setLocal("Divinopolis");
        tcc.setUniversidade("UEMG");
        tcc.setEmprestado(false);
        tcc.setNome("Conhecendo Java");
        tcc.setQtd(5);
        tcc.addTags("Monografia");
        tcc.addTags("Engenharia");
        tcc.addTags("Técnologia");

        //tcc.cadastra();
        tcc.imprimeFichaTecnica();

        Livro livro = new Livro();
        livro.setNome("Fahrenheit 451");
        livro.setQtd(20);
        livro.setAutor("Ray Bradbury");
        livro.setEdicao(2);
        livro.setEditora("Biblioteca Azul");
        livro.setNumPags(215);
        livro.setISBN("9788525052247");
        livro.addTags("Suspense");
        livro.addTags("Distopia");

        //livro.cadastra();
        livro.imprimeFichaTecnica();

        /*Cartaz cartaz = new Cartaz();
        cartaz.cadastra();
        cartaz.imprimeFichaTecnica();

        Mapa mapa = new Mapa();
        mapa.cadastra();
        mapa.imprimeFichaTecnica();*/
    }
}
