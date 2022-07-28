#include<bits/stdc++.h>
#include<conio.h>
#include <windows.h>
#include<string.h>
using namespace std;
#define ll long long
#define mod 1000000007

void changeColor(int desiredColor){
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

void init_code()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
class EMPLOYEE
{
private:
	ll salary ;
	string address;
	char sex;
	string fname;
	string lname;
	string mname;
	ll ssn;

public:
	EMPLOYEE()
	{
		salary = 0;
		address = " ";
		sex = ' ';
		fname = " ";
		mname = " ";
		lname = " ";
		ssn = 0;

	}
	void getdata()
	{
		cout<<"\n\nCreating Employee Record"<<endl;
		cout << "Enter SSN: " ;
		cin >> ssn;
		cout << "Enter fname: ";
		cin >> fname;
		cout << "Enter mname: ";
		cin >> mname;
		cout << "Enter lname: ";
		cin >> lname;
		cout << "Enter Salary(in Rs.): " ;
		cin >> salary;
		cout << "Enter Sex: ";
		cin >> sex;
		cout << "Enter Address: ";
		cin >> address;
		cout << endl;
	}
	void showdata()
	{
        cout << ssn << "\t\t" <<fname << "\t" << mname << "\t" << lname << "\t  " << sex << "\t" << salary <<"\t\t" <<address << endl;
	}
	void storedata()
	{
		if (ssn == 0 )
		{
			cout << "Enter valid data" << endl;
			return ;
		}
		ofstream fout;
		fout.open("file1.dat", ios::app | ios::binary);
		fout.write((char*)this, sizeof(*this));
		fout.close();
		cout<<"\t\tThe record has been stored"<<endl;
		cout<<"Press Enter"<<endl;
	}
	void showalldata()
	{
	    ifstream fin;
		fin.open("file1.dat", ios::in | ios::binary);
		if (!fin){
			cout << "::File not found:: Press any Key to exit" << endl;
			cin.ignore();
            cin.get();
            return;
		}
		else
		{
			fin.read((char*)this, sizeof(*this));
			while (!fin.eof())
			{
				showdata();
				fin.read((char*)this, sizeof(*this));
			}
			fin.close();
		}
		cout<<"\nPress Enter"<<endl;
		getch();
	}
	void searchdata(ll temp_ssn)
	{
		ifstream fin;
		fin.open("file1.dat", ios::in | ios::binary);
		if (!fin){
			cout << "::File not found::" << endl;
			cout<<"Press Enter"<<endl;
            cin.get();
            return;
		}
		else
		{
			int flag = 0;
			fin.read((char*)this, sizeof(*this));
			while (!fin.eof())
			{
				if (temp_ssn == ssn){
                    cout<<"The searched entry is as follow"<<endl;
					showdata();
				}
				fin.read((char*)this, sizeof(*this));

			}
			fin.close();
		}
		cout<<"Press Enter"<<endl;
		getch();

	}
	void deletedata(ll temp_ssn)
	{
		ifstream fin;
		ofstream fout;
		fin.open("file1.dat", ios::in | ios::binary);
		if (!fin)
			cout << "::File doesn't exist::" << endl;
		else
		{
			fout.open("temp_file1.dat", ios::out | ios::binary);
			fin.read((char*)this, sizeof(*this));

            int count = 0;
			while (!fin.eof())
			{
				if (temp_ssn != ssn)
				{
					fout.write((char*)this, sizeof(*this));
				}
                else
                    count++;
				fin.read((char*)this, sizeof(*this));
			}
            if(count == 0)
				cout << "There is no existing Employee with SSN No: " << temp_ssn << endl;
			else
				cout << "Employee with SSN No: " << temp_ssn << " has been deleted" << endl;

			fin.close();
			fout.close();
			remove("file1.dat");
			rename("temp_file1.dat", "file1.dat");
		}
		cout<<"Press Enter"<<endl;
		getch();
	}
	void updatedata(ll temp_ssn)
	{
		fstream file;
		file.open("file1.dat", ios::in | ios::out | ios::ate | ios::binary);
		file.seekg(0);
		if (!file)
			{
			    cout << "::File doesn't exist::" << endl;
			    cout<<"Press Enter"<<endl;
                cin.get();
                return;
			}
		else
		{
            int c=0;
			file.read((char*)this, sizeof(*this));
			while (!file.eof())
			{
				if (temp_ssn == ssn)
				{
					getdata();
					file.seekg(file.tellg() - (ll)sizeof(*this));
					file.write((char*)this, sizeof(*this));
					c++;
                    cout<<"\nThe record for SSN: "<< temp_ssn<<" has been updated"<<endl;
				}
				file.read((char*)this, sizeof(*this));
			}
			file.close();
			if(c == 0)
                cout<<"No such record found"<<endl;
		}
		cout<<"Press Enter"<<endl;
		getch();
	}

};

class PROJECT
{
private:
	int PROJ_NO ;
	string location;
	string proj_name;
public:
	PROJECT()
	{
		PROJ_NO = 0;
		location = " ";
		proj_name = " ";
	}
	void getdata()
	{
		cout << "\nEnter Project No." << endl;
		cin >> PROJ_NO;

		cout << "Enter Project name" << endl;
		cin >> proj_name;

        cout << "Enter location" << endl;
		cin>>location;
	}
    void showdata()
	{
		cout << proj_name << "\t\t\t" << PROJ_NO << "\t\t\t" << location << endl ;
	}
	void storedata()
	{
		if (PROJ_NO == 0 )
		{
			cout << "Enter valid data" << endl;
			return ;
		}
		ofstream fout;
		fout.open("file2.dat", ios::app | ios::binary);
		fout.write((char*)this, sizeof(*this));
		fout.close();
	}
	void showalldata()
	{
		ifstream fin;
		fin.open("file2.dat", ios::in | ios::binary);
		if (!fin)
			cout << "There are no data entries in the table" << endl;
		else
		{
			fin.read((char*)this, sizeof(*this));
			while (!fin.eof())
			{
				showdata();
				fin.read((char*)this, sizeof(*this));

			}
			fin.close();
		}


	}
    void searchdata(int tempPROJ_NO)
	{
		ifstream fin;
		fin.open("file2.dat", ios::in | ios::binary);
		if (!fin)
			cout << "file not found" << endl;
		else
		{
			cout << "\nThe data entry that you searched for, is as follows" << endl;
			int flag = 0;
			fin.read((char*)this, sizeof(*this));
			while (!fin.eof())
			{
				if (tempPROJ_NO == PROJ_NO)
					showdata();
				fin.read((char*)this, sizeof(*this));

			}
			fin.close();
		}
	}
    void deletedata(int tempPROJ_NO)
	{
		ifstream fin;
		ofstream fout;
		fin.open("file2.dat", ios::in | ios::binary);
		if (!fin)
			cout << "File doesnt exist" << endl;
		else
		{
			fout.open("temp_file2.dat", ios::out | ios::binary);
			fin.read((char*)this, sizeof(*this));

			int count = 0;
			while (!fin.eof())
			{
				if (tempPROJ_NO != PROJ_NO)
				{
					fout.write((char*)this, sizeof(*this));
				}
				else{
					count++;
				}
				fin.read((char*)this, sizeof(*this));

			}

			// Just to let the user know, whether the Project has been deleted or not
			if(count == 0)
				cout << "\nThere is no existing project with Project No. " << tempPROJ_NO << endl;
			else
				cout << "\nProject No. " << tempPROJ_NO << " has been deleted" << endl;

			fin.close();
			fout.close();
			remove("file2.dat");
			rename("temp_file2.dat", "file2.dat"); // "file2.dat" contains the updated table

		}
	}
	void updatedata(ll tempPROJ_NO)
    {
        fstream file;
        file.open("file2.dat", ios::in | ios::out | ios::ate);
        file.seekg(0);
        if (!file)
            cout << "\nFile doesnt exist" << endl;
        else
        {

            file.read((char *)this, sizeof(*this));
            while (!file.eof())
            {
                if (tempPROJ_NO == PROJ_NO)
                {
                    getdata();
                    file.seekg(file.tellg() - (ll)sizeof(*this));
                    file.write((char *)this, sizeof(*this));
                }
                file.read((char *)this, sizeof(*this));
            }
            file.close();
        }
    }
};

class DEPTInfo
{
protected:
    int dept_id;
    string dept_name;
    string dept_loc;
public:
    void insert()
    {
            int test_id,found=0;
            ofstream file;

            cout<<"\n\t\t Inserting Record";
            cout<<"\n Department ID : ";
            cin>>dept_id;
            cout<<"Department Name : ";
            cin>>dept_name;

            cout<<"Department location : ";
            fflush(stdin);
            cin>>dept_loc;

            file.open("dept.txt",ios::out|ios::app);

            file<<" "<<dept_id<<" "<<dept_name<<" "<<dept_loc<<"\n";
            file.close();

            cout<<"\n\n   New Record Inserted Successfully.";
            getch();
    }
    void modify()
     {
        int test_id,dept_id2;
		string dept_loc2,dept_name2;
		int found=0;
		fstream file,file3;
		cout<<"\n\t\tModify Record";
		file.open("dept.txt",ios::in);

		if(!file )
		{
			cout<<"\n\n File Opening Error.";
			getch();
            return;
		}
		cout<<"\n\n Department ID to Modify : ";
		cin>>test_id;
		file3.open("dept1.txt",ios::app|ios::out);

        file>>dept_id>>dept_name>>dept_loc;
		while(!file.eof())
		{
			if(test_id == dept_id)
			{
				cout<<"\n\n\t\t\t\tModify Record";
				cout<<"\nNew Department Id : ";
				cin>>dept_id2;
                cout<<"New Department Name : ";
				cin>>dept_name2;
				cout<<"New Department Location : ";
				cin>>dept_loc2;
				file3<<" "<<dept_id2<<" "<<dept_name2<<" "<<dept_loc2<<"\n";
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
            cout<<"\n\n Department ID Can't Found. ";
		else
            cout<<"\n\t\t Record Modified Successfully. ";
     }
    void display()
     {
            fstream file;

            cout<<"\n\n\t\t\t\tDisplay Record\n\n";
            file.open("dept.txt",ios::in);
            if(!file)
            {
                cout<<"\n\n File Opening Error.";
                getch();
                return;
            }
            file>>dept_id>>dept_name>>dept_loc;
            cout<<"DEPARTMENT ID\t\tDEPARTMENT NAME\t\tDEPARTMENT LOCATION"<<endl;
            cout<<"-------------\t\t---------------\t\t--------------------"<<endl;
            while(!file.eof())
            {
                cout<<dept_id<<"\t\t\t"<<dept_name<<"\t\t\t"<<dept_loc<<endl;
//                cout<<"\n DEPARTMENT NAME : "<<dept_name;
//                cout<<"\n DEPARTMENT LOCATION : "<<dept_loc;
//                cout<<"\n\n\n";
           file>>dept_id>>dept_name>>dept_loc;
            }
            file.close();
            cout<<endl;
     }
    void search()
     {
        fstream file;
            int dept_idd;
            int found=0;
            cout<<"\nSearch Record";

            file.open("dept.txt",ios::in);
            if(!file)
            {
                cout<<"\n opening Error...";
                getch();
                return;
            }

            cout<<"\n\nDepartment ID For Search: ";
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
            cout<<"\n\n Department ID Can't Found.";
          getch();
     }
    void Delete()
     {
        int test_id;
		int found=0;
		fstream file,file2;
		cout<<"\n\n\t\t\t\tDelete Record";
		file.open("dept.txt",ios::in);

		if(!file)
		{
			cout<<"\n\n File Opening Error...";
			getch();
			return;
		}
		cout<<"\n\n Department ID For Delete : ";
		cin>>test_id;
		file2.open("dept1.txt",ios::app|ios::out);  //appending and writing
        file>>dept_id>>dept_name>>dept_loc;
		while(!file.eof())
		{
			if(test_id == dept_id)
			{
				cout<<"\n\n Record Deleted Successfully";
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
		cout<<"\n\n\t\t\t Department ID Can't Found"<<endl;
     }
};


void intro()
{
    changeColor(12);
    cout<<"\t\t\t\tHUMAN RESOURCE MANAGMENT SYSTEM";
    cout<<"\n\n\t\tMADE BY STUDENTS OF ECE: \n";
    changeColor(6);
    cout<<"\t\t\tROLL NO.\tNAME"<<endl;
    cout<<"\t\t\t---------\t---------------------"<<endl;
    changeColor(14);

    cout<<"\t\t\t19104004\tAditya Ashish Yadav\n";
    cout<<"\t\t\t19104014\tAtharv Limaye\n";
    cout<<"\t\t\t19104024\tDeepesh Singh\n";
    cout<<"\t\t\t19104034\tHarsh Kriplani\n";
    cout<<"\t\t\t19104044\tKartike Sood\n";
    cout<<"\t\t\t19104054\tNaveen Singh\n";
    cout<<"\t\t\t19104064\tParth Sachaan\n";
    cout<<"\t\t\t19104074\tRahul Sharma\n";
    cout<<"\t\t\t19104084\tSanchit Goyal\n";
    cout<<"\t\t\t19104094\tShalini\n";
    cout<<"\t\t\t19104104\tSourav Goyal\n";
    cout<<"\t\t\t19104114\tVanshika Sahotra\n\n";

    cout<<"\t\t\tPLEASE PRESS ANY KEY   ";
    getch();
}

void department_menu(){
    DEPTInfo d;
    system("cls");
    char ch;
    do
    {
        changeColor(112);
        cout<<"\n\tDEPARTMENT MENU";
        cout<<"\n\n\t1. Insert Record";
        cout<<"\n\t2. Display Record";
        cout<<"\n\t3. Search Record";
        cout<<"\n\t4. Modify Record";
        cout<<"\n\t5. Delete Record";
        cout<<"\n\t6. Go To Main Menu";
        cout<<"\n\n\tPlease Select Your Option (1-6):   ";
        ch=getche();
        ll n;
        switch(ch){
            case '1':
                d.insert();
                break;
            case '2':
                d.display();break;
            case '3':
               d.search();
               break;
            case '4':
                d.modify();
                break;
            case '5':
                d.Delete();
                break;
            case '6':return;
            default :cout<<"\a";
        }
        }while(ch!='6');
}

void project_menu(){
    PROJECT P;
    system("cls");
    char ch;
    do
    {
        changeColor(112);
        cout<<"\n\tPOJECT MENU";
        cout<<"\n\n\t1.CREATE PROJECT RECORD";
        cout<<"\n\t2.DISPLAY ALL PROJECT RECORDS";
        cout<<"\n\t3.DISPLAY SPECIFIC PROJECT RECORD";
        cout<<"\n\t4.MODIFY PROJECT RECORD";
        cout<<"\n\t5.DELETE PROJECT RECORD";
        cout<<"\n\t6.GO TO MAIN MENU";
        cout<<"\n\n\tPlease Select Your Option (1-6):   ";
        ch=getche();
        ll n;
        switch(ch){
            case '1':
                P.getdata();
                P.storedata();
                break;
            case '2':
                cout<<"\nThe contents of the PROJECT TABLE are as follows\n";
                cout<<"==================================================================\n";
                cout<<"PROJECT NAME\t\tPROJECT NO\t\tLOCATION\n";
                cout<<"==================================================================\n";
                P.showalldata();break;
            case '3':
               cout<<"\n\tPlease Enter the Project No. ";
               cin>>n;
               P.searchdata(n);
               break;
            case '4':
                cout<<"\n\tPlease Enter the Project No. ";
                cin>>n;
                P.updatedata(n);
                break;
            case '5':
                cout<<"\n\tPlease Enter the Project No. ";
                cin>>n;
                P.deletedata(n);
                break;
            case '6':return;
            default :cout<<"\a";
        }
        }while(ch!='6');
}

void emplyee_menu(){
    EMPLOYEE E;
    char ch;
    do
    {
        system("cls");
        changeColor(112);
        cout<<"\n\tEMPLOYEE MENU";
        cout<<"\n\n\t1.CREATE EMPLOYEE RECORD";
        cout<<"\n\t2.DISPLAY ALL EMPLOYEE RECORD";
        cout<<"\n\t3.DISPLAY SPECIFIC EMPLOYEE RECORD";
        cout<<"\n\t4.MODIFY EMPLOYEE RECORD";
        cout<<"\n\t5.DELETE EMPLOYEE RECORD";
        cout<<"\n\t6.GO TO MAIN MENU";
        cout<<"\n\n\tPlease Select Your Option (1-6):   ";
        ch=getche();
        ll n;
        switch(ch){
            case '1':
                E.getdata();
                E.storedata();
                break;
            case '2':
                cout<<"\n\tEMPLOYEE LIST\n";
                cout<<"==================================================================\n";
                cout<<"SSN No.\t\tFName\tMName    LName\t\tSex\tSalary(in Rs.)\tAddress\n";
                cout<<"==================================================================\n";
                E.showalldata();break;
            case '3':
               cout<<"\n\tPlease Enter The SSN No. ";
               cin>>n;
               E.searchdata(n);
               break;
            case '4':
                cout<<"\n\tPlease Enter The SSN No. ";
                cin>>n;
                E.updatedata(n);
                break;
            case '5':
                cout<<"\n\tPlease Enter The SSN No. ";
                cin>>n;
                E.deletedata(n);
                break;
            case '6':return;
            default :cout<<"\a";
        }
        }while(ch!='6');
}

signed main()
{
    char ch;
    intro();
    system("cls");
//    system("Color 7D");
    do
    {
        changeColor(117);
        system("cls");
        cout<<"\n\tMAIN MENU";
        cout<<"\n\n\t1.EMPLOYEE MENU";
        cout<<"\n\n\t2.DEPARTMENT MENU";
        cout<<"\n\n\t3.PROJECT ASSIGNED MENU";
        cout<<"\n\n\t4.WORKS ON MENU";
        cout<<"\n\n\t5.WORKS FOR";
        cout<<"\n\n\t6.EXIT";
        cout<<"\n\n\n\tPlease Select Your Option (1-6):   ";
        ch=getche();
        switch(ch){
            case '1':
                emplyee_menu();
                break;
            case '2':
                department_menu();
                break;
            case '3':
                project_menu();
               break;
            case '4':
                //works_on();
                break;
            case '5':
                //works_for();
                break;
            case '6':exit(0);
            default :cout<<"\a";
        }
        }while(ch!='6');
}
