// listener.cpp
//

#include <iomanip>
#include <iostream>

#include <lcm/lcm-cpp.hpp>

#include "util.hpp"

#include "process_management/syslog_t.hpp"

class LCMSyslogListener
{
    public:
        LCMSyslogListener(lcm::LCM* lcm_instance) :
            lcm(lcm_instance)
        {}

        ~LCMSyslogListener() {}

        void out(const lcm::ReceiveBuffer* rbuf,
                const std::string& channel,
                const process_management::syslog_t* msg)
        {
            std::cout << epoch_usec_to_iso8601(msg->epoch_usec)
                << std::left << std::setw(13)
                << " [" + channel.substr(channel.rfind('.') + 1) + "]"
                << msg->text << std::endl;
        }

        void err(const lcm::ReceiveBuffer* rbuf,
                const std::string& channel,
                const process_management::syslog_t* msg)
        {
            std::cerr << epoch_usec_to_iso8601(msg->epoch_usec)
                << std::left << std::setw(13)
                << " [" + channel.substr(channel.rfind('.') + 1) + "]"
                << msg->text << std::endl;
        }


        void echo(const lcm::ReceiveBuffer* rbuf,
                const std::string& channel,
                const process_management::syslog_t* msg)
        {
            lcm->publish("echo." + channel, msg);
        }

        lcm::LCM* lcm;
};

int main(int argc, char ** argv)
{
    std::string prefix = argc > 1 ? argv[1] : "syslog";
    std::string provider = argc > 2 ? argv[2] : "";

    lcm::LCM lcm(provider);

    // XXX Is it a bad idea to share an LCM instance between two objects?
    //     (This is admittedly a contrived example).
    LCMSyslogListener listener(&lcm);
    LCMSyslogListener echoer(&lcm);

    lcm.subscribe(prefix + ".IMPORTANT", &LCMSyslogListener::out, &listener);
    lcm.subscribe(prefix + ".INFO", &LCMSyslogListener::out, &listener);
    lcm.subscribe(prefix + ".CRITICAL", &LCMSyslogListener::err, &listener);
    lcm.subscribe(prefix + ".ERROR", &LCMSyslogListener::err, &listener);
    lcm.subscribe(prefix + ".WARNING", &LCMSyslogListener::err, &listener);
    lcm.subscribe(prefix + ".DEBUG", &LCMSyslogListener::echo, &echoer);

    while(0 == lcm.handle());
    return 0;
}
