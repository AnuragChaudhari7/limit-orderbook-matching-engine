#include "CSVParser.h"

CSVParser::CSVParser(OrderBook &_book) : book(_book) {} //use reference to directly access orderbook (not assignment)

int CSVParser::process_csv(string path_to_csv) {
    /*Setup file input stream*/
    ifstream file;
    string line = "";
    file.open(path_to_csv);

    /*Check header*/
    getline(file, line);
    if(line != "order_type,type,quantity,price"){
        cerr << "Error in " << path_to_csv << ": Unexpected CSV Header" << endl;
        return -1;
    }
    
    /*Go through lines (orders)*/
    while(getline(file, line)){
        /*Match the order_type*/
        stringstream order_stream(line);
        string s;
        getline(order_stream, s, ',');

        if(s == "LimitOrder"){
            cout << "Limit Order: ";
            /*Parse buy_or_sell, quantity, price*/
            getline(order_stream, s, ',');
            int type = stoi(s);
            //cout << type << ",";
            
            getline(order_stream, s, ',');
            unsigned int quantity = stoi(s);
            //cout << quantity << ",";

            getline(order_stream, s, ',');
            double price = stod(s);
            //cout << price << endl;

            book.submitLimitOrder(type, quantity, price);
        }
        else{
            cerr << "Error: Invalid Order Type" << endl;
        }
    }
    return 0;
}