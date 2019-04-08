// test.cc// Copyright 1997, Gregory A. Riccardi
#include <fstream>
#include <vector>
#include <string.h>
#include <iomanip>
#include "fixtext.h"
#include "lentext.h"
#include "deltext.h"
#include "person.h"

int testFixText() {
	cout << "\nTesting FixedTextBuffer" << endl;
	int count, select;
	char filename[20];
	Person person;
	Person *stable[10];

	FixedTextBuffer Buff(100);
	Person::InitBuffer(Buff);



	cout << "Enter the file name:" << flush;
	cin >> filename;

	while (1)
	{
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;

		switch (select) {
		case 1:
			//to store a array of Person objects by inputing
			cout << "the number of Person object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cin >> person;
				person.Print(cout);
				stable[i] = new Person(person);
			}
			break;
		case 2:
			// to display the array of Person objects into screen  
			for (int i = 0; i < count; i++)
			{
				cout << *stable[i];
			}
			break;
		case 3:
		{
			// to write the array of Person objects into a file
			ofstream fostream(filename, ios::out);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Person::InitBuffer(Buff);
			for (int i = 0; i < count; i++)
			{
				Person p = *stable[i];

				p.setFixedLength();


				p.Print(cout);
				p.Pack(Buff);
				Buff.Print(cout);
				Buff.Write(fostream);
				//작성할 코드
			}
			fostream.close();
			break;
		}
		case 4:
		{
			// to read the array of Person records from the file
			ifstream fistream(filename, ios::in | ios::binary);
			if (fistream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
//			Buff.Clear();
		//	Person::InitBuffer(Buff);
			for (int i = 0; i < count; i++)
			{
				//wkrtjdgkfzhem
				Person p;
				Buff.readClear();
				
				Buff.Read(fistream);
				p.Unpack(Buff);
				p.Print(cout);
			}
			fistream.close();
			break;
		}
		default:
			// others
			exit(0);
			break;
		}
		//*/
	}
	return 1;
}
int testLenText() {
	int count, select;
	char filename[20];
	Person person;
	Person *stable[10];
	vector <int> size;

	cout << "\nTesting LengthTextBuffer" << endl;
	LengthTextBuffer Buff(100);
	Person::InitBuffer(Buff);

	cout << "Enter the file name:" << flush;
	cin >> filename;

	while (1)
	{
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;

		switch (select) {
		case 1:
			//to store a array of Person objects by inputing
			cout << "the number of Person object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cin >> person;
				person.Print(cout);
				stable[i] = new Person(person);
			}
			break;
		case 2:
			// to display the array of Person objects into screen  
			for (int i = 0; i < count; i++)
			{
				cout << *stable[i];
			}
			break;
		case 3:
		{
			// to write the array of Person objects into a file
			ofstream fostream(filename, ios::out);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Person::InitBuffer(Buff);
			for (int i = 0; i < count; i++)
			{
				auto p = *stable[i];
				p.Print(cout);
				Buff.Print(cout);

				cout << "pack person " << p.Pack(Buff) << endl;
				Buff.Print(cout);
				size.push_back(Buff.BufferSize);

				Buff.Write(fostream);
			//	Buff.Write(fostream);

			}
			fostream.close();
			break;
		}
		case 4:
		{
			// to read the array of Person records from the file
			ifstream fistream(filename, ios::in | ios::binary);
			if (fistream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Person::InitBuffer(Buff);
			for (int i = 0; i < count; i++)
			{
				Person p;
				Buff.BufferSize = size[i];

				cout << "read " << Buff.Read(fistream) << endl;
				cout << "unpack " << p.Unpack(Buff) << endl;

				p.Print(cout);

			}
			fistream.close();
			break;
		}
		default:
			// others
			exit(0);
			break;
		}
		//*/
	}
	return 1;
}
int testDelText() {
	int count, select;
	char filename[20];
	Person person;
	Person *stable[10];
	cout << "\nTesting DelimTextBuffer" << endl;
	DelimTextBuffer Buff;
	Person::InitBuffer(Buff);

	cout << "Enter the file name:" << flush;
	cin >> filename;

	while (1)
	{
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;

		switch (select) {
		case 1:
			//to store a array of Person objects by inputing
			cout << "the number of Person object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cin >> person;
				person.Print(cout);
				stable[i] = new Person(person);
			}
			break;
		case 2:
			// to display the array of Person objects into screen  
			for (int i = 0; i < count; i++)
			{
				cout << *stable[i];
			}
			break;
		case 3:
		{
			// to write the array of Person objects into a file
			ofstream fostream(filename, ios::out);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Person::InitBuffer(Buff);
			for (int i = 0; i < count; i++)
			{
				auto p = *stable[i];

				Buff.Print(cout);
				cout << "pack person " << p.Pack(Buff) << endl;
				Buff.Print(cout);

				Buff.Write(fostream);
			}
			fostream.close();
			break;
		}
		case 4:
		{
			// to read the array of Person records from the file
			ifstream fistream(filename, ios::in | ios::binary);
			if (fistream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Person::InitBuffer(Buff);
			for (int i = 0; i < count; i++)
			{
				Person p;

				cout << " read " << Buff.Read(fistream) << endl;
				cout << "unpack " << p.Unpack(Buff) << endl;
				p.Print(cout);
			}
			fistream.close();
			break;
		}
		default:
			// others
			exit(0);
			break;
		}
		//*/
	}
	return 1;
}

/*
void testFixTextt()
{
	Person person;
	FixedTextBuffer Buff(6);
	Person::InitBuffer(Buff);
	strcpy(person.LastName, "Ames      ");
	strcpy(person.FirstName, "Mary      ");
	strcpy(person.Address, "123 Maple      ");
	strcpy(person.City, "Stillwater     ");
	strcpy(person.State, "OK");
	strcpy(person.ZipCode, "74075    ");
	person.Print(cout);
	person.Pack(Buff);
	Buff.Print(cout);
	ofstream TestOut("fixtext.dat", ios::out | ios::binary);
	Buff.Write(TestOut);
	TestOut.close();
	ifstream TestIn("fixtext.dat", ios::in | ios::binary);
	FixedTextBuffer InBuff(6);
	Person::InitBuffer(InBuff);
	Buff.Read(TestIn);
	person.Unpack(Buff);
	person.Print(cout);
}
*/
int main(int argc, char ** argv)
{
	cout << "\nTesting Buffer" << endl;
	int select;
	cout << "\nSelect buffer type 1: Fixed Field Buffer, 2. Length Field Buffer, 3. Delim Field Buffer, 4. Quit => ";
	cin >> select;
	switch (select) {
	case 1:
		cout << "Testing Fixed Field Buffer" << endl;
		//testFixTextt();
		if (testFixText() == 0) cout << "***" << endl;
		break;
	case 2:
		cout << "\nTesting LengthTextBuffer" << endl;
		testLenText();
		break;
	case 3:
		cout << "\nTesting DelimTextBuffer" << endl;
		testDelText();
		break;
	default:
		break;
	}
	return 1;
}

/*
void testLenText ()
{
	cout << "\nTesting LengthTextBuffer"<<endl;
	Person person;
	LengthTextBuffer Buff;
	Person :: InitBuffer (Buff);
	strcpy (person.LastName, "Ames");
	strcpy (person.FirstName, "Mary");
	strcpy (person.Address, "123 Maple");
	strcpy (person.City, "Stillwater");
	strcpy (person.State, "OK");
	strcpy (person.ZipCode, "74075");
	person . Print (cout);
	Buff . Print (cout);
	cout <<"pack person "<<person . Pack (Buff)<<endl;
	Buff . Print (cout);
	ofstream TestOut ("lentext.dat",ios::out|ios::inout);
	Buff . Write (TestOut);
	Buff . Write (TestOut);
	strcpy (person.FirstName, "Dave");
	person.Print (cout);
	person.Pack (Buff);
	Buff . Write (TestOut);
	TestOut . close ();
	ifstream TestIn ("lentext.dat", ios::in|ios::bin);
	LengthTextBuffer InBuff;
	Person :: InitBuffer (InBuff);
	cout <<"read "<<Buff . Read (TestIn)<<endl;
	cout <<"unpack "<<person . Unpack (Buff)<<endl;
	person . Print (cout);
	cout <<"read "<<Buff . Read (TestIn)<<endl;
	cout <<"unpack "<<person . Unpack (Buff)<<endl;
	person . Print (cout);
	cout <<"read "<<Buff . Read (TestIn)<<endl;
	cout <<"unpack "<<person . Unpack (Buff)<<endl;
	person . Print (cout);
}

void testDelText ()
{
	cout << "\nTesting DelimTextBuffer"<<endl;
	Person person;
	strcpy (person.LastName, "Ames");
	strcpy (person.FirstName, "Mary");
	strcpy (person.Address, "123 Maple");
	strcpy (person.City, "Stillwater");
	strcpy (person.State, "OK");
	strcpy (person.ZipCode, "74075");
	person . Print (cout);
	DelimTextBuffer Buff;
	Person :: InitBuffer (Buff);
	Buff . Print (cout);
	cout <<"pack person "<<person . Pack (Buff)<<endl;
	Buff . Print (cout);
	ofstream TestOut ("deltext.dat",ios::out|ios::bin);
	Buff . Write (TestOut);
	Buff . Write (TestOut);
	strcpy (person.FirstName, "Dave");
	person.Print (cout);
	person.Pack (Buff);
	Buff . Write (TestOut);
	TestOut . close ();
	ifstream TestIn ("deltext.dat", ios::in|ios::bin);
	DelimTextBuffer InBuff;	Person :: InitBuffer (InBuff);
	cout <<"read "<<Buff . Read (TestIn)<<endl;
	cout <<"unpack "<<person . Unpack (Buff)<<endl;
	person . Print (cout);
	cout <<"read "<<Buff . Read (TestIn)<<endl;
	cout <<"unpack "<<person . Unpack (Buff)<<endl;
	person . Print (cout);
	cout <<"read "<<Buff . Read (TestIn)<<endl;
	cout <<"unpack "<<person . Unpack (Buff)<<endl;
	person . Print (cout);
}
*/