//
//  AVLTree.hpp
//  BalancedBinaryTree
//
//  Created by admin on 2021/12/14.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include "AVLNode.hpp"

#include <cwchar>     // use size_t

#include <algorithm>  // use std::max()

#include <iostream>   // use std::cout

template <class T>
class AVLTree {
#pragma mark - Public
public:
    AVLTree<T>() {}
    
    ~AVLTree<T>() {}
    
    void insert(void *obj, const T data);
    
    bool remove(const T data);
    
    void * findData(const T data) const;
    
    void * findMin() const;
    
    void * findMax() const;
    
    void ** levelTraversal(size_t &n);
    
    void ** DLR(size_t &n) const;
    
    void ** LDR(size_t &n) const;
    void LDR(void *objs[], size_t n) const;
    
    void ** LRD(size_t &n) const;
    
    size_t solveCount() const;
    
#pragma mark - Private
private:
    AVLNode<T> *root;
    
//    AVLNode<T> * getRoot() const;
    
//    void setRoot(AVLNode<T> *node);
    
    //    void insert(AVLNode<T>* &tree, const T data);
    
    void insert(AVLNode<T>* &tree, void *obj, const T data);
    
    bool remove(AVLNode<T>* &tree, const T data);
    
    
    AVLNode<T> * existData(AVLNode<T> *tree, const T data) const;
    
    AVLNode<T> * findMin(AVLNode<T> *tree) const;
    
    AVLNode<T> * findMax(AVLNode<T> *tree) const;
    
    AVLNode<T> ** levelTraversal(AVLNode<T> *tree, const size_t n);
    void levelTraversal(AVLNode<T> *tree);
    
    void DLR(AVLNode<T> *tree, AVLNode<T> *nodes[], size_t &idx) const;
    void DLR(AVLNode<T> *tree) const;
    
    void LDR(AVLNode<T> *tree, AVLNode<T> *nodes[], size_t &idx) const;
    void LDR(AVLNode<T> *tree) const;
    
    void LRD(AVLNode<T> *tree, AVLNode<T> *nodes[], size_t &idx) const;
    void LRD(AVLNode<T> *tree) const;
    
    void ** convert_objs(AVLNode<T> **nodes, const size_t n);
    
    
    size_t solveCount(AVLNode<T> *tree) const;
    
    int solveDepth(AVLNode<T> *tree) const;
    
    int getHeight(AVLNode<T> *tree) const;
    
    bool isNotBalanced(AVLNode<T> *tree) const;
    
    
    AVLNode<T> * LL(AVLNode<T> *tree);
    
    AVLNode<T> * RR(AVLNode<T> *tree);
    
    AVLNode<T> * LR(AVLNode<T> *tree);
    
    AVLNode<T> * RL(AVLNode<T> *tree);
};

#pragma mark - Public Function IMP

//template <class T>
//AVLNode<T> * AVLTree<T>::getRoot() const {
//    return this->root;
//}
//
//template <class T>
//void AVLTree<T>::setRoot(AVLNode<T> *root) {
//    this->root = root;
//}

template <class T>
void AVLTree<T>::insert(void *obj, const T data) {
    insert(this->root, obj, data);
}

template <class T>
bool AVLTree<T>::remove(AVLNode<T>* &tree, const T data) {
    if (tree == nullptr) {
        return false;
    }
    
    if (data < tree->data) {
        remove(tree->left, data);
        
        if (isNotBalanced(tree)) {
            int llh = getHeight(tree->left->left);
            int lrh = getHeight(tree->left->right);
            llh >= lrh ? LL(tree) : LR(tree->right);
        } else {
            tree->height = std::max(getHeight(tree->left), getHeight(tree->right)) + 1;
        }
        
    } else if (data > tree->data) {
        remove(tree->right, data);
        
        if (isNotBalanced(tree)) {
            int rrh = getHeight(tree->right->right);
            int rlh = getHeight(tree->right->left);
            rrh >= rlh ? RR(tree) : RL(tree->left);
            
        } else {
            tree->height = std::max(getHeight(tree->left), getHeight(tree->right)) + 1;
        }
        
    } else {
        if (tree->left && tree->right) {
            if (getHeight(tree->left) >= getHeight(tree->right)) {
                AVLNode<T> *max_node = findMax(tree->left);
                T max = max_node->data;
                tree->data = max;
                tree->obj = max_node->obj;
                remove(tree->left, max);
            } else {
                AVLNode<T> *min_node = findMin(tree->right);
                T min = min_node->data;
                tree->data = min;
                tree->obj = min_node->obj;
                remove(tree->right, min);
            }
            
        } else if (tree->left != nullptr || tree->right == nullptr) {
            AVLNode<T> *t = tree;
            tree = tree->left;
            delete t;
            
        } else if (tree->left == nullptr || tree->right != nullptr) {
            AVLNode<T> *t = tree;
            tree = t->right;
            delete t;
            
        } else  {
            delete tree;
        }
    }
    
    return false;
}

template <class T>
bool AVLTree<T>::remove(const T data) {
    return remove(this->root, data);
}

template <class T>
void * AVLTree<T>::findMin() const {
    return findMin(this->root)->obj;
}

template <class T>
void * AVLTree<T>::findMax() const {
    return findMax(this->root)->obj;
}

template <class T>
void * AVLTree<T>::findData(const T data) const {
    return existData(this->root, data)->obj;
}

template <class T>
void ** AVLTree<T>::DLR(size_t &n) const {
    n = solveCount();
    AVLNode<T> **nodes = new AVLNode<T> *[n];
    
    size_t idx = 0;
    DLR(this->root, nodes, idx);
    
    void **objs = convert_objs(nodes, n);
    
    delete [] nodes;
    
    return objs;
}

template <class T>
void AVLTree<T>::LDR(void *objs[], size_t n) const {
    AVLNode<T> **nodes = new AVLNode<T> *[n];
    size_t idx = 0;
    LDR(this->root, nodes, idx);
    
    for (size_t idx = 0; idx != n; idx++) {
        objs[idx] = nodes[idx]->obj;
    }
    delete [] nodes;
}


template <class T>
void ** AVLTree<T>::LRD(size_t &n) const {
    n = solveCount();
    AVLNode<T> **nodes = new AVLNode<T> *[n];
    
    size_t idx = 0;
    LRD(this->root, nodes, idx);
    
    void **objs = convert_objs(nodes, n);
    
    delete [] nodes;
    
    return objs;
}


template <class T>
size_t AVLTree<T>::solveCount() const {
    return solveCount(this-root);
}

template <class T>
void ** AVLTree<T>::levelTraversal(size_t &n) {
    
    n = solveCount();
    
    AVLNode<T> ** deque = levelTraversal(this->root, n);
    
    void ** objs = new void *[n];
    
    for (size_t idx = 0; idx != n; idx++) {
        objs[idx] = deque[idx]->obj;
    }
    
    delete [] deque;
    
    return objs; // 不用时需要在函数外部 delete [] objs;
}

template <class T>
void ** AVLTree<T>::convert_objs(AVLNode<T> **nodes, const size_t n) {
    void ** objs = new void *[n];
    
    for (size_t idx = 0; idx != n; idx++) {
        objs[idx] = nodes[idx]->obj;
    }
    
    return objs; // 不用时需要在函数外部 delete [] objs;
}

template <class T>
size_t AVLTree<T>::solveCount(AVLNode<T> *tree) const {
    if (tree == nullptr) {
        return 0;
    }
    size_t ltc = solveCount(tree->left);
    size_t rtc = solveCount(tree->right);
    return (ltc + rtc) + 1;
}

#pragma mark - Private Function IMP

template <class T>
void AVLTree<T>::insert(AVLNode<T>* &tree, void *obj, const T data) {
    
    if (tree == nullptr) {
        tree = new AVLNode<T>(obj, data);
    } else if (data < tree->data) {
        insert(tree->left, obj, data);
        
        if (isNotBalanced(tree)) {
            if (data < tree->left->data) {
                tree = LL(tree);
            } else {
                tree = LR(tree);
            }
        }
        
    } else if (data > tree->data) {
        insert(tree->right, obj, data);
        if (isNotBalanced(tree)) {
            if (data > tree->right->data) {
                tree = RR(tree);
            } else {
                tree = RL(tree);
            }
        }
    } else {
        ;
    }
    
    tree->height = std::max(getHeight(tree->left), getHeight(tree->right)) + 1;
}

template <class T>
AVLNode<T> * AVLTree<T>::findMin(AVLNode<T> *tree) const {
    if (tree == nullptr) {
        return nullptr;
    }
    
    if (tree->left == nullptr) {
        return tree;
    }
    
    return findMin(tree->left);
}

template <class T>
AVLNode<T> * AVLTree<T>::findMax(AVLNode<T> *tree) const {
    if (tree == nullptr) {
        return nullptr;
    }
    
    if (tree->right == nullptr) {
        return tree;
    }
    
    return findMax(tree->right);
}

template <class T>
AVLNode<T> * AVLTree<T>::existData(AVLNode<T> *tree, const T data) const {
    if (tree == nullptr) {
        return nullptr;
    }
    if (data < tree->data) {
        return existData(tree->left, data);
    } else if (data > tree->data) {
        return existData(tree->right, data);
    } else {
        return tree;
    }
}

template <class T>
AVLNode<T> ** AVLTree<T>::levelTraversal(AVLNode<T> *tree, const size_t n) {
    if (tree == nullptr) {
        return nullptr;
    }
    
    AVLNode<T> ** deque = new AVLNode<T> *[n];
    int in = 0, out = 0;
    deque[in++] = tree;
    
    while (out < in) {
//        std::cout << deque[out]->data << " -> ";
        AVLNode<T> *lc = deque[out]->left;
        if (lc) deque[in++] = lc;
        
        AVLNode<T> *rc = deque[out]->right;
        if (rc) deque[in++] = rc;
        
        ++out;
    }
    
    return deque; // 不用时需要在函数外部 delete [] deque;
}

template <class T>
void AVLTree<T>::DLR(AVLNode<T> *tree) const {
    if (tree) {
        std::cout << tree->data << ' ';
        DLR(tree->left);
        DLR(tree->right);
    }
}

template <class T>
void AVLTree<T>::DLR(AVLNode<T> *tree, AVLNode<T> *nodes[], size_t &idx) const {
    if (tree) {
        nodes[idx++] = tree;
        std::cout << tree->data << ' ';
        DLR(tree->left);
        DLR(tree->right);
    }
}

template <class T>
void AVLTree<T>::LDR(AVLNode<T> *tree) const {
    if (tree) {
        LDR(tree->left);
        std::cout << tree->data << ' ';
        LDR(tree->right);
    }
}

template <class T>
void AVLTree<T>::LDR(AVLNode<T> *tree, AVLNode<T> *nodes[], size_t &idx) const {
    if (tree) {
        LDR(tree->left);
        nodes[idx++] = tree;
        std::cout << tree->data << ' ';
        LDR(tree->right);
    }
}


template <class T>
void AVLTree<T>::LRD(AVLNode<T> *tree) const {
    if (tree) {
        LRD(tree->left);
        LRD(tree->right);
        std::cout << tree->data << ' ';
    }
}

template <class T>
void AVLTree<T>::LRD(AVLNode<T> *tree, AVLNode<T> *nodes[], size_t &idx) const {
    if (tree) {
        LRD(tree->left);
        LRD(tree->right);
        nodes[idx++] = tree;
        std::cout << tree->data << ' ';
    }
}

template <class T>
void AVLTree<T>::levelTraversal(AVLNode<T> *tree) {
    if (tree == nullptr) {
        return;
    }
    
    AVLNode<T> *deque[1000] = {};
    int in = 0, out = 0;
    deque[in++] = tree;
    
    while (out < in) {
        std::cout << deque[out]->data << " -> ";
        
        AVLNode<T> *lc = deque[out]->left;
        if (lc) deque[in++] = lc;
        
        AVLNode<T> *rc = deque[out]->right;
        if (rc) deque[in++] = rc;
        
        ++out;
    }
}

template <class T>
int AVLTree<T>::solveDepth(AVLNode<T> *tree) const {
    if (tree == nullptr) {
        return 0;
    }
    
    int lh = solveDepth(tree->left);
    
    int rh = solveDepth(tree->right);
    
    return (lh >= rh ? lh : rh) + 1;
}

template <class T>
int AVLTree<T>::getHeight(AVLNode<T> *tree) const {
    if (tree == nullptr) {
        return 0;
    }
    return tree->height;
}

template <class T>
bool AVLTree<T>::isNotBalanced(AVLNode<T> *tree) const {
    return abs(getHeight(tree->left) - getHeight(tree->right)) > 1;
}

template <class T>
AVLNode<T> * AVLTree<T>::LL(AVLNode<T> *tree) {
    AVLNode<T> *nt = tree->left;
    
    tree->left = nt->right;
    
    nt->right = tree;
    
    tree->height = std::max(getHeight(tree->left), getHeight(tree->right)) + 1;
    
    nt->height = std::max(getHeight(tree->left), getHeight(tree->right)) + 1;
    
    return nt;
}

template <class T>
AVLNode<T> * AVLTree<T>::RR(AVLNode<T> *tree) {
    AVLNode<T> *nt = tree->right;
    
    tree->right = nt->left;
    
    nt->left = tree;
    
    tree->height = std::max(getHeight(tree->left), getHeight(tree->right)) + 1;
    
    nt->height = std::max(getHeight(nt->left), getHeight(nt->right)) + 1;
    
    return nt;
}

template <class T>
AVLNode<T> * AVLTree<T>::LR(AVLNode<T> *tree) {
    AVLNode<T> *llt = LL(tree->left);
    return RR(llt);
}

template <class T>
AVLNode<T> * AVLTree<T>::RL(AVLNode<T> *tree) {
    AVLNode<T> *rrt = RR(tree->right);
    return LL(rrt);
}

#endif /* AVLTree_hpp */
