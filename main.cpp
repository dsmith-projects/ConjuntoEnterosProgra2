/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: davidsmith
 *
 * Created on March 18, 2018, 1:02 PM
 */

#include <cstdlib>
#include <iostream>
#include <memory>
#include "CnjOrdInt.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //cout << "Hola David" << endl;
    /*CnjOrdInt a, b; // a = {1, 2, 3} y b = {10, 11, 13}
    
    a.insertarOrd(1);
    a.insertarOrd(2);
    a.insertarOrd(3);
    
    cout << a.aHil() << endl;
    
    b.insertarOrd(10);
    b.insertarOrd(11);
    b.insertarOrd(13);
    
    cout << b.aHil() << endl;
    
    shared_ptr<CnjOrdInt> e (new CnjOrdInt());
    e->insertarOrd(12);
    e->insertarOrd(9);
    e->insertarOrd(6);
    //delete e;
    
    //CnjOrdInt c = a + b; // une a con b igual {1, 2, 3, 10, 11, 13}
    //CnjOrdInt d = a / b; // construye la diferecnia sim�trica entre a y b
    
    //c.insertarOrd(5);
    */
    
    CnjOrdInt a, b; // a = {1, 2, 3} y b = {10, 11, 13}
    
    a.insertarOrd(4);
    a.insertarOrd(9);
    a.insertarOrd(15);
    a.insertarOrd(18);
    a.insertarOrd(13);
    
    cout << "A: " << a.aHil() << endl;
    
    b.insertarOrd(7);
    b.insertarOrd(8);
    b.insertarOrd(9);
    b.insertarOrd(10);
    b.insertarOrd(11);
    b.insertarOrd(15);
    b.insertarOrd(17);
    
    cout << "B: " << b.aHil() << endl;
    
    CnjOrdInt c = a*b;
    cout << "C: " << c.aHil() << endl;
    
    return 0;
}