TARGET = match4
CC = gcc
CFLAGS = -Wall -Wextra
INC = -I ./include
FILES = $(wildcard ./src/*.c)

.PHONEY: all clean fclean re

all: $(TARGET)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(TARGET)

re: fclean all

$(TARGET): $(FILES)
	@$(CC) $(INC) $(CFLAGS) $(FILES) -o $(TARGET)
