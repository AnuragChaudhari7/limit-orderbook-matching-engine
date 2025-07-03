#ifndef ORDER_H
#define ORDER_H

#include <ctime>
#include "ID.h"

class Order{
    private:
        order_id id; //NOTE: generate unique IDs?
        time_t timestamp; //NOTE: Unix Epoch?
        bool type; //(0: buy, 1: sell)
        unsigned int quantity;

    public:
        Order(order_id _id, unsigned long int _timestamp, bool _type, unsigned int _quantity);

        virtual ~Order() = default;

        order_id get_id(){return id;}

        unsigned long int get_timestamp(){return timestamp;}

        bool get_type(){return type;}

        unsigned int get_quantity(){return quantity;}

        void set_quantity(unsigned int _quantity){quantity = _quantity;}
};

#endif