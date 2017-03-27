#include "Computer.h"

Computer :: Computer (CPU aCPU, CPUProgram aCPUProgram, Memory aMemory, int opt){

setCPU(aCPU);
setCPUProgram(aCPUProgram);
setMemory(aMemory);
setOption(opt);
}

Computer :: Computer (int opt){

option = opt;
}

//Executes the file that has been read by myCPUProgram by using myCPU and
//myMemory
void Computer :: execute(){
string instruction;
if(myCPUProgram.checkForSyntaxErrors() != -1){ //If there are no errors in file

myCPU.setOption(getOption());    
while(!myCPU.halted()){ //Until the program reaches HLT command
	instruction  = myCPUProgram.getLine(myCPU.getPC()-1);
	myCPU.execute(instruction,myMemory);
	myCPU.setPC(myCPU.getPC()+1);
}

}

}








