// syslog.hpp
//

#ifndef SYSLOG_HPP
#define SYSLOG_HPP

#include <string>

#include <sys/types.h> // getpid

#include <lcm/lcm-cpp.hpp>

#include "util.hpp" // for eusec
#include "process_management/process_t.hpp"
#include "process_management/syslog_t.hpp"

class Syslog
{
    public:
        Syslog( const process_management::process_t &process );
        virtual ~Syslog();

        void critical(const std::string &text, const int64_t &timestamp=0);
        void fault(const std::string &text, const int64_t &timestamp=0);
        void error(const std::string &text, const int64_t &timestamp=0);
        void important(const std::string &text, const int64_t &timestamp=0);
        void warning(const std::string &text, const int64_t &timestamp=0);
        void info(const std::string &text, const int64_t &timestamp=0);
        void debug(const std::string &text, const int64_t &timestamp=0);

    private:
        lcm::LCM lcm;
        process_management::process_t process;
        process_management::syslog_t msg;
};
#endif // SYSLOG_HPP
