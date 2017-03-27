//Created by Taha Atakan İpekçi on 4.11.2016

#ifndef CPU_H
#define	CPU_H

#include <iostream>
#include <string>
#include "Memory.h"

using namespace std; 



class CPU {
public:
CPU();
CPU(int opt);

bool halted() const;

const int execute(string str, Memory& myMemory);

int getRegister(int index)const {return registers[index];}

int getPC()const {return PC;}

int getOption() const {return option;}

void setRegister(int index,int value){registers[index]=value;}

void setPC(int value){PC=value;}

void setOption(int opt);

void print();
private : 
int registers[5];
int PC;
int checkHLT;
int option;



int checkIfAStringIsANumber(string str,int size);

int stringToInteger(string str, int size);
//Function for JMP instruction that only has 1 parameter
void JMP1(int number) {setPC(number-1);  }
//Function for JMP instruction that has 2 parameters(register and line)
void JMP2(int number,int index){ if(getRegister(index) == 0) setPC(number-1); }
//Functions for other instructions. There are 2 like others because of the 
//possibility of different amount and kind of parameters

void JPN(int number,int index){if(getRegister(index)<=0)setPC(number-1);}

void PRN1(int number) const { cout<<number<<endl;}

void PRN2(int index)const { cout<<getRegister(index)<<endl;}

void MOV1(int number,int index){setRegister(index,number);}

void MOV2(int index,int index2){setRegister(index, getRegister(index2));}

void ADD1(int number,int index){setRegister(index, getRegister(index)+number);}

void ADD2(int index,int index2){setRegister(index, getRegister(index) + getRegister(index2));}

void SUB1(int number,int index){setRegister(index, getRegister(index)-number);}

void SUB2(int index,int index2){setRegister(index, getRegister(index) - getRegister(index2)); }


};

#endif
