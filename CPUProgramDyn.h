//Created by Taha Atakan İpekçi on 14.11.2016
#ifndef CPUProgramDyn_H
#define	CPUProgramDyn_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std; 


namespace AtakanCPUProgram{
class CPUProgramDyn {

public:

CPUProgramDyn (const char filename[]);
CPUProgramDyn (int opt);
CPUProgramDyn ();
CPUProgramDyn (const CPUProgramDyn& Copy);
~CPUProgramDyn (){delete [] line;};

string getLine(int lineNo) const  {return line[lineNo];} 

void ReadFile(const char filename[]);
//Checks for errors before executing the program
int checkForSyntaxErrors();
int size() const {return totalSize;}
void setSize(int value){ totalSize = value;}
void setName(const char filename[]){name = filename;}
const char* getName()const {return name;}
//Operators :
//Returns a new CPUProgramDyn that has the same member variables with original one
//But it has one more line given as a parameter
CPUProgramDyn operator +(string instr) const;
//Adds one more line given as a parameter to the original object and returns it
const CPUProgramDyn operator +=(string instr);
//Adds the lines of another CPUProgramDyn given as a parameter to the original one.
CPUProgramDyn operator +(CPUProgramDyn& p2) const;
//All comparing operators below compares according to the totalSize member.
bool operator ==(const CPUProgramDyn& p2) const;
bool operator !=(const CPUProgramDyn& p2) const;
bool operator <(const CPUProgramDyn& p2) const;
bool operator >(const CPUProgramDyn& p2) const;
bool operator <=(const CPUProgramDyn& p2) const;
bool operator >=(const CPUProgramDyn& p2) const;
//Deletes the last line 
CPUProgramDyn operator --(); //Prefix
CPUProgramDyn operator --(int ignore);//Postfix 
//Returns the line according to the given index value
string& operator [](int index);
CPUProgramDyn operator ()(int i1, int i2);
friend ostream& operator <<(ostream& out, const CPUProgramDyn& p);
private :
string* line;
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
}






#endif	/* CPUProgramDyn_H */

