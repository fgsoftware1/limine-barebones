The stivale 2 protocol is a replacement for the stivale protocol that is able to be cleanly extended without breaking changes, it has support for extra features such as SMP compared to the older protocol.

## the stivale 2 header
This structure must be present in the `.stivale2hdr` section in order for your kernel to be loaded by stivale 2.

```c
struct stivale2_header {
    uint64_t entry_point;
    uint64_t stack;
    uint64_t flags;
    uint64_t tags;
} __attribute__((packed));
```

If `entry_point` is 0 then the ELF entry point will be jumped to, otherwise the address specified will be used, `stack` will be loaded into the stack pointer register, as of now `flags` is 1 if KASLR is to be enabled.

`tags` is a pointer to the first of a linked list of tags which determine the features requested by the kernel, the base structure of a tag is:

```c
struct stivale2_hdr_tag {
    uint64_t identifier;
    uint64_t next;
} __attribute__((packed));
```

Where `identifier` determines the type of the tag, while `next` determines the next tag, a value of `NULL` indicates the end of the list.
For further information on the supported tags consule the [Stivale2 Specification](https://github.com/limine-bootloader/limine/blob/master/STIVALE2.md)
