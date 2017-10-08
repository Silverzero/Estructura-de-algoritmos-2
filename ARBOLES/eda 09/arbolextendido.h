#ifndef arbolextendido_h
#define arbolextendido_h

#include <iostream>
#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
#include "bintree_eda.h"
using namespace std;

template <class T>
class arbolextendido : public bintree<T> {
	using Link = typename bintree<T>::Link;

private:
    static size_t alturaprivate(Link r)
    {
        if(r == nullptr) return 0;
        else
            return 1+ max(alturaprivate(r->left_),alturaprivate(r->right_));
    }

    static size_t hojasprivate(Link r)
    {
        if(r == nullptr) 
			return 0;
        else
		{
			if(r->left_ == nullptr && r->left_ == nullptr)
				return 1;
			else
			{
				return hojasprivate(r->left_) + hojasprivate(r->right_);
			}
		}
    }

	static size_t nodosprivate(Link r)
    {
        if(r == nullptr) 
			return 0;
        else
		{
			return 1 + nodosprivate(r->left_) + nodosprivate(r->right_);
		}
    }

public:
	//constructoras
	arbolextendido() : bintree<T>() {}
	arbolextendido(arbolextendido<T> const& l, T const& e, arbolextendido<T> const& r) : bintree<T>(l, e, r) {}

	size_t altura() const {
		return alturaprivate(this->root_);
	}

	size_t nodos() const {
		return nodosprivate(this->root_);
	}

	size_t hojas() const {
		if (this->root_ == nullptr) return 0;
		else return hojasprivate(this->root_);
	}

};
#endif