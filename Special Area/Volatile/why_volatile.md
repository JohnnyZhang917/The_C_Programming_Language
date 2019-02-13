```c
uint32 status = 0; 
  
while (status == 0) 
{ 
  /*Let us assume that status isn't being changed  
  in this while loop or may be in our whole program*/
  
  /*So long as status (which could be reflecting  
  status of some IO port) is ZERO, do something*/
} 
```
An optimizing Compiler would see that **status isn’t being changed by while loop**. 

So there’s **no need to access status variable again and again after each iteration of loop**. 

So the Compiler would convert this loop to a infinite loop i.e. while (1) so that the Machine code to read status isn’t needed. 

Please note that compiler isn’t aware of that status is a special variable which can be changed from outside the current program at any point of time

# Look into Assembly

when using `volatile`, we get:
```s
.L2:
	movl	-4(%rbp), %eax      ; movl %edx, %eax means Move the contents of the edx register into the eax register
	cmpl	$1, %eax
  je	.L2
```

So after seen `volatile`, the compiler get a new value everytime 

no-volatile:
```s
.L2:
	cmpl	$1, -4(%rbp)
	je	.L2
```