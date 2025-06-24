#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <map>
#include <deque>

#include "Order.h"
using namespace std;

class OrderBook {
    private: //NOTE: Extension plans: if you use a matching engine class, the derivative class needs access to books (protected)
        /*Fields*/
        map<double, deque<Order>> bid_book;
        map<double, deque<Order>> ask_book;
        //NOTE: In future, replace with custom trees instead of slow maps here (despite RBT)
    
    public:
        OrderBook();

        //NOTE: submitLimitOrder(), cancelLimitOrder(id), updateLimitOrder(id, quantity, price), go here as functions
        unsigned int submitLimitOrder(unsigned int quantity, bool type, double price);

};

#endif