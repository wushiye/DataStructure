//
//  BinSerarchTree.hpp
//  BinarySearchTree
//
//  Created by admin on 2021/12/22.
//

#ifndef BinSerarchTree_hpp
#define BinSerarchTree_hpp

#include "BinTree.hpp"
//#include <vector>

template <class T, class K>
class BinSearchTree : public BinTree<T> {
public:
//protected:
    BinNode<T> *& search(const K &key);
    BinNode<T> *& searchIn(BinNode<T> * &t, const K &key);
    BinNode<T> *& searchIn(BinNode<T> *& t, const K &key, BinNode<T> *& p);
    
    BinNode<T> * searchMax();
    BinNode<T> * searchMax(BinNode<T> *t);
    BinNode<T> *& searchMaxIn(BinNode<T> *& t);
    
    BinNode<T> * searchMin();
    BinNode<T> * searchMin(BinNode<T> *t);
    BinNode<T> *& searchMinIn(BinNode<T> *& t);
    
    BinNode<T> * insert(const T &data);
    
    bool remove(const K& key);
    
    void removeAt(BinNode<T> *& t);
    
    BinNode<T> *hot;
};

#pragma mark - Public IMP

template <class T, class K>
bool BinSearchTree<T, K>::remove(const K &key) {
    BinNode<T> *& t = search(key);
    if (!t) return false;
    removeAt(t);
    -- this->size;
    return true;
}

template <class T, class K>
void BinSearchTree<T, K>::removeAt(BinNode<T> *& t) {
    if (t->lc && t->rc) {
        BinNode<T> *& min = searchMinIn(t->rc);
        t->data = min->data;
        delete min;
        min = nullptr;
        
    } else if (t->lc || t->rc) {
        BinNode<T> *& son = t->lc ? t->lc : t->rc;
        delete t;
        t = son;
        
    } else {
        delete t;
        t = nullptr;
    }
}

#pragma mark - Protected IMP

template <class T, class K>
BinNode<T> *& BinSearchTree<T, K>::search(const K &key) {
    return searchIn(this->root, key);
}

template <class T, class K>
BinNode<T> *& BinSearchTree<T, K>::searchIn(BinNode<T> *&t, const K &key) {
    BinNode<T> *p = nullptr;
    BinNode<T> *&res = searchIn(t, key, p);
    this->hot = p;
    return res;
}

template <class T, class K>
BinNode<T> *& BinSearchTree<T, K>::searchIn(BinNode<T> *& t, const K &key, BinNode<T> *& p) {
    if (!t) {
        return t;
    } else {
        if (*key == *(t->data->key)) return t;
    }
    p = t;
    return searchIn(*key < *(t->data->key) ? t->lc : t->rc, key, p);
}

template <class T, class K>
BinNode<T> * BinSearchTree<T, K>::searchMax() {
    return searchMax(this->root);
}

template <class T, class K>
BinNode<T> * BinSearchTree<T, K>::searchMax(BinNode<T> *t) {
    BinNode<T> *p = t, *rc = t->rc;
    while (rc != nullptr) {
        p = rc;
        rc = rc->rc;
    }
    return p;
}

template <class T, class K>
BinNode<T> *& BinSearchTree<T, K>::searchMaxIn(BinNode<T> *& t) {
    if (!t->rc) return t;
    return searchMaxIn(t->rc);
}


template <class T, class K>
BinNode<T> * BinSearchTree<T, K>::searchMin() {
    return searchMin(this->root);
}

template <class T, class K>
BinNode<T> * BinSearchTree<T, K>::searchMin(BinNode<T> * t) {
    BinNode<T> *p = t, *lc = t->lc;
    while (lc != nullptr) {
        p = lc;
        lc = p->lc;
    }
    return p;
}

template <class T, class K>
BinNode<T> *& BinSearchTree<T, K>::searchMinIn(BinNode<T> *& t) {
    if (!t->lc) return t;
    return searchMinIn(t->lc);
}

template <class T, class K>
BinNode<T> * BinSearchTree<T, K>::insert(const T &data) {
    BinNode<T> *& t = search(data->key);
    if (!t) {
//        t = new BinNode<T>(data, hot);
        t = new BinNode<T>(data);
        ++ this->size;
    } else {
        t->data = data;
    }
    return t;
}

#endif /* BinSerarchTree_hpp */
