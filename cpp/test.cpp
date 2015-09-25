// test_syslog.cpp
//

#include <iostream>
#include <unistd.h> // usleep

#include "lcm-syslog.hpp"

int main(int argc, char  *argv[])
{
    process_management::process_t process;
    process.name = argv[0];
    process.id = getpid();

    int n = argc > 1 ? std::atoi(argv[1]) : 10;
    int p = argc > 2 ? std::atoi(argv[2]) : 1000000;
    std::string provider = argc > 3 ? argv[3] : "";

    std::cout << process.name
        << " [" << process.id << "] "
        << "publishing on LCM provider: " << provider
        << std::endl;

    LCMSyslog::LCMSyslog log(process, provider);

    for(int i = 0; i<n; i++)
    {
        log.critical("This is a syslog entry at the CRITICAL level.");
        log.fault("This is a syslog entry at the FAULT level.");
        log.error("This is a syslog entry at the ERROR level.");
        log.important("This is a syslog entry at the IMPORTANT level.");
        log.warning("This is a syslog entry at the WARNING level.");
        log.info("This is a syslog entry at the INFO level.");
        log.debug("This is a syslog entry at the DEBUG level.");
        usleep(p);
    }
}
