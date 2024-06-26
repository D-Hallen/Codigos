package com.poo2.acervobiblioteca.itens;

import java.util.ArrayList;
import java.util.Scanner;

public class Item {
    protected String nome;
    protected int id;
    protected boolean emprestado;
    protected int qtd;
    protected ArrayList<String> tags;

    private static int contador;

    public Item() {
        this.id = ++contador;
        this.emprestado= false;
        this.qtd = 0;
        this.tags = new ArrayList<>();
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getId() {
        return id;
    }

    public boolean isEmprestado() {
        return emprestado;
    }

    public void setEmprestado(boolean emprestado) {
        this.emprestado = emprestado;
    }

    public int getQtd() {
        return qtd;
    }

    public void setQtd(int qtd) {
        this.qtd = qtd;
    }

    public ArrayList<String> getTags() {
        return tags;
    }

    public void addTags(String tag) {
        this.tags.add(tag);
    }

    public void imprimeFichaTecnica(){
        System.out.printf("Nome: %s\nID: %d\nQuantidade: %d\nTags: ", this.nome, this.id, this.qtd);
        for (String tag : this.tags) {
            System.out.print(tag + " - ");
        }
        System.out.println();
    }

    public void cadastra(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Insira o nome:");
        this.nome = scanner.nextLine();
        System.out.println("Qual a quantidade?");
        this.qtd = scanner.nextInt();
    }

    protected void cadastraTags(){
        String tag = "";
        Scanner scanner= new Scanner(System.in);
        do{
            System.out.println("Insira uma tag (Ou digite 'sair' para encerrar)");
            tag = scanner.nextLine();
            if (!tag.equals("sair")){
                this.addTags(tag);
            }
        }while (!tag.equals("sair"));
    }
}
