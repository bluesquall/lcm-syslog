#!/bin/bash
JPATH=./lcmtypes
rm $JPATH/*/*.java
lcm-gen --java --jpath=$JPATH ../process-management-lcmtypes/*.lcm
javac $JPATH/*/*.java
CLASSPATH=$JPATH lcm-spy

