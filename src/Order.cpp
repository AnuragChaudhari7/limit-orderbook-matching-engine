#include "Order.h"

Order::Order(order_id _id, unsigned long int _timestamp, bool _type, unsigned int _quantity)
    : id(_id), timestamp(_timestamp), type(_type), quantity(_quantity) {}