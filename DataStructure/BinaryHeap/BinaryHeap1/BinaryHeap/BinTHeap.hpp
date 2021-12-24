//
//  BinTHeap.hpp
//  BinaryHeap
//
//  Created by admin on 2021/12/12.
//

#ifndef BinTHeap_hpp
#define BinTHeap_hpp

//#include <cwchar>
#include <string>

#include <iostream>

template <class T>
class BinTHeap {
public:
    
    BinTHeap(const size_t n = 10, const bool isMax = false);
    
    ~BinTHeap();
    
    void build(T ary[], const size_t cnt);
    
    void sort(T ary[], const size_t cnt);
    
    bool isEmpty() const;
    
    const T top() const;
    
    bool push(const T data);
    
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
    
    void swap(T &x, T &y);
    
    inline bool iscan_swap(size_t i);
    
    inline bool iscan_swap(size_t pi, size_t mi);
    
    inline size_t get_pi(const size_t ci);
    
    inline size_t get_lci(const size_t pi);
    
    inline size_t get_rci(const size_t pi);
    
    void expand_capacity();
    
    T *heap;
    
    size_t size;
    
    size_t capacity;
    
    bool isMax;
};

#pragma mark - Public Function IMP

template <class T>
BinTHeap<T>::BinTHeap(const size_t n, const bool isMax) : isMax(isMax) , size(0) {
    capacity = n;
    heap = new T[n + 1];
};

template <class T>
BinTHeap<T>::~BinTHeap() {
    delete [] heap;
}

template <class T>
void BinTHeap<T>::build(T ary[], const size_t cnt) {
    for (size_t i = 0; i != cnt; i++) {
        push(ary[i]);
    }
}

template <class T>
void BinTHeap<T>::sort(T ary[], const size_t cnt) {
    for (size_t i = 0; i != cnt; i++) {
        if (! isEmpty()) {
            ary[i] = top();
            pop();
        }
    }
}

template <class T>
const T BinTHeap<T>::top() const {
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
bool BinTHeap<T>::push(const T data) {
    if (size >= capacity) {
        expand_capacity();
    }
    heap[++size] = data;
    swim();
    return true;
}

template <class T>
void BinTHeap<T>::expand_capacity() {
    
    size_t n = capacity + capacity / 2;
    
    T *aryn = new T[n + 1];

    size_t x = capacity + 1;
    
    memmove(aryn, heap, sizeof(T) * x);
    
    capacity = n;
    
    delete [] heap;
    
    heap = aryn;
}

template <class T>
void BinTHeap<T>::pop() {
    if (size > 0) {
        swap(heap[1], heap[size]);
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
        std::cout << heap[idx] << ' ';
    }
    std::cout << "\n";
    
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
    
    for (size_t t = size; t > 1 && iscan_swap(t); t >>= 1) {
        swap(heap[t], heap[t >> 1]); // 可上浮
    }
    /* or
    for (size_t t = size; t > 1 && heap[t] > heap[t >> 1]; t >>= 1) {
        swap(heap[t], heap[t >> 1]);
    }
    */
    // 2 >> 1 == 1; 1 >> 1 == 0; 5 >> 1 == 5 / 2; 1 / 2 == 0;
}

template <class T>
inline bool BinTHeap<T>::iscan_swap(size_t i) {
    T cur = heap[i];
    T parent = heap[i >> 1];
    return isMax ? cur > parent : cur < parent;
}

template <class T>
inline bool BinTHeap<T>::iscan_swap(size_t pi, size_t mi) {
    T parent = heap[pi];
    T maxson = heap[mi];
    return isMax ? parent < maxson : parent > maxson;
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
            return heap[lci] > heap[rci] ? lci : rci;
        } else {
            return heap[lci] < heap[rci] ? lci : rci;
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
void BinTHeap<T>::swap(T &x, T &y) {
    T t = x;
    x = y;
    y = t;
}

template <class T>
inline size_t BinTHeap<T>::get_pi(const size_t ci) {
    return ci >> 1;
}

template <class T>
inline size_t BinTHeap<T>::get_lci(const size_t pi) {
    return pi * 2; // pi << 1
}

template <class T>
inline size_t BinTHeap<T>::get_rci(const size_t pi) {
    return pi * 2 + 1; // (pi << 1) + 1
}

#endif /* BinTHeap_hpp */
