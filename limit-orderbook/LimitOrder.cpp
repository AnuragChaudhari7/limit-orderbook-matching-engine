#include "Order.h"
#include "LimitOrder.h"

LimitOrder::LimitOrder(unsigned int _id, unsigned long int _timestamp, unsigned int _quantity, bool _type, double _price) :
    Order::Order(_id, _timestamp, _quantity, _type), price(_price) {}