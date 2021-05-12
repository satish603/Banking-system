/***************************************************************************/
			       //SOURCE CODE
/***************************************************************************/
/***************************************************************************/
			       //HEADER FILES
/***************************************************************************/
#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<ctype.h>
#include<string.h>

/***************************************************************************/
				//CLASS
/***************************************************************************/

class banking
{
 int accno;
 long acbal;
 char name[25],add[50],gender[10],phone[11],dob[11],btype[15],nominee[25];
 char eid[25];
 
public:
 void crtbacc();
 void shwpdet();
 void shwbdet();
 /*******************/
 void wrtacc();
 void modA();
 void modE();
 /*******************/
 void modC(int);
 void search();
 void del();
 void show();
 void showall();	
 void exit();
 void intro();
 void desk();
  /*******************/
 int retaccno()
 {return accno;
 }
 long retacbal()
 {return acbal;
 }
}B;

/***************************************************************************/
		      //FUNCTION TO CREATE AN ACCOUNT
/***************************************************************************/


void banking::crtbacc()
{
 cout<<"\n\n\t\t--------Account Creation--------\n\n\n";
 cout<<"\tEnter the Account Holder Name: ";
 gets(name);
 cout<<"\n\t";
 cout<<"Enter the Date of Birth (DD/MM/YYYY): ";
 gets(dob);
 cout<<"\n\t";
 cout<<"Enter the emailID: ";
 gets(eid);
 cout<<"\n\t";
 cout<<"Enter the Gender: ";
 gets(gender);
 cout<<"\n\t";
 cout<<"Enter the Phone Number: ";
 gets(phone);
 cout<<"\n\t";
 cout<<"Enter the Address: ";
 gets(add);
 cout<<"\n\t";
 cout<<"Enter the Name of the Nominee: ";
 gets(nominee);
 cout<<"\n\t";
 cout<<"\nEnter the Account Number: ";
 cin>>accno;
 cout<<"\n";
 cout<<"Enter the type of Bank Account: ";
 gets(btype);
 cout<<"\n";
 cout<<"Enter the Amount to be deposited : ";
 cin>>acbal;
 cout<<"\n";
 cout<<"\n\n\nAccount created Successfully....\n\n\t\t";
}

/***************************************************************************/
		      //FUNCTION TO DISPLAY BANK DETAILS
/***************************************************************************/


void banking::shwbdet()
{
clrscr();
cout<<"******************************************************************\n";
cout<<"\t\t\tAccount  Details\n";
cout<<"******************************************************************\n\n";

       cout<<"\nAccount Number     : "<<accno;
       cout<<"\nAccount Holder Name: "<<name;
       cout<<"\nAccount Type       : "<<btype;
       cout<<"\nAccount Balance    : "<<acbal;
}


/***************************************************************************/
		  //FUNCTION TO DISPLAY PERSONAL DETAILS
/***************************************************************************/


void banking::shwpdet()
{
cout<<"\n\n******************************************************************\n";
cout<<"\t\t\tPersonal Details\n";
cout<<"******************************************************************\n";

       cout<<"\nAccount Holder Name: "<<name;
       cout<<"\nAddress            : "<<add;
       cout<<"\nDate of Birth      : "<<dob;
       cout<<"\nGender             : "<<gender;
       cout<<"\nPhone no           : "<<phone;
       cout<<"\nE-mail ID          : "<<eid;
       cout<<"\nNominee            : "<<nominee;
}


/***************************************************************************/
		     //FUNCTION TO WRITE IN FILE
/***************************************************************************/


void banking::wrtacc()
{
	      ofstream fout;
	      fout.open("Accounts.dat",ios::binary|ios::app);
      clrscr();
      {B.crtbacc();
       fout.write((char*)&B,sizeof(B));
      }
	      fout.close();
 cout<<"\n\n\t\t";
 getch();
 B.desk();
}

/***************************************************************************/
		//FUNCTION TO MODIFY AN ACCOUNT AFTER DEPOSITING
/***************************************************************************/


void banking::modA()
{     clrscr();
      int p,a=0;
      long d;
      cout<<"\n\n\n\n\n\n\n\n\n\n\t\tEnter the Account number: ";
      cin>>p;
      cout<<endl;
      fstream f;
      f.open("Accounts.dat",ios::binary|ios::in|ios::out);
      while(f.read((char*)&B,sizeof(B)))
      {
       if(B.retaccno()==p)
		  {
		   B.shwbdet();
		   cout<<endl;
		   cout<<"\n\n\n\n\n\n\n\n\n\n\t\tEnter the Amount to be Deposited: ";
		   cin>>d;
		   acbal+=d;
		   int pos=-1*sizeof(B);
		   f.seekp(pos,ios::cur);
		   f.write((char*)&B,sizeof(B));
		   cout<<"\n\n\n\nAccount Successfully Updated!!\n\n\n\t\t";
		   getch();
		   a=1;
		   }
       }
       if(a==0)
	 { clrscr();
	   cout<<"\n\n\n\n\n\n\n\n\n\n\t\tEntered Account Number Does not Exist\n\n\t\tPress any key to Continue."<<endl;
	 }
       f.close();
       getch();
       B.desk();
}

/***************************************************************************/
		//FUNCTION TO MODIFY AN ACCOUNT AFTER WITHDRAWING
/***************************************************************************/


void banking::modE()
{     clrscr();
      int p,a=0;
      long d;
      cout<<"\n\n\n\n\n\n\n\n\n\n\t\tEnter the Account number: ";
      cin>>p;
      cout<<endl;
      fstream f;
      f.open("Accounts.dat",ios::binary|ios::in|ios::out);
      while(f.read((char*)&B,sizeof(B)))
      {
       if(B.retaccno()==p)
		  {
		   B.shwbdet();
		   cout<<endl;
		   cout<<"\n\n\n\n\n\n\n\n\n\n\t\tEnter the Amount to be Withdrawn: ";
		   cin>>d;
		   acbal-=d;
		   int pos=-1*sizeof(B);
		   f.seekp(pos,ios::cur);
		   f.write((char*)&B,sizeof(B));
		   cout<<"\n\n\n\nAccount Successfully Updated!!\n\n\n\t\t";
		   getch();
		   a=1;
		   }
       }
	  if(a==0)
	  {clrscr();
	   cout<<"\n\n\n\n\n\n\n\n\n\n\t\tEntered Account Number Does not Exist\n\n\t\tPress any key to Continue."<<endl;
	  }
       f.close();
       getch();
       B.desk();
}
/***************************************************************************/
			//FUNCTION TO DISPLAY DETAILS
/***************************************************************************/


void banking::show()
{
 cout<<endl;
 cout<<accno<<setw(20)<<name<<setw(20)<<btype<<setw(30)<<acbal<<endl;
}

/***************************************************************************/
			//FUNCTION TO DISPLAY ALL DETAILS
/***************************************************************************/

void banking::showall()
{
cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
 cout<<"Account Number"<<setw(10)<<"Name"<<setw(20)<<"Account Type"<<setw(30)<<"Account Balance\n";
cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
       ifstream fin;
       fin.open("Accounts.dat",ios::binary|ios::in);
       while(fin.read((char*)&B,sizeof(B)))
      {
       B.show();
      }
       fin.close();
       cout<<"\n\n\t\t";
       getch();
       B.desk();
}

/***************************************************************************/
		      //FUNCTION TO SEARCH AN ACCOUNT
/***************************************************************************/


void banking::search()
{
	int s,fnd=0;
 cout<<"\n\n\n\nEnter the Account Number :";
 cin>>s;
 ifstream fin;
 fin.open("Accounts.dat",ios::binary|ios::in);
  while(fin.read((char*)&B,sizeof(B)))
 { if(B.retaccno()==s)
		 {B.shwbdet();
		  cout<<endl;
		  B.shwpdet();
		  cout<<"\n\n\t\t";
		  fnd+=1;
		  getch();
		  B.desk();
		 }
 }
   if(fnd==0)
   {clrscr();
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\tEntered Account Number Does not Exist..\n\n\t\t";
    getch();
    B.desk();
   }
   getch();
 fin.close();
 }

/***************************************************************************/
		      //FUNCTION TO MODIFY AN ACCOUNT
/***************************************************************************/


void banking::modC(int C)
{clrscr();
 int fnd=0;
 fstream f;
 f.open("Accounts.dat",ios::binary|ios::in|ios::out);
	       while(f.read((char*)&B,sizeof(B)))
	    {
	     if(B.retaccno()==C)
	      {
	       {cout<<"\n\n\n\nEnter the New Details of the Account Holder\n\n";
		cout<<"\n\n\t\t--------Account Modification--------\n\n\n";
		cout<<"\tEnter the Account Holder Name: ";
		gets(name);
		cout<<"\n\t";
		cout<<"Enter the Date of Birth (DD/MM/YYYY): ";
		gets(dob);
		cout<<"\n\t";
		cout<<"Enter the emailID: ";
		gets(eid);
		cout<<"\n\t";
		cout<<"Enter the Gender: ";
		gets(gender);
		cout<<"\n\t";
		cout<<"Enter the Phone Number: ";
		gets(phone);
		cout<<"\n\t";
		cout<<"Enter the Address: ";
		gets(add);
		cout<<"\n\t";
		cout<<"Enter the Name of the Nominee: ";
		gets(nominee);
		cout<<"\n\n\tAccount Modified Successfully..";
	       }
	       int pos=(-1)*sizeof(B);
		f.seekp(pos,ios::cur);
		f.write((char*)&B,sizeof(B));
		fnd+=1;
	      }
	     }
	     if(fnd==0)
	     {
	      cout<<"\n\n\n\n\n\n\n\n\n\n\t\tEntered Account Number does not exist....\n\n\t\tPress any key to continue";
	     }
 f.close();
 getch();
 B.desk();
}

/***************************************************************************/
		     //FUNCTION TO CLOSE AN ACCOUNT
/***************************************************************************/


void banking::del()
{   clrscr();
    int dl,fnd=0;
    ifstream fin;
    fin.open("Accounts.dat",ios::binary|ios::in);
    ofstream fout;
    fout.open("Temp.dat",ios::binary|ios::out);
    cout<<"\n\n\t\t--------Account Deletion--------\n\n\n";
    cout<<"\n\n\n\n\n\n\n\n\t\tEnter the Account number: ";
    cin>>dl;
    while(fin.read((char*)&B,sizeof(B)))
    {
     if(B.retaccno()!=dl)
       {fout.write((char*)&B,sizeof(B));
       }
     if(B.retaccno()==dl)
      { fnd+=1;
      }
    }
	   if(fnd==0)
	     {clrscr();
	      cout<<"\n\n\n\n\n\n\n\n\n\n\t\tEntered Account Number does not exist....\n\n\t\t";
	     }
	   else
	    {   cout<<"\n\n\t\tACCOUNT CLOSED.....";
		cout<<"\n\n\n\n\t\t";
	    }
   fin.close();
   fout.close();
   remove("Accounts.dat");
   rename("Temp.dat","Accounts.dat");
   getch();
   B.desk();
}




/***************************************************************************/
				//EXIT FUNCTION
/***************************************************************************/

void banking::exit()
{clrscr();
 cout<<"\n\n\n\n\n\n\t\t\t.....Thanks For Visiting.....\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t";
 getch();
}

/***************************************************************************/
			      //INTRO FUNCTION
/***************************************************************************/

void banking::intro()
{
 cout<<"\n\n\n\n\n\n.............................Bank Management System.............................";
 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t";
 getch();
}

/***************************************************************************/
				//HOME
/***************************************************************************/


void banking::desk()
{head:
 clrscr();
 cout<<"\t\t\t\tHome";
 cout<<"\n\n\n1.Create a New Account";
 cout<<    "\n\n2.Account Transaction";
 cout<<    "\n\n3.Search an Account";
 cout<<    "\n\n4.All Account details";
 cout<<    "\n\n5.Modifying Account details";
 cout<<    "\n\n6.Account Closing";
 cout<<    "\n\n7.Exit";
 cout<<    "\n\n\n\t\tEnter your choice(1-7): ";
 int c,ch;
 cin>>ch;
 clrscr();
 switch(ch)
 {
 case 1:B.wrtacc();
	  break;
 case 2:{
             c:
             clrscr();
	  int i;
	  cout<<"\n\n\n\n\t1.Cash Deposit\n\n\t2.Cash Withdrawal";
	  cout<<"\n\n\n\t\tEnter your Choice(1 or 2): ";
	  cin>>i;
	  if(i==1)
	  B.modA();
	  else if(i==2)
	  B.modE();
              else goto c;
	 }
	  break;
 case 3:B.search();
	  break;
 case 4:B.showall();
	  break;
 case 5:cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tEnter the Account number: ";
	  cin>>c;
	  B.modC(c);
	  break;
 case 6:B.del();
	  break;
 case 7:B.exit();
	  break;
 default:{cout<<"\n\n\n\n\n\n\n\n\n\n\t\tOops!! Wrong Choice..\n\n\t\t";
	  getch();
	  goto head;
	    }
  }
}

/***************************************************************************/
			       //MAIN FUNCTION
/*-------------------------------------------------------------------------*/
/***************************************************************************/


void main()
{clrscr();
 B.intro();
 B.desk();
}
/***************************************************************************/
/*-------------------------------------------------------------------------*/
