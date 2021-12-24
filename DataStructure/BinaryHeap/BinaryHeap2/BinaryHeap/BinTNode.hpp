//
//  BinTNode.hpp
//  BinaryHeap
//
//  Created by admin on 2021/12/12.
//

#ifndef BinTNode_hpp
#define BinTNode_hpp

template <class T1, class T2>
class BinTNode {
public:
    ~BinTNode();
    
    BinTNode(T1 *obj = nullptr, T2 level = 0, BinTNode<T1, T2> *lc = nullptr, BinTNode<T1, T2> *rc = nullptr);
    
    T1 *obj;
    T2 level;
    BinTNode<T1, T2> * lc;
    BinTNode<T1, T2> * rc;
};

template <class T1, class T2>
BinTNode<T1, T2>::BinTNode(T1 *obj, T2 level, BinTNode<T1, T2> *lc, BinTNode<T1, T2> *rc) : obj(obj), level(level), lc(lc), rc(rc) { }
    
template <class T1, class T2>
BinTNode<T1, T2>::~BinTNode() {
    delete obj;
}

#endif /* BinTNode_hpp */
