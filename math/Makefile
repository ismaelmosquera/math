#
# Makefile to build imath library.
#
# Macro to perform reordering and cleanup
#
define cleanup
	mv imath.dll lib
	rm *.o
endef
#
vpath %.h include
VPATH := src
CC := gcc
FLAGS := -I include
SLIB := imath.dll
OBJ := imr_math.o 
$(SLIB): $(OBJ)
	$(CC) $^ -shared -O2 -s -DNDEBUG -o $@ && $(cleanup)
imr_math.o: imr_math.c imr_math.h
	$(CC) $(FLAGS) -c $<


