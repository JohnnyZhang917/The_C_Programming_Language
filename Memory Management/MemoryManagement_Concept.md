# Stack
These `locals` are on `Stack` and managed by compiler:
```c
    void f()
    {
      int  a;
      char c;
      char d[16];
    }
```

Stack variables are automatically freed when they go out of scope.

## Drawbacks:
1. the compiler need to know how big the variables are in advance
2. the stack size is limited

# Heap

We can allocate a big size of memory on the Heap at `run time`.

- free the memory or there will be `memory leakage`
- manipulate via pointers not directly
