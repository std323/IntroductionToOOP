#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;


////////////CLASS DECLARATION - ���������� ������

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
std::ostream& operator <<(std::ostream& os, const Fraction& obj);
std::istream& operator >>(std::istream& is, Fraction& obj);

class Fraction
{
	int integer;     //����� �����
	int numerator;   //���������
	int denominator; //�����������
public:

	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	//                  Constructors:
	Fraction();
	explicit Fraction(int integer);
	Fraction(double decimal);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();
	//                    Operator:
	Fraction& operator=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator /=(const Fraction& other);
	//              Increment/Decrement
	Fraction& operator++();
	Fraction operator++(int);
	//              Type-cast operators:
	explicit operator int();
	explicit operator double();


	//                   Methods:
	Fraction& to_improper();
	Fraction& to_proper();
	Fraction inverted()const;
	Fraction& reduce();
	void print()const;
};
///////////CLASS DECLARATION END- ����� ���������� ������
