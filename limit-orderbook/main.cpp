#include <iostream>
#include <string>

#include "OrderBook.h"
#include "Order.h"
#include "LimitOrder.h"
using namespace std;

int main(){
    //cout << "Its ALIVEE" << endl;
    OrderBook book = OrderBook();
    
    bool type = 0; //0: buy
    double price = 110;
    unsigned int quantity = 10;

    book.submitLimitOrder(type, quantity, price); //0: buy
    cout << "Bid Order Quantity: " << book.get_bid_book()[price].front()->get_quantity() << endl;
    cout << "Bid Order Price: $" << dynamic_pointer_cast<LimitOrder>(book.get_bid_book()[price].front())->get_price() << endl;

    type = 1; //1: sell
    price = 110;
    quantity = 15;
    book.submitLimitOrder(type, quantity, price); //1: sell
    cout << "Ask Order Quantity: " << book.get_ask_book()[price].front()->get_quantity() << endl;
    cout << "Ask Order Price: $" << dynamic_pointer_cast<LimitOrder>(book.get_ask_book()[price].front())->get_price() << endl;

    // /*Task Failed Succesfully - seg fault here since buy order got fully filled*/
    // cout << "Bid Order Quantity: " << book.get_bid_book()[price].front()->get_quantity() << endl;
    // cout << "Bid Order Price: $" << dynamic_pointer_cast<LimitOrder>(book.get_bid_book()[price].front())->get_price() << endl;

    return 0;
}