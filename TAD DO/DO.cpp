#include "Iterator.h"
#include "DO.h"
#include <iostream>

#include <exception>
using namespace std;

DO::DO(Relatie r) {
	/* de adaugat */
	m = 13;
	len = 0;
	R = r;

	for(auto &e:T)
		e = nullptr;
}

//adauga o pereche (cheie, valoare) in dictionar
//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
//daca nu exista cheia, adauga perechea si returneaza null
///Best Case: TETA(1)
///Worst Case: TETA(n)
///Average Case: O(n)
TValoare DO::adauga(TCheie c, TValoare v) {
	/* de adaugat */
	int h = d(c);

	Pnod curent = (Pnod)T[h], pred = nullptr;
	while(curent != nullptr and R(curent->e.first, c) and curent->e.first != c)
	{
		pred = curent;
		curent = curent->next;
	}

	if(curent == nullptr)
	{
		Pnod p = new nod;
		len++;
		p->e.first = c;
		p->e.second = v;
		p->next = nullptr;
		if(pred == nullptr)
		{
			T[h] = p;
		}
		else
		{
			pred->next = p;
		}
		return NULL_TVALOARE;
	}

	if(curent->e.first == c)
	{
		TCheie old = curent->e.second;
		curent->e.second = v;
		return old;
	}

	Pnod p = new nod;
	len++;
	p->e.first = c;
	p->e.second = v;
	p->next = curent;
	if(pred == nullptr)
	{
		T[h] = p;
	}
	else
	{
		pred->next = p;
	}
	return NULL_TVALOARE;
}

//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
///Best Case: TETA(1)
///Worst Case: TETA(n)
///Average Case: O(n)
TValoare DO::cauta(TCheie c) const {
	/* de adaugat */
	int h = d(c);

	Pnod curent = (Pnod)T[h];
	while(curent != nullptr and R(curent->e.first, c))
	{
		if(curent->e.first == c)
			return  curent->e.second;
		curent = curent->next;
	}
	return NULL_TVALOARE;	
}

//sterge o cheie si returneaza valoarea asociata (daca exista) sau null
///Best Case: TETA(1)
///Worst Case: TETA(n)
///Average Case: O(n)
TValoare DO::sterge(TCheie c) {
	/* de adaugat */
	int h = d(c);

	Pnod curent = (Pnod)T[h], pred = nullptr;
	while(curent != nullptr and R(curent->e.first, c))
	{
		if(curent->e.first == c)
		{
			TValoare old = curent->e.second;
			if(pred == nullptr)
			{
				T[h] = curent->next;
			}
			else
			{
				pred->next = curent->next;
			}
			delete curent;
			len--;
			return old;
		}
		pred = curent;
		curent = curent->next;
	}
	return NULL_TVALOARE;
}

//returneaza numarul de perechi (cheie, valoare) din dictionar
///Complexity: TETA(1)
int DO::dim() const {
	/* de adaugat */
	return len;
}

//verifica daca dictionarul e vid
///Complexity: TETA(1)
bool DO::vid() const {
	/* de adaugat */
	return len == 0;
}

///Complexity: TETA(n)
Iterator DO::iterator() const {
	return  Iterator(*this);
}

///Complexity: TETA(1)
DO::~DO() {
	/* de adaugat */
	for(auto & e:T)
	{
		Pnod curent = (Pnod)e, pred;
		while(curent != nullptr)
		{
			pred = curent;
			curent = curent->next;
			delete pred;
		}
		e = nullptr;
	}
	len = 0;
}

///Best Case: TETA(1)
///Worst Case: TETA(n)
///Average Case: O(n)
void DO::înlocuiște(TCheie k, TValoare valoareVeche, TValoare valoareNoua)
{
	int h = d(k);
	Pnod curent = T[h];
	while(curent != nullptr and R(curent->e.first, k))
	{
		if(curent->e.first == k)
		{
			if(curent->e.second == valoareVeche)
				curent->e.second = valoareNoua;
			break;
		}
		curent = curent->next;
	}
}

///	PseudoCod:
///		pre:	DictOrd - Dictionar Ordonat
///				k - TCheie
///				valoareVeche - TValoare
///				valoareNoua - TValoare
///
///		post:	DictOrd - Dictionar Ordonat modificat daca exista perechea (k, valoareVeche) care devine (k, valoareNoua)
///
///		subalgoritm inlocuieste(DictOrd-i/o, k-i, valoareVeche-i, valoareNoua-i)
///			h <- DictOrd.d(k)
///			curent <- DictOrd.T[k]
///			cat timp curent != NIL si DictOrd.R([curent].e.cheie, k) executa:
///				daca [curent].e.cheie = k atunci
///					daca [curent].e.valoare = valaoreVeche
///						[curent].e.valoare = valoareNoua
///					sf.daca
///					iesi
///				sf.daca
///				curent <-[curent].next
///			sf.cat timp
///		sf.subalgoritm
///

