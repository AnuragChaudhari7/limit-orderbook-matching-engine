#ifndef ID_H
#define ID_H

#include <chrono>
#include <stdint.h>
#include <sstream>
using namespace std;
using namespace chrono;
//using time_stamp = time_point<system_clock,microseconds>;

struct order_id {
    uint32_t user_id;
    uint64_t timestamp;
    uint32_t counter;
};

std::string to_string(const order_id& id);

class ID {
    private:
        ID(){}
        static uint32_t counter;

    public:
        static order_id generate_order_id(uint32_t user_id);
};

#endif