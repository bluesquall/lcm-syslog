#!/bin/bash
LPATH=${1:-../process-management-lcmtypes}
JPATH=${2:-/tmp/lcmtypes}

find $JPATH -type f \( -name "*.java" -o -name "*.class" \) -delete
find $LPATH -type f -name "*.lcm" -exec lcm-gen --java --jpath $JPATH {} \;
find $JPATH -type f -name "*.java" -exec javac -cp $JPATH {} \;

CLASSPATH=$JPATH lcm-spy
