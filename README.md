# clone repository with submodules

git clone --recurse-submodules https://github.com/fgsoftware1/limine-barebones.git

# Limine Bare Bones

This repository will show you how to set up a simple 64-bit x86_64 Long Mode higher half kernel using Limine, a bootloader designed to make getting your kernel up and running as quickly and pain-freely as possible while supporting many useful features, such as:

* Support for ISO, echfs, ext2/3/4 and FAT12/16/32.
* Support for the Linux, stivale, stivale2 and multiboot1 boot protocols.
* Portable runtime terminal facility for stivale2 kernels.
* Modern features such as 5-level paging and x2APIC.
* Multicore startup.
* Address-space layout randomization.
* ...and much more!

This project can be built using the host compiler on most Linux distros on x86_64, but it's recommended you set up an x86_64 [cross compiler](https://wiki.osdev.org/GCC_Cross-Compiler).

It is also recommended to cross reference the contents of this repository with [the Stivale Bare Bones](https://wiki.osdev.org/Stivale_Bare_Bones) OSDev wiki page.

This project covers both the stivale and stivale2 protocols.

## Choosing a boot protocol: stivale or stivale2

Using stivale2 is recommended for most projects, as it is more complete and customizable: stivale2 allows you to pass information to the bootloader using tags and request features like the runtime terminal and multicore startup.

The original stivale is designed to be simpler and easier to target for bootloader developers: you can make your own bootloader while still maintaining compatibility with pre-existing ones.

## Where to go from here

You may be asking yourself: "what now?".  So here's a list of things you may want to do to get started working
on your new kernel:

* Load an [IDT](https://wiki.osdev.org/Interrupt_Descriptor_Table) so that exceptions and interrupts can be handled.
* Write a physical memory allocator, a good starting point is a bitmap allocator.
* Write a virtual memory manager that can map, remap and unmap pages.
* Begin parsing ACPI tables, the most important one is the MADT since it contains information about the APIC.
* Start up the other CPUs. stivale2 provides a facility to make this less painful.
* Set up an interrupt controller such as the APIC.
* Configure a timer such as the Local APIC timer, the PIT, or the HPET.
* Implement a scheduler to schedule threads in order make multitasking possible.
* Design a virtual file system (VFS) and implement it. The traditional UNIX VFS works and saves headaches when porting software, but you can make your own thing too.
* Implement a simple virtual file system like a memory-only tmpfs to avoid crippling the design of your VFS too much while implementing it alongside real storage filesystems.
* Decide how to abstract devices. UNIX likes usually go for a `/dev` virtual filesystem containing device nodes and use `ioctl()` alongside standard FS calls to do operations on them.
* Get a userland going by loading executables from your VFS and running them in ring 3. Set up a way to perform system calls.
* Write a PCI driver.
* Add support for a storage medium, the easiest and most common ones are AHCI and NVMe.


At this point you should have decided what kind of interface your OS is going to provide to programs running on it, a common design that a lot of hobby operating systems use is POSIX (which derives from the UNIX design), which has both pros and cons:

Pros:

* Easier to port existing software that already runs on UNIX like operating systems like Linux.
* The basic parts of POSIX are fairly easy to implement.
* Pretty safe and sound design which has stood the test of time for over 40 years.

Cons:

* Restricts you to use an already existing design.
* POSIX may get complex and has a lot of legacy cruft that software might rely on.

Another point to consider is that a lot of software tends to depend on Linux or glibc specific features, but a portable C library like [mlibc](https://github.com/managarm/mlibc) can be used instead of implementing your own, as it provides good compatibility with POSIX/Linux software.

Other options, instead of implementing POSIX in your kernel, is to add a POSIX compatibility layer on top of your native design (with the large downside of complicating the design of your OS).
