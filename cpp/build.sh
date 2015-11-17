#!/bin/bash
rm -rf lcmtypes
lcm-gen --cpp --cpp-hpath lcmtypes ../process-management-lcmtypes/*.lcm
g++ -std=gnu++11 -I /usr/local/include -I lcmtypes -L/usr/local/lib -llcm lcm-syslog.cpp test.cpp -o test
g++ -std=gnu++11 -I /usr/local/include -I lcmtypes -L/usr/local/lib -llcm listener.cpp -o listener
