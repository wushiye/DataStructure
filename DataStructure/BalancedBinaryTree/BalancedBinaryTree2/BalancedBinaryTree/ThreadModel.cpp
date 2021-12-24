//
//  ThreadModel.cpp
//  BalancedBinaryTree
//
//  Created by admin on 2021/12/15.
//

#include "ThreadModel.hpp"

ThreadModel::ThreadModel(string name, size_t level) : name(name), level(level) { }

ThreadModel::ThreadModel() : name(""), level(0.0) { }

ThreadModel::ThreadModel(const ThreadModel &obj) {
    if (this != &obj) {
        name = obj.name;
        level = obj.level;
    }
}

ThreadModel & ThreadModel::operator=(const ThreadModel &obj) {
    if (this != &obj) {
        name = obj.name;
        level = obj.level;
    }
    return *this;
}

void ThreadModel::setName(string name) {
    this->name = name;
}

string ThreadModel::getName() const {
    return this->name;
}

void ThreadModel::setLevel(size_t level) {
    this->level = level;
}

size_t ThreadModel::getLevel() const {
    return this->level;
}
