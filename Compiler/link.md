# Common Errors during Linking

## `main` 未定义 (entry point)
- 对于有些编译器来讲，可以自定义 entry point，不一定要叫 main

## 无法找到声明的符号 (indentifier not found) (unresolved externals)

### 声明 & Include Headers
对于声明来讲，一种方式是将接口放到头文件，需要使用的源文件可以包含这个头文件，因而被展开之后就有了声明；

另一种方式是直接声明这个接口，与上面达到一样的效果

### 如果有使用，必须有定义
声明只能解决在编译时间无报错，不能解决在Link时间找不到定义

### 未调用的函数里面调用了其它未定义的函数 行不行？

main.c:
```c
void other_file_func();     // declaration

void func_1()
{
  other_file_func();
}

int main()
{
  // func_1();
}
```

这里虽然 `func_1`调用了 `other_file_func`，但是没有人用 `func_1`

Link报错：
> undefined reference to `other_file_func'

why？

**因为linker需要保证外部调用`func_1`**，那么能不能告诉编译器，这个函数只有内部使用呢？？

> **使用static！**

将上面改为：

```c
void other_file_func();     // declaration

static void func_1()
{
  other_file_func();
}

int main()
{
  // func_1();
}
```
这种情况下，编译：gcc main.c -o main，依然报相同的错

但是在Visual Studio 里面不报错。。这个应该和编译器有关？

### 编译器优化
如果不开优化，那么就会报错，如果开了优化，编译器就不会去找没使用的函数：
    
    gcc -O2 main.c -o main

or just lowest optimization:

    gcc -O main.c -o main

## 重复定义
如果我们把定义写在头文件，而该头文件又被重复引用，就会导致重复定义

如何解决？

### 常规操作：将定义写到源文件

### 操作2：使用 staic
使用static将使每一个引用该头文件的源文件有一个`自己的版本`,且都是local的，所以link的时候不会冲突

### 操作3：使用 inline
使用inline将会把该函数体展开，因而不存在函数名这个符号，link不冲突