#include "AB.h"
#include "IteratorAB.h"
#include <exception>
#include <string>
#include <queue>

using std::queue;

// Tetha(1)
AB::AB() {
	/* de adaugat */
	root = nullptr;
}

// Tetha(n) - n numarulde noduri
AB::AB(const AB& ab) {
	/* de adaugat */
	root = ab.root->copy();
}

// Tetha(1)
AB::AB(TElem e){
	/* de adaugat */
	root = new Nod;
	root->e = e;
	root->left = nullptr;
	root->right  = nullptr;
}

// Tetha(a + b) - numarul de noduri din subarborilor
AB::AB(const AB& st, TElem e, const AB& dr){
    	/* de adaugat */
	root = new Nod;
	root->e = e;
	if(st.root != nullptr)
		root->left = st.root->copy();
	if(dr.root != nullptr)
		root->right = dr.root->copy();
}

// Tetha(k) - numarul de noduri al subarborelui
void AB::adaugaSubSt(const AB& st){
 	/* de adaugat */
	if(root->left != nullptr)
		root->left->destroy();
	root->left = st.root->copy();
}

// Tetha(k) - numaril de noduri al subarborelui
void AB::adaugaSubDr(const AB& dr){
	/* de adaugat */
	if(root->right != nullptr)
		root->right->destroy();
	root->right = dr.root->copy();
}

// Theta(1)
TElem AB::element() const{
 	/* de adaugat */
	if(root == nullptr)
		throw exception();
	return root->e;
}

// Theta(k) - numarul de noduri din subgraf
AB AB::stang() const{
 	/* de adaugat */
	if(vid())
		throw(exception());
	AB ab;
	ab.root = nullptr;
	if(root->left != nullptr)
		ab.root = root->left->copy();
	return ab;
}

// Theta(k) - numarul de noduri din subgraf
AB AB::drept() const{
	/* de adaugat */
	if(vid())
		throw(exception());
	AB ab;
	ab.root = nullptr;
	if(root->right != nullptr)
		ab.root = root->right->copy();
	return ab;
}

// Theta(n) - numarul de noduri
AB::~AB() {
	/* de adaugat */
	if(root != nullptr)
		root->destroy();
}

// Theta(1)
bool AB::vid() const{
	/* de adaugat */
	return root == nullptr;
}

// Theta(1)
IteratorAB* AB::iterator(string s) const {
	if (s=="preordine")
		return new IteratorPreordine(*this);
	if (s=="inordine")
		return new IteratorInordine(*this);
	if (s=="postordine")
		return new IteratorPostordine(*this);
	if (s=="latime")
		return new IteratorLatime(*this);
	return nullptr;
};

/*
 * max(ab)
	coada Q
	adauga ab.root in Q
	max <- ab.root

	cat timp Q nu este goala
		curent <- q.front()
		q.pop()

		daca [curent].element > max
			max <- [curent].element

		daca [curent].left nu este NULL
			adauga [curent].left în Q

		daca [curent].right nu este NULL
			adauga [curent].right în Q

	return max
 */
/// gaseste si returneaza valoarea maxima din arbore
/// Complexitate :  Theta(n)
/// Pre: ab - arbore valid
/// post: max - TElem
TElem AB::max()
{
	queue<Nod *> Q;
	Q.push(root);
	TElem max = root->e;
	while(not Q.empty())
	{
		Nod * curent = Q.front();
		Q.pop();
		if(curent->e > max)
		{
			max = curent->e;
		}
		if(curent->left != nullptr)
			Q.push(curent->left);
		if(curent->right != nullptr)
			Q.push(curent->right);
	}
	return max;
}