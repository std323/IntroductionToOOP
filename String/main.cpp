#include"String.h"

//#define CONSTRUCTORS_CHEK
//#define HOME_WORK_1
//#define ISTREAM_OPERATOR
//#define CONSTRUCTORS_CHEK_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHEK
	String str1;      //Default constructor
	str1.print();

	//Single-argiment constructor
	//String str2 = 16; // explicit constructor невозможно вызвать оператором присвоить
	String str2(16);    //его можно вызвать только так
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	str3.print();

	//String str4 = str3; //Copy constructor
	String str4;
	str4 = str3;  //CopyAssignment
	str4.print();

#endif // CONSTRUCTORS_CHEK
#ifdef HOME_WORK_1

	String str1 = "Hello";
	String str2 = "World";
	//String str3 = str1 + " " + str2;
	//String str3 = str1 + str2; //Move constructor
	//String str3;
	//str3 = str1 + str2;         //Move assignment
	//cout << str1 << " + " << str2 << " = " << str3 << endl;
	str1 += str2;
	cout << delimiter << endl;
	cout << str1 << endl;
	cout << delimiter << endl;
#endif // HOME_WORK_1
#ifdef ISTREAM_OPERATOR
	String str;
	cout << "Введите строку: "; cin >> str;
	str.print();
	cout << str << endl;

	/*Strting last_name;
	Strting first_name;
	//str.print();
	cout << "Введите Ваше имя: ";
	cin >> last_name << first_name;
	//str.print();
	cout << last_name << first_name << endl;*/

#endif // ISTREAM_OPERATOR
#ifdef CONSTRUCTORS_CHEK_2

	String str1; //Default constructor
	str1.print();
	String str2(8);  //Single-argument constructor of type 'int'
	str2.print();
	String str3 = "Hello!"; //Single-argument constructor of type 'const char*'
	str3.print();
	String str4();    //Здесь не вызывается конструктор по умолчанию,
	                  //В этой строке обьявляется функция str4, которая
	                  //ничего не принимает, и возвращает значение типа String
//str4.   //This is not an object
	String str5{};     //Явный вызов конструктора по умолчанию
	str5.print();

	String str6{ 123 };
	str6.print();

	String str7{ "World" };
	str7.print();

#endif // CONSTRUCTORS_CHEK_2

}