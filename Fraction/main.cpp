#include"Fraction.h"

//#define CONSTRUCTORS_CHEK
//#define ARITHMETICAL_OPERATORS_CHEK
//#define ISTREAM_OPERATOR_CHEK
//#define TYPE_CONVERSION_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER
//#define HOME_WORK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHEK
	Fraction A;
	A.print();

	Fraction B = 3;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();

	A = E;
	A.print();
#endif // CONSTRUCTORS_CHEK

#ifdef ARITHMETICAL_OPERATORS_CHEK
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	/*double a = 2.5;
	double b = 3.14;
	double c = a * b;


	Fraction C = A * B;
	C.print();

	Fraction D = A / B;
	D.print();

	A.print();
	B.print();

	Fraction E = A + B;
	E.print();

	Fraction F = A - B;
	F.print();*/

	A *= B;
	A.print();

	A /= B;
	A.print();
	 for (double i = .75; i < 10; i++)
	 {
		 cout << i << "\t";
	 }
	 cout << endl;

	for (Fraction i(3, 4); i.get_integer() < 10; i++)
	{
		i.print();
	}
#endif // ARITHMETICAL_OPERATORS_CHEK

#ifdef ISTREAM_OPERATOR_CHEK
	//cout << (Fraction(1, 2) >= Fraction(5, 11)) << endl;
/*Fraction A(2, 3, 4);
cout << A;*/

	Fraction A(123, 32, 45);
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;


#endif // ISTREAM_OPERATOR_CHEK

#ifdef TYPE_CONVERSION_BASICS
	int a = 2;    //No conversion
	double b = 3; //Conversion from less to more
	int c = b;    //Conversion from more to less wiyhout data loss
	int d = 2.5;  //Conversion from more to less with data loss

#endif // TYPE_CONVERSION_BASICS

#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5; //Conversion from other to Class produced by Singl-Argument
	cout << A << endl;
	Fraction B;               //Default constructor
	B = Fraction(8);          //Conversion from other to Class produced by Assignment operato
	cout << B << endl;
#endif // CONVERSION_FROM_OTHER_TO_CLASS

#ifdef  CONVERSION_FROM_CLASS_TO_OTHER
	Fraction A(2, 3, 4);
	cout << A << endl;

	int a = (int)A;
	cout << a << endl;

	double b = (double)A;
	cout << b << endl;
#endif //  CONVERSION_FROM_CLASS_TO_OTHER

#ifdef HOME_WORK
	Fraction A = 2.75;
	cout << A << endl;
#endif // HOME_WORK

}