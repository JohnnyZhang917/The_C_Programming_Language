# Three types of Linkage:
1. External Linkage
2. Internal Linkage
3. No linkage

## External Linkage
Any thing outside `Functions` are by de fault External Linkage except it is made `Internal`

all objects with external linkage must have one and **only one definition**

## Internal Linkage

### Use Case:
you want to be able to declare functions and other objects within a single file in a way that allows them to reference each other but **not to be accessible from outside that file**

You do it through the use of internal linkage.

### How:
Names with internal linkage **only refer to the same object within a single source file.** 

You do this by `prefixing` their declarations with the keyword `static`, which **changes the linkage of external objects from external linkage to internal linkage**. 

It is also possible to declare internal objects to be static, but that has an entirely different meaning

## No linkage

Objects inside a function - local to a single function

## Internal Static
they are **initialized to zero** when the program starts, they **retain their value** between entry to and exit from the statement containing their declaration and there is **only one copy of each one**