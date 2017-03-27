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
