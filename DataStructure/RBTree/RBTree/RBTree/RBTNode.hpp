//
//  RBTNode.hpp
//  RBTree
//
//  Created by admin on 2021/12/27.
//

#ifndef RBTNode_hpp
#define RBTNode_hpp

template <class T>
class RBTNode {
public:
    enum Color{RED, BLACK};
    
    RBTNode() {}
    
    RBTNode(T e, Color c = RED, RBTNode<T> *p = nullptr, RBTNode<T> *lc = nullptr, RBTNode<T> *rc = nullptr);
    
    RBTNode(RBTNode<T> *node, RBTNode<T> *p);
    
    RBTNode(T e, RBTNode<T> *p);
    
    ~RBTNode();
    
    void operator=(RBTNode const &node);
    
    bool operator<(RBTNode const &node);
    
    bool operator==(RBTNode const &node);
    
//private:
    
    Color color;
    
    RBTNode<T> *p;
    
    RBTNode<T> *lc;
    
    RBTNode<T> *rc;
    
//private:
    T entry;
};

template <class T>
RBTNode<T>::RBTNode(T e, Color c, RBTNode<T> *p, RBTNode<T> *lc, RBTNode<T> *rc) : entry(e), color(c), p(p), lc(lc), rc(rc) { }

template <class T>
RBTNode<T>::RBTNode(RBTNode<T> *node, RBTNode<T> *pre) : color(RED), p(pre), lc(nullptr), rc(nullptr) {
    this->entry = node->entry;
}

template <class T>
RBTNode<T>::RBTNode(T e, RBTNode<T> *p) : entry(e), color(RED), p(nullptr), lc(nullptr), rc(nullptr) {
    if (p) (*entry < *p->entry ? p->lc : p->rc) = this;
}

template <class T>
RBTNode<T>::~RBTNode() { }

template <class T>
void RBTNode<T>::operator=(RBTNode const &node) {
    this->entry = node.entry;
}


template <class T>
bool RBTNode<T>::operator<(RBTNode const &node) {
    return *entry < *node.entry;
}

template <class T>
bool RBTNode<T>::operator==(RBTNode const &node) {
    return *entry == *node.entry;
}

#endif /* RBTNode_hpp */
