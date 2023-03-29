#include<iostream>
using namespace std;

class Point
{
	/*
	    Создавая структуру или класс мы создаем новый тип данных.
	*/
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//       Methods:
	double distance(Point other)
	{
		//this - эта точка
		//other - другая точка (указанная точка)

		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
};
double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
	
}

//#define STRUCT_POINT
void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	int a; //Обьявление переменной 'a' типа 'int'
	Point A;//Обьявление переменной 'A' типа 'Point'
	//Обьявление обьекта 'A' типа 'Point'
	//Cоздание экземпляра 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << "Расстояние между точками А и В: " << distance(A, B) << endl;
	cout << "Расстояние между точками B и A: " << distance(B, A) << endl;

}