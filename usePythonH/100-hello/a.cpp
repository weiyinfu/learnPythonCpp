#define PY_SSIZE_T_CLEAN
#include <Python.h>

/**
这意味着包含以下标准头文件：<stdio.h>，<string.h>，<errno.h>，<limits.h>，<assert.h> 和 <stdlib.h>（如果可用）。
*/
int main(){
    printf("hello world\n");
    printf("maxint=%d\n",INT32_MAX);
    assert(1+2==3);
    return 0;
}