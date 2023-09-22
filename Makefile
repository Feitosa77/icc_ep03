CC = gcc
CFLAGS = -Wall -O3 -mavx -march=native

LIKWID_C = -DLIKWID_PERFMON -I${LIKWID_INCLUDE}
LIKWID_O = -L${LIKWID_LIB} -llikwid

TARGET = interpola

#Error
all: main.c point.o interpolate.o utils.o
	$(CC) $(CFLAGS) $(LIKWID_C) -c main.c
	$(CC) -o $(TARGET) main.o point.o interpolate.o utils.o $(LIKWID_O)

point.o: point.c point.h
	$(CC) -c -Wall point.c

interpolate.o: interpolate.c interpolate.h
	$(CC) -c -Wall interpolate.c

utils.o: utils.c utils.h
	$(CC) -c -Wall utils.c

clean:
	rm -f *.o

purge: clean
	rm -f $(TARGET)

