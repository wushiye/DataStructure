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
    class iterator {
    public:
        iterator(Linklist * const iter);
        bool operator = (Linklist * const iter);
        iterator *begin();
        iterator *end();
        iterator operator *(Linklist * const iter);
        iterator *operator ++();
        iterator *operator --();
        bool operator != (Linklist * const iter);
        bool operator == (Linklist * const iter);
    private:
        LNode<T> *p;
    };
    
    inline bool remove(const K &key);
    
    inline bool update(const T &entry);
    
    inline T search(const K &key) const;
    
    inline LNode<T>* insert(const T &entry);
    
    inline LNode<T>* insert(LNode<T> *& prev, const T &entry);
    
    inline LNode<T> * search(const K &key, const LNode<T> *& prev) const;
    
    inline unsigned long length();
    
    bool empty() const;
    
private:
    LNode<T> * _head;
    
    unsigned long _size;
};

template <class T, class K>
inline LNode<T> * Linklist<T, K>::insert(const T &e) {
    LNode<T> *node = new LNode<T>();
    node->entry = e;
    _head->next = node;
    ++ _size;
    return node;
}

template <class T, class K>
inline LNode<T>* Linklist<T, K>::insert(LNode<T> *& prev, const T &e) {
    LNode<T> *node = new LNode<T>();
    node->entry = e;
    node->next = prev->next;
    prev->next = node;
    ++ _size;
    return node;
}

template <class T, class K>
inline bool Linklist<T, K>::remove(const K &key) {
    LNode<T> *prev = nullptr;
    LNode<T> *res = search(key, prev);
    if (!res) return false;
    
    prev->next = res->next;
    delete res;
    -- _size;
    return true;
}

template <class T, class K>
inline bool Linklist<T, K>::update(const T &e) {
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

template <class T, class K>
bool Linklist<T, K>::empty() const {
    return _head->next == nullptr;
}

#pragma mark - iterator class IMP

template <class T, class K>
Linklist<T, K>::iterator Linklist<T, K>::iterator::begin() {
    Linklist<T, K>::iterator *iter = Linklist<T, K>::iterator(_head->next);
    return iter;
}


iterator *end();
bool operator = (Linklist * const iter);
iterator operator * (Linklist * const iter);
iterator *operator ++();
iterator *operator --();
bool operator != (Linklist * const iter);

#endif /* Linklist_hpp */
