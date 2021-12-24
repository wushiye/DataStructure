//
//  BinNode.hpp
//  BinarySearchTree
//
//  Created by admin on 2021/12/20.
//

#ifndef BinNode_hpp
#define BinNode_hpp

template <class T>
class BinNode {
public:
    
    BinNode() {}
    
    BinNode(T data, BinNode<T> *lc = nullptr, BinNode<T> *rc = nullptr);
    
    BinNode(T data, BinNode<T> *p);
    
    ~BinNode();
    
    bool operator<(BinNode const &node);
    
    bool operator==(BinNode const& node);
    
    
    T data;
    
    BinNode<T> *lc;
    
    BinNode<T> *rc;
};

template <class T>
BinNode<T>::BinNode(T data, BinNode<T> *lc, BinNode<T> *rc) : data(data), lc(lc), rc(rc) { }

template <class T>
BinNode<T>::BinNode(T data, BinNode<T> *p) : data(data), lc(nullptr), rc(nullptr) {
    if (p) (*data < *p->data ? p->lc : p->rc) = this;
}

template <class T>
BinNode<T>::~BinNode() {
//    delete data;
}

template <class T>
bool BinNode<T>::operator<(BinNode const &node) {
    return data < node.data;
}

template <class T>
bool BinNode<T>::operator==(BinNode const &node) {
    return data == node.data;
}

#endif /* BinNode_hpp */
