# what is it?
```c
void PmuEccEdcTst_lTrapVectors
(
  void
) __attribute__ ((section(".PMUECCEDCTST_TVT_RAMCODE")));
```
what is this?

# Attributes for variables

## align
`aligned (alignment)`
This attribute specifies a minimum alignment for the variable or structure field, measured in `bytes`. For example, the declaration:

          int x __attribute__ ((aligned (16))) = 0;
     
causes the compiler to allocate the global variable x on a 16-byte boundary. On a 68040, this could be used in conjunction with an asm expression to access the move16 instruction which requires 16-byte aligned operands.

You can also specify the alignment of `structure fields`. For example, to create a double-word aligned int pair, you could write:

          struct foo { int x[2] __attribute__ ((aligned (8))); };

As in the preceding examples, you can explicitly specify the alignment (in bytes) that you wish the compiler to use for a given variable or structure field. Alternatively, you can leave out the alignment factor and just ask the compiler to align a variable or field to the maximum useful alignment for the target machine you are compiling for. For example, you could write:

          short array[3] __attribute__ ((aligned));

### default alignment size     

Whenever you leave out the alignment factor in an aligned attribute specification, the compiler automatically sets the alignment for the declared variable or field to the `largest alignment` which is ever used for any data type on the target machine you are compiling for. Doing this can often `make copy operations more efficient`, because the compiler can use whatever instructions copy the biggest chunks of memory when performing copies to or from the variables or fields that you have aligned this way.

The aligned attribute can only `increase the alignment`; but you can decrease it by specifying packed as well


## packed
The packed attribute specifies that a variable or structure field should have **the smallest possible alignment**—one byte for a variable, and one bit for a field, unless you specify a larger value with the aligned attribute.
Here is a structure in which the field x is packed, so that it immediately follows a:

          struct foo
          {
            char a;
            int x[2] __attribute__ ((packed));
          };
     
## section ("section-name")
Normally, the compiler places the objects it generates in sections like data and bss. Sometimes, however, you need additional sections, or you need certain particular variables to appear in special sections, for example to map to special hardware. The section attribute specifies that a variable (or function) lives in a particular section. For example, this small program uses several specific section names:

```c
          struct duart a __attribute__ ((section ("DUART_A"))) = { 0 };
          struct duart b __attribute__ ((section ("DUART_B"))) = { 0 };
          char stack[10000] __attribute__ ((section ("STACK"))) = { 0 };
          int init_data __attribute__ ((section ("INITDATA"))) = 0;
          
          main()
          {
            /* Initialize stack pointer */
            init_sp (stack + sizeof (stack));
          
            /* Initialize initialized data */
            memcpy (&init_data, &data, &edata - &data);
          
            /* Turn on the serial ports */
            init_duart (&a);
            init_duart (&b);
          }
```

Use the section attribute with an initialized definition of a global variable, as shown in the example. GCC issues a warning and otherwise ignores the section attribute in uninitialized variable declarations.

# Attribute for Functions

## section ("section-name")
Normally, the compiler places the code it generates in the `text section`. Sometimes, however, you need additional sections, or you need certain particular functions to appear in special sections. The section attribute specifies that a function lives in a particular section. For example, the declaration:
          
          extern void foobar (void) __attribute__ ((section ("bar")));
     
puts the function foobar in the `bar section`.

Some file formats do not support arbitrary sections so the section attribute is not available on all platforms. If you need to map the entire contents of a module to a particular section, consider using the facilities of the linker instead. 