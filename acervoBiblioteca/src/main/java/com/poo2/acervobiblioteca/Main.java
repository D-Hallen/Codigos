/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.poo2.acervobiblioteca;

import com.poo2.acervobiblioteca.enums.TipoTCC;
import com.poo2.acervobiblioteca.itens.Item;
import com.poo2.acervobiblioteca.itens.TCC;

/**
 *
 * @author danie
 */
public class Main {

    public static void main(String[] args) {

        Item item = new Item();
        item.setNome("ABC");
        item.setEmprestado(true);
        item.setQtd(3);
        item.addTags("Mistério");
        item.addTags("Suspense");
        //item.imprimeFichaTecnica();

        TCC tcc =new TCC();
        /*tcc.setAno(2015);
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
        */
        tcc.cadastra();
        tcc.imprimeFichaTecnica();

    }
}
