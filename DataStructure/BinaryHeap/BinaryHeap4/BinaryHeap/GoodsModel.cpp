//
//  GoodsModel.cpp
//  BinaryHeap
//
//  Created by admin on 2021/12/13.
//

#include "GoodsModel.hpp"

GoodsModel::GoodsModel(string name, double price) : name(name), price(price) { }

GoodsModel::GoodsModel() : name(""), price(0.0) { }

GoodsModel::GoodsModel(const GoodsModel &obj) {
    if (this != &obj) {
        name = obj.name;
        price = obj.price;
    }
}

GoodsModel & GoodsModel::operator=(const GoodsModel &obj) {
    if (this != &obj) {
        name = obj.name;
        price = obj.price;
    }
    return *this;
}

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
