#!/bin/bash
lcm-gen --java ../process-management-lcmtypes/*.lcm
#javac -cp /usr/local/share/java/lcm.jar process_management/*.java
javac process_management/*.java
jar cf process_management.jar process_management/*.class

