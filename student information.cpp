#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;

class Student
{
	 int rno;
	 char name[20];
	 float fm;
	 public:
	 	 void setData();
	 	 void getData();
	 	 void modifyData();
	 	 void searchData();
	 	 void deleteData();
	 	 
		 
}s;

		 void Student::setData()
	 	{
	 		ofstream fout("Student.dat",ios::app|ios::binary);
	
	 		cout<<"\nEnter Student Detail:\n";
	 		cout<<"Enter roll number";
			cin>>rno;
			cout<<"\nEnter Name:";
			cin.ignore();
			cin.getline(name,20);
			cout<<"\nEnter Marks:";
			cin>>fm;
	        fout.write((char*)this,sizeof(*this));
	        fout.close();
		 }
		 
		void Student:: getData()
		{
			 	ifstream fin("Student.dat",ios::in|ios::binary);
			 		while(fin.read((char*)this,sizeof(*this)))
					{
			
						cout<<"\nDetail of Student:\n";
						cout<<"\nStudent rno:"<<rno;
						cout<<"\nStudent Name:"<<name;
						cout<<"\nstudent marks:"<<fm;
					}
					
					fin.close();
		}
		
		 void Student::modifyData()
		 {
		 	     int sno,f=0;
		 	     
		 	     cout<<"\nEnter student rno:";
		 	     cin>>sno;
				    ofstream fout("temp.dat",ios::out|ios::binary);
					ifstream fin("Student.dat",ios::in|ios::binary);
			 		while(fin.read((char*)this,sizeof(*this)))
					{
			           if(sno==rno)
                        {
					     	cout<<"\nEnter Student Detail:\n";
							cin>>rno;
							cout<<"\nEnter Name:";
							cin.ignore();
							cin.getline(name,20);
							cout<<"\nEnter Marks:";
							cin>>fm;
					        fout.write((char*)this,sizeof(*this));
					     f=1;
						
					   }
					   else
					   fout.write((char*)this,sizeof(*this));
					}
					
					if(f==0)
					cout<<"\nStudent not found";
		         fout.close();
		         fin.close();
		         
		         remove("Student.dat");
		         rename("temp.dat","Student.dat");
		         
		 }
	 	 void Student::searchData()
	 	 {
	 	         char sname[20];
	 	         int f=0;
		 	     cout<<"\nEnter student name:";
		 	     cin.ignore();
		 	     cin.getline(sname,20);
		 	       ifstream fin("Student.dat",ios::in|ios::binary);
			 		while(fin.read((char*)this,sizeof(*this)))
					{
			           if(!strcmp(sname,name))
                        {
												cout<<"\nDetail of Student:\n";
									cout<<"\nStudent rno:"<<rno;
						cout<<"\nStudent Name:"<<name;
						cout<<"\nstudent marks:"<<fm;
						f++;
						
					   }
					}
					
					if(f>0)
					cout<<f<<"times found";
					else
					cout<<"\nStudent not found";
		           fin.close();
		  }
		  
		  
	 	 void Student::deleteData()
	 	 {
}
     int main()
{
	 int ich;
	 while(1)
	 {
	 	 system("cls");
	 	 cout<<"\n1.input";
	 	 cout<<"\n2.show";
	 	 cout<<"\n3.search";
	 	 cout<<"\n4.modify";
	 	 cout<<"\n5.delete";
	 	 cout<<"\n6.exit";
	 	 cout<<"\nEnter your choice:";
	 	 cin>>ich;
	 	 system("cls");
	 	 switch(ich)
	 	 {
	 	 	 case 1:
	 	 	 	s.setData();
	 	 	 break;
	 	 	 case 2:
	 	 	 	s.getData();
	 	 	 break;
	 	 	 case 3:
	 	 	 	s.searchData();
	 	 	 break;
	 	 	 case 4:
	 	 	 	s.modifyData();
	 	 	 break;
	 	 	 case 5:
	 	 	 	s.deleteData();
	 	 	 break;
	 	 	 case 6:
	 	 	 	exit(0);
	 	 	 default :
	 	 	 	cout<<"\nWrong choice";
	 	 	 	
		  }//switch block over here
		  
		  cout<<endl;
		  system("pause");
	 }//while block  over here
	
	
}


//main
