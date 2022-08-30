#!/bin/bash -e
rm -rf build
mkdir build
cd build
cmake ..
make -j8
# 此处必须去掉lib前缀才可以运行成功
mv libhaha.so haha.so
cd ..

python a.py