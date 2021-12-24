//
//  main.cpp
//  BinaryHeap
//
//  Created by admin on 2021/12/11.
//

#include "BinTHeap.hpp"
#include "BinTNode.hpp"

#include "GoodsModel.hpp"

#include <iostream>

void heap_sort() {
    
    const size_t cnt = 10;
    std::string names[cnt] = {"商品A", "商品B", "商品C", "商品D", "商品E", "商品F", "商品G"};
    double prices[cnt] = {9.99, 6.21, 7.32, 4.45, 2.64, 8.11, 1.50, 10.11, 4.99, 3.21};
//    const size_t cnt = sizeof(prices) / sizeof(double);
    BinTNode<GoodsModel, double> **nodes = new BinTNode<GoodsModel, double> * [cnt]; // 指针数组
    for (size_t idx = 0; idx != cnt; idx++) {
        GoodsModel *goods = new GoodsModel(names[idx], prices[idx]);
        BinTNode<GoodsModel, double> *node = new BinTNode<GoodsModel, double>(goods, goods->getPrice());
        nodes[idx] = node;
    }
    
    for (size_t idx = 0; idx != cnt; idx++) {
        std::cout << nodes[idx]->obj->getName() << " " << nodes[idx]->obj->getPrice() << " " << "\n";
    }
    std::cout << "\n";
    
    BinTHeap<BinTNode<GoodsModel, double> > *heap = new BinTHeap<BinTNode<GoodsModel, double> >(); // (cnt, true)
    
    std::cout << "is empty = " << heap->isEmpty() << "\n";

    heap->build(nodes, cnt);
    
    
    std::cout << "is empty = " << heap->isEmpty() << "\n";
    
    std::cout << "top = " << heap->top() << "\n";
    
    std::cout << "size = " << heap->getSize() << "\n";
    
    std::cout << "capacity = " << heap->getCapacity() << "\n";
    
    heap->print();
    
    heap->sort(nodes, cnt);
    
    for (size_t i = 0; i != cnt; i++) {
        std::cout << nodes[i]->level << " ";
    }
    
    delete heap;
    delete [] nodes;
    
    std::cout << std::endl;
}


int main(int argc, const char * argv[]) {
//    std::cout << "Hello, World!\n" << (3 >> 1) << std::endl;
//    std::cout << "Hello, World!\n";
    
    heap_sort();
    
    return 0;
}
