#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>
#include <vector>

#include <exception>
using namespace std;

///Teta(1)
MDO::MDO(Relatie r) {
    /* de adaugat */
    relation = r;
    length = 0;
    capacity = 1;
    start = NULL_Position;
    first_free = 0;
    e = new TElem [capacity];
    next = new long long [capacity];

    for(size_t i = 0; i < capacity; ++i) {
        e[i].first = NULL_TCheie;
        next[i] = NULL_Position;
    }
}

/// Best Case: Teta(1)
/// Worst Case: Teta(capacity)
/// Average Case: O(capacity)
void MDO::adauga(TCheie c, TValoare v) {
    /* de adaugat */
    if(length == capacity) {
        TElem * aux_e = e;
        long long * aux_next = next;

        capacity *= 2;

        e = new TElem [capacity];
        next = new long long [capacity];

        for(size_t i = 0; i < capacity/2; ++i) {
            e[i] = aux_e[i];
            next[i] = aux_next[i];
        }
        for(size_t i = capacity/2; i < capacity; ++i) {
            e[i].first = NULL_TCheie;
            next[i] = NULL_Position;
        }

        first_free = length;

        delete [] aux_e;
        delete [] aux_next;
    }

    long long it = start;
    long long pred = NULL_Position;
    while(it != NULL_Position and relation(e[it].first, c) and e[it].first != c) {
        pred = it;
        it = next[it];
    }

    e[first_free].first = c;
    e[first_free].second = v;
    if(pred == NULL_Position) {
        next[first_free] = start;
        start = first_free;
    }
    else {
        next[pred] = first_free;
        next[first_free] = it;
    }

    ++length;

    if(length == capacity) {
        first_free = NULL_Position;
    }
    else {
        while(e[first_free].first != NULL_TCheie) {
            first_free++;
        }
    }
}

/// Best case: Teta(1)
/// Worst case: Teta(length)
/// Average case: O(length)
vector<TValoare> MDO::cauta(TCheie c) const {
    /* de adaugat */
    vector<TValoare> values;

    long long current = start;
    while(current != NULL_Position and relation(e[current].first, c) and c != e[current].first) {
        current = next[current];
    }
    while(current != NULL_Position and c == e[current].first) {
        values.push_back(e[current].second);
        current = next[current];
    }
    return values;
}

/// Best case: Teta(1)
/// Worst case: Teta(length)
/// Average Case: O(length)
bool MDO::sterge(TCheie c, TValoare v) {
    /* de adaugat */
    long long current = start;
    long long pred = NULL_Position;
    while(current != NULL_Position and relation(e[current].first, c) and (c != e[current].first or v != e[current].second)) {
        pred = current;
        current = next[current];
    }
    if(current != NULL_Position and c == e[current].first and v == e[current].second) {
        if(current == start) {
            start = next[current];
        }
        else {
            next[pred] = next[current];
        }

        e[current].first = NULL_TCheie;
        next[current] = NULL_Position;
        if(current < first_free)
            first_free = current;
        --length;
        return true;
    }
    return false;
}

/// Teta(1)
int MDO::dim() const {
    /* de adaugat */
    return length;
}

/// Teta(1)
bool MDO::vid() const {
    /* de adaugat */
    return length == 0;
}

/// Teta(1)
IteratorMDO MDO::iterator() const {
    return IteratorMDO(*this);
}

/// Teta(1)
MDO::~MDO() {
    /* de adaugat */
    delete [] e;
    delete [] next;
    start = NULL_Position;
    length = 0;
    capacity = 0;
}

/// Teta(length)
void MDO::goleste() {
    int p = start, aux;
    while(p != NULL_Position) {
        e[p].first = NULL_TCheie;
        aux = p;
        p = next[p];
        next[aux] = NULL_Position;
    }
    length = 0;
    start = NULL_Position;
    first_free = 0;
}

/*
 *  Pseudocod GOLESTE:
 *
 *  Precconditii: d - MDO
 *  Postconditii: d - MDO vid
 *
 *  GOLESTE(d - input/output):
 *      p <- d.start
 *
 *      cat timp p != NULL_Position, executa:
 *          d.e[p].cheie/first <- NULL_TCheie
 *          aux <- p
 *          p <- d.next[p]
 *          d.next[aux] <- NULL_Position
 *      sf. cat timp
 *
 *      d.length <- 0
 *      d.start <- NULL_Position
 *      d.first_free <- 0
 *  sf. GOLESTE
 */
