//
//  LNode.hpp
//  Hashtable
//
//  Created by admin on 2021/12/31.
//

#ifndef LNode_hpp
#define LNode_hpp

#include "Entry.hpp"

template <class K, class V>
class LNode {
public:
    LNode *next; // 第一个成员变量与实例化的Linklist同地址
    Entry<K, V> *entry; // 词条(Key : Value)
    ~LNode();
};

template <class K, class V>
LNode<K, V>::~LNode() {
    if (entry) {
        delete entry;
        entry = nullptr;
    }
}

#endif /* LNode_hpp */
