// listener.cpp
//

#include <iomanip>
#include <iostream>

#include <lcm/lcm-cpp.hpp>

#include "util.hpp"

#include "process_management/syslog_t.hpp"


class Handler
{
    public:
        ~Handler() {}

        void printSyslogMessage(const lcm::ReceiveBuffer* rbuf,
                const std::string& channel,
                const process_management::syslog_t* msg)
        {
            std::cout << epoch_usec_to_iso8601(msg->epoch_usec)
                << std::left << std::setw(13)
                << " [" + channel.substr(channel.rfind('.') + 1) + "]"
                << msg->text << std::endl;
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
