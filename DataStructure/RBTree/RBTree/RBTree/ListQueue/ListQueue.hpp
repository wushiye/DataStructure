//
//  ListQueue.hpp
//  RBTree
//
//  Created by admin on 2021/12/28.
//

#ifndef ListQueue_hpp
#define ListQueue_hpp

template <class V>
struct LQNode {
    V value;
    LQNode<V> *next;
};

template <class V>
class ListQueue {
public:
    
    ListQueue();
    
    bool empty() const;
    
    unsigned long getSize() const;
    
    V out();
    
    void in(V value);
    
    V first();
    
    V last();
    
private:
    LQNode<V> *head;
    
    LQNode<V> *end;
    
    unsigned long size;
};

template <class V>
ListQueue<V>::ListQueue() : head(new LQNode<V>()), end(head), size(0) { }

template <class V>
void ListQueue<V>::in(V v) {
    LQNode<V> *node = new LQNode<V>();
    node->value = v;
    end->next = node;
    end = node; // 迭代末尾指针
    size++;
}

template <class V>
V ListQueue<V>::out() {
    if (size == 0) return nullptr;
    
    LQNode<V> *beg = head->next;
    head->next = beg->next;
    V value = beg->value;
    if (beg == end) end = head;
    
    delete beg;
    size--;
    
    return value;
}

template <class V>
V ListQueue<V>::first() {
    if (size == 0) return nullptr;
    return this->head->next->value;
}

template <class V>
bool ListQueue<V>::empty() const {
    return head == end; // size == 0;
}

template <class V>
unsigned long ListQueue<V>::getSize() const {
    return size;
}

#endif /* ListQueue_hpp */
