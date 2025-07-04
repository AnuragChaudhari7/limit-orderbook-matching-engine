#include <iostream>
#include <string>
#include <chrono>

#include "OrderBook.h"
#include "Order.h"
#include "LimitOrder.h"
#include "CSVParser.h"
#include "ID.h"
using namespace std;
using namespace chrono;

int main(){
    //cout << "Its ALIVEE" << endl;
    OrderBook book1 = OrderBook();
    OrderBook book2 = OrderBook();
    OrderBook book3 = OrderBook();
    string filepath = "data/orders10k.csv";
    int numRecords = 30000;
    int status = 0;
    /**
     * CSV file checking/simulation
     */

    CSVParser parser1 = CSVParser(book1);
    CSVParser parser2 = CSVParser(book2);
    CSVParser parser3 = CSVParser(book3);

    auto start_time = high_resolution_clock::now();
    status = parser1.process_csv(filepath);
    status = parser2.process_csv(filepath);
    status = parser3.process_csv(filepath);
    auto end_time = high_resolution_clock::now();
    // cout << "Bid Order Quantity: " << book.get_bid_book()[100].front()->get_quantity() << endl;
    // cout << "Bid Order Price: $" << dynamic_pointer_cast<LimitOrder>(book.get_bid_book()[100].front())->get_price() << endl;
    // cout << "Bid Order Timestamp: " << book.get_bid_book()[100].front()->get_timestamp() << endl;
    

    /**
     * Non CSV file sanity checkinf
     */

    // bool side = 0; //0: buy
    // double price = 110;
    // unsigned int quantity = 10;

    // book.submitLimitOrder(side, quantity, price); //0: buy
    // cout << "Bid Order Quantity: " << book.get_bid_book()[price].front()->get_quantity() << endl;
    // cout << "Bid Order Price: $" << dynamic_pointer_cast<LimitOrder>(book.get_bid_book()[price].front())->get_price() << endl;
    // cout << "Bid Order ID user_id: " << book.get_bid_book()[price].front()->get_id().user_id << endl;
    // cout << "Bid Order ID timestamp: " << book.get_bid_book()[price].front()->get_id().timestamp << endl;
    // cout << "Bid Order ID counter: " << book.get_bid_book()[price].front()->get_id().counter << endl;

    // side = 0; //1: sell
    // price = 120;
    // quantity = 5;

    // book.submitLimitOrder(side, quantity, price); 
    // cout << "Bid Order Quantity: " << book.get_bid_book()[price].front()->get_quantity() << endl;
    // cout << "Bid Order Price: $" << dynamic_pointer_cast<LimitOrder>(book.get_bid_book()[price].front())->get_price() << endl;
    // cout << "Bid Order ID user_id: " << book.get_bid_book()[price].front()->get_id().user_id << endl;
    // cout << "Bid Order ID timestamp: " << book.get_bid_book()[price].front()->get_id().timestamp << endl;
    // cout << "Bid Order ID counter: " << book.get_bid_book()[price].front()->get_id().counter << endl;
    
    duration<double> elapsed = end_time - start_time;
    //NOTE: might need more granular than seconds
    cout << "Processed " << numRecords << " records in: "  << elapsed.count() << " seconds" << endl;
    return status;
}