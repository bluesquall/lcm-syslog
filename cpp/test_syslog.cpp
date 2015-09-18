// test_syslog.cpp
//

#include <unistd.h> // usleep

#include "syslog.hpp"

int main(int argc, char ** argv)
{
    process_management::process_t process;
    process.name = "test-syslog";
    process.id = getpid();
    Syslog::Syslog log(process);

    for(int i = 0; i<10; i++)
    {
        log.critical("This is a syslog entry at the CRITICAL level.");
        log.fault("This is a syslog entry at the FAULT level.");
        log.error("This is a syslog entry at the ERROR level.");
        log.important("This is a syslog entry at the IMPORTANT level.");
        log.warning("This is a syslog entry at the WARNING level.");
        log.info("This is a syslog entry at the INFO level.");
        log.debug("This is a syslog entry at the DEBUG level.");
        usleep(1000000);
    }
}
