#pragma once

#include <iostream>

typedef int TElem;

#define NULL_TELEMENT 0

struct node {
    size_t line;
    size_t column;
    TElem element;
    node * next;
};

typedef node* Pnode;

class Matrice {

private:
    /* aici e reprezentarea */

    Pnode start;
    size_t max_number_lines;
    size_t max_number_columns;

    bool relation(Pnode & node1, Pnode & node2);
    bool valid(int line, int column);

    void addNode(Pnode & node);
    void deleteNode(const Pnode & node);
    Pnode findNode(int line, int column);
    void deletList(Pnode & start);
public:

    //constructor
    //se arunca exceptie daca nrLinii<=0 sau nrColoane<=0
    Matrice(int nrLinii, int nrColoane);


    //destructor
    ~Matrice();

    //returnare element de pe o linie si o coloana
    //se arunca exceptie daca (i,j) nu e pozitie valida in Matrice
    //indicii se considera incepand de la 0
    TElem element(int i, int j);


    // returnare numar linii
    int nrLinii() const;

    // returnare numar coloane
    int nrColoane() const;


    // modificare element de pe o linie si o coloana si returnarea vechii valori
    // se arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
    TElem modifica(int i, int j, TElem);

    // redimensionează o matrice la o anumită dimensiune. În cazul în care dimensiunile sunt mai mici decât dimensiunile actuale, elemente de pe pozițiile care nu mai sunt existente vor dispărea. În cazul în care dimensiunile sunt mai mari decât dimensiunile actuale, toate elementele noi (de pe poziții anterior inexistente) vor fi  NULL_TELEM.
    // aruncă excepție în cazul în care noile dimensiuni sunt negative.
    void redimensioneaza(int numarNouLinii, int numarNouColoane);
};