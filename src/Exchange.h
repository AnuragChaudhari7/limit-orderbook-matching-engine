#ifndef EXCHANGE_H
#define EXCHANGE_H

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "OrderBook.h"
#include "CSVParser.h"
using namespace std;
using namespace chrono;

//NOTE: For now hard code the 3 books, in future make constructor take a list
// of assets and accordingly create that many books
class Exchange {
    private:

    public:
        Exchange() {}

        void performance(string filepath);
        
};

#endif