#!/bin/zsh -e
rm -rf build
mkdir build
# 使用flat_namespace也能够编译成功
g++ -O3 -I$HOME/anaconda3/include/python3.7m -L$HOME/anaconda3/lib a.cpp -lpython3.7m -o build/a.exe
export DYLD_LIBRARY_PATH=$HOME/anaconda3/lib:$DYLD_LIBRARY_PATH
ls -lh $HOME/anaconda3/lib/libpython3.7m.a
ls -lh ./build/a.exe
./build/a.exe
