#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
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
		cout << "enter PROJECT NUMBER " << endl;
		cin >> PROJ_NO;

		cout << "enter PROJECT name" << endl;
		cin >> proj_name;
        cout << "enter location" << endl;
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
			cout << "enter valid data" << endl;
			return ;
		}
		ofstream fout;
		fout.open("file2.dat", ios::out | ios::binary);
		fout.write((char*)this, sizeof(*this));
		fout.close();
	}



	void showalldata()
	{
		ifstream fin;
		fin.open("file2.dat", ios::in | ios::binary);
		if (!fin)
			cout << "file not found" << endl;
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
			cout << "file doesnt exist" << endl;
		else
		{
			fout.open("temp_file2.dat", ios::out | ios::binary);
			fin.read((char*)this, sizeof(*this));
			while (!fin.eof())
			{
				if (tempPROJ_NO != PROJ_NO)
				{
					fout.write((char*)this, sizeof(*this));
				}
				fin.read((char*)this, sizeof(*this));

			}
			fin.close();
			fout.close();
			remove("file2.dat");
			rename("temp_file2.dat", "file1.dat");


		}
	}
	// void updatedata(int tempPROJ_NO)
	// {
	// 	fstream file;
	// 	file.open("file2.dat", ios::in | ios::out | ios::ate | ios::binary);
	// 	file.seekg(0);
	// 	if (!file)
	// 		cout << "file doesnt exist" << endl;
	// 	else
	// 	{

	// 		file.read((char*)this, sizeof(*this));
	// 		while (!file.eof())
	// 		{
	// 			if (tempPROJ_NO == PROJ_NO)
	// 			{
	// 				getdata();
	// 				file.seekg(file.tellg() - sizeof(*this));
	// 				file.write((char*)this, sizeof(*this));
	// 			}
	// 			file.read((char*)this, sizeof(*this));

	// 		}
	// 		file.close();



	// 	}







	// }





};

int  main()
{
	// init_code();
	PROJECT P;
	P.getdata();
	P.storedata();
	P.showalldata();
	P.searchdata(0);
	P.deletedata(2);
	P.searchdata(0);


	return 0;
}
