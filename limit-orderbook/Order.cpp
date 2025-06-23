#include "Order.h"

Order::Order(unsigned int _id, unsigned long int _timestamp, unsigned int _quantity, bool _type)
    : id(_id), timestamp(_timestamp), quantity(_quantity), type(_type) {}