#include "ID.h"

__uint128_t ID::generate_order_id(uint32_t user_id){
    //Get timestamp
    uint64_t timestamp = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

    //get & increment counter
    //TODO: Need to make this threadsafe eventually. Does the counter overflow automatically without error?
    counter++;

    // join these & user_id together
    //TODO: typecast user_id to __int 28 first?
    __uint128_t order_id = ((__uint128_t) user_id << 96) | ((__uint128_t) timestamp << 32) | ((__uint128_t) counter);
    return order_id;
}