#include "AB.h"
#include "IteratorAB.h"

/// Best Case: Theta(1)
/// Worst Case: Theta(n)
/// Average Case: O(n)
IteratorInordine::IteratorInordine(const AB& _ab):ab(_ab) {
	/* de adaugat */
	Nod * aux = ab.root;
	while(aux != nullptr)
	{
		stack_.push(aux);
		aux = aux->left;
	}
	if(stack_.empty())
		it = nullptr;
	else
		it = stack_.top();
}

/// Best Case: Theta(1)
/// Worst Case: Theta(n)
/// Average Case: O(n)
void IteratorInordine::prim(){
	/* de adaugat */
	while(not stack_.empty())
		stack_.pop();
	Nod * aux = ab.root;
	while(aux != nullptr)
	{
		stack_.push(aux);
		aux = aux->left;
	}
	if(not stack_.empty())
		it = stack_.top();
	else it = nullptr;
}

/// Theta(1)
bool IteratorInordine::valid(){
	/* de adaugat */
	return it != nullptr;
}

/// Theta(1)
TElem IteratorInordine::element() {
	/* de adaugat */
	return it->e;
}

/// Best Case: Theta(1)
/// Worst Case: Theta(n)
/// Average Case: O(n)
void IteratorInordine::urmator(){
	/* de adaugat */
	stack_.pop();
	if(it != nullptr)
	{
		it = it->right;
		while(it != nullptr)
		{
			stack_.push(it);
			it = it->left;
		}
	}
	if(stack_.empty())
	{
		it = stack_.top();
	}
	else
	{
		it = nullptr;
	}
}

/// Theta(1)
IteratorPreordine::IteratorPreordine(const AB& _ab):ab(_ab){
	/* de adaugat */
	it = ab.root;
	stack_.push(ab.root);
}

/// Best Case: Theta(1)
/// Worst Case: Theta(n)
/// Average Case: O(n)
void IteratorPreordine::prim(){
 	/* de adaugat */
	while(not stack_.empty())
		stack_.pop();
	it = ab.root;
	stack_.push(ab.root);
}

/// Theta(1)
bool IteratorPreordine::valid(){
	/* de adaugat */
	return it != nullptr;
}

/// Theta(1)
TElem IteratorPreordine::element(){
	/* de adaugat */
	return it->e;
}

/// Theta(1)
void IteratorPreordine::urmator(){
	/* de adaugat */
	Nod * aux = stack_.top();
	stack_.pop();

	if(aux->right != nullptr)
		stack_.push(aux->right);
	if(aux->left != nullptr)
		stack_.push(aux->left);

	if(stack_.empty())
		it = nullptr;
	else
		it = stack_.top();
}

/// Theta(1)
IteratorPostordine::IteratorPostordine(const AB& _ab):ab(_ab){
	/* de adaugat */
	actual.nod = ab.root;
}

/// Best Case: Theta(1)
/// Worst Case: Theta(n)
/// Average Case: O(n)
void IteratorPostordine::prim(){
	/* de adaugat */
	while(not stack_.empty())
		stack_.pop();
	actual.k = 0;
	actual.nod = ab.root;
	stack_.push(actual);
	while(actual.nod != nullptr)
	{
		el x;
		x.k = 0;
		x.nod = actual.nod;
		stack_.push(x);
		actual.nod = actual.nod->left;
	}
}

/// Theta(1)
bool IteratorPostordine::valid(){
	/* de adaugat */
	return actual.nod != nullptr and not stack_.empty();
}

/// Theta(1)
TElem IteratorPostordine::element(){
 	/* de adaugat */
	actual.nod->e;
}

/// Best Case: Theta(1)
/// Worst Case: Theta(n)
/// Average Case: O(n)
void IteratorPostordine::urmator(){
	/* de adaugat */
	while (actual.nod != nullptr)
	{
		el x;
		x.k = 0;
		x.nod = actual.nod;
		stack_.push(x);
		actual.nod = actual.nod->left;
	}

	el x = stack_.top();
	stack_.pop();
	if (x.k == 0)
	{
		x.k = 1;
		stack_.push(x);
		actual.nod = x.nod->right;
	}
}

/// Theta(1)
IteratorLatime::IteratorLatime(const AB& _ab):ab(_ab){
	/* de adaugat */
	it = ab.root;
	Q.push(ab.root);
}

/// Best Case: Theta(1)
/// Worst Case: Theta(n)
/// Average Case: O(n)
void IteratorLatime::prim(){
	/* de adaugat */
	while(not Q.empty())
		Q.pop();
	it = ab.root;
	Q.push(ab.root);
}

/// Theta(1)
bool IteratorLatime::valid(){
	/* de adaugat */
	return it != nullptr;
}

/// Theta(1)
TElem IteratorLatime::element(){
	/* de adaugat */
	return it->e;
}

/// Theta(1)
void IteratorLatime::urmator(){
	/* de adaugat */

	Nod * aux= Q.front();
	Q.pop();
	if(aux->left != nullptr)
		Q.push(aux->left);
	if(aux->right != nullptr)
		Q.push(aux->right);

	if(Q.empty())
		it = nullptr;
	else it = Q.front();
}
