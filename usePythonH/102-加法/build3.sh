#!/bin/zsh -e
rm -rf build
mkdir build
# 使用flat_namespace也能够编译成功
g++ -O3  -shared -Wall -fPIC -flat_namespace -I$HOME/anaconda3/include/python3.7m -L$HOME/anaconda3/lib -lpython3.7m\
  a.cpp -o build/haha.so
python a.py