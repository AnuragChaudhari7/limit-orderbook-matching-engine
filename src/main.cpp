#include <iostream>
#include <string>

#include "OrderBook.h"
#include "Order.h"
#include "LimitOrder.h"
#include "CSVParser.h"
using namespace std;

int main(){
    //cout << "Its ALIVEE" << endl;
    OrderBook book = OrderBook();
    CSVParser parser = CSVParser(book);
    int status = parser.process_csv("data/example1.csv");
    cout << "Bid Order Quantity: " << book.get_bid_book()[100].front()->get_quantity() << endl;
    cout << "Bid Order Price: $" << dynamic_pointer_cast<LimitOrder>(book.get_bid_book()[100].front())->get_price() << endl;
    cout << "Bid Order Timestamp: " << book.get_bid_book()[100].front()->get_timestamp() << endl;
    // bool type = 0; //0: buy
    // double price = 110;
    // unsigned int quantity = 10;

    // book.submitLimitOrder(type, quantity, price); //0: buy
    // cout << "Bid Order Quantity: " << book.get_bid_book()[price].front()->get_quantity() << endl;
    // cout << "Bid Order Price: $" << dynamic_pointer_cast<LimitOrder>(book.get_bid_book()[price].front())->get_price() << endl;

    // type = 1; //1: sell
    // price = 110;
    // quantity = 15;
    // book.submitLimitOrder(type, quantity, price); //1: sell
    // cout << "Ask Order Quantity: " << book.get_ask_book()[price].front()->get_quantity() << endl;
    // cout << "Ask Order Price: $" << dynamic_pointer_cast<LimitOrder>(book.get_ask_book()[price].front())->get_price() << endl;

    return status;
}