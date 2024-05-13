package com.poo2.acervobiblioteca.itens;

import java.util.Scanner;

public class Cartaz extends Item{
    private String assunto;
    private String autor;

    public String getAssunto() {
        return assunto;
    }

    public void setAssunto(String assunto) {
        this.assunto = assunto;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    @Override
    public void imprimeFichaTecnica() {
        System.out.println("Cartaz:");
        super.imprimeFichaTecnica();
        System.out.printf("Assunto: %s\nAutor: %s\n", this.assunto, this.autor);
        System.out.println("============================================================================");
    }

    @Override
    public void cadastra() {
        Scanner scanner = new Scanner(System.in);
        super.cadastra();
        System.out.println("Insira o assunto:");
        this.assunto = scanner.nextLine();
        System.out.println("Insira o autor:");
        this.autor = scanner.nextLine();
        cadastraTags();
    }
}
