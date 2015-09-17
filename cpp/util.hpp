// util.hpp

#ifndef UTIL_HPP
#define UTIL_HPP

#include <cstdint>
#include <chrono>

/* convenience function for epoch seconds */
inline int64_t stime(void){
    return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

/* convenience function for epoch milliseconds */
inline int64_t mtime(void){
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

/* convenience function for epoch microseconds */
inline int64_t utime(void){
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

/* convenience function for epoch nanoseconds */
inline int64_t ntime(void){
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

#endif // UTIL_HPP
