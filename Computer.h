//Created by Taha Atakan İpekçi on 4.11.2016
#ifndef COMPUTER_H
#define	COMPUTER_H

#include <iostream>
#include <string>
#include "CPU.h"
#include "CPUProgram.h"
#include "Memory.h"
using namespace std; 

class Computer {

public:
Computer (CPU aCPU, CPUProgram aCPUProgram, Memory aMemory, int opt);
Computer (int opt);

void execute();

void setCPU(CPU aCPU){myCPU = aCPU;}

void setCPUProgram(CPUProgram aCPUProgram){myCPUProgram = aCPUProgram;}

void setMemory(Memory aMemory){myMemory= aMemory;}

void setOption(int opt){option = opt;}

int getOption()const {return option;}

CPU getCPU()const{ return myCPU;}

CPUProgram getCPUProgram()const { return myCPUProgram;}

Memory getMemory()const {return myMemory;}

private:

int option;

CPU myCPU;

CPUProgram myCPUProgram;

Memory myMemory;
 
};

#endif
