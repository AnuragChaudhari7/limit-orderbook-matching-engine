#include <iostream>
#include <string>

#include "OrderBook.h"
#include "Order.h"
#include "LimitOrder.h"
#include "CSVParser.h"
#include "ID.h"
using namespace std;

int main(){
    //cout << "Its ALIVEE" << endl;
    OrderBook book = OrderBook();

    // CSVParser parser = CSVParser(book);
    // int status = parser.process_csv("data/example1.csv");
    // cout << "Bid Order Quantity: " << book.get_bid_book()[100].front()->get_quantity() << endl;
    // cout << "Bid Order Price: $" << dynamic_pointer_cast<LimitOrder>(book.get_bid_book()[100].front())->get_price() << endl;
    // cout << "Bid Order Timestamp: " << book.get_bid_book()[100].front()->get_timestamp() << endl;
    
    bool type = 0; //0: buy
    double price = 110;
    unsigned int quantity = 10;

    book.submitLimitOrder(type, quantity, price); //0: buy
    cout << "Bid Order Quantity: " << book.get_bid_book()[price].front()->get_quantity() << endl;
    cout << "Bid Order Price: $" << dynamic_pointer_cast<LimitOrder>(book.get_bid_book()[price].front())->get_price() << endl;
    cout << "Bid Order ID user_id: " << book.get_bid_book()[price].front()->get_id().user_id << endl;
    cout << "Bid Order ID timestamp: " << book.get_bid_book()[price].front()->get_id().timestamp << endl;
    cout << "Bid Order ID counter: " << book.get_bid_book()[price].front()->get_id().counter << endl;

    type = 0; //1: sell
    price = 120;
    quantity = 5;

    book.submitLimitOrder(type, quantity, price); 
    cout << "Bid Order Quantity: " << book.get_bid_book()[price].front()->get_quantity() << endl;
    cout << "Bid Order Price: $" << dynamic_pointer_cast<LimitOrder>(book.get_bid_book()[price].front())->get_price() << endl;
    cout << "Bid Order ID user_id: " << book.get_bid_book()[price].front()->get_id().user_id << endl;
    cout << "Bid Order ID timestamp: " << book.get_bid_book()[price].front()->get_id().timestamp << endl;
    cout << "Bid Order ID counter: " << book.get_bid_book()[price].front()->get_id().counter << endl;

    return 0;
}