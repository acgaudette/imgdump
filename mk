#!/bin/sh

if ! test -d ./stb/ ; then git clone git@github.com:nothings/stb || exit 1 ; fi
echo cc ./imgdump.c ; cc ./imgdump.c -Os -lm -o ./imgdump
