//
// Created by stefy0-0 on 10.03.2024.
//

#ifndef TAD_MULTIME_ITERATORMULTIME_H
#define TAD_MULTIME_ITERATORMULTIME_H

#pragma once
#include "Multime.h"

typedef int TElem;

class IteratorMultime
{
    friend class Multime;

private:

    //constructorul primeste o referinta catre Container
    //iteratorul va referi primul element din container
    IteratorMultime(const Multime& m);

    //contine o referinta catre containerul pe care il itereaza
    const Multime& mult;

    TElem * cursor;

public:

    //reseteaza pozitia iteratorului la inceputul containerului
    void prim();

    //muta iteratorul in container
    // arunca exceptie daca iteratorul nu e valid
    void urmator();

    //modifică elementul curent referit de iterator ca fiind elementul anterior din mulțime, sau, în cazul în care elementul curent a fost primul, transformă iteratorul în unul nevalid
    // aruncă excepție în cazul în care iteratorul nu este valid
    void anterior();

    //verifica daca iteratorul e valid (indica un element al containerului)
    bool valid() const;

    //returneaza valoarea elementului din container referit de iterator
    //arunca exceptie daca iteratorul nu e valid
    TElem element() const;
};


#endif //TAD_MULTIME_ITERATORMULTIME_H
