# precision convertion

## Default

Whenever two different real types are involved in an expression, the lower precision type is first implicitly converted to the higher precision type and then the arithmetic is performed at that precision

`lower precision -> higher precision`

> A float value converted to a double or long double, or a double converted to a long double, undergoes no change in value

## Forcing higher->lower
The Standard says that in these cases `loss of precision` may occur; if the destination is unable to hold the necessary value—say by attempting to add the largest representable number to itself—then the behaviour is undefined

> e.g. Double->Float : If double value cannot be represented exactly as float, `loss of precision` occurs. If value is too large to be represented as float, the result is `undefined`.

## Float & Double
由于浮点数只能用2^(-n)的和表示，所以并不能完整的表示赋予的值，会损失精度

```c
int main (void)
{
    float a =1.234567;
    double b = 0;
    b = (double)a;
    printf("%.15f\n%.15f\n",a,b);
    return 0;
}
```

float is a 32 bit IEEE 754 single precision Floating Point Number1 bit for the sign, (8 bits for the exponent, and 23* for the value), i.e. float has 7 decimal digits of precision.

double is a 64 bit IEEE 754 double precision Floating Point Number (1 bit for the sign, 11 bits for the exponent, and 52* bits for the value), i.e. double has 15 decimal digits of precision.