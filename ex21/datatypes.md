# Data Types and Flow Control

## DATA TYPES

Type | Description
--- | ---
`int` | Stores a regular integer, defaulting to 32 bits in size
`double` | Holds a large floating-point number.
`float` | Holds a smaller floating-point number.
`char` | Holds a single 1-byte character.
`void` | Indicates "no type" and is used to say that a function returns nothing, or a pointer has no types, as in a coid \*thing.
`enum` | Enumerated types, which work as and convert to integers, but give you symbolic names for sets. Some compilers will warn you when you don't cover all elements of an enum in switch-statements

### Type Modifiers

Modifier | Description
--- | ---
`unsigned` | Changes the type so that it doesn't have negative numbers, giving you a larger upper bound but nothing lower than 0.
`signed` | Gives you negative and positive numbers, but halves your uppper bound in exchange for the same lower bound negative.
`long` | Uses a larger storage for the type so that it can hold bigger numbers, usually doubling the current size.
`short` | Uses smaller storage for the type so that it stores less, but takes half the space.

### Type Qualifiers

Qualifier | Description
--- | ---
`const` | indicates that the variable won't change after being initialized
`volatile` | Indicates that all bets are off, and the compiler should leave this alone and try not to do any fancy optimizations to it. You usually only need this if you're doing really weird stuff to your variables.
`register` | Forces the compiler to keep this variable in a register, and the compiler can just ignore you. These days, compilers ar better at figuring out where to put variables, so only use this if you can actually measure an improvement in speed.

### Type Conversion

If two operands on either side of an expression are mismatched, the smaller will be promoted to the larger before performing the operation. If one side of the expression is on the following list, then the other side is converted to that type in this order:

1. `long double`
2. `double`
3. `float`
4. `int` (but only `char` and `short int`)
5. `long`

But when in doubt, just use parens to force the cast.  
E.g.  
```c
// long + char - int * double
(double)long - (double)char - (double)int * double
```

### Type Sizes

As defined in `stdint.h`

Type | Definition
--- | ---
`int8_t` | 8-bit signed integer
`uint8_t` | 8-bit unsigned integer
`int16_t` | 16-bit signed integer
`uint16_t` | 16-bit unsigned integer
`int32_t` | 32-bit signed integer
`uint32_t` | 32-bit unsigned integer
`int64_t` | 64-bit signed integer
`uint64_t` | 64-bit unsigned integer

Similarly, `INT(N)_MAX` will give the maximum positive number of the signed integer of bits (_N_) such as `INT16_MAX`

Type | Definition
--- | ---
`int_least(N)_t` | Holds at least (_N_) bits
`uint_least(N)_t` | Holds at least (_N_) bits unsigned
`INT_LEAST(N)_MAX` | Maximum value of the matching least (_N_) type
`INT_LEAST(N)_MIN` | Minimum value of the matching least (_N_) type
`UINT_LEAST(N)_MAX` | Unsigned maximum of the matching least (_N_) type
`int_fast(N)_t` | Similar to `int_least*N*_t` but asking for the "fastest" with at least that precision
`uint_fast(N)_t` | Unsigned fastest least integer
`INT_LEAST(N)_MAX` | Maximum value of the matching fastest (_N_) type
`INT_LEAST(N)_MIN` | Minimum value of the matching fastest (_N_) type
`UINT_LEAST(N)_MAX` | Unsigned maximum of the matching fastest (_N_) type
`intptr_t` | _Signed_ integer large enough to hold a pointer
`uintptr_t` | _Unsigned_ integer large enough to hold a pointer
`INTPTR_MAX` | Maximum value of a `intptr_t`
`INTPTR_MIN` | Minimum value of a `intptr_t`
`UINTPTR_MAX` | Unsigned maximum value of a `uintptr_t`
`intmax_t` | Biggest number possible on that system
`uintmax_t` | Biggest unsigned number possible
`INTMAX_MAX` | Largest value for the biggest signed number
`INTMAX_MIN` | Smallest value for the biggest signed number
`UINTMAX_MAX` | Largest value for the biggest unsigned number
`PTRDIFF_MIN` | Minimum value of `ptrdiff_t`
`PTRDIFF_MAX` | Maximum value of `ptrdiff_t`
`SIZE_MAX` | Maximum of a `size_t`

## AVAILABLE OPERATORS

Operator | Definition
--- | ---
(binary) | The operator has a left and right: `X + Y`
(unary) | The operator his on its own: `-X`
(prefix) | The operator comes before the variable: `++X`
(postfix) | This is usually the same as the (prefix) version, but placing it after gives it a different meaning: `X++`
(ternary) | There's only one of these, so it's actually called the ternary, but it means "three operands": `X ? Y : Z`

### Math Operators

Operator | Definition
--- | ---
`()` | Function call
`* (binary)` | Multiply
`/` | Divide
`+ (binary)` | Add
`+ (unary)` | Positive number
`++ (postfix)` | Read, then increment
`++ (prefix)` | Increment, then read
`-- (postfix)` | Read, then decrement
`-- (prefix)` | Decrement, then read
`- (binary)` | Subtract
`- (unary)` | Negative number

### Data Operators

Operator | Definition
--- | ---
`->` | Struct pointer access
`.` | Struct value access
`[]` | Array index
`sizeof` | Size of a type or variable
`& (unary)` | Address of
`* (unary)` | Value of

### Logic Operators

Operator | Definition
--- | ---
`!=` | Does not equal
`==` | Equal (not assignment)
`<` | Less than
`<=` | Less than or equal
`>` | Greater than
`>=` | Greater than or equal

### Bit Operators

&(binary) | Bitwise and
--- | ---
`<<` | Shift left
`>>` | Shift right
`^` | Bitwise xor (exclusive or)
`|` | Bitwise or
`~` | Complement (flips all the bits)

### Boolean Operators

Operator | Definition
--- | ---
`!` | Not
`&&` | And
`||` | Not
`?:` | Ternary truth test, read `X ? Y : Z` as "if X then Y else Z"

### Assignment Operators

Operator | Definition
--- | ---
`=` | Assign
`%=` | Modulus assign
`&=` | Bitwise and assign
`*=` | Multiply assign
`+=` | Plus assign
`-=` | Minus assign
`/=` | Divide assign
`<<=` | Shift left assign
`>>=` | Shift right assign
`^=` | Bitwise xor, assign
`|=` | Bitwise or, assign

### Control Structures

`do-while` do { ... } while(X); First does the code in the block, then tests the X expression before exiting.

`break` Puts a break in a loop, ending it early.

`continue` Stops the body of a loop and jumps to the test so it can continue.

`goto` Jumps to a spot in the code where you’ve placed a label:, and you’ve been using this in the dbg.h macros to go to the error: label.

