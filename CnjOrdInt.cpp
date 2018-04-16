/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CnjOrdInt.cpp
 * Author: davidsmith
 * 
 * Created on March 18, 2018, 1:05 PM
 */

#include "CnjOrdInt.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

shared_ptr<CnjOrdInt> CnjOrdInt::cnj_nvo_ptr(nullptr);

CnjOrdInt::CnjOrdInt() : inicio(nullptr) {
}

CnjOrdInt::CnjOrdInt(const CnjOrdInt& orig) {
    shared_ptr<NdoInt> p = orig.inicio;
    if (p == nullptr)
        inicio = nullptr;
    else {
        inicio = shared_ptr<NdoInt>(new NdoInt(orig.inicio->dato));
        p = p->sgt;
        shared_ptr<NdoInt> ultimo = inicio;
        while(p != nullptr){
            ultimo->sgt = shared_ptr<NdoInt>(new NdoInt(p->dato));
            p = p->sgt;
            ultimo = ultimo->sgt;
        }
    }
        
}

CnjOrdInt::~CnjOrdInt() {
    /*shared_ptr<NdoInt> p = inicio;
    shared_ptr<NdoInt> q = nullptr;
    
    while(p != nullptr){
        q = p->sgt;
        //delete p;
        p = q;
    }
    */
}

bool CnjOrdInt::insertarOrd(int x) {
    bool rsl = false;
    shared_ptr<NdoInt> p = inicio;
    shared_ptr<NdoInt> ant = nullptr;
    
    if(inicio == nullptr){
        inicio = shared_ptr<NdoInt>(new NdoInt(x));
        rsl = true;
    }
    else if(inicio->dato > x){
        p = shared_ptr<NdoInt>(new NdoInt(x));
        p->sgt = inicio;
        inicio = p;   
        rsl = true;
    }
    else{
        p = inicio;
        
        while(p != nullptr){
            if(p->dato == x){
                p = nullptr;
            }
            else{
                if(p->dato < x){
                    ant = p;
                    p = p->sgt;
                    if(p == nullptr){
                        rsl = true;
                    }
                }
                else{
                    p = nullptr;
                    rsl = true;
                }
            }
        }
        
        if(rsl){
            p = ant->sgt;
            ant->sgt = shared_ptr<NdoInt>(new NdoInt(x));
            ant->sgt->sgt = p;
        }
    }
    
    return rsl;
}

bool CnjOrdInt::eliminarOrd(int x) {
    bool rsl = false;
    shared_ptr<NdoInt> p = inicio;
    shared_ptr<NdoInt> ant = nullptr;
    
    if(inicio != nullptr && inicio->dato <= x){
        if(inicio->dato == x){
            p = inicio->sgt;
            //delete inicio;
            inicio = p;
        }
        else{
            while(p != nullptr){
                if(p->dato == x){
                    rsl = true;
                    p = nullptr;
                }
                else{
                    if(p->dato < x){
                        ant = p;
                        p = p->sgt;
                    }
                    else{
                        p = nullptr;
                    }
                }
            }
            
            if(rsl){
                p = ant->sgt->sgt;
                //delete ant->sgt;
                ant->sgt = p;
            }
        }
    }
    
    return rsl;
}

bool CnjOrdInt::buscar(int x) const {
    bool rsl = false;
    
    shared_ptr<NdoInt> p = inicio;
    
    while(p != nullptr){
        if(p->dato == x){
            rsl = true;
            p = nullptr;
        }
        else{
            if(p->dato < x){
                p = p->sgt;
            }
            else{
                p = nullptr;
            }
        }
    }
    
    return rsl;
}

CnjOrdInt CnjOrdInt::operator+(const CnjOrdInt& b) const {

}

CnjOrdInt& CnjOrdInt::operator*(const CnjOrdInt& b) const {
    if(cnj_nvo_ptr != nullptr){
        cnj_nvo_ptr.reset();
    }
    cnj_nvo_ptr = shared_ptr<CnjOrdInt>(new CnjOrdInt());
    
    CnjOrdInt& cnj_nvo = *cnj_nvo_ptr;
    
    shared_ptr<NdoInt> p, q, ultimo;
    p = inicio;
    q = b.inicio;
    ultimo = nullptr;
    
    //algoritmo de matching
    
    while((p != nullptr) && (q != nullptr)){
        if(p->dato < q->dato){
            p = p->sgt;
        }
        else if(q->dato < p->dato){
            q = q->sgt;
        }
        else{
            if(ultimo == nullptr){
                cnj_nvo.inicio = shared_ptr<NdoInt>(new NdoInt(p->dato));
                ultimo = cnj_nvo.inicio;
            }
            else{
                ultimo->sgt = shared_ptr<NdoInt>(new NdoInt(p->dato));
                ultimo = ultimo->sgt;
            }
            p = p->sgt;
            q = q->sgt;
        }
    }
    
    return cnj_nvo;
}

CnjOrdInt CnjOrdInt::operator-(const CnjOrdInt& b) const {

}

CnjOrdInt CnjOrdInt::operator/(const CnjOrdInt& b) const {

}

string CnjOrdInt::aHil() {
    stringstream fs;
    shared_ptr<NdoInt> p = inicio;
    
    fs << '{';
    
    while(p != nullptr){
        fs << p->dato;
        p = p->sgt;
        if(p != nullptr) {
            fs << ',';
        }
    }
    
    fs << '}';
    
    return fs.str();
}