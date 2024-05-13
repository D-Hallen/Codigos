package com.poo2.acervobiblioteca.itens;

import java.util.Scanner;

public class Mapa extends Item{
    private String escala;
    private String local;

    public String getEscala() {
        return escala;
    }

    public void setEscala(String escala) {
        this.escala = escala;
    }

    public String getLocal() {
        return local;
    }

    public void setLocal(String local) {
        this.local = local;
    }

    @Override
    public void cadastra() {
        super.cadastra();
        Scanner scanner =new Scanner(System.in);
        System.out.println("Insira o local:");
        this.local= scanner.nextLine();
        System.out.println("Insira a escala:");
        this.escala = scanner.nextLine();
        cadastraTags();
    }

    @Override
    public void imprimeFichaTecnica() {
        System.out.println("Mapa:");
        super.imprimeFichaTecnica();
        System.out.printf("Local: %s\nEscala: %s\n", this.local, this.escala);
        System.out.println("============================================================================");
    }
}

