#pragma once
#include <string>
using namespace std;

typedef int TElem;

class Nod
{
public:
	TElem e;
	Nod * left;
	Nod * right;

	Nod()
	{
		e = 0;
		left = nullptr;
		right = nullptr;
	}

	Nod * copy()
	{
		Nod * nod = new Nod;
		nod->e = e;
		if(left != nullptr)
			nod->left = left->copy();
		if(right != nullptr)
			nod->right = right->copy();
		return nod;
	};

	void destroy()
	{
		if(left != nullptr)
			left->destroy();
		if(right != nullptr)
			right->destroy();
		delete this;
	}
};

class AB;

class IteratorAB;


class AB {

private:
	/* aici e reprezentarea */
	Nod * root;
public:
	friend class IteratorAB;
	friend class IteratorPreordine;
	friend class IteratorInordine;
	friend class IteratorPostordine;
	friend class IteratorLatime;

		//constructorul implicit
		AB();

		//contructor de copiere
		AB(const AB& ab);

		//creeaza un arbore binar care se reduce la o frunza
		AB(TElem elem);

		//constructor arbore binar
		AB(const AB& st, TElem elem, const AB& dr);

		//adauga unui arbore binar subarborele stang
		//arunca exceptie daca arborele este vid
		void adaugaSubSt(const AB& st);

		//adauga unui arbore binar subarborele drept
		//arunca exceptie daca arborele este vid
		void adaugaSubDr(const AB& dr);

		//verifica daca arborele este vid
   		 bool vid() const;

		//accesare element din radacina
		//arunca exceptie daca arborele este vid
		TElem element() const;

		//accesare subarbore stang
		//arunca exceptie daca arborele este vid
		AB stang() const;

		//accesare subarbore drept
		//arunca exceptie daca arborele este vid
		AB drept() const;

		//iteratori pe arborele binar (ordine="preordine", "postordine", "inordine", "latime")
		IteratorAB* iterator(string ordine) const;

		// destructorul arborelui binar
		~AB();

		TElem max();
};



