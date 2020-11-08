TARGET := kernel.elf

CC              = cc
CFLAGS          = -O2
LD              = ld
QEMU            = qemu-system-x86_64
QEMUFLAGS       = -m 1G -enable-kvm -cpu host
LDINTERNALFLAGS := -Tlinker.ld -static -nostdlib -no-pie
INTERNALCFLAGS  := -I../stivale -I. -ffreestanding -fno-stack-protector   \
	-fno-pic -fomit-frame-pointer -mno-80387 -mno-mmx -mno-3dnow -mno-sse \
	-mno-sse2 -masm=intel -mcmodel=kernel
CFILES    := $(shell find ./ -type f -name '*.c')
OBJ       := $(CFILES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(LD) $(LDINTERNALFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INTERNALCFLAGS) -c $< -o $@

clean:
	rm -rf $(TARGET) *.o
