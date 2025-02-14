# Bi?n ð?nh ngh?a tr?nh biên d?ch và các tùy ch?n
CC = gcc
CFLAGS = -Wall -Iinclude
SRC_DIR = src
BIN_DIR = bin
DATA_DIR = data

# Tên file th?c thi
TARGET = $(BIN_DIR)/user_management

# Danh sách các file m? ngu?n
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/user.c $(SRC_DIR)/file_io.c $(SRC_DIR)/utils.c $(SRC_DIR)/menu.c

# Danh sách các file object (t? ð?ng t?o t? SRCS)
OBJS = $(SRCS:.c=.o)

# M?c tiêu m?c ð?nh
all: $(TARGET)

# Biên d?ch file th?c thi
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Biên d?ch các file .c thành file .o
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# L?nh clean ð? xóa các file object và file th?c thi
clean:
	rm -f $(OBJS) $(TARGET)

# L?nh run ð? ch?y chýõng tr?nh
run: $(TARGET)
	./$(TARGET)

# L?nh ð? t?o thý m?c bin n?u chýa t?n t?i
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# L?nh ð? t?o thý m?c data n?u chýa t?n t?i
$(DATA_DIR):
	mkdir -p $(DATA_DIR)

# Ð?m b?o thý m?c bin và data t?n t?i trý?c khi biên d?ch
$(TARGET): | $(BIN_DIR) $(DATA_DIR)
