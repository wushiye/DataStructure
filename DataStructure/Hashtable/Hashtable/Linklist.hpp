//
//  Linklist.hpp
//  Hashtable
//
//  Created by admin on 2021/12/31.
//

#ifndef Linklist_hpp
#define Linklist_hpp

#include "LNode.hpp"
#include <string>

template <class K, class V>
class Linklist {
public:
    Linklist();
    
    ~Linklist();
    
    unsigned long hash; // 发生冲突的唯一散列值 hash = hash(key)
    
    bool insert(const V &value, const K &key);
    
    bool remove(const K &key);
    
    bool update(const Entry<K, V> &e);
    
    V search(const K &key) const;
    
    inline unsigned long length();
    
    bool empty() const;
    
    void removeAll();
    
    // iterator class declaration
    class iterator {
    public:
        iterator();
        iterator(LNode<K, V> * const ptr);
        iterator& operator = (LNode<K, V> * const ptr);
        
        Entry<K, V> & operator * ();
        iterator & operator ++();
        bool operator != (LNode<K, V> * const ptr);
    private:
        LNode<K, V> *p;
    };
    
    LNode<K, V> * begin() const;
    LNode<K, V> * end() const;
    
private:
    
    LNode<K, V> * front_insert(const V &value, const K &key);
    
    LNode<K, V> * insertIn(LNode<K, V> *& prev, const Entry<K, V> &e);
    
    LNode<K, V> * searchIn(const K &key, LNode<K, V> *& prev) const;
    
    void removeAll(LNode<K, V> *& node);
    
    LNode<K, V> * _head;
    
    unsigned long _size;
};

template <class K, class V>
Linklist<K, V>::Linklist() : _head(new LNode<K, V>()), _size(0) { }

template <class K, class V>
Linklist<K, V>::~Linklist() {
    removeAll();
}

template <class K, class V>
bool Linklist<K, V>::insert(const V &value, const K &key) {
    LNode<K, V> *prev;
    LNode<K, V> *res = searchIn(key, prev);
    // 找到了就直接改值
    if (res) {
        res->entry->value = value;
        return true; // 更改：true 插入：false
    }
    // 没找到就在链表最前面插入值
    front_insert(value, key);
    
    return false; // 更改：true 插入：false
}

template <class K, class V>
LNode<K, V> * Linklist<K, V>::front_insert(const V &value, const K &key) {
    LNode<K, V> *node = new LNode<K, V>();
    node->entry = new Entry<K, V>(key, value);
    
    node->next = _head->next;
    _head->next = node;
    ++ _size;
    return node;
}

template <class K, class V>
LNode<K, V>* Linklist<K, V>::insertIn(LNode<K, V> *& prev, const Entry<K, V> &e) {
    LNode<K, V> *node = new LNode<K, V>();
    node->entry = e;
    node->next = prev->next;
    prev->next = node;
    ++ _size;
    return node;
}

template <class K, class V>
bool Linklist<K, V>::remove(const K &key) {
    LNode<K, V> *prev = nullptr;
    LNode<K, V> *res = searchIn(key, prev);
    if (!res) return false;
    
    prev->next = res->next;
    delete res;
    -- _size;
    return true;
}

template <class K, class V>
bool Linklist<K, V>::update(const Entry<K, V> &e) {
    LNode<K, V> *prev = nullptr;
    LNode<K, V> *res = search(e.key, prev);
    if (!res) return false;
    
    res->entry = e;
    return true;
}

template <class K, class V>
V Linklist<K, V>::search(const K &key) const {
    LNode<K, V> *next = _head->next;
    while (next && next->entry->key != key) {
        next = next->next;
    };
    return next ? next->entry->value : NULL;
}

template <class K, class V>
LNode<K, V> * Linklist<K, V>::searchIn(const K &key, LNode<K, V> *& prev) const {
    prev = _head;
    LNode<K, V> *next = _head->next;
    while (next && next->entry->key != key) {
        prev = next;
        next = next->next;
    };
    
    return next;
}

template <class K, class V>
inline unsigned long Linklist<K, V>::length() {
    return _size;
}

template <class K, class V>
inline bool Linklist<K, V>::empty() const {
    return _head->next == nullptr;
}

template <class K, class V>
void Linklist<K, V>::removeAll() {
    removeAll(_head->next);
}

template <class K, class V>
void Linklist<K, V>::removeAll(LNode<K, V> *& node) {
    if (! node) return;
    
    removeAll(node->next);
    
    delete node;
    node = nullptr;
    -- _size;
}

template <class K, class V>
LNode<K, V> * Linklist<K, V>::begin() const  {
    return _head->next;
}

template <class K, class V>
LNode<K, V> * Linklist<K, V>::end() const {
    return nullptr;
}

#pragma mark - iterator class IMP

template <class K, class V>
Linklist<K, V>::iterator::iterator() : p(nullptr) { }

template <class K, class V>
Linklist<K, V>::iterator::iterator(LNode<K, V> * const ptr) : p(ptr) { }

template <class K, class V>
typename Linklist<K, V>::iterator & Linklist<K, V>::iterator::operator = (LNode<K, V> * const ptr) {
    this->p = ptr;
    return this;
}

template <class K, class V>
typename Linklist<K, V>::iterator & Linklist<K, V>::iterator::operator ++() {
    if (this->p) this->p = this->p->next;
    return this;
}

template <class K, class V>
bool Linklist<K, V>::iterator::operator != (LNode<K, V> * const ptr) {
    return this->p != ptr;
}

template <class K, class V>
Entry<K, V> & Linklist<K, V>::iterator::operator * () {
    if (! this->p) return nullptr;
    return this->p->entry;
}

#endif /* Linklist_hpp */
