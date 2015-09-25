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
        LCMSyslogListener(const std::string provider= "") :
            lcm(lcm::LCM(provider))
        {
            if(!lcm.good()) std::cout << "LCM would not initialize.";
        }

        ~LCMSyslogListener() {}

        static void printSyslogMessage(const lcm::ReceiveBuffer* rbuf,
                const std::string& channel,
                const process_management::syslog_t* msg,
                LCMSyslogListener*)
        {
            std::cout << epoch_usec_to_iso8601(msg->epoch_usec)
                << std::left << std::setw(13)
                << " [" + channel.substr(channel.rfind('.') + 1) + "]"
                << msg->text << std::endl;
        }

        void listen(const std::string channel = "syslog.*")
        {
            lcm.subscribeFunction(channel, this->printSyslogMessage, this);
            while(0 == lcm.handle());
        }

    private:
        lcm::LCM lcm;
};

int main(int argc, char ** argv)
{
    std::string channel = argc > 1 ? argv[1] : "syslog.*";
    std::string provider = argc > 2 ? argv[2] : "";
    LCMSyslogListener listener(provider);
    listener.listen(channel);
    return 0;
}
