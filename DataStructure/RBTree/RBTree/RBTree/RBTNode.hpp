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
    
    RBTNode(T e, Color c = RED, RBTNode<T> *lc = nullptr, RBTNode<T> *rc = nullptr);
    
    RBTNode(RBTNode<T> *son);
    
    RBTNode(T e, RBTNode<T> *p);
    
    ~RBTNode();
    
    bool operator=(RBTNode const *node);
    
    bool operator<(RBTNode const *node);
    
    bool operator==(RBTNode const *node);
    
    T entry;
    
    Color color;
    
    RBTNode<T> *lc;
    
    RBTNode<T> *rc;
};

template <class T>
RBTNode<T>::RBTNode(T e, Color c, RBTNode<T> *lc, RBTNode<T> *rc) : entry(e), color(c), lc(lc), rc(rc) { }

template <class T>
RBTNode<T>::RBTNode(RBTNode<T> *son) {
    entry = son->entry;
}

template <class T>
RBTNode<T>::RBTNode(T e, RBTNode<T> *p) : entry(e), color(RED), lc(nullptr), rc(nullptr) {
    if (p) (entry < p->entry ? p->lc : p->rc) = this;
}

template <class T>
RBTNode<T>::~RBTNode() { }

template <class T>
bool RBTNode<T>::operator=(RBTNode const *node) {
    entry = node->entry;
    // code..
}

template <class T>
bool RBTNode<T>::operator<(RBTNode const *node) {
    return entry < node->entry;
}

template <class T>
bool RBTNode<T>::operator==(RBTNode const *node) {
    return entry == node->entry;
}

#endif /* RBTNode_hpp */
