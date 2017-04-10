# CPUSimulator
Simulates a simple CPU
2 testfiles and a main.cpp is included.
testfile.txt : Prints numbers from 10 down to 0 to the screen
testfile2.txt: Sorts given 10 numbers.
Usage: 
make
./exe testfile.txt option
------------------------------------
option : 0 -> Only executes without printing registers and memory.
option : 1 -> Prints the value of every register after each instruction
option : 2 -> Prints the value of every register and memory after each instr.
Note that HLT command prints the registers and memory no matter the option.
------------------------------------
INSTRUCTION SET
Move instructions
MOV reg, reg
MOV reg, constant
MOV reg, address
MOV address, reg
MOV address, constant
For example MOV R1, #45 copies the value of register 1 to memory location 45
For example MOV R1, R2 copies the value of register 1 to register 2
and MOV R1, 100 puts the value of 100 to register 1
Addition and Subtraction insructions
ADD reg, reg
ADD reg, constant
SUB reg, reg
SUB reg, constant
ADD reg, address
SUB reg, address
For example, ADD R1, #45 adds the value of memory location 45 to register 1
For example, ADD R1, R2 adds the value of register 2 to register 1
and ADD R1, 100 adds the value of 100 to register 1
Jump instruction
JMP reg, lineAdress
JMP lineAddress
For example, JMP R1, 32 jumps to line 32 of the program if the value of R1 is zero. JMP 23 jumps to
line 23 directly.
Print instructions
PRN reg
PRN constant
PRN address
For example, PRN #56 will print the value of the memory loacation 56 to the screen, after each print
a new line should be inserted.
For example, PRN R3 will print the value of register 3 to the screen, after each print a new line
should be inserted.
Other instructions
HLT
halts the program and prints on the screen the contents of all registers as well as the the memory.
