#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <iostream>
#include <fstream>
#include <string>

#include "OrderBook.h"
using namespace std;

class CSVParser {
    public:
        CSVParser();

        int read_csv(string path_to_csv);
};
#endif