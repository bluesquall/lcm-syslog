#!/bin/bash
lcm-gen --cpp ../process-management-lcmtypes/*.lcm
g++ -std=gnu++11 -I /usr/local/include -I . -L/usr/local/lib -llcm syslog.cpp test_syslog.cpp -o test
# TODO: figure out why I need "-I ." here...
