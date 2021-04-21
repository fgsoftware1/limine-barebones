TARGET := stivale2.elf

CC = cc

CFLAGS = -Wall -Wextra -O2 -pipe

LDINTERNALFLAGS := \
	-fno-pic -fpie \
	-static-pie    \
	-nostdlib      \
	-Tlinker.ld    \
	-z max-page-size=0x1000

INTERNALCFLAGS  :=       \
	-I.                  \
	-std=gnu11           \
	-ffreestanding       \
	-fno-stack-protector \
	-fno-pic -fpie       \
	-mgeneral-regs-only  \
	-mno-red-zone

CFILES := $(shell find ./ -type f -name '*.c')
OBJ    := $(CFILES:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDINTERNALFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INTERNALCFLAGS) -c $< -o $@

clean:
	rm -rf $(TARGET) $(OBJ)
