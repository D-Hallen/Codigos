package com.poo2.acervobiblioteca.itens;

import com.poo2.acervobiblioteca.enums.TipoTCC;

import java.util.ArrayList;
import java.util.Scanner;

public class TCC extends Item {
    private String autor;
    private String universidade;
    private String curso;
    private int ano;
    private String local;
    private TipoTCC tipo;

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public String getUniversidade() {
        return universidade;
    }

    public void setUniversidade(String universidade) {
        this.universidade = universidade;
    }

    public String getCurso() {
        return curso;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public String getLocal() {
        return local;
    }

    public void setLocal(String local) {
        this.local = local;
    }

    public TipoTCC getTipo() {
        return tipo;
    }

    public void setTipo(TipoTCC tipo) {
        this.tipo = tipo;
    }

    @Override
    public void imprimeFichaTecnica() {
        System.out.println("TCC:");
        super.imprimeFichaTecnica();
        System.out.printf("Autor: %s\nUniversidade: %s \nCurso: %s \nano: %d \nLocal: %s \nTipo: %s",
                this.autor, this.universidade, this.curso, this.ano, this.local, this.tipo.toString().toLowerCase());
        System.out.println();
        System.out.println("============================================================================");
    }

    @Override
    public void cadastra() {
        super.cadastra();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Insira o autor:");
        this.autor= scanner.nextLine();
        System.out.println("Insira o curso:");
        this.curso = scanner.nextLine();
        System.out.println("Insira a universidade:");
        this.universidade = scanner.nextLine();
        scanner= new Scanner(System.in); //dando uma resetada no scanner
        System.out.println("Insira o ano: ");
        this.ano=scanner.nextInt();
        System.out.println("Insira o local: ");
        this.local= scanner.next();

        int i= -1;
        do {
            System.out.println("Insira o tipo de TCC\n" +
                    "1- Monografia, 2- Dissertação, 3- Tese");
            i = scanner.nextInt();
            if (i>3 || i<1){
                System.out.println("Valor indisponível, favor escolher um valor válido\n");
            }
            switch (i){
                case 1:
                    this.tipo = TipoTCC.MONOGRAFIA;
                    break;
                case 2:
                    this.tipo = TipoTCC.DISSERTACAO;
                    break;
                case 3:
                    this.tipo = TipoTCC.TESE;
                    break;
            }
        } while (i>3 || i<1);
        cadastraTags();

        }


}
