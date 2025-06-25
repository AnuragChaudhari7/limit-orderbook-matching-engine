#include <iostream>
#include <string>

#include "OrderBook.h"
#include "Order.h"
#include "LimitOrder.h"
using namespace std;

int main(){
    //cout << "Its ALIVEE" << endl;
    OrderBook book = OrderBook();
    double price = 105;
    unsigned int quantity = 4;

    book.submitLimitOrder(quantity, 0, price); //0: buy
    cout << "Order Quantity: " << book.get_bid_book()[price].front()->get_quantity() << endl;
    cout << "Order Price: $" << dynamic_pointer_cast<LimitOrder>(book.get_bid_book()[price].front())->get_price() << endl;

    price = 200;
    quantity = 50;
    book.submitLimitOrder(quantity, 0, price); //0: buy
    cout << "Order Quantity: " << book.get_bid_book()[price].front()->get_quantity() << endl;
    cout << "Order Price: $" << dynamic_pointer_cast<LimitOrder>(book.get_bid_book()[price].front())->get_price() << endl;

    return 0;
}
