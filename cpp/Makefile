# This Makefile was tested with GNU Make
PATH:=/mbari/LRAUV/Tools/linuxi64/cross-compile-tools/bin/:$(PATH)
export PKG_CONFIG_PATH=/mbari/LRAUV/Tools/linuxi64/cross-compile-tools/lib/pkgconfig:/usr/local/lib/pkgconfig:/usr/lib/pkgconfig
CXX=g++
CFLAGS += -std=gnu++0x

# Use pkg-config to lookup the proper compiler and linker flags for LCM
CFLAGS += -Ilcmtypes `pkg-config --cflags lcm`
LDFLAGS += `pkg-config --libs lcm`

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

copy-to-%: clean
	@echo will not copy to $(subst copy-to-,,$@)
	@echo try cross-compiling instead:
	@echo make -f Makefile.lpc3250 $@
