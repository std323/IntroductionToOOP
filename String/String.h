#pragma once

#include<iostream>
using namespace std;

#define delimiter "\n--------------------------------------\n"

////////////////////////////////////////////////////////////////
///////////    CLASS DECLARATION - ���������� ������  //////////


class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& operator>>(std::istream& is, String& obj);

class String
{
	int size;  // ������ ������� � ������
	char* str; // ����� ������ � ������������ ������
public:

	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//            Constructors:
	explicit String(int size = 256);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//                  Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);
	//             Operators:

	String& operator +=(const String& other);
	const char& operator[](int i)const;
	char& operator[](int i);

	//        Methods:
	void print()const;
};

/////////// CLASS DECLARATION END - ����� ���������� ������  //////////
///////////////////////////////////////////////////////////////////////