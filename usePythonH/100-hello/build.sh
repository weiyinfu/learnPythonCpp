#!/bin/zsh -e
rm -rf build
mkdir build
gcc -undefined dynamic_lookup  -O3  \
  -I$HOME/anaconda3/include/python3.7m \
  -L$HOME/anaconda3/lib \
  a.cpp -o build/a.exe
./build/a.exe