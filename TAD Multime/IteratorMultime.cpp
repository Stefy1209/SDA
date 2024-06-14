//
// Created by stefy0-0 on 10.03.2024.
//

#include "IteratorMultime.h"
#include "Multime.h"

IteratorMultime::IteratorMultime(const Multime& m): mult(m) {
    cursor = mult.vector;
}

TElem IteratorMultime::element() const
/// \Complexity TETA(1)
{
    if(not valid())
        throw ("Elementul nu poate fi accesat");
    return *cursor;
}

bool IteratorMultime::valid() const
/// \Complexity TETA(1)
{
    return (mult.vector <= cursor) and (cursor - mult.vector < mult.size);
}

void IteratorMultime::urmator()
/// \Complexity TETA(1)
{
    ++cursor;
    //if(cursor - mult.vector == mult.size )
        //throw ("Cursorul a iesit din multime");
}

void IteratorMultime::anterior()
/// \Complexity TETA(1)
/*  Pseudocod:
 *
 *  anterior():
 *  |   cursor <- cursor - 1
 *  sfarsit anterior
 */
{
    --cursor;
    //if(cursor == mult.vector - 1)
        //throw ("Cursorul a iesit din multime");
}

void IteratorMultime::prim()
/// \Complexity TETA(1)
{
    cursor = mult.vector;
}