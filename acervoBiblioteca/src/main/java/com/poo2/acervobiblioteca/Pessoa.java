package com.poo2.acervobiblioteca;

import java.util.ArrayList;

public class Pessoa {
    private String nome;
    private String cpf;
    private String dataNascimento;
    private ArrayList<Integer> itensPegos;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getDataNascimento() {
        return dataNascimento;
    }

    public void setDataNascimento(String dataNascimento) {
        this.dataNascimento = dataNascimento;
    }

    public ArrayList<Integer> getItensPegos() {
        return itensPegos;
    }

    public boolean estaCom (int itemId){
        for (int i: this.itensPegos){
            if (i == itemId){
                return true;
            }
        }
        return false;
    }
    public void pegaItem (int itemId){
        itensPegos.add(itemId);
    }

    public void removeItem (int itemId){
        for (int i: this.itensPegos){
            if (itensPegos.get(i) == itemId){
                itensPegos.remove(i);
                return;
            }
        }

    }


}
