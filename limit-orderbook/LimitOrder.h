#ifndef LIMIT_ORDER_H
#define LIMIT_ORDER_H

#include "Order.h"

class LimitOrder : public Order {
    private:
        /*Fields (additional for LimitOrder)*/
        double price; //TODO: Not sure if it should be double (must be +ve though)
    public:
        LimitOrder(unsigned int _id, unsigned long int _timestamp, unsigned int _quantity, bool _type, double _price);
        //TODO: Getter for price
};

#endif