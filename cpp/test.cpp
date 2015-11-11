// test_syslog.cpp
//

#include <iostream>
#include <unistd.h> // usleep
#include <stdlib.h> // strtol

#include "lcm-syslog.hpp"

int main(int argc, char  *argv[])
{
    char *eptr; // to check for conversion errors in strtol
    management::process_t process;
    process.name = argv[0];
    process.id = getpid();

    long int n = argc > 1 ? strtol(argv[1], &eptr, 10) : 10;
    long int p = argc > 2 ? strtol(argv[2], &eptr, 10) : 1000000;
    std::string provider = argc > 3 ? argv[3] : "";

    std::cout << process.name
        << " [" << process.id << "] "
        << "publishing on LCM provider: " << provider
        << std::endl;

    LCMSyslog::LCMSyslog log(process, provider);

    for(long int i = 0; i<n; i++)
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
