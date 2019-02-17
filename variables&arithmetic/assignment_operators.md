# '='
## Result of '='
they take two operands and produce a `result`, the result being usable as part of an expression. In this statement

    x = 4;
the value 4 is assigned to x. The `result` has `the type of x` and `the value that was assigned`. It can be used like this

    a = (x = 4);
    // a=4

It's because assignment has a result that an expression like

    a = b = c = d;
works. The value of d is assigned to c, the result of that is assigned to b and so on. 

### Why could that work?
It makes use of the fact that expressions involving only assignment operators are **evaluated from right to left**

## Carefully using the result of '='

```c
while( (input_c = getchar()) != EOF){
            printf("%c was read\n", input_c);
    }
```