//
//  GoodsModel.cpp
//  BinaryHeap
//
//  Created by admin on 2021/12/13.
//

#include "GoodsModel.hpp"

GoodsModel::GoodsModel(string name, double price) : name(name), price(price) { }

void GoodsModel::setName(string name) {
    this->name = name;
}

string GoodsModel::getName() const {
    return this->name;
}

void GoodsModel::setPrice(double price) {
    this->price = price;
}

double GoodsModel::getPrice() const {
    return this->price;
}
