#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include<ostream>
#include"iomanip"
using namespace std;

class book
{
    char bname[30];
    char aname[30];
    char bno[5];
    int price;

public:

    void addbook()
    {
        cout<<"\n\n\t\t...BOOK ENTRY...\n";

        cout<<"\nEnter Book Name : ";
        gets(bname);

        cout<<"\nEnter Author Name : ";
        gets(aname);

        cout<<"\nEnter Book Number : ";
        gets(bno);

        cout<<"\nEnter Price : ";
        cin>>price;

        cout<<"\n\n\n\tBOOK CREATED :-)\n";
    }

    void displaybook()
    {
        cout<<"\n\n\t\t...BOOK DETAILS...\n";
        cout<<"\t\t==================\n";

        cout<<"\nBook Number : ";
		puts(bno);

        cout<<"\nBook Name : ";
        puts(bname);

        cout<<"\nAuthor Name : ";
        puts(aname);

        cout<<"\nEnter Price : "; cout<<price;

    }
    void modifybook()
    {
		cout<<"\nBook number : ";
		puts(bno);

		cout<<"\nModify Book Name : ";
		gets(bname);

		cout<<"\nModify Author Name : ";
		gets(aname);

		cout<<"\nModify Price : ";
		cin>>price;
    }

    char* returnbno()
    {
    	return bno;
	}

	void report()
	{
		cout<<bno<<"."<<setw(30)<<bname<<setw(30)<<aname<<setw(5)<<price<<endl;
	}
};



class student
{
	char admno[5];
	char sname[30];
	char sbookno[10];				//issued book number
	int flag;

public:

	void addstudent()
	{
		system("cls");
		cout<<"\n\n\t\t...STUDENT ENTRY...\n";

        cout<<"\nEnter Admission Number : ";
        gets(admno);

        cout<<"\nEnter Student NAme : ";
        gets(sname);

        flag=0;					//number of books issued by specific student

        sbookno[0]='\0';		//NULL as no book issued

        cout<<"\n\n\n\tSTUDENT RECORD CREATED :-)\n";
	}

	void displaystudent()
	{
		cout<<"\n\n\t\t...BOOK DETAILS...\n";
        cout<<"\t\t==================\n";

        cout<<"Admission Number : ";
		puts(admno);

        cout<<"\nStudent Name : ";
        puts(sname);

        cout<<"\nNumber of Books Issued : "<<flag;

        if(flag == 1)
        {
        	cout<<"\nBook Number : "<<sbookno;
		}
	}

	void modifystudent()
	{
		cout<<"\nAdmission Number of Student : "<<admno;
		cout<<"\nModify Student Name : ";
		gets(sname);

	}

	char* returnadmno()
	{
		return admno;
	}

	char* returnbbokno()
	{
		return sbookno;
	}

	int returnflag()
	{
		return flag;
	}

	void addflag()
	{
		flag=1;
	}

	void resetflag()
	{
		flag=0;
	}

	void getsbookno(char s[])
	{
		strcpy(sbookno,s);
	}

	void report()
	{
		cout<<admno<<"."<<setw(30)<<sname<<setw(5)<<flag<<endl;
	}
};

fstream fp,ft;

book bk;
student st;

void writebook()
{
	char ch;

	fp.open("book.txt",ios::out|ios::app);

	do
	{
		system("cls");

		bk.addbook();
		fp.write((char*)&bk,sizeof(book));

		cout<<"\nDo you want to add more BOOK ? (y/n) : ";
		cin>>ch;

	}while(ch=='y' || ch=='Y');

	fp.close();
}

void writestudent()
{
	char ch;

	fp.open("student.txt",ios::out|ios::app);

	do
	{
		system("cls");

		st.addstudent();
		fp.write((char*)&st,sizeof(student));

		cout<<"\nDo you want to add more STUDENT ? (y/n) : ";
		cin>>ch;

	}while(ch=='y' || ch=='Y');

	fp.close();
}

void displayspecbook(char b[])		//to display sppecific book
{
	cout<<"\n: BOOK DETAILS :";
	int count=0;

	fp.open("book.txt",ios::in);

	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.returnbno(),b)==0)
		{
			bk.displaybook();
			count=1;
		}
	}

	fp.close();

	if(count==0)
	{
		cout<<"\nBook does not exist... "<<endl;
		getche();
	}
}

void displayspecstudent(char b[])		//to display specific student
{
	cout<<"\n: STUDENT DETAILS :";
	int count=0;

	fp.open("student.txt",ios::in);

	while(fp.read((char *)&st,sizeof(student)))
	{
		if(strcmpi(st.returnadmno(),b)==0)
		{
			st.displaystudent();
			count=1;
		}
	}
	fp.close();

	if(count==0)
	{
		cout<<"\n\nStudent Not Found... "<<endl;
		getche();
	}
}

void modifybook()
{
    char n[5];
    int found=0;

    system("cls");

    cout<<"\n: MODIFY BOOK RECORD :"<<endl;

    cout<<"\nEnter Book Number : ";
    cin>>n;

    fp.open("book.txt",ios::in||ios::out);

    while(fp.read((char *)&bk,sizeof(book))  && found == 0)
    {
        if(strcmpi(bk.returnbno(),n) == 0)
        {
            bk.displaybook();

            cout<<"\n\nEnter new details of book : "<<endl;

            bk.modifybook();

            int pos = -1*sizeof(bk);

            fp.seekp(pos,ios::cur);
            fp.write((char *)&bk,sizeof(book));

            cout<<"\n\n\tRECORD UPDATED...\n";
        }
    }
    fp.close();

    if(found == 0)
    {
        cout<<"\nRECORD NOT FOUND...\n"<<endl;
    }
    getche();
}

void modifystudent()
{
    char n[5];
    int found=0;

    system("cls");

    cout<<"\n: MODIFY STUDENT RECORD :"<<endl;

    cout<<"\nEnter Admission Number : ";
    cin>>n;

    fp.open("student.txt",ios::in||ios::out);

    while(fp.read((char*)&st,sizeof(student))  && found == 0)
    {
        if(strcmpi(st.returnadmno(),n) == 0)
        {
            st.displaystudent();

            cout<<"\n\nEnter new details of Student : "<<endl;

            st.modifystudent();

            int pos = -1*sizeof(st);

            fp.seekp(pos,ios::cur);
            fp.write((char *)&st,sizeof(student));

            cout<<"\n\n\tRECORD UPDATED...\n";
        }
    }
    fp.close();

    if(found == 0)
    {
        cout<<"\nRECORD NOT FOUND...\n"<<endl;
    }
    getche();
}

void deletebook()
{
    char n[5];
    int found=0;

    system("cls");

    cout<<"\n\n\n\t: DELETE BOOK :";
    cout<<"\nEnter the Book Number : ";
    cin>>n;

    fp.open("book.txt",ios::in||ios::out);
    fstream fp2;
    fp2.open("temp2.txt",ios::out);
    fp.seekg(0,ios::beg);

    while(fp.read((char *)&bk,sizeof(book)))
    {
        if(strcmpi(bk.returnbno(),n) != 0)
        {
           fp2.write((char *)&bk,sizeof(book));
        }
        else
        {
            found=1;
        }
    }

    fp2.close();
    fp.close();

    remove("book.txt");
    rename("temp2.txt","book.txt");

    if(found==1)
    {
        cout<<"\n\n\tRECORD DELETED...\n";
    }
    else
    {
        cout<<"\nRECORD NOT FOUND...\n"<<endl;
    }
    getche();
}


void deletestudent()
{
    char n[5];
    int found=0;

    system("cls");

    cout<<"\n\n\n\t: DELETE STUDENT :";
    cout<<"\nEnter the admission number : ";
    cin>>n;

    fp.open("student.txt",ios::in||ios::out);
    fstream fp2;
    fp2.open("temp.txt",ios::out);
    fp.seekg(0,ios::beg);

    while(fp.read((char *)&st,sizeof(student)))
    {
        if(strcmpi(st.returnadmno(),n) != 0)
        {
           fp2.write((char *)&st,sizeof(student));

        }
        else
        {
            found=1;
        }
    }

    fp2.close();
    fp.close();

    remove("student.txt");
    rename("temp.txt","student.txt");

    if(found==1)
    {
        cout<<"\n\n\tRECORD DELETED...\n";
    }
    else
    {
        cout<<"\nRECORD NOT FOUND...\n"<<endl;
    }
    getche();
}

void displaystudents()
{
    system("cls");
    fp.open("student.txt",ios::in);
    if(!fp)
    {
        cout<<"\nFILE COULD NOT OPEN...";
        getche();
        return;
    }

    cout<<"\n\n\t: STUDENT LIST :";
    cout<<"\n================================================\n";

    cout<<"\tADMISSION NO."<<setw(10)<<"NAME"<<setw(20)<<"BOOK ISSUED";
    cout<<"\n================================================\n";

    while(fp.read((char *)&st,sizeof(student)))
    {
        st.report();
    }

    fp.close();
    getche();
}

void displaybooks()
{
    system("cls");
    fp.open("book.txt",ios::in);
    if(!fp)
    {
        cout<<"\nFILE COULD NOT OPEN...";
        getche();
        return;
    }

    cout<<"\n\n\t: BOOK LIST :";
    cout<<"\n================================================\n";

    cout<<"\tBOOK NO."<<setw(30)<<"NAME"<<setw(30)<<"AUTHOR NAME"<<setw(5)<<"PRICE";
    cout<<"\n================================================\n";

    while(fp.read((char *)&bk,sizeof(book)))
    {
        bk.report();
    }

    fp.close();
    getche();
}



void start()
{
    system("Color 3F");
    printf("\n\n\n\n\t\t\t\t=====================================================");
    printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t\t\t\t=====================================================");
    printf("\n\t\t\t\t[|:::>:::>::>:>  LIBRARY  MANAGEMENT  <:<::<:::<:::|]\t");
    printf("\n\t\t\t\t=====================================================");
    printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t\t\t\t=====================================================\n");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\tDeveloper : @Sushant_Gaurav\n\n\t\t\t\t");

    system("pause");
}


int main()
{
    start();
    return 0;
}

























