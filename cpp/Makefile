# This Makefile was tested with GNU Make
export PATH := /opt/nxp/gcc-4.3.2-glibc-2.7/bin:/mbari/LRAUV/Tools/linuxi64/cross-compile-tools/bin:$(PATH)
CXX=arm-vfp-linux-gnu-g++

# Use pkg-config to lookup the proper compiler and linker flags for LCM
export PKG_CONFIG_PATH := /mbari/LRAUV/rootfs/2.6.27.8-nxp-middleware/usr/lib/pkgconfig
CFLAGS=-std=gnu++0x -Ilcmtypes `pkg-config --cflags lcm`
LDFLAGS=`pkg-config --libs lcm`

all: lcmtypes/process_management/process_t.hpp \
	lcmtypes/process_management/syslog_t.hpp \
	listener \
	test

listener: listener.o 
	$(CXX) -o $@ $^ $(LDFLAGS)

test: lcm-syslog.o test.o
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp lcmtypes/process_management/process_t.hpp lcmtypes/process_management/syslog_t.hpp 
	$(CXX) $(CFLAGS) -I. -o $@ -c $< 

lcmtypes/process_management/%.hpp:
	lcm-gen --cpp --cpp-hpath lcmtypes ../process-management-lcmtypes/*.lcm

clean:
	rm -f listener test
	rm -f *.o exlcm/*.o
	rm -f lcmtypes/process_management/*.hpp

copy-to-daphne: all
	rsync -avPhv --include=listener --include=test --exclude=* ./* daphne:lcm-syslog
