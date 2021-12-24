//
//  main.cpp
//  BinaryHeap
//
//  Created by admin on 2021/12/11.
//

#include "BinTHeap.hpp"

#include "GoodsModel.hpp"

#include <iostream>

void heap_sort() {
    
    const size_t cnt = 10;
    std::string names[cnt] = {"商品A", "商品B", "商品C", "商品D", "商品E", "商品F", "商品G", "商品H", "商品E", "商品R"};
    double prices[cnt] = {9.99, 6.21, 7.32, 4.45, 2.64, 8.11, 1.50, 10.11, 4.99, 3.21};
//    const size_t cnt = sizeof(prices) / sizeof(double)
    /*
    // 方式一：动态指针数组（堆区）用于 存储动态对象（堆区）
    GoodsModel **objs = new GoodsModel* [cnt];
    for (size_t idx = 0; idx != cnt; idx++) {
        GoodsModel *goods = new GoodsModel(names[idx], prices[idx]);
        std::cout << goods->getName() << " " << goods->getPrice() << " " << "\n";
        objs[idx] = goods;
    }
    std::cout << "\n";
    */
    
    // 方式二：静态指针数组（栈区）用于 存储局部静态对象（栈区）
    GoodsModel *objs[cnt] = {nullptr};
    GoodsModel objects[cnt] = {};
    for (size_t idx = 0; idx != cnt; idx++) {
        objects[idx] = GoodsModel(names[idx], prices[idx]);
        GoodsModel *obj = &objects[idx];
        objs[idx] = obj;
        std::cout << obj->getName() << " " << obj->getPrice() << " " << "\n";
    }
    std::cout << "\n";

    BinTHeap<double> *heap = new BinTHeap<double>(); // (cnt, true)
    //    heap->build(nodes, cnt);
    for (size_t idx = 0; idx != cnt; idx++) {
        GoodsModel *obj = objs[idx];
        heap->push(obj, obj->getPrice());
    }
    
    std::cout << "is empty = " << heap->isEmpty() << "\n";
    std::cout << "top = " << heap->top() << "\n";
    std::cout << "size = " << heap->getSize() << "\n";
    std::cout << "capacity = " << heap->getCapacity() << "\n";
    std::cout << "\n";
    
    heap->print();
    
    /*
    for (size_t idx = 0; idx != cnt; idx++) {
        if (! heap->isEmpty()) {
            GoodsModel *obj = (GoodsModel *)heap->top();
            heap->pop();
            std::cout << obj->getName() << " " << obj->getPrice() << " " << "\n";
        }
    }
    std::cout << "\n";
     */
    
    
//    GoodsModel **objs = new GoodsModel* [cnt];
//    void **objs = new void* [cnt];
//    void *objs[cnt] = {};
    
    heap->sort_objs((void **)objs, cnt);
    
    for (size_t idx = 0; idx != cnt; idx++) {
        GoodsModel *obj = (GoodsModel *)objs[idx];
        std::cout << obj->getName() << " " << obj->getPrice() << " " << "\n";
    }
    std::cout << "\n";
    
//    delete [] objs;
    delete heap;
    
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
//    std::cout << "Hello, World!\n" << (3 >> 1) << std::endl;
    
    heap_sort();
    
    return 0;
}
