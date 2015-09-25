// util.hpp

#ifndef UTIL_HPP
#define UTIL_HPP

#include <chrono>
#include <cstdint>
#include <ctime>

/* convenience function for epoch seconds */
inline int64_t epoch_sec_now(void){
    return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

/* convenience function for epoch milliseconds */
inline int64_t epoch_msec_now(void){
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

/* convenience function for epoch microseconds */
inline int64_t epoch_usec_now(void){
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

/* convenience function for epoch nanoseconds */
inline int64_t epoch_nsec_now(void){
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

inline std::chrono::system_clock::time_point epoch_usec_to_time_point(const int64_t us){
    return std::chrono::system_clock::time_point(std::chrono::microseconds(us));
}

inline std::time_t epoch_usec_to_time_t(const int64_t us){
    return std::chrono::system_clock::to_time_t(std::chrono::system_clock::time_point(std::chrono::microseconds(us)));
}

inline std::string epoch_usec_to_iso8601(const int64_t us){
    char iso8601[21];
    std::time_t t = epoch_usec_to_time_t(us);
    std::strftime(iso8601, 21, "%F %T.", std::gmtime(&t));
    return std::string(iso8601) + std::to_string(us % 1000000);
}

#endif // UTIL_HPP
