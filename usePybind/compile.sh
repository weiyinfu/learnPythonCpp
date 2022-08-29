clang++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes`  -I../../include $1 -o example`python3-config --extension-suffix`
