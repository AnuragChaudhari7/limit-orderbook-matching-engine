#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <map>
#include <deque>

#include "Order.h"
#include "LimitOrder.h"
#include "ID.h"
using namespace std;

class OrderBook {
    private: //NOTE: Extension plans: if you use a matching engine class, the derivative class needs access to books (protected)
        //NOTE: Might be worth changing the price instead of double to be int due to floating point precision!
        /*Fields*/
        map<double, deque<shared_ptr<Order>>> bid_book;
        map<double, deque<shared_ptr<Order>>> ask_book;
        //NOTE: In future, replace with custom trees instead of slow maps here (despite RBT)
    
    public:
        OrderBook();

        //NOTE: submitLimitOrder(), cancelLimitOrder(id), updateLimitOrder(id, quantity, price), go here as functions
        order_id submitLimitOrder(bool type, unsigned int quantity , double price, const uint32_t user_id = 0x01234567);

        map<double, deque<shared_ptr<Order>>> get_bid_book(){return bid_book;}

        map<double, deque<shared_ptr<Order>>> get_ask_book(){return ask_book;}
};

#endif