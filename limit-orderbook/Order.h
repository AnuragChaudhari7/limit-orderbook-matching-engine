#ifndef ORDER_H
#define ORDER_H

class Order{
    private:
        unsigned int id; //NOTE: generate unique IDs?
        unsigned long int timestamp; //NOTE: Unix Epoch?
        bool type; //(0: buy, 1: sell)
        unsigned int quantity;

    public:
        Order(unsigned int _id, unsigned long int _timestamp, bool _type, unsigned int _quantity);

        virtual ~Order() = default;

        unsigned int get_id(){return id;}

        unsigned long int get_timestamp(){return timestamp;}

        bool get_type(){return type;}

        unsigned int get_quantity(){return quantity;}

        void set_quantity(unsigned int _quantity){quantity = _quantity;}
};

#endif