#include "Matrice.h"

#include <exception>

using std::runtime_error;

using namespace std;


Matrice::Matrice(int m, int n)
/// Average Case: TETA(1)
{
    /* de adaugat */
    if(m <= 0 or n <= 0) {
        throw runtime_error("Numarul de linii si coloane trebui sa fie MAI MARE ca 0\n");
    }

    start = nullptr;
    max_number_lines = m;
    max_number_columns = n;
}

int Matrice::nrLinii() const
/// Average Case: TETA(1)
{
    /* de adaugat */
    return max_number_lines;
}

int Matrice::nrColoane() const
/// Average Case: TETEA(1)
{
    /* de adaugat */
    return max_number_columns;
}

TElem Matrice::element(int i, int j)
/// Best Case: TETA(1)
/// Worst Case: TETA(n)
/// Average Case: O(n)
{
    /* de adaugat */
    if(not valid(i, j)) {
        throw runtime_error("Accesare pozitie invalida!!!\n");
    }

    Pnode node = findNode(i,j);
    TElem element = node->element;

    if(element == NULL_TELEMENT) {
        delete node;
    }

    return element;
}

TElem Matrice::modifica(int i, int j, TElem e)
/// Best Case: TETA(1)
/// Worst Case: TETA(n)
/// Average Case: O(n)
{
    /* de adaugat */
    if(not valid(i, j)) {
        throw runtime_error("Accesare pozitie invalida!!!\n");
    }

    Pnode node = findNode(i, j);
    TElem old_element = node->element;
    node->element = e;

    if(old_element == NULL_TELEMENT and e != NULL_TELEMENT) {
        addNode(node);
    }
    else if(old_element != NULL_TELEMENT and e == NULL_TELEMENT) {
        deleteNode(node);
    }
    else if(old_element == NULL_TELEMENT and e == NULL_TELEMENT) {
        delete node;
    }
    return old_element;
}

bool Matrice::relation(Pnode & node1, Pnode & node2)
/// Average Case: TETA(1)
{
    if(node1->line == node2->line)
        return node1->column < node2->column;
    return node1->line < node2->line;
}

bool Matrice::valid(int line, int column)
/// Average Case: TETA(1)
{
    return  -1 < line and line < max_number_lines and
            -1 < column and column < max_number_columns;
}

Pnode Matrice::findNode(int line, int column)
/// Best Case: TETA(1)
/// Worst case: TETA(n)
/// Average Case: O(n)
{
    Pnode curent = start;

    while(curent != nullptr) {
        if(curent->line > line)
            break;
        if(curent->line == line and curent->column > column)
            break;
        if(curent->line == line and curent->column == column) {
            return curent;
        }
        curent = curent->next;
    }

    Pnode new_node = new node;
    new_node->line = line;
    new_node->column = column;
    new_node->element = NULL_TELEMENT;
    new_node->next = nullptr;

    //addNode(new_node);

    return new_node;
}

void Matrice::addNode(Pnode &node)
/// Best Case: TETA(1)
/// Worst Case: TETA(n)
/// Average Case: O(n)
{
    Pnode curent = start, pred = nullptr;

    while (curent != nullptr and relation(curent, node)) {
        pred = curent;
        curent = curent->next;
    }

    if(pred == nullptr) {
        node->next = start;
        start = node;
        return;
    }

    pred->next = node;
    node->next = curent;
}

void Matrice::deleteNode(const Pnode &node)
/// Best Case: TETA(1)
/// Worst Case: TETA(n)
/// Average Case: O(n)
{
    Pnode curent = start, pred = nullptr;

    while (curent != nullptr and curent != node) {
        pred = curent;
        curent = curent->next;
    }

    if(curent == start) {
        pred = start;
        start = start->next;
        delete pred;

        return;
    }

    pred->next = curent->next;
    delete curent;
}

void Matrice::redimensioneaza(int numarNouLinii, int numarNouColoane)
/// Best Case: TETA(1)
/// Worst Case: TETA(n)
/// Average Case: O(n)
{
    if(numarNouLinii <= 0 or numarNouColoane <= 0)
        throw runtime_error("Numarul de linii si coloane trebuie sa fie mai mare ca 0");

    if(numarNouLinii >= max_number_lines and numarNouColoane >= max_number_columns) {
        max_number_lines = numarNouLinii;
        max_number_columns = numarNouColoane;
        return;
    }

    max_number_lines = numarNouLinii;
    max_number_columns = numarNouColoane;

    Pnode curent = start, pred = nullptr;
    while(curent != nullptr) {
        if(curent->line >= max_number_lines or curent->column >= max_number_columns) {
            if(pred == nullptr) // curent == start
            {
                curent = curent->next;
                deleteNode(start);
                start = curent;
            }
            else {
                curent = pred;
                deleteNode(curent->next);
            }
        }
        else {
            pred = curent;
            curent = curent->next;
        }
    }
}
/*
 *  preconditie: numarNouLinii > 0, numarNouColoane > 0, matrice - sa existe
 *  postconditie: matrice cu eventualele elemente sterse, max_number_lines = numarNouLinii, max_number_columns = numarNouColoane
 *  Subalgoritm redimensioneaza(numarNouLinii , numarNouColoane, matrice):
        daca numarNouLinii >= matrice.max_number_lines si numarNouColoane >= matrice.max_number_columns, atunci:
            matrice.max_number_lines <- numarNouLinii
            matrice.max_number_columns <- numarNouColoane
            sf.Program
        sf.daca

        matrice.max_number_lines <- numarNouLinii
        matrice.max_number_columns <- numarNouColoane

        curent <- matrice.start
        pred <- NIL

        cat timp curent != NIL, atunci:
            daca [curent].line >= matrice.max_number_lines sau [curent].column >= matrice.max_number_columns, atunci:
                daca pred == NIL, atunci:
                    curent <- [curent].next
                    deleteNode(start)
                    start <- curent
                altfel:
                    curent <- pred
                    deleteNode([curent].next)
                sf.daca
            altfel:
                pred <- curent
                curent <- [curent].next
            sf.daca
        sf.cat timp
    sf.Subalgoritm
 */

void Matrice::deletList(Pnode &start)
/// Average Case: TETA(n)
{
    if(start != nullptr) {
        deletList(start->next);
        delete start;
    }
}

Matrice::~Matrice()
/// Average Case: TETA(n)
{
    deletList(start);
}