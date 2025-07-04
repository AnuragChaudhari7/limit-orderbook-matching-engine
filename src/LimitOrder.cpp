#include "Order.h"
#include "LimitOrder.h"

LimitOrder::LimitOrder(order_id _id, unsigned long int _timestamp, bool _side, unsigned int _quantity, double _price) :
    Order::Order(_id, _timestamp, _side, _quantity), price(_price) {}