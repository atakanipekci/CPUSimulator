all: begin

begin: _mainTester.o CPU.o CPUProgram.o CPUProgramDyn.o Memory.o Computer.o
	g++ _mainTester.o CPU.o CPUProgram.o CPUProgramDyn.o Memory.o Computer.o -o exe

_mainTester.o: _mainTester.cpp
	g++ -std=c++11 -c _mainTester.cpp

CPU.o: CPU.cpp
	g++ -std=c++11 -c CPU.cpp

CPUProgramDyn.o: CPUProgramDyn.cpp
	g++ -std=c++11 -c CPUProgramDyn.cpp

CPUProgram.o: CPUProgram.cpp
	g++ -std=c++11 -c CPUProgram.cpp

Memory.o: Memory.cpp
	g++ -std=c++11 -c Memory.cpp

Computer.o: Computer.cpp
	g++ -std=c++11 -c Computer.cpp
clean:
	rm *.o exe
