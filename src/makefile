CC=gcc
CFLAGS=-I.
DEPS = Skylab
OBJ = SkylabMain.o Skylab.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

SkylabRun: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

clean:
		rm -f $(OBJ) SkylabRun
