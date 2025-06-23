class Order{
    /*Fields all orders should have*/
    unsigned int id; //TODO: how to generate unique IDs?
    unsigned long int timestamp; //TODO: What do we use? Unix Epoch?
    unsigned int quantity;
    bool type; //TODO: Should it be bool? its basically an int (0: buy, 1: sell)

    /*Constructor*/
    Order(unsigned int _id, unsigned long int _timestamp, unsigned int _quantity, bool _type);
};