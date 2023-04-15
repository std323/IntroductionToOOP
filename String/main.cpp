#include<iostream>
using namespace std;

#define delimiter "\n--------------------------------------\n"

////////////////////////////////////////////////////////////////
///////////    CLASS DECLARATION - ОБЬЯВЛЕНИЕ КЛАССА  //////////


class String;
String operator+(const String& left, const String& right);

class String
{
	int size;  // Размер строкив в Байтах
	char* str; // Адрес строки в динамической памяти
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

/////////// CLASS DECLARATION END - КОНЕЦ ОБЬЯВЛЕНИЯ КЛАССА  //////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
/////////// CLASS DEFINITION - ОПРЕДЕЛЕНИЕ КЛАССА  ////////////////////


//:: - Оператор разрешения видимости (Scope operator)

int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
//            Constructors:

String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "Default1ArgConstruct:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)//Делегируем выделение памяти конструктору по умолчанию
{
	//this->size = strlen(str)+1;
	//this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//Deep copy (Побитовое копирование):
	//this->size = other.size;
	//this->str = new char[size] {};
	//for(int i = 0; i<size; i++)this->str[i]= other.str[i];
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	//Shallow copy (Поверхностное копирование):
	//this->size = other.size;
	//this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
}

//                  Operators:
//type     name       (parameters)
String& String::operator=(const String& other)
{
	//Deep copy (Побитовое копирование):
	int a = 2;
	int b = 3;
	a = b;

	//0) Проверяем не является ли принятый параметр нашим обьектом:
	if (this == &other)return *this;


	//1) Удаляем старую строку:
	delete[] this->str;

	//2) Выполняем побитовое копирование:
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	//Shallow copy - поверхностное копирование
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignemtn:\t\t" << this << endl;
}
//             Operators:

String& String::operator +=(const String& other)
{
	return *this = *this + other;
}
const char& String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//        Methods:
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

String operator+(const String& left, const String& right)
{
	String cat (left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		//cat.get.str()[i]=left.get_str()[i];
		 cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	//cat.get_str()[i+left.get_size()-1]=right.get_str()[i];
	return cat;
}

std::ostream& operator <<(std::ostream& os, const String& obj)
{
	//os - Output stream
	//obj - Object
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is, String& obj)
{
	//is - Input Stream
	const int SIZE = 102400;
	char buffer[SIZE]{};
	is >> buffer;
	obj = buffer;
	return is; // >> obj.get_str();
}

/////////// CLASS DEFINITION END - КОНЕЦ ОПРЕДЕЛЕНИЯ КЛАССА  //////////
///////////////////////////////////////////////////////////////////////

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