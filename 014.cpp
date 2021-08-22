#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char* p;
public:
	MyString(const char* s) {
		if (s) {
			p = new char[strlen(s) + 1];
			strcpy(p, s);
		}
		else
			p = NULL;

	}
	~MyString() { if (p) delete[] p; }
	MyString(const MyString& s)
	{
		p = new char[s.size()];
		strcpy(p, s.p);
	}
	int size() const
	{
		return strlen(p);
	}
	
	void Copy(const char* s);
	friend ostream& operator<< (ostream& is, const MyString& s);
	MyString& operator= (char* s)
	{
		//if (p)
		//	delete[]p;
		p = new char[strlen(s) + 1];
		strcpy(p, s);
		return *this;
	}
	MyString& operator= (MyString& s)
	{
		if (p)
			delete[]p;
		p = new char[s.size()+1];
		strcpy(p, s.p);
		return *this;
	}
};

void MyString::Copy(const char* s)
{
	if (s&&p)
	{
		delete []p;
		p = new char[strlen(s) + 1];
		strcpy(p, s);
	}
	else
	{
		//Èç¹ûsÎª¿Õ
		if (!s)
		{
			delete []p;
			p = NULL;
			return;
		}
		if (!p)
		{
			p = new char[strlen(s) + 1];
			strcpy(p, s);
		}
	}
}

ostream& operator<< (ostream& is,const MyString& s)
{
	is << s.p;
	return is;
}
int main()
{
	char w1[200], w2[100];
	while (cin >> w1 >> w2) {
		MyString s1(w1), s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;

	}
}