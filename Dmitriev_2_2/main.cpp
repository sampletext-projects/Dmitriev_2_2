#include <iostream>
#include <math.h>
#include <iomanip>
#include <conio.h>

using namespace std;

class Triangle
{
	double side1;
	double side2;
	double side3;
	double angle1;
	double angle2;
	double angle3;

public:
	Triangle() //init
	{
		side1 = 0.0;
		side2 = 0.0;
		side3 = 0.0;
		angle1 = 0.0;
		angle2 = 0.0;
		angle3 = 0.0;
	}

	Triangle(double side1_, double side2_, double side3_, double angle1_, double angle2_, double angle3_) //read
	{
		side1 = side1_;
		side2 = side2_;
		side3 = side3_;
		angle1 = angle1_;
		angle2 = angle2_;
		angle3 = angle3_;
	}

	Triangle(Triangle& obj)
	{
		side1 = obj.side1;
		side2 = obj.side2;
		side3 = obj.side3;
		angle1 = obj.angle1;
		angle2 = obj.angle2;
		angle3 = obj.angle3;
	}

	double get_side1()
	{
		return side1;
	}

	double get_side2()
	{
		return side2;
	}

	double get_side3()
	{
		return side3;
	}

	double get_angle1()
	{
		return angle1;
	}

	double get_angle2()
	{
		return angle2;
	}

	double get_angle3()
	{
		return angle3;
	}

	void set_side1(double side1_)
	{
		side1 = side1_;
	}

	void set_side2(double side2_)
	{
		side2 = side2_;
	}

	void set_side3(double side3_)
	{
		side3 = side3_;
	}

	void set_angle1(double angle1_)
	{
		angle1 = angle1_;
	}

	void set_angle2(double angle2_)
	{
		angle2 = angle2_;
	}

	void set_angle3(double angle3_)
	{
		angle3 = angle3_;
	}

	double get_perimeter()
	{
		return side1 + side2 + side3;
	}

	double get_square()
	{
		double a = side1;
		double b = side2;
		double c = side3;
		double p = get_perimeter() / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}

	double get_height_to_side1()
	{
		return (2 * get_square()) / side1;
	}

	double get_height_to_side2()
	{
		return (2 * get_square()) / side2;
	}

	double get_height_to_side3()
	{
		return (2 * get_square()) / side3;
	}

	void check_triangle()
	{
		if (side1 == side2 && side2 == side3 && side1 == side3)
		{
			cout << "Треугольник равносторонний " << endl;
		}
		else if (side1 == side2 || side2 == side3 || side1 == side3)
		{
			cout << "Треугольник равнобедренный " << endl;
		}
		if ((side1 == side2 || side2 == side3 || side1 == side3) && (angle1 == 90 || angle2 == 90 || angle3 == 90))
		{
			cout << "Треугольник равнобедренный и прямоугольный " << endl;
		}

		if (angle1 == 90 || angle2 == 90 || angle3 == 90)
		{
			cout << "Треугольник прямоугольный " << endl;
		}
	}

	friend ostream& operator<<(ostream& os, Triangle& obj);
	friend istream& operator>>(istream& is, Triangle& obj);
};

ostream& operator<<(ostream& os, Triangle& obj)
{
	os << "1-я сторона:" << obj.side1 << endl;
	os << "2-я сторона:" << obj.side2 << endl;
	os << "3-я сторона:" << obj.side3 << endl;
	os << "1-й угол:" << obj.angle1 << endl;
	os << "2-й угол:" << obj.angle2 << endl;
	os << "3-й угол:" << obj.angle3 << endl;
	return os;
}

istream& operator>>(istream& is, Triangle& obj)
{
	cout << "Введите 1-ю сторону:";
	is >> obj.side1;
	cout << "Введите 2-ю сторону:";
	is >> obj.side2;
	cout << "Введите 3-ю сторону:";
	is >> obj.side3;
	cout << "Введите 1-й угол:";
	is >> obj.angle1;
	cout << "Введите 2-й угол:";
	is >> obj.angle2;
	cout << "Введите 3-й угол:";
	is >> obj.angle3;
	return is;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	
	Triangle triangle1;
	cout << triangle1;
	
	Triangle triangle2;
	cin >> triangle2;
	
	cout << "Получаем первую сторону треугольника: " << triangle2.get_side1() << endl;
	cout << "На какое число изменить данную сторону треугольника: ";
	
	double delta;
	cin >> delta;
	
	triangle2.set_side1(delta);
	
	cout << "Теперь вот Ваша сторона:" << triangle2.get_side1() << endl;
	cout << "Периметр треугольника:" << triangle2.get_perimeter() << endl;
	cout << "Площадь треугольника:" << triangle2.get_square() << endl;
	
	cout << "Высота треугольника,основанием которой является первая сторона треугольника:" << triangle2.
		get_height_to_side1() << endl;
	
	triangle2.check_triangle();
	_getch();
}
