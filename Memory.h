//Created by Taha Atakan İpekçi on 4.11.2016
#ifndef MEMORY_H
#define	MEMORY_H

#include <iostream>



using namespace std; 

class Memory{

public:

Memory(int opt);
Memory(){/*body intentionally empty*/};
unsigned int getMem(int index)const {return mem[index];}
void setMem(int index, unsigned int value){mem[index]=value;}
//Prints all the memories and their vales.
void printAll();
private:
int option;
unsigned int mem[50];

};




#endif 
