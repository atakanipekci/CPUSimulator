#include "CPU.h"
//appends all registers to 0 , PC to 1 and checkHLT to 0
CPU :: CPU(){
int i;
for(i=0; i<5;i++)
{
registers[i]=0;
}
PC=1;
checkHLT=0;
}
//does the same thing. But also appends the option
CPU :: CPU(int opt){
int i;
for(i=0; i<5;i++)
{
registers[i]=0;
}
PC=1;
checkHLT=0;
option = opt;
}
//Prints the register values
void CPU :: print(){
int i;

cout<<"PC = "<<PC<<endl;
cout<<"CPU Register Values : "<< endl;
for(i=0; i<5;i++)
{
cout<<'['<<i<<']' <<" -> "<<registers[i]<<' ';
}
cout<<endl;

}
//Used to end the program or not
bool CPU :: halted() const {

if(checkHLT == 0)
	return false;
else
	return true;

}

void CPU :: setOption(int opt){
if(opt == 1 || opt ==2 || opt == 0)
option = opt;
else
{
option = 0;
cout<< "Illegal value for option. Option is set to 0"<<endl;
}
}


int CPU :: checkIfAStringIsANumber(string str,int size){
int i;

	for (i=0; i<size; i++)
	{
		if((str[i] <'0') || (str[i] > '9'))	//Checks every character of string
		return -1;							//to see if it is a number
	}
return 1;									//Returns 1 if it is, -1 otherwise
}

int CPU :: stringToInteger(string str, int size){
int i,j=1,total=0;

	for(i=size; i>1; i--)
		j*=10;

	for(i=0; i<size; i++, j/=10)			//Turns a string to an integer 
	{										//number.Substracting character
		if((int)(str[i]-'0') != 0)			//0 from other numeric characters
		total += (int)(str[i]-'0')*j;		//gives the integer value.
		else 								//*10 is used to increase the value
		{									//of digits.
		total *=j;
		}
	}

return total;
}

//Executes the given instruction. To do that calls the correct functions 
//depending on the instruction and parameters
const int CPU :: execute( string str ,Memory& myMemory){
int a,k,k2,index,index1,index2,index3,index4,index5,index5x1,index6,index7,index8,
isANumber1,isANumber2,isANumber3,isANumber4,numberOfParameters=0,
constantNumber1,constantNumber2,isAnAddress1 =0,isAnAddress2=0,
addressNumber1,addressNumber2,addressValue;
//The string below just holds the name of the registers we have.
//Since we are turning all the letters to their smaller form we have r1 instead
//of R1 etc.
string regs[] = {"r1","r2","r3","r4","r5"};
string sbstr1,sbstr2,sbstr1x1,sbstr1x2,sbstr1x3,sbstraddress1,sbstraddress2;

								

		index1 = str.find_first_of(';');

		if(index1 != -1)
		{
		sbstr1 = str.substr(0,index1);
		sbstr2 = str.substr(index1);
		}

		else 
		sbstr1 = str;
		
		for (a=0; a < sbstr1.size(); a++)
		{

			if(sbstr1[a] >= 'A' && sbstr1[a] <= 'Z')
		
			sbstr1[a] += 'a'- 'A';
			
		}
		
		index2=sbstr1.find_first_not_of(' ');
		index3=sbstr1.find_first_of(' ',index2);
		if(index2 != -1 && index3 != -1)
		sbstr1x1  = sbstr1.substr(index2,index3-index2);
		if(index2 !=-1 && index3 == -1)
		sbstr1x1  = sbstr1.substr(index2,sbstr1.size()-index2);
		
		
			index4=sbstr1.find_first_not_of(' ', index3);
			index5=sbstr1.find_first_of(',',index4);
			if(index5 == -1)
			{
			numberOfParameters = 1;
			}
			else 
			numberOfParameters = 2;

			index5x1=sbstr1.find_first_of(' ',index4);
			
			if((index5x1 < index5 )&& index5x1 !=-1)
			index5=index5x1;			

			if(index4 != -1 && index5 != -1)
			{
			
			sbstr1x2 = sbstr1.substr(index4,index5-index4);
		
			}
			else if(index4 != -1 && index5 == -1)
			{
			index5=sbstr1.find_first_of(' ',index4);
				if(index5 != -1){
				sbstr1x2 = sbstr1.substr(index4,index5-index4);
				numberOfParameters = 1;
				
				}
				else
				sbstr1x2 = sbstr1.substr(index4,sbstr1.size()-index4);
			}	
			else if(index4==-1)
			sbstr1x2.clear();
			
			if(numberOfParameters !=1)
			{
			index6=sbstr1.find_first_of(',');
			index7=sbstr1.find_first_not_of(' ',index6+1);
			index8=sbstr1.find_first_of(' ',index7);	
			if(index6 !=-1)
			{
			if(index7 != -1 && index8 != -1)
			{
			sbstr1x3 = sbstr1.substr(index7,index8-index7);
			}
			else if(index7 != -1 && index8 == -1)
			{ 
			sbstr1x3 = sbstr1.substr(index7,sbstr1.size()-index7);
			}	
			else 
			sbstr1x3.clear();
			}
			else
			sbstr1x3.clear();
			}
			else
			sbstr1x3.clear();

			if(sbstr1x2[0] == '#')
			{			
				sbstraddress1 = sbstr1x2.substr(1,sbstr1x2.size()-1);
				isANumber3 = checkIfAStringIsANumber(sbstraddress1,
													 sbstraddress1.size());
				if(isANumber3 = 1)
				{					
					addressNumber1 = stringToInteger(sbstraddress1,
													 sbstraddress1.size());
					if(addressNumber1 >= 50)
						isAnAddress1 = -1;
					else
						isAnAddress1 = 1;
				}
			}
			if(sbstr1x3[0] == '#')
			{			
				sbstraddress2 = sbstr1x3.substr(1,sbstr1x3.size()-1);
				isANumber4 = checkIfAStringIsANumber(sbstraddress2,
													 sbstraddress2.size());
				if(isANumber4 = 1)
				{				
					addressNumber2 = stringToInteger(sbstraddress2,
													 sbstraddress2.size());
					if(addressNumber2 >= 50)
						isAnAddress2 = -1;
					else
						isAnAddress2 = 1;
				}
			}					
			
			isANumber1 = checkIfAStringIsANumber(sbstr1x2,sbstr1x2.size());
			
			isANumber2 = checkIfAStringIsANumber(sbstr1x3,sbstr1x3.size());
					
			if(sbstr1x1 == "hlt")
			{
			checkHLT = 1;
			
			
			cout<<"HLT "<<" - ";		
				print();
				myMemory.printAll();
			
			
			}	
			//Only JMP and PRN can have a first parameter as a number.
			if(isANumber1==1)
			{
			constantNumber1 = stringToInteger(sbstr1x2,sbstr1x2.size());
			
				if(sbstr1x1 == "jmp")
				{
					if(option > 0 && option <=2)
					{
						cout<<"JMP "<<constantNumber1<<" - ";
						
						if(option == 1)
						print();
						if(option == 2)
						{
						print();
						myMemory.printAll();
						}						
					}
							
					JMP1(constantNumber1);
						
				}
				else if(sbstr1x1 == "prn")
				{
					if(option > 0 && option <=2)
					{
						cout<<"PRN "<<constantNumber1<<" - ";
						if(option == 1)
						print();
						if(option == 2)
						{
						print();
						myMemory.printAll();
						}			
					}		
				PRN1(constantNumber1);
				}
			}			
			else
			{
				//since the order of the register name string array and 
				//the register value array are the same k holds the index for
				//both the name and value arrays.
				//ex: if sbstr1x2 = r2 then the k will be 1.
				//and arr[1] (arr[k]) holds the value of r2.	
				if(isANumber1 != 1 && sbstr1x2.empty()!=1 && isAnAddress1 != 1)
				{	
				for(k=0; k<5, sbstr1x2 != regs[k]; k++)
				{
					
				}
				}
				if(isANumber2==1)
				constantNumber2 = stringToInteger(sbstr1x3,sbstr1x3.size());
				
				if(sbstr1x1 == "mov" && isANumber2 ==1 && isAnAddress1 != 1 )
				{ 	
					MOV1(constantNumber2,k);					
					if(option > 0 && option <=2)
					{
						cout<<"MOV "<<sbstr1x2<<", "<<constantNumber2<<" - ";
						if(option == 1)
						print();
						if(option == 2)
						{
						print();
						myMemory.printAll();
						}			
					}		
										
				}

				if(sbstr1x1 == "add" && isANumber2 ==1 && isAnAddress1 != 1)
				{
					ADD1(constantNumber2,k);
					if(option > 0 && option <=2)
					{
						cout<<"ADD "<<sbstr1x2<<", "<<constantNumber2<<" - ";
						if(option == 1)
						print();
						if(option == 2)
						{
						print();
						myMemory.printAll();
						}			
					}		
					
				}

				if(sbstr1x1 == "sub" && isANumber2 ==1 && isAnAddress1 != 1)
				{
					SUB1(constantNumber2,k);
					if(option > 0 && option <=2)
					{
						cout<<"SUB "<<sbstr1x2<<", "<<constantNumber2<<" - ";
						if(option == 1)
						print();
						if(option == 2)
						{
						print();
						myMemory.printAll();
						}			
					}		
					
				}

				if(sbstr1x1 == "jmp")
				{
					if(option > 0 && option <=2)
					{
						cout<<"JMP "<<sbstr1x2<<", "<<constantNumber2<<" - ";
						if(option == 1)
						print();
						if(option == 2)
						{
						print();
						myMemory.printAll();
						}		
					}		
					JMP2(constantNumber2,k);
				}

				if(sbstr1x1 == "prn" && isAnAddress1 != 1 )
				{
					if(option > 0 && option <=2)
					{
						cout<<"PRN "<<sbstr1x2<<" - ";
						if(option == 1)
						print();
						if(option == 2)
						{
						print();
						myMemory.printAll();
						}	
					}		
					PRN2(k);
				}


				if(isANumber2 != 1 && sbstr1x3.empty()!=1  && isAnAddress2 != 1 )
				{
				for(k2=0; k2<5, sbstr1x3 != regs[k2]; k2++)
				{
					
				}
				}
				
				if(sbstr1x1 == "mov" && isANumber2 !=1&& isAnAddress2 != 1 
									 && isAnAddress1 != 1)
				{	
					MOV2(k,k2);	
					if(option > 0 && option <=2)
					{
						cout<<"MOV "<<sbstr1x2<<", "<<sbstr1x3<<" - ";
						if(option == 1)
						print();
						if(option == 2)
						{
						print();
						myMemory.printAll();
						}
					}		
					
				}
			
				if(sbstr1x1 == "add" && isANumber2 !=1 && isAnAddress2 != 1 )
				{
					ADD2(k,k2); 
					if(option > 0 && option <=2)
					{
						cout<<"ADD "<<sbstr1x2<<", "<<sbstr1x3<<" - ";
						if(option == 1)
						print();
						if(option == 2)
						{
						print();
						myMemory.printAll();
						}		
					}		
					
				}

				if(sbstr1x1 == "sub" && isANumber2 !=1 && isAnAddress2 != 1)
				{
					SUB2(k,k2);
					if(option > 0 && option <=2)
					{
						cout<<"SUB "<<sbstr1x2<<", "<<sbstr1x3<<" - ";
						if(option == 1)
						print();
						if(option == 2)
						{
						print();
						myMemory.printAll();
						}	
					}		
					
				}
			}

				if(sbstr1x1 == "mov" && isAnAddress1 ==1 && isANumber2 !=1)
				{
					MOV1(myMemory.getMem(addressNumber1),k2);
					if(option > 0 && option <=2)
					{
						cout<<"MOV "<<sbstr1x2<<", "<<sbstr1x3<<" - ";
						if(option == 1)
						print();
						if(option == 2)
						{
						print();
						myMemory.printAll();
						}	
					}		
					
				}
				
				if(sbstr1x1 == "mov" && isAnAddress1 ==1 && isANumber2 ==1)
				{
					myMemory.setMem(addressNumber1,constantNumber2);
					
					if(option > 0 && option <=2)
					{
						cout<<"MOV "<<sbstr1x2<<", "<<sbstr1x3<<" - ";
						if(option == 1)
						print();
						if(option == 2)
						{
						print();
						myMemory.printAll();
						}
					}		
					
				}
				
				if(sbstr1x1 == "mov" && isAnAddress1 !=1 && isAnAddress2 == 1)
				{
					myMemory.setMem(addressNumber2, getRegister(k));
					
					if(option > 0 && option <=2)
					{
						cout<<"MOV "<<sbstr1x2<<", "<<sbstr1x3<<" - ";
						if(option == 1)
						print();
						if(option == 2)
						{
						print();
						myMemory.printAll();
						}	
					}		
					
				}

				if(sbstr1x1 == "add" && isAnAddress2 == 1)
				{
					ADD1(myMemory.getMem(addressNumber2), k);
					if(option > 0 && option <=2)
					{
						cout<<"ADD "<<sbstr1x2<<", "<<sbstr1x3<<" - ";
						if(option == 1)
						print();
						if(option == 2)
						{
						print();
						myMemory.printAll();
						}
					}		
					
				}

				if(sbstr1x1 == "sub" && isAnAddress2 == 1)
				{
					SUB1(myMemory.getMem(addressNumber2), k);
					if(option > 0 && option <=2)
					{
						cout<<"SUB "<<sbstr1x2<<", "<<sbstr1x3<<" - ";
						if(option == 1)
						print();
						if(option == 2)
						{
						print();
						myMemory.printAll();
						}
					}		
					
				}
				if(sbstr1x1 == "prn" && isAnAddress1 == 1)
				{
					if(option > 0 && option <=2)
					{
						cout<<"PRN "<<sbstr1x2<<" - ";
						if(option == 1)
						print();
						if(option == 2)
						{
						print();
						myMemory.printAll();
						}
					}		
					PRN1(myMemory.getMem(addressNumber1));
				}
				if(sbstr1x1 == "jpn")
				{
					JPN(constantNumber2,k);
					if(option > 0 && option <=2)
					{
						cout<<"JPN "<<sbstr1x2<<", "<<sbstr1x3<<" - ";
						if(option == 1)
						print();
						if(option == 2)
						{
						print();
						myMemory.printAll();
						}	
					}		
					
				}
				
			

	

return 0;
}





