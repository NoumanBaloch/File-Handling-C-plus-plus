#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

//Employee Class
class Employee
{
int id;
char name[20];
int salary;

public:

Employee()
{ }

~Employee()
{ }

void setID(int tid)
{
id=tid;
}
int getID()
{
return(id);
}
void setData()
{
cout<<name;
cout<<salary;
}
void display()
{
cout<<id;
cout<<"\t"<<name;
cout<<"\t"<<salary;
}
char* getName()
{
return name;
}
};

//Methods related to Employee
void appendEmployee();
void displayAllEmployee();
void modifyEmployee();
void deleteEmployee();
void searchEmployee();
int getSizeofFile();
int getID();

char fname[]={"one.dat"};
char fid[]={"fid.dat"};

//Main Method
int main()
{
int ch;

while(1)
{
printf("========================================================\n\n");

printf("\t\t Welcome Employee Management System\n\n");

printf("========================================================\n\n");

printf("1. Add New Employee\n\n");
printf("2. Modify Existing Employee Details\n\n");
printf("3. Delete Employee\n\n");
printf("4. Search Employee by Name\n\n");
printf("5. Display All Employee Details\n\n");

printf("0. Exit\n\n");

printf("========================================================\n\n");

printf("\nPlease enter your Choice:");
scanf("%d",&ch);

switch(ch)
{
case 1: appendEmployee();
break;

case 2: modifyEmployee();
break;

case 3: deleteEmployee();
break;

case 4: searchEmployee();
break;

case 5: displayAllEmployee();
break;

case 0: exit(0);
}

}

return 0;
}

//Return the Auto generated ID for Employee
int getID()
{
ifstream fin(fid);
int value=0;

if(fin==NULL)
{
fin.close();
ofstream fout(fid);
fout<<value;
fin.close();

ofstream fout(fid);
fout<<value+1;

fout.close();

return(value+1);
}

//Add New Employee record into the File
void appendEmployee()
{
Employee t1;

fstream fout(fname,ios::app|ios::out);

t1.setID(getID());
t1.setData();

fout.write((char *) & t1,sizeof(t1));
fout.close();
}

//Update existing Employee record details into the File – Base of ID
void modifyEmployee()
{
Employee t;
int size=getSizeofFile();

fstream fout(fname,ios::ate|ios::out|ios::in);
fout.seekg(0);

int id;
int counter=0;

cout<>id;

if(fout==NULL)
{
cout<<"\n Sorry no record found \n";
}
else
{
for(int i=0;i<size;i++)
{
fout.read((char *) & t,sizeof(t));

if(id==t.getID())
{
int size=fout.tellg();
size=size-sizeof(t);
fout.seekp(size,ios::beg);

Employee newobj=t;
newobj.setData();
fout.write((char *) &newobj,sizeof(newobj));

counter=1;
break;
}
cout<<"\n";
}
printf("========================================================\n\n");
}
fout.close();

if(counter==0)
{
cout<<"\n Sorry no record found";
}
else
{
cout<<"\n Record Updated";
}
}

//Delete Employee Details from the File – Base on ID
void deleteEmployee()
{
Employee t;
int size=getSizeofFile();

ifstream fin(fname);
ofstream fout("temp.dat");

int id;
int counter=0;

cout<>id;

if(fin==NULL)
{
cout<<"\n Sorry no record found \n";
}
else
{
for(int i=0;i<size;i++)
{
fin.read((char *) & t,sizeof(t));

if(id==t.getID())
{
counter=1;
}
else
{
fout.write((char *) & t,sizeof(t));
}
}
}
fin.close();
fout.close();

if(counter==0)
{
cout<<"\n Sorry no record found";
}
else
{
fin.open("temp.dat");
fout.open(fname);

for(int i=0;i<size-1;i++)
{
fin.read((char *) & t,sizeof(t));

fout.write((char *) & t,sizeof(t));
}

fin.close();
fout.close();
}
}

//Search Employee Details from File – Base on ID.
void searchEmployee()
{
Employee t;
int size=getSizeofFile();
int id=0;
int counter=0;

cout<>id;

ifstream fin(fname);

printf("\n========================================================\n\n");
printf("\t\t Employee Details\n\n");
printf("========================================================\n\n");

printf("ID\tName\tSalary\n\n");

for(int i=0;i<size;i++)
{
fin.read((char *) & t,sizeof(t));

if(id==t.getID())
{
t.display();
counter=1;
}
cout<<"\n";
}
printf("========================================================\n\n");

fin.close();

if(counter==0)
{
cout<<"\n Sorry no record found";
}
}

//Display all the Employee Details stored in the File
void displayAllEmployee()
{
Employee t;
int size=getSizeofFile();

ifstream fin(fname);

if(fin==NULL)
{
cout<<"\n Sorry no record found \n";
}
else
{
printf("\n========================================================\n\n");
printf("\t\t All Employee Details\n\n");
printf("========================================================\n\n");

printf("ID\tName\tSalary\n\n");

for(int i=0;i<size;i++)
{
fin.read((char *) & t,sizeof(t));
t.display();
cout<<"\n";
}
printf("========================================================\n\n");
}

fin.close();
}

//Return Total Objects stored in the File
int getSizeofFile()
{
int size;
int total;
Employee t1;

ifstream fin(fname);
fin.seekg(0,ios::end);

total=fin.tellg();

fin.close();
size=total/sizeof(t1);
return(size);
}


