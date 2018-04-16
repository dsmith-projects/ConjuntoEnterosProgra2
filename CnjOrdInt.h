/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CnjOrdInt.h
 * Author: davidsmith
 *
 * Created on March 18, 2018, 1:05 PM
 */

#ifndef CNJORDINT_H
#define CNJORDINT_H

#include <string>
#include <iostream>
#include <memory>

using namespace std;

class CnjOrdInt {
//Representa un conjunto ordenado de enteros
    
public:
    CnjOrdInt();
    CnjOrdInt(const CnjOrdInt& orig);
    virtual ~CnjOrdInt();
    
    //MOD: *this
    //EFE: si x no pertenece a *this, entonces lo agrega preservando el orden 
    //y retorna true, en caso contrario, no tiene efecto y retorna false
    bool insertarOrd(int x);
    
    //MOD: *this
    //EFE: si x no pertenece a *this, entonces lo elimina preservando el orden 
    //y retorna true, en caso contrario, no tiene efecto y retorna false
    bool eliminarOrd(int x);
    
    //EFE: retorna true si x pertenece a *this o false en caso contrario
    bool buscar (int x) const;
    
    //EFE: retorna un nuevo conjunto ordenado que representa la unión de *this con b
    CnjOrdInt operator+(const CnjOrdInt& b) const;
    
    //EFE: retorna un nuevo conjunto ordenado que representa la intersección de *this con b
    CnjOrdInt& operator*(const CnjOrdInt& b) const;
    
    //EFE: retorna un nuevo conjunto ordenado que representa la diferencia de *this con b
    CnjOrdInt operator-(const CnjOrdInt& b) const;
    
    //EFE: retorna un nuevo conjunto ordenado que representa la diferencia simétrica de *this con b
    CnjOrdInt operator/(const CnjOrdInt& b) const;
    
    //EFE: retorna una hilera que representa a *this
    string aHil();
private:
    
    struct NdoInt {
        int dato;
        shared_ptr<NdoInt> sgt;
        NdoInt(int x): dato(x), sgt(0){};
        ~NdoInt() {
            cout << "borrando: " << dato << endl;
        };
    };
    
    shared_ptr<NdoInt> inicio;
    static shared_ptr<CnjOrdInt> cnj_nvo_ptr;
};

#endif /* CNJORDINT_H */

