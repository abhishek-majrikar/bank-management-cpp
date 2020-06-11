#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<stdio.h>
using namespace std;

class bmlogin
{
	char username[20],password[20];
	int attempt;
	public:
		void getvalue();
		void checkvalue();
		void mainmenu();
		bmlogin()
		{
			attempt=1;
		}

}x;


class admin
{
 protected:
 		char name[20],acc_tp[20];
		int acc_no,phone,balance;
 public:
	       virtual void fldisplay()
	       {
	       }
};

class String
{
        public:
                char str[20];
        public:
                void accept_string()
                {
                        cout<<"\n\n\t\t\t Enter String:   ";
                        cin>>str;
                }
                
                void display_string()
                { 
                        cout<<str;
                }
                
                String operator+(String x)  //Concatenating String
                {
                        String s;
                        strcat(str,x.str);
                        strcpy(s.str,str);
                        return s;
                }
                
                void welcomescreen()
                {
                	String str1, str2, str3;
                	
                	cout<<"\n\n\t\t************BANK MANAGMENT SYSTEM************";
                	cout<<"\n\n\t\t************    WELCOME SCREEN       ************";
                
        			str1.accept_string();
        			str2.accept_string();

        			cout<<"\n\t\t\t ----------------------------------------------";
       			    cout<<"\n\n\t\t\t First String is           :  ";
                    str1.display_string();   //Displaying First String

                    cout<<"\n\n\t\t\t Second String is          :  ";
                    str2.display_string();  //Displaying Second String

                    cout<<"\n\t\t\t ----------------------------------------------";
                    str3=str1+str2;         //String is concatenated. Overloaded '+' operator
                    cout<<"\n\n\t\t\t A message String is    :  ";
                    str3.display_string();
                    cout<<"\n\n\t\t\t Your Message is Displayed...Enjoy Coding";
                    getch();
				}
}objwelcome;


class stud:public admin
{
   public:
   stud()
   { }
   stud(int idd) ;

	void fldelete();
	void add_acc();
	void display();
	void flsearch(int);
	void flsearch(char *);
	void flwrite();
	void fldisplay();
	void flsearch();
	void flupdate();
	void updateinfo();
	friend class update_record;
}obj;

class update_record
{
 public:
 void updaterecord(stud& obup,int id_up);
};

void stud::updateinfo()
{
	cout<<"\n\tEnter Account Number: ";
	cin>>acc_no;
	cout<<"\n\tEnter Bank Holder Name: ";
	cin>>name;
	cout<<"\n\tEnter Account Type(C/S): ";
	cin>>acc_tp;
	cout<<"\n\tEnter Your Mobile No: ";
	cin>>phone;
}

void stud::flupdate()
{
 int idup;
 update_record obj_up;
 stud objs_up;
 cout<<"\n\tEnter The ID You Want To Update: ";
 cin>>idup;
 obj_up.updaterecord(objs_up,idup);
}

void update_record::updaterecord(stud& obup,int id_up)
{
fstream fip;
int found=0;
fip.open("bank",ios::in|ios::out|ios::binary);
while(fip.read((char *)&obup,sizeof(obup))!=NULL)
{
	if(obup.acc_no==id_up)
	{
		int loc=-1*sizeof(obup);
		obup.updateinfo();
		fip.seekp(loc,ios::cur);
		fip.write((char *)&obup,sizeof(obup));
		found=1;
		break;
	}
}
if(found==0)
{
	cout<<"\n\tDetails Not Found,You Can't Update The Details!";
}
else
{
	cout<<"\n\tDetails Updated Successfully!!";
}
fip.close();
}

void stud::flsearch()
{
	int choice,id;
	char name[20];
	cout<<"\n\t 1.Search by Id\n\t 2.Search by Name:\n\t Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
	case 1:cout<<"\n1.Enter ID To Search: ";
	   cin>>id;
	   flsearch(id);
	   break;
	case 2:cout<<"\n2.Enter Name To Search: ";
	   cin>>name;
	   flsearch(name);
	   break;
	default:cout<<"\nInvalid choice";
	  break;
	}
}

 void stud::fldelete()
 {
	int del;
	cout<<"\n\t Enter Account Number To Delete: ";
	cin>>del;
	stud objdel(del);
 }

  stud :: stud(int idd)
  {
	stud objdelete;
	ifstream fip;
	ofstream fop;
	fip.open("bank",ios::binary);
	fop.open("AM",ios::binary|ios::app);
	while(fip.read((char*)&objdelete,sizeof(objdelete))!=NULL)
	{
  		if(objdelete.acc_no!=idd)
  		{
  		fop.write((char *)&objdelete,sizeof(objdelete));
  		}
 	}
	cout<<"\nRecord deleted successfully";
	fip.close();
	fop.close();
	remove("bank");
	rename("AM","bank");
	remove("AM");
    }

 void stud::flsearch(int ids)
 {
	stud objs;
	int found=0;
	ifstream fip;
	fip.open("mystore",ios::binary);
	while(fip.read((char *)&objs,sizeof(objs))!=NULL)
	{
	if(objs.acc_no==ids)
 	{
  	found=1;
  	break;
 	}
}
if(found==1)
{
	cout<<"\n***************************";
	cout<<"\n\tName: "<<objs.name;
	cout<<"\n\tAccount type: "<<objs.acc_tp;
	cout<<"\n\tAccount number: "<<objs.acc_no;
	cout<<"\n\tMobile number: "<<objs.phone;
	cout<<"\n\tBalance: "<<objs.balance;
	cout<<"\n***************************";
}
else
{
 cout<<"DETAILS NOT FOUND!";
}
fip.close();
}

 void stud::flsearch(char name[])
 {
	stud objs;
	int found=0;
	ifstream fip;
	fip.open("bank",ios::binary);
	while(fip.read((char *)&objs,sizeof(objs))!=NULL)
	{
 	if(strcmp(objs.name,name)==0)
 		{
  			found=1;
  			break;
 		}
	}
	if(found==1)
	{
	cout<<"\n*****************************";
	cout<<"\n\t1.Name: "<<objs.name;
	cout<<"\n\t2.Account type: "<<objs.acc_tp;
	cout<<"\n\t3.Account number: "<<objs.acc_no;
	cout<<"\n\t4.Mobile number: "<<objs.phone;
	cout<<"\n\t5.Balance: "<<objs.balance;
	cout<<"\n***************************";
}
else
{
 	cout<<"DETAILS NOT FOUND!";
}
fip.close();
}

void bmlogin::getvalue()
{
	int i=0;
	char ch;

	cout<<"\n\t\t\t\tADMIN LOGIN\n\n\t\t\t\tEnter Username: ";
	cin>>username;
	cout<<"\n\t\t\t\tEnter Password: ";
	ch=getch();
	while(ch!=13)
	{
		if(ch!=13&&ch!=8)
		{
			putch('*');
			password[i]=ch;
			i++;
			ch=getch();
		}
	}
	password[i]='\0';
}

void bmlogin::checkvalue()
{
	while(attempt<3)
	{
		if(strcmp(username,"admin")==0&&strcmp(password,"1234")==0)
		{
			cout<<"\n\t\t\t\tLogin Successful!!";
			system("PAUSE");
			mainmenu();
		}
		else
		{
			cout<<"\n\t\t\tINVALID CREDINTIALS !!!";
			system("PAUSE");
			attempt++;
			getvalue();
		}
	}
}

void bmlogin::mainmenu()
{
	int ch;
	system("CLS");
	cout<<"\n\t\t************************************************************\n";
	cout<<"\n\t\t\tWELCOME TO BANK MANAGEMENT SYSTEM\n";
	cout<<"\n\t\t************************************************************\n";

	cout<<"\n\n\t\t\t1. Add Account"
	<<"\n\n\t\t\t2. Delete Account"
	<<"\n\n\t\t\t3. Update Account"
	<<"\n\n\t\t\t4. Search Account"
	<<"\n\n\t\t\t5. Display Account"
	<<"\n\n\t\t\t6. EXIT"
	<<"\n\n\t\t Enter your Choice";
	cin>>ch;
	switch(ch)
	{
		case 1:
			obj.flwrite();
			break;
		case 2:obj.fldelete();
			break;
		case 3:obj.flupdate();
			break;
		case 4:
			obj.flsearch();
			break;
		case 5:
			obj.fldisplay();
			break;
		case 6:exit(0);
			break;
		default:cout<<"\n INVALID CHOICE";
	}
}

void stud::flwrite()
{
	ofstream fp;
	fp.open("bank",ios::binary | ios::app);
	stud s;
	s.add_acc();
	fp.write((char *)&s,sizeof(s));
	fp.close();
}

void stud::fldisplay()
{
	ifstream fip;
	fip.open("bank",ios::binary);
	stud objs;
	while(fip.read((char*)&obj, sizeof(obj))!=NULL)
	{
	cout<<"\n*****************************";
	cout<<"\n\t1.Name: "<<objs.name;
	cout<<"\n\t2.Account type: "<<objs.acc_tp;
	cout<<"\n\t3.Account number: "<<objs.acc_no;
	cout<<"\n\t4.Mobile number: "<<objs.phone;
	cout<<"\n\t5.Balance: "<<objs.balance;
	cout<<"\n***************************";
	 }
	fip.close();
}

 void stud::add_acc()
{
	char ch;
	
	cout<<"\n\tEnter Account Number: ";
	cin>>acc_no;
	cout<<"\n\tEnter Bank Holder Name: ";
	cin>>name;
	cout<<"\n\tEnter Account Type(C/S): ";
	cin>>acc_tp;
	cout<<"\n\tEnter Your Mobile No: ";
	cin>>phone;
	
	cout<<"\n\nDo You Want To Continue (y/n): ";
	cin>>ch;
	if(ch=='y')
	{
		flwrite();
	}
	else
	{
	 void mainmenu();
	 }
}

int main()
{
	int choice;

 	objwelcome.welcomescreen();

 	cout<<"\n\n\t***************||  BANK MANAGEMENT SYSTEM  ||*********************\n";
	cout<<"\n\t\t\t\t1.ADMIN\n\t\t\t\t2.USER\n\t\t\t\t3.EXIT\n\n\t\tEnter your choice: ";
	cin>>choice;
 try
 {
 	
	if(choice<=0 || choice>=4)
	{
		throw (choice);
	}
	else
	{
		switch(choice)
	{

		case 1:x.getvalue();
		       x.checkvalue();
		break;
		case 2:x.getvalue();
		       x.checkvalue();
			   break;
		case 3:exit(0);
		break;
	}
	
    }
	}
	catch (int c)
	{
		cout<<"\n\tException Caught: Error in entering choice by the user.";
	}
	return 0;
}

