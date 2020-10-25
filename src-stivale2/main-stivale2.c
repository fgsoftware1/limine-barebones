#include <stivale2.h>
#include <stdint.h>
#include <stddef.h>

#define VGA_ADDRESS 0xb8000
#define VGA_COLOR(character, color) ((uint16_t) (character) | (uint16_t) (color) << 8)
#define VGA_BLACK        0
#define VGA_BLUE         1
#define VGA_GREEN        2
#define VGA_CYAN         3
#define VGA_RED          4
#define VGA_PURPLE       5
#define VGA_BROWN        6
#define VGA_GRAY         7
#define VGA_DARK_GRAY    8
#define VGA_LIGHT_BLUE   9
#define VGA_LIGH_GREEN   10
#define VGA_LIGHT_CYAN   11
#define VGA_LIGHT_RED    12
#define VGA_LIGHT_PURPLE 13
#define VGA_YELLOW       14
#define VGA_WHITE        15

static uint8_t stack[4096] = {0};
void stivale2_main(struct stivale2_struct *info);

struct stivale2_header_tag_smp smp_request = {
    .tag = {
        .identifier = STIVALE2_HEADER_TAG_SMP_ID,
        .next       = 0
    },
    .flags = 0
};

__attribute__((section(".stivale2hdr"), used))
struct stivale2_header header2 = {
    .entry_point = (uint64_t)stivale2_main,
    .stack       = (uintptr_t)stack + sizeof(stack),
    .flags       = 0,
    .tags        = (uint64_t)&smp_request
};

void stivale2_main(struct stivale2_struct *info) {
    volatile uint16_t *vga_buffer = (uint16_t*)VGA_ADDRESS;
    vga_buffer[0] = VGA_COLOR('h', VGA_GREEN);
    vga_buffer[1] = VGA_COLOR('e', VGA_GREEN);
    vga_buffer[2] = VGA_COLOR('l', VGA_GREEN);
    vga_buffer[3] = VGA_COLOR('l', VGA_GREEN);
    vga_buffer[4] = VGA_COLOR('o', VGA_GREEN);
    asm volatile ("hlt");
}
