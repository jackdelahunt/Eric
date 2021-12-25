# Eric
Virtual machine vaguely inspired on the JVM. Accepts `.ere` files and generates bytecode to be interpreted and ran on the Eric VM. Bytecode is ran on the VM as a stack based program.

## Examples
Add two numbers
```asm
iconst 10
iconst 10
iadd
print

> 20
```

Function calls
```asm
iconst 100
call_to 1 1
halt

local 0
iconst 10
iadd
print
ret 0

> 110
```

## Instructions
- `iconst`: load integer on the stack
- `iadd`: add to last numbers on the stack as integers
- `print`: print last value on the stack
- `call`: move instruction pointer to location in the bytecode
- `call_to`: move instruction pointer relative to location of a call in the bytecode
- `ret`: return from function call
- `halt`: end program
- `local`: load function arguments on the stack
- `if_cmp_eq`: move to location if last two values are equal
- `rcpy`: copy register value to stack
- `scpy`: copy value on the stack to a register

