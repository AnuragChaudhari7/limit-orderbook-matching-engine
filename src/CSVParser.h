#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "OrderBook.h"
using namespace std;

class CSVParser {
    private:
        OrderBook &book;
    
    public:
        CSVParser(OrderBook &_book);

        int process_csv(string path_to_csv);
};
#endif