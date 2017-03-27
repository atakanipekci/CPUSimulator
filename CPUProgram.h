//Created by Taha Atakan İpekçi on 4.11.2016
#ifndef CPUPROGRAM_H
#define	CPUPROGRAM_H

#include <iostream>
#include <string>
#include <fstream>


using namespace std; 



class CPUProgram {

public:

CPUProgram (const char filename[]);
CPUProgram (int opt);
CPUProgram (){/*body intentionally empty*/};

string line[200];

string getLine(int lineNo) const  {return line[lineNo];} 

void ReadFile(const char filename[]);
//Checks for errors before executing the program
int checkForSyntaxErrors();
int size() const {return totalSize;}
void setSize(int value){ totalSize = value;}
void setName(const char filename[]){name = filename;}
const char* getName() const{return name;}
private :
const char *name;
int totalSize;
int option;
//Checks if the command can actually take the parameters that were calculated
//by checkForSyntaxErrors before. For example JMP can not take 2 registers
//as parameter even if there are no syntax errors.
int checkParameters (const string sbstr1x1, const string sbstr1x2, 
					 const  string sbstr1x3,const int isANumber1,  
					 const int isANumber2,  const int isAnAddress1,
					 const int isAnAddress2, const int constantNumber1,
					 const int constantNumber2, const int j);
//Checks if a string is a number
int checkIfAStringIsANumber(const string str,const int size);
//Turns a string to an integer
int stringToInteger(const string str, const int size);




};







#endif	/* CPUPROGRAM_H */

