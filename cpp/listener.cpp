// listener.cpp
//

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

#include <lcm/lcm-cpp.hpp>

#include "process_management/syslog_t.hpp"


class Handler
{
    public:
        ~Handler() {}

        void printSyslogMessage(const lcm::ReceiveBuffer* rbuf,
                const std::string& channel,
                const process_management::syslog_t* msg)
        {
            std::chrono::microseconds epoch_usec(msg->timestamp);
            std::chrono::system_clock::time_point tp(epoch_usec);
            std::time_t tt = std::chrono::system_clock::to_time_t(tp);
            std::tm tm(*std::gmtime(&tt));
            // std::size_t p = channel.rfind('.');
            // std::string level = channel.substr(p);
            std::string level = channel.substr(7);
            std::cout<< std::put_time(&tm, "%F %T") <<" ["<< level << "] " << msg->text <<std::endl;
            //std::cout<< tm.tm_year+1900 <<'-'<< tm.tm_mon+1 <<'-'<< tm.tm_mday <<' '<< tm.tm_hour <<':'<< tm.tm_min <<':'<< tm.tm_sec <<'.'<< "xxx" <<" ["<< level << "] " << msg->text <<std::endl;
        }
};

// TODO: Accept command line args to filter levels, etc.
int main(int argc, char ** argv)
{
    lcm::LCM lcm;
    if(!lcm.good()) return 1;

    Handler h;
    lcm.subscribe("syslog.*", &Handler::printSyslogMessage, &h);

    while(0 == lcm.handle());

    return 0;
}
