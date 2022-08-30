#define PY_SSIZE_T_CLEAN
#include <Python.h>

int Add(int x, int y) { return x + y; }

int Sub(int x, int y) { return x - y; }

PyObject *WrappAdd(PyObject *self, PyObject *args) {
    int x, y;
    if (!PyArg_ParseTuple(args, "ii", &x, &y)) {
        return nullptr;
    }
    return Py_BuildValue("i", Add(x, y));
}

PyObject *WrappSub(PyObject *self, PyObject *args) {
    int x, y;
    if (!PyArg_ParseTuple(args, "ii", &x, &y)) {
        return nullptr;
    }
    return Py_BuildValue("i", Sub(x, y));
}

static PyMethodDef test_methods[] = {
        {"Add", WrappAdd, METH_VARARGS, "something"},
        {"Sub", WrappSub, METH_VARARGS, "something"},
        {nullptr, nullptr}};
static PyModuleDef hahaModule = {
        PyModuleDef_HEAD_INIT,
        "haha",
        "这里是文档",
        -1,
        test_methods,
};
PyMODINIT_FUNC
PyInit_haha(void)
{
    return PyModule_Create(&hahaModule);
}
