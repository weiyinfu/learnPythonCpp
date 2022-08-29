from distutils.core import setup
from distutils.extension import Extension

"""
打包成so有两种方式：
* 使用setup.py：python setup.py build 
* 使用build.sh命令行
"""
setup(name="PackageName",
      ext_modules=[
          Extension("test2", ["test2.cpp"],
                    libraries=["boost_python"])
      ])
