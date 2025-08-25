#include "Logger.h"
#include "ID.h"

Logger::Logger(){
    string filename = "NERD-2025-08-25.log";
    logFile.open(filename);
    if (!logFile.is_open()){
        cerr << "Error opening file: " << filename << endl;
    }
}

Logger::~Logger(){
    logFile.close();
}

//NOTE: should action be an enum? And if so how does OrderBook access it?
void Logger::log(unsigned long int timestamp, string action, order_id order_id, bool side, unsigned int quantity, double price){
    // timestamp,action,order_id,side,quantity,price
    string side_str = (side) ? "buy" : "sell";
    string order_id_str = to_string(order_id);
    ostringstream logEntry;

    logEntry << timestamp << ","
        << action << ","
        << order_id_str << ","
        << side_str << ","
        << quantity << ","
        << price << endl;
    
    cout << logEntry.str();

    if (logFile.is_open()){
        logFile << logEntry.str();
        logFile.flush(); 
    }
}