//
//  BinTHeap.hpp
//  BinaryHeap
//
//  Created by admin on 2021/12/12.
//

#ifndef BinTHeap_hpp
#define BinTHeap_hpp

#include "BinTNode.hpp"
//#include <cwchar>
#include <string>

#include <iostream>

template <class T>
class BinTHeap {
public:
    
    BinTHeap(const size_t n = 15, const bool isMax = false);
    
    ~BinTHeap();
    
//    void buildByObjs(void *objs[], const size_t cnt);
    
//    void build(T *nodes[], const size_t cnt);
    
    void sort(T *nodes[], const size_t cnt);
    
    void sort_objs(void *objs[], const size_t cnt);
    
    bool isEmpty() const;
    
    T* top() const;
    
    void push(T *node);
    
    void pop();
    
    void print() const;
    
    const size_t getSize() const;
    
    const size_t getCapacity() const;
    
private:
    /** 上浮 */
    void swim();
    /** 下沉 */
    void sink(size_t pi);
    
    size_t son(size_t pi);
    
    void swap(T *& x, T *& y);
    
    inline bool iscan_swap(size_t i);
    
    inline bool iscan_swap(size_t pi, size_t mi);
    
    void expand_capacity();

    size_t size;
    
    size_t capacity;
    
    bool isMax;
    
    T **heap; // 动态指针数组
};

#pragma mark - Public Function IMP

template <class T>
BinTHeap<T>::BinTHeap(const size_t n, const bool isMax) : isMax(isMax) , size(0) {
    capacity = n <= 0 ? 15 : n;
    heap = new T *[capacity + 1];
};

template <class T>
BinTHeap<T>::~BinTHeap() {
    delete [] heap;
}

template <class T>
void BinTHeap<T>::sort(T *nodes[], const size_t cnt) {
    for (size_t i = 0; i != cnt; i++) {
        if (size > 0) {
            nodes[i] = top();
            pop();
        }
    }
}

template <class T>
void BinTHeap<T>::sort_objs(void *objs[], const size_t cnt) {
    for (size_t i = 0; i != cnt; i++) {
        if (size > 0) {
            objs[i] = top()->obj;
            pop();
        }
    }
}

//template <class T>
//void BinTHeap<T>::buildByObjs(void *objs[], const size_t cnt) {
//
//    for (size_t idx = 0; idx != cnt; idx++) {
//        T *node = new T(objs[idx], 0);
//        push(node);
//    }
//}

//template <class T>
//void BinTHeap<T>::build(T *nodes[], const size_t cnt) {
//    for (size_t i = 0; i != cnt; i++) {
//        push(nodes[i]);
//    }
//}

template <class T>
T * BinTHeap<T>::top() const {
    if (size <= 0) {
        return NULL;
    }
    return heap[1];
}

template <class T>
bool BinTHeap<T>::isEmpty() const {
    return size <= 0;
}

template <class T>
void BinTHeap<T>::push(T *node) {
    if (size >= capacity) {
        expand_capacity();
    }
    heap[++size] = node;
    swim();
}

template <class T>
void BinTHeap<T>::expand_capacity() {
    
    size_t n = capacity + capacity; //    size_t n = capacity + (capacity >> 1);
    
    T **new_heap = new T* [n + 1];
    
    memmove(new_heap, heap, sizeof(T *) * (capacity + 1)); // copy
    
    capacity = n;
    
    delete [] heap;
    
    heap = new_heap;
}

template <class T>
void BinTHeap<T>::pop() {
    if (size > 0) {
        swap(heap[1], heap[size]);
        delete heap[size];
        size--;
        sink(1);
    }
}

template <class T>
const size_t BinTHeap<T>::getSize() const {
    return size;
}

template <class T>
const size_t BinTHeap<T>::getCapacity() const {
    return capacity;
}

template <class T>
void BinTHeap<T>::print() const {
    // 方式一：完全二叉树的层序遍历
    for (size_t idx = 1; idx <= size ; idx++) {
        std::cout << heap[idx]->level << ' ';
    }
    std::cout << "\n\n";
    
    /*
    // 方式二：二叉树的层序遍历
    T *deque = new T [size + 1];
    int in = 1, out = 1;
    deque[in++] = heap[1];
    
    while (out < in) {
        std::cout << deque[out] << ' ';
        if (out * 2 <= size) {
            deque[in++] = heap[out * 2];
        }
        if ((out * 2 + 1) <= size) {
            deque[in++] = heap[out * 2 + 1];
        }
        ++out;
    }
    delete [] deque;
    std::cout << "\n";
    */
}

#pragma mark - Private Function IMP

/** 上浮 */
template <class T>
void BinTHeap<T>::swim() {
    if (size < 2) return;
    
    for (size_t idx = size; idx > 1 && iscan_swap(idx); idx >>= 1) {
        swap(heap[idx], heap[idx >> 1]); // 可上浮
    }
    // e.g. 2 >> 1 == 1; 1 >> 1 == 0; 5 >> 1 == 5 / 2; 1 / 2 == 0;
}

template <class T>
inline bool BinTHeap<T>::iscan_swap(size_t idx) {
    T *cur = heap[idx];
    T *parent = heap[idx >> 1];
    return isMax ? cur->level > parent->level : cur->level < parent->level; // cur->obj->level
}

template <class T>
inline bool BinTHeap<T>::iscan_swap(size_t pi, size_t mi) {
    T *parent = heap[pi];
    T *maxson = heap[mi];
    return isMax ? parent->level < maxson->level : parent->level > maxson->level;
}

/** 下沉 */
template <class T>
void BinTHeap<T>::sink(size_t pi) {
    if (size < 2) return;
    
    for (size_t mi = son(pi); mi != pi; pi = mi, mi = son(pi)) {
        if (iscan_swap(pi, mi)) {
            swap(heap[pi], heap[mi]); // 可下沉
        }
    }
}

template <class T>
size_t BinTHeap<T>::son(size_t pi) {
    size_t lci  = pi * 2;
    bool has_lc = lci <= size;
    
    size_t rci = pi * 2 + 1;
    bool has_rc = rci <= size;
    
    if (has_lc && has_rc) {
        if (isMax) {
            return heap[lci]->level > heap[rci]->level ? lci : rci;
        } else {
            return heap[lci]->level < heap[rci]->level ? lci : rci;
        }
    } else if (has_lc) {
        return lci;
    } else if (has_rc) {
        return rci;
    } else {
        return pi;
    }
}

template <class T>
void BinTHeap<T>::swap(T *& x, T *& y) {
    T *t = x;
    x = y;
    y = t;
}

#endif /* BinTHeap_hpp */
