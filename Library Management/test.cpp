#include<iostream>   /////////////////////////////////////////
#include<iomanip>    /////////////////////////////////////////
#include<fstream>    /////////////////////////////////////////
#include<conio.h>    //////////////////Header/////////////////
#include<string.h>   //////////////////Files//////////////////
#include<stdio.h>    /////////////////////////////////////////
#include <cstdlib>   /////////////////////////////////////////
#include <windows.h> /////////////////////////////////////////
using namespace std;
//////////////////////////////////////
//////function prototypes/////////////
//////////////////////////////////////
void gotoxy(short , short );
void display(); //display function
void add();     //add function
void search();  //search function
void sort();    //sort function
void del();     //delete function
void modify();  //modify function
void sbyname(); //search by name
void sbyid();   //search by id
void sbycategory();  //search by category
void sbypubcom();    //search by publcation company
void sbypubyear();   //search by publishing year
void sbyauthor();    //search by author
void sortas();     //sort in ascending order
void sortds();     //sort in descending order
void sortasname(); //sort in ascending order by name
void sortasid();   //sort in ascending order by id
void sortascategory();  //sort in ascending order by category
void sortaspubcom();   //sort in ascending order by publication company
void sortaspubyear();  //sort in ascending order by publication year
void sortasauthor();  //sort in ascending order by author
void sortdsname();   //sort in descending order by name
void sortdsid();     //sort in descending order by id
void sortdscategory();  //sort in descending order by category
void sortdspubcom();    //sort in descending order by publication company
void sortdspubyear();   //sort in descending order by publication year
void sortdsauthor();    //sort in descending order by author
void dbyname();    //delete by name
void dbyid();      //delete by id
void dbycategory();  //delete by category
void dbypubcom();    //delete by publication company
void dbypubyear();   //delete by publication year
void dbyauthor();    //delete by author
void mbyname();      //modify by name
void mbyid();        //modify by id
void mbycategory();  //modify by cateory
void mbypubcom();    //modify by publication company
void mbypubyear();    //modify by publication year
void mbyauthor();    //modify by author

struct book       //structure of name book
{
	int bookid;                ///////////////////////////
	char bookname[60];         ///////////////////////////
	char authorname[40];       ///////////////////////////
	char bookcategory[20];     ///Members of structure///
	char bookpubcom[30];       ///////////////////////////
	char bookpubmonth[10];     ///////////////////////////
	int bookpubyear;           ///////////////////////////
};

    book books[1000];          //array of structures
    int n=0;                   //global variable for number of records

//////////////////////////////////////
///////////////////main///////////////
/////////////////////////////////////
int main()
{
	char ch1;
	while (1)
    {
		system("cls");

		cout << setw( 25 ) << "-------------" << endl

          << setw( 25 ) << "| MAIN MENU |" << endl

          << setw( 25 ) << "-------------" << endl << endl

          << setw( 52 )

          << "Please choose one of the options below: "

          << endl << setw( 71 )

          << "--------------------------------------------------------------"

          << endl << endl



          << setw( 25 ) << "( A ) Add Book" << endl << endl

          << setw( 31 ) << "( O ) Sort all Books" << endl << endl

          << setw( 33 ) << "( S ) Search all Books" << endl << endl

          << setw( 33 ) << "( D ) Diplay all Books" << endl << endl

          << setw( 30 ) << "( T ) Delete a Book" << endl << endl

          << setw( 40 ) << "( M ) Update Book Information" << endl << endl

		  << setw( 21 ) << "( Q ) Quit" << endl << endl
		  <<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
			gotoxy(30,21);

		switch(getche())
		{
			case 'a':
		 	case 'A':add();break;

			case 'd':
		 	case 'D': display();break;

		 	case 'S':
		 	case 's':search();break;

		 	case 't':
		 	case 'T':del();break;

		 	case 'O':
		 	case 'o':sort();break;

		 	case 'm':
		 	case 'M':modify();break;

		 	case 'q':
		 	case 'Q':exit(0);break;

		 	default:
			puts("\n\n \t\tSelect only from the given menu.....\n \t\tpress enter to to go to main menu......");
			getch();
       } //end switch
     }//end while

	getch();
 }//end main

//////////////////////////////////////
///////////////////Display///////////////
/////////////////////////////////////

void display(void)
	{
		system("cls");
		cout<< "In display function\n";
		cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
		cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
		cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
		for(int i=0;i<n;i++)
			{
				cout<<setw(10)<<books[i].bookid<<setw(50)<<books[i].bookname<<setw(30)<<books[i].authorname<<setw(30)<<books[i].bookcategory<<setw(30)<<books[i].bookpubcom<<setw(30)<<books[i].bookpubmonth<<setw(30)<<books[i].bookpubyear<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			}
			cout<<"Press enter to goto main manu.....";
			getch();

	}


//////////////////////////////////////
///////////////////Add///////////////
/////////////////////////////////////
void add(void)
	{
		char ch;char id1[6],year[4];
		do
		{
			system("cls");
			cout<<endl;
			cout<< "In ADD function\n";
			cout<<"Enter Book Name: ";
			gets(books[n].bookname);
			//cin.getline(emp[n].name,40);
			//cin.ignore(40,'\n');
			cout<<"Enter Book ID: ";
			gets(id1);
			books[n].bookid=atoi(id1);
			//cin.ignore();
			cout<<"Enter Author Name: ";
			gets(books[n].authorname);
			cout<<"Enter Book Category: ";
			gets(books[n].bookcategory);
			cout<<"Enter Publication Company Name: ";
			gets(books[n].bookpubcom);
			cout<<"Enter Publication Month: ";
			gets(books[n].bookpubmonth);
			cout<<"Enter Publication Year: ";
			gets(year);
			books[n].bookpubyear=atoi(year);
			n++;
		cout<<"Do you want to add more books? [y/n]";
		ch=getch();
		}
		while(ch!='n'&& ch!='N');
	}

//////////Search////////////////////
void search(void)
	{
		system("cls");

	   cout <<setw(30)<< "In Search Function"<<endl
          << setw( 52 )<< "Please choose one of the options below: "

          << endl << setw( 71 )

          << "--------------------------------------------------------------"

          << endl << endl

          << setw( 31 ) << "( N ) Search by name" << endl << endl

          << setw( 29 ) << "( I ) Search by Id" << endl << endl

          << setw( 38 ) << "( T ) Search by author name" << endl << endl

          << setw( 35 ) << "( C ) Search by Category" << endl << endl

          << setw( 46 ) << "( P ) Search by Publication Company" << endl << endl

          << setw( 43 ) << "( Y ) Search by Publication Year" << endl << endl

		  <<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
			gotoxy(30,16);

	   switch(getche())
       {
         case 'n':
		 case 'N':sbyname();break;

		 case 'i':
		 case 'I': sbyid();break;

		 case 't':
		 case 'T': sbyauthor();break;

		 case 'c':
		 case 'C':sbycategory();break;

		 case 'p':
		 case 'P':sbypubcom();break;

		 case 'y':
		 case 'Y':sbypubyear();break;

         default:
		puts("\n\n \t\tSelect only from the given menu.....\n\t\tPress enter to select again.....");
		getch();
		search();
		getch();
       }
	}

///////Search by name///////

void sbyname(void)
	{
		char name[60];
		int loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"Searching by name of book\n";
		cout<<"Enter the name of book you want to search: ";
		gets(name);
		for(int i = 0;i<n;i++)
		{
			if(strcmp(books[i].bookname,name)==0)
			{
				loc=i;
				found = 1;
				cout<< "Record Found!"<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<books[loc].bookid<<setw(50)<<books[loc].bookname<<setw(30)<<books[loc].authorname<<setw(30)<<books[loc].bookcategory<<setw(30)<<books[loc].bookpubcom<<setw(30)<<books[loc].bookpubmonth<<setw(30)<<books[loc].bookpubyear<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			}
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press enter to goto main manu.....";
		getch();
	}

///////Search by author///////

void sbyauthor(void)
	{
		char author[60];
		int loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"Searching by author of book\n";
		cout<<"Enter the author of book you want to search: ";
		gets(author);
		for(int i = 0;i<n;i++)
		{
			if(strcmp(books[i].authorname,author)==0)
			{
				loc=i;
				found = 1;
				cout<< "Record Found!"<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<books[loc].bookid<<setw(50)<<books[loc].bookname<<setw(30)<<books[loc].authorname<<setw(30)<<books[loc].bookcategory<<setw(30)<<books[loc].bookpubcom<<setw(30)<<books[loc].bookpubmonth<<setw(30)<<books[loc].bookpubyear<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			}
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press enter to goto main manu.....";
		getch();
	}

///////Search by id///////

void sbyid(void)
	{
		char ids[6];
		int id, loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"Searching by Id of book\n";
		cout<<"Enter the id of book you want to search: ";
		gets(ids);
		id=atoi(ids);
		for(int i = 0;i<n;i++)
		{
			if(books[i].bookid==id)
			{
				loc=i;
				found = 1;
				cout<< "Record Found!"<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<books[loc].bookid<<setw(50)<<books[loc].bookname<<setw(30)<<books[loc].authorname<<setw(30)<<books[loc].bookcategory<<setw(30)<<books[loc].bookpubcom<<setw(30)<<books[loc].bookpubmonth<<setw(30)<<books[loc].bookpubyear<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			}
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press enter to goto main manu.....";
		getch();
	}

///////Search by category///////

void sbycategory(void)
	{
		char category[60];
		int loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"Searching by category of book\n";
		cout<<"Enter the category of book you want to search: ";
		gets(category);
		for(int i = 0;i<n;i++)
		{
			if(strcmp(books[i].bookcategory,category)==0)
			{
				loc=i;
				found = 1;
				cout<< "Record Found!"<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<books[loc].bookid<<setw(50)<<books[loc].bookname<<setw(30)<<books[loc].authorname<<setw(30)<<books[loc].bookcategory<<setw(30)<<books[loc].bookpubcom<<setw(30)<<books[loc].bookpubmonth<<setw(30)<<books[loc].bookpubyear<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			}
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press enter to goto main manu.....";
		getch();
	}

///////Search by Publication Company///////

void sbypubcom(void)
	{
		char company[60];
		int loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"Searching by publication company of book\n";
		cout<<"Enter the publicaton company of book you want to search: ";
		gets(company);
		for(int i = 0;i<n;i++)
		{
			if(strcmp(books[i].bookpubcom,company)==0)
			{
				loc=i;
				found = 1;
				cout<< "Record Found!"<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<books[loc].bookid<<setw(50)<<books[loc].bookname<<setw(30)<<books[loc].authorname<<setw(30)<<books[loc].bookcategory<<setw(30)<<books[loc].bookpubcom<<setw(30)<<books[loc].bookpubmonth<<setw(30)<<books[loc].bookpubyear<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			}
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press enter to goto main manu.....";
		getch();
	}

///////Search by Publication Year///////

void sbypubyear(void)
	{
		char year[4];
		int yr,loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"Searching by year of publication of book\n";
		cout<<"Enter the year of publication of book you want to search: ";
		gets(year);
		yr=atoi(year);
		for(int i = 0;i<n;i++)
		{
			if(books[i].bookpubyear==yr)
			{
				loc=i;
				found = 1;
				cout<< "Record Found!"<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<books[loc].bookid<<setw(50)<<books[loc].bookname<<setw(30)<<books[loc].authorname<<setw(30)<<books[loc].bookcategory<<setw(30)<<books[loc].bookpubcom<<setw(30)<<books[loc].bookpubmonth<<setw(30)<<books[loc].bookpubyear<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			}
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press enter to goto main manu.....";
		getch();
	}

//////////sort///////////////////////

void sort(void)
{
	system("cls");

	   cout <<setw( 27 )<< "In Sort Function"<<endl
          << setw( 52 )<< "Please choose one of the options below: "

          << endl << setw( 71 )

          << "--------------------------------------------------------------"

          << endl << endl

          << setw( 40 ) << "( A ) Sort in Ascending Order" << endl << endl

          << setw( 41 ) << "( D ) Sort in Descending Order" << endl << endl

          <<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
			gotoxy(30,8);
		//	cin>>ch1;




	   switch(getche())
	  //switch(ch1)
       {
         case 'a':
		 case 'A':sortas();break;

		 case 'd':
		 case 'D': sortds();break;

         default:
		puts("\n\n \t\tSelect only from the given menu.....\n\t\tPress enter to select again.....");
		getch();
		sort();
		getch();
       }
}

///////Sort in Ascending Order///////

void sortas(void)
{
	system("cls");

	   cout <<setw( 27 )<< "In Sort Function"<<endl
          << setw( 52 )<< "Please choose one of the options below: "

          << endl << setw( 71 )

          << "--------------------------------------------------------------"

          << endl << endl

          << setw( 29 ) << "( N ) Sort by name" << endl << endl

          << setw( 27 ) << "( I ) Sort by Id" << endl << endl

          << setw( 36 ) << "( T ) Sort by author name" << endl << endl

          << setw( 33 ) << "( C ) Sort by Category" << endl << endl

          << setw( 44 ) << "( P ) Sort by Publication Company" << endl << endl

          << setw( 41 ) << "( Y ) Sort by Publication Year" << endl << endl

		  <<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
			gotoxy(30,16);
		//	cin>>ch1;




	   switch(getche())
	  //switch(ch1)
       {
         case 'n':
		 case 'N':sortasname();break;

		 case 'i':
		 case 'I': sortasid();break;

		 case 't':
		 case 'T': sortasauthor();break;

		 case 'c':
		 case 'C':sortascategory();break;

		 case 'p':
		 case 'P':sortaspubcom();break;

		 case 'y':
		 case 'Y':sortaspubyear();break;

         default:
		puts("\n\n \t\tSelect only from the given menu.....\n\t\tPress enter to select again.....");
		getch();
		sortas();
		getch();
       }
}

///////Sort in Desending Order///////

void sortds(void)
{
	system("cls");

	   cout <<setw( 27 )<< "In Sort Function"<<endl
          << setw( 52 )<< "Please choose one of the options below: "

          << endl << setw( 71 )

          << "--------------------------------------------------------------"

          << endl << endl

          << setw( 29 ) << "( N ) Sort by name" << endl << endl

          << setw( 27 ) << "( I ) Sort by Id" << endl << endl

          << setw( 36 ) << "( T ) Sort by author name" << endl << endl

          << setw( 33 ) << "( C ) Sort by Category" << endl << endl

          << setw( 44 ) << "( P ) Sort by Publication Company" << endl << endl

          << setw( 41 ) << "( Y ) Sort by Publication Year" << endl << endl

		  <<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
			gotoxy(30,16);
		//	cin>>ch1;




	   switch(getche())
	  //switch(ch1)
       {
         case 'n':
		 case 'N':sortdsname();break;

		 case 'i':
		 case 'I': sortdsid();break;

		 case 't':
		 case 'T': sortdsauthor();break;

		 case 'c':
		 case 'C':sortdscategory();break;

		 case 'p':
		 case 'P':sortdspubcom();break;

		 case 'y':
		 case 'Y':sortdspubyear();break;

         default:
		puts("\n\n \t\tSelect only from the given menu.....\n\t\tPress enter to select again.....");
		getch();
		sortds();
		getch();
       }
}

///////Sort in Ascending order by id///////

void sortasid(void)
	{
		int i,j;
		book temp;
		system("cls");
		cout<<endl;
		cout<< "Sorting in Ascending Order by Id\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(books[j].bookid>books[j+1].bookid)
				{
					temp = books[j];
					books[j]=books[j+1];
					books[j+1]=temp;
				}
			}
		}
		display();
	}

///////Sort in Descending order by id///////

void sortdsid(void)
	{
		int i,j;
		book temp;
		system("cls");
		cout<<endl;
		cout<< "Sorting in Descending Order by Id\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(books[j].bookid<books[j+1].bookid)
				{
					temp = books[j];
					books[j]=books[j+1];
					books[j+1]=temp;
				}
			}
		}
		display();
	}

///////Sort in Ascending order by year///////

void sortaspubyear(void)
	{
		int i,j;
		book temp;
		system("cls");
		cout<<endl;
		cout<< "Sorting in Ascending Order by Publishing Year\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(books[j].bookpubyear>books[j+1].bookpubyear)
				{
					temp = books[j];
					books[j]=books[j+1];
					books[j+1]=temp;
				}
			}
		}
		display();
	}

///////Sort in Descending order by year///////

void sortdspubyear(void)
	{
		int i,j;
		book temp;
		system("cls");
		cout<<endl;
		cout<< "Sorting in Descending Order by Publishing Year\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(books[j].bookpubyear<books[j+1].bookpubyear)
				{
					temp = books[j];
					books[j]=books[j+1];
					books[j+1]=temp;
				}
			}
		}
		display();
	}

///////Sort in Ascending order by name///////

void sortasname(void)
	{
		int i,j;
		book temp;
		system("cls");
		cout<<endl;
		cout<< "Sorting in Ascending Order by Name\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(strcmp(books[j].bookname,books[j+1].bookname)>0)
				{
					temp = books[j];
					books[j]=books[j+1];
					books[j+1]=temp;
				}
			}
		}
		display();
	}

///////Sort in Descending order by name///////

void sortdsname(void)
	{
		int i,j;
		book temp;
		system("cls");
		cout<<endl;
		cout<< "Sorting in Descending Order by Name\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(strcmp(books[j].bookname,books[j+1].bookname)<0)
				{
					temp = books[j];
					books[j]=books[j+1];
					books[j+1]=temp;
				}
			}
		}
		display();
	}

///////Sort in Ascending order by author///////

void sortasauthor(void)
	{
		int i,j;
		book temp;
		system("cls");
		cout<<endl;
		cout<< "Sorting in Ascending Order by Author\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(strcmp(books[j].authorname,books[j+1].authorname)>0)
				{
					temp = books[j];
					books[j]=books[j+1];
					books[j+1]=temp;
				}
			}
		}
		display();
	}

///////Sort in Descending order by author///////

void sortdsauthor(void)
	{
		int i,j;
		book temp;
		system("cls");
		cout<<endl;
		cout<< "Sorting in Descending Order by Author\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(strcmp(books[j].authorname,books[j+1].authorname)<0)
				{
					temp = books[j];
					books[j]=books[j+1];
					books[j+1]=temp;
				}
			}
		}
		display();
	}

///////Sort in Ascending order by category///////

void sortascategory(void)
	{
		int i,j;
		book temp;
		system("cls");
		cout<<endl;
		cout<< "Sorting in Ascending Order by Category\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(strcmp(books[j].bookcategory,books[j+1].bookcategory)>0)
				{
					temp = books[j];
					books[j]=books[j+1];
					books[j+1]=temp;
				}
			}
		}
		display();
	}

///////Sort in Descending order by category///////

void sortdscategory(void)
	{
		int i,j;
		book temp;
		system("cls");
		cout<<endl;
		cout<< "Sorting in Descending Order by Category\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(strcmp(books[j].bookcategory,books[j+1].bookcategory)<0)
				{
					temp = books[j];
					books[j]=books[j+1];
					books[j+1]=temp;
				}
			}
		}
		display();
	}

///////Sort in Ascending order by company///////

void sortaspubcom(void)
	{
		int i,j;
		book temp;
		system("cls");
		cout<<endl;
		cout<< "Sorting in Ascending Order by Publication Company\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(strcmp(books[j].bookpubcom,books[j+1].bookpubcom)>0)
				{
					temp = books[j];
					books[j]=books[j+1];
					books[j+1]=temp;
				}
			}
		}
		display();
	}

///////Sort in Descending order by company///////

void sortdspubcom(void)
	{
		int i,j;
		book temp;
		system("cls");
		cout<<endl;
		cout<< "Sorting in Descending Order by Publication Company\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(strcmp(books[j].bookpubcom,books[j+1].bookpubcom)<0)
				{
					temp = books[j];
					books[j]=books[j+1];
					books[j+1]=temp;
				}
			}
		}
		display();
	}

////////////Delete//////////////////////
void del(void)
	{
		system("cls");

	   cout <<setw( 29 )<< "In Delete Function"<<endl
          << setw( 52 )<< "Please choose one of the options below: "

          << endl << setw( 71 )

          << "--------------------------------------------------------------"

          << endl << endl

          << setw( 31 ) << "( N ) Delete by name" << endl << endl

          << setw( 29 ) << "( I ) Delete by Id" << endl << endl

          << setw( 38 ) << "( T ) Delete by author name" << endl << endl

          << setw( 35 ) << "( C ) Delete by Category" << endl << endl

          << setw( 46 ) << "( P ) Delete by Publication Company" << endl << endl

          << setw( 43 ) << "( Y ) Delete by Publication Year" << endl << endl

		  <<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
			gotoxy(30,16);
		//	cin>>ch1;




	   switch(getche())
	  //switch(ch1)
       {
         case 'n':
		 case 'N':dbyname();break;

		 case 'i':
		 case 'I': dbyid();break;

		 case 't':
		 case 'T': dbyauthor();break;

		 case 'c':
		 case 'C':dbycategory();break;

		 case 'p':
		 case 'P':dbypubcom();break;

		 case 'y':
		 case 'Y':dbypubyear();break;

         default:
		puts("\n\n \t\tSelect only from the given menu.....\n\t\tPress enter to select again.....");
		getch();
		del();
		getch();
       }
	}

///////Delete by name///////

void dbyname(void)
	{
		char name[60];
		int loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"Deleting by name of book\n";
		cout<<"Enter the name of book you want to delete: ";
		gets(name);
		for(int i = 0;i<n;i++)
		{
			if(strcmp(books[i].bookname,name)==0)
			{
				loc=i;
				found = 1;
				for (i = loc;i<n-1;i++)
				{
					books[i]=books[i+1];
				}
				n--;
			}
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press enter to goto main manu.....";
		getch();
	}

///////Delete by author///////

void dbyauthor(void)
	{
		char author[60];
		int loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"Deleting by author of book\n";
		cout<<"Enter the author of book you want to delete: ";
		gets(author);
		for(int i = 0;i<n;i++)
		{
			if(strcmp(books[i].authorname,author)==0)
			{
				loc=i;
				found = 1;
				for (i = loc;i<n-1;i++)
				{
					books[i]=books[i+1];
				}
				n--;
			}
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press enter to goto main manu.....";
		getch();
	}

///////Delete by id///////

void dbyid(void)
	{
		char ids[6];
		int id, loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"Deleting by Id of book\n";
		cout<<"Enter the id of book you want to delete: ";
		gets(ids);
		id=atoi(ids);
		for(int i = 0;i<n;i++)
		{
			if(books[i].bookid==id)
			{
				loc=i;
				found = 1;
				for (i = loc;i<n-1;i++)
				{
					books[i]=books[i+1];
				}
				n--;
			}
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press enter to goto main manu.....";
		getch();
	}

///////Delete by category///////

void dbycategory(void)
	{
		char category[60];
		int loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"Deleting by category of book\n";
		cout<<"Enter the category of book you want to delete: ";
		gets(category);
		for(int i = 0;i<n;i++)
		{
			if(strcmp(books[i].bookcategory,category)==0)
			{
				loc=i;
				found = 1;
				for (i = loc;i<n-1;i++)
				{
					books[i]=books[i+1];
				}
				n--;
			}
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press enter to goto main manu.....";
		getch();
	}

///////Delete by company///////

void dbypubcom(void)
	{
		char company[60];
		int loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"Deleting by publication company of book\n";
		cout<<"Enter the publicaton company of book you want to delete: ";
		gets(company);
		for(int i = 0;i<n;i++)
		{
			if(strcmp(books[i].bookpubcom,company)==0)
			{
				loc=i;
				found = 1;
				for (i = loc;i<n-1;i++)
				{
					books[i]=books[i+1];
				}
				n--;
			}
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press enter to goto main manu.....";
		getch();
	}

///////Delete by year///////

void dbypubyear(void)
	{
		char year[4];
		int yr,loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"Deleting by year of publication of book\n";
		cout<<"Enter the year of publication of book you want to delete: ";
		gets(year);
		yr=atoi(year);
		for(int i = 0;i<n;i++)
		{
			if(books[i].bookpubyear==yr)
			{
				loc=i;
				found = 1;
				for (i = loc;i<n-1;i++)
				{
					books[i]=books[i+1];
				}
				n--;
			}
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press enter to goto main manu.....";
		getch();
	}
///////////Modify//////////////////////
void modify(void)
	{
		system("cls");

	   cout <<setw( 29 )<< "In Modify Function"<<endl
          << setw( 52 )<< "Please choose one of the options below: "

          << endl << setw( 71 )

          << "--------------------------------------------------------------"

          << endl << endl

          << setw( 31 ) << "( N ) Modify by name" << endl << endl

          << setw( 29 ) << "( I ) Modify by Id" << endl << endl

          << setw( 38 ) << "( T ) Modify by author name" << endl << endl

          << setw( 35 ) << "( C ) Modify by Category" << endl << endl

          << setw( 46 ) << "( P ) Modify by Publication Company" << endl << endl

          << setw( 43 ) << "( Y ) Modify by Publication Year" << endl << endl

		  <<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
			gotoxy(30,16);
		//	cin>>ch1;




	   switch(getche())
	  //switch(ch1)
       {
         case 'n':
		 case 'N':mbyname();break;

		 case 'i':
		 case 'I': mbyid();break;

		 case 't':
		 case 'T': mbyauthor();break;

		 case 'c':
		 case 'C': mbycategory();break;

		 case 'p':
		 case 'P': mbypubcom();break;

		 case 'y':
		 case 'Y': mbypubyear();break;

         default:
		puts("\n\n \t\tSelect only from the given menu.....\n\t\tPress enter to select again.....");
		getch();
		modify();
		getch();
       }
	}

///////Modify by name///////

void mbyname(void)
	{
		char name[60];
		int loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"Modifying by name of book\n";
		cout<<"Enter the name of book you want to modify: ";
		gets(name);
		for(int i = 0;i<n;i++)
		{
			if(strcmp(books[i].bookname,name)==0)
			{
				loc=i;
				found = 1;
				char ch;char id1[6],year[4];
				system("cls");
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<books[loc].bookid<<setw(50)<<books[loc].bookname<<setw(30)<<books[loc].authorname<<setw(30)<<books[loc].bookcategory<<setw(30)<<books[loc].bookpubcom<<setw(30)<<books[loc].bookpubmonth<<setw(30)<<books[loc].bookpubyear<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<endl;
				cout<< "In Modify function\n";
				cout<<"Enter new Book Name: ";
				gets(books[loc].bookname);
				//cin.getline(emp[n].name,40);
				//cin.ignore(40,'\n');
				cout<<"MODIFIED!"<<endl;
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press enter to goto main manu.....";
		getch();
		}
	}

///////Modify by author///////

void mbyauthor(void)
	{
		char author[60];
		int loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"Modifying by author of book\n";
		cout<<"Enter the author of book you want to modify: ";
		gets(author);
		for(int i = 0;i<n;i++)
		{
			if(strcmp(books[i].authorname,author)==0)
			{
				loc=i;
				found = 1;
				char ch;char id1[6],year[4];
				system("cls");
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<books[loc].bookid<<setw(50)<<books[loc].bookname<<setw(30)<<books[loc].authorname<<setw(30)<<books[loc].bookcategory<<setw(30)<<books[loc].bookpubcom<<setw(30)<<books[loc].bookpubmonth<<setw(30)<<books[loc].bookpubyear<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<endl;
				cout<< "In Modify function\n";
				cout<<"Enter new Author Name: ";
				gets(books[loc].authorname);
				cout<<"MODIFIED!"<<endl;
			}
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press enter to goto main manu.....";
		getch();
	}

///////Modify by id///////

void mbyid(void)
	{
		char ids[6];
		int id, loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"Modifying by Id of book\n";
		cout<<"Enter the id of book you want to modify: ";
		gets(ids);
		id=atoi(ids);
		for(int i = 0;i<n;i++)
		{
			if(books[i].bookid==id)
			{
				loc=i;
				found = 1;
				char ch;char id1[6],year[4];
				system("cls");
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<books[loc].bookid<<setw(50)<<books[loc].bookname<<setw(30)<<books[loc].authorname<<setw(30)<<books[loc].bookcategory<<setw(30)<<books[loc].bookpubcom<<setw(30)<<books[loc].bookpubmonth<<setw(30)<<books[loc].bookpubyear<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<endl;
				cout<< "In Modify function\n";
				cout<<"Enter new Book ID: ";
				gets(id1);
				books[loc].bookid=atoi(id1);
				//cin.ignore();
				cout<<"MODIFIED!"<<endl;
			}
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press enter to goto main manu.....";
		getch();
	}

///////Modify by category///////

void mbycategory(void)
	{
		char category[60];
		int loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"Modifying by category of book\n";
		cout<<"Enter the category of book you want to modify: ";
		gets(category);
		for(int i = 0;i<n;i++)
		{
			if(strcmp(books[i].bookcategory,category)==0)
			{
				loc=i;
				found = 1;
				char ch;char id1[6],year[4];
				system("cls");
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<books[loc].bookid<<setw(50)<<books[loc].bookname<<setw(30)<<books[loc].authorname<<setw(30)<<books[loc].bookcategory<<setw(30)<<books[loc].bookpubcom<<setw(30)<<books[loc].bookpubmonth<<setw(30)<<books[loc].bookpubyear<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<endl;
				cout<< "In Modify function\n";
				cout<<"Enter new Book Category: ";
				gets(books[loc].bookcategory);
				cout<<"MODIFIED!"<<endl;
			}
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press enter to goto main manu.....";
		getch();
	}

///////Modify by company///////

void mbypubcom(void)
	{
		char company[60];
		int loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"Modifying by publication company of book\n";
		cout<<"Enter the publicaton company of book you want to modify: ";
		gets(company);
		for(int i = 0;i<n;i++)
		{
			if(strcmp(books[i].bookpubcom,company)==0)
			{
				loc=i;
				found = 1;
				char ch;char id1[6],year[4];
				system("cls");
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<books[loc].bookid<<setw(50)<<books[loc].bookname<<setw(30)<<books[loc].authorname<<setw(30)<<books[loc].bookcategory<<setw(30)<<books[loc].bookpubcom<<setw(30)<<books[loc].bookpubmonth<<setw(30)<<books[loc].bookpubyear<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<endl;
				cout<< "In Modify function\n";
				cout<<"Enter new Publication Company Name: ";
				gets(books[loc].bookpubcom);
				cout<<"MODIFIED!"<<endl;
			}
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press enter to goto main manu.....";
		getch();
	}

///////Modify by year///////

void mbypubyear(void)
	{
		char year[4];
		int yr,loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"Modifying by year of publication of book\n";
		cout<<"Enter the year of publication of book you want to modify: ";
		gets(year);
		yr=atoi(year);
		for(int i = 0;i<n;i++)
		{
			if(books[i].bookpubyear==yr)
			{
				loc=i;
				found = 1;
				char ch;char id1[6],year[4];
				system("cls");
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<books[loc].bookid<<setw(50)<<books[loc].bookname<<setw(30)<<books[loc].authorname<<setw(30)<<books[loc].bookcategory<<setw(30)<<books[loc].bookpubcom<<setw(30)<<books[loc].bookpubmonth<<setw(30)<<books[loc].bookpubyear<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<endl;
				cout<< "In Modify function\n";
				cout<<"Enter new Publication Year: ";
				gets(year);
				books[loc].bookpubyear=atoi(year);
				cout<<"MODIFIED!"<<endl;
			}
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press enter to goto main manu.....";
		getch();
	}

////////////////////////////////////////
/////////////////gotoxy //////////////////////////
void gotoxy(short x, short y)
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
