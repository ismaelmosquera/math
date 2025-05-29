#
# Makefile to build test imath
#
# Macro to perform cleanup
#
define cleanup
	mv prog bin
	rm *.o
endef
#
vpath %.h ../include
CC := gcc
FLAGS := -I ../include
CCF := -L../lib -limath
PROG := prog
OBJ := test_imath.o 
$(PROG): $(OBJ)
	$(CC) $(CCF) $^ -O2 -s -DNDEBUG -o $@ && $(cleanup)
test_imath.o: test_imath.c imr_math.h
	$(CC) $(FLAGS) -c $<

