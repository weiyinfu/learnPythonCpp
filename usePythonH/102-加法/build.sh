# 通过setup.py找到编译命令
gcc -Wno-unused-result -Wsign-compare -Wunreachable-code -DNDEBUG -g -fwrapv -O3 -Wall -Wstrict-prototypes -I$HOME/anaconda3/include -arch x86_64 -I$HOME/anaconda3/include -arch x86_64 -I$HOME/anaconda3/include/python3.7m -c a.cpp -o build/a.o
g++ -bundle -undefined dynamic_lookup -L$HOME/anaconda3/lib -arch x86_64 -L$HOME/anaconda3/lib -arch x86_64 build/a.o -o build/haha.cpython-37m-darwin.so

python a.py