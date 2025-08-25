#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

class Logger {
    public:
        Logger();

        ~Logger();

        void log(unsigned long int timestamp, string action, order_id order_id, bool side, unsigned int quantity, double price);
        
    private:
        ofstream logFile;
};

#endif