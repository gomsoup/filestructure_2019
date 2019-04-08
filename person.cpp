//person.cc
// Copyright 1997, Gregory A. Riccardi

#include "person.h"
#define ARRAY_LEN(X) (sizeof(X)/sizeof(X[0]))

Person::Person ()
{
	Clear ();
}

Person::Person(Person &s)
{
	strcpy(LastName, s.LastName);
	strcpy(FirstName, s.FirstName);
	strcpy(Address, s.Address);
	strcpy(City, s.City);
	strcpy(State, s.State);
	strcpy(ZipCode, s.ZipCode);
}
istream& operator>> (istream &stream, Person &s)
{
	cout << "LastName : ";
	stream >> s.LastName;
	cout << "FirstNAme : ";
	stream >> s.FirstName;
	cout << "Address : ";
	stream >> s.Address;
	cout << "City : ";
	stream >> s.City;
	cout << "State : ";
	stream >> s.State;
	cout << "Zipcode : ";
	stream >> s.ZipCode;
	return stream;
}

ostream& operator<< (ostream &stream, Person &s)
{
	stream << s.LastName << s.FirstName << s.Address << s.City << s.State << s.ZipCode;
	return stream;
}


void Person::Clear ()
{
	// set each field to an empty string
	LastName [0] = 0;
	FirstName [0] = 0;
	Address [0] = 0;
	City [0] = 0;
	State [0] = 0;
	ZipCode [0] = 0;
}

int Person::Pack (FixedTextBuffer & Buffer) const
{// pack the fields into a FixedTextBuffer, return TRUE if all succeed, FALSE o/w
	int result;
	Buffer . Clear ();
	result = Buffer . Pack (LastName);
	result = result && Buffer . Pack (FirstName);
	result = result && Buffer . Pack (Address);
	result = result && Buffer . Pack (City);
	result = result && Buffer . Pack (State);
	result = result && Buffer . Pack (ZipCode);
	return result;
}

int Person::Unpack (FixedTextBuffer & Buffer)
{
	Clear ();
	int result;
	result = Buffer . Unpack (LastName);
	result = result && Buffer . Unpack (FirstName);
	result = result && Buffer . Unpack (Address);
	result = result && Buffer . Unpack (City);
	result = result && Buffer . Unpack (State);
	result = result && Buffer . Unpack (ZipCode);
	return result;
}

int Person::InitBuffer (FixedTextBuffer & Buffer)
// initialize a FixedTextBuffer to be used for Persons
{
	int result;
	result = Buffer . AddField (10); // LastName [11];
	result = result && Buffer . AddField (10); // FirstName [11];
	result = result && Buffer . AddField (15); // Address [16];
	result = result && Buffer . AddField (15); // City [16];
	result = result && Buffer . AddField (2);  // State [3];
	result = result && Buffer . AddField (9); // ZipCode [10];
	return result;
}

int Person::Pack (LengthTextBuffer & Buffer) const
{// pack the fields into a FixedTextBuffer, return TRUE if all succeed, FALSE o/w
	int result;
	Buffer . Clear ();
	result = Buffer . Pack (LastName);
	result = result && Buffer . Pack (FirstName);
	result = result && Buffer . Pack (Address);
	result = result && Buffer . Pack (City);
	result = result && Buffer . Pack (State);
	result = result && Buffer . Pack (ZipCode);
	return result;
}

int Person::Unpack (LengthTextBuffer & Buffer)
{
	int result;
	result = Buffer . Unpack (LastName);
	result = result && Buffer . Unpack (FirstName);
	result = result && Buffer . Unpack (Address);
	result = result && Buffer . Unpack (City);
	result = result && Buffer . Unpack (State);
	result = result && Buffer . Unpack (ZipCode);
	return result;
}

int Person::InitBuffer (LengthTextBuffer & Buffer)
// initialize a LengthTextBuffer to be used for Persons
{
	return TRUE;
}

int Person::Pack (DelimTextBuffer & Buffer) const
{// pack the fields into a FixedTextBuffer, return TRUE if all succeed, FALSE o/w
	int result;
	Buffer . Clear ();
	result = Buffer . Pack (LastName);
	result = result && Buffer . Pack (FirstName);
	result = result && Buffer . Pack (Address);
	result = result && Buffer . Pack (City);
	result = result && Buffer . Pack (State);
	result = result && Buffer . Pack (ZipCode);
	return result;
}

int Person::Unpack (DelimTextBuffer & Buffer)
{
	int result;
	result = Buffer . Unpack (LastName);
	result = result && Buffer . Unpack (FirstName);
	result = result && Buffer . Unpack (Address);
	result = result && Buffer . Unpack (City);
	result = result && Buffer . Unpack (State);
	result = result && Buffer . Unpack (ZipCode);
	return result;
}

int Person::InitBuffer (DelimTextBuffer & Buffer)
// initialize a DelimTextBuffer to be used for Persons
{
	return TRUE;
}

void Person::Print (ostream & stream)
{
	stream << "Person:"
		<< "\t Last Name '"<<LastName<<"'\n"
		<< "\tFirst Name '"<<FirstName<<"'\n"
		<< "\t   Address '"<<Address<<"'\n"
		<< "\t      City '"<<City<<"'\n"
		<< "\t     State '"<<State<<"'\n"
		<< "\t  Zip Code '"<<ZipCode<<"'\n" <<flush;
}

void Person::setFixedLength() {
	printf("%d, %d", ARRAY_LEN(LastName), strlen(LastName));

	for (int i = strlen(LastName); i < ARRAY_LEN(LastName); i++) {
		LastName[i] = ' ';
		if (i == ARRAY_LEN(LastName) - 1)
			LastName[i] = 0;
	}

	for (int i = strlen(FirstName); i < ARRAY_LEN(FirstName); i++) {
		FirstName[i] = ' ';		
		if (i == ARRAY_LEN(FirstName) - 1)
			FirstName[i] = 0;
	}

	for (int i = strlen(Address); i < ARRAY_LEN(Address); i++) {
		Address[i] = ' ';
		if (i == ARRAY_LEN(Address) - 1)
			Address[i] = 0;
	}

	for (int i = strlen(City); i < ARRAY_LEN(City); i++) {
		City[i] = ' ';
		if (i == ARRAY_LEN(City) - 1)
			City[i] = 0;
	}

	for (int i = strlen(State); i < ARRAY_LEN(State); i++) {
		State[i] = ' ';
		if (i == ARRAY_LEN(State) - 1)
			State[i] = 0;
	}

	for (int i = strlen(ZipCode); i < ARRAY_LEN(ZipCode); i++) {
		ZipCode[i] = ' ';
		if (i == ARRAY_LEN(ZipCode) - 1)
			ZipCode[i] = 0;
	}

}