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