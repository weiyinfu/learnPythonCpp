from distutils.core import setup, Extension

"""
python setup.py build
"""
setup(
    name='PackageName',
    version='1.0',
    description='This is a demo package',
    ext_modules=[
        # 此处Extension的名称与代码里面的模块的名称必须一致
        Extension('haha', sources=['a.cpp']),
    ]
)
