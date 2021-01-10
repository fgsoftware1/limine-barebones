# Limine Bare Bones

This repository will show you how to set up a simple 64-bit Long Mode higher half kernel using Limine, a bootloader designed to make getting your kernel up and running as quickly as possible while supporting many useful features, such as:

* support for echfs, ext2/3/4 and fat32
* support for the Linux and stivale and stivale2 boot protocols

This project can be build using the host compiler on most linux distros, but it's recommended you set up a [cross compiler](https://osdev.wiki/tools:compilers:gcc:x86:generic)

In order to build this you have to install [echfs](https://github.com/echfs/echfs), and [Limine](https://github.com/limine-bootloader/limine). Instructions on their respective repositories.

This project covers both the stivale 1 and stivale 2 protocols.

## Where to go from here

The first thing you should do after booting from limine is loading your own [GDT](https://osdev.wiki/x86:structures:gdt)

* Load an [IDT](https://osdev.wiki/x86:structures:idt) so that exceptions and interrupts can be handled
* Write a physical memory allocator, a good starting point is a bitmap allocator
* Write a virtual memory manager that can map, remap and unmap pages
* Begin parsing ACPI tables, the most important one is the MADT since it contains information about the APIC
* Set up an interrupt controller such as the APIC
* Configure a timer such as the lapic timer, the PIT or the HPET
* Write a pci driver
* Add support for a storage medium, the easiest and most common ones are AHCI and NVMe
* Boot other APs in the system
* Write a scheduler

At this point you should have decided what kind of interface your os is going to provide to programs running on it, a common design that a lot of hobby operating systems use is posix, which has both pros and cons

Pros:

* easier to port existing software that already runs on posix-based operating systems
* the basic parts of posix are fairly easy to implement

Cons:

* restricts you to use an already existing design
* posix is very complex and has a lot of legacy cruft that software might rely on

Other points to consider is that a lot of software tends to depend on linux-specific or glibc specific features.

Other options include adding a posix compatibility layer (with the large downside of complicating the design of your os), only implementing part of posix or just going with an entirely custom design.

In any case there are a few more features that should usually be implemented later in your os' development due to their complexity, these include support for USB(add link) and networking.
