- If either operand is a `long double`, then the other one is converted to long double and that is the type of the result.
- Otherwise, if either operand is a `double`, then the other one is converted to double, and that is the type of the result.
- Otherwise, if either operand is a `float`, then the other one is converted to float, and that is the type of the result.
- Otherwise the `integral promotions` are applied to both operands and the following conversions are applied:
  - If either operand is an `unsigned long int`, then the other one is converted to unsigned long int, and that is the type of the result.
  - Otherwise, if either operand is a `long int`, then the other one is converted to long int, and that is the type of the result.
  - Otherwise, if either operand is an `unsigned int`, then the other one is converted to unsigned int, and that is the type of the result.
  - Otherwise, both operands must be of type `int`, so that is the type of the result.