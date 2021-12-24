//
//  main.cpp
//  BalancedBinaryTree
//
//  Created by admin on 2021/12/3.
//

#include <iostream>
#include "AVLTree/AVLTree.hpp"
#include "ThreadModel.hpp"

void buildAVLTree() {
//    int ary[11] = {6, 3, 7, 1, 4, 2, 8, 10, 5, 9, 11};
//    int ary[6] = {6, 3, 7, 1, 4, 8};
    
//    unsigned int count = sizeof(ary) / sizeof(int);
    
//    const size_t cnt = 10;
//    std::string names[cnt] = {"线程0", "线程1", "线程2", "线程3", "线程4", "线程5", "线程6", "线程7", "线程8", "线程9"};
//    double prices[cnt] = {9, 6, 7, 4, 2, 8, 1, 10, 4, 3};
    
    // 方式一：动态指针数组（堆区）用于 存储动态对象（堆区）
    size_t n = 100;
    ThreadModel **objs = new ThreadModel* [n];
    for (size_t idx = 1; idx != 100; idx++) {
        string *name = new string("线程" + std::to_string(idx));
        ThreadModel *thread = new ThreadModel(*name, idx);
        std::cout << thread->getName() << " " << thread->getLevel() << " " << "\n";
        objs[idx] = thread;
    }
    std::cout << "\n";
    
    AVLTree<size_t> *tree = new AVLTree<size_t>;
//    AVLTree<int> tree = AVLTree<int>();
    
    for (int idx = 0; idx != n; idx++) {
        tree->insert(objs[idx], objs[idx]->getLevel());
    }

//    tree->DLR(tree->root);
//    std::cout << "\n";
//
    int cnt = 0;
    tree->LDR(objs, cnt);
    std::cout << "\n";
//
//    tree->LRD(tree->root);
//    std::cout << "\n";
//
//    tree->levelTraversal(tree->root);
//    std::cout << "\n";
//
//    AVLNode<int> *node = tree->existData(tree->root, 7);
//    if (node != nullptr) {
//        std::cout << "exist node data = " << node->data << "\n";
//    }
//    std::cout << "\n";
//
//    AVLNode<int> *maxNode = tree->findMax(tree->root);
//    if (maxNode != nullptr) {
//        std::cout << "find max node data = " << maxNode->data << "\n";
//    }
//
//    AVLNode<int> *minNode = tree->findMin(tree->root);
//    if (minNode != nullptr) {
//        std::cout << "find min node data = " << minNode->data << "\n";
//    }
//
//    int cnt = tree->solveCount(tree->root);
//    std::cout << "tree solve count = " << cnt << "\n";
//    std::cout << "\n";
//
//    if (tree->remove(tree->root, 6)) {
//        std::cout << "remove 6 of node is ok" << "\n";
//    }
//    tree->levelTraversal(tree->root);
//    std::cout << "\n\n";
    
    /*
    std::cout << "remove 2 of node" << "\n";
    tree->remove(tree->root, 2);
    tree->levelTraversal(tree->root);
    std::cout << "\n\n";
    
    std::cout << "remove 7 of node" << "\n";
    tree->remove(tree->root, 7);
    tree->levelTraversal(tree->root);
    std::cout << "\n\n";
    */
    
    delete [] objs;
    delete tree;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    buildAVLTree();
    return 0;
}
