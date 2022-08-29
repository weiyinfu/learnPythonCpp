# 不同语言封装的C封装
不同语言封装C有两种模式：
* 两遍模式：C语言和目标语言之间需要写两遍
* 一遍模式：只需要目标语言写一遍

两边模式的代表：Java、Python
一遍模式的代表：Dart、C#

Swig这种代码生成工具总是两遍模式，CppSharp这个工具则是一遍模式。   
两遍模式会有轻微的性能开销，但是可以封装起来也更灵活。  

Python的C封装不如Java 的JNI好写，原因是Python的垃圾回收机制是引用计数，而Java的垃圾回收更智能。  

Python对象引用计数的宏：Py_INCREF(obj)增加对象obj的引用计数，Py_DECREF(obj)减少对象obj的引用计数。Py_INCREF()和Py_DECREF()两个函数也有一个先检查对象是否为空的版本，分别为Py_XINCREF()和Py_XDECREF()。
编译扩展的程序员必须要注意，代码有可能会被运行在一个多线程的Python环境中。这些线程使用了两个C宏Py_BEGIN_ALLOW_THREADS和Py_END_ALLOW_THREADS，通过将代码和线程隔离，保证了运行和非运行时的安全性，由这些宏包裹的代码将会允许其他线程的运行。

# 编译命令
```plain
gcc -Wno-unused-result -Wsign-compare -Wunreachable-code -DNDEBUG -g -fwrapv -O3 -Wall -Wstrict-prototypes -I/Users/bytedance/anaconda3/include -arch x86_64 -I/Users/bytedance/anaconda3/include -arch x86_64 -I/Users/bytedance/anaconda3/include/python3.7m -c a.cpp -o build/temp.macosx-10.9-x86_64-cpython-37/a.o
g++ -bundle -undefined dynamic_lookup -L/Users/bytedance/anaconda3/lib -arch x86_64 -L/Users/bytedance/anaconda3/lib -arch x86_64 build/temp.macosx-10.9-x86_64-cpython-37/a.o -o build/lib.macosx-10.9-x86_64-cpython-37/baga.cpython-37m-darwin.so

```
```
# 此处引用的是python静态库
##需要注意g++参数的顺序：g++ -Ixxx xx.cpp -Lxxxx -lxxx
## 知识点：Linux中Python的so路径和Python.h头文件的路径

```
```
gcc -shared -Wall -fPIC -flat_namespace \
    -I/Users/bytedance/anaconda3/include/python3.7m \
    -L/Users/bytedance/anaconda3/lib -lpython3.7m \
    example.c example_wrap.c  -o _example.so

```
三种编译方式：
1. 使用cmake
2. 使用setup.py
```
python setup.py build_ext --inplace
or python setup.py build
```
4. 直接写g++


# 技术选型
boost封装python不如pybind11。  

# Python/C API的用途
* 扩展Python，将C++库封装成Python给Python用
* 赋能C++，Python是世界上最好的C++库

# 两种编译方式
* 使用setup.py，好处是可以自动确定使用哪个python进行编译
* 
# goto的用处
goto并不是百无一用，例如一个函数在多处有return，又想记录这个函数的返回值。这时候为了避免写两个函数，使用goto是最好的。

# 参考资料
## 官方文档
* https://docs.python.org/zh-cn/3.7/extending/extending.html
* https://docs.python.org/zh-cn/3/c-api/stable.html 包含了所有的API

* swig代码生成：https://github.com/weiyinfu/learnSwig
* learnCython:http://github.com/weiyinfu/learnCython
* learnCtypes:http://github.com/weiyinfu/learnCtypes