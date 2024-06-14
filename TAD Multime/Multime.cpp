//
// Created by stefy0-0 on 10.03.2024.
//

#include "Multime.h"
#include "IteratorMultime.h"
#include <cstdlib>

using namespace std;

bool rel(TElem e1, TElem e2)
/// verifica relatia de ordine
/// \param e1 - TElem
/// \param e2 - TElem
/// \return bool
/// \pre e1 - TElem
/// \pre e2 - TElem
/// \post TRUE - daca are loc relatia de ordine
/// \post FALSE - in caz contrar
/// \Complexity TETA(1)
{
    return e1 <= e2;
}

Multime::Multime()
/// creaza MULTIME
/// \Complexity TETA(1)
{
    vector = (TElem *)malloc(sizeof(TElem));
    size = 0;
    capacity = 1;
}

bool Multime::adauga(TElem elem)
/// adauaga element in multime
/// \param elem - TElem
/// \return TRUE - daca a reusit sa adauge elem in MULTIME
/// \return FALSE - daca nu a reusit sa adauge elem in MULTIME sau deja se afla in ea
/// \pre elem - TElem
/// \post MULTIME = MULTIME + {elem}, daca elem nu se afla in MULTIME
/// \post MULTIME = MULTIME, daca elem deja se afla in MULTIME
/// \Complexity Best Case: TETA(1)
/// \Complexity Worst Case: TETA(log(N) + N) (cushion)
/// \Complexity Average Case: O(long(N) + N) (cushion)
{
    if(size == capacity) {
        TElem * ptr_aux;

        capacity *= 2;
        ptr_aux = (TElem *)realloc(vector, capacity * sizeof(TElem));

        if(ptr_aux == nullptr)
            return false;

        vector = ptr_aux;
    }

    if(size == 0 or (rel(vector[size - 1], elem) and vector[size - 1] != elem)) {
        vector[size++] = elem;
        return true;
    }

    if(rel(elem, vector[0]) and elem != vector[0]) {
        for(size_t i = size; i > 0; --i)
            vector[i] = vector[i - 1];

        vector[0] = elem;
        ++size;
        return true;
    }

    size_t left, right, mid;
    left = 0;
    right = size - 1;

    do {
        mid = left + ((right - left) / 2);

        if(vector[mid] == elem)
            return false;

        if(rel(elem, vector[mid]))
            right = mid - 1;

        else left = mid + 1;
    } while (left <= right);

    for(size_t i = size; i > left; --i)
        vector[i] = vector[i - 1];

    vector[left] = elem;
    ++size;
    return true;
}

bool Multime::sterge(TElem elem)
/// \Complexity Best Case: TETA(1)
/// \Complexity Worst Case: TETA(log N + N)
/// \Complexity Average Case: O(long N + N)
{
    if(size == 0)
        return false;

    if(rel(elem, vector[0]) and elem != vector[0])
        return false;

    if(rel(vector[size - 1], elem) and vector[size - 1] != elem)
        return false;

    size_t left, right, mid;
    left = 0;
    right = size - 1;

    do {
        mid = left + ((right - left) / 2);

        if(vector[mid] == elem) {
            for(size_t i = mid + 1; i < size; ++i)
                vector[i - 1] = vector[i];

            --size;
            return true;
        }

        if(rel(elem, vector[mid]))
            right = mid - 1;
        else left = mid + 1;
    } while (left <= right);

    return false;
}

bool Multime::cauta(TElem elem) const
/// \Complexity Best Case: TETA(1)
/// \Complexity Worst Case: TETA(long N)
/// \Complexity Average Case: O(long N)
{
    if(size == 0)
        return false;

    if(rel(elem, vector[0]) and elem != vector[0])
        return false;

    if(rel(vector[size-1], elem) and vector[size - 1] != elem)
        return false;

    size_t left, right, mid;
    left = 0;
    right = size - 1;

    do {
        mid = left + ((right - left) / 2);

        if(vector[mid] == elem)
            return true;

        if(rel(elem, vector[mid]))
            right = mid - 1;

        else left = mid + 1;
    } while (left <= right);

    return false;
}

int Multime::dim() const
/// \Complexity TETA(1)
{
    return size;
}

bool Multime::vida() const
/// \Complexity TETA(1)
{
    return size == 0;
}

IteratorMultime Multime::iterator() const
/// \Complexity TETA(1)
{
    return IteratorMultime(*this);
}

Multime::~Multime()
/// \Comeplexity TETA(1)
{
    free(vector);
}