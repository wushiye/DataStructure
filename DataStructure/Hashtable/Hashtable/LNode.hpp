//
//  LNode.hpp
//  Hashtable
//
//  Created by admin on 2021/12/31.
//

#ifndef LNode_hpp
#define LNode_hpp

template <class T>
class LNode {
public:
    LNode<T> *next; // 第一个成员变量与实例化的Linklist同地址
    T entry;        // 词条(Key : Value)
};

#endif /* LNode_hpp */
