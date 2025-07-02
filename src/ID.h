#ifndef ID_H
#define ID_H

#include <chrono>
#include <stdint.h>
using namespace std;
using namespace chrono;
//using time_stamp = time_point<system_clock,microseconds>;


class ID {
    private:
        ID(){}
        static uint32_t counter;
        
    public:
        static __uint128_t generate_order_id(uint32_t user_id);
        
};

#endif