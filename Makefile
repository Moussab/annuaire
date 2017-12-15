CC      = gcc
CFLAGS  = -g -Wall
EXE  = annuaire

SRCS = main.c utilities.c linkedList.c
OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}
HDRS = utilities.h linkedList.h

BINDIR = cmake-build-debug

all: $(EXE)
	mv $(EXE) $(BINDIR)
	make clean

$(EXE): $(OBJS) $(HDRS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

-include ${DEPS}

clean:
	rm -f ${OBJS} ${DEPS}