#ifndef ORDER_H
#define ORDER_H

class Order{
    private:
        /*Fields all orders should have*/
        unsigned int id; //NOTE: how to generate unique IDs?
        unsigned long int timestamp; //NOTE: What do we use? Unix Epoch?
        unsigned int quantity;
        bool type; //(0: buy, 1: sell)

    public:
        /*Constructor*/
        Order(unsigned int _id, unsigned long int _timestamp, unsigned int _quantity, bool _type);
        //TODO: Getters & setters for private fields
};

#endif