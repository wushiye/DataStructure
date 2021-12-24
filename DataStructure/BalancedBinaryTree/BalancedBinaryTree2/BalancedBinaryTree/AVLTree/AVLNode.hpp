//
//  AVLNode.hpp
//  BalancedBinaryTree
//
//  Created by admin on 2021/12/14.
//

#ifndef AVLNode_hpp
#define AVLNode_hpp

template <class T>
class AVLNode {
public:
    
    AVLNode<T>() {}
    
    AVLNode<T>(void *obj, const T data) : obj(obj), data(data), left(nullptr), right(nullptr), height(0) { }
    
    void *obj;
    
    T data;
    
    unsigned height;
    
    AVLNode<T> *left;
    
    AVLNode<T> *right;
};


#endif /* AVLNode_hpp */
