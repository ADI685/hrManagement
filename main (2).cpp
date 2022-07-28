#include<bits/stdc++.h>
#include<stdlib.h>
#include<conio.h>
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
//#define fo(i,n) for(i=0 ;i<n; i++)

class DEPTInfo
{
protected:
int dept_id;
string dept_name;
string dept_loc;

public:
void insert();
 void operations();
void modify();

 void display();
 void search();
 void Delete();

};

void intro()
	{

		system("cls");
		cout<<"\n\n Introduction";
		cout<<"\n\n";
		cout<<"\n Name :    Aditya ";
		cout<<"\n Branch :	BTECH (ECE)";
		cout<<"\n Roll No. :	19104004";
		cout<<"\n Teacher :	Mr. RAJNISH RAANI";
		cout<<"\n Institute :	NIT JALANDHAR";
		getch();

	}
void DEPTInfo::operations()
{
    system("cls");
    int x;
        //cout<<"\n\n\t\t\tHUMAN RESOURCE MANAGEMENT SYSTEM";
        cout<<"\n\n\n      1. Insert Record";
		cout<<"\n\n      2. Display Record";
		cout<<"\n\n      3. Search Record";
		cout<<"\n\n      4. Modify Record";
		cout<<"\n\n      5. Delete Record";
		cout<<"\n\n      6. Exit";
		cout<<"\n\n     ENTER YOUR CHOICE: ";
		cin>>x;
		switch(x)
		{
        case 1:

   insert();break;
        case 2:
display();break;
      case 3:
search();break;
  /*   case 4:modify();
	break;*/

    case 5:Delete();
break;

case 6:
			exit(0);
        default:
				cout<<"\n\n Its a invalid Choice...Please try after sometime :-{\n";
		}
		getch();

    }

void DEPTInfo::insert()
	{
		system("cls");
		int test_id,found=0;
		ofstream file;

		cout<<"\n\t\t\t\t\t Insert Record";
		cout<<"\n Department ID : ";
		cin>>dept_id;
		cout<<"\n Department Name : ";
		cin>>dept_name;

		cout<<"\n  Department location : ";
		fflush(stdin);
		cin>>dept_loc;

        file.open("dept.txt",ios::out|ios::app);

		file<<" "<<dept_id<<" "<<dept_name<<" "<<dept_loc<<"\n";
		file.close();

		cout<<"\n\n     New Record Inserted Successfully :=)";
		getch();
operations();
	}

void DEPTInfo::display()
	{

	system("CLS");
		fstream file;

		cout<<"\n\n\t\t\t\tDisplay Record\n\n";
		file.open("dept.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Opening Error ;-(";
			getch();
           operations();
		}
		file>>dept_id>>dept_name>>dept_loc;
		while(!file.eof())
		{
			cout<<"\n DEPARTMENT ID : "<<dept_id;
            cout<<"\n DEPARTMENT NAME : "<<dept_name;
            cout<<"\n DEPARTMENT LOCATION : "<<dept_loc;
            cout<<"\n\n\n";
       file>>dept_id>>dept_name>>dept_loc;

		}
		file.close();
	}

	void DEPTInfo::search()
	{
		system("cls");
		fstream file;
		int dept_idd;
		int found=0;
		cout<<"\nSearch Record";

		file.open("dept.txt",ios::in);
		if(!file)
		{
			cout<<"\n opening Error...";

		getch();
		operations();
		}

		cout<<"\n\nDepartment ID For Search : ";
        cin>>dept_idd;
		file>>dept_id>>dept_name>>dept_loc;

		while(!file.eof())
		{
			if(dept_id==dept_idd)
			{
			system("cls");
			cout<<"\n\n\t\tSearch Record";
			cout<<"\n Department ID : "<<dept_id;
			cout<<"\n Department Name : "<<dept_name;
			cout<<"\n Department location: "<<dept_loc;
			found++;
			}
		file>>dept_id>>dept_name>>dept_loc;
		}
		file.close();
		if(found == 0)
		cout<<"\n\n Department ID Can't Found :~( ";
      getch();
      operations();
	}

	void DEPTInfo::modify()
	{
		system("cls");
		int test_id;
		string dept_loc2;
		int found=0;


		fstream file,file3;

		cout<<"\n\n\t\tModify Record";

		file.open("dept.txt",ios::in);


		if(!file )
		{
			cout<<"\n\n File Opening Error :-[ ";
			getch();
        operations();
		}
		cout<<"\n\n Department ID For Modify : ";
		cin>>test_id;
		file3.open("dept1.txt",ios::app|ios::out);

	file>>dept_id>>dept_name>>dept_loc;
		while(!file.eof())
		{
			if(test_id == dept_id)
			{
				system("cls");
				cout<<"\n\n\t\t\t\tModify Record";

				cout<<"\n\n Department Location : ";
				cin>>dept_loc2;
				file3<<" "<<dept_id<<" "<<dept_name<<" "<<dept_loc2<<"\n";
				found++;
			}
			else
			{
            file3<<" "<<dept_id<<" "<<dept_name<<dept_loc<<"\n";
			}
          file>>dept_id>>dept_name>>dept_loc;
		}
		file.close();
		file3.close();

		remove("dept.txt");

		rename("dept1.txt","dept.txt");

		if(found == 0)
		cout<<"\n\n Department ID Can't Found ;-( ";
		else
		cout<<"\n\n\t\t\t Record Modify Successfully :-) ";
	}
	void DEPTInfo::Delete()
	{
		system("cls");//to clear the screen
		int test_id;
		int found=0;
		fstream file,file2;
		cout<<"\n\n\t\t\t\tDelete Record";
		file.open("dept.txt",ios::in);

		if(!file)
		{
			cout<<"\n\n File Opening Error...";
			getch();
		operations();
		}
		cout<<"\n\n Department ID For Delete : ";
		cin>>test_id;
		file2.open("dept1.txt",ios::app|ios::out);  //appending and writing
	file>>dept_id>>dept_name>>dept_loc;
		while(!file.eof())
		{
			if(test_id == dept_id)
			{
				cout<<"\n\n Record Deleted Successfully ;-)";
				found++;
			}
			else
			{
				file2<<" "<<dept_id<<" "<<dept_name<<" "<<dept_loc<<"\n";
			}
		file>>dept_id>>dept_name>>dept_loc;
		}
		file.close();
		file2.close();
		remove("dept.txt");
		rename("dept1.txt","dept.txt");
		if(found == 0)
		cout<<"\n\n\t\t\t Department ID Can't Found ;(";
	}

main()
{

DEPTInfo d;
 intro();
  d.operations();
}
