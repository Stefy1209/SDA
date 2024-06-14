#pragma once

typedef int TCheie;
typedef int TValoare;

#define NULL_TVALOARE -1

#include <utility>
#include <cmath>
typedef std::pair<TCheie, TValoare> TElem;

#define A 0.6180339897

struct nod
{
	TElem e;
	nod* next;
};
typedef nod* Pnod;

class Iterator;

typedef bool(*Relatie)(TCheie, TCheie);

class DO {
	friend class Iterator;
    private:
		Pnod T[13];
		int m;
		int len;
		Relatie R;
		[[nodiscard]] int d(const int & c) const
		{
			return std::floor(m * (c * A - std::floor(c * A)));
		}

    public:

	// constructorul implicit al dictionarului
	DO(Relatie r);


	// adauga o pereche (cheie, valoare) in dictionar
	//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
	// daca nu exista cheia, adauga perechea si returneaza null: NULL_TVALOARE
	TValoare adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null: NULL_TVALOARE
	TValoare cauta(TCheie c) const;


	//sterge o cheie si returneaza valoarea asociata (daca exista) sau null: NULL_TVALOARE
	TValoare sterge(TCheie c);

	//returneaza numarul de perechi (cheie, valoare) din dictionar
	int dim() const;

	//verifica daca dictionarul e vid
	bool vid() const;

	// se returneaza iterator pe dictionar
	// iteratorul va returna perechile in ordine dupa relatia de ordine (pe cheie)
	Iterator iterator() const;


	// destructorul dictionarului
	~DO();

	// înlocuiește valoarea mapate în prezent cheii k cu valoarea valoareNoua, dar numai în cazul în care valoarea curentă este egală cu valoareVeche.
	// dacă valoarea curentă nu este valoareVeche sau în cazul în care k nu este în cheie a dicționarului, dicționarul nu este modificat
	void înlocuiște (TCheie k, TValoare valoareVeche, TValoare valoareNoua);
};
