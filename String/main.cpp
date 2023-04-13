#include<iostream>
using namespace std;


class String
{
	int size;  // Размер строкив в Байтах
	char* str; // Адрес строки в динамической памяти
public:
	
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	//            Constructors:
	explicit String(int size = 256)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Default1ArgConstruct:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str)+1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other)
	{
		//Deep copy (Побитовое копирование):
		this->size = other.size;
		this->str = new char[size] {};
		for(int i = 0; i<size; i++)this->str[i]= other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other)
	{
		//Shallow copy (Поверхностное копирование):
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//                  Operators:
	String& operator=(const String& other)
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
	String& operator=(String&& other)
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
	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}

	//        Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

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
	return os << obj.get_str();
}

//#define CONSTRUCTORS_CHEK
#define HOME_WORK_1

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
	String str3 = str1 + str2; //Move constructor
	//String str3;
	//str3 = str1 + str2;         //Move assignment
	cout << str1 << " + " << str2 << " = " << str3 << endl;
	//str1 += str2;
	//cout << str1 << endl;
#endif // HOME_WORK_1


}