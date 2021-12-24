//
//  BinTNode.hpp
//  BinaryHeap
//
//  Created by admin on 2021/12/12.
//

#ifndef BinTNode_hpp
#define BinTNode_hpp

template <class T>
class BinTNode {
public:
    ~BinTNode();
    
    BinTNode(void *obj = nullptr, T level = 0, BinTNode<T> *lc = nullptr, BinTNode<T> *rc = nullptr);
    
    void *obj;
    T level;
    BinTNode<T> *lc;
    BinTNode<T> *rc;
};

template <class T>
BinTNode<T>::BinTNode(void *obj, T level, BinTNode<T> *lc, BinTNode<T> *rc) : obj(obj), level(level), lc(lc), rc(rc) { }
    
template <class T>
BinTNode<T>::~BinTNode() {
//    delete obj; 不确定传进来的是动态对象还是局部或全局对象
}

#endif /* BinTNode_hpp */
