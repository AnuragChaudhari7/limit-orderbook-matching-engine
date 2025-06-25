#include "OrderBook.h"
#include "Order.h"
#include "LimitOrder.h"

OrderBook::OrderBook(){
    /*Default map & deque constructors*/
}

unsigned int OrderBook::submitLimitOrder(unsigned int quantity, bool type, double price){
    /*NOTE: (temporary) generate id & timestamp*/
    unsigned int id = 7;
    unsigned long int timestamp = 10;

    /*Matching Logic*/
    if(!type){ //Buy Order
        
        auto price_it = ask_book.begin();
        while(price_it != ask_book.end()) {
            if(price_it->first > price) break;

            auto& order_queue = price_it->second;

            while(!order_queue.empty()){
                unsigned int order_quantity = order_queue.front().get_quantity();
                
                if(quantity > order_quantity) {
                    quantity -= order_quantity;
                    order_queue.pop_front();
                }
                else if(quantity < order_quantity) {
                    order_queue.front().set_quantity(order_quantity - quantity);
                    return id;
                }
                else {
                    order_queue.pop_front();
                    if(order_queue.empty()) {
                        price_it = ask_book.erase(price_it);
                    }
                    return id;
                }
            }

            /*If queue is empty after loop, erase from ask book*/
            price_it = ask_book.erase(price_it);
        }

        /*Residual Limit Order Quantity - insert into bid book*/
        // deque<Order> not deque<LimitOrder>
        bid_book[price].emplace_back(id, timestamp, quantity, type, price); //N.B. emplace_back == push_back(Order())
    }

    // else{ //Sell Order
        
    // }
    return 0;
}