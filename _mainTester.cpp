#include "requiredIncs.h" 
int main(int argc, char** argv){
////////////////////////////////////////////////////////////////////////// 
//command line parameters 
const char* filename = argv[1]; 
int option = atoi(argv[2]);
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
Memory myMemory(option);
CPU myCPU(option);
CPUProgram myCPUProgram(option);
myCPUProgram.ReadFile(filename); 
Computer myComputer1(myCPU, myCPUProgram, myMemory, option);
myComputer1.execute();
}
