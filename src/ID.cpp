#include "ID.h"

order_id ID::generate_order_id(uint32_t user_id){
    //Get timestamp
    uint64_t timestamp = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

    //get & increment counter
    //TODO: Need to make this threadsafe eventually. Does the counter overflow automatically without error?
    counter++;

    // join these & user_id together
    order_id oid = { user_id, timestamp, counter };
    
    return oid;
}