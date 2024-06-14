#include "IteratorMDO.h"
#include "MDO.h"

/// Teta(1)
IteratorMDO::IteratorMDO(const MDO& d) : dict(d){
	/* de adaugat */
    it = dict.start;
}

/// Teta(1)
void IteratorMDO::prim(){
	/* de adaugat */
    it = dict.start;
}

/// Teta(1)
void IteratorMDO::urmator(){
	/* de adaugat */
    it = dict.next[it];
}

/// Teta(1)
bool IteratorMDO::valid() const{
	/* de adaugat */
	return it != NULL_Position;
}

/// Teta(1)
TElem IteratorMDO::element() const{
	/* de adaugat */
	return pair <TCheie, TValoare>  (dict.e[it].first, dict.e[it].second);
}


