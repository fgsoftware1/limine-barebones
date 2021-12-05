#!/bin/bash
cd limine
make
cd ../
ninja
limine/limine-install ./disk.iso
