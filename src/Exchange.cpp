#include "Exchange.h"


//TODO: Use function process_csv in the thread. But keep the function (check performance here!)
void Exchange::performance(string filepath){
    OrderBook book = OrderBook();

    auto start_time = high_resolution_clock::now();
    auto end_time = high_resolution_clock::now();
    duration<double> elapsed = end_time - start_time;

    cout << "Processed in: " <<  elapsed.count() << " seconds" << endl;
}