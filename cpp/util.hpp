// util.hpp

#ifndef UTIL_HPP
#define UTIL_HPP

#include <sys/time.h>
#include <cstdint>
#include <stdlib.h>

/* convenience function for epoch seconds */
inline int64_t epoch_sec_now(void){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return static_cast<int64_t>(tv.tv_sec);
}

/* convenience function for epoch milliseconds */
inline int64_t epoch_msec_now(void){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return static_cast<int64_t>(tv.tv_sec) * 1000 + static_cast<int64_t>(tv.tv_sec) / 1000;
}

/* convenience function for epoch microseconds */
inline int64_t epoch_usec_now(void){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return static_cast<int64_t>(tv.tv_sec) * 1000000 + static_cast<int64_t>(tv.tv_usec);
}

inline std::string epoch_usec_to_iso8601(const int64_t us){
    char iso8601[27];
    time_t esec(us/1000000);
    strftime(iso8601, sizeof(iso8601), "%Y-%m-%d %H:%M:%S.", gmtime(&esec));
    snprintf(&iso8601[20], 7, "%0ld", us % 1000000);
    return std::string(iso8601);
}

#endif // UTIL_HPP
