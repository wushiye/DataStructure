//
//  GoodsModel.hpp
//  BinaryHeap
//
//  Created by admin on 2021/12/13.
//

#ifndef GoodsModel_hpp
#define GoodsModel_hpp

#include <string>

using namespace std;

class GoodsModel {
public:
    
    GoodsModel(string name, double price);
    
    void setName(string name);
    
    string getName() const;
    
    void setPrice(double price);
    
    double getPrice() const;
    
private:
    string name;
    
    double price;
};

#endif /* GoodsModel_hpp */
