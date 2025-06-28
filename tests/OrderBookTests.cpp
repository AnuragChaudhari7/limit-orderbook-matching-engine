#include <gtest/gtest.h>
#include "OrderBook.h"
#include "Order.h"
#include "LimitOrder.h"

// TEST(LimitOrderBookTest, Sanity){
//     EXPECT_EQ(1, 1) << "You isda foool";
// }

/**
 * Method to test if 2 books match.
 * @return 
 *  0: equal
 *  1: difference in price of the levels
 *  2: order's price doesn't match its price level
 *  3: 0 quantity order not deleted
 *  4: incorrect order type in book
 *  5: order quantity not equal
 *  6: difference in # of orders in list for price level
 *  7: difference in # of price levels 
 */
int books_equal(map<double, deque<shared_ptr<Order>>> expected_book, map<double, deque<shared_ptr<Order>>> book){
    /*Iterators for the price levels*/
    auto expected_it = expected_book.begin();
    auto it = book.begin();

    while(expected_it != expected_book.end() && it != book.end()){
        if(expected_it->first != it->first){
            return 1; //price levels don't match
        }

        /*Get list of orders*/
        auto expected_orders = expected_it->second;
        auto orders = it->second;

        /*List of orders iterators*/
        auto expected_orders_it = expected_orders.begin();
        auto orders_it = orders.begin();

        while(expected_orders_it != expected_orders.end() && orders_it != orders.end()){
            //NOTE:In future with more order types, check nullptr on dynamic_pointer_cast

            auto order = dynamic_pointer_cast<LimitOrder>(*(orders_it));
            auto expected_order = dynamic_pointer_cast<LimitOrder>(*(expected_orders_it));

            if(order->get_price() != it->first){
                return 2; // order price doesnt match its price level
            }

            if(order->get_quantity() <= 0){
                return 3; //quantity <= 0, order shouldve been deleted
            }

            //TODO: Check if order type in actual matches expected
            if(expected_order->get_type() !=order->get_type()){
                return 4;
            }

            if(expected_order->get_quantity() != order->get_quantity()){
                return 5; //compared orders don't have same quantity
            }

            expected_orders_it++;
            orders_it++;
        }

        if(!(expected_orders_it == expected_orders.end() && orders_it == orders.end())){
            return 6; //both iterators didn't reach end (one of them has one more order => not same)
        }

        expected_it++;
        it++;
    }

    if(!(expected_it == expected_book.end() && it == book.end())){
        return 7; //both iterators didn't reach end (one of them has one more price level => not same)
    }

    return 0;
}

//TODO: Test the comparison function
TEST(BookEquality, EmptyBooks){
    map<double, deque<shared_ptr<Order>>> expected_book;
    map<double, deque<shared_ptr<Order>>> book;
    EXPECT_EQ(books_equal(expected_book, book), 0);
}

TEST(BookEquality, OneBuyLimitOrder){

}

TEST(BookEquality, OneSellLimitOrder){
    
}

TEST(BookEquality, CompleteMatchOneBuyOneSellLimit){
    
}

//TODO: Can I use a template to create book once? 
TEST(MatchingLogic, OneBuyLimitOrder){
    /*Limit Order Submission*/
    OrderBook book = OrderBook();
    book.submitLimitOrder(0, 5, 100);
    auto bid_book = book.get_bid_book();

    /*Expected Order Book*/
    map<double, deque<shared_ptr<Order>>> expected_bid_book;
    //NOTE: this is used to create and insert the orders you want (id, timestamp can be left redundant since comparison function won't compare these)
    expected_bid_book[100].emplace_back(make_shared<LimitOrder>(7, 10, 0, 5, 100));
    
    /*Check equality*/
    EXPECT_EQ(books_equal(expected_bid_book, bid_book), true);
}