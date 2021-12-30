//
//  ListStack.hpp
//  RBTree
//
//  Created by admin on 2021/12/27.
//

#ifndef ListStack_hpp
#define ListStack_hpp

template <class V>
struct LSNode {
    V value;
    LSNode<V> *next;
};

template <class V>
class ListStack {
public:
    ListStack();
    
    bool empty() const;
    
    unsigned long getSize() const;
    
    V pop();
    
    void push(V value);
    
    V top();
    
private:
    LSNode<V> *head;
    
    unsigned long size;
};


template <class V>
ListStack<V>::ListStack() : head(new LSNode<V>()), size(0) { }

template <class V>
void ListStack<V>::push(V v) {
    LSNode<V> *node = new LSNode<V>();
    node->value = v;
    node->next = this->head->next;
    this->head->next = node;
    size++;
}

template <class V>
V ListStack<V>::pop() {
    if (size == 0) return nullptr;
    
    LSNode<V> *top = this->head->next;
    this->head->next = top->next;
    V value = top->value;
    
    delete top;
    size--;
    
    return value;
}

template <class V>
V ListStack<V>::top() {
    if (size == 0) return nullptr;
    return this->head->next->value;
}

template <class V>
bool ListStack<V>::empty() const {
    return size == 0;
}

template <class V>
unsigned long ListStack<V>::getSize() const {
    return size;
}

#endif /* ListStack_hpp */
