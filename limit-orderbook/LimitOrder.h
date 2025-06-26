#ifndef LIMIT_ORDER_H
#define LIMIT_ORDER_H

#include "Order.h"

class LimitOrder : public Order {
    private:
        double price;

    public:
        LimitOrder(unsigned int _id, unsigned long int _timestamp,  bool _type, unsigned int _quantity, double _price);

        double get_price(){return price;}

        void set_price(double _price){price = _price;}
};

#endif