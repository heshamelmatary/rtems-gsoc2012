rtems_tests_PROGRAMS = mp03-node2
mp03_node2_SOURCES = ../init.c ../delay.c ../task1.c ../system.h

dist_rtems_tests_DATA = mp03-node2.scn
dist_rtems_tests_DATA += mp03-node2.doc

include $(RTEMS_ROOT)/make/custom/@RTEMS_BSP@.cfg
include $(top_srcdir)/../automake/compile.am
include $(top_srcdir)/../automake/leaf.am

AM_CPPFLAGS += -DNODE_NUMBER=2 -I$(srcdir)/..

AM_CPPFLAGS += -I$(top_srcdir)/../support/include

LINK_OBJS = $(mp03_node2_OBJECTS)
LINK_LIBS = $(mp03_node2_LDLIBS)

mp03-node2$(EXEEXT): $(mp03_node2_OBJECTS) $(mp03_node2_DEPENDENCIES)
	@rm -f mp03-node2$(EXEEXT)
	$(make-exe)

include $(top_srcdir)/../automake/local.am
