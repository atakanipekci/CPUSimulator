#include "Memory.h"


Memory :: Memory(int opt){
int i;
for(i=0; i<50; i++){

mem[i]=0;

}
option=opt;
}

void Memory :: printAll(){
int i;
cout<<"Memory Values:"<<endl;

for(i=0; i<50; i++)
{
if(i+1 < 50 && i%4 !=0 || i ==0)
cout<<'['<<i<<']'<<" -> "<<mem[i]<< " | ";
else
cout<<'['<<i<<']'<<" -> "<<mem[i]<<endl;
}

}
