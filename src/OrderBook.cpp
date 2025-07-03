#include "OrderBook.h"
#include "Order.h"
#include "LimitOrder.h"

OrderBook::OrderBook(){
    /*Default map & deque constructors*/
}

order_id OrderBook::submitLimitOrder(bool type, unsigned int quantity, double price, const uint32_t user_id){
    
    order_id id = ID::generate_order_id(user_id);
    unsigned long int timestamp = time(nullptr);

    //TODO: order_queue.front()->... therefore ensure not null
    /*Matching Logic*/
    if(!type){ //Buy Order
        
        auto ask_it = ask_book.begin();
        while(ask_it != ask_book.end()) {
            if(ask_it->first > price) break;

            auto& order_queue = ask_it->second;

            while(!order_queue.empty()){
                unsigned int order_quantity = order_queue.front()->get_quantity();
                
                if(quantity > order_quantity) {
                    quantity -= order_quantity;
                    order_queue.pop_front();
                }
                else if(quantity < order_quantity) {
                    order_queue.front()->set_quantity(order_quantity - quantity);
                    return id;
                }
                else {
                    order_queue.pop_front();
                    if(order_queue.empty()) {
                        ask_it = ask_book.erase(ask_it);
                    }
                    return id;
                }
            }

            /*If queue is empty after loop, erase from ask book*/
            ask_it = ask_book.erase(ask_it);
        }

        /*Residual Limit Order Quantity - insert into bid book*/
        // deque<shared_ptr<Order>> not deque<shared_ptr<LimitOrder>>
        bid_book[price].emplace_back(make_shared<LimitOrder>(id, timestamp, type, quantity, price));
    }

    else{ //Sell Order
        auto bid_it = bid_book.rbegin();
        while(bid_it != bid_book.rend()) {
            if(bid_it->first < price) break;

            auto& order_queue = bid_it->second;

            while(!order_queue.empty()){
                unsigned int order_quantity = order_queue.front()->get_quantity();
                
                if(quantity > order_quantity) {
                    quantity -= order_quantity;
                    order_queue.pop_front();
                }
                else if(quantity < order_quantity) {
                    order_queue.front()->set_quantity(order_quantity - quantity);
                    return id;
                }
                else {
                    order_queue.pop_front();
                    if(order_queue.empty()) {
                        //N.B. Assumes bid_it != bid_book.end() (holds due to outer while loop and we're not messing with it)
                        auto base_it = next(bid_it).base();
                        base_it = bid_book.erase(base_it);
                        bid_it = make_reverse_iterator(base_it);
                    }
                    return id;
                }
            }

            /*If queue is empty after loop, erase from ask book*/
            //N.B. Assumes bid_it != bid_book.end() (holds due to outer while loop and we're not messing with it)
            auto base_it = next(bid_it).base();
            base_it = bid_book.erase(base_it);
            bid_it = make_reverse_iterator(base_it);
        }

        /*Residual Limit Order Quantity - insert into ask book*/
        // deque<shared_ptr<Order>> not deque<shared_ptr<LimitOrder>>
        ask_book[price].emplace_back(make_shared<LimitOrder>(id, timestamp, type, quantity, price));
    }
    return id;
}