#ifndef ORDER_H
#define ORDER_H

class Order{
    private:
        unsigned int id; //NOTE: generate unique IDs?
        unsigned long int timestamp; //NOTE: Unix Epoch?
        unsigned int quantity;
        bool type; //(0: buy, 1: sell)

    public:
        Order(unsigned int _id, unsigned long int _timestamp, unsigned int _quantity, bool _type);

        unsigned int get_id(){return id;}

        unsigned long int get_timestamp(){return timestamp;}

        unsigned int get_quantity(){return quantity;}

        bool get_type(){return type;}

        void set_quantity(unsigned int _quantity){quantity = _quantity;}
};

#endif