// util.hpp

#ifndef UTIL_HPP
#define UTIL_HPP

#include <cstdint>
#include <chrono>

/* convenience function for epoch seconds */
inline int64_t epoch_sec(void){
    return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

/* convenience function for epoch milliseconds */
inline int64_t epoch_msec(void){
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

/* convenience function for epoch microseconds */
inline int64_t epoch_usec(void){
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

/* convenience function for epoch nanoseconds */
inline int64_t epoch_nsec(void){
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

#endif // UTIL_HPP
