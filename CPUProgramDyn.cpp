//Created by Taha Atakan İpekçi on 14.11.2016
#include "CPUProgramDyn.h"
namespace AtakanCPUProgram{
CPUProgramDyn :: CPUProgramDyn(const char filename[]){

ReadFile(filename);

}

CPUProgramDyn :: CPUProgramDyn(int opt){
line = NULL;
totalSize = 0;
option = opt;

}

CPUProgramDyn :: CPUProgramDyn (){
line = NULL;
totalSize = 0;
}

CPUProgramDyn :: CPUProgramDyn (const CPUProgramDyn& Copy){

totalSize=Copy.totalSize;
line = new string[Copy.totalSize];
option = Copy.option;
for(int i = 0; i<totalSize; i++){

	line[i] = Copy.line[i];

}

}

void CPUProgramDyn :: ReadFile(const char filename[]){
	totalSize = 0;
	name = filename;
	string instr;
	int i=0;

	
	ifstream inputFile(filename);
	
	if(inputFile.is_open())
    {
		while(getline(inputFile,instr))
		{

			totalSize++;
			
		}
	inputFile.close();
	}
	else
	cout<<"File not found"<<endl;

	line = new string[totalSize];
	inputFile.open(filename);
	
	if(inputFile.is_open())
    {
		while(getline(inputFile,instr))
		{
			line[i] = instr;
			i++;
			
		}
	inputFile.close();
	}
	else
	cout<<"File not found"<<endl;


}

string& CPUProgramDyn :: operator [](int index){

	if(index < totalSize)
		return line[index];
	else
		{
		cout<<"Illegal index for [] operator"<<endl;
		cout<<"Returning index 0 instead"<<endl;
		return line[0];
		}
}

CPUProgramDyn CPUProgramDyn :: operator +(string instr) const{

int i;
	CPUProgramDyn newProgram(*this);
	delete [] newProgram.line;

	newProgram.line = new string [size()+1];
	newProgram.setSize(size()+1);

	for (i = 0; i<size(); i++){

		newProgram.line[i] = line[i];
}
	newProgram.line[newProgram.size()-1];
	newProgram.line[i]= instr;

	return newProgram;
}

const CPUProgramDyn CPUProgramDyn :: operator +=(string instr){

	
	if(instr == "")
	{
	 cout<<"Instruction can not be an empty string"<<endl;
	 return *this; 
	}	

	CPUProgramDyn newProgram(*this);
	delete [] line;

	line= new string[size()+1];

	for(int i = 0; i<newProgram.size(); i++){

	line[i] = newProgram.line[i];

	}	
	
	setSize(size()+1);

	line[size()-1] = instr;
	return *this;	

}

CPUProgramDyn CPUProgramDyn :: operator +(CPUProgramDyn& p2) const{
	CPUProgramDyn newProgram(*this);
	delete [] newProgram.line;
	newProgram.line = new string[size()+p2.size()];
	int i,j;
	for(i = 0; i<totalSize; i++){

	newProgram.line[i] = line[i];

	}
	
	newProgram.setSize(size()+p2.size());

	for(j=0; i<newProgram.size(); i++, j++){
	

	newProgram.line[i] = p2.line[j];

}	

	return newProgram;
}

bool CPUProgramDyn :: operator ==(const CPUProgramDyn& p2) const{

	if(totalSize == p2.totalSize)
		return true;
	else 
		return false;

}

bool CPUProgramDyn :: operator !=(const CPUProgramDyn& p2) const{

	if(totalSize == p2.totalSize)
		return false;
	else 
		return true;

}

bool CPUProgramDyn :: operator <(const CPUProgramDyn& p2) const{

	if(totalSize < p2.totalSize)
		return true;
	else 
		return false;

}

bool CPUProgramDyn :: operator >(const CPUProgramDyn& p2) const{

	if(totalSize > p2.totalSize)
		return true;
	else 
		return false;

}

bool CPUProgramDyn :: operator <=(const CPUProgramDyn& p2) const{

	if(totalSize <= p2.totalSize)
		return true;
	else 
		return false;

}

bool CPUProgramDyn :: operator >=(const CPUProgramDyn& p2) const{

	if(totalSize >= p2.totalSize)
		return true;
	else 
		return false;

}

ostream& operator <<(ostream& out, const CPUProgramDyn& p){

	for(int i=0; i<p.totalSize; i++)
		out<<p.line[i]<<endl;

	return out;

}


CPUProgramDyn CPUProgramDyn :: operator --(){

	CPUProgramDyn newProgram(*this);
	delete [] line;

	line = new string [size()-1];
	totalSize -=1;
	for(int i = 0; i<totalSize; i++){

	line[i] = newProgram.line[i];

	}

	return *this;
}

CPUProgramDyn CPUProgramDyn :: operator --(int ignore){
	CPUProgramDyn newProgram(*this);
	delete [] line;

	line = new string [size()-1];
	totalSize -=1;
	for(int i = 0; i<totalSize; i++){

	line[i] = newProgram.line[i];

	}

	return newProgram;

}

CPUProgramDyn CPUProgramDyn :: operator ()(int i1, int i2){

	CPUProgramDyn newProgram;
	int i,j;
	if(i1 < 0 || i2 < 0 || i1 >= i2 || i2>=totalSize)
	{
	cout << "Illegal index value for () operator"<<endl;
	return newProgram;
	}
	
	
	newProgram.line = new string[i2-i1+1];

	newProgram.setSize(i2-i1+1);

	for (i = i1,j=0; i<=i2; i++,j++)
	{
		newProgram.line[j] = line[i];

	}

	return newProgram;
}

int CPUProgramDyn :: checkIfAStringIsANumber(const string str,const int size){

int i;

	for (i=0; i<size; i++)
	{
		if((str[i] <'0') || (str[i] > '9'))	//Checks every character of string
		return -1;							//to see if it is a number
	}
return 1;									//Returns 1 if it is, -1 otherwise
}

int CPUProgramDyn :: stringToInteger(const string str, const int size){

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

int CPUProgramDyn :: checkParameters (string sbstr1x1, string sbstr1x2, string sbstr1x3,
					 int isANumber1, int isANumber2, int isAnAddress1,
					 int isAnAddress2,int constantNumber1,int constantNumber2, 
					 int j){


int flag = 0;


			if(sbstr1x1 == "mov")
			{
				if(isANumber1 == 1)
				{
				flag = -1;
				cout<<"Invalid first parameter for MOV command at line: "
					<<j+1<<endl;				
				}
				
				else if(sbstr1x2 != "r1" && sbstr1x2 != "r2" && sbstr1x2 != "r3" 
					 && sbstr1x2 != "r4" && sbstr1x2 != "r5" && isAnAddress1!=1)
				{
				cout<<"Invalid first parameter for MOV command at line: "
					<<j+1<<endl;				
				flag=-1;
				}
				
				if(isANumber2 != 1)
				{
			    	if(sbstr1x3 != "r1" && sbstr1x3 != "r2" && sbstr1x3 != "r3" 
					&& sbstr1x3 != "r4" && sbstr1x3 != "r5" && isAnAddress2!=1)
					{
					flag=-1;
					cout<<"Invalid second parameter for MOV command at line: "
					<<j+1<<endl;
					}
				}
				if(isAnAddress1 == 1 && isAnAddress2 == 1)
				{
					flag=-1;
					cout<<"Invalid parameters for MOVsd command at line "<<j+1
						<<endl;
				}
			
			}
			if(sbstr1x1 == "prn")
			{
				if(isANumber1 != 1)
				{
			    	if(sbstr1x2 != "r1" && sbstr1x2 != "r2" && sbstr1x2 != "r3" 
					&& sbstr1x2 != "r4" && sbstr1x2 != "r5" && isAnAddress1!=1)
					{
					flag=-1;
					cout<<"Invalid parameter for PRN command at line: "
					<<j+1<<endl;
					}
				}	

				if(sbstr1x3 != "")
				{
				flag=-1;				
				cout<<"Too many arguments are entered for PRN at line: "
					<<j+1<<endl;
				} 
							
			
			}
			if(sbstr1x1 == "add")
			{
				if(isANumber1 == 1)
				{
				flag = -1;
				cout<<"Invalid first parameter for ADD command at line: "
					<<j+1<<endl;				
				}
				
				else if(sbstr1x2 != "r1" && sbstr1x2 != "r2" && sbstr1x2 != "r3" 
					 && sbstr1x2 != "r4" && sbstr1x2 != "r5")
				{
				cout<<"Invalid first parameter for ADD command at line: "
					<<j+1<<endl;				
				flag=-1;
				}
				
				if(isANumber2 != 1)
				{
			    	if(sbstr1x3 != "r1" && sbstr1x3 != "r2" && sbstr1x3 != "r3" 
					 && sbstr1x3 != "r4" && sbstr1x3 != "r5" && isAnAddress2!=1)
					{
					flag=-1;
					cout<<"Invalid second parameter for ADD command at line: "
					<<j+1<<endl;
					}
				}	


			}
			if(sbstr1x1 == "sub")
			{
				if(isANumber1 == 1)
				{
				flag = -1;
				cout<<"Invalid first parameter for SUB command at line: "
					<<j+1<<endl;				
				}
				
				else if(sbstr1x2 != "r1" && sbstr1x2 != "r2" && sbstr1x2 != "r3" 
					 && sbstr1x2 != "r4" && sbstr1x2 != "r5")
				{
				cout<<"Invalid first parameter for SUB command at line: "
					<<j+1<<endl;				
				flag=-1;
				}
				
				if(isANumber2 != 1)
				{
			    	if(sbstr1x3 != "r1" && sbstr1x3 != "r2" && sbstr1x3 != "r3" 
					 && sbstr1x3 != "r4" && sbstr1x3 != "r5" && isAnAddress2!=1)
					{
					flag=-1;
					cout<<"Invalid second parameter for SUB command at line: "
					<<j+1<<endl;
					}
				}	

			}
			if(sbstr1x1 == "jmp")
			{
				if(isANumber1 != 1)
				{
					
			    	if(sbstr1x2 != "r1" && sbstr1x2 != "r2" && sbstr1x2 != "r3" 
					&& sbstr1x2 != "r4" && sbstr1x2 != "r5")
					{
					flag=-1;
					cout<<"Invalid first parameter for JMP command at line: "
					<<j+1<<endl;
					}
					else if(isANumber2 != 1)
					{
					flag=-1;
					cout<<"Invalid second parameter for JMP command at line: "
					<<j+1<<endl;
					}
					else if(constantNumber2 >totalSize)
					{
					cout<<"Invalid line parameter for JMP at line: "<<j+1<<endl;
					flag=-1;					
					}


				}
				else 
				{
					if(constantNumber1 >=totalSize)
					{
					cout<<"Invalid line parameter for JMP at line: "<<j+1<<endl;
					flag=-1;					
					}

					if(sbstr1x3 != "")
					{				

					flag=-1;
					cout<<"Invalid first parameter for JMP command at line: "
						<<j+1<<endl;
					}				
				}	
					

		
			}

			if(sbstr1x1 == "jpn")
			{
				if(isANumber1 != 1)
				{
					
			    	if(sbstr1x2 != "r1" && sbstr1x2 != "r2" && sbstr1x2 != "r3" 
					&& sbstr1x2 != "r4" && sbstr1x2 != "r5")
					{
					flag=-1;
					cout<<"Invalid first parameter for JMP command at line: "
					<<j+1<<endl;
					}
					else if(isANumber2 != 1)
					{
					flag=-1;
					cout<<"Invalid second parameter for JMP command at line: "
					<<j+1<<endl;
					}
					else if(constantNumber2 > totalSize)
					{
					cout<<"Invalid line parameter for JMP at line: "<<j+1<<endl;
					flag=-1;					
					}


				}
				else 
				{			

					flag=-1;
					cout<<"Invalid first parameter for JPN command at line: "
						<<j+1<<endl;
								
				}	
					

		
			}

			

return flag;
}


int CPUProgramDyn :: checkForSyntaxErrors(){

//All the index variables are used to find the start and the end of
//substrings.
//Flag  = -1 means error
//isANumber variables are used to check if a substring is a number
//constantNumber variables hold that value
//checkHLT is used to check if the program has an end(HLT)

int j,a,index1,index2,index3,index4,index5,index5x1,index6,index7,index8,
flag=0,isANumber1,isANumber2,isANumber3,isANumber4,numberOfParameters=0,
constantNumber1,constantNumber2,addressNumber1,addressNumber2,isAnAddress1,
isAnAddress2,checkHLT=0;
//sbstr1=the line till the ; character
//sbstr2=comment after ;
//sbstr1x1 instruction, sbstr1x2 first parameter, sbstr1x3 second parameter
string sbstr1,sbstr2,sbstr1x1,sbstr1x2,sbstr1x3,sbstraddress1,sbstraddress2;
//All the error controls are done for every single line that has been read.

for(j=0; j<totalSize; j++)
	{

		index1 = line[j].find_first_of(';');

		if(index1 != -1)
		{
		sbstr1 = line[j].substr(0,index1);
		sbstr2 = line[j].substr(index1);
		}

		else 
		sbstr1 = line[j];
		//Turning every letter to the smaller version of it to make it easier to
		//compare later.
		for (a=0; a < sbstr1.size(); a++)
		{

			if(sbstr1[a] >= 'A' && sbstr1[a] <= 'Z')
		
			sbstr1[a] += 'a'- 'A';
			
		}
		//The instructions that are done below can be called 
		//"The Sandwich method". Basicly since we know what the substrings
		//should end or start with, we can check for those with find or find not
		//functions. Then we can create the substrings since we know the size 
		//and the start of it.
		index2=sbstr1.find_first_not_of(' ');
		index3=sbstr1.find_first_of(' ',index2);
		if(index2 != -1 && index3 != -1)
		sbstr1x1  = sbstr1.substr(index2,index3-index2);
		if(index2 !=-1 && index3 == -1)
		sbstr1x1  = sbstr1.substr(index2,sbstr1.size()-index2);
		//All commands have a size of 3. No point in checking for other stuff 
		//If there is a wrong command
		//All the if and else statements below explain themselfs with the 
		//cout functions they have inside.
		if(sbstr1x1.size() != 3)
		{
			cout << "Syntax error (invalid command) at line: " <<j+1<< endl;
			
			flag = -1;
		}
		else
		{
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
			isANumber1 = checkIfAStringIsANumber(sbstr1x2,sbstr1x2.size());

			
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
			
			if(isANumber1==1)
			constantNumber1 = stringToInteger(sbstr1x2,sbstr1x2.size());
			else
			{

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
					{
						cerr<<"Error invalid address number at line: "<<j+1;
						cerr<<endl;
						flag = -1;
						isAnAddress1 = -1;
					}
					else
					isAnAddress1 = 1;

				}
			}
			
			else if(sbstr1x2 != "r1" && sbstr1x2 != "r2" && sbstr1x2 != "r3" && 
			   		sbstr1x2 != "r4" && sbstr1x2 != "r5" && sbstr1x2 != "")
			{
				cout << "Syntax error (Invalid Parameter) at line: "<<j+1<<endl;
								
				flag=-1;
			}
			
			}
			
			
			isANumber2 = checkIfAStringIsANumber(sbstr1x3,sbstr1x3.size());
			
			if(isANumber2==1)
			constantNumber2 = stringToInteger(sbstr1x3,index8-index7);
			else
			{	
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
					{
						cerr<<"Error invalid address number at line: "<<j+1;
						cerr<<endl;
						flag = -1;
						isAnAddress2 = -1;
					}
					else
						isAnAddress2 = 1;

				}
			}
			
			else if(sbstr1x3 != "r1" && sbstr1x3 != "r2" && sbstr1x3 != "r3" && 
			   		sbstr1x3 != "r4" && sbstr1x3 != "r5" && sbstr1x3 != "")
			{
				cout << "Syntax error (Invalid Parameter) at line: "<<j+1<<endl;
								
				flag=-1;
			}
			}			
	
			
			
			if(sbstr1x1 != "mov" && sbstr1x1 != "prn" && sbstr1x1 != "add" && 
			   sbstr1x1 != "sub" && sbstr1x1 != "jmp" && sbstr1x1 != "hlt" &&
			   sbstr1x1 != "jpn")
			{
				cout << "Syntax error (Invalid Command) at line: "<<j+1<<endl;
								
				flag=-1;
				
			}
			
			if(sbstr1x3 != "" && index8+1<sbstr1.size() && index8 !=-1)
			{
				int k,checkOverInput=0;
				for(k=index8+1; k<sbstr1.size(); k++)
				{
					if(sbstr1[k] != ' ')
					{
						checkOverInput = 1;
						flag =-1;
					}
					
				}
				if(checkOverInput == 1)
					cout<<"Syntax error (non-space character after the last"
					    <<"parameter at line :"<<j+1<<endl;
			}
			else if(sbstr1x3 == "" && sbstr1x2 != "" && index5 !=-1)
			{
			int k,checkOverInput=0;	
				
				for(k=index5+1; k<sbstr1.size(); k++)
				{
					if(sbstr1[k] != ' ')
					{
						checkOverInput = 1;
						flag =-1;
					
					}
					
				}
				if(checkOverInput == 1)
					cout<<"Syntax error (non-space character after the last"
					    <<"parameter at line :"<<j+1<<endl;

			}			

			if(sbstr1x1 == "hlt")
			{
				checkHLT=1;
				if(sbstr1x2 != "")
				{
				flag=-1;
				cout<<"HLT command can not take any parameters, line: "
					<<j+1<<endl;
				}	

			}

			else
			{
				if(checkParameters(sbstr1x1, sbstr1x2, sbstr1x3, isANumber1,
								   isANumber2, isAnAddress1, isAnAddress2,
								   constantNumber1,constantNumber2,j)
				   == -1)
				flag = -1;
			}


		}
		
isAnAddress1 = 0; isAnAddress2 = 0;
		
	}

	if(checkHLT != 1)
	{
		flag = -1;
		cout <<"Error : No HLT command found."<<endl;
	}
	
	if(flag != -1)
	return 0;
	else
	return -1;
}
}




