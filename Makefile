CC = gcc
CFLAGS = -pedantic -Wall -Wextra -Werror
OUTPUT = ex$(ex).out

all: $(OUTPUT)

$(OUTPUT): clean 
	$(CC) $(CFLAGS) chapter_$(cap)/ex$(ex).c -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)

