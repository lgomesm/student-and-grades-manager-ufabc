CC = gcc
CFLAGS = -Iinclude

SRC = src/main.c src/students.c
OBJ = $(SRC:.c=.o)
OUT = build/StudentManager

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OUT)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o
	rm -rf build/StudentManager
