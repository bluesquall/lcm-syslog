#!/bin/bash
rm -rf ./process-management
lcm-gen --cpp ../process-management-lcmtypes/*.lcm
g++ -std=gnu++11 -I /usr/local/include -I . -L/usr/local/lib -llcm lcm-syslog.cpp test.cpp -o test
g++ -std=gnu++11 -I /usr/local/include -I . -L/usr/local/lib -llcm listener.cpp -o listener
# TODO: figure out why I need "-I ." here...
