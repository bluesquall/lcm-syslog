// lcm-syslog.hpp
//

#ifndef LCM_SYSLOG_HPP
#define LCM_SYSLOG_HPP

#include <string>

#include <sys/types.h> // getpid

#include <lcm/lcm-cpp.hpp>

#include "util.hpp" // for epoch_usec
#include "process_management/process_t.hpp"
#include "process_management/syslog_t.hpp"

class LCMSyslog
{
    public:
/*
        typedef enum { NONE      = 0,
                       DEBUG     = 1,
                       INFO      = 2,
                       WARNING   = 3,
                       IMPORTANT = 4,
                       ERROR     = 5,
                       FAULT     = 6,
                       CRITICAL  = 7,
        } Level;
*/
        LCMSyslog( const process_management::process_t &process );
        virtual ~LCMSyslog();

//        void log(const std::string &text, const int64_t &epoch_usec=0, Level level=LCMSyslog::NONE);
        void critical(const std::string &text, const int64_t &epoch_usec=0);
        void fault(const std::string &text, const int64_t &epoch_usec=0);
        void error(const std::string &text, const int64_t &epoch_usec=0);
        void important(const std::string &text, const int64_t &epoch_usec=0);
        void warning(const std::string &text, const int64_t &epoch_usec=0);
        void info(const std::string &text, const int64_t &epoch_usec=0);
        void debug(const std::string &text, const int64_t &epoch_usec=0);

    private:
        lcm::LCM lcm;
        process_management::process_t process;
        process_management::syslog_t msg;
};
#endif // LCM_SYSLOG_HPP
