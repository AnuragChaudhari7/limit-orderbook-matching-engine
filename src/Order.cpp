#include "Order.h"

Order::Order(order_id _id, unsigned long int _timestamp, bool _side, unsigned int _quantity)
    : id(_id), timestamp(_timestamp), side(_side), quantity(_quantity) {}