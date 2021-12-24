//
//  ThreadModel.hpp
//  BalancedBinaryTree
//
//  Created by admin on 2021/12/15.
//

#ifndef ThreadModel_hpp
#define ThreadModel_hpp

#include <string>

using std::string;

class ThreadModel {
public:
    
    ThreadModel(string name, size_t level);
    
    ThreadModel();
    
    ThreadModel(const ThreadModel &obj);
    
    ThreadModel & operator=(const ThreadModel &obj);
    
    void setName(string name);
    
    string getName() const;
    
    void setLevel(size_t level);
    
    size_t getLevel() const;
    
private:
    string name;
    
    size_t level;
};

#endif /* ThreadModel_hpp */
