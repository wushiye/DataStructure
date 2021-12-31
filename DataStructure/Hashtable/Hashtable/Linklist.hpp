//
//  Linklist.hpp
//  Hashtable
//
//  Created by admin on 2021/12/31.
//

#ifndef Linklist_hpp
#define Linklist_hpp

#include "LNode.hpp"

template <class T, class K>
class Linklist {
public:
    
    inline LNode<T>* insert(const T &entry);
    
    LNode<T>* insert(LNode<T> *& prev, const T &entry);
    
    bool remove(const K &key);
    
    bool update(const T &entry);
    
    inline T search(const K &key) const;
    
    inline LNode<T> * search(const K &key, const LNode<T> *& prev) const;
    
    unsigned long length();
    
private:
    LNode<T> * _head;
    unsigned long _size;
};

template <class T, class K>
inline LNode<T> * Linklist<T, K>::insert(const T &e) {
    LNode<T> *node = new LNode<T>();
    node->entry = e;
    _head->next = node;
    return node;
}

template <class T, class K>
LNode<T>* Linklist<T, K>::insert(LNode<T> *& prev, const T &e) {
    LNode<T> *node = new LNode<T>();
    node->entry = e;
    node->next = prev->next;
    prev->next = node;
    return node;
}

template <class T, class K>
bool Linklist<T, K>::remove(const K &key) {
    LNode<T> *prev = nullptr;
    LNode<T> *res = search(key, prev);
    if (!res) return false;
    
    prev->next = res->next;
    delete res;
    return true;
}

template <class T, class K>
bool Linklist<T, K>::update(const T &e) {
    LNode<T> *prev = nullptr;
    LNode<T> *res = search(e.key, prev);
    if (!res) return false;
    
    res->entry = e;
    return true;
}

template <class T, class K>
inline T Linklist<T, K>::search(const K &key) const {
    LNode<T> *next = _head->next;
    while ((next = next->next) && next->entry->key != key) { };
    return next->entry;
}

template <class T, class K>
inline LNode<T> * Linklist<T, K>::search(const K &key, const LNode<T> *& prev) const {
    prev = _head;
    LNode<T> *next = _head->next;
    while ((next = next->next) && next->entry->key != key) {
        prev = next;
    };
    return next;
}

template <class T, class K>
unsigned long Linklist<T, K>::length() {
    return _size;
}

#endif /* Linklist_hpp */
