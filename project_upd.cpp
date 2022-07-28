/*                          |   /  ______
							|  /  |
							| /   |
							|/    |______
							|\          |
							| \         |
							|  \        |
							|   \ ______|

*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long

// void init_code()
// {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// 	freopen("error.txt", "w", stderr);
// #endif

// 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// }
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
		cout << "Enter Project No." << endl;
		cin >> PROJ_NO;

		cout << "Enter Project name" << endl;
		cin >> proj_name;

        cout << "Enter location" << endl;
		cin>>location;
	}
	
	void showdata()
	{
		cout << proj_name << "-" << PROJ_NO << "-" << location << endl ;
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
};

int  main()
{
	// init_code();
	PROJECT P;
	char choice;
	do{
		P.getdata();
		P.storedata();
		
		cout << "\nDo you want to add another Project? ('Y' for Yes|'N' for No)" << endl;
		cin >> choice;

	}while(choice == 'y' || choice == 'Y');

	// Displaying the data
	cout << "\nThe contents of the table are as follows\n" << endl;
	P.showalldata();

	// Searching
	int search_proj;
	cout << "\nEnter the Project No. of the project you want to search" << endl;
	cin >> search_proj;

	P.searchdata(search_proj);

	// Deleting
	int delete_proj;
	cout << "\nEnter the Project No. of the project you want to delete" << endl;
	cin >> delete_proj;

	P.deletedata(delete_proj);

	cout << "\nThe contents of the table are as follows\n" << endl;
	P.showalldata();
	// P.searchdata(0);

	return 0;
}
