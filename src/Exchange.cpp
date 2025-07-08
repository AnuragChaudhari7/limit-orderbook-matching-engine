#include "Exchange.h"


//TODO: Use function process_csv in the thread. But keep the function (check performance here!)
void Exchange::performance(string filepath){
    OrderBook book1 = OrderBook();
    OrderBook book2 = OrderBook();
    OrderBook book3 = OrderBook();
    OrderBook book4 = OrderBook();
    OrderBook book5 = OrderBook();
    OrderBook book6 = OrderBook();
    OrderBook book7 = OrderBook();
    OrderBook book8 = OrderBook();
    OrderBook book9 = OrderBook();
    OrderBook book10 = OrderBook();

    CSVParser parser1 = CSVParser(book1);
    CSVParser parser2 = CSVParser(book2);
    CSVParser parser3 = CSVParser(book3);
    CSVParser parser4 = CSVParser(book4);
    CSVParser parser5 = CSVParser(book5);
    CSVParser parser6 = CSVParser(book6);
    CSVParser parser7 = CSVParser(book7);
    CSVParser parser8 = CSVParser(book8);
    CSVParser parser9 = CSVParser(book9);
    CSVParser parser10 = CSVParser(book10);

    auto start_time = high_resolution_clock::now();

    thread t_book1(&CSVParser::process_csv, &parser1, filepath);
    thread t_book2(&CSVParser::process_csv, &parser2, filepath);
    thread t_book3(&CSVParser::process_csv, &parser3, filepath);
    thread t_book4(&CSVParser::process_csv, &parser4, filepath);
    thread t_book5(&CSVParser::process_csv, &parser5, filepath);
    thread t_book6(&CSVParser::process_csv, &parser6, filepath);
    thread t_book7(&CSVParser::process_csv, &parser7, filepath);
    thread t_book8(&CSVParser::process_csv, &parser8, filepath);
    thread t_book9(&CSVParser::process_csv, &parser9, filepath);
    thread t_book10(&CSVParser::process_csv, &parser10, filepath);

    t_book1.join();
    t_book2.join();
    t_book3.join();
    t_book4.join();
    t_book5.join();
    t_book6.join();
    t_book7.join();
    t_book8.join();
    t_book9.join();
    t_book10.join();

    // parser1.process_csv(filepath);
    // parser2.process_csv(filepath);
    // parser3.process_csv(filepath);
    // parser4.process_csv(filepath);
    // parser5.process_csv(filepath);
    // parser6.process_csv(filepath);
    // parser7.process_csv(filepath);
    // parser8.process_csv(filepath);
    // parser9.process_csv(filepath);
    // parser10.process_csv(filepath);

    auto end_time = high_resolution_clock::now();
    duration<double> elapsed = end_time - start_time;

    cout << "Processed in: " <<  elapsed.count() << " seconds" << endl;
}