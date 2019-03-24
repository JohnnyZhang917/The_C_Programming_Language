`Compile` translate `source files` into `object files`

and then `linker` links the all the `obj files` into a excutable.
# Compile

## Pre-Process

### include files
It simply imports the whole file into where the `#include` statement is.
也就是说在不同的位置去include可能会有不同的结果

### macros
It simply replace the symbols defined


## Compile
Generates a binary `Obj` file

### Notes:
1. 对于编译来讲，只针对单独的文件，不会去检查是否有`main`（程序入口）存在
2. 编译单独的文件，只要所有的符号都是先声明后使用，一般没有别的问题；至于声明的这个符号在其它文件是否存在，是Linker做的事情