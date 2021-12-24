//
//  main.cpp
//  BalancedBinaryTree
//
//  Created by admin on 2021/12/15.
//

#include <iostream>
#include "AVLTree/AVLTree.hpp"
#include "ThreadModel.hpp"

using namespace std;

void buildAVLTree() {
    /*
                            7
                    4                9
                2       6        8      10
              1   3  5                      11
     */
//    unsigned int count = sizeof(ary) / sizeof(int);
    // 方式0: 静态数据
        const size_t cnt = 11;
        size_t n = cnt;
        std::string names[cnt] = {"线程0", "线程1", "线程2", "线程3", "线程4", "线程5", "线程6", "线程7", "线程8", "线程9", "线程10"};
        size_t levels[cnt] = {9, 6, 7, 4, 2, 8, 1, 10, 5, 3, 11};
//    // or test OK
//    const size_t cnt = 12 + 12 + 5;
//    size_t n = cnt;
//    std::string names[cnt] = {"线程0", "线程1", "线程2", "线程3", "线程4", "线程5", "线程6", "线程7", "线程8", "线程9", "线程10", "线程11"};
//    size_t levels[cnt] = {9, 6, 7, 4, 2, 8, 1, 10, 5, 3, 11, 7, 7, 7, 4, 4, 8, 8, 9, 0, 1, 10, 6, 6, 5, 5, 0, 1, 2};
    AVLTree<size_t> *tree = new AVLTree<size_t>;
    for (size_t i = 0; i != cnt; i++) {
        ThreadModel *thread = new ThreadModel(names[i], levels[i]);
        std::cout << thread->getName() << " " << thread->getLevel() << ", ";
        tree->insert(thread, thread->getLevel());
    }
    
    /*
    // 方式一：动态指针数组（堆区）用于 存储动态对象（堆区）
    size_t n = 100;
    AVLTree<size_t> *tree = new AVLTree<size_t>;
    for (size_t idx = 0; idx != 100; idx++) {
        string *name = new string("线程" + std::to_string(idx));
        ThreadModel *thread = new ThreadModel(*name, idx);
        std::cout << thread->getName() << " " << thread->getLevel() << ", ";
        
        tree->insert(thread, thread->getLevel());
    }
    std::cout << "\n\n\n";
    */
    
    size_t count = tree->solveCount();
    std::cout << "tree->solveCount() = " << count << "\n";
    
    tree->remove(8);
//    tree->remove(5); tree->remove(0); tree->remove(0); tree->remove(7); tree->remove(7); tree->remove(1); tree->remove(1);
//    tree->remove(8); tree->remove(7); tree->remove(1); tree->remove(2); tree->remove(0); tree->remove(6); tree->remove(7);
    
    count = tree->solveCount(); // 重新算结点总数
    std::cout << "重新算结点总数 tree->solveCount() = " << count << "\n";
    
    n = count; // 更新结点总数
    
    ThreadModel *threadObj = (ThreadModel *)tree->findData(1);
    if (threadObj) {
        std::cout << "tree->getName() = " << threadObj->getName() << "\t" << "tree->findData(7) = " << threadObj->getLevel() << "\n";
    } else {
        std::cout << "未查询到1！tree->findData(1) = " << threadObj << "\n";
    }
    
    ThreadModel *max_obj = (ThreadModel *)tree->findMax();
    if (max_obj) std::cout << "tree->findMax() = " << max_obj->getLevel() << "\n";
    
    ThreadModel *min_obj = (ThreadModel *)tree->findMin();
    if (min_obj) std::cout << "tree->findMin() = " << min_obj->getLevel() << "\n";
    
    std::cout << "\n\n";
    
    {
        /** 前序遍历（深度优先搜索）：遍历的树中的每个结点并存放到数组 */
        std::cout << "前序遍历(DLR)：遍历的树中的每个结点并存放到数组:" << "\n\n";
        ThreadModel **dlr_objs = new ThreadModel* [n];
        tree->DLR((void **)dlr_objs, n);
        std::cout << "\n\n";
        for (int idx = 0; idx != n; idx++) {
            ThreadModel *thread = dlr_objs[idx];
            if (thread) std::cout << thread->getName() << " " << thread->getLevel() << ", ";
        }
        delete [] dlr_objs;
        std::cout << "\n\n" << std::endl;
    }
    
    {
        /** 中序遍历（深度优先搜索）：遍历的树中的每个结点并存放到数组 */
        std::cout << "中序遍历(LDR)：遍历的树中的每个结点并存放到数组:" << "\n\n";
        
        ThreadModel **ldr_objs = new ThreadModel* [n];
        tree->LDR((void **)ldr_objs, n);
        std::cout << "\n\n";
        for (int idx = 0; idx != n; idx++) {
            ThreadModel *thread = ldr_objs[idx];
            if (thread) std::cout << thread->getName() << " " << thread->getLevel() << ", ";
        } std::cout << endl;
        delete [] ldr_objs;
        std::cout << "\n\n" << std::endl;
    }

    {
        /** 后序遍历（深度优先搜索）：遍历的树中的每个结点并存放到数组 */
        std::cout << "后序遍历(LRD)：遍历的树中的每个结点并存放到数组:" << "\n\n";
        ThreadModel **lrd_objs = new ThreadModel* [n];
        tree->LRD((void **)lrd_objs, n);
        std::cout << "\n\n";
        for (int idx = 0; idx != n; idx++) {
            ThreadModel *thread = lrd_objs[idx];
            if (thread) std::cout << thread->getName() << " " << thread->getLevel() << ", ";
        } std::cout << endl;
        delete [] lrd_objs;
        std::cout << "\n\n" << std::endl;
    }

    {
        /** 层序遍历（广度优先搜索）：遍历的树中的每个结点并存放到数组 */
        std::cout << "层序遍历（广度优先搜索）：遍历的树中的每个结点并存放到数组:" << "\n\n";
        ThreadModel **lt_objs = new ThreadModel* [n];
        tree->levelTraversal((void **)lt_objs, n);
        std::cout << "\n\n";
        for (int idx = 0; idx != n; idx++) {
            ThreadModel *thread = lt_objs[idx];
            if (thread) std::cout << thread->getName() << " " << thread->getLevel() << ", ";
        } std::cout << endl;
        delete [] lt_objs;
        std::cout << "\n\n" << std::endl;
    }
    
    delete tree;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    buildAVLTree();
    return 0;
}
