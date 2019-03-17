# Definition
When a `sequence point` occurs, it basically means that you are guaranteed 

that **all previous operations are complete**.

# How will it be violated
Changing a variable twice without an intervening sequence point is one example of `undefined behaviour`.

For example, `i = i++`; is undefined because there's `no sequence point between the two changes to  i`.

# Sequence Points in C:
The following are the sequence points described in 5.1.2.3:

- The call to a function, after the arguments have been evaluated (6.5.2.2).
- The `end of the first operand` of the following `operators`: logical AND && (6.5.13); logical OR || (6.5.14); conditional ? (6.5.15); comma , (6.5.17).
- The end of a full declarator: declarators (6.7.5);
- The end of a `full expression`: an initializer (6.7.8); the expression in an expression statement (6.8.3); the controlling expression of a selection statement (if or switch) (6.8.4); the controlling expression of a while or do statement (6.8.5); each of the expressions of a for statement (6.8.5.3); the expression in a return statement (6.8.6.4).
- Immediately before a library function returns (7.1.4).
- After the actions associated with each formatted input/output function conversion specifier (7.19.6, 7.24.2).
- Immediately before and immediately after each call to a comparison function, and also between any call to a comparison function and any movement of the objects passed as arguments to that call (7.20.5).

C11 has the wording changed. It appears to have broken out the ternary operator and added some more detail:

The following are the sequence points described in 5.1.2.3:

Between the evaluations of the function designator and actual arguments in a function call and the actual call. (6.5.2.2).
Between the evaluations of the first and second operands of the following operators: logical AND && (6.5.13); logical OR || (6.5.14); comma , (6.5.17).
Between the evaluations of the first operand of the conditional ?: operator and whichever of the second and third operands is evaluated (6.5.15).
The end of a full declarator: declarators (6.7.6);
Between the evaluation of a full expression and the next full expression to be evaluated. The following are full expressions: an initializer (6.7.9); the expression in an expression statement (6.8.3); the controlling expression of a selection statement (if or switch) (6.8.4); the controlling expression of a while or do statement (6.8.5); each of the expressions of a for statement (6.8.5.3); the expression in a return statement (6.8.6.4).
Immediately before a library function returns (7.1.4).
After the actions associated with each formatted input/output function conversion specifier (7.21.6, 7.28.2).
Immediately before and immediately after each call to a comparison function, and also between any call to a comparison function and any movement of the objects passed as arguments to that call (7.22.5).