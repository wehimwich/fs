# Field System VLBI User Evironment fsVUE
# initial rdg
#
all: ../bin/vueinfo ../bin/fsvue
#
LIBES = ../poclb/poclb.a ../clib/clib.a ../rtelb/rtelb.a ../newlb/newlb.a -lm
#
OBJECTS = \
vueinfo.o what_help.o vuecalq.o
#
../bin/fsvue: fsvue
	rm -f ../bin/fsvue
	ln -s ../fsvue/fsvue ../bin/fsvue
#
../bin/vueinfo: $(OBJECTS)
	$(CC)  -o ../bin/vueinfo $(OBJECTS) $(LIBES)
	strip ../bin/vueinfo
#
vueinfo:
	rm -f ../bin/vueinfo
	make
