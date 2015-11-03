CC=gcc
OUTPUT  =../bin/lalt.exe
CFLAGS  =-std=c99
INCS    =
LDFLAGS =-lreadline -lcurses
WFLAGS  =-Wall -Werror
FILES   =lalt.c mpc.c repl.c lval.c

.PHONY: clean pedan static

all:
	$(CC) $(FILES) $(CFLAGS) $(INCS) $(LDFLAGS) -o $(OUTPUT)

static:
	$(CC) -static $(FILES) $(CFLAGS) $(INCS) $(LDFLAGS) -o ../bin/staticlalt.exe

clean:
	-rm -f *.o *.stackdump $(OUTPUT)

pedan:
	$(CC) $(FILES) $(CFLAGS) $(INCS) $(LDFLAGS) -o $(OUTPUT)
