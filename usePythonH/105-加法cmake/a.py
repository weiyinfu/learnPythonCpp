from os.path import *

import sys
import os

folder = abspath(dirname(__file__))
dll_path = join(folder, 'build')
print(os.listdir(dll_path))
sys.path.insert(0, dll_path)
import haha

print(f"""
模块的内容{dir(haha)}
加法{haha.Add(1, 2)}
减法{haha.Sub(2, 3)}

模块的信息：
模块的文档：{haha.__doc__}
模块的文件：{haha.__file__}
模块的名称：{haha.__name__}

""")
