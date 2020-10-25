The stivale protocol is the original protcol implemented by the limine bootloader, it will keep being supported but no changes will be made to it.

## the stivale header
This structure must be present in the `.stivalehdr` section in order for your kernel to be loaded by stivale.

```c
    struct stivale_header {
        uint64_t stack;
        // Flags
        // bit 0   0 = text mode,   1 = graphics mode
        uint16_t flags;
        uint16_t framebuffer_width;
        uint16_t framebuffer_height;
        uint16_t framebuffer_bpp;
   } __attribute__((packed));
```

 The stack member is the stack pointer that will be loaded, the flags define information on how the kernel wants to be loaded, specifically the info on whether text mode or graphics mode should be enabled and if 5 level paging should be enabled. 
