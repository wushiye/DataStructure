//
//  AVLTree.hpp
//  BalancedBinaryTree
//
//  Created by admin on 2021/12/14.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include "AVLNode.hpp"

#include <cwchar>     // using size_t

#include <algorithm>  // using std::max() std::abs()

#include <iostream>   // using std::cout

template <class T>
class AVLTree {
#pragma mark - Public
public:
    AVLTree<T>() {}
    
    ~AVLTree<T>() {}
    
    void insert(void *obj, const T data);
    
    void remove(const T data);
    
    void * findData(const T data) const;
    
    void * findMin() const;
    
    void * findMax() const;
    
    const size_t solveCount() const;
    
    /** 层序遍历：遍历的树中的每个结点并存放到数组 */
    void levelTraversal(void *objs[], const size_t n);
//    void ** levelTraversal(const size_t n);
    
    /** 前序遍历(DLR)：遍历的树中的每个结点并存放到数组 */
    void DLR(void *objs[], const size_t n) const;
//    void ** DLR(const size_t n) const;
    
    /** 中序遍历(LDR)：遍历的树中的每个结点并存放到数组 */
    void LDR(void *objs[], const size_t n) const;
//    void ** LDR(const size_t n) const;
    
    /** 后序遍历(LRD)：遍历的树中的每个结点并存放到数组 */
    void LRD(void *objs[], const size_t n) const;
//    void ** LRD(const size_t n) const;
    
#pragma mark - Private
private:
    AVLNode<T> *root;
    
//    AVLNode<T> * getRoot() const;
    
//    void setRoot(AVLNode<T> *node);
    
    //    void insert(AVLNode<T>* &tree, const T data);
    
    void insert(AVLNode<T>* &tree, void *obj, const T data);
    
    void insertLC(AVLNode<T>* &tree, void *obj, const T data);
    
    void insertRC(AVLNode<T>* &tree, void *obj, const T data);
    
    
    void remove(AVLNode<T>* &tree, const T data);
    
    
    AVLNode<T> * existData(AVLNode<T> *tree, const T data) const;
    
    AVLNode<T> * findMin(AVLNode<T> *tree) const;
    
    AVLNode<T> * findMax(AVLNode<T> *tree) const;
    
    AVLNode<T> ** levelTraversal(AVLNode<T> *tree, const size_t n);
    void levelTraversal(AVLNode<T> *tree);
    
    /** 前序遍历(DLR)：遍历的树中的每个结点并存放到数组 */
    void DLR(AVLNode<T> *tree, AVLNode<T> *nodes[], size_t &idx, const size_t n) const;
    void DLR(AVLNode<T> *tree) const;
    
    /** 中序遍历(LDR)：遍历的树中的每个结点并存放到数组 */
    void LDR(AVLNode<T> *tree, AVLNode<T> *nodes[], size_t &idx, const size_t n) const;
    void LDR(AVLNode<T> *tree) const;
    
    /** 后序遍历(LRD)：遍历的树中的每个结点并存放到数组 */
    void LRD(AVLNode<T> *tree, AVLNode<T> *nodes[], size_t &idx, const size_t n) const;
    void LRD(AVLNode<T> *tree) const;
    
    void ** convert_objs(AVLNode<T> **nodes, const size_t n) const;
    
    
    size_t solveCount(AVLNode<T> *tree) const;
    
    const size_t solveDepth(AVLNode<T> *tree) const;
    
    inline const long getHeight(AVLNode<T> *tree) const;
    
    inline long get_lrc_max_height(AVLNode<T> *tree) const;
    
    bool isNotBalanced(AVLNode<T> *tree) const;
    
    const size_t solveBalanceFactor(AVLNode<T> *tree) const;
    
    
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
void AVLTree<T>::remove(const T data) {
    remove(this->root, data);
}

template <class T>
void * AVLTree<T>::findMin() const {
    AVLNode<T> *node = findMin(this->root);
    return node ? node->obj : nullptr;
}

template <class T>
void * AVLTree<T>::findMax() const {
    AVLNode<T> *node = findMax(this->root);
    return node ? node->obj : nullptr;
}

template <class T>
void * AVLTree<T>::findData(const T data) const {
    AVLNode<T> *node = existData(this->root, data);
    return node ? node->obj : nullptr;
}

//template <class T>
//void ** AVLTree<T>::DLR(const size_t n) const {
////    size_t n = solveCount();
//    AVLNode<T> **nodes = new AVLNode<T> *[n];
//
//    size_t idx = 0;
//    DLR(this->root, nodes, idx);
//
//    void **objs = convert_objs(nodes, n);
//
//    delete [] nodes;
//
//    return objs; // 不用时需要在函数外部 delete [] objs;
//}

template <class T>
void AVLTree<T>::DLR(void *objs[], const size_t n) const {
    AVLNode<T> **nodes = new AVLNode<T> *[n];
    size_t idx = 0;
    DLR(this->root, nodes, idx, n);
    
    for (size_t idx = 0; idx != n; idx++) {
        AVLNode<T> *node = nodes[idx];
        objs[idx] = node ? node->obj : nullptr;
    }
    delete [] nodes;
}

//template <class T>
//void ** AVLTree<T>::LDR(const size_t n) const {
////    size_t n = solveCount();
//    AVLNode<T> **nodes = new AVLNode<T> *[n];
//
//    size_t idx = 0;
//    LDR(this->root, nodes, idx, n);
//
//    void **objs = convert_objs(nodes, n);
//
//    delete [] nodes;
//
//    return objs;
//}

template <class T>
void AVLTree<T>::LDR(void *objs[], const size_t n) const {
    AVLNode<T> **nodes = new AVLNode<T> *[n];
    size_t idx = 0;
    LDR(this->root, nodes, idx, n);
    
    for (size_t i = 0; i != n; i++) {
        objs[i] = nodes[i] ? nodes[i]->obj: nullptr;
    }
    delete [] nodes;
}

template <class T>
void AVLTree<T>::LRD(void *objs[], const size_t n) const {
    AVLNode<T> **nodes = new AVLNode<T> *[n];
    size_t idx = 0;
    LRD(this->root, nodes, idx, n);
    
    for (size_t idx = 0; idx != n; idx++) {
        objs[idx] = nodes[idx] ? nodes[idx]->obj: nullptr;
    }
    delete [] nodes;
}

//template <class T>
//void ** AVLTree<T>::LRD(const size_t n) const {
////    size_t n = solveCount();
//    AVLNode<T> **nodes = new AVLNode<T> *[n];
//
//    size_t idx = 0;
//    LRD(this->root, nodes, idx, n);
//
//    void **objs = convert_objs(nodes, n);
//
//    delete [] nodes;
//
//    return objs;
//}


template <class T>
const size_t AVLTree<T>::solveCount() const {
    return solveCount(this->root);
}

//template <class T>
//void ** AVLTree<T>::levelTraversal(const size_t n) {
////    size_t n = solveCount();
//    
//    AVLNode<T> ** deque = levelTraversal(this->root, n);
//    
//    void ** objs = new void *[n];
//    
//    for (size_t idx = 0; idx != n; idx++) {
//        objs[idx] = deque[idx]->obj;
//    }
//    
//    delete [] deque;
//    
//    return objs; // 不用时需要在函数外部 delete [] objs;
//}

template <class T>
void AVLTree<T>::levelTraversal(void *objs[], const size_t n) {

    AVLNode<T> ** deque = levelTraversal(this->root, n);

    for (size_t idx = 0; idx != n; idx++) {
        objs[idx] = deque[idx] ? deque[idx]->obj : nullptr;
        
    }

    delete [] deque;
}

template <class T>
void ** AVLTree<T>::convert_objs(AVLNode<T> **nodes, const size_t n) const {
    void ** objs = new void *[n];
    
    for (size_t idx = 0; idx != n; idx++) {
        objs[idx] = nodes[idx] ? nodes[idx]->obj : nullptr;
    }
    
    return objs; // 不用时需要在函数外部 delete [] objs;
}

template <class T>
size_t AVLTree<T>::solveCount(AVLNode<T> *tree) const {
    if (tree == nullptr) {
        return 0;
    } // 函数调用按操作符左结合性（从左到右递归）
    return solveCount(tree->left) + solveCount(tree->right) + 1;
//  or e.g.
//    size_t lch = solveCount(tree->left);
//    size_t rch = solveCount(tree->right);
//    return (lch + rch) + 1;
}

#pragma mark - Private Function IMP

template <class T>
void AVLTree<T>::insert(AVLNode<T>* &tree, void *obj, const T data) {
    if (tree == nullptr) {
        tree = new AVLNode<T>(obj, data);
        
    } else if (data < tree->data) {
        insertLC(tree, obj, data);
        
    } else if (data > tree->data) {
        insertRC(tree, obj, data);
        
    } else { // if (data = tree->data)
        if (getHeight(tree->left) <= getHeight(tree->right)) {
            insertLC(tree, obj, data);
            
        } else {
            insertRC(tree, obj, data);
        }
    }
    
    tree->height = get_lrc_max_height(tree) + 1;
}

template <class T>
void AVLTree<T>::insertLC(AVLNode<T>* &tree, void *obj, const T data) {
    insert(tree->left, obj, data);
    if (isNotBalanced(tree)) {
        if (data < tree->left->data) {
            tree = LL(tree);
        } else {
            tree = LR(tree);
        }
    }
}

template <class T>
void AVLTree<T>::insertRC(AVLNode<T>* &tree, void *obj, const T data) {
    insert(tree->right, obj, data);
    if (isNotBalanced(tree)) {
        if (data > tree->right->data) {
            tree = RR(tree);
        } else {
            tree = RL(tree);
        }
    }
}

template <class T>
void AVLTree<T>::remove(AVLNode<T>* &tree, const T data) {
    if (tree == nullptr) {
        return;
    }
    
    if (data < tree->data) {
        remove(tree->left, data);
        if (isNotBalanced(tree)) {
            tree = getHeight(tree->right->right) >= getHeight(tree->right->left) ? RR(tree) : RL(tree);
        } else {
            tree->height = get_lrc_max_height(tree) + 1;
        }
        
    } else if (data > tree->data) {
        remove(tree->right, data);
        
        if (isNotBalanced(tree)) {
            tree = getHeight(tree->left->left) >= getHeight(tree->left->right) ? LL(tree) : LR(tree);
        } else {
            tree->height = get_lrc_max_height(tree) + 1;
        }
        
    } else { // if (data == tree->data)
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
            
        } else if (tree->left == nullptr && tree->right == nullptr) {
            AVLNode<T> *t = tree;
            delete t;
            tree = nullptr;
            
        } else { // if (tree->left != nullptr || tree->right != nullptr)
            AVLNode<T> *nt = tree->left ? tree->left : tree->right;
            delete tree;
            tree = nt;
        }
    }
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
void AVLTree<T>::DLR(AVLNode<T> *tree) const {
    if (tree) {
        std::cout << tree->data << ' ';
        DLR(tree->left);
        DLR(tree->right);
    }
}

template <class T>
void AVLTree<T>::DLR(AVLNode<T> *tree, AVLNode<T> *nodes[], size_t &idx, const size_t n) const {
    if (tree) {
        if (idx <= n) {
            nodes[idx++] = tree;
            std::cout << tree->data << ' ';
        }
        DLR(tree->left, nodes, idx, n);
        DLR(tree->right, nodes, idx, n);
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
void AVLTree<T>::LDR(AVLNode<T> *tree, AVLNode<T> *nodes[], size_t &idx, const size_t n) const {
    if (tree) {
        LDR(tree->left, nodes, idx, n);
        if (idx <= n) {
            nodes[idx++] = tree;
            std::cout << tree->data << ' ';
        }
        LDR(tree->right, nodes, idx, n);
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
void AVLTree<T>::LRD(AVLNode<T> *tree, AVLNode<T> *nodes[], size_t &idx, const size_t n) const {
    if (tree) {
        LRD(tree->left, nodes, idx, n);
        LRD(tree->right, nodes, idx, n);
        if (idx <= n) {
            nodes[idx++] = tree;
            std::cout << tree->data << ' ';
        }
    }
}

template <class T>
AVLNode<T> ** AVLTree<T>::levelTraversal(AVLNode<T> *tree, const size_t n) {
    if (tree == nullptr) {
        return nullptr;
    }
    
    AVLNode<T> ** deque = new AVLNode<T> *[n];
    size_t in = 0, out = 0;
    deque[in++] = tree;
    
    while (out < in) {
        std::cout << deque[out]->data << " -> ";
        AVLNode<T> *lc = deque[out]->left;
        if (lc) deque[in++] = lc;
        
        AVLNode<T> *rc = deque[out]->right;
        if (rc) deque[in++] = rc;
        
        ++out;
    }
    
    return deque; // 不用时需要在函数外部 delete [] deque;
}

template <class T>
void AVLTree<T>::levelTraversal(AVLNode<T> *tree) {
    if (tree == nullptr) {
        return;
    }
    
    AVLNode<T> *deque[1000] = {};
    size_t in = 0, out = 0;
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
const size_t AVLTree<T>::solveDepth(AVLNode<T> *tree) const {
    if (tree == nullptr) {
        return 0;
    }
    
    size_t lh = solveDepth(tree->left);
    
    size_t rh = solveDepth(tree->right);
    
    return (lh >= rh ? lh : rh) + 1;
}

template <class T>
inline const long AVLTree<T>::getHeight(AVLNode<T> *tree) const {
    if (tree == nullptr) {
        return -1;
    }
    return tree->height;
}

template <class T>
inline long AVLTree<T>::get_lrc_max_height(AVLNode<T> *tree) const {
    long lh = getHeight(tree->left);
    long rh = getHeight(tree->right);
    return lh > rh ? lh : rh;
}

template <class T>
bool AVLTree<T>::isNotBalanced(AVLNode<T> *tree) const {
    return solveBalanceFactor(tree);
}

template <class T>
const size_t AVLTree<T>::solveBalanceFactor(AVLNode<T> *tree) const {
    long differ = getHeight(tree->left) - getHeight(tree->right);
    return std::abs(differ) > 1;
}

template <class T>
AVLNode<T> * AVLTree<T>::LL(AVLNode<T> *tree) {
    AVLNode<T> *nt = tree->left;
    
    tree->left = nt->right;
    
    nt->right = tree;
    
    tree->height = get_lrc_max_height(tree) + 1;
    
    nt->height = get_lrc_max_height(nt) + 1;
    
    return nt;
}

template <class T>
AVLNode<T> * AVLTree<T>::RR(AVLNode<T> *tree) {
    AVLNode<T> *nt = tree->right;
    
    tree->right = nt->left;
    
    nt->left = tree;

    tree->height = get_lrc_max_height(tree) + 1;
    
    nt->height = get_lrc_max_height(nt) + 1;
    
    return nt;
}

template <class T>
AVLNode<T> * AVLTree<T>::LR(AVLNode<T> *tree) {
    AVLNode<T> *llt = RR(tree->left); // 把左子树当成RR树，先对左子树做一次左旋，然后整棵树就变成了LL树
    tree->left = llt;
    return LL(tree); // 再对整棵LL树做右旋
}

template <class T>
AVLNode<T> * AVLTree<T>::RL(AVLNode<T> *tree) {
    AVLNode<T> *rrt = LL(tree->right); // 把右子树当成LL树，先对右子树做一次右旋，然后整棵树就变成了RR树
    tree->right = rrt;
    return RR(tree); // 再对整棵RR树做一次左旋
}

#endif /* AVLTree_hpp */
