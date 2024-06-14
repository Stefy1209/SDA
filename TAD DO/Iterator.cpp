#include "Iterator.h"
#include "DO.h"

#include <algorithm>

using namespace std;

///Complexity: TETA(n)
Iterator::Iterator(const DO& d) : dict(d){
	/* de adaugat */
	pozCurent = 0;

	for(auto &e:dict.T)
	{
		vector<TElem> l2;
		Pnod curent = e;
		while(curent != nullptr)
		{
			l2.push_back(curent->e);
			curent = curent->next;
		}

		vector<TElem> nou;
		int i1 = 0, i2 = 0;

		while(i1 < dict_sorted.size() and i2 < l2.size())
		{
			if(dict.R(dict_sorted[i1].first, l2[i2].first))
			{
				nou.push_back(dict_sorted[i1]);
				i1++;
			}
			else
			{
				nou.push_back(l2[i2]);
				i2++;
			}
		}
		while(i1 < dict_sorted.size())
		{
			nou.push_back(dict_sorted[i1]);
			i1++;
		}
		while(i2 < l2.size())
		{
			nou.push_back(l2[i2]);
			i2++;
		}

		dict_sorted = nou;
	}
}

///Complexity: TETA(1)
void Iterator::prim(){
	/* de adaugat */
	pozCurent = 0;
}

///Complexity: TETA(1)
void Iterator::urmator(){
	/* de adaugat */
	pozCurent++;
}

///Complexity: TETA(1)
bool Iterator::valid() const{
	/* de adaugat */
	return pozCurent < dict_sorted.size();
}

///Complexity: TETA(1)
TElem Iterator::element() const{
	/* de adaugat */
	return dict_sorted[pozCurent];
}



