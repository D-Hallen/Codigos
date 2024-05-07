/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.poo2.acervobiblioteca;

import com.poo2.acervobiblioteca.itens.Item;

/**
 *
 * @author danie
 */
public class AcervoBiblioteca {

    public static void main(String[] args) {
        System.out.println("Hello World!");
        Item item = new Item();
        item.setNome("ABC");
        item.setEmprestado(true);
        item.setQtd(3);
        item.addTags("Mistério");
        item.imprimeFichaTecnica();
    }
}
