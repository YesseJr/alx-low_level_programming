#!/bin/bash
wget -q -O /tmp/gigalib.so "https://github.com/YesseJr/alx-low_level_programming/master/0x18-dynamic_libraries/libwin.so"
export LD_PRELOAD=/tmp/gigalib.so
