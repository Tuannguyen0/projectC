# Bi?n �?nh ngh?a tr?nh bi�n d?ch v� c�c t�y ch?n
CC = gcc
CFLAGS = -Wall -Iinclude
SRC_DIR = src
BIN_DIR = bin
DATA_DIR = data

# T�n file th?c thi
TARGET = $(BIN_DIR)/user_management

# Danh s�ch c�c file m? ngu?n
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/user.c $(SRC_DIR)/file_io.c $(SRC_DIR)/utils.c $(SRC_DIR)/menu.c

# Danh s�ch c�c file object (t? �?ng t?o t? SRCS)
OBJS = $(SRCS:.c=.o)

# M?c ti�u m?c �?nh
all: $(TARGET)

# Bi�n d?ch file th?c thi
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Bi�n d?ch c�c file .c th�nh file .o
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# L?nh clean �? x�a c�c file object v� file th?c thi
clean:
	rm -f $(OBJS) $(TARGET)

# L?nh run �? ch?y ch��ng tr?nh
run: $(TARGET)
	./$(TARGET)

# L?nh �? t?o th� m?c bin n?u ch�a t?n t?i
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# L?nh �? t?o th� m?c data n?u ch�a t?n t?i
$(DATA_DIR):
	mkdir -p $(DATA_DIR)

# �?m b?o th� m?c bin v� data t?n t?i tr�?c khi bi�n d?ch
$(TARGET): | $(BIN_DIR) $(DATA_DIR)
