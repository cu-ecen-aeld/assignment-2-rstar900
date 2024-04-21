# Macros

CC =  gcc

# Had to edit solution of conditional compilation: https://stackoverflow.com/questions/12955379/conditional-compilation-in-makefile
# Run make CROSS_COMPILE=1 to do cross compilation
ifeq ($(CROSS_COMPILE),1)
CC = aarch64-none-linux-gnu-gcc
endif

CCFLAGS = -O

# writer (main executable)
writer : writer.o
	${CC} ${CCFLAGS} -o writer writer.o

# writer.o
writer.o : writer.c
	${CC} ${CCFLAGS} -c writer.c

# phony target to remove all objects and executables
.PHONY : clean
clean:
	rm -f *.o *.exe writer