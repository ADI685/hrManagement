#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
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
		//cout << "enter address " << endl;
		cin >> address;
		//cout << "enter fname" << endl;
		cin >> fname;
		//cout << "enter mname" << endl;
		cin >> mname;
		//cout << "enter lname" << endl;
		cin >> lname;
		//cout << "enter ssn" << endl;
		cin >> ssn;
		//cout << "enter salary" << endl;
		cin >> salary;
		//cout << "enter sex" << endl;
		cin >> sex;
		//cout << endl;
	}
	void showdata()
	{
		cout << ssn << " " << sex << " " << fname << "-" << mname << "-" << lname << " " << address << " " << salary << endl;
	}
	void storedata()
	{
		if (ssn == 0 )
		{
			cout << "enter valid data" << endl;
			return ;
		}
		ofstream fout;
		fout.open("file1.dat", ios::out | ios::binary);
		fout.write((char*)this, sizeof(*this));
		fout.close();



	}
	void showalldata()
	{
		ifstream fin;
		fin.open("file1.dat", ios::in | ios::binary);
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
	void searchdata(ll temp_ssn)
	{
		ifstream fin;
		fin.open("file1.dat", ios::in | ios::binary);
		if (!fin)
			cout << "file not found" << endl;
		else
		{
			int flag = 0;
			fin.read((char*)this, sizeof(*this));
			while (!fin.eof())
			{
				if (temp_ssn == ssn)
					showdata();
				fin.read((char*)this, sizeof(*this));

			}
			fin.close();
		}



	}
	void deletedata(ll temp_ssn)
	{
		ifstream fin;
		ofstream fout;
		fin.open("file1.dat", ios::in | ios::binary);
		if (!fin)
			cout << "file doesnt exist" << endl;
		else
		{
			fout.open("temp_file1.dat", ios::out | ios::binary);
			fin.read((char*)this, sizeof(*this));
			while (!fin.eof())
			{
				if (temp_ssn != ssn)
				{
					fout.write((char*)this, sizeof(*this));
				}
				fin.read((char*)this, sizeof(*this));

			}
			fin.close();
			fout.close();
			remove("file1.dat");
			rename("temp_file1.dat", "file1.dat");


		}



	}
	void updatedata(ll temp_ssn)
	{
		fstream file;
		file.open("file1.dat", ios::in | ios::out | ios::ate | ios::binary);
		file.seekg(0);
		if (!file)
			cout << "file doesnt exist" << endl;
		else
		{

			file.read((char*)this, sizeof(*this));
			while (!file.eof())
			{
				if (temp_ssn == ssn)
				{
					getdata();
					file.seekg(file.tellg() - (ll)sizeof(*this));
					file.write((char*)this, sizeof(*this));
				}
				file.read((char*)this, sizeof(*this));

			}
			file.close();



		}







	}





};

signed  main()
{
	init_code();
	EMPLOYEE E;
	E.getdata();
	//b.showdata();
	E.storedata();
	E.showalldata();
	E.searchdata(123456);
	E.deletedata(1234567);
	//E.updatedata(1234567);
	E.showalldata();


}
