#!/bin/bash
cd limine
make
cd ../
ninja
limine/build/bin/limine-install ./disk.iso
