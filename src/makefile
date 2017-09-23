CC=gcc
CFLAGS=-I. -Wall
LIBS =-lpthread
DEPS = Skylab
OBJ = SkylabMain.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

SkylabRun: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
		rm -f $(OBJ) SkylabRun
