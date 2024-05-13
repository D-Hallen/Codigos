package com.poo2.acervobiblioteca.itens;

import java.util.Scanner;

public class Livro extends Item{
    private int edicao;
    private String editora;
    private String autor;
    private int numPags;
    private String ISBN = "NULL";

    public int getEdicao() {
        return edicao;
    }

    public void setEdicao(int edicao) {
        this.edicao = edicao;
    }

    public String getEditora() {
        return editora;
    }

    public void setEditora(String editora) {
        this.editora = editora;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public int getNumPags() {
        return numPags;
    }

    public void setNumPags(int numPags) {
        this.numPags = numPags;
    }

    public String getISBN() {
        return ISBN;
    }

    public void setISBN(String ISBN) {
        if (validarISBN(ISBN)){
            this.ISBN= ISBN;
        }else{
            System.out.println("O valor da ISBN dado nao e valido, por favor inserir um valor diferente");
        }
    }

    private boolean validarISBN(String isbn) {
        if (isbn.length() != 13) {
            return false; // ISBN-13 deve ter exatamente 13 dígitos
        }
        int soma = 0;
        for (int i = 0; i < 12; ++i) {
            int digito = isbn.charAt(i) - '0';

            // Alterna entre multiplicar por 1 e por 3
            soma += (i % 2 == 0) ? digito : 3 * digito;
        }

        int digitoVerificador = (10 - (soma % 10)) % 10;
        return (digitoVerificador == isbn.charAt(12) - '0');
    }

    @Override
    public void imprimeFichaTecnica() {
        System.out.printf("Livro:\nAutor:%s\n", this.autor);
        super.imprimeFichaTecnica();
        System.out.printf("Editora: %s, %dº edição, %d páginas\n", this.editora, this.edicao, this.numPags);
        System.out.printf("ISBN: %s\n", this.ISBN);
        System.out.println("============================================================================");

    }

    @Override
    public void cadastra() {
        super.cadastra();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Insira o autor:");
        this.autor= scanner.nextLine();
        System.out.println("Insira o número de páginas: ");
        this.numPags=scanner.nextInt();
        scanner= new Scanner(System.in);
        System.out.println("Insira a editora:");
        this.editora= scanner.nextLine();
        System.out.println("Insira a edição:");
        this.edicao= scanner.nextInt();
        while (this.ISBN == "NULL"){
            System.out.println("Insira o código ISBN:");
            setISBN(scanner.next());
        }
        cadastraTags();
    }
}
